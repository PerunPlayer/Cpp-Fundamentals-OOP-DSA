// Exam2Practikum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 1000;
const int SIZE_T = 100;

int searchingDigit(int wanted, int number, int counter);
int countWords(const char* sequence, int wordSize);
void transpose(int matrix[][SIZE_T], int rows, int colls);

int main()
{
	//Task 1
	cout << "Enter number and digit to search\nNumber: ";
	int number = 0;
	cin >> number;
	cout << "Digit: ";
	short digit = 0;
	cin >> digit;

	int counter = searchingDigit(digit, number, 0);
	cout << "The count is: " << counter << endl;

	//Task 2
	cout << "Enter a phrase:\n";
	char sequence[SIZE] = { 0 };
	cin.getline(sequence, SIZE);
	cin.getline(sequence, SIZE);

	cout << "Enter a number:\n";
	int wordSize = 0;
	cin >> wordSize;

	int words = countWords(sequence, wordSize);
	cout << "Count of passed words: " << words << endl;

	//Task 3
	cout << "Enter 2 sizes of a matrix - rows and columns (rows _whitespace_ columns):\n";
	int rows = 0, colls = 0;
	cin >> rows;
	cin >> colls;

	int matrix[SIZE_T][SIZE_T] = { 0 };

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

int searchingDigit(int wanted, int number, int counter)
{
	if (!number)
	{
		return counter;
	}

	short lastDigit = number % 10;
	if (lastDigit == wanted)
	{
		counter++;
	}
	number = number / 10;

	searchingDigit(wanted, number, counter);
}

int countWords(const char* sequence, int wordSize)
{
	int counter = 0;


	for (int i = 0; i < SIZE; i++)
	{
		if (sequence[i] == '\0')
		{
			break;
		}
		if (sequence[i] == ' ' && i < wordSize)
		{
			counter++;
			break;
		}
	}

	for (int i = 0; i < SIZE, sequence[i] != '\0'; i++)
	{
		if (((sequence[i] >= 'a' && sequence[i] <= 'z') || (sequence[i] >= 'A' && sequence[i] <= 'Z'))
			&& sequence[i - 1] == ' ')
		{
			for (int j = i; j < SIZE; j++)
			{
				if (sequence[j] == ' ' || sequence[j] == '\0')
				{
					if (j - i < wordSize)
					{
						counter++;
					}
					break;
				}
			}
		}
	}

	return counter;
}

void transpose(int matrix[][SIZE_T], int rows, int colls)
{
	int matrixT[SIZE_T][SIZE_T] = { 0 };

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < colls; c++)
		{
			matrixT[c][r] = matrix[r][c];
		}
	}

	for (int c = 0; c < colls; c++)
	{
		for (int r = 0; r < rows; r++)
		{
			cout << matrixT[c][r] << " ";
		}
		cout << endl;
	}
}