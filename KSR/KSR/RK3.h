#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <string>



double c, m, k;
double p1 = 0, p2 = 0, h0 = 0, v10, v20, T, E, Egr;
double k1_1, k2_1, k3_1, k1_2, k2_2, k3_2;
int Nmax = 0;

//DataTable table;

//void initALL(double c = 0.15, double m = 1.0, double k = 2.0, double T = 1, double u0 = 0.0, double du0 = 0.0, double h = 0.1) // c,m,k - парам-ры в системе, 0 <= x <= T, v20 н.у. для координаты, v10 = u`0 н.у. скорости, h - шаг.            
//{
//	p1 = -k / m;
//	p2 = -c / m;
//	h0 = h;
//	v10 = du0;
//	v20 = u0;
//}

void k123_12(double v1n, double v2n, double hn) //k(1-3)_(1-2)
{
	k1_1 =  p1 * v1n + p2 * v2n;
	k1_2 = v1n;

	k2_1 = p1 * (v1n + (hn / 3.0) * k1_1) + p2 * (v2n + (hn / 3.0) * k1_2);
	k2_2 = v1n + (hn / 3.0) * k1_2;

	k3_1 = p1 * (v1n + (2.0 * hn / 3.0) * k2_1) + p2 * (v2n + (2.0 * hn / 3.0) * k2_2);
	k3_2 = v1n + (2.0 * hn / 3.0) * k2_2;
}

void RK3_const_step(std::vector<double>& x, std::vector<double>& du, std::vector<double>& u, double& h0, std::vector<double>& S) // du = z = u`; u = u; Все вектора size = 0!!!
{
	x.clear();
	du.clear();
	u.clear();
	S.clear();

	x.push_back(0);          //x[0] = 0;
	du.push_back(v10);      //du[0] = v10;
	u.push_back(v20);      //u[0] = v20;
	S.push_back(0);       //S[0] = 0;
	int n = 0;

	double v1_half_step, v2_half_step;
	double S1, S2;


	while (x.back() <= T && n < Nmax)  //x[n] <= T
	{
		x.push_back(x[n] + h0);   //x[n + 1] = x[n] + h0;
		k123_12(du[n], u[n], h0);

		du.push_back(du[n] + h0 * (0.25 * k1_1 + 0.75 * k3_1));  //du[n + 1] = du[n] + h0 * (0.25 * k1_1 + 0.75 * k3_1);
		u.push_back(u[n] + h0 * (0.25 * k1_2 + 0.75 * k3_2));   //u[n + 1] = u[n] + h0 * (0.25 * k1_2 + 0.75 * k3_2);

		k123_12(du[n], u[n], 0.5 * h0);
		v1_half_step = du[n] + 0.5 * h0 * (0.25 * k1_1 + 0.75 * k3_1);
		v2_half_step = u[n] + 0.5 * h0 * (0.25 * k1_2 + 0.75 * k3_2);
		k123_12(v1_half_step, v2_half_step, 0.5 * h0);
		v1_half_step = v1_half_step + 0.5 * h0 * (0.25 * k1_1 + 0.75 * k3_1);
		v2_half_step = v2_half_step + 0.5 * h0 * (0.25 * k1_2 + 0.75 * k3_2);


		S1 = abs(v1_half_step - du[n + 1]);
		S2 = abs(v2_half_step - u[n + 1]);
		double max = S1;
		if (max < S2)
			max = S2;
		S.push_back(max / 7.0); //S[n + 1] = max / 7.0;

		n++;
	}


	if (x[n] > T)
	{
		x.pop_back();
		du.pop_back();
		u.pop_back();
		S.pop_back();
		n--;
	}

	if (x[n] < T - Egr && n < Nmax)
	{
		h0 = T - 0.5 * Egr - x[n];
		x.push_back(x[n] + h0);            //x[n + 1] = x[n] + h0;
		k123_12(du[n], u[n], h0);

		du.push_back(du[n] + h0 * (0.25 * k1_1 + 0.75 * k3_1));  //du[n + 1] = du[n] + h0 * (0.25 * k1_1 + 0.75 * k3_1);
		u.push_back(u[n] + h0 * (0.25 * k1_2 + 0.75 * k3_2));   //u[n + 1] = u[n] + h0 * (0.25 * k1_2 + 0.75 * k3_2);

		k123_12(du[n], u[n], 0.5 * h0);
		v1_half_step = du[n] + 0.5 * h0 * (0.25 * k1_1 + 0.75 * k3_1);
		v2_half_step = u[n] + 0.5 * h0 * (0.25 * k1_2 + 0.75 * k3_2);
		k123_12(v1_half_step, v2_half_step, 0.5 * h0);
		v1_half_step = v1_half_step + 0.5 * h0 * (0.25 * k1_1 + 0.75 * k3_1);
		v2_half_step = v2_half_step + 0.5 * h0 * (0.25 * k1_2 + 0.75 * k3_2);


		S1 = abs(v1_half_step - du[n + 1]);
		S2 = abs(v2_half_step - u[n + 1]);
		double max = S1;
		if (max < S2)
			max = S2;
		S.push_back(max / 7.0); //S[n + 1] = max / 7.0;


		n++;
	}

	// return n; Уже ненадо, просто вызывать size() у векотра
}

void RK3_variable_step(std::vector<double>& x, std::vector<double>& du, std::vector<double>& u, std::vector<double>& h, double h0, std::vector<double>& S, std::vector<int>& C_mul, std::vector<int>& C_div) // du = z = u`; u = u, S_n = v^_n - v_n;  Все вектора size = 0!!!
{
	int c1 = 0, c2 = 0;
	x.clear();
	du.clear();
	u.clear();
	h.clear();
	S.clear();

	x.push_back(0);            //x[0] = 0; время
	du.push_back(v10);        //du[0] = v10;
	u.push_back(v20);        //u[0] = v20;
	h.push_back(h0);        //h[0] = h0;
	S.push_back(0);        //S[0] = 0;
	C_mul.push_back(0);   //C_mul[0] = 0;
	C_div.push_back(0);  //C_div[0] = 0;
	int n = 0;

	double v1_half_step, v2_half_step;
	double S1, S2;

	while (x.back() <= T && n < Nmax)
	{
		x.push_back(x[n] + h[n]);    //x[n + 1] = x[n] + h[n];
		k123_12(du[n], u[n], h[n]);

		du.push_back(du[n] + h[n] * (0.25 * k1_1 + 0.75 * k3_1));  //du[n + 1] = du[n] + h[n] * (0.25 * k1_1 + 0.75 * k3_1);
		u.push_back(u[n] + h[n] * (0.25 * k1_2 + 0.75 * k3_2));   //u[n + 1] = u[n] + h[n] * (0.25 * k1_2 + 0.75 * k3_2);



		k123_12(du[n], u[n], 0.5 * h[n]);
		v1_half_step = du[n] + 0.5 * h[n] * (0.25 * k1_1 + 0.75 * k3_1);
		v2_half_step = u[n] + 0.5 * h[n] * (0.25 * k1_2 + 0.75 * k3_2);
		k123_12(v1_half_step, v2_half_step, 0.5 * h[n]);
		v1_half_step = v1_half_step + 0.5 * h[n] * (0.25 * k1_1 + 0.75 * k3_1);
		v2_half_step = v2_half_step + 0.5 * h[n] * (0.25 * k1_2 + 0.75 * k3_2);


		S1 = abs(v1_half_step - du[n + 1]);
		S2 = abs(v2_half_step - u[n + 1]);
		double max = S1;
		if (max < S2)
			max = S2;
		S.push_back(max / 7.0); //S[n + 1] = max / 7.0;

		if (S[n + 1] < E / 16.0)  // 2^(3+1)
		{
			h.push_back(h[n] * 2.0);  //h[n + 1] = h[n] * 2.0;
			c1++;
			C_mul.push_back(c1);
			C_div.push_back(c2);
		}
		else if (S[n + 1] > E)
		{
			x.pop_back();
			du.pop_back();
			u.pop_back();
			S.pop_back();   //ничего ыедь не может пойти не так?
			h[n] /= 2.0;
			c2++;
			n--;	
		}
		else
		{
			h.push_back(h[n]);  //h[n + 1] = h[n];
			C_mul.push_back(c1);
			C_div.push_back(c2);
		}
		n++;
	//занулять max S1 S2 да вроде не надо	
	}

	//проверка на правую границу выхода
	if (x.back() > T)  //x[n] <= T
	{
		x.pop_back();
		du.pop_back();
		u.pop_back();
		S.pop_back();

		h.pop_back();


		C_mul.pop_back();
		C_div.pop_back();
		n--;
	}

	if (x.back() < T - Egr && n < Nmax)   //x[n] < T
	{
		h0 = T - 0.5 * Egr - x[n];
		x.push_back(x[n] + h0);            //x[n + 1] = x[n] + h0;
		k123_12(du[n], u[n], h0);

		du.push_back(du[n] + h0 * (0.25 * k1_1 + 0.75 * k3_1));  //du[n + 1] = du[n] + h0 * (0.25 * k1_1 + 0.75 * k3_1);
		u.push_back(u[n] + h0 * (0.25 * k1_2 + 0.75 * k3_2));   //u[n + 1] = u[n] + h0 * (0.25 * k1_2 + 0.75 * k3_2);
		h.push_back(0);   //нам же не надо идти дальше

		k123_12(du[n], u[n], 0.5 * h[n]);
		v1_half_step = du[n] + 0.5 * h[n] * (0.25 * k1_1 + 0.75 * k3_1);
		v2_half_step = u[n] + 0.5 * h[n] * (0.25 * k1_2 + 0.75 * k3_2);
		k123_12(v1_half_step, v2_half_step, 0.5 * h[n]);
		v1_half_step = v1_half_step + 0.5 * h[n] * (0.25 * k1_1 + 0.75 * k3_1);
		v2_half_step = v2_half_step + 0.5 * h[n] * (0.25 * k1_2 + 0.75 * k3_2);


		S1 = abs(v1_half_step - du[n + 1]);
		S2 = abs(v2_half_step - u[n + 1]);
		double max = S1;
		if (max < S2)
			max = S2;
		S.push_back(max / 7.0); //S[n + 1] = max / 7.0;
		C_mul.push_back(C_mul[n]);
		C_div.push_back(C_div[n]);

		n++;
	}

	if (n=Nmax)
	{
		h.pop_back();
		h.push_back(0);
	}

	//return n;
}
