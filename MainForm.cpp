#include "MainForm.h"
#include "StudentForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);


    Assignment03::MainForm form;
    form.ShowDialog();
    
   
	
    return 0;
}