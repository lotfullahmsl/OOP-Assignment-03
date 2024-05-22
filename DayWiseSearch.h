#pragma once

namespace Assignment03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for DayWiseSearch
	/// </summary>
	public ref class DayWiseSearch : public System::Windows::Forms::Form
	{
	public:
		DayWiseSearch(void)
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
		~DayWiseSearch()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cbSection;
	private: System::Windows::Forms::ComboBox^ cbDay;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btSearch;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanelResults; // Added FlowLayoutPanel

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
			this->cbSection = (gcnew System::Windows::Forms::ComboBox());
			this->cbDay = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btSearch = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanelResults = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// cbSection
			// 
			this->cbSection->FormattingEnabled = true;
			this->cbSection->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"BSE-2", L"BSE-2B", L"BSE-4A", L"BSE-6A", L"BSE-8A" });
			this->cbSection->Location = System::Drawing::Point(195, 12);
			this->cbSection->Name = L"cbSection";
			this->cbSection->Size = System::Drawing::Size(121, 21);
			this->cbSection->TabIndex = 0;
			// 
			// cbDay
			// 
			this->cbDay->FormattingEnabled = true;
			this->cbDay->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Mon", L"Tue", L"Wed", L"Thu", L"Fri" });
			this->cbDay->Location = System::Drawing::Point(195, 48);
			this->cbDay->Name = L"cbDay";
			this->cbDay->Size = System::Drawing::Size(121, 21);
			this->cbDay->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(130, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Section";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(134, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Day";
			// 
			// btSearch
			// 
			this->btSearch->Location = System::Drawing::Point(346, 31);
			this->btSearch->Name = L"btSearch";
			this->btSearch->Size = System::Drawing::Size(75, 23);
			this->btSearch->TabIndex = 4;
			this->btSearch->Text = L"Search";
			this->btSearch->UseVisualStyleBackColor = true;
			this->btSearch->Click += gcnew System::EventHandler(this, &DayWiseSearch::btSearch_Click);
			// 
			// flowLayoutPanelResults
			// 
			this->flowLayoutPanelResults->AutoScroll = true;
			this->flowLayoutPanelResults->Location = System::Drawing::Point(13, 90);
			this->flowLayoutPanelResults->Name = L"flowLayoutPanelResults";
			this->flowLayoutPanelResults->Size = System::Drawing::Size(925, 343);
			this->flowLayoutPanelResults->TabIndex = 5;
			// 
			// DayWiseSearch
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(950, 436);
			this->Controls->Add(this->btSearch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cbDay);
			this->Controls->Add(this->cbSection);
			this->Controls->Add(this->flowLayoutPanelResults);
			this->MinimumSize = System::Drawing::Size(966, 475);
			this->Name = L"DayWiseSearch";
			this->Text = L"DayWiseSearch";
			this->Load += gcnew System::EventHandler(this, &DayWiseSearch::DayWiseSearch_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DayWiseSearch_Load(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void btSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ Section = cbSection->Text;  
		String^ Day = cbDay->Text;          

		
		String^ tableName= "[dbo].[" + Section + "]";

		String^ ConninctionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
		SqlConnection^ Conn = gcnew SqlConnection(ConninctionString);

		try {
			Conn->Open();
			String^ query = "SELECT * FROM " + tableName + " WHERE [Day] = @day"; 

			SqlCommand^ cmd = gcnew SqlCommand(query, Conn);
			cmd->Parameters->AddWithValue("@day", Day); 

			SqlDataReader^ reader = cmd->ExecuteReader();

			
			flowLayoutPanelResults->Controls->Clear();

			
			//
			//
			// Took Help From ChatGPT
			//
			//
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

			// Processing each row of data
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
		catch (Exception^ ex) {
			MessageBox::Show("An error occurred: " + ex->Message);
		}
		
			Conn->Close();
		
	}


	
	};
}
