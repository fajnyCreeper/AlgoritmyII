#include "Exercise2.h"
#include "Components.h"
#include <cstdlib>

bool Exercise2::ForwardElimination(Equation& equation)
{
	unsigned int n = equation.size - 1;
	float** A = equation.matrixA;
	float* b = equation.elementsB;

	for (unsigned int i = 0; i <= n; i++)
	{
		A[i][n + 1] = b[i];
	}

	for (unsigned int i = 0; i <= n; i++)
	{
		if (A[i][i] == 0)
		{
			std::cout << "Mathematical Error!" << std::endl;
			return false;
		}

		for (unsigned int j = i + 1; j <= n; j++)
		{
			float ratio = A[j][i] / A[i][i];
			for (unsigned int k = i; k <= n + 1; k++)
			{
				A[j][k] = A[j][k] - ratio * A[i][k];
			}
		}
	}

	return true;
}

bool Exercise2::BetterForwardElimination(Equation& equation)
{
	unsigned int n = equation.size - 1;
	float** A = equation.matrixA;
	float* b = equation.elementsB;

	for (unsigned int i = 0; i <= n; i++)
	{
		A[i][n + 1] = b[i];
	}

	for (unsigned int i = 0; i <= n; i++)
	{
		int pivotrow = i;

		for (unsigned int j = i + 1; j <= n; j++)
		{
			if (abs(A[j][i]) > abs(A[pivotrow][i]))
			{
				pivotrow = j;
			}
		}

		if (pivotrow != i)
		{
			for (unsigned int k = 0; k <= n + 1; k++)
			{
				// Debug output
				//std::cout << "i: " << i << " pivotrow: " << pivotrow << std::endl;
				//std::cout << A[i][k] << ':' << A[pivotrow][k] << std::endl;

				Components<float>::SwapValues(A[i][k], A[pivotrow][k]);
			}
		}

		for (unsigned int j = i + 1; j <= n; j++)
		{
			float temp = A[j][i] / A[i][i];
			for (unsigned int k = i; k <= n + 1; k++)
			{
				A[j][k] = A[j][k] - A[i][k] * temp;
			}
		}
	}

	return true;
}

void Exercise2::BackSubstitution(Equation& equation, float*& result)
{
	unsigned int N = equation.size;
	float* X = result;

	float** A = equation.matrixA;

	for (int i = N - 1; i >= 0; i--)
	{
		X[i] = A[i][N];

		for (unsigned int j = i + 1; j < N; j++)
		{
			X[i] -= A[i][j] * X[j];
		}

		X[i] = X[i] / A[i][i];
	}
}
