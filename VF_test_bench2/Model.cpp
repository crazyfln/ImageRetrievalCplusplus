#include "StdAfx.h"
#include "Model.h"
//#include "VFComparer.h"
#include "VF.h"
#include "MyList.h"
#include "Constants.h"
#include "UtilityFunctions.h"
#include <math.h>


using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::Collections::Generic;

Model::Model(void)
{
	knn_list = gcnew MyList();

	load_bfly_features();

	load_vf_counter();
	new_vf = false;////////////////////////
}


//loads the current VF counter value from the database
void Model::load_vf_counter() {
	try {

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		MessageBox::Show( "Failed to connect to DB. Exiting.",
						  "Model::load_vf_counter()",
						  MessageBoxButtons::OK, MessageBoxIcon::Error );
	}
	
	mysqlpp::Query query = con.query();

	query << "SELECT * FROM " << VF_COUNTER_TABLE;

	mysqlpp::StoreQueryResult res = query.store();

	this->vf_counter = (int) res[0][0];

	con.disconnect();
	return;

	} catch (mysqlpp::Exception e) {
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "Model::load_vf_coutner()", MessageBoxButtons::OK, MessageBoxIcon::Error );
	}
}

mysqlpp::StoreQueryResult Model::get_knn( BflyObject ^ q ) {
	//NOTE: when changing this, also change Controller::process_RF
	//return this->PF_only_knn( q );
	return this->PF_and_VF_knn( q );
}


mysqlpp::StoreQueryResult Model::PF_and_VF_knn( BflyObject ^ q ) {

	knn_list->reset();

	double temp_distance;
	int query_pid = q->pid;
	bool q_has_VFs = q->has_VFs();

	//find the knn
	for( int i = 0; i < bfly_features->GetLength(0); i++ ) {
		//don't look at the query image..
		if( bfly_features[i]->pid == query_pid )
			continue;

		temp_distance = get_PF_distance( q, i );

		if( q_has_VFs && bfly_features[i]->has_VFs() )
			temp_distance *= ( 1 - get_VF_cosine_theta(q, i) );
		bool inserted = knn_list->conditional_insert( bfly_features[i]->pid, temp_distance );
		
		//DEBUGGING
		//if( inserted ) {
		//	System::Text::StringBuilder ^ sb = gcnew System::Text::StringBuilder("Inserted into knn: ");
		//	sb->Append( "pid: " );
		//	sb->Append( bfly_features[i]->pid );
		//	sb->Append( ", distance: " );
		//	sb->Append( temp_distance );
			//MessageBox::Show( sb->ToString(), "Model::PF_and_VF_knn", MessageBoxButtons::OK, MessageBoxIcon::Information );
		//}
	}

	//now load the knn's objects
	try {

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		std::cout << "\n\nFAILED TO CONNECT TO DB. EXITING. (press return)\n";
		std::getchar();
		exit(1);
	}
	
	mysqlpp::Query query = con.query();

	array<int> ^ pids = knn_list->get_pids();
	/*query << "SELECT pid, eta, precision_pre, group_index FROM "
		  << BFLY_FEATURES_TABLE << " WHERE ";*/
	query << "SELECT * FROM " << BFLY_OBJECTS_TABLE << " WHERE ";
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		query << " pid = " << pids[i];
		if( i < NUM_D_RESULTS - 1 )
			query << " || ";
		else
			query << ";";
	}

	mysqlpp::StoreQueryResult result = query.store();
	con.disconnect();

	//order the result based on the distance
	mysqlpp::StoreQueryResult ordered_res = result;
	for( int i = 0; i < pids->Length; i++ ) {
		for( unsigned int j = 0; j < result.num_rows(); j++ ) {
			if( pids[i] == (int)result[j]["pid"] ) {
				ordered_res[i] = result[j];
				break;
			}
		}
	}

	return ordered_res;

	} catch (mysqlpp::Exception e) {		
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "Model::PF_and_VF_knn", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(2);
	}
}


void Model::update_D_VFs( BflyObject ^ q, array<D_small_display_object ^> ^ ds ) {
	
	//relevant images with no VFs
	List<D_small_display_object^> ^ R_prime = gcnew List<D_small_display_object^>();
	//relevant images that already have VFs
	List<D_small_display_object^> ^ R_double_prime = gcnew List<D_small_display_object^>();
	//all relevant images
	List<D_small_display_object^> ^ R = gcnew List<D_small_display_object^>();

	//create two subsets of relevant images, based on whether the images have VFs or not
	for( int i = 0; i < ds->Length; i++ ) {
		if( ds[i]->rf_pos ) {
			R->Add( ds[i] );
			if( ds[i]->has_VFs() )
				R_double_prime->Add( ds[i] );
			else
				R_prime->Add( ds[i] );
		}
		if( R->Count == 0 )
			return;
	}

	//if no images already have VFs, just give them the current counter and return
	if( R_double_prime->Count == 0 ) {
		for each( D_small_display_object^ d in R_prime ) {
			d->VF_cs[0] = this->vf_counter;
			d->VF_es[0] = 1;
			this->bfly_features[d->pid - 1]->VF_cs[0] = this->vf_counter;
			this->bfly_features[d->pid - 1]->VF_es[0] = 1;
			//d->has_VFs = true;
		}
		new_vf = true;//////////////////////////////////////////////////////////////////////////////
		store_VF_changes_in_DB( R_prime );
		return;
	}

	//give all the images that didn't have VFs a concatenation of the VFs of the images that did
	//concatenate them
	ArrayList ^ temp_VFs = gcnew ArrayList();
	for each( D_small_display_object^ dd in R_double_prime ) {
		int j = 0;
		while( j < NUM_VFS_PER_IMAGE && dd->VF_cs[j] > 0 && dd->VF_es[j] > 0 ) {
			temp_VFs->Add( gcnew VF(dd->VF_cs[j], dd->VF_es[j]) );
			j++;
		}
	}
	//transform the VF vector into standard form
	array<VF^>^ new_VFs = normalize_VF_vector( temp_VFs );

	//give the new VF vector to all images that previously did not have any VFs
	for each( D_small_display_object ^ d in R_prime ) {
		for( int i = 0; i < new_VFs->Length; i++ ) {
			d->VF_cs[i] = new_VFs[i]->c;
			d->VF_es[i] = new_VFs[i]->e;
			this->bfly_features[d->pid - 1]->VF_cs[i] = new_VFs[i]->c;
			this->bfly_features[d->pid - 1]->VF_es[i] = new_VFs[i]->e;
		}
		//d->has_VFs = true;
	}

	//now give each image the current concept
	double mu = q->mu;
	for each( D_small_display_object ^ d in R ) {
		temp_VFs = gcnew ArrayList();
		for( int i = 0; i < NUM_VFS_PER_IMAGE; i++ ) {
			if( d->VF_cs[i] <= 0 )
				break;
			temp_VFs->Add( gcnew VF(d->VF_cs[i], d->VF_es[i] * mu) );
		}
		temp_VFs->Add( gcnew VF( this->vf_counter, 1 - mu ) );
		new_VFs = normalize_VF_vector( temp_VFs );
		for( int i = 0; i < NUM_VFS_PER_IMAGE; i++ ) {
			if( i < new_VFs->Length ) {
				d->VF_cs[i] = new_VFs[i]->c;
				d->VF_es[i] = new_VFs[i]->e;
				this->bfly_features[d->pid - 1]->VF_cs[i] = new_VFs[i]->c;
				this->bfly_features[d->pid - 1]->VF_es[i] = new_VFs[i]->e;
			}
			else {
				d->VF_cs[i] = 0;
				d->VF_es[i] = 0;
				this->bfly_features[d->pid - 1]->VF_cs[i] = 0;
				this->bfly_features[d->pid - 1]->VF_es[i] = 0;
			}
		}
	}
	new_vf = true;
	//store the changes in the database
	store_VF_changes_in_DB( R_prime );
	store_VF_changes_in_DB( R_double_prime );

	return;
}


//get the k nearest neighbours in PF space only
mysqlpp::StoreQueryResult Model::PF_only_knn( BflyObject ^ q ){
	
	knn_list->reset();

	double temp_distance;
	int query_pid = q->pid;

	//find the knn
	for( int i = 0; i < bfly_features->GetLength(0); i++ ) {
		//don't look at the query image..
		if( bfly_features[i]->pid == query_pid )
			continue;

		temp_distance = get_PF_distance( q, i );
		knn_list->conditional_insert( bfly_features[i]->pid, temp_distance );
	}

	//now load the knn's objects
	try {

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		std::cout << "\n\nFAILED TO CONNECT TO DB. EXITING. (press return)\n";
		std::getchar();
		exit(1);
	}
	
	mysqlpp::Query query = con.query();

	array<int> ^ pids = knn_list->get_pids();
	query << "SELECT pid, eta, precision_pre, group_index FROM " 
		  << BFLY_FEATURES_TABLE << " WHERE ";
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		query << " pid = " << pids[i];
		if( i < NUM_D_RESULTS - 1 )
			query << " || ";
		else
			query << ";";
	}

	mysqlpp::StoreQueryResult result = query.store();
	con.disconnect();

	//order the result based on the distance
	mysqlpp::StoreQueryResult ordered_res = result;
	for( int i = 0; i < pids->Length; i++ ) {
		for( unsigned int j = 0; j < result.num_rows(); j++ ) {
			if( pids[i] == (int)result[j]["pid"] ) {
				ordered_res[i] = result[j];
				break;
			}
		}
	}

	return ordered_res;

	} catch (mysqlpp::Exception e) {		
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "Model::PF_only_knn", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(2);
	}
}






//loads the butterfly pictorial features into Model's bfly_features array
//this makes searching for the relevant images much faster
void Model::load_bfly_features() {
	try {

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		MessageBox::Show( "Failed to connect to DB. Exiting.",
						  "Model::load_bfly_features()",
						  MessageBoxButtons::OK, MessageBoxIcon::Error );
	}
	
	mysqlpp::Query query = con.query();

	query << "SELECT * FROM " << BFLY_FEATURES_TABLE;

	//get the query results one at a time
	if (mysqlpp::UseQueryResult result = query.use() ) {
		
		bfly_features = gcnew array<BflyFeatures^>(DB_SIZE);
		for( int i = 0; i < DB_SIZE; i++ ) {
			bfly_features[i] = gcnew BflyFeatures();
		}

		int row_counter = 0;
		try {
		for( int row_index = 0; row_index < DB_SIZE; row_index++ ) {
			mysqlpp::Row row = result.fetch_row();
			bfly_features[row_counter]->pid = row[0];
			//store all the PFs
			for( int i = 0; i < NUM_PFS; i++ ) {
				bfly_features[row_counter]->PFs[i] = row[i+DB_INDEX_OF_FIRST_PF];
			}
			//and all the VFs
			for( int db_i = DB_INDEX_OF_FIRST_VF, local_i = 0;
				 local_i < NUM_VFS_PER_IMAGE;
				 db_i += 2, local_i++ ) {
					 bfly_features[row_counter]->VF_cs[local_i] = (int)row[db_i];
					 bfly_features[row_counter]->VF_es[local_i] = (double)row[db_i + 1];
			}
			row_counter++;
		}
		} catch (mysqlpp::Exception e) {
			//for some reason this pulls an empty row once all the valid rows have been processed
			//this can be ignored
			System::Text::StringBuilder ^ sb = gcnew System::Text::StringBuilder("row_counter = ");
			sb->Append( row_counter );
			MessageBox::Show( sb->ToString(), "Model::load_bfly_features()", MessageBoxButtons::OK, MessageBoxIcon::Information );
		}
	}
	} catch (mysqlpp::Exception e) {
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "Model::load_bfly_features()", MessageBoxButtons::OK, MessageBoxIcon::Error );
	}

}


//computes the euclidean distance between the two images
// q is the query image
// index is the index in bfly_features of the other image
double Model::get_PF_distance( BflyObject ^ q, int index ) {
	
	double distance = 0;
	double temp1;
	double temp2;

	bool list_full = (knn_list->get_length() == NUM_D_RESULTS);
	double max_distance = MAX_PF_DISTANCE;

	if( list_full )
		max_distance = knn_list->get_longest_distance();
		
	// for each pictorial feature
	for( int i = 0; i < NUM_PFS; i++ ) {
		//if this picture is already too different, no need to look at the remaining PFs
		if( list_full && distance >= max_distance )
			return distance;
		
		temp1 = q->PFs[i];
		temp2 = bfly_features[index]->PFs[i];
		distance += (temp1 - temp2) * (temp1 - temp2);
		if( distance < 0 )
			//overflow error - this is for debugging
			distance = MAX_PF_DISTANCE;
	}
	
	return distance;
}



//computes cos( angle between the two images' VF vectors )
//assumes VFs are ordered by increasing concept number
double Model::get_VF_cosine_theta( BflyObject ^ q, int index ) {
	
	if( !q->has_VFs() || !bfly_features[index]->has_VFs() )
		return 0;

	BflyFeatures ^ d = bfly_features[index];

	double cos_theta = 0;
	int Q_index = 0;
	int D_index = 0;
	int Q_c;
	int D_c;

	while( true ) {
		if( Q_index >= NUM_VFS_PER_IMAGE || D_index >= NUM_VFS_PER_IMAGE ) {
			if( cos_theta > 1 )
				return 1;
			else
				return cos_theta;
		}

		Q_c = q->VF_cs[Q_index];
		D_c = d->VF_cs[D_index];

		if( Q_c == 0 || D_c == 0 )
			return cos_theta;

		if( Q_c == D_c ) {
			cos_theta += q->VF_es[Q_index] * d->VF_es[D_index];
			Q_index++;
			D_index++;
		}
		else if( Q_c > D_c )
			D_index++;
		else
			Q_index++;
	}
	
	//never reached
	return 0;
}

void Model::do_qvm( BflyObject ^ q, array<D_small_display_object ^> ^ Ds) {
	standard_qvm( q, Ds );
	//krystof_qvm( q, Ds );
	return;
}


void Model::standard_qvm( BflyObject ^ q, array<D_small_display_object ^> ^ Ds) {
	
	int num_pos = 0;
	int num_neg = 0;
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		if( Ds[i]->rf_pos )
			num_pos++;
		else if( Ds[i]->rf_neg )
			num_neg++;
	}

	//DEBUGGING STUFF
	double orig_pf;
	double plus_val;
	double minus_val;

	//for all the pictorial features
	for( int i = 0; i < NUM_PFS; i++ ) {
		orig_pf = q->PFs[i];
		q->PFs[i] = ALPHA * q->PFs[i];
		//for each relevant or nonrelevant DB image
		for( int j = 0; j < NUM_D_RESULTS; j++ ) {
			if( Ds[j]->rf_pos ) {
				plus_val = BETA * Ds[j]->PFs[i] / num_pos;
				q->PFs[i] += plus_val;
			}
			else if( Ds[j]->rf_neg ) {
				minus_val = GAMMA * Ds[j]->PFs[i] / num_neg;
				q->PFs[i] -= minus_val;
			}
		}
	}

	//normalize the PF vector
	double magnitude = 0;
	for( int i = 0; i < NUM_PFS; i++ ) {
		magnitude += q->PFs[i] * q->PFs[i];
	}
	magnitude = sqrt( magnitude );
	for( int i = 0; i < NUM_PFS; i++ ) {
		q->PFs[i] /= magnitude;
	}

	return;
}


void Model::krystof_qvm( BflyObject ^ q, array<D_small_display_object ^> ^ Ds) {
	
	double difference;
	double pos_percent;

	int num_pos = 0;
	int num_neg = 0;
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		if( Ds[i]->rf_pos )
			num_pos++;
		else if( Ds[i]->rf_neg )
			num_neg++;
	}

	pos_percent = num_pos / NUM_D_RESULTS;

	//for all the pictorial features
	for( int i = 0; i < NUM_PFS; i++ ) {
		//for each relevant or nonrelevant DB image
		for( int j = 0; j < NUM_D_RESULTS; j++ ) {
			difference = Ds[j]->PFs[i] - q->PFs[i];
			if( Ds[j]->rf_pos ) {
				q->PFs[i] +=  (1-pos_percent) * difference / num_pos;
			}
			else if( Ds[j]->rf_neg ) {
				q->PFs[i] -= pos_percent * difference / num_neg;
			}
		}
	}

	return;
}



//returns the normalized VF vector
array<VF^>^ Model::normalize_VF_vector( ArrayList ^ temp_VFs ) {

	//if there are no VFs, return an empty array
	if( temp_VFs->Count == 0 ) {
		array<VF^> ^ a = gcnew array<VF^>(1);
		a[0] = gcnew VF(0,0);
		return a;
	}

	//add together the support values of the same concept
	temp_VFs->Sort();

	array<VF^> ^ VF_arr = reinterpret_cast<array<VF^>^>(temp_VFs->ToArray());	
	
	int small_i = 0;
	int big_i = 0;
	int temp_c;
	int real_length = VF_arr->Length;
	double magnitude = 0;
	while( small_i < VF_arr->Length ) {
		temp_c = VF_arr[small_i]->c;
		while( big_i + 1 < VF_arr->Length && VF_arr[big_i+1]->c == temp_c ) {
			big_i++;
			VF_arr[small_i]->e += VF_arr[big_i]->e;
			VF_arr[big_i]->c = -1; //make this "invalidated", because it's been added to the other one
			real_length--;
		}
		magnitude += (VF_arr[small_i]->e) * (VF_arr[small_i]->e);
		big_i++;
		small_i = big_i;
	}

	//handle the situation where an image has more VFs than allowed
	//by removing the concepts with the smallest support values
	if( real_length > NUM_VFS_PER_IMAGE ) {
		
		MessageBox::Show( "An image wants more VFs than it can have. No worries, it's being dealt with. Just thought you might like to know.",
			              "Model::normalize_VF_vector", MessageBoxButtons::OK, MessageBoxIcon::Information );

		int num_to_remove = real_length - NUM_VFS_PER_IMAGE;
		int orig_real_length = real_length;

		MyList ^ l = gcnew MyList( num_to_remove );
		for( int i = 0; i < VF_arr->Length; i++ ) {
			if( VF_arr[i]->c < 0 )
				continue;
			l->conditional_insert( VF_arr[i]->c, VF_arr[i]->e );
		}
		array<int> ^ remove_these = l->get_pids();
		for( int i = 0; i < VF_arr->Length; i++ ) {
			for( int j = 0; j < remove_these->Length; j++ ) {
				if( VF_arr[i]->c == remove_these[j] ) {
					VF_arr[i]->c = -1;
					real_length--;
				}
			}
		}
	}

	//and normalize the values, too
	magnitude = sqrt(magnitude);
	array<VF^> ^ VF_arr2 = gcnew array<VF^>(real_length);
	int arr2_index = 0;
	for( int i = 0; i < VF_arr->Length; i++ ) {
		if( VF_arr[i]->c > 0 ) {
			VF_arr2[arr2_index] = gcnew VF( VF_arr[i]->c, Math::Abs(VF_arr[i]->e / magnitude) );
			arr2_index++;
		}
	}

	return VF_arr2;
}

void Model::store_Q_VF_changes_in_DB( BflyObject ^ q ) {

	try
	{
		mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
		if( !con.connected() ) {
			MessageBox::Show( "Failed to connect to DB. Exiting.", "Model::update_Q_VFs", MessageBoxButtons::OK, MessageBoxIcon::Error );
			exit(1);
		}
		mysqlpp::Query query = con.query();
		
		int counter = 0;
		for( int j = 0; j < NUM_VFS_PER_IMAGE; j++ ) {
			if( (q->VF_cs[j] != 0) && (q->VF_es[j] != 0) )
				counter++;
		}
		q->local_vf_counter = counter;
		query << "UPDATE " << BFLY_FEATURES_TABLE << " SET number_of_vf = " << counter << ",";
		for( int i = 0; i < NUM_VFS_PER_IMAGE; i++ ) {
			query << " vf_c_" << i+1 << " = " << q->VF_cs[i]
				  << ", vf_e_" << i+1 << " = " << q->VF_es[i];
			if( i == NUM_VFS_PER_IMAGE - 1 )
				query << " WHERE pid = " << q->pid << ";";
			else
				query << ",";
		}
		if( !query.exec() ) {
			MessageBox::Show( "Failed to connect to update VF data.", "Model::update_Q_VFs", MessageBoxButtons::OK, MessageBoxIcon::Error );
		}
		query.reset();
		
		query << "UPDATE " << BFLY_OBJECTS_TABLE << " SET number_of_vf = " << counter << " WHERE pid = " << q->pid << ";";////////////////////////////////
		if( !query.exec() ) {
			MessageBox::Show( "Failed to connect to update VF data.", "Model::update_Q_VFs", MessageBoxButtons::OK, MessageBoxIcon::Error );
		}
		query.reset();///////////////
		
	} catch (mysqlpp::Exception e) {		
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "Model::store_Q_VF_changes_in_DB", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(2);
	}

	return;
}

void Model::store_VF_changes_in_DB( List<D_small_display_object^> ^ ds ) {
	try
	{

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	if( !con.connected() ) {
		MessageBox::Show( "Failed to connect to DB. Exiting.", "Model::update_D_VFs", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(1);
	}
	mysqlpp::Query query = con.query();

	for each( D_small_display_object^ d in ds ) {
		int counter = 0;
		
		for( int j = 0; j < NUM_VFS_PER_IMAGE; j++ ) {
			if( (d->VF_cs[j] != 0) && (d->VF_es[j] != 0) )/////////////////need more considerations
				counter++;
		}
		d->local_vf_counter = counter;
		query << "UPDATE " << BFLY_FEATURES_TABLE << " SET number_of_vf = " << counter << ",";////////////////////////
		for( int i = 0; i < NUM_VFS_PER_IMAGE; i++ ) {
			query << " vf_c_" << i+1 << " = " << d->VF_cs[i]
				  << ", vf_e_" << i+1 << " = " << d->VF_es[i];
			if( i == NUM_VFS_PER_IMAGE - 1 )
				query << " WHERE pid = " << d->pid << ";";
			else
				query << ",";
		}
		if( !query.exec() ) {
			MessageBox::Show( "Failed to connect to update VF data.", "Model::update_D_VFs", MessageBoxButtons::OK, MessageBoxIcon::Error );
		}
		query.reset();
		
		query << "UPDATE " << BFLY_OBJECTS_TABLE << " SET number_of_vf = " << counter << " WHERE pid = " << d->pid << ";";////////////////////////////////
		if( !query.exec() ) {
			MessageBox::Show( "Failed to connect to update VF data.", "Model::update_D_VFs", MessageBoxButtons::OK, MessageBoxIcon::Error );
		}
		query.reset();///////////////
	}

	} catch (mysqlpp::Exception e) {		
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "Model::store_VF_changes_in_DB", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(2);
	}

	return;
}


void Model::update_q_mu_and_precision( BflyObject ^ q, array<D_small_display_object ^> ^ ds ) {
	
	double new_mu = 0;
	float new_prec = 0;
	int num_pos = 0;
	float average_precision = 0;//////////////////////
	float temp = 0;/////////////////////////
	//calculate the current precision
	int i, j;  //////////////////////////////
	for( i = 0; i < ds->Length; i++ ) {//////////////////////////////
		if( ds[i]->rf_pos ) {
			num_pos++;
		}
		j = i + 1;
		temp += (float)num_pos / j;//////////////////////////
	}
	new_prec = ((float)num_pos) / ((float)ds->Length);
	if( num_pos > 0)
	    average_precision = (float)temp / ((float)ds->Length);//////////////////////////
	else
		average_precision = 0;
	new_mu = q->mu * (1 + new_prec - q->precision_pre);
	if( new_mu > 1 )
		new_mu = 1;
	else if( new_mu <= 0 )
		new_mu = MINIMUM_ETA;

	q->mu = (float)new_mu;
	q->precision_pre = new_prec;
	q->average_pre = average_precision;//////////////////////////
	//store the changes in the db
	try
	{

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	if( !con.connected() ) {
		MessageBox::Show( "Failed to connect to DB. Exiting.", "Model::update_q_mu_and_precision", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(1);
	}
	mysqlpp::Query query = con.query();

	query << "UPDATE " << BFLY_OBJECTS_TABLE << " SET "//////////////////////////////
		  << "eta = " << q->mu
		  << ", average_pre = " << q->average_pre    ////////////////////////////
		  << ", precision_pre = " << q->precision_pre
		  << " WHERE pid = " << q->pid << ";";

	query.exec();
	query.reset();
	
	query << "UPDATE " << BFLY_FEATURES_TABLE << " SET "//////////////////////////////
		  << "eta = " << q->mu
		  << ", average_pre = " << q->average_pre    ////////////////////////////
		  << ", precision_pre = " << q->precision_pre
		  << " WHERE pid = " << q->pid << ";";
	query.exec();

	con.disconnect();

	} catch (mysqlpp::Exception e) {		
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "Model::update_q_mu_and_precision", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(2);
	}

}

void Model::update_q_VFs(BflyObject ^q, cli::array<D_small_display_object ^,1> ^ ds ) {
	
	//concatenate all the relevant images' VFs
	ArrayList ^ temp_VFs = gcnew ArrayList();
	for( int i = 0; i < ds->Length; i++ ) {
		if( ds[i]->rf_pos ) {
			for( int j = 0; j < NUM_VFS_PER_IMAGE; j++ ) {
				if( ds[i]->VF_cs[j] <= 0 )
					break;
				temp_VFs->Add( gcnew VF(ds[i]->VF_cs[j], ds[i]->VF_es[j]) );
			}
		}
	}
	array<VF^> ^ new_VFs = normalize_VF_vector( temp_VFs );

	//store them back in the query
	for( int i = 0; i < NUM_VFS_PER_IMAGE; i++ ) {
		if( i < new_VFs->Length ) {
			q->VF_cs[i] = new_VFs[i]->c;
			q->VF_es[i] = new_VFs[i]->e;
		}
		else {
			q->VF_cs[i] = 0;
			q->VF_es[i] = 0;
		}
	}
	store_Q_VF_changes_in_DB( q );

	return;
}


//increments the VF counter value, and stores the new value in the DB
int Model::increment_VF_counter() {
	if( new_vf == true ) {
		vf_counter++;
		new_vf = false;
	}

	//store the change in the DB
	try {

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		std::cout << "\n\nFAILED TO CONNECT TO DB. EXITING. (press return)\n";
		std::getchar();
		exit(1);
	}
	
	mysqlpp::Query query = con.query();

	query << "UPDATE " << VF_COUNTER_TABLE
		  << " SET vf_counter = " << vf_counter << ";";

	query.exec();

	con.disconnect();

	} catch (mysqlpp::Exception e) {		
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "Model::increment_VF_counter", MessageBoxButtons::OK, MessageBoxIcon::Error );
		//exit(2);
	}

	return vf_counter;
}

int Model::return_vf() {
	
	int counter = this->vf_counter - 1;
	return counter;
}