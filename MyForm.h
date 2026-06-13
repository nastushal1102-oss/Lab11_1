#pragma once

namespace Lab11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		System::Collections::Generic::List<int>^ numbersList = gcnew System::Collections::Generic::List<int>();
		int sumResult = 0;       // Для збереження суми
		bool isCalculated = false; // Прапорець, щоб не записувати порожній файл
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	protected:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(92, 46);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(193, 260);
			this->listBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(120, 332);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 57);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Читати з файла дані";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(568, 76);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(146, 55);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Обчислити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(572, 326);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(152, 63);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Записати у файл";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(559, 188);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(185, 18);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Сума чисел, кратних 5";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(559, 238);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 16);
			this->label2->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(903, 445);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ filePath = "numbers.txt";

		if (!System::IO::File::Exists(filePath)) {
			MessageBox::Show("Файл numbers.txt не знайдено!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Очищаємо список на формі та наш список у пам'яті перед новим зчитуванням
		listBox1->Items->Clear();
		numbersList->Clear();
		isCalculated = false; // Скидаємо прапорець обчислення
		label2->Text = "0";

		String^ content = System::IO::File::ReadAllText(filePath);
		array<Char>^ separators = { ' ', '\n', '\r', '\t' };
		array<String^>^ stringNumbers = content->Split(separators, System::StringSplitOptions::RemoveEmptyEntries);

		for (int i = 0; i < stringNumbers->Length; i++) {
			int num = Convert::ToInt32(stringNumbers[i]);
			numbersList->Add(num); // Зберігаємо в пам'ять
			listBox1->Items->Add(num.ToString()); // Виводимо на екран
		}
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Помилка при зчитуванні файлу: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (numbersList->Count == 0) {
		MessageBox::Show("Спочатку зчитайте дані з файлу!", "Увага", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	sumResult = 0; // Обнуляємо суму перед рахунком

	// Перебираємо збережені числа
	for each (int num in numbersList) {
		if (num % 5 == 0) {
			sumResult += num;
		}
	}

	// Виводимо результат на форму
	label2->Text = sumResult.ToString();
	isCalculated = true; // Дозволяємо запис у файл
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isCalculated) {
		MessageBox::Show("Спочатку виконайте обчислення!", "Увага", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	try {
		// Створюємо або перезаписуємо файл numbers.txt
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter("numbers.txt", false, System::Text::Encoding::GetEncoding(1251));

		writer->WriteLine("Числа з файлу, які кратні 5:");
		for each (int num in numbersList) {
			if (num % 5 == 0) {
				writer->Write(num + " "); // Пишемо числа через пробіл
			}
		}

		writer->WriteLine(); // Перехід на новий рядок
		writer->WriteLine("Сума чисел, кратних 5: " + sumResult);

		writer->Close(); // Обов'язково закриваємо файл

		MessageBox::Show("Числа, кратні 5, та їх суму було записано у файл output.txt", "Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Помилка при записі у файл: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
