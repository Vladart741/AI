#include "pch.h"
#include <iostream>
#include <string>
#include<vector>
#include "funkcijos.h"

int main()
{
	std::cout << "Pasirinkite norima varianta:" << std::endl;
	std::cout << "1) t = x1 AND x2" << std::endl;
	std::cout << "2) t = x1 AND x2 OR x3" << std::endl;
	std::string n;
	std::cin >> n;

	std::cout << "Kiek bus ivedimo vektoriu? ";
	int kiek;
	std::cin >> kiek;

	std::cout << "Pasirinkite aktivacijos funkcija:" << std::endl;
	std::cout << "1) Slenkstine" << std::endl;
	std::cout << "2) Sigmoidine" << std::endl;
	std::string funk;
	std::cin >> funk;

	

	std::vector<std::vector<double>>x;
	std::vector<double>w;
	std::vector<double>w_old;
	std::vector<double>t,t_gautas;

	if (n == "1")
	{
		
		int iteraciju_sk = 0;
		x = x_pildymas(x, n, kiek);
		t = t_pildymas(x, n, kiek,funk);
		w = w_pildymas(3);
		w_old = w;
		

		for (auto i = 0; i < t.size(); i++)
		{
			if (funk == "1")
			{
				double y = Slenkstine_func(aktivacijos_fun(w, x, i));
				t_gautas.push_back(y);
			}
			else if (funk == "2")
			{
				double y = Sigmoidine_func(aktivacijos_fun(w, x, i));
				t_gautas.push_back(y);
			}

		}

		for (auto i = 0; i < t.size(); i++)
		{
			
			while (t_gautas!=t & iteraciju_sk <10000)
			{
				w = mokymas(w, x, t,funk);
				iteraciju_sk++;
				for (auto i = 0; i < t.size(); i++)
				{

					if (funk == "1")
					{
						double y = Slenkstine_func(aktivacijos_fun(w, x, i));
						t_gautas[i] = y;
					}
					else if (funk == "2")
					{
						double y = Sigmoidine_func(aktivacijos_fun(w, x, i));
						t_gautas[i] = y;
					}

				}
			}
		}
		for (auto i = 0; i < w.size(); i++)
		{
			std::cout << "Iki mokymo w(" << i << "): " << w_old[i];
			std::cout << "----------> Po mokymo w(" << i << "): " << w[i] << std::endl;
		}

		std::cout << "Iteraciju sk: " << iteraciju_sk << std::endl;
		std::cout << std::endl;
		std::cout << "PATIKRINIMAS t:" << std::endl;
		std::cout << std::endl;
		for (auto i = 0; i < x.size(); i++)
		{
			if (funk == "1")
			{
				double y = Slenkstine_func(aktivacijos_fun(w, x, i));
				std::cout << "t(" << i << "): " << t[i] << " ----------> t_gautas(" << i << "): " << y <<"   PAKLAIDA: "<<t[i]-y<< std::endl;
			}
			else if (funk == "2")
			{
				double y = Sigmoidine_func(aktivacijos_fun(w, x, i));
				std::cout << "t(" << i << "): " << t[i] << " ----------> t_gautas(" << i << "): " << y << "   PAKLAIDA: " << t[i] - y << std::endl;
			}


		}

	}
	else if (n == "2")
	{
		int iteraciju_sk = 0;
		x = x_pildymas(x, n, kiek);
		t = t_pildymas(x, n, kiek,funk);
		w = w_pildymas(4);
		w_old = w;


		for (auto i = 0; i < t.size(); i++)
		{
			if (funk == "1")
			{
				double y = Slenkstine_func(aktivacijos_fun(w, x, i));
				t_gautas.push_back(y);
			}
			else if (funk == "2")
			{
				double y = Sigmoidine_func(aktivacijos_fun(w, x, i));
				t_gautas.push_back(y);
			}
		}

		for (auto i = 0; i < t.size(); i++)
		{

			while (t_gautas != t & iteraciju_sk < 10000)
			{
				w = mokymas(w, x, t,funk);
				iteraciju_sk++;
				for (auto i = 0; i < t.size(); i++)
				{
					if (funk == "1")
					{
						double y = Slenkstine_func(aktivacijos_fun(w, x, i));
						t_gautas[i] = y;
					}
					else if (funk == "2")
					{
						double y = Sigmoidine_func(aktivacijos_fun(w, x, i));
						t_gautas[i] = y;
					}
				}
			}
		}
		for (auto i = 0; i < w.size(); i++)
		{
			std::cout << "Iki mokymo w(" << i << "): " << w_old[i];
			std::cout << "----------> Po mokymo w(" << i << "): " << w[i] << std::endl;
		}

		std::cout << "Iteraciju sk: " << iteraciju_sk << std::endl;
		std::cout << std::endl;
		std::cout << "PATIKRINIMAS t:" << std::endl;
		std::cout << std::endl;
		for (auto i = 0; i < t.size(); i++)
		{
			if (funk == "1")
			{
				double y = Slenkstine_func(aktivacijos_fun(w, x, i));
				std::cout << "t(" << i << "): " << t[i] << " ----------> t_gautas(" << i << "): " << y << "   PAKLAIDA: " << t[i] - y << std::endl;
			}
			else if (funk == "2")
			{
				double y = Sigmoidine_func(aktivacijos_fun(w, x, i));
				std::cout << "t(" << i << "): " << t[i] << " ----------> t_gautas(" << i << "): " << y << "   PAKLAIDA: " << t[i] - y << std::endl;
			}
		}
	}
	

	return 0;
}
