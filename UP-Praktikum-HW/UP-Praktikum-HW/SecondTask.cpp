#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;
int const ARR_SIZE = 4;

int main()
{
	/*int fourByFourArr[ARR_SIZE][ARR_SIZE] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};*/

	int fourByFourArr[ARR_SIZE][ARR_SIZE] = { 0 };

	for (short i = 0; i < ARR_SIZE; i++)
	{
		for (short j = 0; j < ARR_SIZE; j++)
		{
			cin >> fourByFourArr[i][j];
		}
	}

	int maxSumRows = 0, maxSumCols = 0, sumOfRow = 0, sumOfCol = 0;

	for (short j = 0; j < ARR_SIZE; j++) //sum of first row
	{
		maxSumRows += fourByFourArr[0][j];
	}

	for (short i = 0; i < ARR_SIZE; i++)  //sum of first col
	{
		maxSumCols += fourByFourArr[i][0];
	}

	for (short i = 1; i < ARR_SIZE; i++)	//max sum of rows
	{
		for (short j = 0; j < ARR_SIZE; j++)
		{
			sumOfRow += fourByFourArr[i][j];
		}
		maxSumRows = maxSumRows < sumOfRow ? sumOfRow : maxSumRows;
		sumOfRow = 0;
	}

	for (short j = 1; j < ARR_SIZE; j++)	//max sum of cols
	{
		for (short i = 0; i < ARR_SIZE; i++)
		{
			sumOfCol += fourByFourArr[i][j];
		}
		maxSumCols = maxSumCols < sumOfCol ? sumOfCol : maxSumCols;
		sumOfCol = 0;
	}

	cout << "Biggest sum from rows: " << maxSumRows << "\nBiggest sum from columns: " << maxSumCols << endl;
	char sign = '=';
	if (maxSumRows < maxSumCols)
	{
		sign = '<';
	}
	if (maxSumRows > maxSumCols)
	{
		sign = '>';
	}
	cout << "Maximum sum from rows is " << sign << " than maximum sum from columns\n";
	return 0;
}