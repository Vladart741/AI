#pragma once
#include<vector>
#include<iostream>

#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

double w_naujas_slenkstine(std::vector<double>w, std::vector<std::vector<double>>x, int nr, int i, std::vector<double>t);
double w_naujas_sigmoidine(std::vector<double>w, std::vector<std::vector<double>>x, int nr, int i, std::vector<double>t);
double aktivacijos_fun(std::vector<double> w, std::vector<std::vector<double>>x, int j);
double Slenkstine_func(double a);
double Sigmoidine_func(double a);
double randomNum();
double t_AND(std::vector<double>x,std::string funk);
double t_AND_OR(std::vector<double>x, std::string funk);
std::vector<double> w_pildymas(int j);
std::vector<std::vector<double>> x_pildymas(std::vector<std::vector<double>>x, std::string n, int kiek);
std::vector<double> t_pildymas(std::vector<std::vector<double>>x, std::string n, int kiek, std::string funk);

std::vector<double> mokymas(std::vector<double> w, std::vector<std::vector<double>>x, std::vector<double>t, std::string funk);

#endif //FUNKCIJOS_H