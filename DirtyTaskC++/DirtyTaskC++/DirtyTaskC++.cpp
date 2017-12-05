// DirtyTaskC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int const MAX_NUMBER = 1000;
//The twin primes in [1, 1000] are 35.

//short const TWIN_PRIMES_SIZE = 2;

bool isPrime(int numberToCheck);

int main()
{
	cout << "Enter an integer: \n";
	int integerX = 0;
	cin >> integerX;
	cout << "And now enter a real number: \n";
	double realK = 0;
	cin >> realK;

	//int twinPrimes[TWIN_PRIMES_SIZE] = { 0 };

	for (int i = 2; i < 1000;)
	{
		if (isPrime(i) && isPrime(i + 2))
		{
			cout << "(" << i << "," << i + 2 << ") ";
			i += 2;
		}
		else
		{
			i++;
		}
	}

	return 0;
}

bool isPrime(int numberToCheck)
{
	bool isPrime = true;

	for (int j = 2; j <= numberToCheck - 1 && isPrime; j++)
	{
		if (numberToCheck % j == 0)
		{
			isPrime = false;
		}
	}

	return isPrime;
}