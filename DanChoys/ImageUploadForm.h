#pragma once

namespace Upload {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	
	public ref class ImageUploadForm : public System::Windows::Forms::Form {

	public: ImageUploadForm(void);

	protected: ~ImageUploadForm();

	private: System::Windows::Forms::Label^			  mainImagePathLabel;
	private: System::Windows::Forms::TextBox^		  mainImagePath;
	private: System::Windows::Forms::Button^		  searchMainImageButton;
	private: System::Windows::Forms::Label^			  mainPictureBoxLabel;
	private: System::Windows::Forms::PictureBox^	  mainPictureBox;
	
	private: System::Windows::Forms::Label^			  watermarkImagePathLabel;
	private: System::Windows::Forms::TextBox^		  watermarkImagePath;
	private: System::Windows::Forms::Button^		  searchWatermarkImageButton;
	private: System::Windows::Forms::Label^			  watermarkPictureBoxLabel;
	private: System::Windows::Forms::PictureBox^      watermarkPictureBox;

	private: System::Windows::Forms::Button^          nextButton;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;

	private: System::ComponentModel::Container^		  components;

#pragma region Windows Form Designer generated code

	private: void InitializeComponent(void);

#pragma endregion
	private: System::Void searchMainImageButton_Click(System::Object^ , System::EventArgs^ );
	private: System::Void searchWatermarkImageButton_Click(System::Object^ , System::EventArgs^ );

	private: System::Void mainImagePath_TextChanged(System::Object^ , System::EventArgs^ );
	private: System::Void watermarkImagePath_TextChanged(System::Object^ , System::EventArgs^ );

	private: System::Void nextButton_Click(System::Object^ , System::EventArgs^ );
	};

}
