// SomeFunctions.cpp : Defines the entry point for the console application.
// Program for searching twin primes.

#include "stdafx.h"
#include <iostream>

using namespace std;

bool isTwinPrime(int a, int b);
bool isPrime(int numToCheck);
bool absDiffIsTwo(int a, int b);

int main()
{
	cout << "Enter two numbers to check if they are twin prime: ";
	int a = 0, b = 0;
	cin >> a >> b;

	bool result = isTwinPrime(a, b);
	if (a <= 2 || b <= 2)
	{
		cout << "No\n";
		return 0;
	}

	if (result && absDiffIsTwo(a, b))
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}

    return 0;
}

bool isTwinPrime(int a, int b)
{
	bool result = false;

	if (isPrime(a) && isPrime(b))
	{
		result = true;
	}

	return result;
}

bool isPrime(int numToCheck)
{
	bool prime = true;

	for (int i = 2; i < numToCheck && prime; i++)
	{
		if (numToCheck % i == 0)
		{
			prime = false;
		}
	}

	return prime;
}

bool absDiffIsTwo(int a, int b)
{
	bool isAbsDiffTwo = false;

	int result = a - b;
	result = result < 0 ? result * (-1) : result;
	
	if (result == 2)
	{
		isAbsDiffTwo = true;
	}

	return isAbsDiffTwo;
}