#include "StdAfx.h"
#include "MyView.h"
#include "Constants.h"


MyView::MyView(Form1^ f)
{
	this->form = f;

	//D_img_objects = gcnew array<D_small_display_object ^>(NUM_D_RESULTS);
	//setup_D_objects();

	//Q_possibilities = gcnew array<Q_possibility_object ^>(NUM_Q_POSSIBILITIES);
}

bool MyView::update_D_displays( mysqlpp::StoreQueryResult result ) {

	//form->VF_test_bench2::Form1::update_D_displays( result );
	//form->update_D_displays( result );

	return true;
}

void MyView::setup_D_objects() {
	//D_img_objects[0]->pic = form
	return;
}

void MyView::setup_Q_objects() {
	return;
}