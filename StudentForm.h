#pragma once
#include "StudentLoginForm.h"


namespace Assignment03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for StudentForm
	/// </summary>
	public ref class StudentForm : public System::Windows::Forms::Form
	{
	public:
		StudentForm(void)
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
		~StudentForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbRollNo;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbPassword;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbCPassword;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbDepartment;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tbSection;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btOK;
	private: System::Windows::Forms::Button^ btCancel;
	private: System::Windows::Forms::LinkLabel^ lllogin;


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
			this->tbRollNo = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbCPassword = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbDepartment = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbSection = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btOK = (gcnew System::Windows::Forms::Button());
			this->btCancel = (gcnew System::Windows::Forms::Button());
			this->lllogin = (gcnew System::Windows::Forms::LinkLabel());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(211, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Register";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(52, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Roll-No";
			// 
			// tbRollNo
			// 
			this->tbRollNo->Location = System::Drawing::Point(150, 74);
			this->tbRollNo->Name = L"tbRollNo";
			this->tbRollNo->Size = System::Drawing::Size(234, 20);
			this->tbRollNo->TabIndex = 2;
			this->tbRollNo->TextChanged += gcnew System::EventHandler(this, &StudentForm::tbRollNo_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(52, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Password";
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(150, 100);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(234, 20);
			this->tbPassword->TabIndex = 2;
			this->tbPassword->TextChanged += gcnew System::EventHandler(this, &StudentForm::tbPassword_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(52, 129);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Confirm Password";
			// 
			// tbCPassword
			// 
			this->tbCPassword->Location = System::Drawing::Point(150, 126);
			this->tbCPassword->Name = L"tbCPassword";
			this->tbCPassword->PasswordChar = '*';
			this->tbCPassword->Size = System::Drawing::Size(234, 20);
			this->tbCPassword->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(52, 155);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Department";
			// 
			// tbDepartment
			// 
			this->tbDepartment->Location = System::Drawing::Point(150, 152);
			this->tbDepartment->Name = L"tbDepartment";
			this->tbDepartment->Size = System::Drawing::Size(234, 20);
			this->tbDepartment->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(52, 181);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(43, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Section";
			// 
			// tbSection
			// 
			this->tbSection->Location = System::Drawing::Point(150, 178);
			this->tbSection->Name = L"tbSection";
			this->tbSection->Size = System::Drawing::Size(234, 20);
			this->tbSection->TabIndex = 2;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->btOK, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btCancel, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(183, 207);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(171, 41);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// btOK
			// 
			this->btOK->Location = System::Drawing::Point(3, 3);
			this->btOK->Name = L"btOK";
			this->btOK->Size = System::Drawing::Size(79, 35);
			this->btOK->TabIndex = 0;
			this->btOK->Text = L"OK";
			this->btOK->UseVisualStyleBackColor = true;
			this->btOK->Click += gcnew System::EventHandler(this, &StudentForm::btOK_Click);
			// 
			// btCancel
			// 
			this->btCancel->Location = System::Drawing::Point(88, 3);
			this->btCancel->Name = L"btCancel";
			this->btCancel->Size = System::Drawing::Size(79, 35);
			this->btCancel->TabIndex = 0;
			this->btCancel->Text = L"Cancel";
			this->btCancel->UseVisualStyleBackColor = true;
			this->btCancel->Click += gcnew System::EventHandler(this, &StudentForm::btCancel_Click);
			// 
			// lllogin
			// 
			this->lllogin->AutoSize = true;
			this->lllogin->Location = System::Drawing::Point(435, 253);
			this->lllogin->Name = L"lllogin";
			this->lllogin->Size = System::Drawing::Size(33, 13);
			this->lllogin->TabIndex = 4;
			this->lllogin->TabStop = true;
			this->lllogin->Text = L"Login";
			this->lllogin->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &StudentForm::lllogin_LinkClicked);
			// 
			// StudentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(480, 275);
			this->Controls->Add(this->lllogin);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbSection);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tbDepartment);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->tbCPassword);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbRollNo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"StudentForm";
			this->Text = L"StudentForm";
			this->Load += gcnew System::EventHandler(this, &StudentForm::StudentForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: bool switchTologin = false;
	private: System::Void StudentForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
}
	private: System::Void btOK_Click(System::Object^ sender, System::EventArgs^ e) {
		//read text box values
		String ^rollNo = tbRollNo->Text;
		String ^password = tbPassword->Text;
		String ^cPassword = tbCPassword->Text;
		String ^department = tbDepartment->Text;
		String ^section = tbSection->Text;
		
		if (rollNo == "" || password == "" || cPassword == "" || department == "" || section == "")
			{
			MessageBox::Show("Please fill all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
		if (password != cPassword)
		{
			MessageBox::Show("Password does not match", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
		try {

			//connection string
			
			String^ connString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=Registration;Integrated Security=True;";
			//connecting to sql
			SqlConnection^ sqlConn = gcnew SqlConnection(connString);
			sqlConn->Open();

			
			

			//sql query
			String^ query = "INSERT INTO [dbo].[Registration] (RollNo, Password, Department, Section) VALUES (@rollno, @password, @department, @section)";

			SqlCommand^ command = gcnew SqlCommand(query, sqlConn);
			command->Parameters->AddWithValue("@rollno", rollNo);
			command->Parameters->AddWithValue("@password", password);
			command->Parameters->AddWithValue("@department", department);
			command->Parameters->AddWithValue("@section", section);
			command->ExecuteNonQuery();
			

			MessageBox::Show("Registration Successful", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			sqlConn->Close();
			
			


		}
		catch (Exception ^ex) {
			MessageBox::Show(ex->Message, "Failed to register", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		this->Close();

		

	}
private: System::Void tbRollNo_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lllogin_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	//switching to loging form
	switchTologin = true;
	StudentLoginForm^ stLoginForm = gcnew StudentLoginForm();
	stLoginForm->ShowDialog();


}
};
}
