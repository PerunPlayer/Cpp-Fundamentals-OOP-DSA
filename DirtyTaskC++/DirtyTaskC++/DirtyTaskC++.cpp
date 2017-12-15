// DirtyTaskC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int const MAX_NUMBER = 1000;
//The twin primes in [1, 1000] are 35.

bool isPrime(int numberToCheck);
int getDigitsSum(int input);
bool sumFilter(int numberToCheck, int integerX);
int twinPrimePowTwo(int firstNumber, int secondNumber);

int main()
{
	//cout << "Enter an integer: \n";
	int integerX = 0;
	//cin >> integerX;
	//cout << "And now enter a real number: \n";
	double realK = 0;
	cin >> integerX >> realK;

	vector<int> primes;

	for (int i = 2; i < MAX_NUMBER;)
	{
		if (isPrime(i) && isPrime(i + 2))
		{
			primes.push_back(i);
			primes.push_back(i + 2);
			i += 2;
		}
		else
		{
			i++;
		}
	}

	vector<int> filteredTwinPrimes;
	for (short i = 0; i < primes.size(); i += 2)
	{
		if (sumFilter(primes[i], integerX) || sumFilter(primes[i + 1], integerX))
		{
			filteredTwinPrimes.push_back(primes[i]);
			filteredTwinPrimes.push_back(primes[i + 1]);
		}
	}

	int sumOfFiltered = 0;
	for (short i = 0; i < filteredTwinPrimes.size(); i++)
	{
		sumOfFiltered += filteredTwinPrimes[i];
	}
	double averageSumOfFiltered = sumOfFiltered / (filteredTwinPrimes.size() / 2);

	bool passSecondFiltration = true;
	for (short i = 0; i < filteredTwinPrimes.size() && passSecondFiltration; i += 2)
	{
		int sum = twinPrimePowTwo(filteredTwinPrimes[i], filteredTwinPrimes[i + 1]);
		if (sum >= averageSumOfFiltered / realK)
		{
			passSecondFiltration = false;
		}
	}

	cout << passSecondFiltration;
	//for (int i = 0, j = 0; i < filteredTwinPrimes.size() - 1; i++)
	//{
	//	if (filteredTwinPrimes.at(i + 1) - filteredTwinPrimes.at(i) == 2)
	//	{
	//		cout << ++j << " (" << filteredTwinPrimes.at(i) << ", " << filteredTwinPrimes.at(i + 1) << ")" << endl;
	//	}
	//}

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

int getDigitsSum(int input)
{
	int sum = 0;
	while (input > 0)
	{
		sum += input % 10;
		input /= 10;
	}
	return sum;
}

bool sumFilter(int numberToCheck, int integerX)
{
	bool result = false;
	double sumOfDigits = getDigitsSum(numberToCheck);
	double magicVar = sumOfDigits / integerX;
	
	//Max number of digits in this case is 3. So I need only the second digit.
	if (numberToCheck >= 10 && (numberToCheck / 10) % 10 < magicVar)
	{
		result = true;
	}

	return result;
}

int twinPrimePowTwo(int firstNumber, int secondNumber)
{
	int result = (firstNumber * firstNumber) + (secondNumber * secondNumber);
	return result;
}