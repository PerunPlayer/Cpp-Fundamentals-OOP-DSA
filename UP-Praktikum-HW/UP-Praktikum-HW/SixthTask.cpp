#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int const ARR_SIZE = 100;

int main()
{
	short rows = 0, cols = 0;
	cout << "Enter rows and cols of the matrix separated by space: \n";
	cin >> rows >> cols;
	cout << "Now enter the matrix: \n";

	int matrix[ARR_SIZE][ARR_SIZE] = { 0 };
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << "Now enter number to check: ";
	int numberToCheck = 0;
	cin >> numberToCheck;

	short numberRowIndex = 0, numberColIndex = 0;
	bool isInArray = false;
	for (short i = 0; i < rows && !isInArray; i++)
	{
		for (short j = 0; j < cols && !isInArray; j++)
		{
			if (matrix[i][j] == numberToCheck)
			{
				isInArray = true;
				numberRowIndex = i;
				numberColIndex = j;
			}
		}
	}
	
	short neighbours = 0;
	if (numberRowIndex < rows - 1)
	{
		neighbours++;		//for the one neighbour below
	}
	if (numberRowIndex > 0)
	{
		neighbours++;		//for the one above
	}
	if (numberColIndex < cols - 1)
	{
		neighbours++;		//for the one to the right
	}
	if (numberColIndex > 0)
	{
		neighbours++;		//for the one to the left
	}
	if (numberRowIndex < rows - 1 && numberColIndex < cols - 1)
	{
		neighbours++;		//for the one in corner down right
	}
	if (numberRowIndex < rows - 1 && numberColIndex > 0)
	{
		neighbours++;		//for the one in corner down left
	}
	if (numberRowIndex > 0 && numberColIndex < cols - 1)
	{
		neighbours++;		//for the one in corner up right
	}
	if (numberRowIndex > 0 && numberColIndex > 0)
	{
		neighbours++;		//for the one in corner up left
	}


	if (!isInArray)
	{
		cout << "There is not such an element in the matrix.\n";
		return 0;
	}
	else
	{
		cout << "The number of neighbours of the element you checked: " << neighbours << endl;
	}

	return 0;
}