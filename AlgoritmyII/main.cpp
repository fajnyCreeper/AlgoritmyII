#include <iostream>
#include <vector>
#include "TransitiveClosure.h"

using namespace std;

int main(void)
{
	//Vector of matrices
	vector<vector<vector<bool>>> matrices = {
		{
			{0, 1, 0},
			{0, 0, 1},
			{1, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 0, 0, 1},
			{0, 0, 0, 0},
			{1, 0, 1, 0}
		},
		{
			{0, 0, 1, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0},
			{1, 1, 1, 1, 1}
		},
		{
			{0, 0, 1, 0, 0, 0},
			{0, 0, 0, 1, 0, 0},
			{0, 0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{1, 1, 1, 1, 1, 1, 1},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0}
		}
	};

	
	vector<vector<vector<bool>>> calculatedMatrices;	//Create vector for calculated matrices and fill it

	for (int i = 0; i < matrices.size(); i++)
		calculatedMatrices.push_back(TransitiveClosure::GetByWarshall(matrices[i]));

	for (int i = 0; i < matrices.size(); i++)			//Traverse vector of matrices
	{
		cout << "Matrix no. " << i + 1 << endl;
		for (int j = 0; j < matrices[i].size(); j++)	//Traverse rows of single matrix
		{
			for (auto cell : matrices[i][j])			//Traverse cells of single rows and print values
				cout << cell << " ";
			cout << " |  ";
			for (auto cell : calculatedMatrices[i][j])
				cout << cell << " ";
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}