// UP-Praktikum-HW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int numToCheck);
int sumOfDevisors(int number);

int main()
{
	int n, m;
	cin >> n >> m;
	int counterOfWeirdNumbers = 0;

	for (int i = n; i < m; i++)
	{
		int copy = i;
		int sumOfCurrNum = sumOfDevisors(copy);
		if (sumOfCurrNum == 1)
		{
			continue;
		}
		if (isPrime(sumOfCurrNum))
		{
			counterOfWeirdNumbers++;
			//cout << i << " ";
		}
	}

	cout << counterOfWeirdNumbers << endl;

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

int sumOfDevisors(int number)
{
	int sum = 0;
	for (int i = 1; i <= number; i++)
	{
		if (number % i == 0)
		{
			sum += i;
		}
	}

	return sum;
}