// Pointers.cpp : Defines the entry point for the console application.
// https://github.com/GeorgiMinkov/FMI_IS_UP_2_2017/blob/master/week10/TASKS.md

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

void swapingValues(int &a, int &b);
void reverseArr(int *arr, int size);
void fusionArrays(int *arr, int size, int *arr2, int size2, int *arr3, int size3);
bool isPassingFilter(int n, double *arrayOfReal, int SIZE);

int const SIZE = 10;

int main()
{
	// TASK 0
	cout << "Enter two integers: ";
	int a, b;
	cin >> a >> b;
	swapingValues(a, b);

	cout << "first = " << a << " second = " << b << endl << endl;

	// TASK 1
	int arr[] = { 2, 4, 6, 8, 10, 12 };
	short size = 6;
	cout << "Now I'll reverse an array.\nThe array is:\n";
	for (short i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
	cout << "The reversed array is:\n";
	reverseArr(arr, size);
	for (short i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl << endl;

	// TASK 2
	int arr1[] = { 2, 4, 6, 8, 10, 12 };
	int arr2[] = { 1, 3, 5, 7, 9, 11 };
	cout << "We've got two sorted arrays and I'll make a fusion sorted array.\n";
	for (short i = 0; i < size; i++)
	{
		cout << *(arr2 + i) << " ";
	}
	cout << endl;
	for (short i = 0; i < size; i++)
	{
		cout << *(arr1 + i) << " ";
	}
	cout << endl;

	cout << "There is the fusion array:\n";
	int arr3[12] = { 0 };
	fusionArrays(arr1, size, arr2, size, arr3, size * 2);
	for (short i = 0; i < size * 2; i++)
	{
		cout << *(arr3 + i) << " ";
	}
	cout << endl;

	//TASK 3
	//double arrayOfReal[] = {3.3, 5.0, 4.5, 4.0, 3.5, 3.0};
	int n = 0;
	
	double arrayOfReal[SIZE] = { 0 };
	cout << "Enter 10 real numbers in the array in format: XX.XXX(3.478 2.14158): ";
	for (short i = 0; i < SIZE; i++)
	{
		cin >> arrayOfReal[i];
	}

	bool result = isPassingFilter(n, arrayOfReal, SIZE);
	cout << result;








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
	for (short i = 0, j = 0; i < size; i++, j += 2)
	{
		if (*(arr + i) <= *(arr2 + i))
		{
			*(arr3 + j) = *(arr + i);
			*(arr3 + j + 1) = *(arr2 + i);
		}
		else
		{
			*(arr3 + j) = *(arr2 + i);
			*(arr3 + j + 1) = *(arr + i);
		}
	}
}

bool isPassingFilter(int n, double *arrayOfReal, int SIZE)
{
	bool result = true;
	return result;
}