#pragma once
#include "ImageUploadForm.h"
#include "ImageWorkClass.h"

namespace Work {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class ImageWorkForm : public System::Windows::Forms::Form {
	
	public: ImageWorkForm(Upload::ImageUploadForm^ imageUploadForm, ImageWork^ imageWork);

	protected: ~ImageWorkForm();

	private:
		Upload::ImageUploadForm^ _imageUploadForm = nullptr;
		ImageWork^ _imageWork = nullptr;

	private: System::Windows::Forms::Label^          changeSizeHeading;
	private: System::Windows::Forms::TrackBar^		 sizeTrackBar;
	private: System::Windows::Forms::NumericUpDown^  sizeNumericUpDown;
	private: System::Windows::Forms::Label^			 sizePercentSignLabel;

	private: System::Windows::Forms::Label^          changeTransparencyHeading;
	private: System::Windows::Forms::TrackBar^		 transparencyTrackBar;
	private: System::Windows::Forms::NumericUpDown^  transparencyNumericUpDown;
	private: System::Windows::Forms::Label^			 transparencyPercentSignLabel;
	private: System::Windows::Forms::GroupBox^		 positionGroupBox;

	private: System::Windows::Forms::Label^          xHeading;
	private: System::Windows::Forms::TrackBar^       xTrackBar;
	private: System::Windows::Forms::NumericUpDown^  xNumericUpDown;
	private: System::Windows::Forms::Label^          xPercentSignLabel;

	private: System::Windows::Forms::Label^          yHeading;
	private: System::Windows::Forms::TrackBar^       yTrackBar;
	private: System::Windows::Forms::NumericUpDown^  yNumericUpDown;
	private: System::Windows::Forms::Label^          yPercentSignLabel;
	
	private: System::Windows::Forms::Button^         backButton;
	private: System::Windows::Forms::Button^         nextButton;
	
	private: System::Windows::Forms::Label^			 capabilitPictureBoxLabel;
	private: System::Windows::Forms::PictureBox^     pictureBox;
	
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

	private: void InitializeComponent(void);

#pragma endregion
	private: System::Void sizeTrackBar_Scroll(System::Object^ , System::EventArgs^ );
	private: System::Void sizeNumericUpDown_ValueChanged(System::Object^ , System::EventArgs^ );
	private: System::Void changeMaxMinPositionValue(System::Void);

	private: System::Void transparencyTrackBar_Scroll(System::Object^ , System::EventArgs^ );
	private: System::Void transparencyNumericUpDown_ValueChanged(System::Object^ , System::EventArgs^ );

	private: System::Void xTrackBar_Scroll(System::Object^ , System::EventArgs^ );
	private: System::Void xNumericUpDown_ValueChanged(System::Object^ , System::EventArgs^ );

	private: System::Void yTrackBar_Scroll(System::Object^ , System::EventArgs^ );
	private: System::Void yNumericUpDown_ValueChanged(System::Object^ , System::EventArgs^ );

	private: System::Void nextButton_Click(System::Object^ , System::EventArgs^ );
	private: System::Void backButton_Click(System::Object^ , System::EventArgs^ );

	private: System::Void pictureBox_MouseDoubleClick(System::Object^ , System::Windows::Forms::MouseEventArgs^ );
	
	private: System::Void ImageWorkForm_FormClosed(System::Object^ , System::Windows::Forms::FormClosedEventArgs^ );
	};

}
