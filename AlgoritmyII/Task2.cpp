#include "Task2.h"

Equation Task2::GetEquation()
{
	return this->equation;
}

float** Task2::DecompositionLU(Equation equation)
{
	float** matrixA = equation.matrixA;
	
	int imax, tmp;
	float maxA, absA, *ptr;

	//Permutacni vektor
	//Slozitost O(n)
	P = new int[equation.size];
	for (int i = 0; i < equation.size; i++)
		P[i] = i;

	//Prochazeni radku matice
	//Slozitost O(n^3)?
	for (int i = 0; i < equation.size; i++)
	{
		maxA = 0.0;
		imax = i;

		//Hledame radek s nejvyssimi hodnotami ve sloupci
		for (int j = i; j < equation.size; j++)
		{
			if ((absA = fabs(matrixA[j][i])) > maxA)
			{
				maxA = absA;
				imax = j;
			}
		}

		//Pokud ma radek radek vyssi hodnotu, vymenime hodnoty sloupce a upravime permutacni vektor
		if (imax != i)
		{
			//Vymenime permutacni vektor
			tmp = P[i];
			P[i] = P[imax];
			P[imax] = tmp;

			//Vymenime radky
			ptr = matrixA[i];
			matrixA[i] = matrixA[imax];
			matrixA[imax] = ptr;
		}

		//Vypocitame LU matici
		for (int j = i + 1; j < equation.size; j++)
		{
			matrixA[j][i] /= matrixA[i][i];

			for (int k = i + 1; k < equation.size; k++)
				matrixA[j][k] -= matrixA[j][i] * matrixA[i][k];
		}
	}

	return matrixA;
}

float* Task2::DecompositionSolving(Equation equation, float** matrixLU)
{
	float* elementsLU = new float[equation.size];

	//Zaneseni permutacniho vektoru
	//Slozitost O(n)
	for (int i = 0; i < equation.size; i++)
	{
		elementsLU[i] = equation.elementsB[P[i]];

		for (int j = 0; j < i; j++)
			elementsLU[i] -= matrixLU[i][j] * elementsLU[j];

	}

	//Vypocet vyslednych neznamych
	//Slozitost O(n)
	for (int i = equation.size - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < equation.size; j++)
			elementsLU[i] -= matrixLU[i][j] * elementsLU[j];

		elementsLU[i] /= matrixLU[i][i];
	}


	return elementsLU;
}
