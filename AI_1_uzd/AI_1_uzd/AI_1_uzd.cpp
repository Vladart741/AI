#include "stdafx.h"
#include<iostream>
#include<vector>
#include <string>

#include <fstream>
const double EulerConstant = std::exp(1.0);

double aktivacijos_fun(double x[4][3], double w[3], int j);
double Slenkstine_func(double a);
double Sigmoidine_func(double a);
void nuskaitymas(double x[4][3], double w[3]);

int main()
{
	start:
	double x[4][3];
	double w[3];
	double a[4], rez_sl[4], rez_sig[4];
	nuskaitymas(x, w);
	std::cout << "Pasirinkite kokią funciją norite naudoti:" << std::endl;
	std::cout << "1) Slenkstinę" << std::endl;
	std::cout << "2) Sigmoidine" << std::endl;
	std::string pasirinkimas;
	std::cin >> pasirinkimas;
	for (int i = 0; i < 4; i++)
	{
		a[i] = aktivacijos_fun(x, w, i);
	}
	for (int i = 0; i < 4; i++)
	{
		if (pasirinkimas == "1")
		{
			rez_sl[i] = Slenkstine_func(a[i]);
			std::cout<< rez_sl[i] << std::endl;
		}
		else if (pasirinkimas == "2")
		{

			rez_sig[i] = Sigmoidine_func(a[i]);
			std::cout << rez_sig[i] << std::endl;
		}
		else
		{
			std::cout << "Iveskite SKAICIU" << std::endl;
			goto start;
		}

	}

	system("pause");

    return 0;
}

void nuskaitymas(double x[4][3], double w[3])
{
	std::ifstream fd;
	fd.open("data.txt");
	for (int i = 0; i < 4; i++)
	{
		fd >> x[i][0] >> x[i][1] >> x[i][2];
	}
	fd >> w[0] >> w[1] >> w[2]; // Nuskaitomi nuspėjamieji w

}
double aktivacijos_fun(double x[4][3], double w[3], int j)
{
	double a=0;
	
		for (auto i = 0; i < 3; i++)
		{
			a = a + (w[i] * x[j][i]); 
		}

	return a;
}
double Slenkstine_func(double a)
{
		if (a >= 0)
		{
			return 1;
		}
		else if (a < 0)
		{
			return 0;
		}
	
}
double Sigmoidine_func(double a)
{
	double rez = 1 / (1 + pow(EulerConstant, -a));
	if (rez >= 0.5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
