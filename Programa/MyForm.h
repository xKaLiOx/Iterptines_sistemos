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
	private: const UINT16 Point_number = 60;
	private: const UINT16 Graph_shift_time = 10000; //in milliseccnds

	public: bool Start_UART_flag = false;
	private: double margin = 0.1;//10% margin for Y axis
	private: double maxy, miny;
	private: static initonly String^ val = "value = ";
	private: static initonly String^ atVal = " at ";
	private: static initonly String^ msVal = " ms";
	private: enum class GraphType{Difference, CHValues };
	private: GraphType CurrentGraph = GraphType::CHValues;
	private: GraphType PreviousGraph = GraphType::CHValues;
	private: bool GraphChangeFlag = false;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartData;
	private: System::Windows::Forms::Label^ labelmin;
	public:

	public:





	private: System::Windows::Forms::Label^ labelmax;


	private: System::Windows::Forms::Button^ buttonStart;

	private: System::Windows::Forms::Label^ labelInfo;
	private: System::Windows::Forms::Button^ buttonCloseCOM;
	private: System::Windows::Forms::ProgressBar^ progressBar;
	private: System::Windows::Forms::Button^ buttonOpenCOM;

	private: System::Windows::Forms::Label^ labelmaxval;
	private: System::Windows::Forms::Label^ labelminval;


	private: System::Windows::Forms::Button^ buttonReset;
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Button^ buttonStore;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label2CHmax;

	private: System::Windows::Forms::Label^ labelCH2min;




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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::LineAnnotation^ lineAnnotation1 = (gcnew System::Windows::Forms::DataVisualization::Charting::LineAnnotation());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->buttonUART_config = (gcnew System::Windows::Forms::Button());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chartData = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->labelmin = (gcnew System::Windows::Forms::Label());
			this->labelmax = (gcnew System::Windows::Forms::Label());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			this->labelInfo = (gcnew System::Windows::Forms::Label());
			this->buttonCloseCOM = (gcnew System::Windows::Forms::Button());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->buttonOpenCOM = (gcnew System::Windows::Forms::Button());
			this->labelmaxval = (gcnew System::Windows::Forms::Label());
			this->labelminval = (gcnew System::Windows::Forms::Label());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->buttonStore = (gcnew System::Windows::Forms::Button());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2CHmax = (gcnew System::Windows::Forms::Label());
			this->labelCH2min = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartData))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonUART_config
			// 
			this->buttonUART_config->Location = System::Drawing::Point(34, 37);
			this->buttonUART_config->Margin = System::Windows::Forms::Padding(2);
			this->buttonUART_config->Name = L"buttonUART_config";
			this->buttonUART_config->Size = System::Drawing::Size(136, 33);
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
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// timer1
			// 
			this->timer1->Interval = 200;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 64);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 2;
			// 
			// chartData
			// 
			lineAnnotation1->Name = L"LineAnnotation1";
			lineAnnotation1->Visible = false;
			this->chartData->Annotations->Add(lineAnnotation1);
			this->chartData->BackColor = System::Drawing::Color::Silver;
			this->chartData->BorderlineColor = System::Drawing::Color::Black;
			chartArea2->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea2->AxisX->LabelStyle->Angle = 90;
			chartArea2->AxisX->LabelStyle->Format = L"0";
			chartArea2->AxisX->LabelStyle->Interval = 0;
			chartArea2->AxisX->MajorGrid->Interval = 0;
			chartArea2->AxisX->MajorTickMark->Interval = 0;
			chartArea2->AxisX->MinorGrid->Enabled = true;
			chartArea2->AxisX->MinorGrid->Interval = 200;
			chartArea2->AxisX->MinorGrid->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea2->AxisX->MinorGrid->LineColor = System::Drawing::Color::DarkGray;
			chartArea2->AxisX->MinorTickMark->Enabled = true;
			chartArea2->AxisX->MinorTickMark->LineColor = System::Drawing::Color::DarkGray;
			chartArea2->AxisX->Title = L"Time, ms";
			chartArea2->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			chartArea2->AxisY->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea2->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea2->AxisY->IsLogarithmic = true;
			chartArea2->AxisY->IsStartedFromZero = false;
			chartArea2->AxisY->MajorGrid->Interval = 0;
			chartArea2->AxisY->Minimum = 1;
			chartArea2->AxisY->MinorGrid->Enabled = true;
			chartArea2->AxisY->MinorGrid->LineColor = System::Drawing::Color::DarkGray;
			chartArea2->AxisY->MinorTickMark->Enabled = true;
			chartArea2->AxisY->MinorTickMark->LineColor = System::Drawing::Color::DarkGray;
			chartArea2->AxisY->Title = L"Illuminance, lux";
			chartArea2->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			chartArea2->BackColor = System::Drawing::Color::White;
			chartArea2->CursorX->IsUserEnabled = true;
			chartArea2->CursorX->IsUserSelectionEnabled = true;
			chartArea2->CursorX->SelectionColor = System::Drawing::Color::IndianRed;
			chartArea2->CursorY->SelectionColor = System::Drawing::Color::IndianRed;
			chartArea2->Name = L"ChartArea1";
			chartArea3->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea3->AxisX->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea3->AxisX->IsStartedFromZero = false;
			chartArea3->AxisX->MinorGrid->LineColor = System::Drawing::Color::DimGray;
			chartArea3->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea3->AxisY->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea3->AxisY->IsStartedFromZero = false;
			chartArea3->AxisY->LabelStyle->Format = L"F1";
			chartArea3->AxisY->MajorGrid->Interval = 0;
			chartArea3->AxisY->MajorTickMark->Interval = 0;
			chartArea3->AxisY->MinorGrid->Enabled = true;
			chartArea3->AxisY->MinorGrid->LineColor = System::Drawing::Color::DimGray;
			chartArea3->BackColor = System::Drawing::Color::White;
			chartArea3->CursorX->IsUserEnabled = true;
			chartArea3->CursorX->IsUserSelectionEnabled = true;
			chartArea3->CursorX->SelectionColor = System::Drawing::Color::IndianRed;
			chartArea3->Name = L"ChartArea2";
			chartArea3->Visible = false;
			this->chartData->ChartAreas->Add(chartArea2);
			this->chartData->ChartAreas->Add(chartArea3);
			this->chartData->Cursor = System::Windows::Forms::Cursors::Cross;
			legend2->BorderColor = System::Drawing::Color::Red;
			legend2->DockedToChartArea = L"ChartArea1";
			legend2->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend2->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend2->Name = L"Legend1";
			legend3->BorderColor = System::Drawing::Color::Red;
			legend3->DockedToChartArea = L"ChartArea2";
			legend3->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend3->Enabled = false;
			legend3->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend3->Name = L"Legend2";
			this->chartData->Legends->Add(legend2);
			this->chartData->Legends->Add(legend3);
			this->chartData->Location = System::Drawing::Point(305, 10);
			this->chartData->Margin = System::Windows::Forms::Padding(2);
			this->chartData->Name = L"chartData";
			series2->BorderWidth = 4;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->MarkerColor = System::Drawing::Color::IndianRed;
			series2->Name = L"CH1";
			series3->BorderWidth = 4;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Legend = L"Legend1";
			series3->MarkerColor = System::Drawing::Color::Black;
			series3->Name = L"CH2";
			series4->BorderWidth = 4;
			series4->ChartArea = L"ChartArea2";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Legend = L"Legend2";
			series4->Name = L"Difference";
			series4->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			this->chartData->Series->Add(series2);
			this->chartData->Series->Add(series3);
			this->chartData->Series->Add(series4);
			this->chartData->Size = System::Drawing::Size(468, 405);
			this->chartData->TabIndex = 7;
			this->chartData->Text = L"Luminance";
			title1->Name = L"Title1";
			title1->Visible = false;
			this->chartData->Titles->Add(title1);
			this->chartData->Visible = false;
			// 
			// labelmin
			// 
			this->labelmin->AutoSize = true;
			this->labelmin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelmin->Location = System::Drawing::Point(42, 205);
			this->labelmin->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelmin->Name = L"labelmin";
			this->labelmin->Size = System::Drawing::Size(38, 20);
			this->labelmin->TabIndex = 9;
			this->labelmin->Text = L"MIN";
			this->labelmin->Visible = false;
			// 
			// labelmax
			// 
			this->labelmax->AutoSize = true;
			this->labelmax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelmax->Location = System::Drawing::Point(180, 205);
			this->labelmax->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelmax->Name = L"labelmax";
			this->labelmax->Size = System::Drawing::Size(44, 20);
			this->labelmax->TabIndex = 10;
			this->labelmax->Text = L"MAX";
			this->labelmax->Visible = false;
			// 
			// buttonStart
			// 
			this->buttonStart->Location = System::Drawing::Point(202, 37);
			this->buttonStart->Margin = System::Windows::Forms::Padding(2);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(80, 32);
			this->buttonStart->TabIndex = 12;
			this->buttonStart->Text = L"Start";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &MyForm::buttonStart_Click);
			// 
			// buttonStop
			// 
			this->buttonStop->Location = System::Drawing::Point(202, 73);
			this->buttonStop->Margin = System::Windows::Forms::Padding(2);
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->Size = System::Drawing::Size(80, 32);
			this->buttonStop->TabIndex = 13;
			this->buttonStop->Text = L"Stop";
			this->buttonStop->UseVisualStyleBackColor = true;
			this->buttonStop->Click += gcnew System::EventHandler(this, &MyForm::buttonStop_Click);
			// 
			// labelInfo
			// 
			this->labelInfo->AutoSize = true;
			this->labelInfo->Location = System::Drawing::Point(32, 87);
			this->labelInfo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelInfo->Name = L"labelInfo";
			this->labelInfo->Size = System::Drawing::Size(0, 13);
			this->labelInfo->TabIndex = 14;
			// 
			// buttonCloseCOM
			// 
			this->buttonCloseCOM->Location = System::Drawing::Point(34, 119);
			this->buttonCloseCOM->Margin = System::Windows::Forms::Padding(2);
			this->buttonCloseCOM->Name = L"buttonCloseCOM";
			this->buttonCloseCOM->Size = System::Drawing::Size(136, 29);
			this->buttonCloseCOM->TabIndex = 17;
			this->buttonCloseCOM->Text = L"Close port";
			this->buttonCloseCOM->UseVisualStyleBackColor = true;
			this->buttonCloseCOM->Click += gcnew System::EventHandler(this, &MyForm::buttonCloseCOM_Click);
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(34, 153);
			this->progressBar->Margin = System::Windows::Forms::Padding(2);
			this->progressBar->Maximum = 1;
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(136, 19);
			this->progressBar->Step = 1;
			this->progressBar->TabIndex = 16;
			// 
			// buttonOpenCOM
			// 
			this->buttonOpenCOM->Location = System::Drawing::Point(34, 84);
			this->buttonOpenCOM->Margin = System::Windows::Forms::Padding(2);
			this->buttonOpenCOM->Name = L"buttonOpenCOM";
			this->buttonOpenCOM->Size = System::Drawing::Size(136, 29);
			this->buttonOpenCOM->TabIndex = 15;
			this->buttonOpenCOM->Text = L"Open port";
			this->buttonOpenCOM->UseVisualStyleBackColor = true;
			this->buttonOpenCOM->Click += gcnew System::EventHandler(this, &MyForm::buttonOpenCOM_Click);
			// 
			// labelmaxval
			// 
			this->labelmaxval->AutoSize = true;
			this->labelmaxval->Location = System::Drawing::Point(172, 247);
			this->labelmaxval->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelmaxval->Name = L"labelmaxval";
			this->labelmaxval->Padding = System::Windows::Forms::Padding(30, 16, 30, 16);
			this->labelmaxval->Size = System::Drawing::Size(60, 45);
			this->labelmaxval->TabIndex = 19;
			// 
			// labelminval
			// 
			this->labelminval->AutoSize = true;
			this->labelminval->Location = System::Drawing::Point(31, 247);
			this->labelminval->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelminval->Name = L"labelminval";
			this->labelminval->Padding = System::Windows::Forms::Padding(30, 16, 30, 16);
			this->labelminval->Size = System::Drawing::Size(60, 45);
			this->labelminval->TabIndex = 18;
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(202, 153);
			this->buttonReset->Margin = System::Windows::Forms::Padding(2);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(80, 24);
			this->buttonReset->TabIndex = 21;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &MyForm::buttonReset_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->ForeColor = System::Drawing::Color::Red;
			this->buttonExit->Location = System::Drawing::Point(202, 393);
			this->buttonExit->Margin = System::Windows::Forms::Padding(2);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(80, 22);
			this->buttonExit->TabIndex = 22;
			this->buttonExit->Text = L"Exit";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm::buttonExit_Click);
			// 
			// buttonStore
			// 
			this->buttonStore->Location = System::Drawing::Point(34, 393);
			this->buttonStore->Margin = System::Windows::Forms::Padding(2);
			this->buttonStore->Name = L"buttonStore";
			this->buttonStore->Size = System::Drawing::Size(136, 22);
			this->buttonStore->TabIndex = 23;
			this->buttonStore->Text = L"Store";
			this->buttonStore->UseVisualStyleBackColor = true;
			this->buttonStore->Click += gcnew System::EventHandler(this, &MyForm::buttonStore_Click);
			// 
			// label2CHmax
			// 
			this->label2CHmax->AutoSize = true;
			this->label2CHmax->Location = System::Drawing::Point(172, 314);
			this->label2CHmax->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2CHmax->Name = L"label2CHmax";
			this->label2CHmax->Padding = System::Windows::Forms::Padding(30, 16, 30, 16);
			this->label2CHmax->Size = System::Drawing::Size(60, 45);
			this->label2CHmax->TabIndex = 25;
			this->label2CHmax->Visible = false;
			// 
			// labelCH2min
			// 
			this->labelCH2min->AutoSize = true;
			this->labelCH2min->Location = System::Drawing::Point(31, 314);
			this->labelCH2min->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelCH2min->Name = L"labelCH2min";
			this->labelCH2min->Padding = System::Windows::Forms::Padding(30, 16, 30, 16);
			this->labelCH2min->Size = System::Drawing::Size(60, 45);
			this->labelCH2min->TabIndex = 24;
			this->labelCH2min->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 425);
			this->Controls->Add(this->label2CHmax);
			this->Controls->Add(this->labelCH2min);
			this->Controls->Add(this->buttonStore);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->labelmaxval);
			this->Controls->Add(this->labelminval);
			this->Controls->Add(this->buttonCloseCOM);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->buttonOpenCOM);
			this->Controls->Add(this->labelInfo);
			this->Controls->Add(this->buttonStop);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->labelmax);
			this->Controls->Add(this->labelmin);
			this->Controls->Add(this->chartData);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonUART_config);
			this->Margin = System::Windows::Forms::Padding(2);
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
		}
		buttonOpenCOM->Enabled = true;
		progressBar->Value = 0;
		Pasirinkimu_langas^ configWindow = gcnew Pasirinkimu_langas(UART);
		configWindow->ShowDialog();
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
			   if (CurrentGraph == GraphType::CHValues)
			   {
				   ChangeGraphType(GraphType::Difference);
				   CurrentGraph = GraphType::Difference;
			   }
		   }
		   else if (message->Contains("CH1") || message->Contains("CH2")) {
			   ParseCHData(message);
			   if (CurrentGraph == GraphType::Difference)
			   {
				   ChangeGraphType(GraphType::CHValues);
				   CurrentGraph = GraphType::CHValues;
			   }
		   }
		   else
		   {
			   Console::WriteLine("No packet found");
		   }
		   if (CurrentGraph == GraphType::CHValues)
		   {
		   if (chartData->Series["CH1"]->Points->Count > Point_number && chartData->Series["CH2"]->Points->Count > Point_number)
		   {
			   chartData->Series["CH1"]->Points->RemoveAt(0);  // Remove the first point (oldest)
			   chartData->Series["CH2"]->Points->RemoveAt(0);  // Remove the first point (oldest)
			}
		   int pointCount = chartData->Series["CH1"]->Points->Count;
		   if (pointCount > 0)
		   {
			   double lastX = chartData->Series["CH1"]->Points[pointCount - 1]->XValue;

			   chartData->ChartAreas["ChartArea1"]->AxisX->Minimum = lastX - Graph_shift_time; // or use milliseconds window
			   chartData->ChartAreas["ChartArea1"]->AxisX->Maximum = lastX;
		   }
		   }

		   if (CurrentGraph == GraphType::Difference)
		   {
			   maxy = chartData->Series["Difference"]->Points->FindMaxByValue()->YValues[0];
			   miny = chartData->Series["Difference"]->Points->FindMinByValue()->YValues[0];

			   if (maxy != miny)
			   {
				   chartData->ChartAreas["ChartArea2"]->AxisY->Minimum = miny+ margin*miny;
				   chartData->ChartAreas["ChartArea2"]->AxisY->Maximum = maxy+margin*maxy;
			   }
		   if (chartData->Series["Difference"]->Points->Count > Point_number)
		   {
			   chartData->Series["Difference"]->Points->RemoveAt(0);  // Remove the first point (oldest)
			   chartData->Invalidate();
		   }
		   int pointCount = chartData->Series["Difference"]->Points->Count;
		   if (pointCount > 0)
		   {
			   double lastX = chartData->Series["Difference"]->Points[pointCount - 1]->XValue;

			   chartData->ChartAreas["ChartArea2"]->AxisX->Minimum = lastX - Graph_shift_time; // or use milliseconds window
			   chartData->ChartAreas["ChartArea2"]->AxisX->Maximum = lastX;
		   }
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

	this->labelmin->Visible = false;
	this->labelmax->Visible = false;
	this->labelmaxval->Visible = false;
	this->labelminval->Visible = false;
	this->labelCH2min->Visible = false;
	this->label2CHmax->Visible = false;

	if (serialPort1->IsOpen)
	{
		try
		{
			serialPort1->DiscardInBuffer();
			serialPort1->DiscardOutBuffer();
			serialPort1->Close();
			buttonOpenCOM->Enabled = true;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message + "IO warning", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	progressBar->Value = 0;
}
private: System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
	chartData->SuspendLayout();

	this->labelminval->Text = " ";
	this->labelmaxval->Text = " ";
	this->labelCH2min->Text = " ";
	this->label2CHmax->Text = " ";

	if (CurrentGraph == GraphType::CHValues)
	{
		this->chartData->Series["CH1"]->Points->Clear();
		this->chartData->Series["CH2"]->Points->Clear();
	}
	else
	{
		this->chartData->Series["Difference"]->Points->Clear();
	}
	chartData->ResumeLayout();
	chartData->Refresh();

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
				this->labelmin->Visible = true;
				this->labelmax->Visible = true;
				this->labelmaxval->Visible = true;
				this->labelminval->Visible = true;
				if (CurrentGraph == GraphType::CHValues)
				{
				this->labelCH2min->Visible = true;
				this->label2CHmax->Visible = true;
				}

				this->timer1->Enabled = true;
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

			this->timer1->Enabled = false;
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
	String^ file_error = "Couldn't open the file";
	String^ file_link = gcnew String(file_name);
	String^ Formatted_string = String::Concat("Data was succesfully exported ", file_link);

	opened_file = fopen_s(&fptr, file_name, "w");
	if (opened_file != 0)
	{
		System::Windows::Forms::MessageBox::Show(this, file_error,"Error");
	}
	else
	{
		if (CurrentGraph == GraphType::CHValues)
		{
			fprintf(fptr, "\"Time, ms\",\"CH1, lux\",\"CH2, lux\"\n");
			for (int i = 0; i < this->chartData->Series["CH1"]->Points->Count; i++)
			{
				fprintf(fptr, "\"%.0f\",\"%.1f\",\"%.1f\"\n", this->chartData->Series["CH1"]->Points[i]->XValue, this->chartData->Series["CH1"]->Points[i]->YValues[0], this->chartData->Series["CH2"]->Points[i]->YValues[0]);
			}
			Windows::Forms::MessageBox::Show(this, Formatted_string, "SUCCESS", MessageBoxButtons::OK, MessageBoxIcon::Information);

			fclose(fptr);
		}
		else
		{
			fprintf(fptr, "\"Time, ms\",\"CH1-CH2, lux\"\n");
			for (int i = 0; i < this->chartData->Series["Difference"]->Points->Count; i++)
			{
				fprintf(fptr, "\"%.0f\",\"%.1f\"\n", this->chartData->Series["Difference"]->Points[i]->XValue, this->chartData->Series["Difference"]->Points[i]->YValues[0]);
			}
			Windows::Forms::MessageBox::Show(this, Formatted_string, "SUCCESS", MessageBoxButtons::OK, MessageBoxIcon::Information);

			fclose(fptr);
		}

	}
}
		private: void ChangeGraphType(GraphType CurrentGraphType)
		{
			chartData->SuspendLayout();
			if (CurrentGraph == GraphType::CHValues)
			{
				this->chartData->Series["CH1"]->Points->Clear();
				this->chartData->Series["CH2"]->Points->Clear();
			}
			else
			{
				this->chartData->Series["Difference"]->Points->Clear();
			}
			if (CurrentGraphType == GraphType::CHValues)
			{
				chartData->ChartAreas["ChartArea1"]->Visible = true;
				chartData->ChartAreas["ChartArea2"]->Visible = false;
				chartData->Legends["Legend2"]->Enabled = false;
				chartData->Legends["Legend1"]->Enabled = true;
			}
			else if (CurrentGraphType == GraphType::Difference)
			{
				chartData->Legends["Legend2"]->Enabled = true;
				chartData->Legends["Legend1"]->Enabled = false;
				chartData->ChartAreas["ChartArea1"]->Visible = false;
				chartData->ChartAreas["ChartArea2"]->Visible = true;
				chartData->ChartAreas["ChartArea2"]->AxisY->Minimum = Double::NaN;  // Auto
				chartData->ChartAreas["ChartArea2"]->AxisY->Maximum = Double::NaN;  // Auto
				chartData->ChartAreas["ChartArea2"]->AxisY->IsLogarithmic = false; // Ensure linear scale
			}
			chartData->ResumeLayout();
			chartData->Refresh();
		}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (CurrentGraph == GraphType::Difference && this->chartData->Series["Difference"]->Points->Count > 0)
	{
		this->labelCH2min->Visible = false;
		this->label2CHmax->Visible = false;
		this->labelminval->Text = Convert::ToString(this->chartData->Series["Difference"]->Points->FindMinByValue()->YValues[0]);
		this->labelmaxval->Text = Convert::ToString(this->chartData->Series["Difference"]->Points->FindMaxByValue()->YValues[0]);

	}
	else if (CurrentGraph == GraphType::CHValues && this->chartData->Series["CH1"]->Points->Count > 0 && this->chartData->Series["CH2"]->Points->Count > 0)
	{
		this->labelCH2min->Visible = true;
		this->label2CHmax->Visible = true;
		this->labelminval->Text = Convert::ToString(this->chartData->Series["CH1"]->Points->FindMinByValue()->YValues[0]);
		this->labelmaxval->Text = Convert::ToString(this->chartData->Series["CH1"]->Points->FindMaxByValue()->YValues[0]);

		this->labelCH2min->Text = Convert::ToString(this->chartData->Series["CH2"]->Points->FindMinByValue()->YValues[0]);;
		this->label2CHmax->Text = Convert::ToString(this->chartData->Series["CH2"]->Points->FindMaxByValue()->YValues[0]);;
	}
}
};
};

