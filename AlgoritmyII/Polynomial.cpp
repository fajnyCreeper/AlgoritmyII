#include "Polynomial.h"

Polynomial::Polynomial() : Polynomial(0)
{}

Polynomial::Polynomial(double a0)
{
	this->coefficients.push_back(a0);
}

Polynomial::Polynomial(double a0, double a1)
{
	this->coefficients.push_back(a0);
	this->coefficients.push_back(a1);
}

Polynomial::Polynomial(double a0, double a1, double a2)
{
	this->coefficients.push_back(a0);
	this->coefficients.push_back(a1);
	this->coefficients.push_back(a2);
}

Polynomial::Polynomial(vector<double> coefficients)
{
	this->coefficients = coefficients;
}

Polynomial::~Polynomial()
{
	this->coefficients.clear();
}

double Polynomial::Get(int degree)
{
	//Check, if degree is lower than size, else return 0
	return degree < this->coefficients.size() ? this->coefficients[degree] : 0;
}

int Polynomial::GetDegree()
{
	//Degree = vector size - 1
	return this->coefficients.size() - 1;
}

double Polynomial::CalculateValue(double x0)
{
	//Initiate first value
	double result = this->coefficients[this->GetDegree()];

	//Calculate the result using Horner's method
	for (int i = this->GetDegree() - 1; i >= 0; i--)
	{
		result = result * x0 + this->coefficients[i];
	}

	return result;
}

Polynomial Polynomial::Add(Polynomial other)
{
	//Get highest degree from both polynoms
	int highest_degree = this->GetDegree() > other.GetDegree() ? this->GetDegree() : other.GetDegree();
	vector<double> combined;

	//Combine the polynom values into one vector
	for (int i = 0; i <= highest_degree; i++)
	{
		combined.push_back(this->Get(i) + other.Get(i));
	}

	//Create new polynom with combined vector and return it
	return Polynomial(combined);

}

void Polynomial::Print()
{
	for (int i = this->coefficients.size() - 1; i > 0; i--)
	{
		//Skip coefficients with zero value
		if (this->coefficients[i] == 0)
			continue;
		
		//Don't use x^i output if coefficient index is 1
		cout << this->coefficients[i];
		if (i == 1)
			cout << "x" << " + ";
		else
			cout << "x^" << i << " + ";

	}

	//Print last element as number only
	cout << this->coefficients[0] << endl;
}