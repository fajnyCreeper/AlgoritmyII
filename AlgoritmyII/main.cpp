#include <iostream>
#include <vector>
#include "CountingSort.h"
#include "FileManager.h"

using namespace std;

static void printPair(vector<int> first, vector<int> second)
{
	for (auto i : first)
		cout << i << ",";
	cout << endl;

	for (auto i : second)
		cout << i << ",";
	cout << endl << endl;
}

int main(void)
{
	CountingSort sort;
	
	FileManager fileManager;
	cout << "Loading file..." << endl;
	vector<char> content = fileManager.GetDataFromFile("Ecoli.txt");
	cout << "File loaded, sorting..." << endl;
	vector<char> sortedContent = sort.ComparisonCountingSort<char>(content);
	cout << "Sorted, writing to file:" << endl;
	if (fileManager.SaveDataToFile("Sorted.txt", sortedContent))
		cout << "Saved successfuly!" << endl;
	else
		cout << "There was error saving the file!";

	srand(time(0));
	vector<vector<int>> tests(3), sortedTests(3);	//Create two vectors, that have three vectors inside of them each
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5 * i + 50; j++)
			tests[i].push_back(rand() % 100);
	}

	for (int i = 0; i < 3; i++)
	{
		sortedTests[i] = sort.DistributionCountingSort(tests[i]);
		cout << "Printing vector no. " << i + 1 << ":" << endl;
		printPair(tests[i], sortedTests[i]);
	}

	return 0;
}