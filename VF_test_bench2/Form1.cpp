#include "StdAfx.h"
#include "Form1.h"
#include <Windows.h>

void Form1::relevance_switch() {
	this->label1->Visible = false;
	this->label2->Visible = false;
	this->label3->Visible = false;
	this->label4->Visible = false;
	this->label5->Visible = false;
	this->label6->Visible = false;
	this->label7->Visible = false;
	this->label8->Visible = false;
	this->label9->Visible = false;
	this->label10->Visible = false;
	this->label11->Visible = false;
	this->label12->Visible = false;
}

bool Form1::update_D_displays( mysqlpp::StoreQueryResult result ) {
	
	System::Text::StringBuilder ^ temp;
	System::Text::StringBuilder ^ temp1;///////////////////////////////
	//update the displayed D info boxes
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		
		//update the image
		temp = gcnew System::Text::StringBuilder("");
		temp1 = gcnew System::Text::StringBuilder("");//////////////////////////////////////
		temp->Append( gcnew System::String( LARGE_IMG_FOLDER ) );
		temp->Append( gcnew System::String((result[i]["photo_top"]).c_str()) );
		temp->Append( ".jpg" );
		D_img_objects[i]->Pic->BackgroundImage = System::Drawing::Image::FromFile(temp->ToString());
		D_img_objects[i]->Pic->Refresh();
		//update the text
		if( (int)result[i]["group_index"] == Q->group_index )
			D_img_objects[i]->text->ForeColor = System::Drawing::Color::Green;
		else
			D_img_objects[i]->text->ForeColor = System::Drawing::Color::Black;
		//temp->Append( (int)result[i]["group_index"] );/////////////////////////
		temp1->Append("Group:");/////////////////////
		temp1->Append( (int)result[i]["group_index"] );//////////////////////////
		temp1->Append("\r\n pid:");/////////////////////////////
		temp1->Append( (int)result[i]["pid"] );///////////////////////////
		D_img_objects[i]->text->Text = temp1->ToString();////////////////////////
		D_img_objects[i]->text->Refresh();
		//update the bfly info fields
		D_img_objects[i]->parse_metadata( result[i] );

		//remove past RF information
		D_img_objects[i]->rf_neg = false;
		D_img_objects[i]->rf_pos = false;
	}
	
	return true;
}

bool Form1::update_d_displays( mysqlpp::StoreQueryResult result ) {
	
	System::Text::StringBuilder ^ temp;
	System::Text::StringBuilder ^ temp1;///////////////////////////////
	//update the displayed D info boxes
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		
		//update the image
		temp = gcnew System::Text::StringBuilder("");
		temp1 = gcnew System::Text::StringBuilder("");//////////////////////////////////////
		temp->Append( gcnew System::String( LARGE_IMG_FOLDER ) );
		temp->Append( gcnew System::String((result[i]["photo_top"]).c_str()) );
		temp->Append( ".jpg" );
		D_little_img_objects[i]->pic->BackgroundImage = System::Drawing::Image::FromFile(temp->ToString());
		D_little_img_objects[i]->pic->Refresh();
		//update the bfly info fields
		D_little_img_objects[i]->parse_metadata( result[i] );

		//remove past RF information
		D_little_img_objects[i]->rf_neg = false;
		D_little_img_objects[i]->rf_pos = false;
	}
	
	return true;
}

bool Form1::update_Q_displays( mysqlpp::StoreQueryResult result, array<int>^ num_specimens ) {
	
	System::Text::StringBuilder ^ temp;

	//update the displayed D info boxes
	for( int i = 0; i < NUM_Q_POSSIBILITIES; i++ ) {
		
		//update the image
		temp = gcnew System::Text::StringBuilder("");
		temp->Append( gcnew System::String( SMALL_IMG_FOLDER ) );
		temp->Append( gcnew System::String((result[i]["photo_top"]).c_str()) );
		temp->Append( ".jpg" );
		Q_possibilities[i]->picBox->BackgroundImage = System::Drawing::Image::FromFile(temp->ToString());
		Q_possibilities[i]->picBox->Refresh();
		//update the label
		temp = gcnew System::Text::StringBuilder("");
		temp->Append( "Group " );
		temp->Append( (int)result[i]["group_index"] );
		temp->Append( "\n" );
		temp->Append( num_specimens[i] ); 
		temp->Append( " images" );
		Q_possibilities[i]->label->Text = temp->ToString();
		Q_possibilities[i]->label->Refresh();
		//update the pid
		Q_possibilities[i]->pid = (int)result[i]["pid"];
	}
	
	return true;
}

void Form1::setup_D_objects() {
	D_img_objects = gcnew array<D_small_display_object ^>(NUM_D_RESULTS);
	
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		D_img_objects[i] = gcnew D_small_display_object;
	}

	D_img_objects[0]->text = Form1::DText0;
	D_img_objects[0]->Pic = Form1::panel1;

	D_img_objects[1]->text = Form1::DText1;
	D_img_objects[1]->Pic = Form1::panel2;

	D_img_objects[2]->text = Form1::DText2;
	D_img_objects[2]->Pic = Form1::panel3;

	D_img_objects[3]->text = Form1::DText3;
	D_img_objects[3]->Pic = Form1::panel4;

	D_img_objects[4]->text = Form1::DText4;
	D_img_objects[4]->Pic = Form1::panel5;

	D_img_objects[5]->text = Form1::DText5;
	D_img_objects[5]->Pic = Form1::panel6;

	D_img_objects[6]->text = Form1::DText6;
	D_img_objects[6]->Pic = Form1::panel7;

	D_img_objects[7]->text = Form1::DText7;
	D_img_objects[7]->Pic = Form1::panel8;

	D_img_objects[8]->text = Form1::DText8;
	D_img_objects[8]->Pic = Form1::panel9;

	D_img_objects[9]->text = Form1::DText9;
	D_img_objects[9]->Pic = Form1::panel10;

	D_img_objects[10]->text = Form1::DText10;
	D_img_objects[10]->Pic = Form1::panel11;

	D_img_objects[11]->text = Form1::DText11;
	D_img_objects[11]->Pic = Form1::panel12;

}

void Form1::setup_d_objects() {
	
	D_little_img_objects = gcnew array<D_small_display_object ^>(NUM_D_RESULTS);
	
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		D_little_img_objects[i] = gcnew D_small_display_object;
	}
	D_little_img_objects[0]->pic = Form1::DPBox0;

	D_little_img_objects[1]->pic = Form1::DPBox1;

	D_little_img_objects[2]->pic = Form1::DPBox2;

	D_little_img_objects[3]->pic = Form1::DPBox3;

	D_little_img_objects[4]->pic = Form1::DPBox4;

	D_little_img_objects[5]->pic = Form1::DPBox5;

	D_little_img_objects[6]->pic = Form1::DPBox6;

	D_little_img_objects[7]->pic = Form1::DPBox7;

	D_little_img_objects[8]->pic = Form1::DPBox8;

	D_little_img_objects[9]->pic = Form1::DPBox9;

	D_little_img_objects[10]->pic = Form1::DPBox10;

	D_little_img_objects[11]->pic = Form1::DPBox11;

}


void Form1::setup_Q_objects() {
	Q_possibilities = gcnew array<Q_possibility_object ^>(NUM_Q_POSSIBILITIES);

	for( int i = 0; i < NUM_Q_POSSIBILITIES; i++ ) {
		Q_possibilities[i] = gcnew Q_possibility_object;
	}
	
	Q_possibilities[0]->picBox = Form1::Q1SPBox;
	Q_possibilities[0]->label = Form1::Q1_label;

	Q_possibilities[1]->picBox = Form1::Q2SPBox;
	Q_possibilities[1]->label = Form1::Q2_label;

	Q_possibilities[2]->picBox = Form1::Q3SPBox;
	Q_possibilities[2]->label = Form1::Q3_label;

	Q_possibilities[3]->picBox = Form1::Q4SPBox;
	Q_possibilities[3]->label = Form1::Q4_label;

	Q_possibilities[4]->picBox = Form1::Q5SPBox;
	Q_possibilities[4]->label = Form1::Q5_label;

	Q_possibilities[5]->picBox = Form1::Q6SPBox;
	Q_possibilities[5]->label = Form1::Q6_label;

}

void Form1::setup_q_objects() {

	Q_possibility = gcnew D_small_display_object;
	Q_possibility->pic = Form1::query;
	Q_possibility->text = Form1::querybox;
}

// id is the index of the D_small_display_object
void Form1::change_large_D_img( int id ) {
	//no image
	//if( !Form1::BottomViewRadio->Checked )
	DLrgPBox->BackgroundImage =  System::Drawing::Image::FromFile(D_img_objects[id]->photo_top.ToString());
		DLrgPBox->Refresh();
	//else
	//	DLrgPBox->ImageLocation =  D_img_objects[id]->photo_bottom.ToString();
	//the info text box
	DLrgTextBox->Text = D_img_objects[id]->print_info();
}

void Form1::change_D_img( int id ) {

	DLrgPBox->BackgroundImage = System::Drawing::Image::FromFile(D_little_img_objects[id]->photo_top.ToString());
	DLrgPBox->Refresh();
	DLrgTextBox->Text = D_little_img_objects[id]->print_info();
}

void Form1::change_Q_display() {
	//no image
	//if( !Form1::BottomViewRadio->Checked )
	QLrgPBox->BackgroundImage = System::Drawing::Image::FromFile( Q->photo_top.ToString());
	QLrgPBox->Refresh();
	//else
	//	QLrgPBox->ImageLocation = Q->photo_bottom.ToString();
	//and the info text box
	QLrgTextBox->Text = Q->print_info();
}

void Form1::change_q_display() {

	query->BackgroundImage = System::Drawing::Image::FromFile( Q->photo_top.ToString());
	query->Refresh();
	querybox->Text = Q->print_info();

}

void Form1::autorun( int pid ) {
	
	relevance_switch();
	
	int num_specimens;
	mysqlpp::StoreQueryResult res = controller->generate_query( pid, num_specimens );
	Q->pid = pid;
	change_q_display();
	new_query_auto();
}

void Form1::new_query_auto() {

	mysqlpp::StoreQueryResult res = controller->new_query( Q ); //do knn here
	//change_q_display();
	update_d_displays( res );
	parse_d_features();
	update_vf_counter();
	for( int k = 0; k < 10; k++ ) {
		for( int i =0; i <= 11; i++) {
			if( (int)res[i]["group_index"] == Q->group_index ) {
				D_little_img_objects[i]->rf_pos = true;
				D_little_img_objects[i]->rf_neg = false;
			}
		}

		//change_Q_display();
		//update_D_displays( res );
		//D_object_enlarged = 0;
		//change_large_D_img( 0 );
		//parse_all_D_features();
		process_rf();
	}
}

void Form1::process_rf() {
	//for now, assume that if the feedback's not been set to positive it must be negative
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		if( !D_little_img_objects[i]->rf_pos )
			D_little_img_objects[i]->rf_neg = true;
	}
	mysqlpp::StoreQueryResult res = controller->process_RF( Q, D_little_img_objects );
	querybox->Text = Q->print_info();
	querybox->Refresh();
	//QLrgTextBox->Text = Q->print_info();
	update_d_displays( res );
	//Sleep(3000);
	//D_object_enlarged = 0;
	//change_large_D_img( 0 );
	parse_d_features();
	update_vf_counter();
}

void Form1::new_query() {
	relevance_switch();
	mysqlpp::StoreQueryResult res = controller->new_query( Q ); 
	change_Q_display();
	update_D_displays( res );
	D_object_enlarged = 0;
	change_large_D_img( 0 );
	parse_all_D_features();
	update_vf_counter();
}

void Form1::generate_queries() {
	//the number of specimens from each of the queries' species
	//will be populated by Controller::generate_queries
	array<int>^ num_specimens = gcnew array<int>(NUM_Q_POSSIBILITIES);
	mysqlpp::StoreQueryResult res = controller->generate_queries( num_specimens );
	update_Q_displays( res, num_specimens );
	Q->pid = Q_possibilities[0]->pid;
	this->new_query();
}

void Form1::process_RF() {
	//for now, assume that if the feedback's not been set to positive it must be negative
	int neg = 0;
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		if( !D_img_objects[i]->rf_pos ) {
			D_img_objects[i]->rf_neg = true;
			neg++;
		}
	}
	//if( neg == 12 )
		//return;

	mysqlpp::StoreQueryResult res = controller->process_RF( Q, D_img_objects );
	QLrgTextBox->Text = Q->print_info();

	update_D_displays( res );
	D_object_enlarged = 0;
	change_large_D_img( 0 );
	parse_all_D_features();
	update_vf_counter();
}

void Form1::parse_all_D_features() {
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		D_img_objects[i]->parse_all_features();
	}
}

void Form1::parse_d_features() {
	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		D_little_img_objects[i]->parse_all_features();
	}
}

void Form1::update_vf_counter() {
	this->progressBar1->Value = (controller->get_vf() * 10000) / MAX_VF_NUMBER;
	
	System::Text::StringBuilder ^ temp;
	temp = gcnew System::Text::StringBuilder("");
	temp->Append( "Num of current VF: " );
	temp->Append( (int)controller->get_vf() );
	//Q_possibilities[i]->label->Text = temp->ToString();
	this->label13->Text = temp->ToString();
	this->label13->Refresh();
}
