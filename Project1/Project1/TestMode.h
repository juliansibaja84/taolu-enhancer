#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de TestMode
	/// </summary>
	public ref class TestMode : public System::Windows::Forms::Form
	{
	public:
		TestMode(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~TestMode()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  title;
	private: System::Windows::Forms::PictureBox^  testimage;
	protected:


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  stop;
	private: System::Windows::Forms::PictureBox^  start;


	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::Label^  startop;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  predictedform;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  predictedpos;


	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TestMode::typeid));
			this->title = (gcnew System::Windows::Forms::Label());
			this->testimage = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->startop = (gcnew System::Windows::Forms::Label());
			this->stop = (gcnew System::Windows::Forms::PictureBox());
			this->start = (gcnew System::Windows::Forms::PictureBox());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->predictedpos = (gcnew System::Windows::Forms::Label());
			this->predictedform = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testimage))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->start))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->BackColor = System::Drawing::Color::Transparent;
			this->title->Location = System::Drawing::Point(371, 23);
			this->title->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(98, 20);
			this->title->TabIndex = 0;
			this->title->Text = L"TEST MODE";
			// 
			// testimage
			// 
			this->testimage->BackColor = System::Drawing::Color::Transparent;
			this->testimage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"testimage.Image")));
			this->testimage->Location = System::Drawing::Point(331, 66);
			this->testimage->Name = L"testimage";
			this->testimage->Size = System::Drawing::Size(441, 363);
			this->testimage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->testimage->TabIndex = 1;
			this->testimage->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->startop);
			this->panel1->Controls->Add(this->stop);
			this->panel1->Controls->Add(this->start);
			this->panel1->Location = System::Drawing::Point(81, 242);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(73, 100);
			this->panel1->TabIndex = 2;
			// 
			// startop
			// 
			this->startop->AutoSize = true;
			this->startop->Location = System::Drawing::Point(8, 68);
			this->startop->Name = L"startop";
			this->startop->Size = System::Drawing::Size(59, 20);
			this->startop->TabIndex = 2;
			this->startop->Text = L"START";
			this->startop->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// stop
			// 
			this->stop->BackColor = System::Drawing::Color::Transparent;
			this->stop->Cursor = System::Windows::Forms::Cursors::Hand;
			this->stop->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"stop.Image")));
			this->stop->Location = System::Drawing::Point(10, 15);
			this->stop->Name = L"stop";
			this->stop->Size = System::Drawing::Size(52, 50);
			this->stop->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->stop->TabIndex = 1;
			this->stop->TabStop = false;
			this->stop->Click += gcnew System::EventHandler(this, &TestMode::stop_Click);
			// 
			// start
			// 
			this->start->BackColor = System::Drawing::Color::Transparent;
			this->start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->start->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"start.Image")));
			this->start->Location = System::Drawing::Point(10, 15);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(52, 50);
			this->start->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->start->TabIndex = 0;
			this->start->TabStop = false;
			this->start->Click += gcnew System::EventHandler(this, &TestMode::start_Click);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"estrella_0.jpeg");
			this->imageList1->Images->SetKeyName(1, L"estrella_1.jpeg");
			this->imageList1->Images->SetKeyName(2, L"estrella_2.jpeg");
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->predictedpos);
			this->panel2->Controls->Add(this->predictedform);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(12, 136);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(228, 100);
			this->panel2->TabIndex = 3;
			// 
			// predictedpos
			// 
			this->predictedpos->AutoSize = true;
			this->predictedpos->Location = System::Drawing::Point(96, 52);
			this->predictedpos->Name = L"predictedpos";
			this->predictedpos->Size = System::Drawing::Size(129, 20);
			this->predictedpos->TabIndex = 3;
			this->predictedpos->Text = L"_______________";
			// 
			// predictedform
			// 
			this->predictedform->AutoSize = true;
			this->predictedform->Location = System::Drawing::Point(75, 13);
			this->predictedform->Name = L"predictedform";
			this->predictedform->Size = System::Drawing::Size(129, 20);
			this->predictedform->TabIndex = 2;
			this->predictedform->Text = L"_______________";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"posición:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"forma:";
			// 
			// TestMode
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gold;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(784, 441);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->testimage);
			this->Controls->Add(this->title);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->Name = L"TestMode";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TestMode";
			this->Load += gcnew System::EventHandler(this, &TestMode::TestMode_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testimage))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->start))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void ChangeTextStop(){
		startop->Text = "Stop";
	}
	private: void ChangeTextStart() {
		 startop->Text = "Start";
	}
	private: System::Void TestMode_Load(System::Object^  sender, System::EventArgs^  e) {
		stop->Visible = false;
	}
	private: System::Void stop_Click(System::Object^  sender, System::EventArgs^  e) {
		start->Visible = true;
		stop->Visible = false;
		ChangeTextStart();

		// TERMINA GRABACIÓN DEL KINECT
	}
private: System::Void start_Click(System::Object^  sender, System::EventArgs^  e) {
	start->Visible = false;
	stop->Visible = true;
	ChangeTextStop();

	// COMIENZA GRABACIÓN DEL KINECT
}
};
}
