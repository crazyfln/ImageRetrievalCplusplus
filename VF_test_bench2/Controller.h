#pragma once

#include "MyView.h"
#include "Model.h"
#include "BflyObject.h"


public ref class Controller
{
	public:
		Controller(void);
		Controller( Model^, MyView^ );

		//updates the result images displayed on the form
		mysqlpp::StoreQueryResult generate_query( int, int & );
		mysqlpp::StoreQueryResult generate_queries( array<int>^ );
		mysqlpp::StoreQueryResult new_query( BflyObject ^ q );
		mysqlpp::StoreQueryResult process_RF( BflyObject ^ q, array<D_small_display_object ^> ^ );
		int get_vf();

	private:
		MyView^ view;
		Model^ model;
		
		mysqlpp::StoreQueryResult process_RF_no_VFs( BflyObject ^ q, array<D_small_display_object ^> ^ );
		mysqlpp::StoreQueryResult process_RF_with_VFs( BflyObject ^ q, array<D_small_display_object ^> ^ );


};
