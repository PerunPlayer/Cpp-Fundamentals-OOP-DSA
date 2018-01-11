// Recurion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const short SIZE = 4;

int fib(int searched);
bool checkIfExist(int searched, int* sequence, short i, short sequenceLenght);
bool containsDifferent(int* sequence, short SIZE, short count);

//int main()
//{
//	//Task 1
//	int searched;
//
//	do
//	{
//		cout << "Which Fibonacci number you want? ";
//		cin >> searched;
//	} while (searched <= 0);
//
//	cout << fib(searched) << endl;
//
//	//Task 2
//	cout << "Enter number to search? ";
//	cin >> searched;
//	int sequence[20] = { 0 };
//	for (short i = 0; i < 20; i++)
//	{
//		sequence[i] = i + 1;
//	}
//
//	short index = 0;
//	bool result = checkIfExist(searched, sequence, index, 20);
//	if (result)
//		cout << "Yes\n";
//	else
//		cout << "No\n";
//
//	//Task 3
//	int seq1[SIZE] = { 1, 2, 3, 4 };
//	int seq2[SIZE] = { 2, 3, 4, 4 };
//
//	short count = 0;
//	bool result2 = containsDifferent(seq1, SIZE, count);
//	//result = containsDifferent(seq2);
//	if (result)
//		cout << "Yes\n";
//	else
//		cout << "No\n";
//
//    return 0;
//}

//So dumb, yes I know. 
//TODO: Fix this!
int fib(int searched)
{
	if (searched == 1 || searched == 2)
	{
		return 1;
	}
	return fib(searched - 1) + fib(searched - 2);
}

bool checkIfExist(int searched, int* sequence, short i, short sequenceLenght)
{
	if (searched == sequence[i])
	{
		return 1;
	}
	if (i == sequenceLenght - 1 && searched != sequence[i])
	{
		return 0;
	}

	return checkIfExist(searched, sequence, i + 1, sequenceLenght);
}

bool containsDifferent(int* sequence, short SIZE, short count)
{
	if (count == SIZE)
	{
		return 1;
	}
	for (short i = 0; i < SIZE; i++)
	{
		for (short j = i + 1; j < SIZE; j++)
		{
			if (&sequence[i] == &sequence[j])
			{
				return 0;
			}
		}
	}

	return containsDifferent(sequence + 1, SIZE, ++count);
}