#pragma once
#include <iostream>

class Determinant
{
public:
	template <class T, size_t size>
	static void DuplicateArray(T*, T*&);

	template <class T, size_t size>
	static float CalculateDeterminant(T** matrix);
};

template<class T, size_t size>
static void Determinant::DuplicateArray(T* elements, T*& elementsOutput)
{
	for (unsigned int i = 0; i < size; i++)
		elementsOutput[i] = elements[i];
}

template <class T, size_t size>
static float Determinant::CalculateDeterminant(T** matrixO)
{
	T** matrix = new T* [size];

	for (int i = 0; i < size; i++)
	{
		matrix[i] = new T[size];
		Determinant::DuplicateArray<T, size>(matrixO[i], matrix[i]);
	}


	T n1, n2, det = 1, total = 1;
	T* tempRow =  new T [size + 1];

	int index;
	
	//Loop for traversing diagonal elements
	for (int i = 0; i < size; i++)
	{
		index = i;

		//Finding index with non-zero value
		while (index < size && matrix[index][i] == 0)
			index++;

		//If non-zero element is found, 
		if (index == size)
			continue;

		if (index != i)
		{
			//Swapping diagonal row and index row
			for (int j = 0; j < size; j++)
				std::swap(matrix[index][j], matrix[i][j]);

			//When swapping row, determinant sign is changed
			det *= (T)pow(-1, index - i);
		}

		//Temporary store for diagonal row
		for (int j = 0; j < size; j++)
			tempRow[j] = matrix[i][j];

		//Go through every row below the diagonal
		for (int j = i + 1; j < size; j++)
		{
			n1 = tempRow[i];	//Value of diagonal element
			n2 = matrix[j][i];	//Value of next row element

			//Going through every column of row and creating 0 below diagonal
			for (int k = 0; k < size; k++)
				matrix[j][k] = (n1 * matrix[j][k]) - (n2 * tempRow[k]);

			total *= n1;	//det(kA) = k det(A)
		}
	}

	//Calculate determinant from diagonal elements
	for (int i = 0; i < size; i++)
		det *= matrix[i][i];

	delete[] tempRow;
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;

	return (det / total); // det(kA)/k = det(A)
}