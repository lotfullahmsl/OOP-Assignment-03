#pragma once

namespace Assignment03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MakeUpClass
	/// </summary>
	public ref class MakeUpClass : public System::Windows::Forms::Form
	{
	public:
		MakeUpClass(void)
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
		~MakeUpClass()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label10;
	protected:
	private: System::Windows::Forms::ComboBox^ cbCourseType;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ cbDay;
	private: System::Windows::Forms::TextBox^ tbRoom;
	private: System::Windows::Forms::TextBox^ tbTeacher;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ btAdd;
	private: System::Windows::Forms::ComboBox^ cbCreditHours;
	private: System::Windows::Forms::ComboBox^ cbTiming;
	private: System::Windows::Forms::ComboBox^ cbSection;
	private: System::Windows::Forms::TextBox^ tbCourseID;
	private: System::Windows::Forms::TextBox^ tbCourseName;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

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
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->cbCourseType = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cbDay = (gcnew System::Windows::Forms::ComboBox());
			this->tbRoom = (gcnew System::Windows::Forms::TextBox());
			this->tbTeacher = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btAdd = (gcnew System::Windows::Forms::Button());
			this->cbCreditHours = (gcnew System::Windows::Forms::ComboBox());
			this->cbTiming = (gcnew System::Windows::Forms::ComboBox());
			this->cbSection = (gcnew System::Windows::Forms::ComboBox());
			this->tbCourseID = (gcnew System::Windows::Forms::TextBox());
			this->tbCourseName = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(131, 149);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(67, 13);
			this->label10->TabIndex = 39;
			this->label10->Text = L"Course Type";
			this->label10->Click += gcnew System::EventHandler(this, &MakeUpClass::label10_Click);
			// 
			// cbCourseType
			// 
			this->cbCourseType->FormattingEnabled = true;
			this->cbCourseType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Lab", L"Theory" });
			this->cbCourseType->Location = System::Drawing::Point(229, 146);
			this->cbCourseType->Name = L"cbCourseType";
			this->cbCourseType->Size = System::Drawing::Size(175, 21);
			this->cbCourseType->TabIndex = 38;
			this->cbCourseType->SelectedIndexChanged += gcnew System::EventHandler(this, &MakeUpClass::cbCourseType_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(137, 332);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(26, 13);
			this->label9->TabIndex = 37;
			this->label9->Text = L"Day";
			this->label9->Click += gcnew System::EventHandler(this, &MakeUpClass::label9_Click);
			// 
			// cbDay
			// 
			this->cbDay->FormattingEnabled = true;
			this->cbDay->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Mon", L"Tue", L"Wed", L"Thu", L"Fri" });
			this->cbDay->Location = System::Drawing::Point(229, 324);
			this->cbDay->Name = L"cbDay";
			this->cbDay->Size = System::Drawing::Size(175, 21);
			this->cbDay->TabIndex = 36;
			this->cbDay->SelectedIndexChanged += gcnew System::EventHandler(this, &MakeUpClass::cbDay_SelectedIndexChanged);
			// 
			// tbRoom
			// 
			this->tbRoom->Location = System::Drawing::Point(229, 204);
			this->tbRoom->Name = L"tbRoom";
			this->tbRoom->Size = System::Drawing::Size(175, 20);
			this->tbRoom->TabIndex = 35;
			this->tbRoom->TextChanged += gcnew System::EventHandler(this, &MakeUpClass::tbRoom_TextChanged);
			// 
			// tbTeacher
			// 
			this->tbTeacher->Location = System::Drawing::Point(229, 177);
			this->tbTeacher->Name = L"tbTeacher";
			this->tbTeacher->Size = System::Drawing::Size(175, 20);
			this->tbTeacher->TabIndex = 34;
			this->tbTeacher->TextChanged += gcnew System::EventHandler(this, &MakeUpClass::tbTeacher_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(136, 211);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 33;
			this->label8->Text = L"Room";
			this->label8->Click += gcnew System::EventHandler(this, &MakeUpClass::label8_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(133, 184);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(47, 13);
			this->label7->TabIndex = 32;
			this->label7->Text = L"Teacher";
			this->label7->Click += gcnew System::EventHandler(this, &MakeUpClass::label7_Click);
			// 
			// btAdd
			// 
			this->btAdd->Location = System::Drawing::Point(282, 362);
			this->btAdd->Name = L"btAdd";
			this->btAdd->Size = System::Drawing::Size(75, 23);
			this->btAdd->TabIndex = 31;
			this->btAdd->Text = L"Add";
			this->btAdd->UseVisualStyleBackColor = true;
			this->btAdd->Click += gcnew System::EventHandler(this, &MakeUpClass::btAdd_Click);
			// 
			// cbCreditHours
			// 
			this->cbCreditHours->FormattingEnabled = true;
			this->cbCreditHours->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"1", L"2", L"3" });
			this->cbCreditHours->Location = System::Drawing::Point(229, 297);
			this->cbCreditHours->Name = L"cbCreditHours";
			this->cbCreditHours->Size = System::Drawing::Size(175, 21);
			this->cbCreditHours->TabIndex = 30;
			this->cbCreditHours->SelectedIndexChanged += gcnew System::EventHandler(this, &MakeUpClass::cbCreditHours_SelectedIndexChanged);
			// 
			// cbTiming
			// 
			this->cbTiming->FormattingEnabled = true;
			this->cbTiming->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"8:30 - 9:25", L"9:30 - 10:25", L"10:30 - 11:25",
					L"11:30 - 12:25", L"12:30 - 1:25", L"1:30 - 2:25", L"2:30 - 3:25", L"3:30 - 4:25", L"", L"", L"", L"", L"", L"", L""
			});
			this->cbTiming->Location = System::Drawing::Point(229, 268);
			this->cbTiming->Name = L"cbTiming";
			this->cbTiming->Size = System::Drawing::Size(175, 21);
			this->cbTiming->TabIndex = 29;
			this->cbTiming->SelectedIndexChanged += gcnew System::EventHandler(this, &MakeUpClass::cbTiming_SelectedIndexChanged);
			// 
			// cbSection
			// 
			this->cbSection->FormattingEnabled = true;
			this->cbSection->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"BSE-2A", L"BSE-2B", L"BSE-4A", L"BSE-6A", L"BSE-8A" });
			this->cbSection->Location = System::Drawing::Point(229, 236);
			this->cbSection->Name = L"cbSection";
			this->cbSection->Size = System::Drawing::Size(175, 21);
			this->cbSection->TabIndex = 28;
			this->cbSection->SelectedIndexChanged += gcnew System::EventHandler(this, &MakeUpClass::cbSection_SelectedIndexChanged);
			// 
			// tbCourseID
			// 
			this->tbCourseID->Location = System::Drawing::Point(229, 111);
			this->tbCourseID->Name = L"tbCourseID";
			this->tbCourseID->Size = System::Drawing::Size(175, 20);
			this->tbCourseID->TabIndex = 27;
			this->tbCourseID->TextChanged += gcnew System::EventHandler(this, &MakeUpClass::tbCourseID_TextChanged);
			// 
			// tbCourseName
			// 
			this->tbCourseName->Location = System::Drawing::Point(229, 83);
			this->tbCourseName->Name = L"tbCourseName";
			this->tbCourseName->Size = System::Drawing::Size(175, 20);
			this->tbCourseName->TabIndex = 26;
			this->tbCourseName->TextChanged += gcnew System::EventHandler(this, &MakeUpClass::tbCourseName_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(137, 243);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(43, 13);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Section";
			this->label6->Click += gcnew System::EventHandler(this, &MakeUpClass::label6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(139, 272);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 13);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Timing";
			this->label5->Click += gcnew System::EventHandler(this, &MakeUpClass::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(137, 297);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Credit Hours";
			this->label4->Click += gcnew System::EventHandler(this, &MakeUpClass::label4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(131, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Course Name";
			this->label3->Click += gcnew System::EventHandler(this, &MakeUpClass::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(133, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Course ID";
			this->label2->Click += gcnew System::EventHandler(this, &MakeUpClass::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(207, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(215, 24);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Adding MakeUp Class";
			this->label1->Click += gcnew System::EventHandler(this, &MakeUpClass::label1_Click);
			// 
			// MakeUpClass
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 427);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->cbCourseType);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->cbDay);
			this->Controls->Add(this->tbRoom);
			this->Controls->Add(this->tbTeacher);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->btAdd);
			this->Controls->Add(this->cbCreditHours);
			this->Controls->Add(this->cbTiming);
			this->Controls->Add(this->cbSection);
			this->Controls->Add(this->tbCourseID);
			this->Controls->Add(this->tbCourseName);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MakeUpClass";
			this->Text = L"MakeUpClass";
			this->Load += gcnew System::EventHandler(this, &MakeUpClass::MakeUpClass_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cbCourseType_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cbDay_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbRoom_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbTeacher_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void cbCreditHours_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cbTiming_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cbSection_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbCourseID_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbCourseName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MakeUpClass_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ courseName = tbCourseName->Text;
		   String^ courseID = tbCourseID->Text;
		   String^ courseType = cbCourseType->Text;
		   String^ room = tbRoom->Text;
		   String^ teacher = tbTeacher->Text;
		   String^ section = cbSection->Text;
		   String^ timing = cbTiming->Text;
		   String^ creditHours = cbCreditHours->Text;
		   String^ day = cbDay->Text;

		   if (courseName->Trim() == "" || courseID->Trim() == "" || section->Trim() == "" || timing->Trim() == "" || creditHours->Trim() == "") {
			   MessageBox::Show("Please fill all the fields", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		   }
		   if (day == "Mon" && courseType == "Lab") {
			   MessageBox::Show("Cannot arrange lab on Monday", "Schedule Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		   }

		   String^ constring = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
		   SqlConnection^ connectionDataBase = gcnew SqlConnection(constring);
		   try {
			   connectionDataBase->Open();
			   String^ queryCheck = "SELECT COUNT(*) FROM [dbo].[Courses] WHERE [Timing] = @timing AND [Section] = @section AND [Day] = @day";
			   SqlCommand^ cmdCheck = gcnew SqlCommand(queryCheck, connectionDataBase);
			   cmdCheck->Parameters->AddWithValue("@timing", timing);
			   cmdCheck->Parameters->AddWithValue("@day", day);

			   int count = Convert::ToInt32(cmdCheck->ExecuteScalar());
			   if (count > 0) {
				   MessageBox::Show("Time slot is not available for this section on the selected day", "Timing Conflict", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   // Insert into Courses table
			   String^ query = "INSERT INTO [dbo].[Courses] (CourseName, CourseID, Teacher, Room, Section, Timing, CreditHours, Day) VALUES (@coursename, @courseid, @teacher, @room, @section, @timing, @credithours, @day)";
			   SqlCommand^ cmd = gcnew SqlCommand(query, connectionDataBase);
			   cmd->Parameters->AddWithValue("@coursename", courseName);
			   cmd->Parameters->AddWithValue("@courseid", courseID);
			   cmd->Parameters->AddWithValue("@teacher", teacher);
			   cmd->Parameters->AddWithValue("@room", room);
			   cmd->Parameters->AddWithValue("@section", section);
			   cmd->Parameters->AddWithValue("@timing", timing);
			   cmd->Parameters->AddWithValue("@credithours", creditHours);
			   cmd->Parameters->AddWithValue("@day", day);
			   cmd->ExecuteNonQuery();

			   // Insert into specific section table
			   String^ sectionQuery = String::Format("INSERT INTO [dbo].[{0}] (CourseName, CourseID, Teacher, Room, Section, Timing, CreditHours, Day) VALUES (@coursename, @courseid, @teacher, @room, @section, @timing, @credithours, @day)", section);
			   SqlCommand^ sectionCmd = gcnew SqlCommand(sectionQuery, connectionDataBase);
			   sectionCmd->Parameters->AddWithValue("@coursename", courseName);
			   sectionCmd->Parameters->AddWithValue("@courseid", courseID);
			   sectionCmd->Parameters->AddWithValue("@teacher", teacher);
			   sectionCmd->Parameters->AddWithValue("@room", room);
			   sectionCmd->Parameters->AddWithValue("@section", section);
			   sectionCmd->Parameters->AddWithValue("@timing", timing);
			   sectionCmd->Parameters->AddWithValue("@credithours", creditHours);
			   sectionCmd->Parameters->AddWithValue("@day", day);
			   sectionCmd->ExecuteNonQuery();

			   MessageBox::Show("Course added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		   }
		   catch (Exception^ ex) {
			   MessageBox::Show(ex->Message, "Failed to connect to database", MessageBoxButtons::OK, MessageBoxIcon::Error);
		   }
		   connectionDataBase->Close();
		   
	   }

};
}
