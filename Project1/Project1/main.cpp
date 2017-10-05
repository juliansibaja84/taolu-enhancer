#include "MyForm.h"
#include "Connect2Kinect.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;

Connect2Kinect *Connect2Kinect::instance = 0;

/*
ref class Work
{
public:

	int * Data;
	void DoMoreWork()
	{
		while(1)
			(Data)();
	}

};
*/

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//Work^ w = gcnew Work;


	Project1::MyForm form;

	//w->Data = &form.manageVideo;
	//Thread^ piThread = gcnew Thread(gcnew ThreadStart(w, &Work::DoMoreWork));
	//(*piThread).Start();

	Application::Run(%(form));
}