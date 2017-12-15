// Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

void swapingValues(int &a, int &b);
void reverseArr(int *arr, int size);
void fusionArrays(int *arr, int size, int *arr2, int size2, int *arr3, int size3);

int main()
{
	// TASK 0
	cout << "Enter two integers: ";
	int a, b;
	cin >> a >> b;
	swapingValues(a, b);

	cout << "first = " << a << " second = " << b << endl;

	// TASK 1
	int arr[] = { 2, 4, 6, 8, 10, 12 };
	short size = 6;
	for (short i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
	reverseArr(arr, size);
	for (short i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;

	// TASK 2
	int arr1[] = { 2, 4, 6, 8, 10, 12 };
	int arr2[] = { 1, 3, 5, 7, 9, 11 };
	for (short i = 0; i < size; i++)
	{
		cout << *(arr2 + i) << " ";
	}
	cout << endl;

	int arr3[12] = { 0 };
	fusionArrays(arr1, size, arr2, size, arr3, size * 2);
	for (short i = 0; i < size * 2; i++)
	{
		cout << *(arr1 + i) << " ";
	}

    return 0;
}

void swapingValues(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

void reverseArr(int *arr, int size)
{
	for (short i = 0; i < size / 2; i++)
	{
		swapingValues(*(arr + i), *(arr + size - 1 - i));
	}
}

void fusionArrays(int *arr, int size, int *arr2, int size2, int *arr3, int size3)
{
	for (short i = 0; i < size3; i += 2)
	{
		if (*(arr + i) <= *(arr2 + i))
		{
			*(arr3 + i) = *(arr + i);
			*(arr3 + i + 1) = *(arr2 + i);
		}
		else
		{
			*(arr3 + i) = *(arr2 + i);
			*(arr3 + i + 1) = *(arr + i);
		}
	}
}