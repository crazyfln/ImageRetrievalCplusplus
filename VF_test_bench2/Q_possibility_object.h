#pragma once

using namespace System::Windows::Forms;

public ref class Q_possibility_object
{
public:
	Q_possibility_object(void);
	Q_possibility_object( PictureBox ^, Label ^ ); 

	PictureBox ^ picBox;
	Label ^ label;
	int pid;

};
