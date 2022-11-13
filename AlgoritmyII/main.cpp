#include <iostream>
#include <vector>
#include <algorithm>
#include "Robot.h"

using namespace std;

int main(void)
{
	vector<vector<vector<int>>> coinMatrixes = {
		{
			{ 0, 0, 1 },
			{ 0, 0, 1 },
			{ 1, 1, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 1, 1, 0, 1 },
			{ 1, 1, 1, 1}
		},
		{
			{ 1, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 1 }
		}
	};

	vector<Robot> robots;

	int x, y;
	for (int i = 0; i < coinMatrixes.size(); i++)
	{
		x = coinMatrixes[i][0].size();
		y = coinMatrixes[i].size();
		robots.push_back(Robot(x, y));

		cout << "Robot no. " << i + 1 << endl;
		cout << "Matrix size: " << x << " columns, " << y << " rows" << endl;

		robots[i].SolveCoinCollectionProblem(coinMatrixes[i]);
		robots[i].PrintBoard();
		cout << endl;
	}

	return 0;
}