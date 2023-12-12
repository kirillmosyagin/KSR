#include "MyForm.h"
#include <iostream>
#include "RK3.h"



using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	KSR::MyForm form;
	Application::Run(% form);
}

std::vector<double> vec_x, vec_u, vec_du, vec_h, vec_S;
std::vector<int> vec_C_mul, vec_C_div;



System::Void KSR::MyForm::radioButton_const_step_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->params->Height = 383;
	this->label_h->Text = "Шаг ч.м. h (см)";
	this->textBox_E->Text = "";
}

System::Void KSR::MyForm::radioButton_variable_step_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->params->Height = 423;
	this->label_h->Text = "Начальный шаг ч.м. h0 (см)";
}

System::Void KSR::MyForm::button_default_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->radioButton_const_step->Checked)
	{
		this->textBox_c->Text = "0,15";
		this->textBox_m->Text = "1";
		this->textBox_k->Text = "2";
		this->textBox_T->Text = "1";
		this->textBox_du0->Text = "0";
		this->textBox_u0->Text = "10";
		this->textBox_h->Text = "0,1";
		this->textBox_Nmax->Text = "10000";
		this->textBox_Egr->Text = "0,0001";

		c = Convert::ToDouble(this->textBox_c->Text);               //1
		m = Convert::ToDouble(this->textBox_m->Text);              //2
		k = Convert::ToDouble(this->textBox_k->Text);             //3
		T = Convert::ToDouble(this->textBox_T->Text);            //4
		v10 = Convert::ToDouble(this->textBox_du0->Text);       //5
		v20 = Convert::ToDouble(this->textBox_u0->Text);       //6
		h0 = Convert::ToDouble(this->textBox_h->Text);        //7
		Nmax = Convert::ToDouble(this->textBox_Nmax->Text);  //8
		Egr = Convert::ToDouble(this->textBox_Egr->Text);   //9
	}

	if (this->radioButton_variable_step->Checked)
	{
		this->textBox_c->Text = "0,15";
		this->textBox_m->Text = "1";
		this->textBox_k->Text = "2";
		this->textBox_T->Text = "1";
		this->textBox_du0->Text = "0";
		this->textBox_u0->Text = "10";
		this->textBox_h->Text = "0,1";
		this->textBox_Nmax->Text = "10000";
		this->textBox_Egr->Text = "0,0001";
		this->textBox_E->Text = "0,001";

		c = Convert::ToDouble(this->textBox_c->Text);               //1
		m = Convert::ToDouble(this->textBox_m->Text);              //2
		k = Convert::ToDouble(this->textBox_k->Text);             //3
		T = Convert::ToDouble(this->textBox_T->Text);            //4
		v10 = Convert::ToDouble(this->textBox_du0->Text);       //5
		v20 = Convert::ToDouble(this->textBox_u0->Text);       //6
		h0 = Convert::ToDouble(this->textBox_h->Text);        //7
		Nmax = Convert::ToDouble(this->textBox_Nmax->Text);  //8
		Egr = Convert::ToDouble(this->textBox_Egr->Text);   //9
		E = Convert::ToDouble(this->textBox_E->Text);      //10
	}
}

System::Void KSR::MyForm::button_start_calc_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (this->radioButton_const_step->Checked)
	{
		if (this->textBox_c->Text == "" || this->textBox_m->Text == "" || this->textBox_k->Text == "" || this->textBox_T->Text == "" || this->textBox_du0->Text == "" || this->textBox_u0->Text == "" || this->textBox_h->Text == "" || this->textBox_Egr->Text == "" || this->textBox_Nmax->Text == "")
		{
			MessageBox::Show("Введите все требующиеся параметры", "Внимание!");
			return;
		}

		c = Convert::ToDouble(this->textBox_c->Text);               //1
		m = Convert::ToDouble(this->textBox_m->Text);              //2
		k = Convert::ToDouble(this->textBox_k->Text);             //3
		T = Convert::ToDouble(this->textBox_T->Text);            //4
		v10 = Convert::ToDouble(this->textBox_du0->Text);       //5
		v20 = Convert::ToDouble(this->textBox_u0->Text);       //6
		h0 = Convert::ToDouble(this->textBox_h->Text);        //7
		Nmax = Convert::ToDouble(this->textBox_Nmax->Text);  //8
		Egr = Convert::ToDouble(this->textBox_Egr->Text);   //9
		p1 = -k / m;
		p2 = -c / m;
		
		double copy_h0 = h0;
		RK3_const_step(vec_x, vec_du, vec_u, h0, vec_S);
		this->chart_x_u->Series[0]->Points->Clear(); // условие поставить
		for (size_t n = 0; n < vec_x.size(); n++)
		{
			this->chart_x_u->Series[0]->Points->AddXY(vec_x[n], vec_u[n]);
		}

		this->chart_du_x->Series[0]->Points->Clear(); // условие поставить
		for (size_t n = 0; n < vec_x.size(); n++)
		{
			this->chart_du_x->Series[0]->Points->AddXY(vec_x[n], vec_du[n]);
		}

		this->chart_du_u->Series[0]->Points->Clear(); // условие поставить
		for (size_t n = 0; n < vec_x.size(); n++)
		{
			this->chart_du_u->Series[0]->Points->AddXY(vec_u[n], vec_du[n]);
		}
		std::vector<double> h(vec_x.size() - 1, copy_h0);
		h.push_back(h0);


		System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();

		dataGridView_data->Rows->Clear();
		size_t size = vec_x.size();
		for (int i = 0; i < size; i++)
			dataGridView_data->Rows->Add(i, vec_x[i], vec_du[i], vec_u[i], h[i], vec_S[i], vec_S[i]*8);
		//MyTable table("const");
		//MyTable* ptrMT;
		//table.addRow(vec_x, vec_du, vec_u, h0, h_last, vec_S);
	//	dataGridView_data->Rows->Clear();
		//ptrMT = &table;
		//ptrMT->printTable1(dataGridView_data);

		//this->dataGridView_const_step->Columns[0] = vec_x;

    }
	else if (this->radioButton_variable_step->Checked)
	{
		if (this->textBox_c->Text == "" || this->textBox_m->Text == "" || this->textBox_k->Text == "" || this->textBox_T->Text == "" || this->textBox_du0->Text == "" || this->textBox_u0->Text == "" || this->textBox_h->Text == "" || this->textBox_Egr->Text == "" || this->textBox_Nmax->Text == "" || this->textBox_E->Text == "")
		{
			MessageBox::Show("Введите все требующиеся параметры", "Внимание!");
			return;
		}

		c = Convert::ToDouble(this->textBox_c->Text);               //1
		m = Convert::ToDouble(this->textBox_m->Text);              //2
		k = Convert::ToDouble(this->textBox_k->Text);             //3
		T = Convert::ToDouble(this->textBox_T->Text);            //4
		v10 = Convert::ToDouble(this->textBox_du0->Text);       //5
		v20 = Convert::ToDouble(this->textBox_u0->Text);       //6
		h0 = Convert::ToDouble(this->textBox_h->Text);        //7
		Nmax = Convert::ToDouble(this->textBox_Nmax->Text);  //8
		Egr = Convert::ToDouble(this->textBox_Egr->Text);   //9
		E = Convert::ToDouble(this->textBox_E->Text);      //10 
		p1 = -c / m;
		p2 = -k / m;

		RK3_variable_step(vec_x, vec_du, vec_u, vec_h, h0, vec_S, vec_C_mul, vec_C_div);
		this->chart_x_u->Series[0]->Points->Clear(); // условие поставить
		for (size_t n = 0; n < vec_x.size(); n++)
		{
			this->chart_x_u->Series[0]->Points->AddXY(vec_x[n], vec_u[n]);
		}

		this->chart_du_x->Series[0]->Points->Clear(); // условие поставить
		for (size_t n = 0; n < vec_x.size(); n++)
		{
			this->chart_du_x->Series[0]->Points->AddXY(vec_x[n], vec_du[n]);
		}

		this->chart_du_u->Series[0]->Points->Clear(); // условие поставить
		for (size_t n = 0; n < vec_x.size(); n++)
		{
			this->chart_du_u->Series[0]->Points->AddXY(vec_u[n], vec_du[n]);
		}

		System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();
		dataGridView_data->Rows->Clear();
		size_t size = vec_x.size();
		for (int i = 0; i < size; i++)
			dataGridView_data->Rows->Add(i, vec_x[i], vec_du[i], vec_u[i], vec_h[i], vec_S[i], vec_S[i] * 8.0, vec_C_mul[i], vec_C_div[i]);
	}
}


