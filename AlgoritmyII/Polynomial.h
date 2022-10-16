#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Polynomial
{
private:
	vector<double> coefficients;

public:
	Polynomial();
	Polynomial(double);
	Polynomial(double, double);
	Polynomial(double, double, double);
	Polynomial(vector<double>);
	~Polynomial();

	double Get(int);

	int GetDegree();

	double CalculateValue(double);

	Polynomial Add(Polynomial);

	void Print();
};