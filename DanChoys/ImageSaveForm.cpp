#include "ImageSaveForm.h"
#include <iostream>

using namespace System::Drawing;

Save::ImageSaveForm::ImageSaveForm(Work::ImageWorkForm^ imageWorkForm, Bitmap^ newImage) : 
										_imageWorkForm(imageWorkForm), _newImage(newImage) {

	InitializeComponent();

	pictureBox->Image = _newImage;
}

Save::ImageSaveForm::~ImageSaveForm() {

	if (components) {
		delete components;
	}
}

void Save::ImageSaveForm::InitializeComponent(void) {
	this->pictureBoxLabel = (gcnew System::Windows::Forms::Label());
	this->newImageSavePathLabel = (gcnew System::Windows::Forms::Label());
	this->backButton = (gcnew System::Windows::Forms::Button());
	this->saveButton = (gcnew System::Windows::Forms::Button());
	this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
	this->searchPathSaveImageButton = (gcnew System::Windows::Forms::Button());
	this->saveImagePathTextBox = (gcnew System::Windows::Forms::TextBox());
	this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
	this->SuspendLayout();
	// 
	// pictureBoxLabel
	// 
	this->pictureBoxLabel->AutoSize = true;
	this->pictureBoxLabel->Location = System::Drawing::Point(144, 378);
	this->pictureBoxLabel->Name = L"pictureBoxLabel";
	this->pictureBoxLabel->Size = System::Drawing::Size(77, 13);
	this->pictureBoxLabel->TabIndex = 22;
	this->pictureBoxLabel->Text = L"Изображение";
	// 
	// newImageSavePathLabel
	// 
	this->newImageSavePathLabel->AutoSize = true;
	this->newImageSavePathLabel->Location = System::Drawing::Point(19, 16);
	this->newImageSavePathLabel->Name = L"newImageSavePathLabel";
	this->newImageSavePathLabel->Size = System::Drawing::Size(216, 13);
	this->newImageSavePathLabel->TabIndex = 21;
	this->newImageSavePathLabel->Text = L"Куда вы хотите сохарнить изображение\?";
	// 
	// backButton
	// 
	this->backButton->Location = System::Drawing::Point(516, 376);
	this->backButton->Name = L"backButton";
	this->backButton->Size = System::Drawing::Size(75, 23);
	this->backButton->TabIndex = 20;
	this->backButton->Text = L"Назад";
	this->backButton->UseVisualStyleBackColor = true;
	this->backButton->Click += gcnew System::EventHandler(this, &ImageSaveForm::backButton_Click);
	// 
	// saveButton
	// 
	this->saveButton->Location = System::Drawing::Point(597, 376);
	this->saveButton->Name = L"saveButton";
	this->saveButton->Size = System::Drawing::Size(75, 23);
	this->saveButton->TabIndex = 19;
	this->saveButton->Text = L"Сохранить";
	this->saveButton->UseVisualStyleBackColor = true;
	this->saveButton->Click += gcnew System::EventHandler(this, &ImageSaveForm::saveButton_Click);
	// 
	// pictureBox
	// 
	this->pictureBox->Location = System::Drawing::Point(22, 62);
	this->pictureBox->Name = L"pictureBox";
	this->pictureBox->Size = System::Drawing::Size(321, 313);
	this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
	this->pictureBox->TabIndex = 18;
	this->pictureBox->TabStop = false;
	// 
	// searchPathSaveImageButton
	// 
	this->searchPathSaveImageButton->Location = System::Drawing::Point(575, 31);
	this->searchPathSaveImageButton->Name = L"searchPathSaveImageButton";
	this->searchPathSaveImageButton->Size = System::Drawing::Size(75, 23);
	this->searchPathSaveImageButton->TabIndex = 17;
	this->searchPathSaveImageButton->Text = L"Обзор...";
	this->searchPathSaveImageButton->UseVisualStyleBackColor = true;
	this->searchPathSaveImageButton->Click += gcnew System::EventHandler(this, &ImageSaveForm::searchPathSaveImageButton_Click);
	// 
	// saveImagePathTextBox
	// 
	this->saveImagePathTextBox->Location = System::Drawing::Point(22, 32);
	this->saveImagePathTextBox->Name = L"saveImagePathTextBox";
	this->saveImagePathTextBox->Size = System::Drawing::Size(536, 20);
	this->saveImagePathTextBox->TabIndex = 16;
	// 
	// saveFileDialog
	// 
	this->saveFileDialog->CheckPathExists = false;
	this->saveFileDialog->OverwritePrompt = false;
	// 
	// ImageSaveForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(684, 411);
	this->Controls->Add(this->pictureBoxLabel);
	this->Controls->Add(this->newImageSavePathLabel);
	this->Controls->Add(this->backButton);
	this->Controls->Add(this->saveButton);
	this->Controls->Add(this->pictureBox);
	this->Controls->Add(this->searchPathSaveImageButton);
	this->Controls->Add(this->saveImagePathTextBox);
	this->MaximizeBox = false;
	this->MaximumSize = System::Drawing::Size(700, 450);
	this->MinimizeBox = false;
	this->MinimumSize = System::Drawing::Size(700, 450);
	this->Name = L"ImageSaveForm";
	this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
	this->Text = L"DanChoys";
	this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ImageSaveForm::ImageSaveForm_FormClosed);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
	this->ResumeLayout(false);
	this->PerformLayout();

}

System::Void Save::ImageSaveForm::searchPathSaveImageButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
	saveFileDialog->Filter = "PNG (.png)|*.png|BMP (.bmp)|*.bmp|Jpg (.jpg)|*.jpg|Jpeg (.jpeg)|*.jpeg";
	saveFileDialog->ShowDialog();
	saveImagePathTextBox->Text = saveFileDialog->FileName;
}

System::Void Save::ImageSaveForm::saveButton_Click(System::Object^  sender, System::EventArgs^  e) {

	int numberUploadedImages = _imageWorkForm->getImageUploadForm()->getNumberUploadedImages();

	for (int i = 0; i < numberUploadedImages; i++) {
		String ^_pathUploadedImages = _imageWorkForm->getImageUploadForm()->getPathUploadedImages(i);

		if (_pathUploadedImages == saveImagePathTextBox->Text) {
			MessageBox::Show("Изображение с таким именем уже используется в программе.\n"
				             "Пожалуйста, укажите другое имя.", "Ошибка!");
			return;
		}
	}

	bool isFileExists = System::IO::File::Exists(saveImagePathTextBox->Text);

	if (isFileExists) {
		Windows::Forms::DialogResult result = MessageBox::Show("Изображение с таким именем уже существует.\n"
				                                               "Хотите заменить изображение?", "Сообщение", MessageBoxButtons::YesNo);

		if (result == Windows::Forms::DialogResult::No) {
			return;
		}

	}

	try {
		_newImage->Save(saveImagePathTextBox->Text);

		Windows::Forms::DialogResult result = MessageBox::Show("Изображение успешно сохранено.\n"
                                                               "Хотите закрыть приложение?", "Сообщение", MessageBoxButtons::YesNo);
		
		if (result == Windows::Forms::DialogResult::Yes) {
			Application::Exit();
		}

	} catch (Runtime::InteropServices::ExternalException^ exception) {

		MessageBox::Show("Не удалось сохранить файл по указанному пути.", "Ошибка!");

	} catch (ArgumentException^ exception) {

		MessageBox::Show("Вы не указали путь к файлу.", "Ошибка!");

	}

}

System::Void Save::ImageSaveForm::backButton_Click(System::Object^  sender, System::EventArgs^  e) {

	_imageWorkForm->Location = this->Location;
	_imageWorkForm->Show();
	this->Hide();

}

System::Void Save::ImageSaveForm::ImageSaveForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

	Application::Exit();

}