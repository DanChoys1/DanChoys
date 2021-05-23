#include "ImageUploadForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(void) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew Upload::ImageUploadForm());

	return 0;
}