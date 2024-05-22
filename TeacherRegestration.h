#pragma once
#include "TeacherSignin.h"

namespace Assignment03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for TeacherRegestration
	/// </summary>
	public ref class TeacherRegestration : public System::Windows::Forms::Form
	{
	public:
		TeacherRegestration(void)
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
		~TeacherRegestration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lable;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btOK;

	private: System::Windows::Forms::TextBox^ tbEmail;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbPassword;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbPosition;
	private: System::Windows::Forms::Button^ tbCancel;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;


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
			this->lable = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btOK = (gcnew System::Windows::Forms::Button());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbPosition = (gcnew System::Windows::Forms::TextBox());
			this->tbCancel = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// lable
			// 
			this->lable->AutoSize = true;
			this->lable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lable->Location = System::Drawing::Point(150, 46);
			this->lable->Name = L"lable";
			this->lable->Size = System::Drawing::Size(92, 25);
			this->lable->TabIndex = 0;
			this->lable->Text = L"Sign up";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(56, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Email";
			// 
			// btOK
			// 
			this->btOK->Location = System::Drawing::Point(217, 202);
			this->btOK->Name = L"btOK";
			this->btOK->Size = System::Drawing::Size(75, 23);
			this->btOK->TabIndex = 2;
			this->btOK->Text = L"OK";
			this->btOK->UseVisualStyleBackColor = true;
			this->btOK->Click += gcnew System::EventHandler(this, &TeacherRegestration::button1_Click);
			// 
			// tbEmail
			// 
			this->tbEmail->Location = System::Drawing::Point(125, 84);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(192, 20);
			this->tbEmail->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(56, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Password";
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(125, 127);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->Size = System::Drawing::Size(192, 20);
			this->tbPassword->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(56, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Position";
			this->label3->Click += gcnew System::EventHandler(this, &TeacherRegestration::label3_Click);
			// 
			// tbPosition
			// 
			this->tbPosition->Location = System::Drawing::Point(125, 163);
			this->tbPosition->Name = L"tbPosition";
			this->tbPosition->Size = System::Drawing::Size(192, 20);
			this->tbPosition->TabIndex = 7;
			// 
			// tbCancel
			// 
			this->tbCancel->Location = System::Drawing::Point(143, 202);
			this->tbCancel->Name = L"tbCancel";
			this->tbCancel->Size = System::Drawing::Size(75, 23);
			this->tbCancel->TabIndex = 8;
			this->tbCancel->Text = L"Cancel";
			this->tbCancel->UseVisualStyleBackColor = true;
			this->tbCancel->Click += gcnew System::EventHandler(this, &TeacherRegestration::tbCancel_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(344, 239);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(39, 13);
			this->linkLabel1->TabIndex = 9;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Sign in";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &TeacherRegestration::linkLabel1_LinkClicked);
			// 
			// TeacherRegestration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(411, 261);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->tbCancel);
			this->Controls->Add(this->tbPosition);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->btOK);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lable);
			this->Name = L"TeacherRegestration";
			this->Text = L"TeacherRegestration";
			this->Load += gcnew System::EventHandler(this, &TeacherRegestration::TeacherRegestration_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: bool switchToSignin = false;
	private: System::Void TeacherRegestration_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = tbEmail->Text;
		String^ password = tbPassword->Text;
		String^ position = tbPosition->Text;

		if (email == "" || password == "" || position == "") {
			MessageBox::Show("Please fill all the fields");
			return;
		}
		try {
			String^ ConnictionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=Registration;Integrated Security=True;";
			SqlConnection^ connection = gcnew SqlConnection(ConnictionString);
			connection->Open();
			String^ query = "INSERT INTO [TeacherRegester] (Email, Password, Position) VALUES (@email, @password, @position)";
			SqlCommand^ cmd = gcnew SqlCommand(query, connection);

			cmd->Parameters->AddWithValue("@email", email);
			cmd->Parameters->AddWithValue("@password", password);
			cmd->Parameters->AddWithValue("@position", position);
			cmd->ExecuteNonQuery();

			MessageBox::Show("Registered successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
			connection->Close();



		}
		catch (Exception^ x) {
		MessageBox::Show(x->Message, "Failed to register", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->Close();
	}
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	switchToSignin = true;
	this->Close();
	TeacherSignin^ teacherSignin = gcnew TeacherSignin();
	teacherSignin->ShowDialog();

}
};
}
