#pragma once

#include "ImageWorkForm.h"
#include "ImageWorkClass.h"

namespace Save {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ImageSaveForm
	/// </summary>
	public ref class ImageSaveForm : public System::Windows::Forms::Form {
	public:

		ImageSaveForm(Work::ImageWorkForm^ imageWorkForm, ImageWork^ _imageWork);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ImageSaveForm();

	private:
		Work::ImageWorkForm^ _imageWorkForm = nullptr;
		ImageWork^ _imageWork = nullptr;
	
	private: System::Windows::Forms::Label^           newImageSavePathLabel;
	private: System::Windows::Forms::TextBox^         saveImagePathTextBox;
	private: System::Windows::Forms::Button^          searchPathSaveImageButton;
			   
	private: System::Windows::Forms::Label^           pictureBoxLabel;
	private: System::Windows::Forms::PictureBox^      pictureBox;

	private: System::Windows::Forms::Button^          backButton;
	private: System::Windows::Forms::Button^          saveButton;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>

		void InitializeComponent(void);

#pragma endregion
		
	private: System::Void searchPathSaveImageButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void ImageSaveForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
	};

}
