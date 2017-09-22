#pragma once
#include "DBhandle.h"
#include "Connect2Kinect.h"

namespace Project1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de TrainingMode
	/// </summary>
	
	
	public ref class TrainingMode : public System::Windows::Forms::Form
	{
	public:
		TrainingMode()
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		
		System::String^ currentform;
		System::String^ currentpos;
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~TrainingMode()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  formtitle;
	protected:

	private: System::Windows::Forms::Label^  title;
	private: System::Windows::Forms::PictureBox^  trainingimage;




	private: System::Windows::Forms::Panel^  panel1;





	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  form3;

	private: System::Windows::Forms::PictureBox^  form2;

	private: System::Windows::Forms::PictureBox^  form1;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  postitle;





	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::PictureBox^  home;
	private: System::Windows::Forms::Label^  loading;


	private: System::Windows::Forms::PictureBox^  newform;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  finalpos;

	private: System::Windows::Forms::PictureBox^  centralpos;

	private: System::Windows::Forms::PictureBox^  initialpos;
	private: System::Windows::Forms::PictureBox^  back;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TrainingMode::typeid));
			this->formtitle = (gcnew System::Windows::Forms::Label());
			this->title = (gcnew System::Windows::Forms::Label());
			this->trainingimage = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->newform = (gcnew System::Windows::Forms::PictureBox());
			this->form3 = (gcnew System::Windows::Forms::PictureBox());
			this->form2 = (gcnew System::Windows::Forms::PictureBox());
			this->form1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->home = (gcnew System::Windows::Forms::PictureBox());
			this->loading = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->back = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->finalpos = (gcnew System::Windows::Forms::PictureBox());
			this->centralpos = (gcnew System::Windows::Forms::PictureBox());
			this->initialpos = (gcnew System::Windows::Forms::PictureBox());
			this->postitle = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trainingimage))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->newform))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->form3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->form2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->form1))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->home))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->finalpos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->centralpos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->initialpos))->BeginInit();
			this->SuspendLayout();
			// 
			// formtitle
			// 
			this->formtitle->AutoSize = true;
			this->formtitle->Location = System::Drawing::Point(32, 13);
			this->formtitle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->formtitle->Name = L"formtitle";
			this->formtitle->Size = System::Drawing::Size(96, 17);
			this->formtitle->TabIndex = 0;
			this->formtitle->Text = L"Pick a Form!";
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Location = System::Drawing::Point(359, 30);
			this->title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(136, 20);
			this->title->TabIndex = 1;
			this->title->Text = L"TRAINING MODE";
			// 
			// trainingimage
			// 
			this->trainingimage->BackColor = System::Drawing::Color::Transparent;
			this->trainingimage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"trainingimage.Image")));
			this->trainingimage->Location = System::Drawing::Point(363, 85);
			this->trainingimage->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->trainingimage->Name = L"trainingimage";
			this->trainingimage->Size = System::Drawing::Size(431, 365);
			this->trainingimage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->trainingimage->TabIndex = 2;
			this->trainingimage->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->newform);
			this->panel1->Controls->Add(this->form3);
			this->panel1->Controls->Add(this->form2);
			this->panel1->Controls->Add(this->form1);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->formtitle);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(33, 142);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(158, 203);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TrainingMode::panel1_Paint);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(81, 157);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 17);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Add new";
			// 
			// newform
			// 
			this->newform->BackColor = System::Drawing::Color::Transparent;
			this->newform->Cursor = System::Windows::Forms::Cursors::Hand;
			this->newform->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"newform.Image")));
			this->newform->Location = System::Drawing::Point(94, 117);
			this->newform->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->newform->Name = L"newform";
			this->newform->Size = System::Drawing::Size(39, 37);
			this->newform->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->newform->TabIndex = 15;
			this->newform->TabStop = false;
			// 
			// form3
			// 
			this->form3->BackColor = System::Drawing::Color::Transparent;
			this->form3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->form3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"form3.Image")));
			this->form3->Location = System::Drawing::Point(17, 117);
			this->form3->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->form3->Name = L"form3";
			this->form3->Size = System::Drawing::Size(39, 37);
			this->form3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->form3->TabIndex = 13;
			this->form3->TabStop = false;
			this->form3->Click += gcnew System::EventHandler(this, &TrainingMode::form3_Click);
			// 
			// form2
			// 
			this->form2->BackColor = System::Drawing::Color::Transparent;
			this->form2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->form2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"form2.Image")));
			this->form2->Location = System::Drawing::Point(94, 52);
			this->form2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->form2->Name = L"form2";
			this->form2->Size = System::Drawing::Size(39, 37);
			this->form2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->form2->TabIndex = 12;
			this->form2->TabStop = false;
			this->form2->Click += gcnew System::EventHandler(this, &TrainingMode::form2_Click);
			// 
			// form1
			// 
			this->form1->BackColor = System::Drawing::Color::Transparent;
			this->form1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->form1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"form1.Image")));
			this->form1->Location = System::Drawing::Point(17, 52);
			this->form1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->form1->Name = L"form1";
			this->form1->Size = System::Drawing::Size(39, 37);
			this->form1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->form1->TabIndex = 5;
			this->form1->TabStop = false;
			this->form1->Click += gcnew System::EventHandler(this, &TrainingMode::form1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 157);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 17);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Form 3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(91, 92);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Form 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 92);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Form 1";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Transparent;
			this->panel3->Controls->Add(this->progressBar1);
			this->panel3->Controls->Add(this->home);
			this->panel3->Controls->Add(this->loading);
			this->panel3->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel3->Location = System::Drawing::Point(30, 159);
			this->panel3->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(140, 163);
			this->panel3->TabIndex = 15;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TrainingMode::panel3_Paint);
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::Color::Gold;
			this->progressBar1->Location = System::Drawing::Point(18, 53);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(100, 23);
			this->progressBar1->TabIndex = 9;
			this->progressBar1->Value = 20;
			// 
			// home
			// 
			this->home->Cursor = System::Windows::Forms::Cursors::Hand;
			this->home->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"home.Image")));
			this->home->Location = System::Drawing::Point(40, 105);
			this->home->Name = L"home";
			this->home->Size = System::Drawing::Size(53, 55);
			this->home->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->home->TabIndex = 7;
			this->home->TabStop = false;
			this->home->Click += gcnew System::EventHandler(this, &TrainingMode::home_Click);
			// 
			// loading
			// 
			this->loading->AutoSize = true;
			this->loading->Location = System::Drawing::Point(37, 20);
			this->loading->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->loading->Name = L"loading";
			this->loading->Size = System::Drawing::Size(66, 17);
			this->loading->TabIndex = 0;
			this->loading->Text = L"loading";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->back);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->finalpos);
			this->panel2->Controls->Add(this->centralpos);
			this->panel2->Controls->Add(this->initialpos);
			this->panel2->Controls->Add(this->postitle);
			this->panel2->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel2->Location = System::Drawing::Point(13, 168);
			this->panel2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(209, 154);
			this->panel2->TabIndex = 14;
			// 
			// back
			// 
			this->back->BackColor = System::Drawing::Color::Transparent;
			this->back->Cursor = System::Windows::Forms::Cursors::Hand;
			this->back->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back.Image")));
			this->back->Location = System::Drawing::Point(81, 114);
			this->back->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(39, 37);
			this->back->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->back->TabIndex = 20;
			this->back->TabStop = false;
			this->back->Click += gcnew System::EventHandler(this, &TrainingMode::back_Click_1);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(142, 82);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 17);
			this->label6->TabIndex = 19;
			this->label6->Text = L"final";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(69, 84);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 17);
			this->label2->TabIndex = 18;
			this->label2->Text = L"central";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 82);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 17);
			this->label1->TabIndex = 17;
			this->label1->Text = L"initial";
			// 
			// finalpos
			// 
			this->finalpos->BackColor = System::Drawing::Color::Transparent;
			this->finalpos->Cursor = System::Windows::Forms::Cursors::Hand;
			this->finalpos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"finalpos.Image")));
			this->finalpos->Location = System::Drawing::Point(141, 42);
			this->finalpos->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->finalpos->Name = L"finalpos";
			this->finalpos->Size = System::Drawing::Size(39, 37);
			this->finalpos->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->finalpos->TabIndex = 17;
			this->finalpos->TabStop = false;
			this->finalpos->Click += gcnew System::EventHandler(this, &TrainingMode::finalpos_Click);
			// 
			// centralpos
			// 
			this->centralpos->BackColor = System::Drawing::Color::Transparent;
			this->centralpos->Cursor = System::Windows::Forms::Cursors::Hand;
			this->centralpos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"centralpos.Image")));
			this->centralpos->Location = System::Drawing::Point(81, 42);
			this->centralpos->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->centralpos->Name = L"centralpos";
			this->centralpos->Size = System::Drawing::Size(39, 37);
			this->centralpos->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->centralpos->TabIndex = 17;
			this->centralpos->TabStop = false;
			this->centralpos->Click += gcnew System::EventHandler(this, &TrainingMode::centralpos_Click);
			// 
			// initialpos
			// 
			this->initialpos->BackColor = System::Drawing::Color::Transparent;
			this->initialpos->Cursor = System::Windows::Forms::Cursors::Hand;
			this->initialpos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"initialpos.Image")));
			this->initialpos->Location = System::Drawing::Point(20, 42);
			this->initialpos->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->initialpos->Name = L"initialpos";
			this->initialpos->Size = System::Drawing::Size(39, 37);
			this->initialpos->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->initialpos->TabIndex = 17;
			this->initialpos->TabStop = false;
			this->initialpos->Click += gcnew System::EventHandler(this, &TrainingMode::initialpos_Click);
			// 
			// postitle
			// 
			this->postitle->AutoSize = true;
			this->postitle->Location = System::Drawing::Point(26, 14);
			this->postitle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->postitle->Name = L"postitle";
			this->postitle->Size = System::Drawing::Size(141, 17);
			this->postitle->TabIndex = 0;
			this->postitle->Text = L"chosse a position!";
			// 
			// TrainingMode
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gold;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(807, 497);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->trainingimage);
			this->Controls->Add(this->title);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"TrainingMode";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TrainingMode";
			this->Load += gcnew System::EventHandler(this, &TrainingMode::TrainingMode_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trainingimage))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->newform))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->form3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->form2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->form1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->home))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->finalpos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->centralpos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->initialpos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TrainingMode_Load(System::Object^  sender, System::EventArgs^  e) {
		panel2->Visible = false;
		panel3->Visible = false;
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void form1_Click(System::Object^  sender, System::EventArgs^  e) {
	currentform = "form1";
	panel2->Visible = true;
	panel1->Visible = false;
	// form = "Strike the hearth with fist";
}
private: System::Void form2_Click(System::Object^  sender, System::EventArgs^  e) {
	currentform = "form2";
	panel2->Visible = true;
	panel1->Visible = false;
	// form = "Arhat holds sea";
}
private: System::Void form3_Click(System::Object^  sender, System::EventArgs^  e) {
	currentform = "form3";
	panel2->Visible = true;
	panel1->Visible = false;
	// form = "Brush hand and fist in bow stance";
}
private: System::Void home_Click(System::Object^  sender, System::EventArgs^  e) {
	panel1->Visible = true;
	panel3->Visible = false;
}
private: System::Void back_Click_1(System::Object^  sender, System::EventArgs^  e) {
	panel2->Visible = false;
	panel3->Visible = false;
	panel1->Visible = true;
}
private: System::Void initialpos_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentform == "form1") {
		currentpos = "Horse-with-separate-palms";
		
	}
	else if (currentform == "form2") {
		currentpos = "crouch-on-the-ground";
	}
	else if (currentform == "form3") {
		currentpos = "hit-with-elbows";
	}
	else {
		currentpos = "";
	}
	panel3->Visible = true;
	panel1->Visible = false;
	panel2->Visible = false;
}
private: System::Void centralpos_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentform == "form1") {
		currentpos = "Bow-with-grip";
	}
	else if (currentform == "form2") {
		currentpos = "Hands-illusion";
	}
	else if (currentform == "form3") {
		currentpos = "Rush-hand";
	}
	else {
		currentpos = "";
	}
	panel3->Visible = true;
	panel1->Visible = false;
	panel2->Visible = false;
}
private: System::Void finalpos_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentform == "form1") {
		currentpos = "Heart-strike";
	}
	else if (currentform == "form2") {
		currentpos = "hit-with-elbows";
	}
	else if (currentform == "form3") {
		currentpos = "thrust-fist";
	}
	else {
		currentpos = "";
	}
	panel3->Visible = true;
	panel1->Visible = false;
	panel2->Visible = false;
}
private: System::Void panel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
public: System::Void getImageFromKinect(void) {
	BYTE RGBADATA[640*480*4];
	const char * data;
	///data = Connect2Kinect::getPInstance().getData();
}
};
}
