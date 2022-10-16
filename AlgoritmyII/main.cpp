#include <iostream>

#include "Polynomial.h"

int main(void)
{
	Polynomial p = Polynomial({4, 5, -1, 7, 0, 3});
	cout << "Polynomial P: ";
	p.Print();
	cout << "Degree of P: " << p.GetDegree() << endl;
	cout << "Value of P(5): " << p.CalculateValue(5) << endl;

	cout << endl;
	Polynomial q = Polynomial({ -3, 1, 0, -1, 0, 0, 4 });
	cout << "Polynomial Q: ";
	q.Print();

	cout << endl;
	Polynomial r = p.Add(q);
	cout << "Polynomial R: ";
	r.Print();

	cout << endl;
	Polynomial c = Polynomial();
	cout << "Polynomial C: ";
	c.Print();

	return 0;
}