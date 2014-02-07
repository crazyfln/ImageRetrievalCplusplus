#pragma once

#include "BflyObject.h"

using namespace System::Windows::Forms;

public ref class D_small_display_object : public BflyObject
{
public:
	D_small_display_object(void);
	D_small_display_object( PictureBox^, TextBox^, Button^, Button^ );

	PictureBox^ pic;
	Panel^ Pic;
	TextBox^ text;
	Button^ RF_plus_button;
	Button^ RF_minus_button;

	bool rf_pos;
	bool rf_neg;
};
