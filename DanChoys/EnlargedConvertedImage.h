#pragma once

namespace Enlarged {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class EnlargConvertedImage : public System::Windows::Forms::Form {

	public: EnlargConvertedImage(Image^ image);

	protected: ~EnlargConvertedImage();

	private: System::Windows::Forms::PictureBox^  pictureBox;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

	private: void InitializeComponent(void);

#pragma endregion

	private: System::Void pictureBox_Click(System::Object^ , System::EventArgs^ );

	};
}
