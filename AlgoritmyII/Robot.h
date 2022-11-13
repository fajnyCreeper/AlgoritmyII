#pragma once
#include <vector>

class Robot
{
private:
	std::vector<std::vector<int>> board;

	void ResetBoard();

public:
	Robot(int, int);
	void SolveCoinCollectionProblem(std::vector<std::vector<int>>);
	void PrintBoard();
};