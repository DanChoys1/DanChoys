#include "ImageUploadForm.h"
#include "ImageWorkForm.h"
#include "ImageWorkClass.h"

using namespace System::Drawing;

Upload::ImageUploadForm::ImageUploadForm(void) {

	InitializeComponent();

}

Upload::ImageUploadForm::~ImageUploadForm() {

	if (components) {
		delete components;
	}

}

void Upload::ImageUploadForm::InitializeComponent(void) {
	this->watermarkImagePathLabel = (gcnew System::Windows::Forms::Label());
	this->mainImagePathLabel = (gcnew System::Windows::Forms::Label());
	this->watermarkPictureBoxLabel = (gcnew System::Windows::Forms::Label());
	this->mainPictureBoxLabel = (gcnew System::Windows::Forms::Label());
	this->watermarkPictureBox = (gcnew System::Windows::Forms::PictureBox());
	this->mainPictureBox = (gcnew System::Windows::Forms::PictureBox());
	this->searchWatermarkImageButton = (gcnew System::Windows::Forms::Button());
	this->watermarkImagePath = (gcnew System::Windows::Forms::TextBox());
	this->searchMainImageButton = (gcnew System::Windows::Forms::Button());
	this->nextButton = (gcnew System::Windows::Forms::Button());
	this->mainImagePath = (gcnew System::Windows::Forms::TextBox());
	this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->watermarkPictureBox))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainPictureBox))->BeginInit();
	this->SuspendLayout();
	// 
	// watermarkImagePathLabel
	// 
	this->watermarkImagePathLabel->AutoSize = true;
	this->watermarkImagePathLabel->Location = System::Drawing::Point(19, 58);
	this->watermarkImagePathLabel->Name = L"watermarkImagePathLabel";
	this->watermarkImagePathLabel->Size = System::Drawing::Size(129, 13);
	this->watermarkImagePathLabel->TabIndex = 21;
	this->watermarkImagePathLabel->Text = L"Выберите водяной знак";
	// 
	// mainImagePathLabel
	// 
	this->mainImagePathLabel->AutoSize = true;
	this->mainImagePathLabel->Location = System::Drawing::Point(19, 16);
	this->mainImagePathLabel->Name = L"mainImagePathLabel";
	this->mainImagePathLabel->Size = System::Drawing::Size(106, 13);
	this->mainImagePathLabel->TabIndex = 20;
	this->mainImagePathLabel->Text = L"Выберите картинку";
	// 
	// watermarkPictureBoxLabel
	// 
	this->watermarkPictureBoxLabel->AutoSize = true;
	this->watermarkPictureBoxLabel->Location = System::Drawing::Point(393, 381);
	this->watermarkPictureBoxLabel->Name = L"watermarkPictureBoxLabel";
	this->watermarkPictureBoxLabel->Size = System::Drawing::Size(77, 13);
	this->watermarkPictureBoxLabel->TabIndex = 19;
	this->watermarkPictureBoxLabel->Text = L"Водяной знак";
	// 
	// mainPictureBoxLabel
	// 
	this->mainPictureBoxLabel->AutoSize = true;
	this->mainPictureBoxLabel->Location = System::Drawing::Point(106, 381);
	this->mainPictureBoxLabel->Name = L"mainPictureBoxLabel";
	this->mainPictureBoxLabel->Size = System::Drawing::Size(77, 13);
	this->mainPictureBoxLabel->TabIndex = 18;
	this->mainPictureBoxLabel->Text = L"Изображение";
	// 
	// watermarkPictureBox
	// 
	this->watermarkPictureBox->Location = System::Drawing::Point(322, 112);
	this->watermarkPictureBox->Name = L"watermarkPictureBox";
	this->watermarkPictureBox->Size = System::Drawing::Size(227, 266);
	this->watermarkPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
	this->watermarkPictureBox->TabIndex = 17;
	this->watermarkPictureBox->TabStop = false;
	// 
	// mainPictureBox
	// 
	this->mainPictureBox->Location = System::Drawing::Point(40, 112);
	this->mainPictureBox->Name = L"mainPictureBox";
	this->mainPictureBox->Size = System::Drawing::Size(227, 266);
	this->mainPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
	this->mainPictureBox->TabIndex = 16;
	this->mainPictureBox->TabStop = false;
	// 
	// searchWatermarkImageButton
	// 
	this->searchWatermarkImageButton->Location = System::Drawing::Point(575, 73);
	this->searchWatermarkImageButton->Name = L"searchWatermarkImageButton";
	this->searchWatermarkImageButton->Size = System::Drawing::Size(75, 23);
	this->searchWatermarkImageButton->TabIndex = 15;
	this->searchWatermarkImageButton->Text = L"Обзор...";
	this->searchWatermarkImageButton->UseVisualStyleBackColor = true;
	this->searchWatermarkImageButton->Click += gcnew System::EventHandler(this, &ImageUploadForm::searchWatermarkImageButton_Click);
	// 
	// watermarkImagePath
	// 
	this->watermarkImagePath->Location = System::Drawing::Point(22, 74);
	this->watermarkImagePath->Name = L"watermarkImagePath";
	this->watermarkImagePath->Size = System::Drawing::Size(536, 20);
	this->watermarkImagePath->TabIndex = 14;
	this->watermarkImagePath->TextChanged += gcnew System::EventHandler(this, &ImageUploadForm::watermarkImagePath_TextChanged);
	// 
	// searchMainImageButton
	// 
	this->searchMainImageButton->Location = System::Drawing::Point(575, 31);
	this->searchMainImageButton->Name = L"searchMainImageButton";
	this->searchMainImageButton->Size = System::Drawing::Size(75, 23);
	this->searchMainImageButton->TabIndex = 13;
	this->searchMainImageButton->Text = L"Обзор...";
	this->searchMainImageButton->UseVisualStyleBackColor = true;
	this->searchMainImageButton->Click += gcnew System::EventHandler(this, &ImageUploadForm::searchMainImageButton_Click);
	// 
	// nextButton
	// 
	this->nextButton->Location = System::Drawing::Point(597, 376);
	this->nextButton->Name = L"nextButton";
	this->nextButton->Size = System::Drawing::Size(75, 23);
	this->nextButton->TabIndex = 12;
	this->nextButton->Text = L"Далее";
	this->nextButton->UseVisualStyleBackColor = true;
	this->nextButton->Click += gcnew System::EventHandler(this, &ImageUploadForm::nextButton_Click);
	// 
	// mainImagePath
	// 
	this->mainImagePath->Location = System::Drawing::Point(22, 32);
	this->mainImagePath->Name = L"mainImagePath";
	this->mainImagePath->Size = System::Drawing::Size(536, 20);
	this->mainImagePath->TabIndex = 11;
	this->mainImagePath->TextChanged += gcnew System::EventHandler(this, &ImageUploadForm::mainImagePath_TextChanged);
	// 
	// openFileDialog
	// 
	this->openFileDialog->FileName = L"openFileDialog";
	// 
	// ImageUpload
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(684, 411);
	this->Controls->Add(this->watermarkImagePathLabel);
	this->Controls->Add(this->mainImagePathLabel);
	this->Controls->Add(this->watermarkPictureBoxLabel);
	this->Controls->Add(this->mainPictureBoxLabel);
	this->Controls->Add(this->watermarkPictureBox);
	this->Controls->Add(this->mainPictureBox);
	this->Controls->Add(this->searchWatermarkImageButton);
	this->Controls->Add(this->watermarkImagePath);
	this->Controls->Add(this->searchMainImageButton);
	this->Controls->Add(this->nextButton);
	this->Controls->Add(this->mainImagePath);
	this->MaximizeBox = false;
	this->MaximumSize = System::Drawing::Size(700, 450);
	this->MinimizeBox = false;
	this->MinimumSize = System::Drawing::Size(700, 450);
	this->Name = L"ImageUpload";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Text = L"DanChoys";
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->watermarkPictureBox))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainPictureBox))->EndInit();
	this->ResumeLayout(false);
	this->PerformLayout();

}

System::Void Upload::ImageUploadForm::searchMainImageButton_Click(System::Object^  sender, System::EventArgs^  e) {

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

		mainImagePath->Text = openFileDialog->FileName;

	}

}

System::Void Upload::ImageUploadForm::mainImagePath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
	try {

		mainPictureBox->Image = Image::FromFile(mainImagePath->Text);

	} catch (OutOfMemoryException^ exception) {

		mainPictureBox->Image = nullptr;

	} catch (ArgumentException^ exception) {

		mainPictureBox->Image = nullptr;

	} catch (System::IO::FileNotFoundException^ exception) {

		mainPictureBox->Image = nullptr;

	}

}

System::Void Upload::ImageUploadForm::searchWatermarkImageButton_Click(System::Object^  sender, System::EventArgs^  e) {

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

		watermarkImagePath->Text = openFileDialog->FileName;

	}

}

System::Void Upload::ImageUploadForm::watermarkImagePath_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	try {

		watermarkPictureBox->Image = Image::FromFile(watermarkImagePath->Text);

	} catch (OutOfMemoryException^ exception) {

		watermarkPictureBox->Image = nullptr;

	} catch (ArgumentException^ exception) {

		watermarkPictureBox->Image = nullptr;

	} catch (System::IO::FileNotFoundException^ exception) {

		watermarkPictureBox->Image = nullptr;

	}

}

System::Void Upload::ImageUploadForm::nextButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
	bool isExistMainImage = mainPictureBox->Image != nullptr;
	bool isExistWatermark = watermarkPictureBox->Image != nullptr;

	if (!isExistMainImage) {
		MessageBox::Show("Основное изображение не существует или не может быть открыто.", "Ошибка!");
		return;
	}

	if (!isExistWatermark) {
		MessageBox::Show("Водяной знак не существует или не может быть открыто.", "Ошибка!");
		return;
	}

	ImageWork^ imageWork = gcnew ImageWork(mainPictureBox->Image, watermarkPictureBox->Image);

	if (imageWork->getWatermark() == nullptr) {
		MessageBox::Show("Основное изображение слишком мало.", "Ошибка!");
		return;
	}

	_pathUploadedImages = gcnew array<String^>(_numberUploadedImages);
	_pathUploadedImages[0] = mainImagePath->Text;
	_pathUploadedImages[1] = watermarkImagePath->Text;

	Work::ImageWorkForm^ imageWorkForm = gcnew Work::ImageWorkForm(this, imageWork);

	imageWorkForm->Location = this->Location;
	imageWorkForm->Show();
	this->Hide();
}

System::String^ Upload::ImageUploadForm::getPathUploadedImages(int pictureNumber) {
	return _pathUploadedImages[pictureNumber];
}

int Upload::ImageUploadForm::getNumberUploadedImages(void) {
	return _numberUploadedImages;
}