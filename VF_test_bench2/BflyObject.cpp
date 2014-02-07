#include "StdAfx.h"
#include "BflyObject.h"
#include "Constants.h"

using namespace System::Windows::Forms;

BflyObject::BflyObject(void)
{
}

BflyObject::~BflyObject(void)
{
}

void BflyObject::parse_metadata( mysqlpp::Row r ) {
	
	/*pid = (int)r["pid"];
	mu = (double)r["eta"];
	precision_pre = (double)r["precision_pre"];
	group_index = (int)r["group_index"];*/
	if( !r["photo_bottom"].is_null() ) {
		parse_photos( gcnew System::String((r["photo_top"]).c_str()),
					  gcnew System::String((r["photo_bottom"]).c_str()) );
	} else {
		parse_photos( gcnew System::String((r["photo_top"]).c_str()),
	  				  gcnew System::String("") );
	}

	//other metadata
	pid = (int)r["pid"];
	group_index = (int)r["group_index"];//////////////////////////
	mu = (float)r["eta"];
	precision_pre = (float)r["precision_pre"];
	average_pre = (float)r["average_pre"]; //////////////////////////// 
	local_vf_counter = (int)r["number_of_vf"];////////////////////////
	
}


//parses the photo ids from the database to complete file names
void BflyObject::parse_photos( System::String ^ top, System::String ^ bottom ) {
	
	System::Text::StringBuilder ^ temp = gcnew System::Text::StringBuilder("");
	temp->Append( gcnew System::String( LARGE_IMG_FOLDER ) );
	temp->Append( top );
	temp->Append( ".jpg" );
	
	photo_top.Remove( 0, photo_top.Length );
	photo_top.Append( temp );
	
	temp->Remove( 0, temp->Length );

	temp->Append( gcnew System::String( LARGE_IMG_FOLDER ) );
	temp->Append( bottom );
	temp->Append( ".jpg" );
	
	photo_bottom.Remove( 0, photo_bottom.Length );
	photo_bottom.Append( temp );
	//return;
}


// returns a formatted string of the metadata
System::String ^ BflyObject::print_info() {
	System::Text::StringBuilder ^ temp = gcnew System::Text::StringBuilder( "" );  //////////////////////////////                          
	temp->Append( "pid: " );
	temp->Append( this->pid );
	temp->Append( "\r Group: " );
	temp->Append( this->group_index );
	temp->Append( "\r\nEta: " );
	temp->Append( this->mu );
	temp->Append( "\r\nPrecision_pre: " );
	temp->Append( this->precision_pre );
	temp->Append( "\r\nAverage_precision: " );//////////////////////////////////////////
	temp->Append( this->average_pre );////////////////////////////////////////	
	temp->Append( "\r\nNumber of VFs: ");///////////////////////////
	temp->Append( this->local_vf_counter );///////////////////
	return temp->ToString();
}
