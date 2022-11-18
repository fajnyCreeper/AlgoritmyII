#include "TransitiveClosure.h"

std::vector<std::vector<bool>> TransitiveClosure::GetByWarshall(std::vector<std::vector<bool>> matrix)
{
	std::vector<std::vector<bool>> result = matrix;

	for (int k = 0; k < matrix.size(); k++)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix.size(); j++)
				result[i][j] = result[i][j] || (result[i][k] && result[k][j]); //Cell on position i, j  is result of: matrix[i,j] OR (matrix[i,k] AND matrix[k,j])
		}
	}

	return result;
}