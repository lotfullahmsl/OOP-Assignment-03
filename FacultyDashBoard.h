#pragma once
#include "AddingCourse.h"
#include "GenrateTimeTable.h"
#include "TeacherWiseSearch.h"
#include "DayWiseSearch.h"
#include "SectionWiseChoise.h"
#include "RoomWiseSearch.h"
#include "RemoveCourse.h"
#include "MakeUpClass.h"

namespace Assignment03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FacultyDashBoard
	/// </summary>
	public ref class FacultyDashBoard : public System::Windows::Forms::Form
	{
	public:
		FacultyDashBoard(void)
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
		~FacultyDashBoard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::TextBox^ tbChoise;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ btOK;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;


	protected:

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->tbChoise = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btOK = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(214, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dashboard";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(86, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(162, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"1. Genrate TimeTable";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(88, 220);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(176, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"8. Add a Make up Class";
			this->label3->Click += gcnew System::EventHandler(this, &FacultyDashBoard::label3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(88, 102);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(163, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"3. Search Room Wise";
			this->label5->Click += gcnew System::EventHandler(this, &FacultyDashBoard::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(88, 78);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(251, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"2. Search TimeTable Teacher wise";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(524, 344);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(40, 13);
			this->linkLabel1->TabIndex = 6;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Cancel";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &FacultyDashBoard::linkLabel1_LinkClicked);
			// 
			// tbChoise
			// 
			this->tbChoise->Location = System::Drawing::Point(214, 253);
			this->tbChoise->Name = L"tbChoise";
			this->tbChoise->Size = System::Drawing::Size(36, 20);
			this->tbChoise->TabIndex = 7;
			this->tbChoise->TextChanged += gcnew System::EventHandler(this, &FacultyDashBoard::tbChoise_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(112, 251);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 20);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Your Choise";
			// 
			// btOK
			// 
			this->btOK->Location = System::Drawing::Point(268, 253);
			this->btOK->Name = L"btOK";
			this->btOK->Size = System::Drawing::Size(49, 23);
			this->btOK->TabIndex = 9;
			this->btOK->Text = L"OK";
			this->btOK->UseVisualStyleBackColor = true;
			this->btOK->Click += gcnew System::EventHandler(this, &FacultyDashBoard::btOK_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(89, 196);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(140, 20);
			this->label9->TabIndex = 11;
			this->label9->Text = L"7. Remove Course";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(89, 149);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(148, 20);
			this->label10->TabIndex = 12;
			this->label10->Text = L"5. Search Day Wise";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(89, 125);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(119, 20);
			this->label11->TabIndex = 13;
			this->label11->Text = L"4. Section Wise";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(89, 173);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(125, 20);
			this->label12->TabIndex = 14;
			this->label12->Text = L"6. Add A Course";
			// 
			// FacultyDashBoard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 378);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->btOK);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tbChoise);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"FacultyDashBoard";
			this->Text = L"FacultyDashBoard";
			this->Load += gcnew System::EventHandler(this, &FacultyDashBoard::FacultyDashBoard_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	//  public: bool switchToSectionChoise = false;
	  public: bool switchToAddingCourse = false;
	  public: bool switchToGenrateTimeTable = false;
	  public: bool switchToDayWiseSearch = false;
	  public: bool switchToSectionWiseSearch = false;
	  public: bool switchToRoomWiseSearch = false;
	  public: bool switchToTeacherWiseSearch = false;
	  public: bool switchToRemoveCourse = false;
	  public: bool switchToMakeUpClass = false;
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	this->Close();
}
private: System::Void FacultyDashBoard_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btOK_Click(System::Object^ sender, System::EventArgs^ e) {

	int choise = Convert::ToInt32(tbChoise->Text);

	if (choise == 1) {
		switchToGenrateTimeTable = true;
		GenrateTimeTable^ genrateTimeTable = gcnew GenrateTimeTable();
		genrateTimeTable->ShowDialog();
	}
	else if (choise == 2) {
		switchToTeacherWiseSearch = true;
		TeacherWiseSearch^ teacherWiseSearch = gcnew TeacherWiseSearch();
		teacherWiseSearch->ShowDialog();
		
	}
	else if (choise == 3) {
		switchToRoomWiseSearch = true;
		RoomWiseSearch^ roomWiseSearch = gcnew RoomWiseSearch();
		roomWiseSearch->ShowDialog();
		
	}
	else if (choise == 4) {
		switchToSectionWiseSearch = true;
		SectionWiseChoise^ sectionWise = gcnew SectionWiseChoise();
		sectionWise->ShowDialog();
		
	}
	else if (choise == 5) {
		switchToDayWiseSearch = true;
		DayWiseSearch^ dayWiseSearch = gcnew DayWiseSearch();
		dayWiseSearch->ShowDialog();
	}
	else if (choise == 6) {
		switchToAddingCourse = true;
		AddingCourse^ addingCourse = gcnew AddingCourse();
		addingCourse->ShowDialog();		
	}
	else if (choise == 7) {
		switchToRemoveCourse = true;
		RemoveCourse^ removingCourse = gcnew RemoveCourse();
		removingCourse->ShowDialog();
	}
	else if (choise == 8) {
		switchToMakeUpClass = true;
		MakeUpClass^ makeUpClass = gcnew MakeUpClass();
		makeUpClass->ShowDialog();
	}
	else {
		MessageBox::Show("Invalid Choise");
	}
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbChoise_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
