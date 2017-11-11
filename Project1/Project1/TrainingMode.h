#pragma once
#include "DBhandle.h"
#include "Connect2Kinect.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include <math.h>

const INT32 streamsize = width*height*3;
namespace Project1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
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
			startThread();
		}
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
			if (this->trd->IsAlive) {
				trd->Abort();
			}
		}
	private: System::Windows::Forms::Label^  formtitle;
	protected:


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




	private: System::Windows::Forms::PictureBox^  newform;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  finalpos;
	private: System::Windows::Forms::PictureBox^  centralpos;
	private: System::Windows::Forms::PictureBox^  initialpos;
	private: System::Windows::Forms::PictureBox^  back;
	private: System::Windows::Forms::Button^  button1;


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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->back = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->finalpos = (gcnew System::Windows::Forms::PictureBox());
			this->centralpos = (gcnew System::Windows::Forms::PictureBox());
			this->initialpos = (gcnew System::Windows::Forms::PictureBox());
			this->postitle = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trainingimage))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->newform))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->form3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->form2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->form1))->BeginInit();
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
			// trainingimage
			// 
			this->trainingimage->BackColor = System::Drawing::Color::Transparent;
			this->trainingimage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"trainingimage.Image")));
			this->trainingimage->Location = System::Drawing::Point(251, 9);
			this->trainingimage->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->trainingimage->Name = L"trainingimage";
			this->trainingimage->Size = System::Drawing::Size(640, 480);
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(68, 433);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 31);
			this->button1->TabIndex = 15;
			this->button1->Text = L"C2A";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TrainingMode::button1_Click);
			// 
			// TrainingMode
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gray;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(904, 501);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->trainingimage);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->MaximizeBox = false;
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
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->finalpos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->centralpos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->initialpos))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TrainingMode_Load(System::Object^  sender, System::EventArgs^  e) {
		panel2->Visible = false;
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
	// form = "Brush hand and fist in bow stance";
}
private: System::Void form3_Click(System::Object^  sender, System::EventArgs^  e) {
	currentform = "form3";
	panel2->Visible = true;
	panel1->Visible = false;
	// form = "Twist body and thrust fist in rest stance";
}
private: System::Void home_Click(System::Object^  sender, System::EventArgs^  e) {
	panel1->Visible = true;
}
private: System::Void back_Click_1(System::Object^  sender, System::EventArgs^  e) {
	panel2->Visible = false;
	panel1->Visible = true;
}
private: System::Void initialpos_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentform == "form1") {
		currentpos = "horse-with-separate-palms";
		
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
	panel1->Visible = false;
	panel2->Visible = true;
	save_dbdata = TRUE;
}
private: System::Void centralpos_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentform == "form1") {
		currentpos = "bow-with-grip";
	}
	else if (currentform == "form2") {
		currentpos = "rush-hand";
	}
	else if (currentform == "form3") {
		currentpos = "circular-hammer-fist";
	}
	else {
		currentpos = "";
	}
	panel1->Visible = false;
	panel2->Visible = true;
	save_dbdata = TRUE;
}
private: System::Void finalpos_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentform == "form1") {
		currentpos = "heart-strike";
	}
	else if (currentform == "form2") {
		currentpos = "thrust-fist";
	}
	else if (currentform == "form3") {
		currentpos = "left-fist-rest-stance";
	}
	else {
		currentpos = "";
	}
	panel1->Visible = false;
	panel2->Visible = true;
	save_dbdata = TRUE;

}
private: System::Void panel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}

private: System::Void getImageFromKinect() {
	array<unsigned char>^ buffer = gcnew array<unsigned char>(streamsize);
	DBhandle dbh;
	std::string joints = "";
	std::string pos = "";
	String^ posS = "";
	//int y = 0;
	Bitmap^ bmp = gcnew Bitmap(width, height, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	System::Drawing::Rectangle^ rect = gcnew System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height);
	int lockimage = 0;
	while(1){
		joints = Connect2Kinect::getPInstance().getData();// esto debe estar aquí porque hay stackoverflow en el getdatargb
		lockimage = Connect2Kinect::getPInstance().getDataRGB(buffer,1);
		if (lockimage == 1) {
			if (joints != "") {
				addJointsToImageData(buffer, joints); }
			System::Drawing::Imaging::BitmapData^ bmp_data = bmp->LockBits(*rect, System::Drawing::Imaging::ImageLockMode::WriteOnly, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			System::Runtime::InteropServices::Marshal::Copy(buffer, 0, bmp_data->Scan0, streamsize);
			bmp->UnlockBits(bmp_data);
		}
		
		if (this->trainingimage->IsHandleCreated && lockimage == 1) 
		{
			trainingimage->Invoke(gcnew Action<Image ^>(trainingimage, &PictureBox::Image::set), bmp);
			trainingimage->Invoke(gcnew Action(trainingimage, &PictureBox::Update));
		}
		if (save_dbdata) {
			if (joints != "") {
				posS = currentpos;
				pos = msclr::interop::marshal_as<std::string>(posS);
				joints = "'" + pos + "'," + joints;
				dbh.saveJoints(joints);
				posS = gcnew String(("Saved position " + pos).c_str());
				MessageBox::Show(posS);
				save_dbdata = FALSE;
				joints = "";
			}
		}
		//MessageBox::Show(x);
		/*
		x = gcnew String(System::Convert::ToString(y));
		if (y == 10) {
			y = 0;
		}else{
			y += 1;
		}
		if (this->title->IsHandleCreated) {
			title->Invoke(gcnew Action<String ^>(title,&Label::Text::set),x);
			title->Invoke(gcnew Action(title, &Label::Update));
		}
		x = "";
		*/
		Thread::Sleep(10);
	}
}
private: Thread^ trd;
public: System::String^ currentform = "";
public: System::String^ currentpos = "";
public: BOOL save_dbdata = FALSE;
private:System::Void addJointsToImageData(array<unsigned char>^ data, std::string jointsstring) {
	double jointsArray[20][3],xt, yt, angx, angy, xr, yr, xpix, ypix;
	int i = 0;
	INT32 idx;
	std::string str = jointsstring;
	size_t pos = 0;
	size_t post = 0;
	std::string delimiter = "'";
	std::string token;
	str.pop_back();
	str.erase(0, 1);
	while ((pos = str.find(delimiter)) != std::string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + 3);
		for (int j = 0; j < 2; j++) {
			post = token.find(",");
			jointsArray[i][j] = strtod((token.substr(0, post)).c_str(), NULL);
			token.erase(0, post + 1);
		}
		jointsArray[i][2] = strtod(token.c_str(), NULL);
		
		i++;
	}
	
	for (int j = 0; j < 2; j++) {
		post = str.find(",");
		jointsArray[i][j] = strtod((str.substr(0, post)).c_str(), NULL);
		str.erase(0, post + 1);
	}
	jointsArray[i][2] = strtod(str.c_str(), NULL);
	
	std::ostringstream strs;


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 3; j++) {
			strs << jointsArray[i][j];
			strs << " || ";
		}
	}
	//MessageBox::Show(gcnew String(strs.str().c_str()));
	// --------------------put joints into image----------------------------------
	
	for (int i = 0; i < 20; i++) {
		xt = jointsArray[i][0] * 320 / 2.2;
		yt = jointsArray[i][1] * 240 / 1.6;
		
		angx = 57 * xt / 640;
		angy = 43 * yt / 480;
		
		xr = tan(angx*3.14159265359 / 180) * 640 * 4 / (jointsArray[i][2]);
		yr = tan(angy*3.14159265359 / 180) * 480 * 4.5 / (jointsArray[i][2]);

		xpix = 320 + xr;
		ypix = abs(yr - 240) + 15;

		if (abs(xpix) > 639) 
			xpix = 639;
		if (abs(ypix) > 479) 
			ypix = 479;

		// DRAW IMAGE
		if (xpix > 0 && xpix < 639) {
		
			if (ypix > 0 && ypix < 479) {
				// Inferior
				idx = (width * 3) * (int(ypix) - 1) + 3 * int(xpix);
				data[idx] = 0;
				data[idx + 1] = 255;
				data[idx + 2] = 0;
				// Superior
				idx = (width * 3) * (int(ypix) + 1) + 3 * int(xpix);
				data[idx] = 0;
				data[idx + 1] = 255;
				data[idx + 2] = 0;
			}

			//  Central
			idx = (width*3) * int(ypix) + 3 * int(xpix);
			data[idx-3] = 0;
			data[idx-2] = 255;
			data[idx-1] = 0;
			data[idx] = 0;
			data[idx + 1] = 255;
			data[idx + 2] = 0;
			data[idx+3] = 0;
			data[idx + 4] = 255;
			data[idx + 5] = 0;
		}
	}
	
	
	
	//idx = (width*3) * int(20) + 3 * int(20);
	//data[idx] = 255;
	//data[idx + 1] = 255;
	//data[idx + 2] = 255;
	//idx = (width*3) * int(400) + 3 * int(20);
	//data[idx] = 0;
	//data[idx + 1] = 0;
	//data[idx + 2] = 255;
	//idx = (width) * int(400) + 3 * int(20);
	//data[idx] = 0;
	//data[idx + 1] = 255;
	//data[idx + 2] = 0;
	
}
private: System::Void startThread() {
	
	ThreadStart^ delegate = gcnew ThreadStart(this, &TrainingMode::getImageFromKinect);
	trd = gcnew Thread(delegate);
	(*trd).IsBackground = true;
	(*trd).Start();

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	DBhandle dbh;
	dbh.convertJoints2Angles();
	System::String^ message;
	MessageBox::Show("Operation Completed!");
}
};
}

