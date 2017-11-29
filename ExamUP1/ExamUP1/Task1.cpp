// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

bool isPerfect(int numberToCheck);

int main()
{
	int a, b;
	cout << "Enter two positive numbers: ";
	cin >> a >> b;

	int counter = 0;

	for (int i = a; i <= b; i++)
	{
		if (isPerfect(i))
		{
			cout << i << endl;
			counter++;
		}
	}

	cout << "All perfect numbers in the interval: " << counter << endl;

    return 0;
}

bool isPerfect(int numberToCheck)
{
	bool result = false;
	int sum = 0;

	for (int i = 1; i < numberToCheck; i++)
	{
		if (numberToCheck % i == 0)
		{
			sum += i;
		}
	}

	if (sum == numberToCheck)
	{
		result = true;
	}

	return result;
}

