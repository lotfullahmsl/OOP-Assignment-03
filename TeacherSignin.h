#pragma once
#include "FacultyDashBoard.h"

namespace Assignment03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;


	/// <summary>
	/// Summary for TeacherSignin
	/// </summary>
	public ref class TeacherSignin : public System::Windows::Forms::Form
	{
	public:
		TeacherSignin(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			// 
			//
			this->CenterToScreen();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TeacherSignin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btOK;
	private: System::Windows::Forms::TextBox^ tbEmail;
	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbPassword;

	private: System::Windows::Forms::Button^ btCancel;


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
			this->btOK = (gcnew System::Windows::Forms::Button());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->btCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(131, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign in";
			// 
			// btOK
			// 
			this->btOK->Location = System::Drawing::Point(107, 179);
			this->btOK->Name = L"btOK";
			this->btOK->Size = System::Drawing::Size(75, 23);
			this->btOK->TabIndex = 1;
			this->btOK->Text = L"OK";
			this->btOK->UseVisualStyleBackColor = true;
			this->btOK->Click += gcnew System::EventHandler(this, &TeacherSignin::btOK_Click);
			// 
			// tbEmail
			// 
			this->tbEmail->Location = System::Drawing::Point(95, 80);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(205, 20);
			this->tbEmail->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(36, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Email";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(36, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Password";
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(95, 121);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->Size = System::Drawing::Size(205, 20);
			this->tbPassword->TabIndex = 5;
			// 
			// btCancel
			// 
			this->btCancel->Location = System::Drawing::Point(188, 179);
			this->btCancel->Name = L"btCancel";
			this->btCancel->Size = System::Drawing::Size(75, 23);
			this->btCancel->TabIndex = 6;
			this->btCancel->Text = L"Cancel";
			this->btCancel->UseVisualStyleBackColor = true;
			this->btCancel->Click += gcnew System::EventHandler(this, &TeacherSignin::btCancel_Click);
			// 
			// TeacherSignin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(350, 261);
			this->Controls->Add(this->btCancel);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->btOK);
			this->Controls->Add(this->label1);
			this->Name = L"TeacherSignin";
			this->Text = L"TeacherSignin";
			this->Load += gcnew System::EventHandler(this, &TeacherSignin::TeacherSignin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: bool switchToFacultyDashboard = false;
	private: System::Void TeacherSignin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btOK_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ email = tbEmail->Text;
	String^ password = tbPassword->Text;

	if (tbEmail->Text == "" || tbPassword->Text == "") {
		MessageBox::Show("Please fill in all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}


	try {

		String^ conn_String = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=Registration;Integrated Security=True;";
		SqlConnection^ conn = gcnew SqlConnection(conn_String);
		conn->Open();

		String^ query = "SELECT * FROM [dbo].[TeacherRegester]  WHERE Email=@email AND Password=@password;";
		SqlCommand^ sqlCommand = gcnew SqlCommand(query, conn);

		sqlCommand->Parameters->Add(gcnew SqlParameter("@email", email));
		sqlCommand->Parameters->Add(gcnew SqlParameter("@password", password));
		SqlDataReader^ dr = sqlCommand->ExecuteReader();

		if (dr->Read()) {

			MessageBox::Show("Login Successful", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			switchToFacultyDashboard = true;
			FacultyDashBoard^ facultyDashBoard = gcnew FacultyDashBoard();
			facultyDashBoard->ShowDialog();

		}
		else {
			MessageBox::Show("Login Failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error in Connection to the database", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
