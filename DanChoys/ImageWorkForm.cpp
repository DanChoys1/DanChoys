#include <cmath>

#include "ImageWorkForm.h"
#include "ImageSaveForm.h"
#include "EnlargedConvertedImage.h"

using namespace System::Drawing;

Work::ImageWorkForm::ImageWorkForm(Upload::ImageUploadForm^ imageUploadForm, Bitmap^ mainImage, Bitmap^ watermarkImage) : _imageUploadForm(imageUploadForm) {
	
	InitializeComponent();

	_mainImage = gcnew Bitmap(mainImage);
	_watermarkImage = gcnew Bitmap(watermarkImage);
	_originalWatermark = gcnew Bitmap(watermarkImage);

	const double imageRatio = _mainImage->Width / static_cast<double>(_watermarkImage->Width);
	const int hundredPercent = 100;

	if ((_watermarkImage->Height * imageRatio) < _mainImage->Height) {

		changeSizeTrackBar->Value = (_watermarkImage->Width * hundredPercent) / _mainImage->Width;
		changeSizeNumericUpDown->Value = static_cast<Decimal>(changeSizeTrackBar->Value);

	} else {

		changeSizeTrackBar->Value = (_watermarkImage->Height * hundredPercent) / _mainImage->Height;
		changeSizeNumericUpDown->Value = static_cast<Decimal>(changeSizeTrackBar->Value);

	}

	xTrackBar->Maximum = _mainImage->Width - _watermarkImage->Width;

	if (yTrackBar->Maximum == 0) {
		xNumericUpDown->Value = hundredPercent;
	}

	yTrackBar->Maximum = _mainImage->Height - _watermarkImage->Height;

	if (yTrackBar->Maximum == 0) {
		yNumericUpDown->Value = hundredPercent;
	}

	Bitmap^ pictureBoxImage = gcnew Bitmap(_mainImage);
	Graphics^ imageGraphics = Graphics::FromImage(pictureBoxImage);

	imageGraphics->DrawImage(pictureBoxImage, 0, 0);
	imageGraphics->DrawImage(_watermarkImage, 0, 0);

	pictureBox->Image = pictureBoxImage;

}

Work::ImageWorkForm::~ImageWorkForm() {

	if (components) {

		delete components;

	}


}

void Work::ImageWorkForm::InitializeComponent(void) {
	this->changeTransparencyPercentSignLabel = (gcnew System::Windows::Forms::Label());
	this->changeTransparencyNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
	this->changeSizePercentSignLabel = (gcnew System::Windows::Forms::Label());
	this->changeSizeNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
	this->changeTransparencyTrackBar = (gcnew System::Windows::Forms::TrackBar());
	this->changeSizeTrackBar = (gcnew System::Windows::Forms::TrackBar());
	this->backButton = (gcnew System::Windows::Forms::Button());
	this->nextButton = (gcnew System::Windows::Forms::Button());
	this->changeTransparencyHeading = (gcnew System::Windows::Forms::Label());
	this->changePositionGroupBox = (gcnew System::Windows::Forms::GroupBox());
	this->yPercentSignLabel = (gcnew System::Windows::Forms::Label());
	this->xPercentSignLabel = (gcnew System::Windows::Forms::Label());
	this->yNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
	this->yTrackBar = (gcnew System::Windows::Forms::TrackBar());
	this->xNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
	this->xTrackBar = (gcnew System::Windows::Forms::TrackBar());
	this->yHeading = (gcnew System::Windows::Forms::Label());
	this->xHeading = (gcnew System::Windows::Forms::Label());
	this->changeSizeHeading = (gcnew System::Windows::Forms::Label());
	this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
	this->capabilitPictureBoxLabel = (gcnew System::Windows::Forms::Label());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeTransparencyNumericUpDown))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeSizeNumericUpDown))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeTransparencyTrackBar))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeSizeTrackBar))->BeginInit();
	this->changePositionGroupBox->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yNumericUpDown))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yTrackBar))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xNumericUpDown))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xTrackBar))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
	this->SuspendLayout();
	// 
	// changeTransparencyPercentSignLabel
	// 
	this->changeTransparencyPercentSignLabel->AutoSize = true;
	this->changeTransparencyPercentSignLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
	this->changeTransparencyPercentSignLabel->Location = System::Drawing::Point(321, 96);
	this->changeTransparencyPercentSignLabel->Name = L"changeTransparencyPercentSignLabel";
	this->changeTransparencyPercentSignLabel->Size = System::Drawing::Size(20, 16);
	this->changeTransparencyPercentSignLabel->TabIndex = 27;
	this->changeTransparencyPercentSignLabel->Text = L"%";
	// 
	// changeTransparencyNumericUpDown
	// 
	this->changeTransparencyNumericUpDown->DecimalPlaces = 1;
	this->changeTransparencyNumericUpDown->Location = System::Drawing::Point(268, 92);
	this->changeTransparencyNumericUpDown->Name = L"changeTransparencyNumericUpDown";
	this->changeTransparencyNumericUpDown->Size = System::Drawing::Size(50, 20);
	this->changeTransparencyNumericUpDown->TabIndex = 26;
	this->changeTransparencyNumericUpDown->ThousandsSeparator = true;
	this->changeTransparencyNumericUpDown->ValueChanged += gcnew System::EventHandler(this, &ImageWorkForm::changeTransparencyNumericUpDown_ValueChanged);
	// 
	// changeSizePercentSignLabel
	// 
	this->changeSizePercentSignLabel->AutoSize = true;
	this->changeSizePercentSignLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
	this->changeSizePercentSignLabel->Location = System::Drawing::Point(321, 32);
	this->changeSizePercentSignLabel->Name = L"changeSizePercentSignLabel";
	this->changeSizePercentSignLabel->Size = System::Drawing::Size(20, 16);
	this->changeSizePercentSignLabel->TabIndex = 25;
	this->changeSizePercentSignLabel->Text = L"%";
	// 
	// changeSizeNumericUpDown
	// 
	this->changeSizeNumericUpDown->Location = System::Drawing::Point(268, 28);
	this->changeSizeNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
	this->changeSizeNumericUpDown->Name = L"changeSizeNumericUpDown";
	this->changeSizeNumericUpDown->Size = System::Drawing::Size(50, 20);
	this->changeSizeNumericUpDown->TabIndex = 24;
	this->changeSizeNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
	this->changeSizeNumericUpDown->ValueChanged += gcnew System::EventHandler(this, &ImageWorkForm::changeSizeNumericUpDown_ValueChanged);
	// 
	// changeTransparencyTrackBar
	// 
	this->changeTransparencyTrackBar->Location = System::Drawing::Point(12, 92);
	this->changeTransparencyTrackBar->Maximum = 255;
	this->changeTransparencyTrackBar->Name = L"changeTransparencyTrackBar";
	this->changeTransparencyTrackBar->Size = System::Drawing::Size(254, 45);
	this->changeTransparencyTrackBar->TabIndex = 23;
	this->changeTransparencyTrackBar->Scroll += gcnew System::EventHandler(this, &ImageWorkForm::changeTransparencyTrackBar_Scroll);
	// 
	// changeSizeTrackBar
	// 
	this->changeSizeTrackBar->Location = System::Drawing::Point(12, 28);
	this->changeSizeTrackBar->Maximum = 100;
	this->changeSizeTrackBar->Minimum = 1;
	this->changeSizeTrackBar->Name = L"changeSizeTrackBar";
	this->changeSizeTrackBar->Size = System::Drawing::Size(254, 45);
	this->changeSizeTrackBar->TabIndex = 22;
	this->changeSizeTrackBar->Value = 1;
	this->changeSizeTrackBar->Scroll += gcnew System::EventHandler(this, &ImageWorkForm::changeSizeTrackBar_Scroll);
	// 
	// backButton
	// 
	this->backButton->Location = System::Drawing::Point(516, 376);
	this->backButton->Name = L"backButton";
	this->backButton->Size = System::Drawing::Size(75, 23);
	this->backButton->TabIndex = 21;
	this->backButton->Text = L"Назад";
	this->backButton->UseVisualStyleBackColor = true;
	this->backButton->Click += gcnew System::EventHandler(this, &ImageWorkForm::backButton_Click);
	// 
	// nextButton
	// 
	this->nextButton->Location = System::Drawing::Point(597, 376);
	this->nextButton->Name = L"nextButton";
	this->nextButton->Size = System::Drawing::Size(75, 23);
	this->nextButton->TabIndex = 20;
	this->nextButton->Text = L"Далее";
	this->nextButton->UseVisualStyleBackColor = true;
	this->nextButton->Click += gcnew System::EventHandler(this, &ImageWorkForm::nextButton_Click);
	// 
	// changeTransparencyHeading
	// 
	this->changeTransparencyHeading->AutoSize = true;
	this->changeTransparencyHeading->Location = System::Drawing::Point(12, 76);
	this->changeTransparencyHeading->Name = L"changeTransparencyHeading";
	this->changeTransparencyHeading->Size = System::Drawing::Size(200, 13);
	this->changeTransparencyHeading->TabIndex = 19;
	this->changeTransparencyHeading->Text = L"Прозрачность водяного изображения";
	// 
	// changePositionGroupBox
	// 
	this->changePositionGroupBox->Controls->Add(this->yPercentSignLabel);
	this->changePositionGroupBox->Controls->Add(this->xPercentSignLabel);
	this->changePositionGroupBox->Controls->Add(this->yNumericUpDown);
	this->changePositionGroupBox->Controls->Add(this->yTrackBar);
	this->changePositionGroupBox->Controls->Add(this->xNumericUpDown);
	this->changePositionGroupBox->Controls->Add(this->xTrackBar);
	this->changePositionGroupBox->Controls->Add(this->yHeading);
	this->changePositionGroupBox->Controls->Add(this->xHeading);
	this->changePositionGroupBox->Location = System::Drawing::Point(12, 145);
	this->changePositionGroupBox->Name = L"changePositionGroupBox";
	this->changePositionGroupBox->Size = System::Drawing::Size(333, 148);
	this->changePositionGroupBox->TabIndex = 18;
	this->changePositionGroupBox->TabStop = false;
	this->changePositionGroupBox->Text = L"Положение водяного знака";
	// 
	// yPercentSignLabel
	// 
	this->yPercentSignLabel->AutoSize = true;
	this->yPercentSignLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
	this->yPercentSignLabel->Location = System::Drawing::Point(309, 101);
	this->yPercentSignLabel->Name = L"yPercentSignLabel";
	this->yPercentSignLabel->Size = System::Drawing::Size(20, 16);
	this->yPercentSignLabel->TabIndex = 29;
	this->yPercentSignLabel->Text = L"%";
	// 
	// xPercentSignLabel
	// 
	this->xPercentSignLabel->AutoSize = true;
	this->xPercentSignLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
	this->xPercentSignLabel->Location = System::Drawing::Point(309, 36);
	this->xPercentSignLabel->Name = L"xPercentSignLabel";
	this->xPercentSignLabel->Size = System::Drawing::Size(20, 16);
	this->xPercentSignLabel->TabIndex = 28;
	this->xPercentSignLabel->Text = L"%";
	// 
	// yNumericUpDown
	// 
	this->yNumericUpDown->DecimalPlaces = 1;
	this->yNumericUpDown->Location = System::Drawing::Point(254, 97);
	this->yNumericUpDown->Name = L"yNumericUpDown";
	this->yNumericUpDown->Size = System::Drawing::Size(50, 20);
	this->yNumericUpDown->TabIndex = 18;
	this->yNumericUpDown->ValueChanged += gcnew System::EventHandler(this, &ImageWorkForm::yNumericUpDown_ValueChanged);
	// 
	// yTrackBar
	// 
	this->yTrackBar->Location = System::Drawing::Point(6, 97);
	this->yTrackBar->Name = L"yTrackBar";
	this->yTrackBar->Size = System::Drawing::Size(242, 45);
	this->yTrackBar->TabIndex = 13;
	this->yTrackBar->Scroll += gcnew System::EventHandler(this, &ImageWorkForm::yTrackBar_Scroll);
	// 
	// xNumericUpDown
	// 
	this->xNumericUpDown->DecimalPlaces = 1;
	this->xNumericUpDown->Location = System::Drawing::Point(254, 32);
	this->xNumericUpDown->Name = L"xNumericUpDown";
	this->xNumericUpDown->Size = System::Drawing::Size(50, 20);
	this->xNumericUpDown->TabIndex = 16;
	this->xNumericUpDown->ValueChanged += gcnew System::EventHandler(this, &ImageWorkForm::xNumericUpDown_ValueChanged);
	// 
	// xTrackBar
	// 
	this->xTrackBar->Location = System::Drawing::Point(6, 32);
	this->xTrackBar->Name = L"xTrackBar";
	this->xTrackBar->Size = System::Drawing::Size(242, 45);
	this->xTrackBar->TabIndex = 12;
	this->xTrackBar->Scroll += gcnew System::EventHandler(this, &ImageWorkForm::xTrackBar_Scroll);
	// 
	// yHeading
	// 
	this->yHeading->AutoSize = true;
	this->yHeading->Location = System::Drawing::Point(3, 81);
	this->yHeading->Name = L"yHeading";
	this->yHeading->Size = System::Drawing::Size(77, 13);
	this->yHeading->TabIndex = 1;
	this->yHeading->Text = L"По вертикали";
	// 
	// xHeading
	// 
	this->xHeading->AutoSize = true;
	this->xHeading->Location = System::Drawing::Point(3, 16);
	this->xHeading->Name = L"xHeading";
	this->xHeading->Size = System::Drawing::Size(88, 13);
	this->xHeading->TabIndex = 0;
	this->xHeading->Text = L"По горизонтали";
	// 
	// changeSizeHeading
	// 
	this->changeSizeHeading->AutoSize = true;
	this->changeSizeHeading->Location = System::Drawing::Point(12, 12);
	this->changeSizeHeading->Name = L"changeSizeHeading";
	this->changeSizeHeading->Size = System::Drawing::Size(167, 13);
	this->changeSizeHeading->TabIndex = 17;
	this->changeSizeHeading->Text = L"Размер водяного изображения";
	// 
	// pictureBox
	// 
	this->pictureBox->Location = System::Drawing::Point(348, 28);
	this->pictureBox->Name = L"pictureBox";
	this->pictureBox->Size = System::Drawing::Size(324, 342);
	this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
	this->pictureBox->TabIndex = 16;
	this->pictureBox->TabStop = false;
	this->pictureBox->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ImageWorkForm::pictureBox_MouseDoubleClick);
	// 
	// capabilitPictureBoxLabel
	// 
	this->capabilitPictureBoxLabel->AutoSize = true;
	this->capabilitPictureBoxLabel->Location = System::Drawing::Point(363, 12);
	this->capabilitPictureBoxLabel->Name = L"capabilitPictureBoxLabel";
	this->capabilitPictureBoxLabel->Size = System::Drawing::Size(293, 13);
	this->capabilitPictureBoxLabel->TabIndex = 28;
	this->capabilitPictureBoxLabel->Text = L"Нажмите на изображение дважды, чтобы увеличить его";
	// 
	// ImageWorkForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(684, 411);
	this->Controls->Add(this->capabilitPictureBoxLabel);
	this->Controls->Add(this->changeTransparencyPercentSignLabel);
	this->Controls->Add(this->changeTransparencyNumericUpDown);
	this->Controls->Add(this->changeSizePercentSignLabel);
	this->Controls->Add(this->changeSizeNumericUpDown);
	this->Controls->Add(this->changeTransparencyTrackBar);
	this->Controls->Add(this->changeSizeTrackBar);
	this->Controls->Add(this->backButton);
	this->Controls->Add(this->nextButton);
	this->Controls->Add(this->changeTransparencyHeading);
	this->Controls->Add(this->changePositionGroupBox);
	this->Controls->Add(this->changeSizeHeading);
	this->Controls->Add(this->pictureBox);
	this->MaximizeBox = false;
	this->MaximumSize = System::Drawing::Size(700, 450);
	this->MinimizeBox = false;
	this->MinimumSize = System::Drawing::Size(700, 450);
	this->Name = L"ImageWorkForm";
	this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
	this->Text = L"DanChoys";
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeTransparencyNumericUpDown))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeSizeNumericUpDown))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeTransparencyTrackBar))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeSizeTrackBar))->EndInit();
	this->changePositionGroupBox->ResumeLayout(false);
	this->changePositionGroupBox->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yNumericUpDown))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yTrackBar))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xNumericUpDown))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xTrackBar))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
	this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ImageWorkForm::ImageWorkForm_FormClosed);
	this->ResumeLayout(false);
	this->PerformLayout();

}

System::Void Work::ImageWorkForm::changeSizeTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {

	changeSizeNumericUpDown->Value = static_cast<Decimal>(changeSizeTrackBar->Value);
	changeSizeWatermark();

}

System::Void Work::ImageWorkForm::changeSizeNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

	changeSizeTrackBar->Value = static_cast<int>(changeSizeNumericUpDown->Value);
	changeSizeWatermark();

}

void Work::ImageWorkForm::changeSizeWatermark(void) {

	double imageRatio = _mainImage->Width / static_cast<double>(_originalWatermark->Width);

	if ((_originalWatermark->Height * imageRatio) < _mainImage->Height) {

		int width = static_cast<int>(_mainImage->Width * (changeSizeTrackBar->Value * 0.01));
		int height = static_cast<int>( (_originalWatermark->Height * imageRatio) * (changeSizeTrackBar->Value * 0.01) );
		_watermarkImage = gcnew Bitmap(_originalWatermark, width, height);

	} else {

		imageRatio = _mainImage->Height / static_cast<double>(_originalWatermark->Height);
		int height = static_cast<int>(_mainImage->Height * (changeSizeTrackBar->Value * 0.01));
		int width = static_cast<int>( (_originalWatermark->Width * imageRatio) * (changeSizeTrackBar->Value * 0.01) );
		_watermarkImage = gcnew Bitmap(_originalWatermark, width, height);

	}

	xTrackBar->Maximum = _mainImage->Width - _watermarkImage->Width;

	if (xTrackBar->Maximum != 0) {

		xNumericUpDown->Value = static_cast<Decimal>((xTrackBar->Value / static_cast<double>(xTrackBar->Maximum)) * 100);

	} else {

		xNumericUpDown->Value = 100;

	}

	yTrackBar->Maximum = _mainImage->Height - _watermarkImage->Height;

	if (yTrackBar->Maximum != 0) {

		yNumericUpDown->Value = static_cast<Decimal>((yTrackBar->Value / static_cast<double>(yTrackBar->Maximum)) * 100);

	} else {

		yNumericUpDown->Value = 100;

	}

	if (_alpha != 255) {

		changeTransparencyWatermark();

	} else {

		changePositionWatermark();

	}

}

System::Void Work::ImageWorkForm::changeTransparencyTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {

	const double maxAlpha = 255;
	const int hundredPercent = 100;

	changeTransparencyNumericUpDown->Value = static_cast<Decimal>((changeTransparencyTrackBar->Value / maxAlpha) * hundredPercent);

	changeTransparencyWatermark();

}

System::Void Work::ImageWorkForm::changeTransparencyNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

	const int maxAlpha = 255;
	const int hundredPercent = 100;

	changeTransparencyTrackBar->Value = static_cast<int>(maxAlpha * static_cast<double>(changeTransparencyNumericUpDown->Value) / hundredPercent);

	changeTransparencyWatermark();

}

void Work::ImageWorkForm::changeTransparencyWatermark(void) {
	const int maxAlpha = 255;
	_alpha = abs(changeTransparencyTrackBar->Value - maxAlpha);

	for (int x = 0; x < _watermarkImage->Width; x++) {

		for (int y = 0; y < _watermarkImage->Height; y++) {

			Color watermarkPixel = _watermarkImage->GetPixel(x, y);
			watermarkPixel = Color::FromArgb(_alpha, watermarkPixel);
			_watermarkImage->SetPixel(x, y, watermarkPixel);

		}

	}

	changePositionWatermark();
}

System::Void Work::ImageWorkForm::xTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	
	const int hundredPercent = 100;

	xNumericUpDown->Value = static_cast<Decimal>((xTrackBar->Value / static_cast<double>(xTrackBar->Maximum)) * hundredPercent);

	changePositionWatermark();
	
}

System::Void Work::ImageWorkForm::xNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

	const int hundredPercent = 100;

	xTrackBar->Value = static_cast<int>(xTrackBar->Maximum * static_cast<double>(xNumericUpDown->Value) / hundredPercent);

	changePositionWatermark();

}

System::Void Work::ImageWorkForm::yTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	
	const double hundredPercent = 100;

	yNumericUpDown->Value = static_cast<Decimal>((yTrackBar->Value / static_cast<double>(yTrackBar->Maximum)) * hundredPercent);

	changePositionWatermark();

}

System::Void Work::ImageWorkForm::yNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

	const int hundredPercent = 100;

	yTrackBar->Value = static_cast<int>(yTrackBar->Maximum * static_cast<double>(yNumericUpDown->Value) / hundredPercent);

	changePositionWatermark();

}

void Work::ImageWorkForm::changePositionWatermark(void) {
	Bitmap^ pictureBoxImage = gcnew Bitmap(_mainImage);
	Graphics^ imageGraphics = Graphics::FromImage(pictureBoxImage);

	imageGraphics->DrawImage(pictureBoxImage, 0, 0);
	imageGraphics->DrawImage(_watermarkImage, xTrackBar->Value, yTrackBar->Value);

	pictureBox->Image = pictureBoxImage;
}

System::Void Work::ImageWorkForm::nextButton_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ newImage = gcnew Bitmap(_mainImage);
	Graphics^ imageGraphics = Graphics::FromImage(newImage);

	imageGraphics->DrawImage(newImage, 0, 0);
	imageGraphics->DrawImage(_watermarkImage, xTrackBar->Value, yTrackBar->Value);

	Save::ImageSaveForm^ MF2 = gcnew Save::ImageSaveForm(this, newImage);

}

System::Void Work::ImageWorkForm::backButton_Click(System::Object^  sender, System::EventArgs^  e) {

	_imageUploadForm->Location = this->Location;
	_imageUploadForm->Show();
	this->Hide();

}

System::Void Work::ImageWorkForm::pictureBox_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	Enlarged::EnlargConvertedImage^ enlargConvertedImage = gcnew Enlarged::EnlargConvertedImage(pictureBox->Image);

}

System::Void  Work::ImageWorkForm::ImageWorkForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	
	Application::Exit();

}