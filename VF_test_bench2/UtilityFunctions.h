/*#pragma once

#include <mysql++.h>
#include "Constants.h"

using namespace System::Windows::Forms;

mysqlpp::Connection get_db_connection() {
	try {

	mysqlpp::Connection con( BFLY_DB, BFLY_DB_SERVER, BFLY_DB_USER, BFLY_DB_PASS );
	
	if( !con.connected() ) {
		std::cout << "\n\nFAILED TO CONNECT TO DB. EXITING. (press return)\n";
		std::getchar();
		exit(1);
	}

	return con;

	} catch ( mysqlpp::Exception e ) {
		System::String ^ e_string = gcnew System::String( e.what() );
		MessageBox::Show( e_string, "UtilityFunctions::get_db_connection", MessageBoxButtons::OK, MessageBoxIcon::Error );
		exit(2);
	}
}
*/