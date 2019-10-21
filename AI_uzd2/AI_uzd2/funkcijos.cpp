#include "pch.h"
#include "funkcijos.h"
#include <random>
#include <chrono>
#include <iomanip>

const double EulerConstant = std::exp(1.0);

std::mt19937 randomly_seeded_engine() {

	// create a seed sequence of several reasonably random values
	std::seed_seq seed_seq{ (unsigned int)std::random_device{}(),
						   (unsigned int)std::chrono::system_clock::now().time_since_epoch().count(),
						   (unsigned int)std::random_device{}(),
						   (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count(),
						   (unsigned int)std::random_device{}() };

	return std::mt19937(seed_seq); // note: the seed sequence provides a warm up sequence for the rng
}
double randomNum() {

	static auto rng = randomly_seeded_engine();
	static std::uniform_real_distribution<double> distribution;

	distribution.param(std::uniform_real_distribution<double>::param_type{ 0, 1 });
	return distribution(rng);
}

double w_naujas_slenkstine(std::vector<double>w, std::vector<std::vector<double>>x, int nr, int i, std::vector<double>t)
{
	double naujas;
	double n = 1;
	double y = Slenkstine_func(aktivacijos_fun(w, x, i));
	naujas = w[nr] + n * (t[i])*x[i][nr];
	return naujas;
}

double w_naujas_sigmoidine(std::vector<double>w, std::vector<std::vector<double>>x, int nr, int i, std::vector<double>t)
{
	double naujas;
	double n = 1;
	double y = Sigmoidine_func(aktivacijos_fun(w, x, i));
	naujas = w[nr] + n * (t[i] - y)*x[i][nr];
	return naujas;
}

double aktivacijos_fun(std::vector<double> w, std::vector<std::vector<double>>x, int j)
{
	double a = 0;

	for (auto i = 0; i < w.size(); i++)
	{
		a = a + w[i] * x[j][i];
	}

	return a;
}
double Slenkstine_func(double a)
{
	if (a > 0)
	{
		return 1;
	}
	else if (a <= 0)
	{
		return -1;
	}

}
double Sigmoidine_func(double a)
{
	double rez = 1 / (1 + pow(EulerConstant, -a));
	return rez;
}

std::vector<double> w_pildymas(int j)
{
	std::vector<double>w_data;
	for (int i = 0; i < j; i++)
	{
		w_data.push_back(randomNum());
	}
	return w_data;
}
std::vector<std::vector<double>> x_pildymas(std::vector<std::vector<double>>x, std::string n, int kiek)
{
	if (n == "1")
	{
		for (int i = 0; i < kiek; i++)
		{
			double x0, x1, x2, ti;
			std::vector<double>tarpinis;
			x0 = 1;
			tarpinis.push_back(x0);

			std::cout << "Iveskite x" << i << "(1): ";
			std::cin >> x1;
			tarpinis.push_back(x1);

			std::cout << "Iveskite x"<<i<<"(2): ";
			std::cin >> x2;
			std::cout << std::endl;
			tarpinis.push_back(x2);

			x.push_back(tarpinis); // Baigiasi x-su nuskaitymas

		}
		return x;

	}
	else if (n == "2")
	{
		for (int i = 0; i < kiek; i++)
		{
			double x0, x1, x2, x3, ti;
			std::vector<double>tarpinis;
			x0 = 1;
			tarpinis.push_back(x0);

			std::cout << "Iveskite x" << i << "(1): ";
			std::cin >> x1;
			tarpinis.push_back(x1);

			std::cout << "Iveskite x" << i << "(2): ";
			std::cin >> x2;
			tarpinis.push_back(x2);


			std::cout << "Iveskite x" << i << "(3): ";
			std::cin >> x3;
			std::cout << std::endl;
			tarpinis.push_back(x3);

			x.push_back(tarpinis); // Baigiasi x-su nuskaitymas
		}
		return x;
	}
}

std::vector<double> t_pildymas(std::vector<std::vector<double>>x, std::string n, int kiek,std::string funk)
{
	std::vector<double>t;
	double ti;
	if (n == "1")
	{
		for (int i = 0; i < kiek; i++)
		{
			ti = t_AND(x[i],funk);//nustatoma norima reiksme
			t.push_back(ti);
		}
		return t;
	}
	else if (n == "2")
	{
		for (int i = 0; i < kiek; i++)
		{
			ti = t_AND_OR(x[i],funk);//nustatoma norima reiksme
			t.push_back(ti);
		}
		return t;
	}

	
}


double t_AND(std::vector<double>x, std::string funk)
{
	if (funk == "1")
	{
		if (x[1] == 1 & x[2] == 1)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else if (funk == "2")
	{
		if (x[1] == 1 & x[2] == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

}
double t_AND_OR(std::vector<double>x, std::string funk)
{
	if (funk == "1")
	{
		if (x[1] == 1 & x[2] == 1 || x[3] == 1)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else if (funk == "2")
	{
		if (x[1] == 1 & x[2] == 1 || x[3] == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

}

std::vector<double> mokymas(std::vector<double> w, std::vector<std::vector<double>>x, std::vector<double>t, std::string funk)
{
	if (funk == "1")
	{
		std::vector<double> w_new = w;

		for (auto i = 0; i < x.size(); i++)
		{
			double y = Slenkstine_func(aktivacijos_fun(w, x, i));
			if (y != t[i])
			{
				for (auto nr = 0; nr < w_new.size(); nr++)
				{
					w_new[nr] = w_naujas_slenkstine(w_new, x, nr, i, t);

				}

			}
		}
		return w_new;
	}
	else if (funk == "2")
	{
		std::vector<double> w_new = w;

		for (auto i = 0; i < x.size(); i++)
		{
			double y = Sigmoidine_func(aktivacijos_fun(w, x, i));
			if (y != t[i])
			{
				for (auto nr = 0; nr < w_new.size(); nr++)
				{
					w_new[nr] = w_naujas_sigmoidine(w_new, x, nr, i, t);

				}

			}
		}
		return w_new;
	}


}