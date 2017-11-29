#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int const ARR_SIZE = 100;

int main()
{
	cout << "Enter size of the matrix: \n";
	short size = 1;
	cin >> size;
	cout << "Now enter the matrix: \n";

	int matrix[ARR_SIZE][ARR_SIZE] = { 0 };
	for (short i = 0; i < size; i++)
	{
		for (short j = 0; j < size; j++)
		{
			cin >> matrix[i][j];
		}
	}

	bool isSimetric = true;
	short loopSteps = ceil(size / 2.0);
	for (short i = 0; i < loopSteps && isSimetric; i++)
	{
		for (short j = 0; j < loopSteps && isSimetric; j++)
		{
			if (matrix[i][j] != matrix[j][i])
			{
				isSimetric = false;
			}
		}
	}

	if (isSimetric)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}

	return 0;
}