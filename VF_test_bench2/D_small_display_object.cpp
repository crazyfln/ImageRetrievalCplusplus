#include "StdAfx.h"
#include "D_small_display_object.h"

D_small_display_object::D_small_display_object(void)
: BflyObject()
{
	rf_pos = rf_neg = false;
}

D_small_display_object::D_small_display_object(PictureBox ^ picture, TextBox ^ t, Button ^ rf_plus, Button ^ rf_minus )
: BflyObject()
{
	pic = picture;
	text = t;
	RF_plus_button = rf_plus;
	RF_minus_button = rf_minus;

	rf_pos = rf_neg = false;
}

