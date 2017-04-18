#pragma once

//Global Variables
int iteration_glob;
Map m;
parametrs p;
int i,best;
time_t start;
double seconds_since_start;

namespace AntColonyOptimizationTSP {

	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Form1
	/// </summary>

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  title_label;
	private: System::Windows::Forms::PictureBox^  logo_picbox;
	private: System::Windows::Forms::Button^  about_button;
	private: System::Windows::Forms::GroupBox^  TspSettings_gbox;
	private: System::Windows::Forms::NumericUpDown^  numcity_numdown;
	private: System::Windows::Forms::Label^  numCities_label;
	private: System::Windows::Forms::Label^  minValue_label;
	private: System::Windows::Forms::NumericUpDown^  max_numdown;
	private: System::Windows::Forms::Label^  maxValue_label;

	private: System::Windows::Forms::NumericUpDown^  min_numdown;
	private: System::Windows::Forms::Label^  FileName_label;

	private: System::Windows::Forms::TextBox^  FileName_txt;
	private: System::Windows::Forms::Button^  showFile_button;

	private: System::Windows::Forms::Button^  generateRamdom_button;

	private: System::Windows::Forms::GroupBox^  acoSetting_gbox;
	private: System::Windows::Forms::Label^  numOfAnts_label;
	private: System::Windows::Forms::NumericUpDown^  numOfAnts_numdown;
	private: System::Windows::Forms::Label^  alpha_label;
	private: System::Windows::Forms::TextBox^  alpha_txtbox;

	private: System::Windows::Forms::Label^  beta_label;
	private: System::Windows::Forms::TextBox^  beta_txtbox;

	private: System::Windows::Forms::Label^  eFactor_label;
	private: System::Windows::Forms::TextBox^  eFacor_txtbox;



	private: System::Windows::Forms::Label^  numOfIteration_label;
	private: System::Windows::Forms::NumericUpDown^  numOfIteration_numdown;
	private: System::Windows::Forms::Button^  showTsp_button;

	private: System::Windows::Forms::Button^  start_button;
	private: System::Windows::Forms::ProgressBar^  progressBar;
	private: System::Windows::Forms::GroupBox^  statistics_gbox;
	private: System::Windows::Forms::Label^  timeValue_label;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  bestTspValue_label;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  iterValue_label;
	private: System::Windows::Forms::Label^  iter_label;
	private: System::Windows::Forms::Label^  idle_label;












	protected: 



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->logo_picbox = (gcnew System::Windows::Forms::PictureBox());
			this->about_button = (gcnew System::Windows::Forms::Button());
			this->TspSettings_gbox = (gcnew System::Windows::Forms::GroupBox());
			this->showFile_button = (gcnew System::Windows::Forms::Button());
			this->generateRamdom_button = (gcnew System::Windows::Forms::Button());
			this->FileName_label = (gcnew System::Windows::Forms::Label());
			this->FileName_txt = (gcnew System::Windows::Forms::TextBox());
			this->max_numdown = (gcnew System::Windows::Forms::NumericUpDown());
			this->maxValue_label = (gcnew System::Windows::Forms::Label());
			this->min_numdown = (gcnew System::Windows::Forms::NumericUpDown());
			this->minValue_label = (gcnew System::Windows::Forms::Label());
			this->numCities_label = (gcnew System::Windows::Forms::Label());
			this->numcity_numdown = (gcnew System::Windows::Forms::NumericUpDown());
			this->acoSetting_gbox = (gcnew System::Windows::Forms::GroupBox());
			this->showTsp_button = (gcnew System::Windows::Forms::Button());
			this->start_button = (gcnew System::Windows::Forms::Button());
			this->numOfIteration_label = (gcnew System::Windows::Forms::Label());
			this->numOfIteration_numdown = (gcnew System::Windows::Forms::NumericUpDown());
			this->eFactor_label = (gcnew System::Windows::Forms::Label());
			this->eFacor_txtbox = (gcnew System::Windows::Forms::TextBox());
			this->beta_label = (gcnew System::Windows::Forms::Label());
			this->beta_txtbox = (gcnew System::Windows::Forms::TextBox());
			this->alpha_label = (gcnew System::Windows::Forms::Label());
			this->alpha_txtbox = (gcnew System::Windows::Forms::TextBox());
			this->numOfAnts_label = (gcnew System::Windows::Forms::Label());
			this->numOfAnts_numdown = (gcnew System::Windows::Forms::NumericUpDown());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->statistics_gbox = (gcnew System::Windows::Forms::GroupBox());
			this->idle_label = (gcnew System::Windows::Forms::Label());
			this->timeValue_label = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->bestTspValue_label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->iterValue_label = (gcnew System::Windows::Forms::Label());
			this->iter_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logo_picbox))->BeginInit();
			this->TspSettings_gbox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->max_numdown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->min_numdown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numcity_numdown))->BeginInit();
			this->acoSetting_gbox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numOfIteration_numdown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numOfAnts_numdown))->BeginInit();
			this->statistics_gbox->SuspendLayout();
			this->SuspendLayout();
			// 
			// title_label
			// 
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->title_label->Location = System::Drawing::Point(191, 22);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(310, 26);
			this->title_label->TabIndex = 0;
			this->title_label->Text = L"Ant Colony Optimization - TSP v1.0";
			// 
			// logo_picbox
			// 
			this->logo_picbox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"logo_picbox.Image")));
			this->logo_picbox->Location = System::Drawing::Point(12, 29);
			this->logo_picbox->Name = L"logo_picbox";
			this->logo_picbox->Size = System::Drawing::Size(173, 262);
			this->logo_picbox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->logo_picbox->TabIndex = 1;
			this->logo_picbox->TabStop = false;
			// 
			// about_button
			// 
			this->about_button->Location = System::Drawing::Point(521, 22);
			this->about_button->Name = L"about_button";
			this->about_button->Size = System::Drawing::Size(78, 26);
			this->about_button->TabIndex = 2;
			this->about_button->Text = L"About";
			this->about_button->UseVisualStyleBackColor = true;
			this->about_button->Click += gcnew System::EventHandler(this, &Form1::about_button_Click);
			// 
			// TspSettings_gbox
			// 
			this->TspSettings_gbox->Controls->Add(this->showFile_button);
			this->TspSettings_gbox->Controls->Add(this->generateRamdom_button);
			this->TspSettings_gbox->Controls->Add(this->FileName_label);
			this->TspSettings_gbox->Controls->Add(this->FileName_txt);
			this->TspSettings_gbox->Controls->Add(this->max_numdown);
			this->TspSettings_gbox->Controls->Add(this->maxValue_label);
			this->TspSettings_gbox->Controls->Add(this->min_numdown);
			this->TspSettings_gbox->Controls->Add(this->minValue_label);
			this->TspSettings_gbox->Controls->Add(this->numCities_label);
			this->TspSettings_gbox->Controls->Add(this->numcity_numdown);
			this->TspSettings_gbox->Location = System::Drawing::Point(196, 67);
			this->TspSettings_gbox->Name = L"TspSettings_gbox";
			this->TspSettings_gbox->Size = System::Drawing::Size(431, 101);
			this->TspSettings_gbox->TabIndex = 4;
			this->TspSettings_gbox->TabStop = false;
			this->TspSettings_gbox->Text = L"TSP Settings";
			// 
			// showFile_button
			// 
			this->showFile_button->Enabled = false;
			this->showFile_button->Location = System::Drawing::Point(320, 58);
			this->showFile_button->Name = L"showFile_button";
			this->showFile_button->Size = System::Drawing::Size(78, 26);
			this->showFile_button->TabIndex = 9;
			this->showFile_button->Text = L"Show File";
			this->showFile_button->UseVisualStyleBackColor = true;
			this->showFile_button->Click += gcnew System::EventHandler(this, &Form1::showFile_button_Click);
			// 
			// generateRamdom_button
			// 
			this->generateRamdom_button->Location = System::Drawing::Point(296, 23);
			this->generateRamdom_button->Name = L"generateRamdom_button";
			this->generateRamdom_button->Size = System::Drawing::Size(122, 26);
			this->generateRamdom_button->TabIndex = 8;
			this->generateRamdom_button->Text = L"Generate Random File";
			this->generateRamdom_button->UseVisualStyleBackColor = true;
			this->generateRamdom_button->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// FileName_label
			// 
			this->FileName_label->AutoSize = true;
			this->FileName_label->Location = System::Drawing::Point(143, 30);
			this->FileName_label->Name = L"FileName_label";
			this->FileName_label->Size = System::Drawing::Size(54, 13);
			this->FileName_label->TabIndex = 7;
			this->FileName_label->Text = L"File Name";
			// 
			// FileName_txt
			// 
			this->FileName_txt->Location = System::Drawing::Point(206, 27);
			this->FileName_txt->MaxLength = 20;
			this->FileName_txt->Name = L"FileName_txt";
			this->FileName_txt->Size = System::Drawing::Size(68, 20);
			this->FileName_txt->TabIndex = 6;
			this->FileName_txt->Text = L"file.txt";
			this->FileName_txt->TextChanged += gcnew System::EventHandler(this, &Form1::FileName_txt_TextChanged);
			// 
			// max_numdown
			// 
			this->max_numdown->Location = System::Drawing::Point(206, 62);
			this->max_numdown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->max_numdown->Name = L"max_numdown";
			this->max_numdown->Size = System::Drawing::Size(41, 20);
			this->max_numdown->TabIndex = 5;
			this->max_numdown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			// 
			// maxValue_label
			// 
			this->maxValue_label->AutoSize = true;
			this->maxValue_label->Location = System::Drawing::Point(143, 64);
			this->maxValue_label->Name = L"maxValue_label";
			this->maxValue_label->Size = System::Drawing::Size(57, 13);
			this->maxValue_label->TabIndex = 4;
			this->maxValue_label->Text = L"Max Value";
			// 
			// min_numdown
			// 
			this->min_numdown->Location = System::Drawing::Point(73, 62);
			this->min_numdown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {400, 0, 0, 0});
			this->min_numdown->Name = L"min_numdown";
			this->min_numdown->Size = System::Drawing::Size(41, 20);
			this->min_numdown->TabIndex = 3;
			// 
			// minValue_label
			// 
			this->minValue_label->AutoSize = true;
			this->minValue_label->Location = System::Drawing::Point(14, 65);
			this->minValue_label->Name = L"minValue_label";
			this->minValue_label->Size = System::Drawing::Size(54, 13);
			this->minValue_label->TabIndex = 2;
			this->minValue_label->Text = L"Min Value";
			// 
			// numCities_label
			// 
			this->numCities_label->AutoSize = true;
			this->numCities_label->Location = System::Drawing::Point(14, 30);
			this->numCities_label->Name = L"numCities_label";
			this->numCities_label->Size = System::Drawing::Size(42, 13);
			this->numCities_label->TabIndex = 1;
			this->numCities_label->Text = L"# Cities";
			// 
			// numcity_numdown
			// 
			this->numcity_numdown->Location = System::Drawing::Point(73, 28);
			this->numcity_numdown->Name = L"numcity_numdown";
			this->numcity_numdown->Size = System::Drawing::Size(41, 20);
			this->numcity_numdown->TabIndex = 0;
			this->numcity_numdown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			// 
			// acoSetting_gbox
			// 
			this->acoSetting_gbox->Controls->Add(this->showTsp_button);
			this->acoSetting_gbox->Controls->Add(this->start_button);
			this->acoSetting_gbox->Controls->Add(this->numOfIteration_label);
			this->acoSetting_gbox->Controls->Add(this->numOfIteration_numdown);
			this->acoSetting_gbox->Controls->Add(this->eFactor_label);
			this->acoSetting_gbox->Controls->Add(this->eFacor_txtbox);
			this->acoSetting_gbox->Controls->Add(this->beta_label);
			this->acoSetting_gbox->Controls->Add(this->beta_txtbox);
			this->acoSetting_gbox->Controls->Add(this->alpha_label);
			this->acoSetting_gbox->Controls->Add(this->alpha_txtbox);
			this->acoSetting_gbox->Controls->Add(this->numOfAnts_label);
			this->acoSetting_gbox->Controls->Add(this->numOfAnts_numdown);
			this->acoSetting_gbox->Location = System::Drawing::Point(197, 182);
			this->acoSetting_gbox->Name = L"acoSetting_gbox";
			this->acoSetting_gbox->Size = System::Drawing::Size(429, 111);
			this->acoSetting_gbox->TabIndex = 5;
			this->acoSetting_gbox->TabStop = false;
			this->acoSetting_gbox->Text = L"ACO Settings";
			// 
			// showTsp_button
			// 
			this->showTsp_button->ForeColor = System::Drawing::Color::Black;
			this->showTsp_button->Location = System::Drawing::Point(350, 66);
			this->showTsp_button->Name = L"showTsp_button";
			this->showTsp_button->Size = System::Drawing::Size(70, 26);
			this->showTsp_button->TabIndex = 17;
			this->showTsp_button->Text = L"Show TSP";
			this->showTsp_button->UseVisualStyleBackColor = true;
			this->showTsp_button->Click += gcnew System::EventHandler(this, &Form1::showTsp_button_Click);
			// 
			// start_button
			// 
			this->start_button->ForeColor = System::Drawing::Color::Green;
			this->start_button->Location = System::Drawing::Point(277, 66);
			this->start_button->Name = L"start_button";
			this->start_button->Size = System::Drawing::Size(68, 26);
			this->start_button->TabIndex = 16;
			this->start_button->Text = L"Start";
			this->start_button->UseVisualStyleBackColor = true;
			this->start_button->Click += gcnew System::EventHandler(this, &Form1::start_button_Click);
			// 
			// numOfIteration_label
			// 
			this->numOfIteration_label->AutoSize = true;
			this->numOfIteration_label->Location = System::Drawing::Point(293, 35);
			this->numOfIteration_label->Name = L"numOfIteration_label";
			this->numOfIteration_label->Size = System::Drawing::Size(55, 13);
			this->numOfIteration_label->TabIndex = 15;
			this->numOfIteration_label->Text = L"# Iteration";
			// 
			// numOfIteration_numdown
			// 
			this->numOfIteration_numdown->Location = System::Drawing::Point(361, 31);
			this->numOfIteration_numdown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
			this->numOfIteration_numdown->Name = L"numOfIteration_numdown";
			this->numOfIteration_numdown->Size = System::Drawing::Size(52, 20);
			this->numOfIteration_numdown->TabIndex = 14;
			this->numOfIteration_numdown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			// 
			// eFactor_label
			// 
			this->eFactor_label->AutoSize = true;
			this->eFactor_label->Location = System::Drawing::Point(14, 72);
			this->eFactor_label->Name = L"eFactor_label";
			this->eFactor_label->Size = System::Drawing::Size(56, 13);
			this->eFactor_label->TabIndex = 13;
			this->eFactor_label->Text = L"Evaporate";
			// 
			// eFacor_txtbox
			// 
			this->eFacor_txtbox->Location = System::Drawing::Point(80, 69);
			this->eFacor_txtbox->MaxLength = 20;
			this->eFacor_txtbox->Name = L"eFacor_txtbox";
			this->eFacor_txtbox->Size = System::Drawing::Size(49, 20);
			this->eFacor_txtbox->TabIndex = 12;
			this->eFacor_txtbox->Text = L"0.9";
			// 
			// beta_label
			// 
			this->beta_label->AutoSize = true;
			this->beta_label->Location = System::Drawing::Point(157, 73);
			this->beta_label->Name = L"beta_label";
			this->beta_label->Size = System::Drawing::Size(29, 13);
			this->beta_label->TabIndex = 11;
			this->beta_label->Text = L"Beta";
			// 
			// beta_txtbox
			// 
			this->beta_txtbox->Location = System::Drawing::Point(209, 69);
			this->beta_txtbox->MaxLength = 3;
			this->beta_txtbox->Name = L"beta_txtbox";
			this->beta_txtbox->Size = System::Drawing::Size(52, 20);
			this->beta_txtbox->TabIndex = 10;
			this->beta_txtbox->Text = L"3";
			// 
			// alpha_label
			// 
			this->alpha_label->AutoSize = true;
			this->alpha_label->Location = System::Drawing::Point(156, 34);
			this->alpha_label->Name = L"alpha_label";
			this->alpha_label->Size = System::Drawing::Size(34, 13);
			this->alpha_label->TabIndex = 9;
			this->alpha_label->Text = L"Alpha";
			// 
			// alpha_txtbox
			// 
			this->alpha_txtbox->Location = System::Drawing::Point(209, 31);
			this->alpha_txtbox->MaxLength = 3;
			this->alpha_txtbox->Name = L"alpha_txtbox";
			this->alpha_txtbox->Size = System::Drawing::Size(52, 20);
			this->alpha_txtbox->TabIndex = 8;
			this->alpha_txtbox->Text = L"2.8";
			// 
			// numOfAnts_label
			// 
			this->numOfAnts_label->AutoSize = true;
			this->numOfAnts_label->Location = System::Drawing::Point(20, 36);
			this->numOfAnts_label->Name = L"numOfAnts_label";
			this->numOfAnts_label->Size = System::Drawing::Size(38, 13);
			this->numOfAnts_label->TabIndex = 3;
			this->numOfAnts_label->Text = L"# Ants";
			// 
			// numOfAnts_numdown
			// 
			this->numOfAnts_numdown->Location = System::Drawing::Point(80, 31);
			this->numOfAnts_numdown->Name = L"numOfAnts_numdown";
			this->numOfAnts_numdown->Size = System::Drawing::Size(41, 20);
			this->numOfAnts_numdown->TabIndex = 2;
			this->numOfAnts_numdown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(6, 15);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(336, 23);
			this->progressBar->TabIndex = 6;
			// 
			// statistics_gbox
			// 
			this->statistics_gbox->Controls->Add(this->idle_label);
			this->statistics_gbox->Controls->Add(this->timeValue_label);
			this->statistics_gbox->Controls->Add(this->label4);
			this->statistics_gbox->Controls->Add(this->bestTspValue_label);
			this->statistics_gbox->Controls->Add(this->label2);
			this->statistics_gbox->Controls->Add(this->iterValue_label);
			this->statistics_gbox->Controls->Add(this->iter_label);
			this->statistics_gbox->Controls->Add(this->progressBar);
			this->statistics_gbox->Location = System::Drawing::Point(12, 301);
			this->statistics_gbox->Name = L"statistics_gbox";
			this->statistics_gbox->Size = System::Drawing::Size(612, 45);
			this->statistics_gbox->TabIndex = 6;
			this->statistics_gbox->TabStop = false;
			this->statistics_gbox->Text = L"Statistics";
			// 
			// idle_label
			// 
			this->idle_label->AutoSize = true;
			this->idle_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->idle_label->Location = System::Drawing::Point(353, 20);
			this->idle_label->Name = L"idle_label";
			this->idle_label->Size = System::Drawing::Size(28, 13);
			this->idle_label->TabIndex = 13;
			this->idle_label->Text = L"Idle";
			// 
			// timeValue_label
			// 
			this->timeValue_label->AutoSize = true;
			this->timeValue_label->Location = System::Drawing::Point(588, 20);
			this->timeValue_label->Name = L"timeValue_label";
			this->timeValue_label->Size = System::Drawing::Size(13, 13);
			this->timeValue_label->TabIndex = 12;
			this->timeValue_label->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(543, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Time(s):";
			// 
			// bestTspValue_label
			// 
			this->bestTspValue_label->AutoSize = true;
			this->bestTspValue_label->Location = System::Drawing::Point(510, 20);
			this->bestTspValue_label->Name = L"bestTspValue_label";
			this->bestTspValue_label->Size = System::Drawing::Size(13, 13);
			this->bestTspValue_label->TabIndex = 10;
			this->bestTspValue_label->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(457, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Best Tsp:";
			// 
			// iterValue_label
			// 
			this->iterValue_label->AutoSize = true;
			this->iterValue_label->Location = System::Drawing::Point(432, 20);
			this->iterValue_label->Name = L"iterValue_label";
			this->iterValue_label->Size = System::Drawing::Size(13, 13);
			this->iterValue_label->TabIndex = 8;
			this->iterValue_label->Text = L"0";
			// 
			// iter_label
			// 
			this->iter_label->AutoSize = true;
			this->iter_label->Location = System::Drawing::Point(406, 20);
			this->iter_label->Name = L"iter_label";
			this->iter_label->Size = System::Drawing::Size(25, 13);
			this->iter_label->TabIndex = 7;
			this->iter_label->Text = L"Iter:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 360);
			this->Controls->Add(this->statistics_gbox);
			this->Controls->Add(this->acoSetting_gbox);
			this->Controls->Add(this->TspSettings_gbox);
			this->Controls->Add(this->about_button);
			this->Controls->Add(this->logo_picbox);
			this->Controls->Add(this->title_label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Form1";
			this->Text = L"Ant Colony Optimization - TSP";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logo_picbox))->EndInit();
			this->TspSettings_gbox->ResumeLayout(false);
			this->TspSettings_gbox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->max_numdown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->min_numdown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numcity_numdown))->EndInit();
			this->acoSetting_gbox->ResumeLayout(false);
			this->acoSetting_gbox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numOfIteration_numdown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numOfAnts_numdown))->EndInit();
			this->statistics_gbox->ResumeLayout(false);
			this->statistics_gbox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void about_button_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ msg= "ACO TSP v1.0\n";
				 msg = String::Concat(msg,"Programmer: Emad Khezri\n");
				 msg = String::Concat(msg,"M.Sc Student - University of Tehran\n");
				 msg = String::Concat(msg,"Professor: Masoud Asadpour\n");
				 msg = String::Concat(msg,"Course: BioComputing 2013");
				MessageBox::Show( msg, "About",    MessageBoxButtons::OK , MessageBoxIcon::Information );
			 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 //Getting File Name
			 String^ text = this->FileName_txt->Text;
			 msclr::interop::marshal_context context;
			 p.fileName = context.marshal_as<std::string>(text);
			 
			 //Getting number of cities,minValue and MaxValue
			 p.numOfCities = (int)this->numcity_numdown->Value;
			 p.minValue = (int)this->min_numdown->Value;
			 p.maxValue = (int)this->max_numdown->Value;

			 this->start_button->Enabled = true; //Start Button get enable
			 //Make map file
			 m.makeFile(p);

			 this->showFile_button->Enabled = true;
			 this->showTsp_button->Enabled = false;

		 }

private: System::Void showFile_button_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 //Getting File Name
			 String^ text = this->FileName_txt->Text;
			 msclr::interop::marshal_context context;
			 string tempString = "notepad.exe "; //Temporary file
			 tempString = tempString + context.marshal_as<std::string>(text); //Concate with file Name
			 system( tempString.c_str() );
		 }

private: System::Void FileName_txt_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 String^ text = this->FileName_txt->Text;
			 msclr::interop::marshal_context context;
			 fstream f(context.marshal_as<std::string>(text),ios::in); //check see is file ok
			 if(!f)
				 this->showFile_button->Enabled = false;
			 else
				 this->showFile_button->Enabled = true;
		 }

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 String^ text = this->FileName_txt->Text;
			 msclr::interop::marshal_context context;
			 fstream f(context.marshal_as<std::string>(text),ios::in); //check see is file ok
			 this->start_button->Enabled = false;
			 if(!f)
				 this->showFile_button->Enabled = false;

			 this->showTsp_button->Enabled = false;
			 srand ((unsigned int)time(NULL)); //Seek time for rand function
		 }

void setText()
{
			this->bestTspValue_label->Text = best.ToString();;
			this->iterValue_label->Text = (i+1).ToString();
			this->progressBar->Value = (int)((i+1) * 100 / iteration_glob);
			seconds_since_start = difftime( time(0), start);
		    this->timeValue_label->Text = ((int)seconds_since_start).ToString();
}

void disableStart()
{
				 this->idle_label->Text = "Idle";
				 this->showTsp_button->Enabled = true;
				 this->start_button->Enabled = true;
}

void mainAlgorithm()
{
			 for(i=0; i<iteration_glob ;i++)
			 {
				 m.tsp();
			     best  = (int)m.getBestTotalDistance();
				 this->Invoke(gcnew MethodInvoker(this, &Form1::setText));
				 Sleep(100);  

			 }
			 
			 MessageBox::Show( "Algorithm Finished", "Completed",MessageBoxButtons::OK , MessageBoxIcon::Information );
			 this->Invoke(gcnew MethodInvoker(this, &Form1::disableStart));

}

private: System::Void start_button_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 this->progressBar->Value = 0;
			 this->start_button->Enabled = false;
			 this->idle_label->Text = "Busy";
			 //Getting Iteration
			 iteration_glob = (int)this->numOfIteration_numdown->Value;

			 //Keeping track of time
			 start = time(0);

			 String^ text;
			 msclr::interop::marshal_context context;
			 //Getting number of ants, Evaporate Factor, alpha,beta,and iteration
			 p.numOfAnts = (int)this->numOfAnts_numdown->Value;
			 text = this->alpha_txtbox->Text;
			 p.alpha = atof(context.marshal_as<std::string>(text).c_str());
			 text = this->beta_txtbox->Text;
			 p.beta = atof(context.marshal_as<std::string>(text).c_str());
			 text = this->eFacor_txtbox->Text;
		     p.evaporateFactor = atof(context.marshal_as<std::string>(text).c_str());

			 m.freeMemory();

			 m.initialize(p);

			 //Initialize main thread
			 Thread^ tThread = gcnew Thread(gcnew ThreadStart(this, &Form1::mainAlgorithm));
			 //Main Thread Algorithm
			 tThread->Start();




		 }

private: System::Void showTsp_button_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ msg = "The Best Path is :\n ";
			 msg = String::Concat(msg,gcnew String(m.getBestPath().c_str()));
			 
			 MessageBox::Show(msg,"TSP path",MessageBoxButtons::OK);
		 }
};
}

