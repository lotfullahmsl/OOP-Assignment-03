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
	/// Summary for RoomWiseSearch
	/// </summary>
	public ref class RoomWiseSearch : public System::Windows::Forms::Form
	{
	public:
		RoomWiseSearch(void)
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
		~RoomWiseSearch()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbRoom;
	private: System::Windows::Forms::Button^ btOK;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanelResults;


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
			this->tbRoom = (gcnew System::Windows::Forms::TextBox());
			this->btOK = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanelResults = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(279, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Choose A Room";
			// 
			// tbRoom
			// 
			this->tbRoom->Location = System::Drawing::Point(396, 25);
			this->tbRoom->Name = L"tbRoom";
			this->tbRoom->Size = System::Drawing::Size(92, 20);
			this->tbRoom->TabIndex = 1;
			// 
			// btOK
			// 
			this->btOK->Location = System::Drawing::Point(551, 23);
			this->btOK->Name = L"btOK";
			this->btOK->Size = System::Drawing::Size(43, 23);
			this->btOK->TabIndex = 2;
			this->btOK->Text = L"OK";
			this->btOK->UseVisualStyleBackColor = true;
			this->btOK->Click += gcnew System::EventHandler(this, &RoomWiseSearch::btOK_Click);
			// 
			// flowLayoutPanelResults
			// 
			this->flowLayoutPanelResults->AutoScroll = true;
			this->flowLayoutPanelResults->Location = System::Drawing::Point(13, 90);
			this->flowLayoutPanelResults->Name = L"flowLayoutPanelResults";
			this->flowLayoutPanelResults->Size = System::Drawing::Size(925, 343);
			this->flowLayoutPanelResults->TabIndex = 5;
			// 
			// RoomWiseSearch
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(985, 454);
			this->Controls->Add(this->flowLayoutPanelResults);
			this->Controls->Add(this->btOK);
			this->Controls->Add(this->tbRoom);
			this->Controls->Add(this->label1);
			this->MinimumSize = System::Drawing::Size(1001, 493);
			this->Name = L"RoomWiseSearch";
			this->Text = L"RoomWiseSearch";
			this->Load += gcnew System::EventHandler(this, &RoomWiseSearch::RoomWiseSearch_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btOK_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ Room = tbRoom->Text;
		if (Room == "") {
			MessageBox::Show("Invalid Input");
			return;
		}

		String^ ConninctionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
		SqlConnection^ Conn = gcnew SqlConnection(ConninctionString);

		try {
			Conn->Open();
			String^ query = "SELECT * FROM [dbo].[Courses] WHERE [Room] = @room";

			SqlCommand^ cmd = gcnew SqlCommand(query, Conn);
			cmd->Parameters->AddWithValue("@room", Room);

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
				MessageBox::Show("No records found for the given Room.");
			}

		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
		
			Conn->Close();
		
	}
	private: System::Void RoomWiseSearch_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
