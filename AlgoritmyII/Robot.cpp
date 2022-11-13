#include <algorithm>
#include <iostream>
#include "Robot.h"

Robot::Robot(int sizeX, int sizeY)
{
	std::vector<int> line(sizeX, 0);
	std::vector<std::vector<int>> board(sizeY, line);

	this->board = board;
}

void Robot::ResetBoard()
{
	std::vector<int> line(board[0].size(), 0);
	std::vector<std::vector<int>> board(board.size(), line);

	this->board = board;
}

void Robot::SolveCoinCollectionProblem(std::vector<std::vector<int>> coinMatrix)
{
	board[0][0] = coinMatrix[0][0];															//Initialize first cell
	for (int i = 1; i < board[0].size(); i++)												//Traverse first row
		board[0][i] = board[0][i - 1] + coinMatrix[0][i];									//Value of cell is value of cell on the left plus value of coin matrix on current coordinates

	for (int i = 1; i < board.size(); i++)													//Traverse rest of the rows
	{
		board[i][0] = board[i - 1][0] + coinMatrix[i][0];									//Value of first cell is value of first cell on row above plus value of coin matrix on current coordinates
		for (int j = 1; j < board[i].size(); j++)											//Traverse rest of the columns
			board[i][j] = std::max(board[i - 1][j], board[i][j - 1]) + coinMatrix[i][j];	//Value of cell is the greater value of either cell on left, or cell above; plus value of coin matrix on current coordinates
	}
}

void Robot::PrintBoard()
{
	int x, y;
	x = board[0].size() - 1;
	y = board.size() - 1;

	std::vector<int> line(x + 1, 0);
	std::vector<std::vector<int>> path(y + 1, line);										//Initialize path matrix
	path[y][x] = 1;																			//Set current position 

	while (x > 0 || y > 0)
	{
		if (x == 0)																			//If we reached first column, move up
		{
			path[--y][x] = 1;
			continue;
		}
		else if (y == 0)																	//If we reached first row, move right
		{
			path[y][--x] = 1;
			continue;
		}

		if (board[y - 1][x] >= board[y][x - 1])												//If value above is greater than or same as (when two equal paths exists) value on the left move up
			path[--y][x] = 1;							
		else																				//Else move left
			path[y][--x] = 1;
	}

	for (auto i : path)
	{
		for (auto j : i)
			std::cout << (j == 1 ? 'x' : ' ') << ' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
