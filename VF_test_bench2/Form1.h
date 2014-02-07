#pragma once

#include <mysql++.h>
#include "Controller.h"
#include "MyView.h"
#include "Model.h"
#include "BflyObject.h"

//class MyView;
//class Model;

namespace VF_test_bench2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form {

	public:	Controller^ controller;
			Model^ model;	//defined here for initialization purposes - the form should never call model methods
			MyView^ view;	//defined here for initialization purposes - the form should never call view methods
			
	private://the index of the D_small_display_object in D_img_objects
			//that is enlarged
			int D_object_enlarged;
			BflyObject ^ Q;

			array<D_small_display_object ^> ^ D_img_objects;
			
			array<D_small_display_object ^> ^ D_little_img_objects;
	
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Button^  autorun_button;
	
	array<Q_possibility_object ^> ^ Q_possibilities;
	private: System::Windows::Forms::PictureBox^  query;
	private: System::Windows::Forms::TextBox^  querybox;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label13;

	D_small_display_object ^ Q_possibility;
	
	public:	bool update_D_displays( mysqlpp::StoreQueryResult res );
			bool update_d_displays( mysqlpp::StoreQueryResult res );
			bool update_Q_displays( mysqlpp::StoreQueryResult res, array<int>^ num_specimens );

	private: void setup_D_objects();
			 void setup_Q_objects();
			 void change_large_D_img( int id );
			 void change_D_img( int id );
			 void change_Q_display();
			 void new_query();
			 void process_RF();
			 void generate_queries();
			 void parse_all_D_features();
			 void parse_d_features();
			 void relevance_switch();
			 void autorun( int i );
			 void new_query_auto();
			 void process_rf();
			 void setup_d_objects();
			 void setup_q_objects();
			 void change_q_display();
			 void update_vf_counter();
	
	public:
		Form1(void)
		{
			InitializeComponent();
			
			view = gcnew MyView(this);
			model = gcnew Model();
			controller = gcnew Controller(model, view);
			
			setup_D_objects();
			setup_Q_objects();
			setup_d_objects();
			setup_q_objects();

			D_object_enlarged = 0;

			Q = gcnew BflyObject();

			this->generate_queries();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Control Declarations

////////////////////////// CONTROL DECLARATIONS /////////////////////////////////


	private: System::Windows::Forms::PictureBox^  QLrgPBox;
	private: System::Windows::Forms::PictureBox^  DLrgPBox;
	private: System::Windows::Forms::Button^  RegenQsButton;
	private: System::Windows::Forms::Button^  RFButton;
	private: System::Windows::Forms::PictureBox^  Q1SPBox;
	private: System::Windows::Forms::PictureBox^  Q2SPBox;
	private: System::Windows::Forms::PictureBox^  Q3SPBox;
	private: System::Windows::Forms::PictureBox^  Q4SPBox;
	private: System::Windows::Forms::PictureBox^  Q5SPBox;
	private: System::Windows::Forms::Label^  Label;

	private: System::Windows::Forms::TextBox^  QLrgTextBox;
	private: System::Windows::Forms::TextBox^  DLrgTextBox;
	private: System::Windows::Forms::PictureBox^  DPBox0;
	private: System::Windows::Forms::TextBox^  DText0;









	private: System::Windows::Forms::TextBox^  DText6;

	private: System::Windows::Forms::PictureBox^  DPBox6;






	private: System::Windows::Forms::TextBox^  DText7;

	private: System::Windows::Forms::PictureBox^  DPBox7;






	private: System::Windows::Forms::TextBox^  DText8;

	private: System::Windows::Forms::PictureBox^  DPBox8;






	private: System::Windows::Forms::TextBox^  DText9;

	private: System::Windows::Forms::PictureBox^  DPBox9;






	private: System::Windows::Forms::TextBox^  DText10;

	private: System::Windows::Forms::PictureBox^  DPBox10;






	private: System::Windows::Forms::TextBox^  DText11;

	private: System::Windows::Forms::PictureBox^  DPBox11;






	private: System::Windows::Forms::TextBox^  DText1;


	private: System::Windows::Forms::PictureBox^  DPBox1;






	private: System::Windows::Forms::TextBox^  DText2;


	private: System::Windows::Forms::PictureBox^  DPBox2;







	private: System::Windows::Forms::TextBox^  DText3;


	private: System::Windows::Forms::PictureBox^  DPBox3;






	private: System::Windows::Forms::TextBox^  DText4;


	private: System::Windows::Forms::PictureBox^  DPBox4;






	private: System::Windows::Forms::TextBox^  DText5;


	private: System::Windows::Forms::PictureBox^  DPBox5;

	private: System::Windows::Forms::PictureBox^  Q6SPBox;
	private: System::Windows::Forms::Label^  Q1_label;
	private: System::Windows::Forms::Label^  Q2_label;
	private: System::Windows::Forms::Label^  Q3_label;
	private: System::Windows::Forms::Label^  Q4_label;
	private: System::Windows::Forms::Label^  Q5_label;
	private: System::Windows::Forms::Label^  Q6_label;



//////////////////////////////////////////////////////////////////////////////////
#pragma endregion

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->QLrgPBox = (gcnew System::Windows::Forms::PictureBox());
			this->DLrgPBox = (gcnew System::Windows::Forms::PictureBox());
			this->RegenQsButton = (gcnew System::Windows::Forms::Button());
			this->RFButton = (gcnew System::Windows::Forms::Button());
			this->Q1SPBox = (gcnew System::Windows::Forms::PictureBox());
			this->Q2SPBox = (gcnew System::Windows::Forms::PictureBox());
			this->Q3SPBox = (gcnew System::Windows::Forms::PictureBox());
			this->Q4SPBox = (gcnew System::Windows::Forms::PictureBox());
			this->Q5SPBox = (gcnew System::Windows::Forms::PictureBox());
			this->Label = (gcnew System::Windows::Forms::Label());
			this->QLrgTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DLrgTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DPBox0 = (gcnew System::Windows::Forms::PictureBox());
			this->DText0 = (gcnew System::Windows::Forms::TextBox());
			this->DText6 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->DText7 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->DText8 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->DText9 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->DText10 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->DText11 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->DText1 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->DText2 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->DText3 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->DText4 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->DText5 = (gcnew System::Windows::Forms::TextBox());
			this->DPBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->Q6SPBox = (gcnew System::Windows::Forms::PictureBox());
			this->Q1_label = (gcnew System::Windows::Forms::Label());
			this->Q2_label = (gcnew System::Windows::Forms::Label());
			this->Q3_label = (gcnew System::Windows::Forms::Label());
			this->Q4_label = (gcnew System::Windows::Forms::Label());
			this->Q5_label = (gcnew System::Windows::Forms::Label());
			this->Q6_label = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->autorun_button = (gcnew System::Windows::Forms::Button());
			this->query = (gcnew System::Windows::Forms::PictureBox());
			this->querybox = (gcnew System::Windows::Forms::TextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label13 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->QLrgPBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DLrgPBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q1SPBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q2SPBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q3SPBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q4SPBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q5SPBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q6SPBox))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel12->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->query))->BeginInit();
			this->SuspendLayout();
			// 
			// QLrgPBox
			// 
			this->QLrgPBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->QLrgPBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->QLrgPBox->Location = System::Drawing::Point(205, 12);
			this->QLrgPBox->Name = L"QLrgPBox";
			this->QLrgPBox->Size = System::Drawing::Size(275, 280);
			this->QLrgPBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->QLrgPBox->TabIndex = 0;
			this->QLrgPBox->TabStop = false;
			// 
			// DLrgPBox
			// 
			this->DLrgPBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DLrgPBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DLrgPBox->Location = System::Drawing::Point(489, 12);
			this->DLrgPBox->Name = L"DLrgPBox";
			this->DLrgPBox->Size = System::Drawing::Size(275, 280);
			this->DLrgPBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DLrgPBox->TabIndex = 1;
			this->DLrgPBox->TabStop = false;
			this->DLrgPBox->Click += gcnew System::EventHandler(this, &Form1::DLrgPBox_Click);
			// 
			// RegenQsButton
			// 
			this->RegenQsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RegenQsButton->Location = System::Drawing::Point(13, 12);
			this->RegenQsButton->Name = L"RegenQsButton";
			this->RegenQsButton->Size = System::Drawing::Size(189, 51);
			this->RegenQsButton->TabIndex = 2;
			this->RegenQsButton->Text = L"Regenerate Possible Queries";
			this->RegenQsButton->UseVisualStyleBackColor = true;
			this->RegenQsButton->Click += gcnew System::EventHandler(this, &Form1::RegenQsButton_Click);
			// 
			// RFButton
			// 
			this->RFButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RFButton->Location = System::Drawing::Point(13, 69);
			this->RFButton->Name = L"RFButton";
			this->RFButton->Size = System::Drawing::Size(189, 62);
			this->RFButton->TabIndex = 3;
			this->RFButton->Text = L"Submit\r\nRelevance\r\nFeedback\r\n";
			this->RFButton->UseVisualStyleBackColor = true;
			this->RFButton->Click += gcnew System::EventHandler(this, &Form1::RFButton_Click);
			// 
			// Q1SPBox
			// 
			this->Q1SPBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Q1SPBox->Location = System::Drawing::Point(16, 223);
			this->Q1SPBox->Name = L"Q1SPBox";
			this->Q1SPBox->Size = System::Drawing::Size(64, 67);
			this->Q1SPBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Q1SPBox->TabIndex = 6;
			this->Q1SPBox->TabStop = false;
			this->Q1SPBox->Click += gcnew System::EventHandler(this, &Form1::Q1SPBox_Click);
			// 
			// Q2SPBox
			// 
			this->Q2SPBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Q2SPBox->Location = System::Drawing::Point(16, 296);
			this->Q2SPBox->Name = L"Q2SPBox";
			this->Q2SPBox->Size = System::Drawing::Size(64, 67);
			this->Q2SPBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Q2SPBox->TabIndex = 7;
			this->Q2SPBox->TabStop = false;
			this->Q2SPBox->Click += gcnew System::EventHandler(this, &Form1::Q2SPBox_Click);
			// 
			// Q3SPBox
			// 
			this->Q3SPBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Q3SPBox->Location = System::Drawing::Point(16, 369);
			this->Q3SPBox->Name = L"Q3SPBox";
			this->Q3SPBox->Size = System::Drawing::Size(64, 67);
			this->Q3SPBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Q3SPBox->TabIndex = 8;
			this->Q3SPBox->TabStop = false;
			this->Q3SPBox->Click += gcnew System::EventHandler(this, &Form1::Q3SPBox_Click);
			// 
			// Q4SPBox
			// 
			this->Q4SPBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Q4SPBox->Location = System::Drawing::Point(16, 445);
			this->Q4SPBox->Name = L"Q4SPBox";
			this->Q4SPBox->Size = System::Drawing::Size(64, 67);
			this->Q4SPBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Q4SPBox->TabIndex = 9;
			this->Q4SPBox->TabStop = false;
			this->Q4SPBox->Click += gcnew System::EventHandler(this, &Form1::Q4SPBox_Click);
			// 
			// Q5SPBox
			// 
			this->Q5SPBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Q5SPBox->Location = System::Drawing::Point(16, 518);
			this->Q5SPBox->Name = L"Q5SPBox";
			this->Q5SPBox->Size = System::Drawing::Size(64, 67);
			this->Q5SPBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Q5SPBox->TabIndex = 10;
			this->Q5SPBox->TabStop = false;
			this->Q5SPBox->Click += gcnew System::EventHandler(this, &Form1::Q5SPBox_Click);
			// 
			// Label
			// 
			this->Label->AutoSize = true;
			this->Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Label->Location = System::Drawing::Point(12, 200);
			this->Label->Name = L"Label";
			this->Label->Size = System::Drawing::Size(127, 20);
			this->Label->TabIndex = 11;
			this->Label->Text = L"Choose a Query:";
			// 
			// QLrgTextBox
			// 
			this->QLrgTextBox->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->QLrgTextBox->Location = System::Drawing::Point(205, 298);
			this->QLrgTextBox->Multiline = true;
			this->QLrgTextBox->Name = L"QLrgTextBox";
			this->QLrgTextBox->Size = System::Drawing::Size(275, 83);
			this->QLrgTextBox->TabIndex = 12;
			// 
			// DLrgTextBox
			// 
			this->DLrgTextBox->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DLrgTextBox->Location = System::Drawing::Point(489, 298);
			this->DLrgTextBox->Multiline = true;
			this->DLrgTextBox->Name = L"DLrgTextBox";
			this->DLrgTextBox->Size = System::Drawing::Size(275, 83);
			this->DLrgTextBox->TabIndex = 13;
			// 
			// DPBox0
			// 
			this->DPBox0->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox0->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox0->Location = System::Drawing::Point(797, 12);
			this->DPBox0->Name = L"DPBox0";
			this->DPBox0->Size = System::Drawing::Size(110, 111);
			this->DPBox0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox0->TabIndex = 14;
			this->DPBox0->TabStop = false;
			this->DPBox0->Click += gcnew System::EventHandler(this, &Form1::DPBox0_Click);
			// 
			// DText0
			// 
			this->DText0->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText0->Location = System::Drawing::Point(205, 504);
			this->DText0->Name = L"DText0";
			this->DText0->Size = System::Drawing::Size(128, 20);
			this->DText0->TabIndex = 20;
			// 
			// DText6
			// 
			this->DText6->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText6->Location = System::Drawing::Point(205, 647);
			this->DText6->Name = L"DText6";
			this->DText6->Size = System::Drawing::Size(128, 20);
			this->DText6->TabIndex = 26;
			// 
			// DPBox6
			// 
			this->DPBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox6->Location = System::Drawing::Point(1029, 129);
			this->DPBox6->Name = L"DPBox6";
			this->DPBox6->Size = System::Drawing::Size(110, 111);
			this->DPBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox6->TabIndex = 25;
			this->DPBox6->TabStop = false;
			this->DPBox6->Click += gcnew System::EventHandler(this, &Form1::DPBox6_Click);
			// 
			// DText7
			// 
			this->DText7->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText7->Location = System::Drawing::Point(348, 647);
			this->DText7->Name = L"DText7";
			this->DText7->Size = System::Drawing::Size(128, 20);
			this->DText7->TabIndex = 31;
			// 
			// DPBox7
			// 
			this->DPBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox7->Location = System::Drawing::Point(1145, 129);
			this->DPBox7->Name = L"DPBox7";
			this->DPBox7->Size = System::Drawing::Size(110, 111);
			this->DPBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox7->TabIndex = 30;
			this->DPBox7->TabStop = false;
			this->DPBox7->Click += gcnew System::EventHandler(this, &Form1::DPBox7_Click);
			// 
			// DText8
			// 
			this->DText8->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText8->Location = System::Drawing::Point(489, 647);
			this->DText8->Name = L"DText8";
			this->DText8->Size = System::Drawing::Size(128, 20);
			this->DText8->TabIndex = 36;
			// 
			// DPBox8
			// 
			this->DPBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox8->Location = System::Drawing::Point(797, 246);
			this->DPBox8->Name = L"DPBox8";
			this->DPBox8->Size = System::Drawing::Size(110, 111);
			this->DPBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox8->TabIndex = 35;
			this->DPBox8->TabStop = false;
			this->DPBox8->Click += gcnew System::EventHandler(this, &Form1::DPBox8_Click);
			// 
			// DText9
			// 
			this->DText9->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText9->Location = System::Drawing::Point(626, 647);
			this->DText9->Name = L"DText9";
			this->DText9->Size = System::Drawing::Size(128, 20);
			this->DText9->TabIndex = 41;
			// 
			// DPBox9
			// 
			this->DPBox9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox9->Location = System::Drawing::Point(913, 246);
			this->DPBox9->Name = L"DPBox9";
			this->DPBox9->Size = System::Drawing::Size(110, 111);
			this->DPBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox9->TabIndex = 40;
			this->DPBox9->TabStop = false;
			this->DPBox9->Click += gcnew System::EventHandler(this, &Form1::DPBox9_Click);
			// 
			// DText10
			// 
			this->DText10->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText10->Location = System::Drawing::Point(771, 647);
			this->DText10->Name = L"DText10";
			this->DText10->Size = System::Drawing::Size(128, 20);
			this->DText10->TabIndex = 46;
			// 
			// DPBox10
			// 
			this->DPBox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox10->Location = System::Drawing::Point(1029, 246);
			this->DPBox10->Name = L"DPBox10";
			this->DPBox10->Size = System::Drawing::Size(110, 111);
			this->DPBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox10->TabIndex = 45;
			this->DPBox10->TabStop = false;
			this->DPBox10->Click += gcnew System::EventHandler(this, &Form1::DPBox10_Click);
			// 
			// DText11
			// 
			this->DText11->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText11->Location = System::Drawing::Point(909, 647);
			this->DText11->Name = L"DText11";
			this->DText11->Size = System::Drawing::Size(128, 20);
			this->DText11->TabIndex = 51;
			// 
			// DPBox11
			// 
			this->DPBox11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox11->Location = System::Drawing::Point(1145, 246);
			this->DPBox11->Name = L"DPBox11";
			this->DPBox11->Size = System::Drawing::Size(110, 111);
			this->DPBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox11->TabIndex = 50;
			this->DPBox11->TabStop = false;
			this->DPBox11->Click += gcnew System::EventHandler(this, &Form1::DPBox11_Click);
			// 
			// DText1
			// 
			this->DText1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText1->Location = System::Drawing::Point(348, 504);
			this->DText1->Name = L"DText1";
			this->DText1->Size = System::Drawing::Size(128, 20);
			this->DText1->TabIndex = 56;
			// 
			// DPBox1
			// 
			this->DPBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox1->Location = System::Drawing::Point(913, 12);
			this->DPBox1->Name = L"DPBox1";
			this->DPBox1->Size = System::Drawing::Size(110, 111);
			this->DPBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox1->TabIndex = 55;
			this->DPBox1->TabStop = false;
			this->DPBox1->Click += gcnew System::EventHandler(this, &Form1::DPBox1_Click);
			// 
			// DText2
			// 
			this->DText2->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText2->Location = System::Drawing::Point(489, 504);
			this->DText2->Name = L"DText2";
			this->DText2->Size = System::Drawing::Size(128, 20);
			this->DText2->TabIndex = 61;
			// 
			// DPBox2
			// 
			this->DPBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox2->Location = System::Drawing::Point(1029, 12);
			this->DPBox2->Name = L"DPBox2";
			this->DPBox2->Size = System::Drawing::Size(110, 111);
			this->DPBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox2->TabIndex = 60;
			this->DPBox2->TabStop = false;
			this->DPBox2->Click += gcnew System::EventHandler(this, &Form1::DPBox2_Click);
			// 
			// DText3
			// 
			this->DText3->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText3->Location = System::Drawing::Point(626, 504);
			this->DText3->Name = L"DText3";
			this->DText3->Size = System::Drawing::Size(128, 20);
			this->DText3->TabIndex = 66;
			// 
			// DPBox3
			// 
			this->DPBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox3->Location = System::Drawing::Point(1145, 12);
			this->DPBox3->Name = L"DPBox3";
			this->DPBox3->Size = System::Drawing::Size(110, 111);
			this->DPBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox3->TabIndex = 65;
			this->DPBox3->TabStop = false;
			this->DPBox3->Click += gcnew System::EventHandler(this, &Form1::DPBox3_Click);
			// 
			// DText4
			// 
			this->DText4->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText4->Location = System::Drawing::Point(771, 504);
			this->DText4->Name = L"DText4";
			this->DText4->Size = System::Drawing::Size(128, 20);
			this->DText4->TabIndex = 71;
			// 
			// DPBox4
			// 
			this->DPBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox4->Location = System::Drawing::Point(797, 129);
			this->DPBox4->Name = L"DPBox4";
			this->DPBox4->Size = System::Drawing::Size(110, 111);
			this->DPBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox4->TabIndex = 70;
			this->DPBox4->TabStop = false;
			this->DPBox4->Click += gcnew System::EventHandler(this, &Form1::DPBox4_Click);
			// 
			// DText5
			// 
			this->DText5->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DText5->Location = System::Drawing::Point(909, 504);
			this->DText5->Name = L"DText5";
			this->DText5->Size = System::Drawing::Size(128, 20);
			this->DText5->TabIndex = 76;
			// 
			// DPBox5
			// 
			this->DPBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DPBox5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DPBox5->Location = System::Drawing::Point(913, 129);
			this->DPBox5->Name = L"DPBox5";
			this->DPBox5->Size = System::Drawing::Size(110, 111);
			this->DPBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DPBox5->TabIndex = 75;
			this->DPBox5->TabStop = false;
			this->DPBox5->Click += gcnew System::EventHandler(this, &Form1::DPBox5_Click);
			// 
			// Q6SPBox
			// 
			this->Q6SPBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Q6SPBox->Location = System::Drawing::Point(16, 591);
			this->Q6SPBox->Name = L"Q6SPBox";
			this->Q6SPBox->Size = System::Drawing::Size(64, 67);
			this->Q6SPBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Q6SPBox->TabIndex = 80;
			this->Q6SPBox->TabStop = false;
			this->Q6SPBox->Click += gcnew System::EventHandler(this, &Form1::Q6SPBox_Click);
			// 
			// Q1_label
			// 
			this->Q1_label->AutoSize = true;
			this->Q1_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Q1_label->Location = System::Drawing::Point(86, 223);
			this->Q1_label->Name = L"Q1_label";
			this->Q1_label->Size = System::Drawing::Size(87, 51);
			this->Q1_label->TabIndex = 81;
			this->Q1_label->Text = L"Chiodies\ncatillus\n5 specimens";
			// 
			// Q2_label
			// 
			this->Q2_label->AutoSize = true;
			this->Q2_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Q2_label->Location = System::Drawing::Point(87, 296);
			this->Q2_label->Name = L"Q2_label";
			this->Q2_label->Size = System::Drawing::Size(87, 51);
			this->Q2_label->TabIndex = 82;
			this->Q2_label->Text = L"Chiodies\ncatillus\n5 specimens";
			// 
			// Q3_label
			// 
			this->Q3_label->AutoSize = true;
			this->Q3_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Q3_label->Location = System::Drawing::Point(87, 369);
			this->Q3_label->Name = L"Q3_label";
			this->Q3_label->Size = System::Drawing::Size(87, 51);
			this->Q3_label->TabIndex = 83;
			this->Q3_label->Text = L"Chiodies\ncatillus\n5 specimens";
			// 
			// Q4_label
			// 
			this->Q4_label->AutoSize = true;
			this->Q4_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Q4_label->Location = System::Drawing::Point(87, 445);
			this->Q4_label->Name = L"Q4_label";
			this->Q4_label->Size = System::Drawing::Size(87, 51);
			this->Q4_label->TabIndex = 84;
			this->Q4_label->Text = L"Chiodies\ncatillus\n5 specimens";
			// 
			// Q5_label
			// 
			this->Q5_label->AutoSize = true;
			this->Q5_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Q5_label->Location = System::Drawing::Point(87, 518);
			this->Q5_label->Name = L"Q5_label";
			this->Q5_label->Size = System::Drawing::Size(87, 51);
			this->Q5_label->TabIndex = 85;
			this->Q5_label->Text = L"Chiodies\ncatillus\n5 specimens";

			// 
			// Q6_label
			// 
			this->Q6_label->AutoSize = true;
			this->Q6_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Q6_label->Location = System::Drawing::Point(87, 591);
			this->Q6_label->Name = L"Q6_label";
			this->Q6_label->Size = System::Drawing::Size(87, 51);
			this->Q6_label->TabIndex = 86;
			this->Q6_label->Text = L"Chiodies\ncatillus\n5 specimens";
			// 
			// panel1
			// 
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(205, 387);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(110, 111);
			this->panel1->TabIndex = 88;
			this->panel1->Click += gcnew System::EventHandler(this, &Form1::Panel1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(41, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"R";
			// 
			// panel2
			// 
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(348, 387);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(110, 111);
			this->panel2->TabIndex = 89;
			this->panel2->Click += gcnew System::EventHandler(this, &Form1::Panel2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(44, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"R";
			// 
			// panel3
			// 
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel3->Controls->Add(this->label3);
			this->panel3->Location = System::Drawing::Point(489, 387);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(110, 111);
			this->panel3->TabIndex = 90;
			this->panel3->Click += gcnew System::EventHandler(this, &Form1::Panel3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(42, 44);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 29);
			this->label3->TabIndex = 2;
			this->label3->Text = L"R";
			// 
			// panel4
			// 
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->label4);
			this->panel4->Location = System::Drawing::Point(626, 387);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(110, 111);
			this->panel4->TabIndex = 91;
			this->panel4->Click += gcnew System::EventHandler(this, &Form1::Panel4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(43, 44);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"R";
			// 
			// panel5
			// 
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->label5);
			this->panel5->Location = System::Drawing::Point(771, 387);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(110, 111);
			this->panel5->TabIndex = 92;
			this->panel5->Click += gcnew System::EventHandler(this, &Form1::Panel5_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(41, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 29);
			this->label5->TabIndex = 4;
			this->label5->Text = L"R";
			// 
			// panel6
			// 
			this->panel6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel6->Controls->Add(this->label6);
			this->panel6->Location = System::Drawing::Point(909, 387);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(110, 111);
			this->panel6->TabIndex = 93;
			this->panel6->Click += gcnew System::EventHandler(this, &Form1::Panel6_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(44, 44);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 29);
			this->label6->TabIndex = 5;
			this->label6->Text = L"R";
			// 
			// panel7
			// 
			this->panel7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel7->Controls->Add(this->label7);
			this->panel7->Location = System::Drawing::Point(205, 530);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(110, 111);
			this->panel7->TabIndex = 89;
			this->panel7->Click += gcnew System::EventHandler(this, &Form1::Panel7_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(41, 47);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 29);
			this->label7->TabIndex = 95;
			this->label7->Text = L"R";
			// 
			// panel8
			// 
			this->panel8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel8->Controls->Add(this->label8);
			this->panel8->Location = System::Drawing::Point(348, 530);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(110, 111);
			this->panel8->TabIndex = 94;
			this->panel8->Click += gcnew System::EventHandler(this, &Form1::Panel8_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Red;
			this->label8->Location = System::Drawing::Point(44, 47);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(31, 29);
			this->label8->TabIndex = 96;
			this->label8->Text = L"R";
			// 
			// panel9
			// 
			this->panel9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel9->Controls->Add(this->label9);
			this->panel9->Location = System::Drawing::Point(489, 530);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(110, 111);
			this->panel9->TabIndex = 90;
			this->panel9->Click += gcnew System::EventHandler(this, &Form1::Panel9_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Red;
			this->label9->Location = System::Drawing::Point(42, 47);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(31, 29);
			this->label9->TabIndex = 95;
			this->label9->Text = L"R";
			// 
			// panel10
			// 
			this->panel10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel10->Controls->Add(this->label10);
			this->panel10->Location = System::Drawing::Point(626, 530);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(110, 111);
			this->panel10->TabIndex = 90;
			this->panel10->Click += gcnew System::EventHandler(this, &Form1::Panel10_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Red;
			this->label10->Location = System::Drawing::Point(43, 47);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(31, 29);
			this->label10->TabIndex = 96;
			this->label10->Text = L"R";
			// 
			// panel11
			// 
			this->panel11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel11->Controls->Add(this->label11);
			this->panel11->Location = System::Drawing::Point(771, 530);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(110, 111);
			this->panel11->TabIndex = 90;
			this->panel11->Click += gcnew System::EventHandler(this, &Form1::Panel11_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Red;
			this->label11->Location = System::Drawing::Point(41, 47);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(31, 29);
			this->label11->TabIndex = 97;
			this->label11->Text = L"R";
			// 
			// panel12
			// 
			this->panel12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel12->Controls->Add(this->label12);
			this->panel12->Location = System::Drawing::Point(909, 530);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(110, 111);
			this->panel12->TabIndex = 90;
			this->panel12->Click += gcnew System::EventHandler(this, &Form1::Panel12_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Red;
			this->label12->Location = System::Drawing::Point(44, 47);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(31, 29);
			this->label12->TabIndex = 98;
			this->label12->Text = L"R";
			// 
			// autorun_button
			// 
			this->autorun_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->autorun_button->Location = System::Drawing::Point(16, 135);
			this->autorun_button->Name = L"autorun_button";
			this->autorun_button->Size = System::Drawing::Size(185, 40);
			this->autorun_button->TabIndex = 95;
			this->autorun_button->Text = L"Autorun";
			this->autorun_button->UseVisualStyleBackColor = true;
			this->autorun_button->Click += gcnew System::EventHandler(this, &Form1::autorun_button_Click);
			// 
			// query
			// 
			this->query->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->query->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->query->Location = System::Drawing::Point(1056, 381);
			this->query->Name = L"query";
			this->query->Size = System::Drawing::Size(118, 120);
			this->query->TabIndex = 96;
			this->query->TabStop = false;
			// 
			// querybox
			// 
			this->querybox->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->querybox->Location = System::Drawing::Point(1056, 524);
			this->querybox->Multiline = true;
			this->querybox->Name = L"querybox";
			this->querybox->Size = System::Drawing::Size(228, 80);
			this->querybox->TabIndex = 97;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(16, 673);
			this->progressBar1->Maximum = 10000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(1021, 20);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 98;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(1053, 673);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(41, 13);
			this->label13->TabIndex = 99;
			this->label13->Text = L"label13";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1276, 692);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->querybox);
			this->Controls->Add(this->query);
			this->Controls->Add(this->autorun_button);
			this->Controls->Add(this->panel12);
			this->Controls->Add(this->panel11);
			this->Controls->Add(this->panel10);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->Q6_label);
			this->Controls->Add(this->Q5_label);
			this->Controls->Add(this->Q4_label);
			this->Controls->Add(this->Q3_label);
			this->Controls->Add(this->Q2_label);
			this->Controls->Add(this->Q1_label);
			this->Controls->Add(this->Q6SPBox);
			this->Controls->Add(this->DText5);
			this->Controls->Add(this->DPBox5);
			this->Controls->Add(this->DText4);
			this->Controls->Add(this->DPBox4);
			this->Controls->Add(this->DText3);
			this->Controls->Add(this->DPBox3);
			this->Controls->Add(this->DText2);
			this->Controls->Add(this->DPBox2);
			this->Controls->Add(this->DText1);
			this->Controls->Add(this->DPBox1);
			this->Controls->Add(this->DText11);
			this->Controls->Add(this->DPBox11);
			this->Controls->Add(this->DText10);
			this->Controls->Add(this->DPBox10);
			this->Controls->Add(this->DText9);
			this->Controls->Add(this->DPBox9);
			this->Controls->Add(this->DText8);
			this->Controls->Add(this->DPBox8);
			this->Controls->Add(this->DText7);
			this->Controls->Add(this->DPBox7);
			this->Controls->Add(this->DText6);
			this->Controls->Add(this->DPBox6);
			this->Controls->Add(this->DText0);
			this->Controls->Add(this->DPBox0);
			this->Controls->Add(this->DLrgTextBox);
			this->Controls->Add(this->QLrgTextBox);
			this->Controls->Add(this->Label);
			this->Controls->Add(this->Q5SPBox);
			this->Controls->Add(this->Q4SPBox);
			this->Controls->Add(this->Q3SPBox);
			this->Controls->Add(this->Q2SPBox);
			this->Controls->Add(this->Q1SPBox);
			this->Controls->Add(this->RFButton);
			this->Controls->Add(this->RegenQsButton);
			this->Controls->Add(this->DLrgPBox);
			this->Controls->Add(this->QLrgPBox);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->TopMost = true;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->QLrgPBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DLrgPBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q1SPBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q2SPBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q3SPBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q4SPBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q5SPBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Q6SPBox))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->query))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


#pragma region Query Image Click Events
//////////////////////////// QUERY IMAGE CLICK EVENTS /////////////////////////////////////////

private: System::Void Q1SPBox_Click(System::Object^  sender, System::EventArgs^  e) {
			 Q->pid = Q_possibilities[0]->pid;
			 this->new_query();
		 }

		 System::Void Q2SPBox_Click(System::Object^  sender, System::EventArgs^  e) {
			 Q->pid = Q_possibilities[1]->pid;
			 this->new_query();
		 }

		 System::Void Q3SPBox_Click(System::Object^  sender, System::EventArgs^  e) { 
			 Q->pid = Q_possibilities[2]->pid;
			 this->new_query();
		 }

		 System::Void Q4SPBox_Click(System::Object^  sender, System::EventArgs^  e) {
			 Q->pid = Q_possibilities[3]->pid;
			 this->new_query();
		 }

		 System::Void Q5SPBox_Click(System::Object^  sender, System::EventArgs^  e) {
			 Q->pid = Q_possibilities[4]->pid;
			 this->new_query();
		 }

		 System::Void Q6SPBox_Click(System::Object^  sender, System::EventArgs^  e) {
			 Q->pid = Q_possibilities[5]->pid;
			 this->new_query();
		 }

//////////////////////////////////////////////////////////////////////////////////////////////
#pragma endregion


		 System::Void RFButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->relevance_switch();
			 this->process_RF();		  
		 }

		 System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
		 System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

		System::Void DLrgPBox_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void RegenQsButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->generate_queries();
		 }


#pragma region Displayed DB image click events
///////////////////////// DISPLAYED DATABASE IMAGE CLICKS //////////////////////////////////


private: System::Void DPBox0_Click(System::Object^  sender, System::EventArgs^  e) {
			 //D_object_enlarged = 0;
			 change_D_img( 0 );
		 }
private: System::Void DPBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 //D_object_enlarged = 1;
			 change_D_img( 1 );
		 }
private: System::Void DPBox2_Click(System::Object^  sender, System::EventArgs^  e) {
			 //D_object_enlarged = 2;
			 change_D_img( 2 );
		 }
private: System::Void DPBox3_Click(System::Object^  sender, System::EventArgs^  e) {
			 //D_object_enlarged = 3;
			 change_D_img( 3 );
		 }
private: System::Void DPBox4_Click(System::Object^  sender, System::EventArgs^  e) {
			//D_object_enlarged = 4; 
			change_D_img( 4 );
		 }
private: System::Void DPBox5_Click(System::Object^  sender, System::EventArgs^  e) {
			//D_object_enlarged = 5;
			change_D_img( 5 );
		 }
private: System::Void DPBox6_Click(System::Object^  sender, System::EventArgs^  e) {
			//D_object_enlarged = 6;
			change_D_img( 6 );
		 }
private: System::Void DPBox7_Click(System::Object^  sender, System::EventArgs^  e) {
			//D_object_enlarged = 7;
			change_D_img( 7 );
		 }
private: System::Void DPBox8_Click(System::Object^  sender, System::EventArgs^  e) {
			//D_object_enlarged = 8;
			change_D_img( 8 );
		 }
private: System::Void DPBox9_Click(System::Object^  sender, System::EventArgs^  e) {
			//D_object_enlarged = 9;
			change_D_img( 9 );
		 }
private: System::Void DPBox10_Click(System::Object^  sender, System::EventArgs^  e) {
			
			change_D_img( 10 );
		 }
private: System::Void DPBox11_Click(System::Object^  sender, System::EventArgs^  e) {
			
			change_D_img( 11 );
		 }

#pragma endregion

#pragma region Radio Button Events

/////////////////////////// RADIO BUTTONS ///////////////////////////////////////

//private: System::Void TopViewRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
//			change_large_D_img( D_object_enlarged );
//			change_Q_display();
//		 }
//private: System::Void BottomViewRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
//			change_large_D_img( D_object_enlarged );
//			change_Q_display();
//		 }
#pragma endregion


#pragma region RF button clicks

private: System::Void RF_P0_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[0]->rf_pos = true;
			 D_img_objects[0]->rf_neg = false;
		 }
private: System::Void RF_N0_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[0]->rf_pos = false;
			 D_img_objects[0]->rf_neg = true;
		 }
private: System::Void RF_P1_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[1]->rf_pos = true;
			 D_img_objects[1]->rf_neg = false;
		 }
private: System::Void RF_N1_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[1]->rf_pos = false;
			 D_img_objects[1]->rf_neg = true;
		 }
private: System::Void RF_P2_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[2]->rf_pos = true;
			 D_img_objects[2]->rf_neg = false;
		 }
private: System::Void RF_N2_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[2]->rf_pos = false;
			 D_img_objects[2]->rf_neg = true;
		 }
private: System::Void RF_P3_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[3]->rf_pos = true;
			 D_img_objects[3]->rf_neg = false;
		 }
private: System::Void RF_N3_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[3]->rf_pos = false;
			 D_img_objects[3]->rf_neg = true;
		 }
private: System::Void RF_P4_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[4]->rf_pos = true;
			 D_img_objects[4]->rf_neg = false;
		 }
private: System::Void RF_N4_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[4]->rf_pos = false;
			 D_img_objects[4]->rf_neg = true;
		 }
private: System::Void RF_P5_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[5]->rf_pos = true;
			 D_img_objects[5]->rf_neg = false;
		 }
private: System::Void RF_N5_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[5]->rf_pos = false;
			 D_img_objects[5]->rf_neg = true;
		 }
private: System::Void RF_P6_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[6]->rf_pos = true;
			 D_img_objects[6]->rf_neg = false;
		 }
private: System::Void RF_N6_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[6]->rf_pos = false;
			 D_img_objects[6]->rf_neg = true;
		 }
private: System::Void RF_P7_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[7]->rf_pos = true;
			 D_img_objects[7]->rf_neg = false;
		 }
private: System::Void RF_N7_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[7]->rf_pos = false;
			 D_img_objects[7]->rf_neg = true;
		 }
private: System::Void RF_P8_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[8]->rf_pos = true;
			 D_img_objects[8]->rf_neg = false;
		 }
private: System::Void RF_N8_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[8]->rf_pos = false;
			 D_img_objects[8]->rf_neg = true;
		 }
private: System::Void RF_P9_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[9]->rf_pos = true;
			 D_img_objects[9]->rf_neg = false;
		 }
private: System::Void RF_N9_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[9]->rf_pos = false;
			 D_img_objects[9]->rf_neg = true;
		 }
private: System::Void RF_P10_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[10]->rf_pos = true;
			 D_img_objects[10]->rf_neg = false;
		 }
private: System::Void RF_N10_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[10]->rf_pos = false;
			 D_img_objects[10]->rf_neg = true;
		 }
private: System::Void RF_P11_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[11]->rf_pos = true;
			 D_img_objects[11]->rf_neg = false;
		 }
private: System::Void RF_N11_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_img_objects[11]->rf_pos = false;
			 D_img_objects[11]->rf_neg = true;
		 }

#pragma endregion

private: System::Void Panel1_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 0;
		change_large_D_img( 0 );
			//this->pictureBox1->BringToFront();
		if( this->label1->Visible == false ) {
			this->label1->Visible = true;
			D_img_objects[0]->rf_pos = true;
			D_img_objects[0]->rf_neg = false;
		}
		else if( this->label1->Visible == true ) {
			this->label1->Visible = false;
			D_img_objects[0]->rf_pos = false;
			D_img_objects[0]->rf_neg = true;
		}
}
private: System::Void Panel2_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 1;
		change_large_D_img( 1 );
			//this->pictureBox1->BringToFront();
		if( this->label2->Visible == false ) {
			this->label2->Visible = true;
			D_img_objects[1]->rf_pos = true;
			D_img_objects[1]->rf_neg = false;
		}
		else if( this->label2->Visible == true ) {
			this->label2->Visible = false;
			D_img_objects[1]->rf_pos = false;
			D_img_objects[1]->rf_neg = true;
		}
}

 private: System::Void Panel3_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 2;
		change_large_D_img( 2 );
			//this->pictureBox1->BringToFront();
		if( this->label3->Visible == false ) {
			this->label3->Visible = true;
			D_img_objects[2]->rf_pos = true;
			D_img_objects[2]->rf_neg = false;
		}
		else if( this->label3->Visible == true ) {
			this->label3->Visible = false;
			D_img_objects[2]->rf_pos = false;
			D_img_objects[2]->rf_neg = true;
		}
}

private: System::Void Panel4_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 3;
		change_large_D_img( 3 );
			//this->pictureBox1->BringToFront();
		if( this->label4->Visible == false ) {
			this->label4->Visible = true;
			D_img_objects[3]->rf_pos = true;
			D_img_objects[3]->rf_neg = false;
		}
		else if( this->label4->Visible == true ) {
			this->label4->Visible = false;
			D_img_objects[3]->rf_pos = false;
			D_img_objects[3]->rf_neg = true;
		}
}

private: System::Void Panel5_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 4;
		change_large_D_img( 4 );
			//this->pictureBox1->BringToFront();
		if( this->label5->Visible == false ) {
			this->label5->Visible = true;
			D_img_objects[4]->rf_pos = true;
			D_img_objects[4]->rf_neg = false;
		}
		else if( this->label5->Visible == true ) {
			this->label5->Visible = false;
			D_img_objects[4]->rf_pos = false;
			D_img_objects[4]->rf_neg = true;
		}
}

private: System::Void Panel6_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 5;
		change_large_D_img( 5 );
			//this->pictureBox1->BringToFront();
		if( this->label6->Visible == false ) {
			this->label6->Visible = true;
			D_img_objects[5]->rf_pos = true;
			D_img_objects[5]->rf_neg = false;
		}
		else if( this->label6->Visible == true ) {
			this->label6->Visible = false;
			D_img_objects[5]->rf_pos = false;
			D_img_objects[5]->rf_neg = true;
		}
}

private: System::Void Panel7_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 6;
		change_large_D_img( 6 );
			//this->pictureBox1->BringToFront();
		if( this->label7->Visible == false ) {
			this->label7->Visible = true;
			D_img_objects[6]->rf_pos = true;
			D_img_objects[6]->rf_neg = false;
		}
		else if( this->label7->Visible == true ) {
			this->label7->Visible = false;
			D_img_objects[6]->rf_pos = false;
			D_img_objects[6]->rf_neg = true;
		}
}

private: System::Void Panel8_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 7;
		change_large_D_img( 7 );
			//this->pictureBox1->BringToFront();
		if( this->label8->Visible == false ) {
			this->label8->Visible = true;
			D_img_objects[7]->rf_pos = true;
			D_img_objects[7]->rf_neg = false;
		}
		else if( this->label8->Visible == true ) {
			this->label8->Visible = false;
			D_img_objects[7]->rf_pos = false;
			D_img_objects[7]->rf_neg = true;
		}
}

private: System::Void Panel9_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 8;
		change_large_D_img( 8 );
			//this->pictureBox1->BringToFront();
		if( this->label9->Visible == false ) {
			this->label9->Visible = true;
			D_img_objects[8]->rf_pos = true;
			D_img_objects[8]->rf_neg = false;
		}
		else if( this->label9->Visible == true ) {
			this->label9->Visible = false;
			D_img_objects[8]->rf_pos = false;
			D_img_objects[8]->rf_neg = true;
		}
}

private: System::Void Panel10_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 9;
		change_large_D_img( 9 );
			//this->pictureBox1->BringToFront();
		if( this->label10->Visible == false ) {
			this->label10->Visible = true;
			D_img_objects[9]->rf_pos = true;
			D_img_objects[9]->rf_neg = false;
		}
		else if( this->label10->Visible == true ) {
			this->label10->Visible = false;
			D_img_objects[9]->rf_pos = false;
			D_img_objects[9]->rf_neg = true;
		}
}

private: System::Void Panel11_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 10;
		change_large_D_img( 10 );
			//this->pictureBox1->BringToFront();
		if( this->label11->Visible == false ) {
			this->label11->Visible = true;
			D_img_objects[10]->rf_pos = true;
			D_img_objects[10]->rf_neg = false;
		}
		else if( this->label11->Visible == true ) {
			this->label11->Visible = false;
			D_img_objects[10]->rf_pos = false;
			D_img_objects[10]->rf_neg = true;
		}
}

private: System::Void Panel12_Click(System::Object^  sender, System::EventArgs^  e) {
		D_object_enlarged = 11;
		change_large_D_img( 11 );
			//this->pictureBox1->BringToFront();
		if( this->label12->Visible == false ) {
			this->label12->Visible = true;
			D_img_objects[11]->rf_pos = true;
			D_img_objects[11]->rf_neg = false;
		}
		else if( this->label12->Visible == true ) {
			this->label12->Visible = false;
			D_img_objects[11]->rf_pos = false;
			D_img_objects[11]->rf_neg = true;
		}
}
private: System::Void autorun_button_Click(System::Object^  sender, System::EventArgs^  e) {
		int i = 15;
		this->autorun( i );
}

};
}