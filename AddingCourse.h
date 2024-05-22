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
	/// Summary for AddingCourse
	/// </summary>
	public ref class AddingCourse : public System::Windows::Forms::Form
	{
	public:
		AddingCourse(void)
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
		~AddingCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tbCourseName;
	private: System::Windows::Forms::TextBox^ tbCourseID;
	private: System::Windows::Forms::ComboBox^ cbSection;
	private: System::Windows::Forms::ComboBox^ cbTiming;
	private: System::Windows::Forms::ComboBox^ cbCreditHours;





	private: System::Windows::Forms::Button^ btAdd;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ tbTeacher;
	private: System::Windows::Forms::TextBox^ tbRoom;
	private: System::Windows::Forms::ComboBox^ cbDay;



	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ cbCourseType;

	private: System::Windows::Forms::Label^ label10;

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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbCourseName = (gcnew System::Windows::Forms::TextBox());
			this->tbCourseID = (gcnew System::Windows::Forms::TextBox());
			this->cbSection = (gcnew System::Windows::Forms::ComboBox());
			this->cbTiming = (gcnew System::Windows::Forms::ComboBox());
			this->cbCreditHours = (gcnew System::Windows::Forms::ComboBox());
			this->btAdd = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbTeacher = (gcnew System::Windows::Forms::TextBox());
			this->tbRoom = (gcnew System::Windows::Forms::TextBox());
			this->cbDay = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cbCourseType = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(146, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Adding Course";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(72, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Course ID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(70, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Course Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(76, 299);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Credit Hours";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(78, 274);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Timing";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(76, 245);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(43, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Section";
			// 
			// tbCourseName
			// 
			this->tbCourseName->Location = System::Drawing::Point(168, 85);
			this->tbCourseName->Name = L"tbCourseName";
			this->tbCourseName->Size = System::Drawing::Size(175, 20);
			this->tbCourseName->TabIndex = 6;
			// 
			// tbCourseID
			// 
			this->tbCourseID->Location = System::Drawing::Point(168, 113);
			this->tbCourseID->Name = L"tbCourseID";
			this->tbCourseID->Size = System::Drawing::Size(175, 20);
			this->tbCourseID->TabIndex = 7;
			// 
			// cbSection
			// 
			this->cbSection->FormattingEnabled = true;
			this->cbSection->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"BSE-2A", L"BSE-2B", L"BSE-4A", L"BSE-6A", L"BSE-8A" });
			this->cbSection->Location = System::Drawing::Point(168, 238);
			this->cbSection->Name = L"cbSection";
			this->cbSection->Size = System::Drawing::Size(175, 21);
			this->cbSection->TabIndex = 8;
			// 
			// cbTiming
			// 
			this->cbTiming->FormattingEnabled = true;
			this->cbTiming->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"8:30 - 9:25", L"9:30 - 10:25", L"10:30 - 11:25",
					L"11:30 - 12:25", L"12:30 - 1:25", L"1:30 - 2:25", L"2:30 - 3:25", L"3:30 - 4:25", L"", L"", L"", L"", L"", L"", L""
			});
			this->cbTiming->Location = System::Drawing::Point(168, 270);
			this->cbTiming->Name = L"cbTiming";
			this->cbTiming->Size = System::Drawing::Size(175, 21);
			this->cbTiming->TabIndex = 9;
			this->cbTiming->SelectedIndexChanged += gcnew System::EventHandler(this, &AddingCourse::cbTiming_SelectedIndexChanged);
			// 
			// cbCreditHours
			// 
			this->cbCreditHours->FormattingEnabled = true;
			this->cbCreditHours->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"1", L"2", L"3" });
			this->cbCreditHours->Location = System::Drawing::Point(168, 299);
			this->cbCreditHours->Name = L"cbCreditHours";
			this->cbCreditHours->Size = System::Drawing::Size(175, 21);
			this->cbCreditHours->TabIndex = 10;
			// 
			// btAdd
			// 
			this->btAdd->Location = System::Drawing::Point(221, 364);
			this->btAdd->Name = L"btAdd";
			this->btAdd->Size = System::Drawing::Size(75, 23);
			this->btAdd->TabIndex = 11;
			this->btAdd->Text = L"Add";
			this->btAdd->UseVisualStyleBackColor = true;
			this->btAdd->Click += gcnew System::EventHandler(this, &AddingCourse::btAdd_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(72, 186);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(47, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Teacher";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(75, 213);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Room";
			// 
			// tbTeacher
			// 
			this->tbTeacher->Location = System::Drawing::Point(168, 179);
			this->tbTeacher->Name = L"tbTeacher";
			this->tbTeacher->Size = System::Drawing::Size(175, 20);
			this->tbTeacher->TabIndex = 14;
			// 
			// tbRoom
			// 
			this->tbRoom->Location = System::Drawing::Point(168, 206);
			this->tbRoom->Name = L"tbRoom";
			this->tbRoom->Size = System::Drawing::Size(175, 20);
			this->tbRoom->TabIndex = 15;
			// 
			// cbDay
			// 
			this->cbDay->FormattingEnabled = true;
			this->cbDay->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Mon", L"Tue", L"Wed", L"Thu", L"Fri" });
			this->cbDay->Location = System::Drawing::Point(168, 326);
			this->cbDay->Name = L"cbDay";
			this->cbDay->Size = System::Drawing::Size(175, 21);
			this->cbDay->TabIndex = 16;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(76, 334);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(26, 13);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Day";
			// 
			// cbCourseType
			// 
			this->cbCourseType->FormattingEnabled = true;
			this->cbCourseType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Lab", L"Theory" });
			this->cbCourseType->Location = System::Drawing::Point(168, 148);
			this->cbCourseType->Name = L"cbCourseType";
			this->cbCourseType->Size = System::Drawing::Size(175, 21);
			this->cbCourseType->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(70, 151);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(67, 13);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Course Type";
			// 
			// AddingCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(476, 432);
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
			this->Name = L"AddingCourse";
			this->Text = L"AddingCourse";
			this->Load += gcnew System::EventHandler(this, &AddingCourse::AddingCourse_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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

		if (courseName == "" || courseID == "" || section == "" || timing == "" || creditHours == "") {
			MessageBox::Show("Please fill all the fields");
			return;
		}
		if (day == "Mon" && courseType == "Lab") {
			MessageBox::Show("Cant Arrange Lab on Monday");
			return;
		}
		try
		{
			String^ constring = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
			SqlConnection^ connectionDataBase = gcnew SqlConnection(constring);
			connectionDataBase->Open();
			
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

			MessageBox::Show("Course added successfully");
			
			if (cbSection->Text == "BSE-2A") {

				String^ query = "INSERT INTO [dbo].[BSE-2] (CourseName, CourseID, Teacher, Room, Section, Timing, CreditHours, Day) VALUES (@coursename, @courseid, @teacher, @room, @section, @timing, @credithours, @day)";
				SqlCommand^ BSE2cmd = gcnew SqlCommand(query, connectionDataBase);

				BSE2cmd->Parameters->AddWithValue("@coursename", courseName);
				BSE2cmd->Parameters->AddWithValue("@courseid", courseID);
				BSE2cmd->Parameters->AddWithValue("@teacher", teacher);
				BSE2cmd->Parameters->AddWithValue("@room", room);
				BSE2cmd->Parameters->AddWithValue("@section", section);
				BSE2cmd->Parameters->AddWithValue("@timing", timing);
				BSE2cmd->Parameters->AddWithValue("@credithours", creditHours);
				BSE2cmd->Parameters->AddWithValue("@day", day);
				BSE2cmd->ExecuteNonQuery();

				MessageBox::Show("Course added successfully");
				this->Close();
			}

			if (cbSection->Text == "BSE-2B") {
				String^ query = "INSERT INTO [dbo].[BSE-2B] (CourseName, CourseID, Teacher, Room, Section, Timing, CreditHours, Day) VALUES (@coursename, @courseid, @teacher, @room, @section, @timing, @credithours, @day)";
				SqlCommand^ BSE2Bcmd = gcnew SqlCommand(query, connectionDataBase);

				BSE2Bcmd->Parameters->AddWithValue("@coursename", courseName);
				BSE2Bcmd->Parameters->AddWithValue("@courseid", courseID);
				BSE2Bcmd->Parameters->AddWithValue("@teacher", teacher);
				BSE2Bcmd->Parameters->AddWithValue("@room", room);
				BSE2Bcmd->Parameters->AddWithValue("@section", section);
				BSE2Bcmd->Parameters->AddWithValue("@timing", timing);
				BSE2Bcmd->Parameters->AddWithValue("@credithours", creditHours);
				BSE2Bcmd->Parameters->AddWithValue("@day", day);
				BSE2Bcmd->ExecuteNonQuery();

				MessageBox::Show("Course added successfully");
				this->Close();
			}
			if (cbSection->Text == "BSE-4A") {
				String^ query = "INSERT INTO [dbo].[BSE-4A] (CourseName, CourseID, Teacher, Room, Section, Timing, CreditHours, Day) VALUES (@coursename, @courseid, @teacher, @room, @section, @timing, @credithours, @day)";
				SqlCommand^ BSE4Acmd = gcnew SqlCommand(query, connectionDataBase);

				BSE4Acmd->Parameters->AddWithValue("@coursename", courseName);
				BSE4Acmd->Parameters->AddWithValue("@courseid", courseID);
				BSE4Acmd->Parameters->AddWithValue("@teacher", teacher);
				BSE4Acmd->Parameters->AddWithValue("@room", room);
				BSE4Acmd->Parameters->AddWithValue("@section", section);
				BSE4Acmd->Parameters->AddWithValue("@timing", timing);
				BSE4Acmd->Parameters->AddWithValue("@credithours", creditHours);
				BSE4Acmd->Parameters->AddWithValue("@day", day);
				BSE4Acmd->ExecuteNonQuery();

				MessageBox::Show("Course added successfully");
				this->Close();
			}
			if (cbSection->Text == "BSE-6A") {
				String^ query = "INSERT INTO [dbo].[BSE-6A] (CourseName, CourseID, Teacher, Room, Section, Timing, CreditHours, Day) VALUES (@coursename, @courseid, @teacher, @room, @section, @timing, @credithours, @day)";
				SqlCommand^ BSE6Acmd = gcnew SqlCommand(query, connectionDataBase);

				BSE6Acmd->Parameters->AddWithValue("@coursename", courseName);
				BSE6Acmd->Parameters->AddWithValue("@courseid", courseID);
				BSE6Acmd->Parameters->AddWithValue("@teacher", teacher);
				BSE6Acmd->Parameters->AddWithValue("@room", room);
				BSE6Acmd->Parameters->AddWithValue("@section", section);
				BSE6Acmd->Parameters->AddWithValue("@timing", timing);
				BSE6Acmd->Parameters->AddWithValue("@credithours", creditHours);
				BSE6Acmd->Parameters->AddWithValue("@day", day);
				BSE6Acmd->ExecuteNonQuery();

				MessageBox::Show("Course added successfully");
				this->Close();
			}
			if (cbSection->Text == "BSE-8A") {
				String^ query = "INSERT INTO [dbo].[BSE-8A] (CourseName, CourseID, Teacher, Room, Section, Timing, CreditHours, Day) VALUES (@coursename, @courseid, @teacher, @room, @section, @timing, @credithours, @day)";
				SqlCommand^ BSE8Acmd = gcnew SqlCommand(query, connectionDataBase);

				BSE8Acmd->Parameters->AddWithValue("@coursename", courseName);
				BSE8Acmd->Parameters->AddWithValue("@courseid", courseID);
				BSE8Acmd->Parameters->AddWithValue("@teacher", teacher);
				BSE8Acmd->Parameters->AddWithValue("@room", room);
				BSE8Acmd->Parameters->AddWithValue("@section", section);
				BSE8Acmd->Parameters->AddWithValue("@timing", timing);
				BSE8Acmd->Parameters->AddWithValue("@credithours", creditHours);
				BSE8Acmd->Parameters->AddWithValue("@day", day);
				BSE8Acmd->ExecuteNonQuery();

				MessageBox::Show("Course added successfully");
				this->Close();
			}



		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Failed to connect to database", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void cbTiming_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void AddingCourse_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
