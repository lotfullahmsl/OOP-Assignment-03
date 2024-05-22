#pragma once

namespace Assignment03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for F_SectionChoise
	/// </summary>
	public ref class F_SectionChoise : public System::Windows::Forms::Form
	{
	public:
		F_SectionChoise(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~F_SectionChoise()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ btEnter;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->btEnter = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(84, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Section Choise";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"BSE-2A", L"BSE-2B", L"BSE-4A", L"BSE-6A", L"BSE-8A" });
			this->comboBox1->Location = System::Drawing::Point(71, 88);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(107, 21);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &F_SectionChoise::comboBox1_SelectedIndexChanged);
			// 
			// btEnter
			// 
			this->btEnter->Location = System::Drawing::Point(95, 131);
			this->btEnter->Name = L"btEnter";
			this->btEnter->Size = System::Drawing::Size(54, 23);
			this->btEnter->TabIndex = 3;
			this->btEnter->Text = L"Enter";
			this->btEnter->UseVisualStyleBackColor = true;
			this->btEnter->Click += gcnew System::EventHandler(this, &F_SectionChoise::btEnter_Click);
			// 
			// F_SectionChoise
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(250, 184);
			this->Controls->Add(this->btEnter);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Name = L"F_SectionChoise";
			this->Text = L"F_SectionChoise";
			this->Load += gcnew System::EventHandler(this, &F_SectionChoise::F_SectionChoise_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//public: bool switchToTimeTable = false;
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void F_SectionChoise_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btEnter_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		if (comboBox1->Text == "BSE-2A") {

			/*switchToTimeTable = true;
			GenrateTimeTable^ genrateTimeTable = gcnew GenrateTimeTable();
			genrateTimeTable->Show();*/			
			
		}
		else if (comboBox1->Text == "BSE-2B") {
			
		}
		else if (comboBox1->Text == "BSE-4A") {
			
		}
		else if (comboBox1->Text == "BSE-6A") {
			
		}
		else if (comboBox1->Text == "BSE-8A") {
		}
	}
	};
}
