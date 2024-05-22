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
	/// Summary for GenrateTimeTable
	/// </summary>
	public ref class GenrateTimeTable : public System::Windows::Forms::Form
	{
	public:
		GenrateTimeTable(void)
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
		~GenrateTimeTable()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ cbSection;

	private: System::Windows::Forms::Button^ tbGenrate;


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
			this->cbSection = (gcnew System::Windows::Forms::ComboBox());
			this->tbGenrate = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(231, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TimeTable";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(98, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Chose Section";
			this->label2->Click += gcnew System::EventHandler(this, &GenrateTimeTable::label2_Click);
			// 
			// cbSection
			// 
			this->cbSection->FormattingEnabled = true;
			this->cbSection->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"BSE-2A", L"BSE-2B", L"BSE-4A", L"BSE-6A", L"BSE-8A" });
			this->cbSection->Location = System::Drawing::Point(215, 60);
			this->cbSection->Name = L"cbSection";
			this->cbSection->Size = System::Drawing::Size(153, 21);
			this->cbSection->TabIndex = 2;
			// 
			// tbGenrate
			// 
			this->tbGenrate->Location = System::Drawing::Point(400, 60);
			this->tbGenrate->Name = L"tbGenrate";
			this->tbGenrate->Size = System::Drawing::Size(54, 23);
			this->tbGenrate->TabIndex = 3;
			this->tbGenrate->Text = L"Genrate";
			this->tbGenrate->UseVisualStyleBackColor = true;
			this->tbGenrate->Click += gcnew System::EventHandler(this, &GenrateTimeTable::tbGenrate_Click);
			// 
			// GenrateTimeTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(909, 395);
			this->Controls->Add(this->tbGenrate);
			this->Controls->Add(this->cbSection);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MinimumSize = System::Drawing::Size(925, 434);
			this->Name = L"GenrateTimeTable";
			this->Text = L"GenrateTimeTable";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void tbGenrate_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ section = cbSection->Text;

		if (section == "") {
			MessageBox::Show("invalid section");
		}
		else if (section == "BSE-2A") {
			String^ connectionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
			String^ query = "SELECT * FROM [dbo].[BSE-2]";
			SqlConnection^ con = gcnew SqlConnection(connectionString);

			try {
				con->Open();
				SqlDataAdapter^ sda = gcnew SqlDataAdapter(query, con);
				DataTable^ dt = gcnew DataTable();
				sda->Fill(dt);
				con->Close();

				// Clear any existing labels
				this->Controls->Clear();

				// Define starting positions
				int startX = 10;
				int startY = 10;
				int verticalSpacing = 30; // Space between rows

				// Create labels dynamically for each row
				for (int i = 0; i < dt->Rows->Count; i++) {
					DataRow^ row = dt->Rows[i];

					Label^ lblCourseID = gcnew Label();
					lblCourseID->Text = "CourseID: " + row["CourseID"]->ToString();
					lblCourseID->Location = System::Drawing::Point(startX, startY + (i * verticalSpacing));
					lblCourseID->AutoSize = true;
					this->Controls->Add(lblCourseID);

					Label^ lblCourseName = gcnew Label();
					lblCourseName->Text = "CourseName: " + row["CourseName"]->ToString();
					lblCourseName->Location = System::Drawing::Point(startX + 100, startY + (i * verticalSpacing));
					lblCourseName->AutoSize = true;
					this->Controls->Add(lblCourseName);

					Label^ lblTeacher = gcnew Label();
					lblTeacher->Text = "Teacher: " + row["Teacher"]->ToString();
					lblTeacher->Location = System::Drawing::Point(startX + 220, startY + (i * verticalSpacing));
					lblTeacher->AutoSize = true;
					this->Controls->Add(lblTeacher);

					Label^ lblRoom = gcnew Label();
					lblRoom->Text = "Room: " + row["Room"]->ToString();
					lblRoom->Location = System::Drawing::Point(startX + 340, startY + (i * verticalSpacing));
					lblRoom->AutoSize = true;
					this->Controls->Add(lblRoom);

					Label^ lblSection = gcnew Label();
					lblSection->Text = "Section: " + row["Section"]->ToString();
					lblSection->Location = System::Drawing::Point(startX + 460, startY + (i * verticalSpacing));
					lblSection->AutoSize = true;
					this->Controls->Add(lblSection);

					Label^ lblTiming = gcnew Label();
					lblTiming->Text = "Timing: " + row["Timing"]->ToString();
					lblTiming->Location = System::Drawing::Point(startX + 580, startY + (i * verticalSpacing));
					lblTiming->AutoSize = true;
					this->Controls->Add(lblTiming);

					Label^ lblCreditHours = gcnew Label();
					lblCreditHours->Text = "CreditHours: " + row["CreditHours"]->ToString();
					lblCreditHours->Location = System::Drawing::Point(startX + 700, startY + (i * verticalSpacing));
					lblCreditHours->AutoSize = true;
					this->Controls->Add(lblCreditHours);

					Label^ lblDay = gcnew Label();
					lblDay->Text = "Day: " + row["Day"]->ToString();
					lblDay->Location = System::Drawing::Point(startX + 820, startY + (i * verticalSpacing));
					lblDay->AutoSize = true;
					this->Controls->Add(lblDay);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
				con->Close();
			}

		}
		
		else if (section == "BSE-2B") {
			String^ connectionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
			String^ query = "SELECT * FROM [dbo].[BSE-2B]";
			SqlConnection^ con = gcnew SqlConnection(connectionString);

			try {
				con->Open();
				SqlDataAdapter^ sda = gcnew SqlDataAdapter(query, con);
				DataTable^ dt = gcnew DataTable();
				sda->Fill(dt);
				con->Close();

				// Clear any existing labels
				this->Controls->Clear();

				// Define starting positions
				int startX = 10;
				int startY = 10;
				int verticalSpacing = 30; // Space between rows

				// Create labels dynamically for each row
				for (int i = 0; i < dt->Rows->Count; i++) {
					DataRow^ row = dt->Rows[i];

					Label^ lblCourseID = gcnew Label();
					lblCourseID->Text = "CourseID: " + row["CourseID"]->ToString();
					lblCourseID->Location = System::Drawing::Point(startX, startY + (i * verticalSpacing));
					lblCourseID->AutoSize = true;
					this->Controls->Add(lblCourseID);

					Label^ lblCourseName = gcnew Label();
					lblCourseName->Text = "CourseName: " + row["CourseName"]->ToString();
					lblCourseName->Location = System::Drawing::Point(startX + 100, startY + (i * verticalSpacing));
					lblCourseName->AutoSize = true;
					this->Controls->Add(lblCourseName);

					Label^ lblTeacher = gcnew Label();
					lblTeacher->Text = "Teacher: " + row["Teacher"]->ToString();
					lblTeacher->Location = System::Drawing::Point(startX + 220, startY + (i * verticalSpacing));
					lblTeacher->AutoSize = true;
					this->Controls->Add(lblTeacher);

					Label^ lblRoom = gcnew Label();
					lblRoom->Text = "Room: " + row["Room"]->ToString();
					lblRoom->Location = System::Drawing::Point(startX + 340, startY + (i * verticalSpacing));
					lblRoom->AutoSize = true;
					this->Controls->Add(lblRoom);

					Label^ lblSection = gcnew Label();
					lblSection->Text = "Section: " + row["Section"]->ToString();
					lblSection->Location = System::Drawing::Point(startX + 460, startY + (i * verticalSpacing));
					lblSection->AutoSize = true;
					this->Controls->Add(lblSection);

					Label^ lblTiming = gcnew Label();
					lblTiming->Text = "Timing: " + row["Timing"]->ToString();
					lblTiming->Location = System::Drawing::Point(startX + 580, startY + (i * verticalSpacing));
					lblTiming->AutoSize = true;
					this->Controls->Add(lblTiming);

					Label^ lblCreditHours = gcnew Label();
					lblCreditHours->Text = "CreditHours: " + row["CreditHours"]->ToString();
					lblCreditHours->Location = System::Drawing::Point(startX + 700, startY + (i * verticalSpacing));
					lblCreditHours->AutoSize = true;
					this->Controls->Add(lblCreditHours);

					Label^ lblDay = gcnew Label();
					lblDay->Text = "Day: " + row["Day"]->ToString();
					lblDay->Location = System::Drawing::Point(startX + 820, startY + (i * verticalSpacing));
					lblDay->AutoSize = true;
					this->Controls->Add(lblDay);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
				con->Close();
			}
		}

		else if (section == "BSE-4A") {
			String^ connectionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
			String^ query = "SELECT * FROM [dbo].[BSE-4A]";
			SqlConnection^ con = gcnew SqlConnection(connectionString);

			try {
				con->Open();
				SqlDataAdapter^ sda = gcnew SqlDataAdapter(query, con);
				DataTable^ dt = gcnew DataTable();
				sda->Fill(dt);
				con->Close();

				// Clear any existing labels
				this->Controls->Clear();

				// Define starting positions
				int startX = 10;
				int startY = 10;
				int verticalSpacing = 30; // Space between rows

				// Create labels dynamically for each row
				for (int i = 0; i < dt->Rows->Count; i++) {
					DataRow^ row = dt->Rows[i];

					Label^ lblCourseID = gcnew Label();
					lblCourseID->Text = "CourseID: " + row["CourseID"]->ToString();
					lblCourseID->Location = System::Drawing::Point(startX, startY + (i * verticalSpacing));
					lblCourseID->AutoSize = true;
					this->Controls->Add(lblCourseID);

					Label^ lblCourseName = gcnew Label();
					lblCourseName->Text = "CourseName: " + row["CourseName"]->ToString();
					lblCourseName->Location = System::Drawing::Point(startX + 100, startY + (i * verticalSpacing));
					lblCourseName->AutoSize = true;
					this->Controls->Add(lblCourseName);

					Label^ lblTeacher = gcnew Label();
					lblTeacher->Text = "Teacher: " + row["Teacher"]->ToString();
					lblTeacher->Location = System::Drawing::Point(startX + 220, startY + (i * verticalSpacing));
					lblTeacher->AutoSize = true;
					this->Controls->Add(lblTeacher);

					Label^ lblRoom = gcnew Label();
					lblRoom->Text = "Room: " + row["Room"]->ToString();
					lblRoom->Location = System::Drawing::Point(startX + 340, startY + (i * verticalSpacing));
					lblRoom->AutoSize = true;
					this->Controls->Add(lblRoom);

					Label^ lblSection = gcnew Label();
					lblSection->Text = "Section: " + row["Section"]->ToString();
					lblSection->Location = System::Drawing::Point(startX + 460, startY + (i * verticalSpacing));
					lblSection->AutoSize = true;
					this->Controls->Add(lblSection);

					Label^ lblTiming = gcnew Label();
					lblTiming->Text = "Timing: " + row["Timing"]->ToString();
					lblTiming->Location = System::Drawing::Point(startX + 580, startY + (i * verticalSpacing));
					lblTiming->AutoSize = true;
					this->Controls->Add(lblTiming);

					Label^ lblCreditHours = gcnew Label();
					lblCreditHours->Text = "CreditHours: " + row["CreditHours"]->ToString();
					lblCreditHours->Location = System::Drawing::Point(startX + 700, startY + (i * verticalSpacing));
					lblCreditHours->AutoSize = true;
					this->Controls->Add(lblCreditHours);

					Label^ lblDay = gcnew Label();
					lblDay->Text = "Day: " + row["Day"]->ToString();
					lblDay->Location = System::Drawing::Point(startX + 820, startY + (i * verticalSpacing));
					lblDay->AutoSize = true;
					this->Controls->Add(lblDay);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
				con->Close();
			}
			}

		else if (section == "BSE-6A") {
			String^ connectionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
			String^ query = "SELECT * FROM [dbo].[BSE-6A]";
			SqlConnection^ con = gcnew SqlConnection(connectionString);

			try {
				con->Open();
				SqlDataAdapter^ sda = gcnew SqlDataAdapter(query, con);
				DataTable^ dt = gcnew DataTable();
				sda->Fill(dt);
				con->Close();

				// Clear any existing labels
				this->Controls->Clear();

				// Define starting positions
				int startX = 10;
				int startY = 10;
				int verticalSpacing = 30; // Space between rows

				// Create labels dynamically for each row
				for (int i = 0; i < dt->Rows->Count; i++) {
					DataRow^ row = dt->Rows[i];

					Label^ lblCourseID = gcnew Label();
					lblCourseID->Text = "CourseID: " + row["CourseID"]->ToString();
					lblCourseID->Location = System::Drawing::Point(startX, startY + (i * verticalSpacing));
					lblCourseID->AutoSize = true;
					this->Controls->Add(lblCourseID);

					Label^ lblCourseName = gcnew Label();
					lblCourseName->Text = "CourseName: " + row["CourseName"]->ToString();
					lblCourseName->Location = System::Drawing::Point(startX + 100, startY + (i * verticalSpacing));
					lblCourseName->AutoSize = true;
					this->Controls->Add(lblCourseName);

					Label^ lblTeacher = gcnew Label();
					lblTeacher->Text = "Teacher: " + row["Teacher"]->ToString();
					lblTeacher->Location = System::Drawing::Point(startX + 220, startY + (i * verticalSpacing));
					lblTeacher->AutoSize = true;
					this->Controls->Add(lblTeacher);

					Label^ lblRoom = gcnew Label();
					lblRoom->Text = "Room: " + row["Room"]->ToString();
					lblRoom->Location = System::Drawing::Point(startX + 340, startY + (i * verticalSpacing));
					lblRoom->AutoSize = true;
					this->Controls->Add(lblRoom);

					Label^ lblSection = gcnew Label();
					lblSection->Text = "Section: " + row["Section"]->ToString();
					lblSection->Location = System::Drawing::Point(startX + 460, startY + (i * verticalSpacing));
					lblSection->AutoSize = true;
					this->Controls->Add(lblSection);

					Label^ lblTiming = gcnew Label();
					lblTiming->Text = "Timing: " + row["Timing"]->ToString();
					lblTiming->Location = System::Drawing::Point(startX + 580, startY + (i * verticalSpacing));
					lblTiming->AutoSize = true;
					this->Controls->Add(lblTiming);

					Label^ lblCreditHours = gcnew Label();
					lblCreditHours->Text = "CreditHours: " + row["CreditHours"]->ToString();
					lblCreditHours->Location = System::Drawing::Point(startX + 700, startY + (i * verticalSpacing));
					lblCreditHours->AutoSize = true;
					this->Controls->Add(lblCreditHours);

					Label^ lblDay = gcnew Label();
					lblDay->Text = "Day: " + row["Day"]->ToString();
					lblDay->Location = System::Drawing::Point(startX + 820, startY + (i * verticalSpacing));
					lblDay->AutoSize = true;
					this->Controls->Add(lblDay);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
				con->Close();
			}
			}

		else if (section == "BSE-8A") {
			String^ connectionString = "Data Source=DESKTOP-5CPB1F4;Initial Catalog=TimeTable;Integrated Security=True;";
			String^ query = "SELECT * FROM [dbo].[BSE-8A]";
			SqlConnection^ con = gcnew SqlConnection(connectionString);

			try {
				con->Open();
				SqlDataAdapter^ sda = gcnew SqlDataAdapter(query, con);
				DataTable^ dt = gcnew DataTable();
				sda->Fill(dt);
				con->Close();

				// Clear any existing labels
				this->Controls->Clear();

				// Define starting positions
				int startX = 10;
				int startY = 10;
				int verticalSpacing = 30; // Space between rows

				// Create labels dynamically for each row
				for (int i = 0; i < dt->Rows->Count; i++) {
					DataRow^ row = dt->Rows[i];

					Label^ lblCourseID = gcnew Label();
					lblCourseID->Text = "CourseID: " + row["CourseID"]->ToString();
					lblCourseID->Location = System::Drawing::Point(startX, startY + (i * verticalSpacing));
					lblCourseID->AutoSize = true;
					this->Controls->Add(lblCourseID);

					Label^ lblCourseName = gcnew Label();
					lblCourseName->Text = "CourseName: " + row["CourseName"]->ToString();
					lblCourseName->Location = System::Drawing::Point(startX + 100, startY + (i * verticalSpacing));
					lblCourseName->AutoSize = true;
					this->Controls->Add(lblCourseName);

					Label^ lblTeacher = gcnew Label();
					lblTeacher->Text = "Teacher: " + row["Teacher"]->ToString();
					lblTeacher->Location = System::Drawing::Point(startX + 220, startY + (i * verticalSpacing));
					lblTeacher->AutoSize = true;
					this->Controls->Add(lblTeacher);

					Label^ lblRoom = gcnew Label();
					lblRoom->Text = "Room: " + row["Room"]->ToString();
					lblRoom->Location = System::Drawing::Point(startX + 340, startY + (i * verticalSpacing));
					lblRoom->AutoSize = true;
					this->Controls->Add(lblRoom);

					Label^ lblSection = gcnew Label();
					lblSection->Text = "Section: " + row["Section"]->ToString();
					lblSection->Location = System::Drawing::Point(startX + 460, startY + (i * verticalSpacing));
					lblSection->AutoSize = true;
					this->Controls->Add(lblSection);

					Label^ lblTiming = gcnew Label();
					lblTiming->Text = "Timing: " + row["Timing"]->ToString();
					lblTiming->Location = System::Drawing::Point(startX + 580, startY + (i * verticalSpacing));
					lblTiming->AutoSize = true;
					this->Controls->Add(lblTiming);

					Label^ lblCreditHours = gcnew Label();
					lblCreditHours->Text = "CreditHours: " + row["CreditHours"]->ToString();
					lblCreditHours->Location = System::Drawing::Point(startX + 700, startY + (i * verticalSpacing));
					lblCreditHours->AutoSize = true;
					this->Controls->Add(lblCreditHours);

					Label^ lblDay = gcnew Label();
					lblDay->Text = "Day: " + row["Day"]->ToString();
					lblDay->Location = System::Drawing::Point(startX + 820, startY + (i * verticalSpacing));
					lblDay->AutoSize = true;
					this->Controls->Add(lblDay);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
				con->Close();
			}
			}

	}
};
}
