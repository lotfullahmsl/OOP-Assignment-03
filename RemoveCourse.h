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
//
//	/// <summary>
//	/// Summary for RemoveCourse
//	/// </summary>
//	public ref class RemoveCourse : public System::Windows::Forms::Form
//	{
//	public:
//		RemoveCourse(void)
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
//		~RemoveCourse()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//	private: System::Windows::Forms::Label^ label1;
//
//	private: System::Windows::Forms::Button^ btDelete;
//	private: System::Windows::Forms::TextBox^ textBox1;
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
//			this->btDelete = (gcnew System::Windows::Forms::Button());
//			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
//			this->SuspendLayout();
//			// 
//			// label1
//			// 
//			this->label1->AutoSize = true;
//			this->label1->Location = System::Drawing::Point(14, 51);
//			this->label1->Name = L"label1";
//			this->label1->Size = System::Drawing::Size(71, 13);
//			this->label1->TabIndex = 0;
//			this->label1->Text = L"Enter Section";
//			// 
//			// btDelete
//			// 
//			this->btDelete->Location = System::Drawing::Point(232, 47);
//			this->btDelete->Name = L"btDelete";
//			this->btDelete->Size = System::Drawing::Size(75, 23);
//			this->btDelete->TabIndex = 2;
//			this->btDelete->Text = L"Delete";
//			this->btDelete->UseVisualStyleBackColor = true;
//			// 
//			// textBox1
//			// 
//			this->textBox1->Location = System::Drawing::Point(91, 49);
//			this->textBox1->Name = L"textBox1";
//			this->textBox1->Size = System::Drawing::Size(127, 20);
//			this->textBox1->TabIndex = 3;
//			// 
//			// RemoveCourse
//			// 
//			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->ClientSize = System::Drawing::Size(319, 156);
//			this->Controls->Add(this->textBox1);
//			this->Controls->Add(this->btDelete);
//			this->Controls->Add(this->label1);
//			this->Name = L"RemoveCourse";
//			this->Text = L"RemoveCourse";
//			this->Load += gcnew System::EventHandler(this, &RemoveCourse::RemoveCourse_Load);
//			this->ResumeLayout(false);
//			this->PerformLayout();
//
//		}
//#pragma endregion
//	private: System::Void RemoveCourse_Load(System::Object^ sender, System::EventArgs^ e) {
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

	public ref class RemoveCourse : public System::Windows::Forms::Form
	{
	public:
		RemoveCourse(void)
		{
			InitializeComponent();
		}

	protected:
		~RemoveCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btDelete;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::Container^ components;

		   void InitializeComponent(void)
		   {
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->btDelete = (gcnew System::Windows::Forms::Button());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->SuspendLayout();

			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(14, 51);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(70, 13);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Course Name";

			   this->btDelete->Location = System::Drawing::Point(232, 47);
			   this->btDelete->Name = L"btDelete";
			   this->btDelete->Size = System::Drawing::Size(75, 23);
			   this->btDelete->TabIndex = 2;
			   this->btDelete->Text = L"Delete";
			   this->btDelete->UseVisualStyleBackColor = true;
			   this->btDelete->Click += gcnew System::EventHandler(this, &RemoveCourse::btDelete_Click);

			   this->textBox1->Location = System::Drawing::Point(91, 49);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(127, 20);
			   this->textBox1->TabIndex = 3;

			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(319, 156);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->btDelete);
			   this->Controls->Add(this->label1);
			   this->Name = L"RemoveCourse";
			   this->Text = L"RemoveCourse";
			   this->ResumeLayout(false);
			   this->PerformLayout();
		   }

	private: System::Void btDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ courseName = textBox1->Text;

		if (String::IsNullOrEmpty(courseName)) {
			MessageBox::Show("Please enter a course name.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ connectionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
		SqlConnection^ conn = gcnew SqlConnection(connectionString);
		// it will delete the course from all the tables 
		array<String^>^ sections = gcnew array<String^> { "Courses", "BSE-2", "BSE-2B", "BSE-4A", "BSE-6A", "BSE-8A" };
		int totalDeleted = 0;

		try {
			conn->Open();
			for each (String ^ section in sections)
			{
				String^ query = String::Format("DELETE FROM [{0}] WHERE [CourseName] = @CourseName", section);
				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@CourseName", courseName);
				totalDeleted += cmd->ExecuteNonQuery();
			}

			if (totalDeleted > 0) {
				MessageBox::Show("Course successfully deleted from all relevant tables.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("No course found for the given name in any table.", "Not Found", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error");
		}
		conn->Close();
		
	}
	};
}
