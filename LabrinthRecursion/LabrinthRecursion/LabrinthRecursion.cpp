// LabrinthRecursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

short const SIZE = 5;
bool labrinth[SIZE][SIZE] = { { 1, 1, 0, 1, 1 },
							  { 0, 1, 1, 1, 0 },
							  { 0, 0, 1, 0, 0 },
							  { 0, 0, 1, 0, 1 },
							  { 0, 0, 1, 1, 1 }, };

bool doYouKnowDaWae(short startX, int startY, short endX, short endY);
void printMaze(bool Maze[][SIZE]);
bool correctIndxes(int x, int y);

int main()
{
	bool result = false;
	printMaze(labrinth);
	result = doYouKnowDaWae(0, 0, 0, 4);
	cout << result << endl;
	return 0;
}

void printMaze(bool Maze[][SIZE])
{
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			cout << Maze[row][col] << " ";
		}
		cout << endl;
	}
}

bool doYouKnowDaWae(short startX, int startY, short endX, short endY)
{
	bool result = false;

	if ((labrinth[startX][startY] == 0) || (labrinth[endX][endY] == 0))
	{
		return false;
	}
	if ((startX < 0 || startX >= SIZE) || (startY < 0 || startY >= SIZE))
	{
		return false;
	}
	if (&labrinth[startX][startY] == &labrinth[endX][endY])
	{
		return true;
	}

	//with only one way - without wrong paths and returning back
	//return doYouKnowDaWae(startX + 1, startY, endX, endY) || doYouKnowDaWae(startX, startY + 1, endX, endY) || doYouKnowDaWae(startX - 1, startY, endX, endY) || doYouKnowDaWae(startX, startY - 1, endX, endY);

	bool leftTurn = false, rightTurn = false, upTurn = false, downTurn = false;

	labrinth[startX][startY] = 0;//making current position as inaccessible
	if (correctIndxes(startX + 1, startY) && labrinth[startX + 1][startY] == 1)
	{
		downTurn = doYouKnowDaWae(startX + 1, startY, endX, endY);
	}
	if (correctIndxes(startX - 1, startY) && labrinth[startX - 1][startY] == 1)
	{
		upTurn = doYouKnowDaWae(startX - 1, startY, endX, endY);
	}
	if (correctIndxes(startX, startY + 1) && labrinth[startX][startY + 1] == 1)
	{
		rightTurn = doYouKnowDaWae(startX, startY + 1, endX, endY);
	}
	if (correctIndxes(startX, startY - 1) && labrinth[startX][startY - 1] == 1)
	{
		leftTurn = doYouKnowDaWae(startX, startY - 1, endX, endY);
	}
	labrinth[startX][startY] = 1;//returning initial value
	return leftTurn || rightTurn || upTurn || downTurn;
}

bool correctIndxes(int x, int y)
{
	if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
	{
		return false;
	}
	return true;
}