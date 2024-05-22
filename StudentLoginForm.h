#pragma once
//#include "StudentForm.h"
#include "StudentDashboard.h"



namespace Assignment03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	/// <summary>
	/// Summary for StudentLoginForm
	/// </summary>
	public ref class StudentLoginForm : public System::Windows::Forms::Form
	{
	public:
		StudentLoginForm(void)
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
		~StudentLoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbRollNo;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::Button^ btSignin;




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
			this->tbRollNo = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->btSignin = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(182, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign in";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(69, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Roll No";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(69, 128);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Password";
			// 
			// tbRollNo
			// 
			this->tbRollNo->Location = System::Drawing::Point(136, 84);
			this->tbRollNo->Name = L"tbRollNo";
			this->tbRollNo->Size = System::Drawing::Size(175, 20);
			this->tbRollNo->TabIndex = 3;
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(136, 125);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(175, 20);
			this->tbPassword->TabIndex = 4;
			// 
			// btSignin
			// 
			this->btSignin->Location = System::Drawing::Point(171, 180);
			this->btSignin->Name = L"btSignin";
			this->btSignin->Size = System::Drawing::Size(90, 32);
			this->btSignin->TabIndex = 5;
			this->btSignin->Text = L"Sign in";
			this->btSignin->UseVisualStyleBackColor = true;
			this->btSignin->Click += gcnew System::EventHandler(this, &StudentLoginForm::btSignin_Click);
			// 
			// StudentLoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(451, 261);
			this->Controls->Add(this->btSignin);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbRollNo);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"StudentLoginForm";
			this->Text = L"StudentLoginForm";
			this->Load += gcnew System::EventHandler(this, &StudentLoginForm::StudentLoginForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: bool switchToRegester = false;
	public: bool switchToDashboard = false;
	private: System::Void StudentLoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btSignin_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ rollNo = tbRollNo->Text;
		String^ password = tbPassword->Text;

		if (rollNo == "" || password == "") {
			MessageBox::Show("Please fill all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try {
			String^ connectionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=Registration;Integrated Security=True;";
			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			sqlConnection->Open();

			String^ query = "SELECT * FROM [dbo].[Registration]  WHERE RollNo=@rollno AND Password=@password;";
			SqlCommand^ sqlCommand = gcnew SqlCommand(query, sqlConnection);

			sqlCommand->Parameters->Add(gcnew SqlParameter("@rollno", rollNo));
			sqlCommand->Parameters->Add(gcnew SqlParameter("@password", password));
			SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();

			if (sqlDataReader->Read()) {  
				MessageBox::Show("Login successful", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				switchToDashboard = true;
				StudentDashboard^ studentDashboard = gcnew StudentDashboard();
				studentDashboard->Show();
		
			}
			else {
				MessageBox::Show("Invalid Email or Password", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			} 

		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message, "Failed to connect to database", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
};
}
