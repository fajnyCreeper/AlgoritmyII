#include <iostream>
#include "Determinant.h"

#define N 3

using namespace std;

int main(void)
{
#if N == 3
	float** matrix = new float* [N];
	matrix[0] = new float[N] { -3, 1, -2 };
	matrix[1] = new float[N] { 2, 2, 1 };
	matrix[2] = new float[N] { -2, 3, -1 };
	std::cout << "Detarminant of matrix: " << Determinant::CalculateDeterminant<float, N>(matrix) << endl;
#endif // N == 3

#if N == 4
	int** matrix = new int* [N];
	matrix[0] = new int[N] { 1, 0, 2, -1 };
	matrix[1] = new int[N] { 3, 0, 0, 5 };
	matrix[2] = new int[N] { 2, 1, 4, -3 };
	matrix[3] = new int[N] { 1, 0, 5, 0 };
	std::cout << "Detarminant of matrix: " << Determinant::CalculateDeterminant<int, N>(matrix) << endl;

#endif // N == 4

	

	for (int i = 0; i < N; i++)
		delete[] matrix[i];
	delete[] matrix;
	return 0;
}
