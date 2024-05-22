//#pragma once
//
//namespace Assignment03 {
//
//	using namespace System;
//	using namespace System::ComponentModel;
//	using namespace System::Collections;
//	using namespace System::Windows::Forms;
//	using namespace System::Data;
//	using namespace System::Drawing;
//	using namespace System::Data::SqlClient;
//	
//
//	/// <summary>
//	/// Summary for TeacherWiseSearch
//	/// </summary>
//	public ref class TeacherWiseSearch : public System::Windows::Forms::Form
//	{
//	public:
//		TeacherWiseSearch(void)
//		{
//			InitializeComponent();
//			//
//			//TODO: Add the constructor code here
//			//
//		}
//
//	protected:
//		/// <summary>
//		/// Clean up any resources being used.
//		/// </summary>
//		~TeacherWiseSearch()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//	private: System::Windows::Forms::Label^ label1;
//	private: System::Windows::Forms::Button^ btSearch;
//	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanelResults;
//	private: System::Windows::Forms::TextBox^ tbTeacher;
//	protected:
//
//	private:
//		/// <summary>
//		/// Required designer variable.
//		/// </summary>
//		System::ComponentModel::Container ^components;
//
//#pragma region Windows Form Designer generated code
//		/// <summary>
//		/// Required method for Designer support - do not modify
//		/// the contents of this method with the code editor.
//		/// </summary>
//		void InitializeComponent(void)
//		{
//			this->label1 = (gcnew System::Windows::Forms::Label());
//			this->btSearch = (gcnew System::Windows::Forms::Button());
//			this->tbTeacher = (gcnew System::Windows::Forms::TextBox());
//			this->flowLayoutPanelResults = (gcnew System::Windows::Forms::FlowLayoutPanel());
//			this->SuspendLayout();
//			// 
//			// label1
//			// 
//			this->label1->AutoSize = true;
//			this->label1->Location = System::Drawing::Point(206, 17);
//			this->label1->Name = L"label1";
//			this->label1->Size = System::Drawing::Size(78, 13);
//			this->label1->TabIndex = 0;
//			this->label1->Text = L"Teacher Name";
//			// 
//			// btSearch
//			// 
//			this->btSearch->Location = System::Drawing::Point(465, 14);
//			this->btSearch->Name = L"btSearch";
//			this->btSearch->Size = System::Drawing::Size(75, 23);
//			this->btSearch->TabIndex = 1;
//			this->btSearch->Text = L"Search";
//			this->btSearch->UseVisualStyleBackColor = true;
//			this->btSearch->Click += gcnew System::EventHandler(this, &TeacherWiseSearch::btSearch_Click);
//			// 
//			// tbTeacher
//			// 
//			this->tbTeacher->Location = System::Drawing::Point(291, 15);
//			this->tbTeacher->Name = L"tbTeacher";
//			this->tbTeacher->Size = System::Drawing::Size(168, 20);
//			this->tbTeacher->TabIndex = 2;
//			// 
//			// flowLayoutPanelResults
//			// 
//			this->flowLayoutPanelResults->AutoScroll = true;
//			this->flowLayoutPanelResults->Location = System::Drawing::Point(13, 90);
//			this->flowLayoutPanelResults->Name = L"flowLayoutPanelResults";
//			this->flowLayoutPanelResults->Size = System::Drawing::Size(925, 343);
//			this->flowLayoutPanelResults->TabIndex = 5;
//			// 
//			// TeacherWiseSearch
//			// 
//			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->ClientSize = System::Drawing::Size(840, 366);
//			this->Controls->Add(this->tbTeacher);
//			this->Controls->Add(this->btSearch);
//			this->Controls->Add(this->label1);
//			this->Name = L"TeacherWiseSearch";
//			this->Text = L"TeacherWiseSearch";
//			this->Load += gcnew System::EventHandler(this, &TeacherWiseSearch::TeacherWiseSearch_Load);
//			this->ResumeLayout(false);
//			this->PerformLayout();
//
//		}
//#pragma endregion
//	private: System::Void TeacherWiseSearch_Load(System::Object^ sender, System::EventArgs^ e) {
//	}
//	private: System::Void btSearch_Click(System::Object^ sender, System::EventArgs^ e) {
//		String^ Teacher = tbTeacher->Text;
//
//		if (Teacher == "") {
//			MessageBox::Show("Invalid Input");
//			return;
//		}
//
//		String^ ConninctionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
//		SqlConnection^ Conn = gcnew SqlConnection(ConninctionString);
//
//		try {
//			Conn->Open();
//			String^ query = "SELECT * FROM [dbo].[Courses] WHERE [Teacher] = @Teacher";
//
//			SqlCommand^ cmd = gcnew SqlCommand(query, Conn);
//			cmd->Parameters->AddWithValue("@room", Teacher);
//
//			SqlDataReader^ reader = cmd->ExecuteReader();
//
//			flowLayoutPanelResults->Controls->Clear();
//
//			array<String^>^ headers = { "Course Name", "Course ID", "Teacher", "Room", "Section", "Timing", "Credit Hours", "Day" };
//			FlowLayoutPanel^ headerPanel = gcnew FlowLayoutPanel();
//			headerPanel->FlowDirection = FlowDirection::LeftToRight;
//			headerPanel->AutoSize = true;
//
//			for each (String ^ header in headers) {
//				Label^ label = gcnew Label();
//				label->Text = header + ": ";
//				label->Width = 100;
//				label->AutoSize = false;
//				label->TextAlign = ContentAlignment::MiddleLeft;
//				headerPanel->Controls->Add(label);
//			}
//			flowLayoutPanelResults->Controls->Add(headerPanel);
//
//			while (reader->Read()) {
//				FlowLayoutPanel^ rowPanel = gcnew FlowLayoutPanel();
//				rowPanel->FlowDirection = FlowDirection::LeftToRight;
//				rowPanel->AutoSize = true;
//
//				array<String^>^ columns = { "CourseName", "CourseID", "Teacher", "Room", "Section", "Timing", "CreditHours", "Day" };
//				for each (String ^ column in columns) {
//					Label^ valueLabel = gcnew Label();
//					valueLabel->Text = reader[column]->ToString();
//					valueLabel->Width = 100;
//					valueLabel->AutoSize = false;
//					valueLabel->TextAlign = ContentAlignment::MiddleLeft;
//					rowPanel->Controls->Add(valueLabel);
//				}
//
//				flowLayoutPanelResults->Controls->Add(rowPanel);
//			}
//
//			reader->Close();
//
//			if (flowLayoutPanelResults->Controls->Count == 1) {
//				MessageBox::Show("No records found for the given Room.");
//			}
//
//		}
//		catch (Exception^ e) {
//			MessageBox::Show(e->Message);
//		}
//
//		Conn->Close();
//	}
//	};
//}
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
	/// Summary for TeacherWiseSearch
	/// </summary>
	public ref class TeacherWiseSearch : public System::Windows::Forms::Form
	{
	public:
		TeacherWiseSearch(void)
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
		~TeacherWiseSearch()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btSearch;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanelResults;
	private: System::Windows::Forms::TextBox^ tbTeacher;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btSearch = (gcnew System::Windows::Forms::Button());
			this->tbTeacher = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanelResults = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(206, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Teacher Name";
			// 
			// btSearch
			// 
			this->btSearch->Location = System::Drawing::Point(465, 14);
			this->btSearch->Name = L"btSearch";
			this->btSearch->Size = System::Drawing::Size(75, 23);
			this->btSearch->TabIndex = 1;
			this->btSearch->Text = L"Search";
			this->btSearch->UseVisualStyleBackColor = true;
			this->btSearch->Click += gcnew System::EventHandler(this, &TeacherWiseSearch::btSearch_Click);
			// 
			// tbTeacher
			// 
			this->tbTeacher->Location = System::Drawing::Point(291, 15);
			this->tbTeacher->Name = L"tbTeacher";
			this->tbTeacher->Size = System::Drawing::Size(168, 20);
			this->tbTeacher->TabIndex = 2;
			// 
			// flowLayoutPanelResults
			// 
			this->flowLayoutPanelResults->AutoScroll = true;
			this->flowLayoutPanelResults->Location = System::Drawing::Point(13, 90);
			this->flowLayoutPanelResults->Name = L"flowLayoutPanelResults";
			this->flowLayoutPanelResults->Size = System::Drawing::Size(925, 343);
			this->flowLayoutPanelResults->TabIndex = 5;
			// 
			// TeacherWiseSearch
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(840, 366);
			this->Controls->Add(this->flowLayoutPanelResults); // Ensure flowLayoutPanelResults is added to the form
			this->Controls->Add(this->tbTeacher);
			this->Controls->Add(this->btSearch);
			this->Controls->Add(this->label1);
			this->Name = L"TeacherWiseSearch";
			this->Text = L"TeacherWiseSearch";
			this->Load += gcnew System::EventHandler(this, &TeacherWiseSearch::TeacherWiseSearch_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TeacherWiseSearch_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ Teacher = tbTeacher->Text;

		if (Teacher == "") {
			MessageBox::Show("Invalid Input");
			return;
		}

		String^ ConninctionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
		SqlConnection^ Conn = gcnew SqlConnection(ConninctionString);

		try {
			Conn->Open();
			String^ query = "SELECT * FROM [dbo].[Courses] WHERE [Teacher] = @Teacher";

			SqlCommand^ cmd = gcnew SqlCommand(query, Conn);
			cmd->Parameters->AddWithValue("@Teacher", Teacher); // Correct parameter name

			SqlDataReader^ reader = cmd->ExecuteReader();

			flowLayoutPanelResults->Controls->Clear();

			array<String^>^ headers = { "Course Name", "Course ID", "Teacher", "Room", "Section", "Timing", "Credit Hours", "Day" };
			FlowLayoutPanel^ headerPanel = gcnew FlowLayoutPanel();
			headerPanel->FlowDirection = FlowDirection::LeftToRight;
			headerPanel->AutoSize = true;

			for each (String ^ header in headers) {
				Label^ label = gcnew Label();
				label->Text = header + ": ";
				label->Width = 100;
				label->AutoSize = false;
				label->TextAlign = ContentAlignment::MiddleLeft;
				headerPanel->Controls->Add(label);
			}
			flowLayoutPanelResults->Controls->Add(headerPanel);

			while (reader->Read()) {
				FlowLayoutPanel^ rowPanel = gcnew FlowLayoutPanel();
				rowPanel->FlowDirection = FlowDirection::LeftToRight;
				rowPanel->AutoSize = true;

				array<String^>^ columns = { "CourseName", "CourseID", "Teacher", "Room", "Section", "Timing", "CreditHours", "Day" };
				for each (String ^ column in columns) {
					Label^ valueLabel = gcnew Label();
					valueLabel->Text = reader[column]->ToString();
					valueLabel->Width = 100;
					valueLabel->AutoSize = false;
					valueLabel->TextAlign = ContentAlignment::MiddleLeft;
					rowPanel->Controls->Add(valueLabel);
				}

				flowLayoutPanelResults->Controls->Add(rowPanel);
			}

			reader->Close();

			if (flowLayoutPanelResults->Controls->Count == 1) {
				MessageBox::Show("No records found for the given Teacher.");
			}

		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}

		Conn->Close();
	}
	};
}
