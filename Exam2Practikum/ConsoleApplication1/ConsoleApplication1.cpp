// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 1000;

void transpose(int matrix[][SIZE], int rows, int colls);


int main()
{
	cout << "Enter 2 sizes of a matrix - rows and columns (rows _whitespace_ columns):\n";
	int rows = 0, colls = 0;
	cin >> rows >> colls;

	int matrix[SIZE][SIZE] = { 0 };

	cout << "Now enter the matrix:\n";
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < colls; c++)
		{
			cin >> matrix[r][c];
		}
	}

	transpose(matrix, rows, colls);

    return 0;
}

void transpose(int matrix[][SIZE], int rows, int colls)
{
	int matrixT[SIZE][SIZE] = { 0 };

	for (int c = 0; c < colls; c++)
	{
		for (int r = 0; r < rows; r++)
		{
			matrixT[rows][colls] = matrix[rows][colls];
		}
	}

	for (int c = 0; c < colls; c++)
	{
		for (int r = 0; r < rows; r++)
		{
			cin >> matrixT[r][c];
		}
	}
}