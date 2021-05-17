#include "ImageWorkForm.h"
#include "ImageSaveForm.h"
#include "EnlargedConvertedImage.h"

using namespace System::Drawing;

Work::ImageWorkForm::ImageWorkForm(Upload::ImageUploadForm^ imageUploadForm, ImageWork^ imageWork) :
	_imageUploadForm(imageUploadForm), _imageWork(imageWork) {

	InitializeComponent();

	const double imageRatio = imageWork->getWidthMainImage() / static_cast<double>(imageWork->getWidthWatermark());
	const int maxPercent = 100;

	if ((imageWork->getHeightWatermark() * imageRatio) < imageWork->getHeightMainImage()) {
																	
		sizeTrackBar->Value = (imageWork->getWidthWatermark() * maxPercent) / imageWork->getWidthMainImage();
		sizeNumericUpDown->Value = static_cast<Decimal>(sizeTrackBar->Value);

	} else {

		sizeTrackBar->Value = (imageWork->getHeightWatermark() * maxPercent) / imageWork->getHeightMainImage();
		sizeNumericUpDown->Value = static_cast<Decimal>(sizeTrackBar->Value);

	}

	xTrackBar->Maximum = _imageWork->getWidthMainImage() - _imageWork->getWidthWatermark();
	yTrackBar->Maximum = _imageWork->getHeightMainImage() - _imageWork->getHeightWatermark();

	pictureBox->Image = imageWork->getResultingImage();
}

Work::ImageWorkForm::~ImageWorkForm() {
	if (components) {
		delete components;
	}
}

void Work::ImageWorkForm::InitializeComponent(void) {
	this->transparencyPercentSignLabel = (gcnew System::Windows::Forms::Label());
	this->transparencyNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
	this->sizePercentSignLabel = (gcnew System::Windows::Forms::Label());
	this->sizeNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
	this->transparencyTrackBar = (gcnew System::Windows::Forms::TrackBar());
	this->sizeTrackBar = (gcnew System::Windows::Forms::TrackBar());
	this->backButton = (gcnew System::Windows::Forms::Button());
	this->nextButton = (gcnew System::Windows::Forms::Button());
	this->changeTransparencyHeading = (gcnew System::Windows::Forms::Label());
	this->positionGroupBox = (gcnew System::Windows::Forms::GroupBox());
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
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->transparencyNumericUpDown))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeNumericUpDown))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->transparencyTrackBar))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeTrackBar))->BeginInit();
	this->positionGroupBox->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yNumericUpDown))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yTrackBar))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xNumericUpDown))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xTrackBar))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
	this->SuspendLayout();
	// 
	// transparencyPercentSignLabel
	// 
	this->transparencyPercentSignLabel->AutoSize = true;
	this->transparencyPercentSignLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
	this->transparencyPercentSignLabel->Location = System::Drawing::Point(321, 96);
	this->transparencyPercentSignLabel->Name = L"transparencyPercentSignLabel";
	this->transparencyPercentSignLabel->Size = System::Drawing::Size(20, 16);
	this->transparencyPercentSignLabel->TabIndex = 27;
	this->transparencyPercentSignLabel->Text = L"%";
	// 
	// transparencyNumericUpDown
	// 
	this->transparencyNumericUpDown->DecimalPlaces = 1;
	this->transparencyNumericUpDown->Location = System::Drawing::Point(268, 92);
	this->transparencyNumericUpDown->Name = L"transparencyNumericUpDown";
	this->transparencyNumericUpDown->Size = System::Drawing::Size(50, 20);
	this->transparencyNumericUpDown->TabIndex = 26;
	this->transparencyNumericUpDown->ThousandsSeparator = true;
	this->transparencyNumericUpDown->ValueChanged += gcnew System::EventHandler(this, &ImageWorkForm::transparencyNumericUpDown_ValueChanged);
	// 
	// sizePercentSignLabel
	// 
	this->sizePercentSignLabel->AutoSize = true;
	this->sizePercentSignLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
	this->sizePercentSignLabel->Location = System::Drawing::Point(321, 32);
	this->sizePercentSignLabel->Name = L"sizePercentSignLabel";
	this->sizePercentSignLabel->Size = System::Drawing::Size(20, 16);
	this->sizePercentSignLabel->TabIndex = 25;
	this->sizePercentSignLabel->Text = L"%";
	// 
	// sizeNumericUpDown
	// 
	this->sizeNumericUpDown->Location = System::Drawing::Point(268, 28);
	this->sizeNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
	this->sizeNumericUpDown->Name = L"sizeNumericUpDown";
	this->sizeNumericUpDown->Size = System::Drawing::Size(50, 20);
	this->sizeNumericUpDown->TabIndex = 24;
	this->sizeNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
	this->sizeNumericUpDown->ValueChanged += gcnew System::EventHandler(this, &ImageWorkForm::sizeNumericUpDown_ValueChanged);
	// 
	// transparencyTrackBar
	// 
	this->transparencyTrackBar->Location = System::Drawing::Point(12, 92);
	this->transparencyTrackBar->Maximum = 0;
	this->transparencyTrackBar->Minimum = -255;
	this->transparencyTrackBar->Name = L"transparencyTrackBar";
	this->transparencyTrackBar->Size = System::Drawing::Size(254, 45);
	this->transparencyTrackBar->TabIndex = 23;
	this->transparencyTrackBar->Value = -255;
	this->transparencyTrackBar->Scroll += gcnew System::EventHandler(this, &ImageWorkForm::transparencyTrackBar_Scroll);
	// 
	// sizeTrackBar
	// 
	this->sizeTrackBar->Location = System::Drawing::Point(12, 28);
	this->sizeTrackBar->Maximum = 100;
	this->sizeTrackBar->Minimum = 1;
	this->sizeTrackBar->Name = L"sizeTrackBar";
	this->sizeTrackBar->Size = System::Drawing::Size(254, 45);
	this->sizeTrackBar->TabIndex = 22;
	this->sizeTrackBar->Value = 1;
	this->sizeTrackBar->Scroll += gcnew System::EventHandler(this, &ImageWorkForm::sizeTrackBar_Scroll);
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
	// positionGroupBox
	// 
	this->positionGroupBox->Controls->Add(this->yPercentSignLabel);
	this->positionGroupBox->Controls->Add(this->xPercentSignLabel);
	this->positionGroupBox->Controls->Add(this->yNumericUpDown);
	this->positionGroupBox->Controls->Add(this->yTrackBar);
	this->positionGroupBox->Controls->Add(this->xNumericUpDown);
	this->positionGroupBox->Controls->Add(this->xTrackBar);
	this->positionGroupBox->Controls->Add(this->yHeading);
	this->positionGroupBox->Controls->Add(this->xHeading);
	this->positionGroupBox->Location = System::Drawing::Point(12, 145);
	this->positionGroupBox->Name = L"positionGroupBox";
	this->positionGroupBox->Size = System::Drawing::Size(333, 148);
	this->positionGroupBox->TabIndex = 18;
	this->positionGroupBox->TabStop = false;
	this->positionGroupBox->Text = L"Положение водяного знака";
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
	this->Controls->Add(this->transparencyPercentSignLabel);
	this->Controls->Add(this->transparencyNumericUpDown);
	this->Controls->Add(this->sizePercentSignLabel);
	this->Controls->Add(this->sizeNumericUpDown);
	this->Controls->Add(this->transparencyTrackBar);
	this->Controls->Add(this->sizeTrackBar);
	this->Controls->Add(this->backButton);
	this->Controls->Add(this->nextButton);
	this->Controls->Add(this->changeTransparencyHeading);
	this->Controls->Add(this->positionGroupBox);
	this->Controls->Add(this->changeSizeHeading);
	this->Controls->Add(this->pictureBox);
	this->MaximizeBox = false;
	this->MaximumSize = System::Drawing::Size(700, 450);
	this->MinimizeBox = false;
	this->MinimumSize = System::Drawing::Size(700, 450);
	this->Name = L"ImageWorkForm";
	this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
	this->Text = L"DanChoys";
	this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ImageWorkForm::ImageWorkForm_FormClosed);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->transparencyNumericUpDown))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeNumericUpDown))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->transparencyTrackBar))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeTrackBar))->EndInit();
	this->positionGroupBox->ResumeLayout(false);
	this->positionGroupBox->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yNumericUpDown))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yTrackBar))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xNumericUpDown))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xTrackBar))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
	this->ResumeLayout(false);
	this->PerformLayout();

}

System::Void Work::ImageWorkForm::sizeTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	if (sizeTrackBar->Focused) {
		sizeNumericUpDown->Value = static_cast<Decimal>(sizeTrackBar->Value);
		_imageWork->changeSizeWatermark(sizeTrackBar->Value);

		changeMaxMinPositionValue();

		pictureBox->Image = _imageWork->getResultingImage();
	}
}

System::Void Work::ImageWorkForm::sizeNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	if (sizeNumericUpDown->Focused) {
		sizeTrackBar->Value = static_cast<int>(sizeNumericUpDown->Value);
		_imageWork->changeSizeWatermark(sizeTrackBar->Value);

		changeMaxMinPositionValue();

		pictureBox->Image = _imageWork->getResultingImage();
	}
}

System::Void Work::ImageWorkForm::changeMaxMinPositionValue(System::Void) {
	const int maxPercent = 100;
	const int minPercent = 0;

	xTrackBar->Maximum = _imageWork->getWidthMainImage() - _imageWork->getWidthWatermark();

	if (xTrackBar->Maximum != 0) {

		if (xNumericUpDown->Minimum == maxPercent) {
			xNumericUpDown->Minimum = minPercent;
		}

		xNumericUpDown->Value = static_cast<Decimal>((xTrackBar->Value / static_cast<double>(xTrackBar->Maximum)) * maxPercent);
	} else {
		xNumericUpDown->Minimum = maxPercent;
		xNumericUpDown->Value = maxPercent;
	}

	yTrackBar->Maximum = _imageWork->getHeightMainImage() - _imageWork->getHeightWatermark();

	if (yTrackBar->Maximum != 0){

		if (yNumericUpDown->Minimum == maxPercent) {
			yNumericUpDown->Minimum = minPercent;
		}

		yNumericUpDown->Value = static_cast<Decimal>((yTrackBar->Value / static_cast<double>(yTrackBar->Maximum)) * maxPercent);
	} else {
		yNumericUpDown->Minimum = maxPercent;
		yNumericUpDown->Value = maxPercent;
	}

	_imageWork->changePositionWatermark(xTrackBar->Value, yTrackBar->Value);
}

System::Void Work::ImageWorkForm::transparencyTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	if (transparencyTrackBar->Focused) {
		const double maxAlpha = 255.0;
		const int maxPercent = 100;
		const double percentageTransparency = maxPercent + (transparencyTrackBar->Value / maxAlpha) * maxPercent;

		transparencyNumericUpDown->Value = static_cast<Decimal>(percentageTransparency);

		_imageWork->changeTransparencyWatermark(transparencyTrackBar->Value);
		pictureBox->Image = _imageWork->getResultingImage();
	}
}

System::Void Work::ImageWorkForm::transparencyNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	if (transparencyNumericUpDown->Focused) {
		const int maxAlpha = 255;
		const int maxPercent = 100;
		const int transparencyValue = static_cast<int>(-maxAlpha + maxAlpha * static_cast<double>(transparencyNumericUpDown->Value) / maxPercent);
		
		transparencyTrackBar->Value = transparencyValue;

		_imageWork->changeTransparencyWatermark(transparencyTrackBar->Value);
		pictureBox->Image = _imageWork->getResultingImage();
	}
}

System::Void Work::ImageWorkForm::xTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	if (xTrackBar->Focused) {
		const int maxPercent = 100;

		xNumericUpDown->Value = static_cast<Decimal>((xTrackBar->Value / static_cast<double>(xTrackBar->Maximum)) * maxPercent);

		_imageWork->changePositionWatermark(xTrackBar->Value, yTrackBar->Value);
		pictureBox->Image = _imageWork->getResultingImage();
	}
}

System::Void Work::ImageWorkForm::xNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	if (xNumericUpDown->Focused) {
		const int maxPercent = 100;

		xTrackBar->Value = static_cast<int>(xTrackBar->Maximum * static_cast<double>(xNumericUpDown->Value) / maxPercent);

		_imageWork->changePositionWatermark(xTrackBar->Value, yTrackBar->Value);
		pictureBox->Image = _imageWork->getResultingImage();
	}
}

System::Void Work::ImageWorkForm::yTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	if (yTrackBar->Focused) {
		const double maxPercent = 100;

		yNumericUpDown->Value = static_cast<Decimal>((yTrackBar->Value / static_cast<double>(yTrackBar->Maximum)) * maxPercent);

		_imageWork->changePositionWatermark(xTrackBar->Value, yTrackBar->Value);
		pictureBox->Image = _imageWork->getResultingImage();
	}
}

System::Void Work::ImageWorkForm::yNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	if (yNumericUpDown->Focused) {
		const int maxPercent = 100;

		yTrackBar->Value = static_cast<int>(yTrackBar->Maximum * static_cast<double>(yNumericUpDown->Value) / maxPercent);

		_imageWork->changePositionWatermark(xTrackBar->Value, yTrackBar->Value);
		pictureBox->Image = _imageWork->getResultingImage();
	}
}

System::Void Work::ImageWorkForm::nextButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Save::ImageSaveForm^ imageSaveForm = gcnew Save::ImageSaveForm(this, _imageWork);

	imageSaveForm->Location = this->Location;
	imageSaveForm->Show();
	this->Hide();
}

System::Void Work::ImageWorkForm::backButton_Click(System::Object^  sender, System::EventArgs^  e) {
	_imageUploadForm->Location = this->Location;
	_imageUploadForm->Show();
	this->Hide();
}

System::Void Work::ImageWorkForm::pictureBox_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Enlarged::EnlargConvertedImage^ enlargConvertedImage = gcnew Enlarged::EnlargConvertedImage(pictureBox->Image);
	enlargConvertedImage->Show();
}

System::Void  Work::ImageWorkForm::ImageWorkForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	Application::Exit();
}