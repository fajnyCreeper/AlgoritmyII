#pragma once
#include<iostream>
#include<vector>

using namespace std;



class CountingSort
{
public:
	template<class T>
	std::vector<T> ComparisonCountingSort(vector<T>);

	vector<int> DistributionCountingSort(vector<int>);
};

template<class T>
std::vector<T> CountingSort::ComparisonCountingSort(vector<T> input)
{
	std::vector<int> count(input.size(), 0);
	std::vector<T> result(input.size(), 0);

	for (int i = 0; i < input.size() - 1; i++)		//Going through input vector
	{
		for (int j = i + 1; j < input.size(); j++)	//Going through all elements on higher index than I
		{
			if (input[i] < input[j])
				count[j]++;							//If J element is bigger than I element, we increase count vector on J index
			else
				count[i]++;							//Else increase it on I index
		}
	}

	for (int i = 0; i < input.size(); i++)
		result[count[i]] = input[i];				//We read all values from input vector, and place them to output vector on index, that is determined by value on I index from count vector

	return result;
}