#pragma once
#include "DBhandle.h"
#include "Connect2Kinect.h"
#include "Classifier.h"
#include <msclr\marshal_cppstd.h>
#include <math.h>
#include <queue>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
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
			startThread();
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
			if (this->trd->IsAlive) {
				trd->Abort();
			}
		}

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
	private: System::Windows::Forms::Button^  button1;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testimage))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->start))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// testimage
			// 
			this->testimage->BackColor = System::Drawing::Color::Transparent;
			this->testimage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"testimage.Image")));
			this->testimage->Location = System::Drawing::Point(79, 12);
			this->testimage->Name = L"testimage";
			this->testimage->Size = System::Drawing::Size(640, 480);
			this->testimage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->testimage->TabIndex = 1;
			this->testimage->TabStop = false;
			this->testimage->Click += gcnew System::EventHandler(this, &TestMode::testimage_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->startop);
			this->panel1->Controls->Add(this->stop);
			this->panel1->Controls->Add(this->start);
			this->panel1->Location = System::Drawing::Point(658, 498);
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
			this->panel2->Location = System::Drawing::Point(67, 498);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(427, 100);
			this->panel2->TabIndex = 3;
			// 
			// predictedpos
			// 
			this->predictedpos->AutoSize = true;
			this->predictedpos->Location = System::Drawing::Point(96, 52);
			this->predictedpos->Name = L"predictedpos";
			this->predictedpos->Size = System::Drawing::Size(0, 20);
			this->predictedpos->TabIndex = 3;
			// 
			// predictedform
			// 
			this->predictedform->AutoSize = true;
			this->predictedform->Location = System::Drawing::Point(96, 12);
			this->predictedform->Name = L"predictedform";
			this->predictedform->Size = System::Drawing::Size(0, 20);
			this->predictedform->TabIndex = 2;
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(516, 531);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 32);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Predict";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TestMode::button1_Click);
			// 
			// TestMode
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gold;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(810, 621);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->testimage);
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
private: System::Void generateModel(DBhandle dbh, Classifier cls) {
	//System::String^ key;
	//double anglessample[] = { 3.05458 , 2.8185 , 2.791 , 2.80899 , 2.76042 , 2.47989 , 2.50082 , 2.03454 , 1.9806 , 1.70052 , 1.60372 , 2.55284 , 2.33598 }; // |
	//double anglessample[] = { 2.80381, 2.45424, 2.61379, 1.31193, 2.93246, 2.91801, 2.68098, 2.47769, 2.77961, 0.940495, 1.85448, 2.44962, 2.29614 };   // 5
	//double anglessample[] = { 2.83516, 2.93061, 1.50215, 2.33439, 2.27075, 2.20532, 2.35499, 2.82366, 2.70627, 0.670907, 0.932144, 1.42013, 1.58839 }; // 7
	//std::string str = "'9,3,6','3,4,3','3,14,5','11,4,3','9,3,6','3,4,3','3,14,5','11,4,3','9,3,6','3,4,3','3,14,5','11,4,3','9,3,6','3,4,3','3,14,5','11,4,3','9,3,6','3,4,3','3,14,5','11,4,3'";
	dbh.convertJoints2Angles();
	dbh.saveDataForTraining();
	cls.doTraining();
	/*
	std::ostringstream strs;
	strs << cls.doPrediction(dbh.U.jointsToAnglesarray(str));
	std::string predicted_label = strs.str();
	
	for (auto &i : dbh.U.classtointeger) {
		if (i.second == predicted_label) {
			key = gcnew String(i.first.c_str());
			break; // to stop searching
		}
	}
	MessageBox::Show(key);*/
}


private: Thread^ trd;
public: BOOL predict = FALSE;
public: 

	private: System::Void getImageFromKinect() {
		Classifier cls;
		DBhandle dbh;
		//dbh.convertJoints2Angles();
		dbh.saveDataForTraining();
		cls.doTraining();
		double anglessample[] = { 3.05458 , 2.8185 , 2.791 , 2.80899 , 2.76042 , 2.47989 , 2.50082 , 2.03454 , 1.9806 , 1.70052 , 1.60372 , 2.55284 , 2.33598 };
		array<unsigned char>^ buffer = gcnew array<unsigned char>(width*height * 3);
		std::string joints = "";
		std::string pos = "";
		String^ posS = "";
		std::string position;
		std::string form;
		std::string listofpositions;
		std::string posstack[3] = { "","","" };
		float angles[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	//int y = 0;
	Bitmap^ bmp = gcnew Bitmap(width, height, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	System::Drawing::Rectangle^ rect = gcnew System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height);
	int lockimage = 0;
	while (1) {
		joints = Connect2Kinect::getPInstance().getData();// esto debe estar aquí porque hay stackoverflow en el getdatargb
		lockimage = Connect2Kinect::getPInstance().getDataRGB(buffer, 1);
		if (lockimage == 1) {
			if (joints != "") { addJointsToImageData(buffer, joints); }
			System::Drawing::Imaging::BitmapData^ bmp_data = bmp->LockBits(*rect, System::Drawing::Imaging::ImageLockMode::WriteOnly, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			System::Runtime::InteropServices::Marshal::Copy(buffer, 0, bmp_data->Scan0, width*height * 3);
			bmp->UnlockBits(bmp_data);
		}

		if (this->testimage->IsHandleCreated && lockimage == 1)
		{
			testimage->Invoke(gcnew Action<Image ^>(testimage, &PictureBox::Image::set), bmp);
			testimage->Invoke(gcnew Action(testimage, &PictureBox::Update));
		}
		if (this->predict) {
			if (joints != "") {
				std::ostringstream strs;
				dbh.U.jointsToAnglesarray(joints, angles);
				for (int i = 0; i < 13; i++) {
					strs << angles[i];
					strs << " ";
				}
				
				//strs << cls.doPrediction(angles);
				MessageBox::Show(gcnew String(strs.str().c_str()));
				//MessageBox::Show(gcnew String(strs.str().c_str()));
				std::string predicted_label = strs.str();
				for (auto &i : dbh.U.classtointeger) {
					if (i.second == predicted_label) {
						position = i.first;
						break; // to stop searching
					}

				}
				MessageBox::Show(gcnew String(predicted_label.c_str()));
				posstack[0] = posstack[1];
				posstack[1] = posstack[2];
				posstack[2] = position;
				listofpositions = posstack[0]+","+posstack[1] + ","+ posstack[2];
				for (auto &i : dbh.U.formmap) {
					if (i.second == listofpositions) {
						form = i.first;
						break; // to stop searching
					}
					else {
						form = "Unknown";
					}
				}

				if (this->predictedpos->IsHandleCreated) {
					predictedpos->Invoke(gcnew Action<String ^>(predictedpos, &Label::Text::set), gcnew String(position.c_str()));
					predictedpos->Invoke(gcnew Action(predictedpos, &Label::Update));
				}

				if (this->predictedform->IsHandleCreated) {
					predictedform->Invoke(gcnew Action<String ^>(predictedform, &Label::Text::set), gcnew String(form.c_str()));
					predictedform->Invoke(gcnew Action(predictedform, &Label::Update));
				}
				this->predict = FALSE;
				joints = "";
			}
		}
		Thread::Sleep(10);
	}
}

private:System::Void addJointsToImageData(array<unsigned char>^ data, std::string jointsstring) {
	double jointsArray[20][3], xt, yt, angx, angy, xr, yr, xpix, ypix;
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
	//MessageBox::Show("string to array done!");
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
			idx = (width * 3) * int(ypix) + 3 * int(xpix);
			data[idx - 3] = 0;
			data[idx - 2] = 255;
			data[idx - 1] = 0;
			data[idx] = 0;
			data[idx + 1] = 255;
			data[idx + 2] = 0;
			data[idx + 3] = 0;
			data[idx + 4] = 255;
			data[idx + 5] = 0;
		}
	}


}

private: System::Void startThread() {

	ThreadStart^ delegate = gcnew ThreadStart(this, &TestMode::getImageFromKinect);
	trd = gcnew Thread(delegate);
	(*trd).IsBackground = true;
	(*trd).Start();

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->predict = TRUE;
}
private: System::Void testimage_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
