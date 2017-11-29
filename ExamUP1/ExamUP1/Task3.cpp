#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int numberToCheck);

short const MAX_ARR_SIZE = 100;

int main()
{
	cout << "Enter type of the matrix: (3 - that means 3x3 / 4 - that means 4x4 / ...)  ";
	/*char typeOfMatrix = { 0 };		for 3x3 / 4x4/ ....
	cin >> typeOfMatrix;
	int matrixIndex = typeOfMatrix[0];*/

	short matrixType = 1;
	cin >> matrixType;

	cout << "Now enter the matrix in that format:\n";
	int matrix[MAX_ARR_SIZE][MAX_ARR_SIZE] = { 0 };
	for (short i = 0; i < matrixType; i++)
	{
		for (short j = 0; j < matrixType; j++)
		{
			cin >> matrix[i][j];
		}
	}

	bool prime = true;
	int sumOfPrimary = 0, sumOfSecondary = 0;
	for (short i = 0; i < matrixType && prime; i++)
	{
		for (short j = 0; j < matrixType && prime; j++)
		{
			if (i == j)
			{
				sumOfPrimary += matrix[i][j];
				prime = isPrime(matrix[i][j]) && prime;
			}

			if (i + j == matrixType - 1)
			{
				sumOfSecondary += matrix[i][j];
				prime = isPrime(matrix[i][j]) && prime;
			}
		}
	}

	if (sumOfPrimary == sumOfSecondary && prime)
	{
		cout << "True.\n";
	}
	else
	{
		cout << "False.\n";
	}



	return 0;
}

bool isPrime(int numberToCheck)
{
	bool isPrime = true;

	for (int j = 2; j < numberToCheck && isPrime; j++)
	{
		if (numberToCheck % j == 0)
		{
			isPrime = false;
		}
	}

	return isPrime;
}