#include "CountingSort.h"
#include <algorithm>


vector<int> CountingSort::DistributionCountingSort(vector<int> input)
{
	//Get minimum and maximum element from vector, save it to pair
	pair<vector<int>::iterator, vector<int>::iterator> minmax_it = std::minmax_element(input.begin(), input.end());
	int min = *minmax_it.first;
	int max = *minmax_it.second;

	int m = max - min + 1;
	std::vector<int> count(m, 0);
	std::vector<int> result(input.size(), 0);
	
	for (int i = 0; i < input.size(); i++)
		count[input[i] - min]++;				//Count index is determined by the value of input vector on index I minus minimum value of vector

	for (int i = 1; i < m; i++)
		count[i] += count[i - 1];				//Starting from I=1, we add to every index value from index I-1

	for (int i = input.size() - 1; i >= 0; i--)
	{
		int j = input[i] - min;					//Index J is value on index I minus minimum value
		result[count[j] - 1] = input[i];		//Place input value on index I to result vector on index determided by value of count vector on index J, minus 1
		count[j]--;								//Decrease value of count vector on index J by one
	}

	return result;
}