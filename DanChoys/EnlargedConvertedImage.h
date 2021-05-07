#pragma once

namespace Enlarged {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� EnlargedConvertedImage
	/// </summary>

	public ref class EnlargConvertedImage : public System::Windows::Forms::Form {
	public:

		EnlargConvertedImage(Image^ image);

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>

		~EnlargConvertedImage();

	private: System::Windows::Forms::PictureBox^  pictureBox;

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>

		void InitializeComponent(void);

#pragma endregion

	private: System::Void pictureBox_Click(System::Object^  sender, System::EventArgs^  e);

	};
}
