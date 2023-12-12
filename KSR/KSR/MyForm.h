#pragma once
#include "RK3.h"

namespace KSR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_c;
	protected:

	private: System::Windows::Forms::GroupBox^ params;
	private: System::Windows::Forms::TextBox^ textBox_c;
	private: System::Windows::Forms::Label^ label_m;


	private: System::Windows::Forms::TextBox^ textBox_m;
	private: System::Windows::Forms::Label^ label_k;
	private: System::Windows::Forms::TextBox^ textBox_k;
	private: System::Windows::Forms::TextBox^ textBox_T;
	private: System::Windows::Forms::Label^ label1_u0;



	private: System::Windows::Forms::Label^ label_T;
	private: System::Windows::Forms::TextBox^ textBox_u0;
	private: System::Windows::Forms::Label^ label_du0;
	private: System::Windows::Forms::TextBox^ textBox_du0;
	private: System::Windows::Forms::Label^ label_h;
	private: System::Windows::Forms::TextBox^ textBox_Egr;

	private: System::Windows::Forms::TextBox^ textBox_E;
	private: System::Windows::Forms::TextBox^ textBox_h;
	private: System::Windows::Forms::Label^ label_Egr;
	private: System::Windows::Forms::Label^ label_E;
	private: System::Windows::Forms::RadioButton^ radioButton_const_step;
	private: System::Windows::Forms::RadioButton^ radioButton_variable_step;



	private: System::Windows::Forms::GroupBox^ groupBox_step_type;
	private: System::Windows::Forms::Button^ button_start_calc;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_x_u;
	private: System::Windows::Forms::TextBox^ textBox_Nmax;

	private: System::Windows::Forms::Label^ label_Nmax;
	private: System::Windows::Forms::Button^ button_default;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_du_x;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_du_u;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView_data;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ counter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_x;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_dU;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_U;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_h;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ S;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ OLP;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ C_mul;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ C_div;







































	protected:


	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label_c = (gcnew System::Windows::Forms::Label());
			this->params = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_Nmax = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Egr = (gcnew System::Windows::Forms::TextBox());
			this->textBox_E = (gcnew System::Windows::Forms::TextBox());
			this->textBox_h = (gcnew System::Windows::Forms::TextBox());
			this->textBox_du0 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_u0 = (gcnew System::Windows::Forms::TextBox());
			this->label_Nmax = (gcnew System::Windows::Forms::Label());
			this->label_Egr = (gcnew System::Windows::Forms::Label());
			this->textBox_T = (gcnew System::Windows::Forms::TextBox());
			this->textBox_k = (gcnew System::Windows::Forms::TextBox());
			this->textBox_m = (gcnew System::Windows::Forms::TextBox());
			this->textBox_c = (gcnew System::Windows::Forms::TextBox());
			this->label_E = (gcnew System::Windows::Forms::Label());
			this->label_h = (gcnew System::Windows::Forms::Label());
			this->label_du0 = (gcnew System::Windows::Forms::Label());
			this->label1_u0 = (gcnew System::Windows::Forms::Label());
			this->label_T = (gcnew System::Windows::Forms::Label());
			this->label_k = (gcnew System::Windows::Forms::Label());
			this->label_m = (gcnew System::Windows::Forms::Label());
			this->radioButton_const_step = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_variable_step = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox_step_type = (gcnew System::Windows::Forms::GroupBox());
			this->button_start_calc = (gcnew System::Windows::Forms::Button());
			this->chart_x_u = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button_default = (gcnew System::Windows::Forms::Button());
			this->chart_du_x = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart_du_u = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView_data = (gcnew System::Windows::Forms::DataGridView());
			this->counter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_x = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_dU = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_U = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_h = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->S = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OLP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C_mul = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C_div = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->params->SuspendLayout();
			this->groupBox_step_type->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_x_u))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_du_x))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_du_u))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_data))->BeginInit();
			this->SuspendLayout();
			// 
			// label_c
			// 
			this->label_c->AutoSize = true;
			this->label_c->Location = System::Drawing::Point(6, 28);
			this->label_c->Name = L"label_c";
			this->label_c->Size = System::Drawing::Size(217, 13);
			this->label_c->TabIndex = 0;
			this->label_c->Text = L"Коэффициент демпфирования c (H*c/см)";
			// 
			// params
			// 
			this->params->Controls->Add(this->textBox_Nmax);
			this->params->Controls->Add(this->textBox_Egr);
			this->params->Controls->Add(this->textBox_E);
			this->params->Controls->Add(this->textBox_h);
			this->params->Controls->Add(this->textBox_du0);
			this->params->Controls->Add(this->textBox_u0);
			this->params->Controls->Add(this->label_Nmax);
			this->params->Controls->Add(this->label_Egr);
			this->params->Controls->Add(this->textBox_T);
			this->params->Controls->Add(this->textBox_k);
			this->params->Controls->Add(this->textBox_m);
			this->params->Controls->Add(this->textBox_c);
			this->params->Controls->Add(this->label_E);
			this->params->Controls->Add(this->label_h);
			this->params->Controls->Add(this->label_du0);
			this->params->Controls->Add(this->label1_u0);
			this->params->Controls->Add(this->label_T);
			this->params->Controls->Add(this->label_k);
			this->params->Controls->Add(this->label_m);
			this->params->Controls->Add(this->label_c);
			this->params->Location = System::Drawing::Point(12, 83);
			this->params->Name = L"params";
			this->params->Size = System::Drawing::Size(252, 423);
			this->params->TabIndex = 1;
			this->params->TabStop = false;
			this->params->Text = L"Параметры";
			this->params->Enter += gcnew System::EventHandler(this, &MyForm::params_Enter);
			// 
			// textBox_Nmax
			// 
			this->textBox_Nmax->Location = System::Drawing::Point(9, 318);
			this->textBox_Nmax->Name = L"textBox_Nmax";
			this->textBox_Nmax->Size = System::Drawing::Size(211, 20);
			this->textBox_Nmax->TabIndex = 1;
			this->textBox_Nmax->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox_Egr
			// 
			this->textBox_Egr->Location = System::Drawing::Point(9, 358);
			this->textBox_Egr->Name = L"textBox_Egr";
			this->textBox_Egr->Size = System::Drawing::Size(211, 20);
			this->textBox_Egr->TabIndex = 1;
			this->textBox_Egr->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox_E
			// 
			this->textBox_E->Location = System::Drawing::Point(9, 399);
			this->textBox_E->Name = L"textBox_E";
			this->textBox_E->Size = System::Drawing::Size(211, 20);
			this->textBox_E->TabIndex = 1;
			this->textBox_E->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox_h
			// 
			this->textBox_h->Location = System::Drawing::Point(9, 279);
			this->textBox_h->Name = L"textBox_h";
			this->textBox_h->Size = System::Drawing::Size(211, 20);
			this->textBox_h->TabIndex = 1;
			this->textBox_h->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox_du0
			// 
			this->textBox_du0->Location = System::Drawing::Point(9, 240);
			this->textBox_du0->Name = L"textBox_du0";
			this->textBox_du0->Size = System::Drawing::Size(211, 20);
			this->textBox_du0->TabIndex = 1;
			this->textBox_du0->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox_u0
			// 
			this->textBox_u0->Location = System::Drawing::Point(9, 201);
			this->textBox_u0->Name = L"textBox_u0";
			this->textBox_u0->Size = System::Drawing::Size(211, 20);
			this->textBox_u0->TabIndex = 1;
			this->textBox_u0->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label_Nmax
			// 
			this->label_Nmax->AutoSize = true;
			this->label_Nmax->Location = System::Drawing::Point(6, 302);
			this->label_Nmax->Name = L"label_Nmax";
			this->label_Nmax->Size = System::Drawing::Size(215, 13);
			this->label_Nmax->TabIndex = 0;
			this->label_Nmax->Text = L"Максимальное колличество шагов Nmax";
			// 
			// label_Egr
			// 
			this->label_Egr->AutoSize = true;
			this->label_Egr->Location = System::Drawing::Point(6, 342);
			this->label_Egr->Name = L"label_Egr";
			this->label_Egr->Size = System::Drawing::Size(215, 13);
			this->label_Egr->TabIndex = 0;
			this->label_Egr->Text = L"Параметр выхода на правую границу Egr";
			// 
			// textBox_T
			// 
			this->textBox_T->Location = System::Drawing::Point(9, 162);
			this->textBox_T->Name = L"textBox_T";
			this->textBox_T->Size = System::Drawing::Size(211, 20);
			this->textBox_T->TabIndex = 1;
			this->textBox_T->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox_k
			// 
			this->textBox_k->Location = System::Drawing::Point(9, 123);
			this->textBox_k->Name = L"textBox_k";
			this->textBox_k->Size = System::Drawing::Size(211, 20);
			this->textBox_k->TabIndex = 1;
			this->textBox_k->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox_m
			// 
			this->textBox_m->Location = System::Drawing::Point(9, 84);
			this->textBox_m->Name = L"textBox_m";
			this->textBox_m->Size = System::Drawing::Size(211, 20);
			this->textBox_m->TabIndex = 1;
			this->textBox_m->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox_c
			// 
			this->textBox_c->Location = System::Drawing::Point(9, 45);
			this->textBox_c->Name = L"textBox_c";
			this->textBox_c->Size = System::Drawing::Size(211, 20);
			this->textBox_c->TabIndex = 1;
			this->textBox_c->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label_E
			// 
			this->label_E->AutoSize = true;
			this->label_E->Location = System::Drawing::Point(6, 383);
			this->label_E->Name = L"label_E";
			this->label_E->Size = System::Drawing::Size(244, 13);
			this->label_E->TabIndex = 0;
			this->label_E->Text = L"Параметр контроля локальной погрешности E";
			this->label_E->Click += gcnew System::EventHandler(this, &MyForm::label_E_Click);
			// 
			// label_h
			// 
			this->label_h->AutoSize = true;
			this->label_h->Location = System::Drawing::Point(6, 263);
			this->label_h->Name = L"label_h";
			this->label_h->Size = System::Drawing::Size(81, 13);
			this->label_h->TabIndex = 0;
			this->label_h->Text = L"Шаг ч.м. h (см)";
			// 
			// label_du0
			// 
			this->label_du0->AutoSize = true;
			this->label_du0->Location = System::Drawing::Point(6, 224);
			this->label_du0->Name = L"label_du0";
			this->label_du0->Size = System::Drawing::Size(203, 13);
			this->label_du0->TabIndex = 0;
			this->label_du0->Text = L"Начальное значение скорости u`0 (см)";
			// 
			// label1_u0
			// 
			this->label1_u0->AutoSize = true;
			this->label1_u0->Location = System::Drawing::Point(6, 185);
			this->label1_u0->Name = L"label1_u0";
			this->label1_u0->Size = System::Drawing::Size(214, 13);
			this->label1_u0->TabIndex = 0;
			this->label1_u0->Text = L"Начальное значение координаты u0 (см)";
			// 
			// label_T
			// 
			this->label_T->AutoSize = true;
			this->label_T->Location = System::Drawing::Point(6, 146);
			this->label_T->Name = L"label_T";
			this->label_T->Size = System::Drawing::Size(242, 13);
			this->label_T->TabIndex = 0;
			this->label_T->Text = L"Правая граница отрезка времени T (0<=t<= T)";
			// 
			// label_k
			// 
			this->label_k->AutoSize = true;
			this->label_k->Location = System::Drawing::Point(6, 107);
			this->label_k->Name = L"label_k";
			this->label_k->Size = System::Drawing::Size(157, 13);
			this->label_k->TabIndex = 0;
			this->label_k->Text = L"Жесткость пружины k (H/см)";
			// 
			// label_m
			// 
			this->label_m->AutoSize = true;
			this->label_m->Location = System::Drawing::Point(6, 68);
			this->label_m->Name = L"label_m";
			this->label_m->Size = System::Drawing::Size(102, 13);
			this->label_m->TabIndex = 0;
			this->label_m->Text = L"Масса груза m (кг)";
			// 
			// radioButton_const_step
			// 
			this->radioButton_const_step->AutoSize = true;
			this->radioButton_const_step->Location = System::Drawing::Point(6, 23);
			this->radioButton_const_step->Name = L"radioButton_const_step";
			this->radioButton_const_step->Size = System::Drawing::Size(110, 17);
			this->radioButton_const_step->TabIndex = 2;
			this->radioButton_const_step->TabStop = true;
			this->radioButton_const_step->Text = L"Постоянный шаг";
			this->radioButton_const_step->UseVisualStyleBackColor = true;
			this->radioButton_const_step->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_const_step_CheckedChanged);
			// 
			// radioButton_variable_step
			// 
			this->radioButton_variable_step->AutoSize = true;
			this->radioButton_variable_step->Location = System::Drawing::Point(6, 44);
			this->radioButton_variable_step->Name = L"radioButton_variable_step";
			this->radioButton_variable_step->Size = System::Drawing::Size(113, 17);
			this->radioButton_variable_step->TabIndex = 2;
			this->radioButton_variable_step->TabStop = true;
			this->radioButton_variable_step->Text = L"Переменный шаг";
			this->radioButton_variable_step->UseVisualStyleBackColor = true;
			this->radioButton_variable_step->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_variable_step_CheckedChanged);
			// 
			// groupBox_step_type
			// 
			this->groupBox_step_type->Controls->Add(this->radioButton_const_step);
			this->groupBox_step_type->Controls->Add(this->radioButton_variable_step);
			this->groupBox_step_type->Location = System::Drawing::Point(12, 12);
			this->groupBox_step_type->Name = L"groupBox_step_type";
			this->groupBox_step_type->Size = System::Drawing::Size(161, 65);
			this->groupBox_step_type->TabIndex = 3;
			this->groupBox_step_type->TabStop = false;
			this->groupBox_step_type->Text = L"Выбор контроля шага";
			// 
			// button_start_calc
			// 
			this->button_start_calc->Location = System::Drawing::Point(12, 541);
			this->button_start_calc->Name = L"button_start_calc";
			this->button_start_calc->Size = System::Drawing::Size(161, 23);
			this->button_start_calc->TabIndex = 4;
			this->button_start_calc->Text = L"Начать расчет";
			this->button_start_calc->UseVisualStyleBackColor = true;
			this->button_start_calc->Click += gcnew System::EventHandler(this, &MyForm::button_start_calc_Click);
			// 
			// chart_x_u
			// 
			chartArea4->Name = L"ChartArea1";
			this->chart_x_u->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->chart_x_u->Legends->Add(legend4);
			this->chart_x_u->Location = System::Drawing::Point(6, 25);
			this->chart_x_u->Name = L"chart_x_u";
			series4->BorderWidth = 2;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Color = System::Drawing::Color::Purple;
			series4->Legend = L"Legend1";
			series4->LegendText = L"u(x)";
			series4->Name = L"Series1";
			this->chart_x_u->Series->Add(series4);
			this->chart_x_u->Size = System::Drawing::Size(384, 300);
			this->chart_x_u->TabIndex = 5;
			this->chart_x_u->Text = L"chart1";
			// 
			// button_default
			// 
			this->button_default->Location = System::Drawing::Point(12, 512);
			this->button_default->Name = L"button_default";
			this->button_default->Size = System::Drawing::Size(161, 23);
			this->button_default->TabIndex = 6;
			this->button_default->Text = L"Параметры по умолчанию";
			this->button_default->UseVisualStyleBackColor = true;
			this->button_default->Click += gcnew System::EventHandler(this, &MyForm::button_default_Click);
			// 
			// chart_du_x
			// 
			chartArea5->Name = L"ChartArea1";
			this->chart_du_x->ChartAreas->Add(chartArea5);
			legend5->Name = L"Legend1";
			this->chart_du_x->Legends->Add(legend5);
			this->chart_du_x->Location = System::Drawing::Point(396, 25);
			this->chart_du_x->Name = L"chart_du_x";
			series5->BorderWidth = 2;
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series5->Color = System::Drawing::Color::Purple;
			series5->Legend = L"Legend1";
			series5->LegendText = L"u`(x)";
			series5->Name = L"Series1";
			this->chart_du_x->Series->Add(series5);
			this->chart_du_x->Size = System::Drawing::Size(384, 300);
			this->chart_du_x->TabIndex = 5;
			this->chart_du_x->Text = L"chart1";
			// 
			// chart_du_u
			// 
			chartArea6->Name = L"ChartArea1";
			this->chart_du_u->ChartAreas->Add(chartArea6);
			legend6->Name = L"Legend1";
			this->chart_du_u->Legends->Add(legend6);
			this->chart_du_u->Location = System::Drawing::Point(786, 25);
			this->chart_du_u->Name = L"chart_du_u";
			series6->BorderWidth = 2;
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series6->Color = System::Drawing::Color::Purple;
			series6->Legend = L"Legend1";
			series6->LegendText = L"u`(u)";
			series6->Name = L"Series1";
			this->chart_du_u->Series->Add(series6);
			this->chart_du_u->Size = System::Drawing::Size(384, 300);
			this->chart_du_u->TabIndex = 5;
			this->chart_du_u->Text = L"chart1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->chart_x_u);
			this->groupBox1->Controls->Add(this->chart_du_x);
			this->groupBox1->Controls->Add(this->chart_du_u);
			this->groupBox1->Location = System::Drawing::Point(275, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1175, 331);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Графики";
			// 
			// dataGridView_data
			// 
			this->dataGridView_data->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_data->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->counter,
					this->Column_x, this->Column_dU, this->Column_U, this->Column_h, this->S, this->OLP, this->C_mul, this->C_div
			});
			this->dataGridView_data->Location = System::Drawing::Point(281, 349);
			this->dataGridView_data->Name = L"dataGridView_data";
			this->dataGridView_data->RowTemplate->ReadOnly = true;
			this->dataGridView_data->Size = System::Drawing::Size(944, 295);
			this->dataGridView_data->TabIndex = 8;
			// 
			// counter
			// 
			this->counter->HeaderText = L"i";
			this->counter->Name = L"counter";
			// 
			// Column_x
			// 
			this->Column_x->HeaderText = L"X";
			this->Column_x->Name = L"Column_x";
			this->Column_x->ToolTipText = L"fff";
			// 
			// Column_dU
			// 
			this->Column_dU->HeaderText = L"U`";
			this->Column_dU->Name = L"Column_dU";
			// 
			// Column_U
			// 
			this->Column_U->HeaderText = L"U";
			this->Column_U->Name = L"Column_U";
			// 
			// Column_h
			// 
			this->Column_h->HeaderText = L"h";
			this->Column_h->Name = L"Column_h";
			// 
			// S
			// 
			this->S->HeaderText = L"S = |v^ - v|";
			this->S->Name = L"S";
			// 
			// OLP
			// 
			this->OLP->HeaderText = L"OLP";
			this->OLP->Name = L"OLP";
			// 
			// C_mul
			// 
			this->C_mul->HeaderText = L"Count h*2";
			this->C_mul->Name = L"C_mul";
			// 
			// C_div
			// 
			this->C_div->HeaderText = L"Count h/2";
			this->C_div->Name = L"C_div";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1451, 656);
			this->Controls->Add(this->dataGridView_data);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_default);
			this->Controls->Add(this->button_start_calc);
			this->Controls->Add(this->groupBox_step_type);
			this->Controls->Add(this->params);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->params->ResumeLayout(false);
			this->params->PerformLayout();
			this->groupBox_step_type->ResumeLayout(false);
			this->groupBox_step_type->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_x_u))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_du_x))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_du_u))->EndInit();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_data))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}

private: System::Void radioButton_const_step_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void radioButton_variable_step_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
//Чето перепутал----------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
private: System::Void params_Enter(System::Object^ sender, System::EventArgs^ e) {}

private: System::Void button_start_calc_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label_E_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_default_Click(System::Object^ sender, System::EventArgs^ e);
};
}
