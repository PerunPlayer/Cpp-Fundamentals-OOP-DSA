// DirtyTaskC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int const MAX_NUMBER = 1000;
//The twin primes in [1, 1000] are 35.

short const TWIN_PRIMES_SIZE = 2;

bool isPrime(int numberToCheck);
int twinOfPrimes(int lastPrime);

int main()
{
	cout << "Enter an integer: \n";
	int integerX = 0;
	cin >> integerX;
	cout << "And now enter an real number: \n";
	double realK = 0;
	cin >> realK;

	int lastPrime = 2;
	int nextPrime = nextPrimeNumber(lastPrime);

	int twinPrimes[TWIN_PRIMES_SIZE] = { 0 };
	if (nextPrime - lastPrime == 2)
	{
		twinPrimes[0] = lastPrime;
		twinPrimes[1] = nextPrime;
	}
	else
	{
		lastPrime = nextPrime;
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

int twinOfPrimes(int lastPrime)
{
	int firstPrime = 0;

	return firstPrime;
}