#pragma once

#include "UART_CONFIG.h"

extern bool Init_flag;

namespace Programa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Pasirinkimu_langas
	/// </summary>
	public ref class Pasirinkimu_langas : public System::Windows::Forms::Form
	{
	private:UART_CONFIG^ UART_PARAMETERS;

	public:
		Pasirinkimu_langas(UART_CONFIG^ uartConfig)
		{
			InitializeComponent();
			UART_PARAMETERS = uartConfig;
			// DEFAULT UART PARAM
			if (!Init_flag)
			{
				UART_PARAMETERS->BAUD_RATE = 9600;
				UART_PARAMETERS->STOP_BIT = IO::Ports::StopBits::One;
				UART_PARAMETERS->PARITY_BIT = IO::Ports::Parity::None;
				UART_PARAMETERS->DATA_LENGTH = 8;
				Init_flag = true;
			}
			


			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Pasirinkimu_langas()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ button_UART_OK;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::ComboBox^ comboBoxBAUD;

	private: System::Windows::Forms::ComboBox^ comboBoxPORTS;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownDataBits;
	private: System::Windows::Forms::ComboBox^ comboBoxParity;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::ComboBox^ comboBoxStopBit;

	private: System::Windows::Forms::Label^ label5;


	protected:

	protected:



	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Pasirinkimu_langas::typeid));
			this->button_UART_OK = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxBAUD = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxPORTS = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownDataBits = (gcnew System::Windows::Forms::NumericUpDown());
			this->comboBoxParity = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->comboBoxStopBit = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownDataBits))->BeginInit();
			this->SuspendLayout();
			// 
			// button_UART_OK
			// 
			this->button_UART_OK->BackColor = System::Drawing::Color::MidnightBlue;
			this->button_UART_OK->Location = System::Drawing::Point(77, 345);
			this->button_UART_OK->Name = L"button_UART_OK";
			this->button_UART_OK->Size = System::Drawing::Size(73, 44);
			this->button_UART_OK->TabIndex = 1;
			this->button_UART_OK->Text = L"Apply";
			this->button_UART_OK->UseVisualStyleBackColor = false;
			this->button_UART_OK->Click += gcnew System::EventHandler(this, &Pasirinkimu_langas::button_UART_OK_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::Indigo;
			this->label1->Location = System::Drawing::Point(105, 105);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Baud rate";
			// 
			// comboBoxBAUD
			// 
			this->comboBoxBAUD->BackColor = System::Drawing::Color::Thistle;
			this->comboBoxBAUD->FormattingEnabled = true;
			this->comboBoxBAUD->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"4800", L"9600", L"19200", L"57600", L"115200" });
			this->comboBoxBAUD->Location = System::Drawing::Point(108, 124);
			this->comboBoxBAUD->Name = L"comboBoxBAUD";
			this->comboBoxBAUD->Size = System::Drawing::Size(128, 24);
			this->comboBoxBAUD->TabIndex = 5;
			// 
			// comboBoxPORTS
			// 
			this->comboBoxPORTS->BackColor = System::Drawing::Color::Thistle;
			this->comboBoxPORTS->FormattingEnabled = true;
			this->comboBoxPORTS->Location = System::Drawing::Point(108, 62);
			this->comboBoxPORTS->Name = L"comboBoxPORTS";
			this->comboBoxPORTS->Size = System::Drawing::Size(128, 24);
			this->comboBoxPORTS->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::Color::Indigo;
			this->label2->Location = System::Drawing::Point(105, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Port name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->ForeColor = System::Drawing::Color::Indigo;
			this->label3->Location = System::Drawing::Point(105, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Data bits";
			// 
			// numericUpDownDataBits
			// 
			this->numericUpDownDataBits->BackColor = System::Drawing::Color::Thistle;
			this->numericUpDownDataBits->Location = System::Drawing::Point(108, 186);
			this->numericUpDownDataBits->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			this->numericUpDownDataBits->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownDataBits->Name = L"numericUpDownDataBits";
			this->numericUpDownDataBits->Size = System::Drawing::Size(127, 22);
			this->numericUpDownDataBits->TabIndex = 10;
			this->numericUpDownDataBits->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			// 
			// comboBoxParity
			// 
			this->comboBoxParity->BackColor = System::Drawing::Color::Thistle;
			this->comboBoxParity->FormattingEnabled = true;
			this->comboBoxParity->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"None", L"Even", L"Odd" });
			this->comboBoxParity->Location = System::Drawing::Point(108, 246);
			this->comboBoxParity->Name = L"comboBoxParity";
			this->comboBoxParity->Size = System::Drawing::Size(128, 24);
			this->comboBoxParity->TabIndex = 12;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->ForeColor = System::Drawing::Color::Indigo;
			this->label4->Location = System::Drawing::Point(105, 227);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 16);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Parity";
			// 
			// buttonCancel
			// 
			this->buttonCancel->BackColor = System::Drawing::Color::MidnightBlue;
			this->buttonCancel->Location = System::Drawing::Point(198, 345);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(73, 44);
			this->buttonCancel->TabIndex = 13;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = false;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &Pasirinkimu_langas::buttonCancel_Click);
			// 
			// comboBoxStopBit
			// 
			this->comboBoxStopBit->BackColor = System::Drawing::Color::Thistle;
			this->comboBoxStopBit->FormattingEnabled = true;
			this->comboBoxStopBit->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"One", L"Two" });
			this->comboBoxStopBit->Location = System::Drawing::Point(108, 296);
			this->comboBoxStopBit->Name = L"comboBoxStopBit";
			this->comboBoxStopBit->Size = System::Drawing::Size(128, 24);
			this->comboBoxStopBit->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->ForeColor = System::Drawing::Color::Indigo;
			this->label5->Location = System::Drawing::Point(105, 277);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 16);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Stop bits";
			// 
			// Pasirinkimu_langas
			// 
			this->AcceptButton = this->button_UART_OK;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(349, 433);
			this->Controls->Add(this->comboBoxStopBit);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->comboBoxParity);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->numericUpDownDataBits);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBoxPORTS);
			this->Controls->Add(this->comboBoxBAUD);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_UART_OK);
			this->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Pasirinkimu_langas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Config";
			this->Load += gcnew System::EventHandler(this, &Pasirinkimu_langas::Pasirinkimu_langas_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownDataBits))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Pasirinkimu_langas_Load(System::Object^ sender, System::EventArgs^ e) {
		array<Object^>^ ObjectArray = System::IO::Ports::SerialPort::GetPortNames();
		comboBoxPORTS->Items->Clear();
		comboBoxPORTS->Items->AddRange(ObjectArray);
		this->comboBoxBAUD->Text = System::Convert::ToString(UART_PARAMETERS->BAUD_RATE);
		this->comboBoxParity->Text = System::Convert::ToString(UART_PARAMETERS->PARITY_BIT);
		this->comboBoxStopBit->Text = System::Convert::ToString(UART_PARAMETERS->STOP_BIT);
		this->numericUpDownDataBits->Text = System::Convert::ToString(UART_PARAMETERS->DATA_LENGTH);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button_UART_OK_Click(System::Object^ sender, System::EventArgs^ e) {

		UART_PARAMETERS->BAUD_RATE = System::Convert::ToInt32(this->comboBoxBAUD->Text);
		UART_PARAMETERS->PORT = this->comboBoxPORTS->Text;
		UART_PARAMETERS->STOP_BIT = static_cast<System::IO::Ports::StopBits>(System::Enum::Parse(System::IO::Ports::StopBits::typeid, this->comboBoxStopBit->Text));
		UART_PARAMETERS->PARITY_BIT = static_cast<System::IO::Ports::Parity>(System::Enum::Parse(System::IO::Ports::Parity::typeid, this->comboBoxParity->Text));
		UART_PARAMETERS->DATA_LENGTH = System::Convert::ToInt32(this->numericUpDownDataBits->Text);
		this->Close();
	}
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
