// Homework2Praktikum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int SIZE = 100;

void task1();
void task2();
void task3();
void task4();
void lobbyFunc();
int reverse(int number);
int findBiggestPossible(int number);
void quickSort(int *arr, int startIndex, int endIndex);
void swapFunc(int* a, int* b);
void swapCh(char& a, char& b);
int partition(int *arr, int startIndex, int endIndex);
bool containsChar(char *set, int setIndex, char ch);
void sortAlphabetical(char *set, int setIndex, int startIndex);
char* containsSubsequence(char *sequence, char *subSequence, bool *isSubseq);
int* findLastPowerOf2(int *intArr, int arrSize);
void reset(int* p, int *intArr, int arrSize);
void twoDimensionalSort(int matrix[][SIZE], int rows, int cols);

int main()
{
	lobbyFunc();

	return 0;
}

void lobbyFunc()
{
	string message = "Task 1: Reversing of number and finding the biggest possible number with the same digits.\nTask 2: Finding different symbols in sequence, check for subsequence\nTask 3: Find and replace elements in array\nTask 4: Sort two-dimensional array\n";
	string choice = "Enter number from 1 to 4 to open this task or enter 0 to exit:\n";
	char input = 0;

	do
	{
		cout << message;
		cout << choice;

		cin >> input;

		switch (input)
		{
		case '0': return;
			break;
		case '1': task1();
			break;
		case '2': task2();
			break;
		case '3': task3();
			break;
		case '4': task4();
			break;
		default: cout << "Incorrect parameters!\n";
			break;
		}
	} while (input < '0' || input > '4');
}

void task1()
{
	cout << "Enter a number: ";
	int number = 0;
	cin >> number;

	cout << "Reversed number: ";
	int reversed = reverse(number);
	cout << reversed << endl;

	int biggestPossible = findBiggestPossible(number);
	cout << "Biggest possible number with these digits is: " << biggestPossible << endl << endl;

	lobbyFunc();

	return;
}

void task2()
{
	char sequence[SIZE] = { 0 };
	cout << "Enter a sequence:\n";
	cin.getline(sequence, SIZE);
	cin.getline(sequence, SIZE);


	char set[SIZE] = { 0 };
	int setIndex = 0;
	char ch = '0';
	for (int i = 0; i < SIZE; i++)
	{
		if ((sequence[i] >= 65 && sequence[i] <= 90) || sequence[i] >= 97 && sequence[i] <= 122)
		{
			ch = sequence[i];
			ch = tolower(ch);
		}

		if (sequence[i] == '\0')
		{
			break;
		}

		if (!containsChar(set, setIndex, ch))
		{
			set[setIndex] = ch;
			setIndex++;
		}
	}

	sortAlphabetical(set, setIndex, 0);

	for (int i = 0; i <= setIndex; i++)
	{
		cout << set[i];
	}
	cout << " " << setIndex << " symbols" << endl;

	cout << "Enter second sequence to check does the first sequence contain the second one:\n";
	char subSequence[SIZE] = { 0 };
	cin.getline(subSequence, SIZE);

	bool isSubseq = false;
	char *p = containsSubsequence(sequence, subSequence, &isSubseq);
	if (isSubseq)
	{
		cout << "Address of the start of subsequence is: " << &p << endl << endl;
	}
	else
	{
		cout << "This is not in the subsequence.\n\n";
	}

	lobbyFunc();

	return;
}

void task3()
{
	cout << "Enter size of integer array (max 100): ";
	int arrSize = 0;
	cin >> arrSize;
	cout << "Now enter " << arrSize << " elements in the array (separated by whitespaces): ";
	int intArr[SIZE] = { 0 };
	for (int i = 0; i < arrSize; i++)
	{
		cin >> intArr[i];
	}

	int *p = findLastPowerOf2(intArr, arrSize);	//finds address of last element, that is power of 2: 2/4/8/16/.../2048/...

	if (p == NULL)
	{
		cout << "There's not element that is power of 2.\n";
		lobbyFunc();
	}
	else
	{
		cout << p << "     ";

		reset(p, intArr, arrSize);
		for (int i = 0; i < arrSize; i++)
		{
			cout << intArr[i] << " ";
		}
		cout << endl;

		lobbyFunc();
	}

	return;
}

void task4()
{
	int matrix[SIZE][SIZE] = { 0 };
	int rows = 0, cols = 0;

	cout << "Enter sizes of two dimensional matrix(rows cols): ";
	cin >> rows >> cols;
	cout << "Now enter the matrix( " << rows * cols << " elements ): ";
	for (short r = 0; r < rows; r++)
	{
		for (short c = 0; c < cols; c++)
		{
			cin >> matrix[r][c];
		}
	}

	twoDimensionalSort(matrix, rows, cols);

	for (short r = 0; r < rows; r++)
	{
		for (short c = 0; c < cols; c++)
		{
			cout << matrix[r][c] << " ";
		}
		cout << endl;
	}

	lobbyFunc();

	return;
}

int reverse(int number)
{
	int reversedNumber = 0, remainder;
	if (number == 0)
	{
		return 0;
	}

	while (number)
	{
		remainder = number % 10;
		if (remainder == 0)		//fixing for case 1000 -> expected output: "0001", not "1"
		{
			cout << "0";
		}
		else
		{
			reversedNumber = reversedNumber * 10 + remainder;
		}
		number /= 10;
	}

	return reversedNumber;
}

int findBiggestPossible(int number)
{
	int arr[SIZE] = { 0 };
	int i = 0;
	while (number)
	{
		arr[i] = number % 10;
		number /= 10;
		i++;
	}

	quickSort(arr, 0, i - 1);

	for (int j = i - 1; j >= 0; j--)
	{
		number = (number * 10) + arr[j];
	}

	return number;
}

//Takes last element as pivot, places the pivot in sorted array, and places all smaller to left and all greater to right
int partition(int *arr, int startIndex, int endIndex)
{
	int pivot = arr[endIndex];
	int i = (startIndex - 1);

	for (int j = startIndex; j < endIndex; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swapFunc(&arr[i], &arr[j]);
		}
	}
	swapFunc(&arr[i + 1], &arr[endIndex]);
	return (i + 1);
}

void quickSort(int *arr, int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int partitioningIndex = partition(arr, startIndex, endIndex);

		quickSort(arr, startIndex, partitioningIndex - 1);
		quickSort(arr, partitioningIndex + 1, endIndex);
	}
}

void swapFunc(int* a, int* b)
{
	short temp = *a;
	*a = *b;
	*b = temp;
	/**a ^= *b;
	*b ^= *a;
	*a ^= *b;*/
	//TODO: Check why doesn't work
}

void swapCh(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

bool containsChar(char *set, int setIndex, char ch)
{
	for (int i = 0; i <= setIndex; i++)
	{
		if (set[i] == ch)
		{
			return 1;
		}
		if (set[i] != ch && i == setIndex)
		{
			return 0;
		}
	}
}

void sortAlphabetical(char *set, int setIndex, int startIndex)
{
	if (startIndex == setIndex - 1)
	{
		return;
	}

	char min = set[startIndex];
	int j = startIndex;
	for (int i = startIndex + 1; i <= setIndex; i++)
	{
		if (set[i] < min && set[i] != '\0')
		{
			min = set[i];
			j = i;
		}
	}

	swapCh(set[startIndex], set[j]);

	sortAlphabetical(set, setIndex, ++startIndex);
}

char* containsSubsequence(char *sequence, char *subSequence, bool *isSubseq)
{
	char *p = &sequence[0];
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (subSequence[j] == sequence[i + j])
			{
				if (j == 0)
				{
					p = &sequence[i];
				}

			}
			
			if (subSequence[j] == '\0')
			{
				*isSubseq = true;
				return p;
			}

			if (sequence[i] == '\0')
			{
				p = NULL;
				return p;
			}

			if (subSequence[j] != sequence[i + j])
			{
				break;
			}
		}
	}
}

int* findLastPowerOf2(int *intArr, int arrSize) //finds last element, that is power of 2: 2/4/8/16/.../2048/...
{
	int *p = NULL;
	for (int i = arrSize - 1; i >= 0; i--)
	{
		if (intArr[i] % 2 == 0)
		{
			p = &intArr[i];
			return p;
		}
	}

	return p;
}

void reset(int* p, int *intArr, int arrSize)
{
	for (int i = arrSize; &intArr[i] >= p; i--)
	{
		intArr[i] = 0;
	}
}

void twoDimensionalSort(int matrix[][SIZE], int rows, int cols)
{
	for (short r = 0; r < rows; r++)
	{
		quickSort(matrix[r], 0, cols - 1);
	}
}