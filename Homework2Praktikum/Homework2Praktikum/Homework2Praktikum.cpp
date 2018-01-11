// Homework2Praktikum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int reverse(int number);
int findBiggestPossible(int number);
void quickSort(int arr[], int low, int high);
void swap(int* a, int*b);

const int SIZE = 100;

int main()
{
	cout << "Enter a number: ";
	int number = 0;
	cin >> number;

	int reversed = reverse(number);
	cout << "Reversed number: " << reversed << endl;
	
	int biggestPossible = findBiggestPossible(number);
	cout << "Biggest possible number with these digits is: " << biggestPossible << endl;


    return 0;
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
		reversedNumber = reversedNumber * 10 + remainder;
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

	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);

	return 0;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int partitioningIndex = partition(arr, low, high);

		// Sort elements before and after partition
		quickSort(arr, low, partitioningIndex - 1);
		quickSort(arr, partitioningIndex + 1, high);
	}
}

void swap(int* a, int*b)
{
	*a ^ *b;
	*b ^ *a;
	*a ^ *b;
}