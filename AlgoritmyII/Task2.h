#pragma once
#include "Equation.h"
#include "Components.h"

class Task2
{
private:
	Equation equation;
	int* P;
	
public:
	template<size_t rows, size_t cols>
	void CreateEquation(float matrixA[rows][cols], int, float elementsB[rows]);

	Equation GetEquation();

	float** DecompositionLU(Equation);
	float* DecompositionSolving(Equation, float**);
};

template<size_t rows, size_t cols>
void Task2::CreateEquation(float matrixA[rows][cols], int size, float elementsB[rows])
{
	Equation equation;
	equation.size = size;
	equation.matrixA = new float* [equation.size];
	equation.elementsB = new float[equation.size];

	Components<float>::InitializeElements(equation.matrixA, equation.size, equation.size + 1);

	for (unsigned int i = 0; i < equation.size; i++)
	{
		Components<float>::DuplicateArray(matrixA[i], equation.size, equation.matrixA[i]);
	}
	Components<float>::DuplicateArray(elementsB, equation.size, equation.elementsB);

	this->equation = equation;

	Components<float>::PrintMatrix(this->equation);
}