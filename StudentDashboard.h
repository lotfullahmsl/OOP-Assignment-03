#pragma once
#include "GenrateTimeTable.h"
#include "TeacherWiseSearch.h"
#include "RoomWiseSearch.h"
#include "SectionWiseChoise.h"
#include "DayWiseSearch.h"



namespace Assignment03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StudentDashboard
	/// </summary>
	public ref class StudentDashboard : public System::Windows::Forms::Form
	{
	public:
		StudentDashboard(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label11;
	protected:
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btOK;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ tbChoise;

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
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btOK = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbChoise = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(63, 142);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(119, 20);
			this->label11->TabIndex = 19;
			this->label11->Text = L"4. Section Wise";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(63, 166);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(148, 20);
			this->label10->TabIndex = 18;
			this->label10->Text = L"5. Search Day Wise";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(62, 95);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(251, 20);
			this->label6->TabIndex = 17;
			this->label6->Text = L"2. Search TimeTable Teacher wise";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(62, 119);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(163, 20);
			this->label5->TabIndex = 16;
			this->label5->Text = L"3. Search Room Wise";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(60, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(162, 20);
			this->label2->TabIndex = 15;
			this->label2->Text = L"1. Genrate TimeTable";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(188, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 31);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Dashboard";
			// 
			// btOK
			// 
			this->btOK->Location = System::Drawing::Point(236, 196);
			this->btOK->Name = L"btOK";
			this->btOK->Size = System::Drawing::Size(49, 23);
			this->btOK->TabIndex = 22;
			this->btOK->Text = L"OK";
			this->btOK->UseVisualStyleBackColor = true;
			this->btOK->Click += gcnew System::EventHandler(this, &StudentDashboard::btOK_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(80, 195);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 20);
			this->label7->TabIndex = 21;
			this->label7->Text = L"Your Choise";
			// 
			// tbChoise
			// 
			this->tbChoise->Location = System::Drawing::Point(182, 197);
			this->tbChoise->Name = L"tbChoise";
			this->tbChoise->Size = System::Drawing::Size(36, 20);
			this->tbChoise->TabIndex = 20;
			// 
			// StudentDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(480, 316);
			this->Controls->Add(this->btOK);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tbChoise);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"StudentDashboard";
			this->Text = L"StudentDashboard";
			this->Load += gcnew System::EventHandler(this, &StudentDashboard::StudentDashboard_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: bool switchToGenrateTimeTable = false;
	public: bool switchToTeacherWise = false;
	public: bool switchToRoomWise = false;
	public: bool switchToSectinWise = false;
	public: bool switchToDayWise = false;
	private: System::Void btOK_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ Choices = tbChoise->Text;
		if (Choices == "1")
		{
			switchToGenrateTimeTable = true;
			GenrateTimeTable^ genrateTimeTable = gcnew GenrateTimeTable();
			genrateTimeTable->ShowDialog();
		}
		else if (Choices == "2")
		{
			switchToTeacherWise = true;
			TeacherWiseSearch^ TeacherWisesearch = gcnew TeacherWiseSearch();
			TeacherWisesearch->ShowDialog();
		}
		else if (Choices == "3")
		{
			switchToRoomWise = true;
			RoomWiseSearch^ roomWiseSearch = gcnew RoomWiseSearch();
			roomWiseSearch->ShowDialog();
		}
		else if (Choices == "4")
		{
			switchToSectinWise = true;
			SectionWiseChoise^ sectionWiseSearch = gcnew SectionWiseChoise();
			sectionWiseSearch->ShowDialog();
		}
		else if (Choices == "5")
		{
			switchToDayWise = true;
			DayWiseSearch^ dayWiseSearch = gcnew DayWiseSearch();
			dayWiseSearch->ShowDialog();
		}

	}
private: System::Void StudentDashboard_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
