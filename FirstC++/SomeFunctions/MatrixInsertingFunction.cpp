#include "stdafx.h"
#include <iostream>

using namespace std;

int const MAX_ARR_SIZE = 100;
void printMatrix(int rows, int cols);

int main()
{
	cout << "Enter rows and columns of the matrix in format: row col  ";
	int rows = 1, cols = 1;
	cin >> rows >> cols;

	printMatrix(rows, cols);

	return 0;
}

void printMatrix(int rows, int cols)
{
	int matrix[MAX_ARR_SIZE][MAX_ARR_SIZE] = { 0 };
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (i == j)
			{
				matrix[i][j] = i;
			}
			else if (j - i > 0)
			{
				matrix[i][j] = j - i;
			}
			else
			{
				matrix[i][j] = i * j;
			}
		}
	}

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}