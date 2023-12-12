#pragma once
#include <ios>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "MyForm.h"

#include <vector>
#include <string>

class MyTable
{
	std::vector<std::string> columnNames;
	std::vector<std::vector<double>> columns;
public:
	MyTable() {}

	MyTable(const std::vector<std::string>& rowNames)
	{
		this->columnNames = rowNames;
		columns = std::vector<std::vector<double>>(rowNames.size());
	}

	MyTable(std::string type_step)
	{

		if (type_step == "const")
		{
			columnNames.push_back("X");
			columnNames.push_back("U`");
			columnNames.push_back("U");
			columnNames.push_back("h");
			columnNames.push_back("S = |V^ - V|");
			columnNames.push_back("OLP");
		}
		else if(type_step == "variable")
		{
			columnNames.push_back("X");
			columnNames.push_back("U`");
			columnNames.push_back("U");
			columnNames.push_back("h");
			columnNames.push_back("S = |V^ - V|");
			columnNames.push_back("OLP");
			columnNames.push_back("C1");
			columnNames.push_back("C2");
		}


		columns = std::vector<std::vector<double>>(columnNames.size());
	}

	void addRow(const std::vector<double>& row)
	{
		for (int i = 0; i < columns.size(); i++)
			columns[i].push_back(row[i]);
	}

	void addRow(std::vector<double>& x, std::vector<double>& du, std::vector<double>& u, double& h0, double h_last, std::vector<double>& S)
	{
		columns[0] = x;
		columns[1] = du;
		columns[2] = u;
		std::vector<double> tmp(x.size() - 1, h0);
		tmp.push_back(h_last);
		columns[3] = tmp;
		columns[4] = S;
		tmp.clear();
		for (size_t i = 0; i < S.size(); i++)
		{
			tmp.push_back(S[i] * 8.0);
		}
		columns[5] = tmp;
	}

	void addColumn(std::string columnName, std::vector<double> values)
	{
		columnNames.push_back(columnName);
		columns.push_back(values);
	}

	void printTable1(System::Windows::Forms::DataGridView^ dataGridView)                    //const step
	{
		System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();

		size_t size = columns[0].size();
		for (int i = 0; i < size; i++)
			dataGridView->Rows->Add(i, columns[0][i], columns[1][i], columns[2][i], columns[3][i], columns[4][i], columns[5][i]);
	}

	void printTable2(System::Windows::Forms::DataGridView^ dataGridView)
	{
		System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();

		size_t size = columns[0].size();
		for (int i = 0; i < size; i++)
			dataGridView->Rows->Add(i, columns[0][i], columns[2][i], columns[4][i], columns[9][i], columns[6][i], columns[8][i], columns[10][i], columns[11][i]);
	}

	std::vector<double> getColumn(std::string columnName)
	{
		size_t columnInd;

		for (size_t i = 0; i < columnNames.size(); i++)
			if (columnNames[i] == columnName)
				columnInd = i;

		return columns[columnInd];
	}

	~MyTable();
};

void spravka(MyTable* res, System::Windows::Forms::RichTextBox^ out, double b)
{
	out->Text = "";

	size_t size = res->getColumn("Xi").size(), maxHind = 0, minHind = 0;
	double maxOLP1 = -1.0, maxOLP2 = -1.0, maxH = res->getColumn("h")[0], minH = res->getColumn("h")[0];

	out->Text = out->Text + "×èñëî óäâîåíèé øàãà:  " + System::Convert::ToString(res->getColumn("C2")[size - 1]) + "\n";
	out->Text = out->Text + "×èñëî äåëåíèé øàãà:  " + System::Convert::ToString(res->getColumn("C1")[size - 1]) + "\n";
	out->Text = out->Text + "Îáùåå ÷èñëî øàãîâ:  " + System::Convert::ToString(size) + "\n";

	std::vector<double> OLP1 = res->getColumn("OLP1");
	std::vector<double> OLP2 = res->getColumn("OLP2");
	std::vector<double> h = res->getColumn("h");

	for (int i = 0; i < size; i++)
		if (maxOLP1 < abs(OLP1[i]))
			maxOLP1 = abs(OLP1[i]);

	for (int i = 0; i < size; i++)
		if (maxOLP2 < abs(OLP2[i]))
			maxOLP2 = abs(OLP2[i]);

	if (OLP1 >= OLP2)
		out->Text = out->Text + "Ìàêñ. |ÎËÏ|:  " + System::Convert::ToString(maxOLP1) + "\n";
	else
		out->Text = out->Text + "Ìàêñ. |ÎËÏ|:  " + System::Convert::ToString(maxOLP2) + "\n";

	for (int i = 1; i < size; i++)
	{
		if (maxH < h[i])
		{
			maxH = h[i];
			maxHind = i;
		}

		if (minH > h[i])
		{
			minH = h[i];
			minHind = i;
		}
	}

	out->Text = out->Text + "Написать здесь1...:  " + System::Convert::ToString(res->getColumn("h")[maxHind]) + "\n";
	out->Text = out->Text + "Написать здесь2...:  " + System::Convert::ToString(res->getColumn("h")[minHind]) + "\n";
}
