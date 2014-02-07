#pragma once

#include <mysql++.h>
#include "Model.h"
#include "D_small_display_object.h"
#include "Constants.h"
#include "Q_possibility_object.h"

/*namespace mysqlpp {
	class StoreQueryResult;
}*/

namespace VF_test_bench2 {
	ref class Form1;// {
	//	bool update_D_displays( mysqlpp::StoreQueryResult );
	//}
}

using namespace VF_test_bench2;

public ref class MyView
{
public:
	//MyView();
	MyView( Form1^ f );
	//array<D_small_display_object ^> ^ D_img_objects;
	//array<Q_possibility_object ^> ^ Q_possibilities;

	bool update_D_displays( mysqlpp::StoreQueryResult res );
	

private:
	Form1^ form;
	void setup_D_objects();
	void setup_Q_objects();

};