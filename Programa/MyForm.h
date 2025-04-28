#pragma once
#include <math.h>
#include <string.h>
#include <Windows.h>
#include <stdio.h>
#include "Pasirinkimu_langas.h"
#include "UART_CONFIG.h"

bool Init_flag;

namespace Programa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		UART_CONFIG^ UART;
	public:

		MyForm(void)
		{
			InitializeComponent();
			Init_flag = false;
			UART = gcnew UART_CONFIG();
			chartData->ChartAreas["ChartArea1"]->AxisX->LabelStyle->Format = "0";

			//
			//TODO: Add the constructor code here
			//
		}


	private: int Send_UART_data(String^ message)
	{
		message += "\r\n";
		try
		{
			serialPort1->Write(message);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Check COM port", "Serial Error " + ex->Message);
			return -1;
		}
		return 0;
;

	}
	public: bool Start_UART_flag = false;
	private: String^ rxBuffer = "";
	private: static initonly String^ val = "value = ";
	private: static initonly String^ atVal = " at ";
	private: static initonly String^ msVal = " ms";
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartData;
	public:

	public:




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ buttonStart;

	private: System::Windows::Forms::Label^ labelInfo;
	private: System::Windows::Forms::Button^ buttonCloseCOM;
	private: System::Windows::Forms::ProgressBar^ progressBar;
	private: System::Windows::Forms::Button^ buttonOpenCOM;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ buttonReset;
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Button^ buttonStore;

	private: System::Windows::Forms::Button^ buttonStop;





	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonUART_config;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
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
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::LineAnnotation^ lineAnnotation2 = (gcnew System::Windows::Forms::DataVisualization::Charting::LineAnnotation());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->buttonUART_config = (gcnew System::Windows::Forms::Button());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chartData = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			this->labelInfo = (gcnew System::Windows::Forms::Label());
			this->buttonCloseCOM = (gcnew System::Windows::Forms::Button());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->buttonOpenCOM = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->buttonStore = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartData))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonUART_config
			// 
			this->buttonUART_config->Location = System::Drawing::Point(45, 45);
			this->buttonUART_config->Name = L"buttonUART_config";
			this->buttonUART_config->Size = System::Drawing::Size(181, 41);
			this->buttonUART_config->TabIndex = 1;
			this->buttonUART_config->Text = L"Configuration";
			this->buttonUART_config->UseVisualStyleBackColor = true;
			this->buttonUART_config->Click += gcnew System::EventHandler(this, &MyForm::buttonUART_config_Click);
			// 
			// serialPort1
			// 
			this->serialPort1->ReadTimeout = 100;
			this->serialPort1->ReceivedBytesThreshold = 8;
			this->serialPort1->WriteTimeout = 100;
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort1_DataReceived);
			// 
			// chart1
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chart1->Legends->Add(legend3);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			series5->ChartArea = L"ChartArea1";
			series5->Legend = L"Legend1";
			series5->Name = L"Series1";
			this->chart1->Series->Add(series5);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(42, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 16);
			this->label1->TabIndex = 2;
			// 
			// chartData
			// 
			lineAnnotation2->Name = L"LineAnnotation1";
			lineAnnotation2->Visible = false;
			this->chartData->Annotations->Add(lineAnnotation2);
			this->chartData->BackColor = System::Drawing::Color::Silver;
			this->chartData->BorderlineColor = System::Drawing::Color::Black;
			chartArea4->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea4->AxisX->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea4->AxisX->IsLabelAutoFit = false;
			chartArea4->AxisX->IsStartedFromZero = false;
			chartArea4->AxisX->LabelStyle->Angle = 90;
			chartArea4->AxisX->LabelStyle->Format = L"0";
			chartArea4->AxisX->LabelStyle->Interval = 0;
			chartArea4->AxisX->MajorGrid->Interval = 0;
			chartArea4->AxisX->MajorTickMark->Interval = 0;
			chartArea4->AxisX->MinorGrid->Enabled = true;
			chartArea4->AxisX->MinorGrid->Interval = 200;
			chartArea4->AxisX->MinorGrid->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea4->AxisX->MinorGrid->LineColor = System::Drawing::Color::DarkGray;
			chartArea4->AxisX->MinorTickMark->Enabled = true;
			chartArea4->AxisX->MinorTickMark->LineColor = System::Drawing::Color::DarkGray;
			chartArea4->AxisX->Title = L"Time, ms";
			chartArea4->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			chartArea4->AxisY->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea4->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea4->AxisY->IsLogarithmic = true;
			chartArea4->AxisY->MajorGrid->Interval = 0;
			chartArea4->AxisY->Minimum = 1;
			chartArea4->AxisY->MinorGrid->Enabled = true;
			chartArea4->AxisY->MinorGrid->LineColor = System::Drawing::Color::DarkGray;
			chartArea4->AxisY->MinorTickMark->Enabled = true;
			chartArea4->AxisY->MinorTickMark->LineColor = System::Drawing::Color::DarkGray;
			chartArea4->AxisY->Title = L"Illuminance, lux";
			chartArea4->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			chartArea4->BackColor = System::Drawing::Color::White;
			chartArea4->CursorX->IsUserEnabled = true;
			chartArea4->CursorX->IsUserSelectionEnabled = true;
			chartArea4->CursorX->SelectionColor = System::Drawing::Color::IndianRed;
			chartArea4->CursorY->SelectionColor = System::Drawing::Color::IndianRed;
			chartArea4->Name = L"ChartArea1";
			this->chartData->ChartAreas->Add(chartArea4);
			this->chartData->Cursor = System::Windows::Forms::Cursors::Cross;
			legend4->BorderColor = System::Drawing::Color::Red;
			legend4->Enabled = false;
			legend4->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend4->Name = L"Legend1";
			legend4->Position->Auto = false;
			legend4->Position->Height = 16.88312F;
			legend4->Position->Width = 32;
			legend4->Position->X = 60;
			legend4->Position->Y = 8;
			this->chartData->Legends->Add(legend4);
			this->chartData->Location = System::Drawing::Point(407, 12);
			this->chartData->Name = L"chartData";
			series6->BorderWidth = 4;
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series6->Legend = L"Legend1";
			series6->MarkerColor = System::Drawing::Color::IndianRed;
			series6->Name = L"CH1";
			series7->BorderWidth = 4;
			series7->ChartArea = L"ChartArea1";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series7->Legend = L"Legend1";
			series7->MarkerColor = System::Drawing::Color::Black;
			series7->Name = L"CH2";
			series7->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series8->BorderWidth = 4;
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series8->Legend = L"Legend1";
			series8->Name = L"Difference";
			this->chartData->Series->Add(series6);
			this->chartData->Series->Add(series7);
			this->chartData->Series->Add(series8);
			this->chartData->Size = System::Drawing::Size(624, 499);
			this->chartData->TabIndex = 7;
			this->chartData->Text = L"Luminance";
			title2->Name = L"Title1";
			title2->Visible = false;
			this->chartData->Titles->Add(title2);
			this->chartData->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(82, 256);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 16);
			this->label2->TabIndex = 9;
			this->label2->Text = L"min";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(310, 256);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 16);
			this->label3->TabIndex = 10;
			this->label3->Text = L"max";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(196, 256);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 16);
			this->label4->TabIndex = 11;
			this->label4->Text = L"avg";
			this->label4->Visible = false;
			// 
			// buttonStart
			// 
			this->buttonStart->Location = System::Drawing::Point(269, 45);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(106, 39);
			this->buttonStart->TabIndex = 12;
			this->buttonStart->Text = L"Start";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &MyForm::buttonStart_Click);
			// 
			// buttonStop
			// 
			this->buttonStop->Location = System::Drawing::Point(269, 90);
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->Size = System::Drawing::Size(106, 39);
			this->buttonStop->TabIndex = 13;
			this->buttonStop->Text = L"Stop";
			this->buttonStop->UseVisualStyleBackColor = true;
			this->buttonStop->Click += gcnew System::EventHandler(this, &MyForm::buttonStop_Click);
			// 
			// labelInfo
			// 
			this->labelInfo->AutoSize = true;
			this->labelInfo->Location = System::Drawing::Point(42, 107);
			this->labelInfo->Name = L"labelInfo";
			this->labelInfo->Size = System::Drawing::Size(0, 16);
			this->labelInfo->TabIndex = 14;
			// 
			// buttonCloseCOM
			// 
			this->buttonCloseCOM->Location = System::Drawing::Point(45, 146);
			this->buttonCloseCOM->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->buttonCloseCOM->Name = L"buttonCloseCOM";
			this->buttonCloseCOM->Size = System::Drawing::Size(181, 36);
			this->buttonCloseCOM->TabIndex = 17;
			this->buttonCloseCOM->Text = L"Close port";
			this->buttonCloseCOM->UseVisualStyleBackColor = true;
			this->buttonCloseCOM->Click += gcnew System::EventHandler(this, &MyForm::buttonCloseCOM_Click);
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(45, 188);
			this->progressBar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->progressBar->Maximum = 1;
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(181, 23);
			this->progressBar->Step = 1;
			this->progressBar->TabIndex = 16;
			// 
			// buttonOpenCOM
			// 
			this->buttonOpenCOM->Location = System::Drawing::Point(45, 104);
			this->buttonOpenCOM->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->buttonOpenCOM->Name = L"buttonOpenCOM";
			this->buttonOpenCOM->Size = System::Drawing::Size(181, 36);
			this->buttonOpenCOM->TabIndex = 15;
			this->buttonOpenCOM->Text = L"Open port";
			this->buttonOpenCOM->UseVisualStyleBackColor = true;
			this->buttonOpenCOM->Click += gcnew System::EventHandler(this, &MyForm::buttonOpenCOM_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(168, 311);
			this->label5->Name = L"label5";
			this->label5->Padding = System::Windows::Forms::Padding(40, 20, 40, 20);
			this->label5->Size = System::Drawing::Size(80, 56);
			this->label5->TabIndex = 20;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(282, 311);
			this->label6->Name = L"label6";
			this->label6->Padding = System::Windows::Forms::Padding(40, 20, 40, 20);
			this->label6->Size = System::Drawing::Size(80, 56);
			this->label6->TabIndex = 19;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(54, 311);
			this->label7->Name = L"label7";
			this->label7->Padding = System::Windows::Forms::Padding(40, 20, 40, 20);
			this->label7->Size = System::Drawing::Size(80, 56);
			this->label7->TabIndex = 18;
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(269, 188);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(106, 30);
			this->buttonReset->TabIndex = 21;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &MyForm::buttonReset_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->ForeColor = System::Drawing::Color::Red;
			this->buttonExit->Location = System::Drawing::Point(269, 484);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(106, 27);
			this->buttonExit->TabIndex = 22;
			this->buttonExit->Text = L"Exit";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm::buttonExit_Click);
			// 
			// buttonStore
			// 
			this->buttonStore->Location = System::Drawing::Point(45, 484);
			this->buttonStore->Name = L"buttonStore";
			this->buttonStore->Size = System::Drawing::Size(181, 27);
			this->buttonStore->TabIndex = 23;
			this->buttonStore->Text = L"Store";
			this->buttonStore->UseVisualStyleBackColor = true;
			this->buttonStore->Click += gcnew System::EventHandler(this, &MyForm::buttonStore_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1043, 523);
			this->Controls->Add(this->buttonStore);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->buttonCloseCOM);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->buttonOpenCOM);
			this->Controls->Add(this->labelInfo);
			this->Controls->Add(this->buttonStop);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->chartData);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonUART_config);
			this->Name = L"MyForm";
			this->Text = L"LuxIn";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartData))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonUART_config_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort1->IsOpen)
		{
			serialPort1->DiscardInBuffer();
			serialPort1->DiscardOutBuffer();
			serialPort1->Close();
			buttonOpenCOM->Enabled = true;
			progressBar->Value = 0;
		}
		Pasirinkimu_langas^ configWindow = gcnew Pasirinkimu_langas(UART);
		configWindow->ShowDialog();

		this->labelInfo->Text = "";
	}
	private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
		if (serialPort1->IsOpen && Start_UART_flag)
		{
			//String^ bandom = serialPort1->ReadLine(); VEIKIA MUHAHA
			try {
				String^ incoming = serialPort1->ReadLine()->TrimStart(' ');  // Grab all available bytes until \r\s
				array<String^>^ Messages = incoming->Split(gcnew array<String^> {"\r\n"}, StringSplitOptions::RemoveEmptyEntries);
				for each(String ^ msg in Messages)
				{
					this->BeginInvoke(gcnew Action<String^>(this, &MyForm::ProcessUARTMessage), msg);
				}
				if (serialPort1->BytesToRead > 2048)
				{
					serialPort1->DiscardInBuffer();
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message, "Serial Error" + ex->Message);
			}
		}
	}
	private: void ProcessUARTMessage(String^ message)
	{

		   if (message->Contains("CH1-CH2")) {
			   ParseDifferenceData(message);
		   }
		   else if (message->Contains("CH1") || message->Contains("CH2")) {
			   ParseCHData(message);
		   }
		   else
		   {
			   Console::WriteLine("No packet found");
		   }
		   if (chartData->Series["CH1"]->Points->Count > 50 && chartData->Series["CH2"]->Points->Count > 50)
		   {
			   chartData->Series["CH1"]->Points->RemoveAt(0);  // Remove the first point (oldest)
			   chartData->Series["CH2"]->Points->RemoveAt(0);  // Remove the first point (oldest)
		   }
		   if (chartData->Series["Difference"]->Points->Count > 50)
		   {
			   chartData->Series["Difference"]->Points->RemoveAt(0);  // Remove the first point (oldest)
		   }
	 }
private: void ParseCHData(String^ Packet)
{
	//CH1 value = 12.34 at 12345 ms\r\nCH2 value = 56.78 at 12346 ms\r\n
	try
	{
		double LuxValue;
		float Time;
		int valuePos, atPos,msPos;

		valuePos = Packet->IndexOf(val);
		atPos = Packet->IndexOf(atVal);
		msPos = Packet->IndexOf(msVal);

		String^ valueString = Packet->Substring(valuePos + val->Length, atPos - (valuePos + val->Length));
		String^ timeString = Packet->Substring(atPos + atVal->Length, msPos-(atPos+atVal->Length));


		LuxValue = Convert::ToDouble(valueString); //lux
		Time = Convert::ToDouble(timeString); //ms
		if (Packet->Contains("CH1"))
		{
			chartData->Series["CH1"]->Points->AddXY(Time, LuxValue);
		}
		else if (Packet->Contains("CH2"))
		{
			chartData->Series["CH2"]->Points->AddXY(Time, LuxValue);
		}
		else
		{
			Console::WriteLine("Unknown UART (CH data) message: " + Packet);
		}
	}
	catch (Exception^ ex)
	{
		Console::WriteLine("Parsing error: " + ex->Message);
	}
}
private: void ParseDifferenceData(String^ Packet)
{
	//CH1-CH2 value = %1.2f at %d ms\r\n
	try
	{
		double Difference;
		float Time;
		int valuePos, atPos, msPos;

		valuePos = Packet->IndexOf(val);
		atPos = Packet->IndexOf(atVal);
		msPos = Packet->IndexOf(msVal);

		String^ valueString = Packet->Substring(valuePos + val->Length, atPos - (valuePos + val->Length));
		String^ timeString = Packet->Substring(atPos + atVal->Length, msPos - (atPos + atVal->Length));


		Difference = Convert::ToDouble(valueString); //lux
		Time = Convert::ToDouble(timeString); //ms

		if (Packet->Contains("CH1-CH2"))
		{
			chartData->Series["Difference"]->Points->AddXY(Time, Difference);
		}
		else
		{
			Console::WriteLine("Unknown UART (DIFF data) message: " + Packet);
		}
	}
	catch (Exception^ ex)
	{
		Console::WriteLine("Parsing error: " + ex->Message);
	}


}
private: System::Void buttonOpenCOM_Click(System::Object^ sender, System::EventArgs^ e) {
	progressBar->Value = 0;

	if (UART->PORT == nullptr|| UART->PORT == String::Empty || UART->BAUD_RATE ==0 || UART->DATA_LENGTH == 0)
		MessageBox::Show("Configure the COM port", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Stop);
	else
	{
		serialPort1->BaudRate = UART->BAUD_RATE;
		serialPort1->DataBits = UART->DATA_LENGTH;
		serialPort1->StopBits = UART->STOP_BIT;
		serialPort1->PortName = UART->PORT;
		serialPort1->ReadTimeout = 100;
		serialPort1->WriteTimeout = 100;

		if (!serialPort1->IsOpen)
		{
			try
			{
				serialPort1->Open();
				progressBar->Value = 1;
				buttonOpenCOM->Enabled = false;
			}
			catch (Exception^ ER)
			{
				MessageBox::Show(ER->Message + "Check COM port", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

		}
	}
}
private: System::Void buttonCloseCOM_Click(System::Object^ sender, System::EventArgs^ e) {
	if (serialPort1->IsOpen)
	{
		serialPort1->DiscardInBuffer();
		serialPort1->DiscardOutBuffer();
		serialPort1->Close();
		buttonOpenCOM->Enabled = true;
	}

	progressBar->Value = 0;
}
private: System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
	this->chartData->Series["CH1"]->Points->Clear();
	this->chartData->Series["CH2"]->Points->Clear();
	this->chartData->Series["Difference"]->Points->Clear();
}
private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Are you sure?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == Windows::Forms::DialogResult::Yes)
	{
		if (serialPort1->IsOpen)
		{
			serialPort1->DiscardInBuffer();
			serialPort1->DiscardOutBuffer();
			serialPort1->Close();
		}
		this->Close();
	}
}
private: System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e) {
	//SEND TO MCU TO START SENDING DATA
	if (serialPort1->IsOpen)
	{
		serialPort1->DiscardInBuffer();
		serialPort1->DiscardOutBuffer();
		if (!Start_UART_flag)
		{
			if (Send_UART_data("Start") != -1)
			{
				Start_UART_flag = true;
				chartData->Visible = true;
			}

		}
	}
	else MessageBox::Show("Port not opened", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Stop);

}
private: System::Void buttonStop_Click(System::Object^ sender, System::EventArgs^ e) {
	if (serialPort1->IsOpen)
	{
		if (Start_UART_flag)
		{
			if (Send_UART_data("Stop") != -1)
			{
			Start_UART_flag = false;
			}
		}
		serialPort1->DiscardInBuffer();
		serialPort1->DiscardOutBuffer();
	}
	else MessageBox::Show("Port not opened", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Stop);
}
private: System::Void buttonStore_Click(System::Object^ sender, System::EventArgs^ e) {
	bool opened_file = true;
	FILE* fptr;
	int x;
	const char file_name[] = "SavedFiles.csv";
	String^ testas = "Nepavyko atidaryti failo";
	String^ file_link = gcnew String(file_name);
	String^ VISAS = String::Concat("Duomenys patalpinti sekmingai faile ", file_link);

	opened_file = fopen_s(&fptr, file_name, "w");
	if (opened_file != 0)
	{
		System::Windows::Forms::MessageBox::Show(this, "Nepavyko atidaryti failo");
	}
	else
	{
		fprintf(fptr, "\"Time, ms\",\"CH1, lux\",\"CH2, lux\"\n");
		/*
		for (int i = 0; i < ApdorojimuiLastNumber; i++)
		{
			kuris = i * this->timerRezistorius->Interval / 1000;
			fprintf(fptr, "\"%-d\";\"%.2f\"\n", kuris, ApdorojimuiData[i]);
		}
		Windows::Forms::MessageBox::Show(this, VISAS, "Vaizduote", MessageBoxButtons::OK, MessageBoxIcon::Information);
		*/
		fclose(fptr);
	}
}
};
};

