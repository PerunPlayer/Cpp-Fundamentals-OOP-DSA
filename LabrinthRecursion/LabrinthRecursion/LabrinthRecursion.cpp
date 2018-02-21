// LabrinthRecursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

short const SIZE = 5;
bool labrinth[SIZE][SIZE] = { { 1, 1, 0, 1, 1 },
							  { 0, 1, 1, 1, 0 },
							  { 0, 0, 1, 0, 0 },
							  { 0, 0, 1, 0, 1 },
							  { 0, 0, 1, 1, 1 }, };

bool doYouKnowDaWae(short startX, int startY, short endX, short endY);

int main()
{
	bool result = false;
	result = doYouKnowDaWae(0, 0, 0, 4);
	std::cout << result << std::endl;
    return 0;
}

bool doYouKnowDaWae(short startX, int startY, short endX, short endY)
{
	bool result = false;

	if (labrinth[startX][startY] == 0)
	{
		return false;
	}
	if (labrinth[endX][endY] == 0)
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
	return doYouKnowDaWae(startX + 1, startY, endX, endY) || doYouKnowDaWae(startX, startY + 1, endX, endY) || doYouKnowDaWae(startX - 1, startY, endX, endY) || doYouKnowDaWae(startX, startY - 1, endX, endY);
}