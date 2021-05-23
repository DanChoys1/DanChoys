#include "EnlargedConvertedImage.h"

using namespace System::Drawing;

Enlarged::EnlargConvertedImage::EnlargConvertedImage(Image^ image) {
	InitializeComponent();

	pictureBox->Width = SystemInformation::PrimaryMonitorSize.Width;
	pictureBox->Height = SystemInformation::PrimaryMonitorSize.Height;

	pictureBox->Image = image;
}

Enlarged::EnlargConvertedImage::~EnlargConvertedImage() {
	if (components) {
		delete components;
	} 
}

void Enlarged::EnlargConvertedImage::InitializeComponent(void) {
	this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
	this->SuspendLayout();
	// 
	// pictureBox
	// 
	this->pictureBox->Location = System::Drawing::Point(0, 0);
	this->pictureBox->Name = L"pictureBox";
	this->pictureBox->Size = System::Drawing::Size(100, 50);
	this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
	this->pictureBox->TabIndex = 0;
	this->pictureBox->TabStop = false;
	this->pictureBox->Click += gcnew System::EventHandler(this, &EnlargConvertedImage::pictureBox_Click);
	// 
	// EnlargConvertedImage
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(284, 261);
	this->Controls->Add(this->pictureBox);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	this->Name = L"EnlargConvertedImage";
	this->Text = L"EnlargedConvertedImage";
	this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
	this->ResumeLayout(false);

}

System::Void Enlarged::EnlargConvertedImage::pictureBox_Click(System::Object^ , System::EventArgs^ ) {
	this->Hide();
}