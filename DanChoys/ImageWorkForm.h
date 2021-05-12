#pragma once
#include "ImageUploadForm.h"
#include "ImageWorkClass.h"

namespace Work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ImageWorkForm
	/// </summary>
	public ref class ImageWorkForm : public System::Windows::Forms::Form {
	public:

		ImageWorkForm(Upload::ImageUploadForm^ imageUploadForm, ImageWork^ imageWork);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>

		~ImageWorkForm();

	private:
		Upload::ImageUploadForm^ _imageUploadForm = nullptr;
		ImageWork^ _imageWork = nullptr;
		bool _isUsedTypeChanging = false;

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
	private: System::Void sizeTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e);

	private: System::Void sizeNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void transparencyTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e);

	private: System::Void transparencyNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void xTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e);

	private: System::Void xNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void yTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e);

	private: System::Void yNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void nextButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void pictureBox_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	
	private: System::Void ImageWorkForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
			 
	};

}
