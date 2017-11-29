// C++ComboX3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

//int main()
//{
//	////TASK 3
//	//int n;
//	//cout << "Enter a number:\n";
//	//cin >> n;
//	//cout << "Now enter " << n << " integers and I'll show you the smallest of them:\n";
//
//	//int theSmallest = std::numeric_limits<int>::max();
//	//for (int i = 0; i < n; i++)
//	//{
//	//	int newInt;
//	//	cin >> newInt;
//	//	theSmallest = newInt < theSmallest ? newInt : theSmallest;
//	//}
//
//	//cout << "The smallest integer is: " << theSmallest << endl;
//
//	////TASK 4
//	//cout << "Enter a positive integer: ";
//	//int numToFac;
//	//cin >> numToFac;
//	//int factorial = 1;
//
//	//for (int i = 0; i < numToFac - 1; i++)
//	//{
//	//	factorial *= numToFac - i;
//	//}
//
//	//cout << factorial << endl;
//
//	////TASK 5
//	//cout << "Enter an integer: ";
//	//int numberOfMembers;
//	//cin >> numberOfMembers;
//
//	//for (int i = 1; i <= numberOfMembers; i++)
//	//{
//	//	int member = i * i + 3 * i;
//	//	cout << "Member " << i << " is " << member << endl;
//	//}
//
//	////TASK 6
//	//cout << "Enter a positive integer and two symbols: ";
//	//int rowsAndColls;
//	//char firstSymbol = '*';
//	//char secondSymbol = '-';
//	//cin >> rowsAndColls >> firstSymbol >> secondSymbol;
//
//	//if (rowsAndColls < 1)
//	//{
//	//	cout << "The integer is not positive!\n";
//	//}
//
//	//for (int row = 0; row < rowsAndColls; row++)
//	//{
//	//	for (int coll = 0; coll < rowsAndColls; coll++)
//	//	{
//	//		if (row - coll == 0)
//	//		{
//	//			cout << (char)firstSymbol;
//	//		}
//	//		else
//	//		{
//	//			cout << (char)secondSymbol;
//	//		}
//	//	}
//
//	//	cout << endl;
//
//	//}
//
//
//	//// TASK 7
//
//	//int sum = 0;
//	//cin >> sum;
//
//	//for (int i = 100; i <= 999; i++)
//	//{
//	//	short hundreds = i / 100;
//	//	short dec = (i / 10) % 10;
//	//	short digit = i % 10;
//	//	int currSum = hundreds + dec + digit;
//
//	//	if (currSum == sum)
//	//	{
//	//		cout << i << endl;
//	//	}
//	//}
//
//
//	//// TASK 8
//
//	//int chars = 0;
//	//cin >> chars;
//	//char current = '0';
//	//int counter = 0;
//
//	//for (int i = 0; i < chars; i++)
//	//{
//	//	cin >> current;
//	//	if (current >= 'a' && current <= 'z')
//	//	{
//	//		counter++;
//	//	}
//	//}
//
//	//cout << counter << endl;
//
//	// TASK 9
//
//	int num = 1;
//	int i = 0, r;
//	int globalCounter = 0;
//
//	while (true)
//	{
//		int	arr[64] = { 0 };
//
//		do
//		{
//			r = num % 2;
//			arr[i++] = r;
//			num /= 2;
//		} while (num != 0);
//
//		int countForOnes = 0;
//		int countForZeros = 0;
//
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (arr[j] == 0)
//			{
//				countForZeros++;
//			}
//			else
//			{
//				countForOnes++;
//			}
//		}
//
//		if (countForZeros == countForOnes)
//		{
//			cout << num << endl;
//			globalCounter++;
//		}
//
//		num++;
//		if (globalCounter == 20)
//		{
//			break;
//		}
//	}
//	
//
//	cout << endl;
//
//// TASK 10
//
//
//
//
//return 0;
//}

