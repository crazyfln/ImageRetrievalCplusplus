#include "StdAfx.h"
#include "BflyFeatures.h"
#include "Constants.h"

using namespace System::Windows::Forms;


BflyFeatures::BflyFeatures(void)
{
	pid = 0;
	PFs = gcnew array<double>(NUM_PFS);
	VF_cs = gcnew array<int>(NUM_VFS_PER_IMAGE);
	VF_es = gcnew array<double>(NUM_VFS_PER_IMAGE);
}

BflyFeatures::~BflyFeatures() {}

bool BflyFeatures::has_VFs() {
	if( VF_cs[0] > 0 )
		return true;
	else
		return false;
}


//parses the VFs from the database
void BflyFeatures::parse_VFs() {
	//check that the picture id is valid
	if( pid < 1 || pid > DB_SIZE )
		return;

	try {

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		MessageBox::Show( "Cannot connect to DB.", "Something smells foul..", MessageBoxButtons::OK, MessageBoxIcon::Error );
		return;
	}
	
	mysqlpp::Query query = con.query();

	query << "SELECT * FROM " << BFLY_FEATURES_TABLE << " WHERE pid = " << pid << ";";
	
	mysqlpp::StoreQueryResult result = query.store();

	if( result.empty() ) {
		MessageBox::Show( "Querying for nonexistant image (pid not in db).", "Something smells foul..", MessageBoxButtons::OK, MessageBoxIcon::Error );
		return;
	}

	//update all the VFs
	for( int db_i = DB_INDEX_OF_FIRST_VF, local_i = 0; local_i < NUM_VFS_PER_IMAGE; db_i += 2, local_i++ ) {
		VF_cs[local_i] = (int)result[0][db_i];
		VF_es[local_i] = (double)result[0][db_i + 1];
	}

	return;

	} catch (mysqlpp::Exception e) {
		
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "EXCEPTION!", MessageBoxButtons::OK, MessageBoxIcon::Error );

		exit(2);
	}
}

void BflyFeatures::parse_PFs() {
	//check that the picture id is valid
	if( pid < 1 || pid > DB_SIZE ) {
		MessageBox::Show( "BflyFeatures::parse_PFs: invalid pid", "BflyFeatures::parse_PFs", MessageBoxButtons::OK, MessageBoxIcon::Information );
		return;
	}

	try {

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		MessageBox::Show( "Cannot connect to DB.", "Something smells foul..", MessageBoxButtons::OK, MessageBoxIcon::Error );
		return;
	}
	
	mysqlpp::Query query = con.query();

	query << "SELECT * FROM " << BFLY_FEATURES_TABLE << " WHERE pid = " << pid << ";";
	
	mysqlpp::StoreQueryResult result = query.store();

	if( result.empty() ) {
		MessageBox::Show( "Querying for nonexistant image (pid not in db).", "Something smells foul..", MessageBoxButtons::OK, MessageBoxIcon::Error );
		return;
	}

	//update all the PFs
	for( int i = 0; i < NUM_PFS; i++ ) {
		try {
		PFs[i] = (double) result[0][i+DB_INDEX_OF_FIRST_PF];
		} catch (const mysqlpp::BadConversion& ) {
			//had some issues when MySQL stored the value in scientific notation when it was too small
			//in that case, just set it to zero,
			//this should not cause significant loss in accuracy
			PFs[i] = 0;
		}
	}

	return;

	} catch (mysqlpp::Exception e) {
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "E! QueryImage::parse_PFs()", MessageBoxButtons::OK, MessageBoxIcon::Error );
		//exit(2);
	}
}

void BflyFeatures::parse_all_features() {
	parse_PFs();
	parse_VFs();
}