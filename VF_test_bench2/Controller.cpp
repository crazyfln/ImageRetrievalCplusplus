#include "StdAfx.h"
#include "Controller.h"
#include <iostream>
#include <ssqls.h>
#include <exceptions.h>
#include <string>
#include <mysql++.h>
//#include "UtilityFunctions.h"
#include "Constants.h"


using namespace std;
using namespace System::Windows::Forms;

Controller::Controller(void)
{
	 srand( (unsigned int)time(0) );
}

Controller::Controller( Model^ m, MyView^ v){
	model = m;
	view = v;
	srand( (unsigned int)time(0) );
}

mysqlpp::StoreQueryResult Controller::new_query( BflyObject ^ q ) {
	try {

	int pid = q->pid;

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		std::cout << "\n\nFAILED TO CONNECT TO DB. EXITING. (press return)\n";
		std::getchar();
		exit(1);
	}
	
	mysqlpp::Query query = con.query();

	query << "SELECT * FROM " << BFLY_OBJECTS_TABLE /*BFLY_FEATURES_TABLE*/ << " WHERE pid = " << pid << ";";
	
	mysqlpp::StoreQueryResult result = query.store();

	if( result.empty() ) {
		MessageBox::Show( "Controller::new_query: Querying for nonexistant image (pid not in db).", "Something smells foul..", MessageBoxButtons::OK, MessageBoxIcon::Error );
	}

	//update the QueryImage: bfly object info
	q->parse_metadata( result[0] );

	//update the QueryImage: features
	//use the pid stored in the parent BflyPicture object
	q->parse_VFs();
	q->parse_PFs();

	return model->get_knn( q );

	} catch (mysqlpp::Exception e) {
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "E! Controller::new_query", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(2);
	}
}



mysqlpp::StoreQueryResult Controller::generate_queries( array<int>^ num_specimens ) {

	try {

	//mysqlpp::Connection con = get_db_connection();
	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		std::cout << "\n\nFAILED TO CONNECT TO DB. EXITING. (press return)\n";
		std::getchar();
		exit(1);
	}
	
	mysqlpp::Query query = con.query();
	
	//get the query objects
	query << "SELECT * " //"SELECT pid, eta, precision_pre, group_index " 
		  << "FROM " << BFLY_OBJECTS_TABLE /*BFLY_FEATURES_TABLE*/ << " WHERE ";
	
	int temp;
	for( int i = 0; i < NUM_Q_POSSIBILITIES; i++ ) {
		temp = rand() % DB_SIZE + 1;
		query << " pid = " << temp;
		if( i < NUM_Q_POSSIBILITIES - 1 )
			query << " || ";
		else
			query << ";";
	}
	
	mysqlpp::StoreQueryResult result = query.store();

	//and now get the number of specimens for each query's category
	query.reset();
	query << "SELECT group_index, COUNT(*) FROM " << BFLY_FEATURES_TABLE << " WHERE";
	for( int i = 0; i < NUM_Q_POSSIBILITIES; i++ ) {
		query << " group_index = " << result[i]["group_index"];
		if( i == NUM_Q_POSSIBILITIES - 1 )
			query << " GROUP BY group_index;";
		else
			query << " ||";
	}
	
	mysqlpp::StoreQueryResult count_result = query.store();

	for( int i = 0; i < NUM_Q_POSSIBILITIES; i++ ) {
		for( int j = 0; j < NUM_Q_POSSIBILITIES; j++ ) {
			if( result[i]["group_index"] == count_result[j]["group_index"] ) {
				//set the count
				num_specimens[i] = (int)count_result[j][1];
				break;
			}
		}
	}

	return result;

	} catch (mysqlpp::Exception e) {
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "Controller::generate_queries(): MySQL++ EXCEPTION!", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(2);
	}
}

mysqlpp::StoreQueryResult Controller::generate_query( int pid, int & num_specimens ) {

	try {

	//mysqlpp::Connection con = get_db_connection();
	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		std::cout << "\n\nFAILED TO CONNECT TO DB. EXITING. (press return)\n";
		std::getchar();
		exit(1);
	}
	
	mysqlpp::Query query = con.query();
	
	//get the query objects
	query << "SELECT * " //"SELECT pid, eta, precision_pre, group_index " 
		  << "FROM " << BFLY_OBJECTS_TABLE /*BFLY_FEATURES_TABLE*/ << " WHERE ";
	
	int temp;
	temp = pid;
		query << " pid = " << temp;
		query << ";";

	
	mysqlpp::StoreQueryResult result = query.store();

	//and now get the number of specimens for each query's category
	query.reset();
	query << "SELECT group_index, COUNT(*) FROM " << BFLY_FEATURES_TABLE << " WHERE";
	query << " group_index = " << result[0]["group_index"];

	query << ";";

	
	mysqlpp::StoreQueryResult count_result = query.store();


	num_specimens = (int)count_result[0][1];


	return result;

	} catch (mysqlpp::Exception e) {
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "Controller::generate_queries(): MySQL++ EXCEPTION!", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(2);
	}
}

mysqlpp::StoreQueryResult Controller::process_RF( BflyObject ^ q, array<D_small_display_object ^> ^ displays) {
	//NOTE: when changing this, also need to change Model::get_knn()
	return this->process_RF_with_VFs( q, displays );
	//return this->process_RF_no_VFs( q, displays );
}

mysqlpp::StoreQueryResult Controller::process_RF_no_VFs( BflyObject ^ q, array<D_small_display_object ^> ^ displays) {
	model->do_qvm( q, displays );
	mysqlpp::StoreQueryResult res = model->get_knn( q );
	return res;
}

mysqlpp::StoreQueryResult Controller::process_RF_with_VFs( BflyObject ^ q, array<D_small_display_object ^> ^ displays) {
	
	model->update_q_mu_and_precision( q, displays );
	model->update_D_VFs( q, displays );
	model->do_qvm( q, displays );
	model->update_q_VFs( q, displays );
	model->increment_VF_counter();
	mysqlpp::StoreQueryResult res = model->get_knn( q );
	return res;
}

int Controller::get_vf() {

	return model->return_vf();
}