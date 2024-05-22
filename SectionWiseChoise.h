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
	/// Summary for SectionWiseChoise
	/// </summary>
	public ref class SectionWiseChoise : public System::Windows::Forms::Form
	{
	public:
		SectionWiseChoise(void)
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
		~SectionWiseChoise()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cbSection;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanelResults; 
	protected:

	private: System::Windows::Forms::Button^ btSearch;

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
			this->cbSection = (gcnew System::Windows::Forms::ComboBox());
			this->btSearch = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanelResults = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(142, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Chose Section";
			// 
			// cbSection
			// 
			this->cbSection->FormattingEnabled = true;
			this->cbSection->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"BSE-2A", L"BSE-2B", L"BSE-4A", L"BSE-6A", L"BSE-8A" });
			this->cbSection->Location = System::Drawing::Point(224, 31);
			this->cbSection->Name = L"cbSection";
			this->cbSection->Size = System::Drawing::Size(144, 21);
			this->cbSection->TabIndex = 1;
			// 
			// btSearch
			// 
			this->btSearch->Location = System::Drawing::Point(385, 29);
			this->btSearch->Name = L"btSearch";
			this->btSearch->Size = System::Drawing::Size(62, 23);
			this->btSearch->TabIndex = 2;
			this->btSearch->Text = L"Search";
			this->btSearch->UseVisualStyleBackColor = true;
			this->btSearch->Click += gcnew System::EventHandler(this, &SectionWiseChoise::btSearch_Click);
			// 
			// flowLayoutPanelResults
			// 
			this->flowLayoutPanelResults->AutoScroll = true;
			this->flowLayoutPanelResults->Location = System::Drawing::Point(13, 90);
			this->flowLayoutPanelResults->Name = L"flowLayoutPanelResults";
			this->flowLayoutPanelResults->Size = System::Drawing::Size(925, 343);
			this->flowLayoutPanelResults->TabIndex = 5;
			// 
			// SectionWiseChoise
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(983, 467);
			this->Controls->Add(this->flowLayoutPanelResults);
			this->Controls->Add(this->btSearch);
			this->Controls->Add(this->cbSection);
			this->Controls->Add(this->label1);
			this->Name = L"SectionWiseChoise";
			this->Text = L"SectionWiseChoise";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ Section = cbSection->Text;
		if (Section == "") {
			MessageBox::Show("Please Enter Something");
			return;
		}

		String^ ConninctionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
		SqlConnection^ Conn = gcnew SqlConnection(ConninctionString);

		try {

			Conn->Open();
			String^ query = "SELECT * FROM [dbo].[Courses] WHERE [Section] = @section";

			SqlCommand^ cmd = gcnew SqlCommand(query, Conn);
			cmd->Parameters->AddWithValue("@section", Section);

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
				MessageBox::Show("No records found for the given Section and Day.");
			}

		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
		
		Conn->Close();
		
	}
	};
}
