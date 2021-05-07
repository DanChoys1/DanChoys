#pragma once

namespace Enlarged {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ EnlargedConvertedImage
	/// </summary>

	public ref class EnlargConvertedImage : public System::Windows::Forms::Form {
	public:

		EnlargConvertedImage(Image^ image);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>

		~EnlargConvertedImage();

	private: System::Windows::Forms::PictureBox^  pictureBox;

	protected:

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

	private: System::Void pictureBox_Click(System::Object^  sender, System::EventArgs^  e);

	};
}
