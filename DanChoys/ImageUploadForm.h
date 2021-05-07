#pragma once

namespace Upload {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class ImageUploadForm : public System::Windows::Forms::Form {
	public:

		ImageUploadForm(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>

		~ImageUploadForm();

	private: System::Windows::Forms::Label^			 mainImagePathLabel;
	private: System::Windows::Forms::TextBox^		 mainImagePath;
	private: System::Windows::Forms::Button^		 searchMainImageButton;
	private: System::Windows::Forms::Label^			 mainPictureBoxLabel;
	private: System::Windows::Forms::PictureBox^	 mainPictureBox;
	
	private: System::Windows::Forms::Label^			  watermarkImagePathLabel;
	private: System::Windows::Forms::TextBox^		  watermarkImagePath;
	private: System::Windows::Forms::Button^		  searchWatermarkImageButton;
	private: System::Windows::Forms::Label^			  watermarkPictureBoxLabel;
	private: System::Windows::Forms::PictureBox^      watermarkPictureBox;

	
	private: System::Windows::Forms::Button^          nextButton;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;

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
	private:

		System::Void mainImagePath_TextChanged(System::Object^  sender, System::EventArgs^  e);

		System::Void searchMainImageButton_Click(System::Object^  sender, System::EventArgs^  e);

		System::Void watermarkImagePath_TextChanged(System::Object^  sender, System::EventArgs^  e);

		System::Void searchWatermarkImageButton_Click(System::Object^  sender, System::EventArgs^  e);

		System::Void nextButton_Click(System::Object^  sender, System::EventArgs^  e);

	};

}
