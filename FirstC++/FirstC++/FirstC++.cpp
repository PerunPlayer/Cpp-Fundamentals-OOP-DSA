// FirstC++.cpp : Defines the entry point for the console application.
//


//#define _USE_MATH_DEFINES

#include "stdafx.h"
#include <string>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

void FirstTask();
void SecondTask();
void ThirdTask(); 
void FourthTask(); 
void FifthTask(); 
void SixthTask(); 
void BonusTask();

//int main()
//{
//	short input = 0;
//	cout << "Which one task do you want to execute? (from 1 to 7)\n";
//	cin >> input;
//
//	switch (input)
//	{
//	case 1:
//		FirstTask();
//		break;
//	case 2:
//		SecondTask();
//		break;
//	case 3:
//		ThirdTask();
//		break;
//	case 4:
//		FourthTask();
//		break;
//	case 5:
//		FifthTask();
//		break;
//	case 6:
//		SixthTask();
//		break;
//	case 7:
//		BonusTask();
//		break;
//	default:
//		cout << "Your input is invalid!";
//		break;
//	}
//	// Seventh task
//	return 0;
//}

void FirstTask()
{
	int firstNum1 = 0;
	int firstNum2 = 0;
	int var = 0;
	cout << "Insert two integers: " << endl << "The first integer is: ";
	cin >> firstNum1;
	cout << "The second integer is: ";
	cin >> firstNum2;

	var = firstNum1;
	firstNum1 = firstNum2;
	firstNum2 = var;

	cout << "Now the first is: " << firstNum1 << endl << "And the second is: " << firstNum2 << endl;
}

void SecondTask()
{
	cout << "Second task" << endl;

	cout << "Insert an integer: " << endl;
	int secondNum = 0;
	cin >> secondNum;
	if (secondNum % 10 == 0 && secondNum % 3 == 0)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
}

void ThirdTask()
{
	cout << "Third task" << endl;

	int thirdNum1 = 0;
	int thirdNum2 = 0;
	cout << "Insert two integers: " << endl << "The first integer is: ";
	cin >> thirdNum1;
	cout << "The second integer is: ";
	cin >> thirdNum2;

	if (thirdNum2 % thirdNum1 == 0)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
}

void FourthTask()
{
	cout << "Fourth task" << endl;
	double radius = 0;
	cout << "Insert radius: " << endl;
	cin >> radius;
	/*
	int area = radius * radius * M_PI;
	int circuit = 2 * M_PI * radius;*/

	double area = radius * radius * 3.14159;
	double circuit = 2 * 3.14159 * radius;

	cout << "The area of the circle is " << area << " and the circuit is " << circuit << endl;

}

void FifthTask()
{
	cout << "Insrt threedigit number\n";
	int threedigitNumber = 0;
	cin >> threedigitNumber;

	int hundreds = threedigitNumber / 100;
	cout << hundreds << endl;
	int dec = (threedigitNumber - (hundreds * 100)) / 10;
	cout << dec << endl;
	int digits = (threedigitNumber - (hundreds * 100)) - (dec * 10);
	cout << digits << endl;
	int result = hundreds + dec + digits;
	cout << result << endl;
}

void SixthTask()
{
	int fourdigitNum = 0;
	cout << "Insert a positive fourdigit number\n";
	cin >> fourdigitNum;

	int thousends = fourdigitNum / 1000;
	int hundreds1 = (fourdigitNum - (thousends * 1000)) / 100;
	int dec1 = ((fourdigitNum - (thousends * 1000)) - (hundreds1 * 100)) / 10;
	int digits1 = fourdigitNum % 10;

	if (thousends == hundreds1 || thousends == dec1 ||
		thousends == digits1 || hundreds1 == dec1 ||
		hundreds1 == digits1 || dec1 == digits1)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << 1 << endl;
	}
}

void BonusTask()
{
	const double kelvinsChange = 273.15;
	double farenhait = 0;
	string inputText;
	string messageFirstHalf = "The temperature in ";
	string messageSecondHalf = " is: ";
	string KelvinStr = "kelvins";
	double kelvins;
	string celsiumStr = "celsium";
	double celsium;

	cin >> farenhait;
	cin >> inputText;

	if (inputText == "c")
	{
		celsium = ((farenhait - 32) * 5) / 9;
		cout << messageFirstHalf << celsiumStr << messageSecondHalf << celsium << endl;
	}
	else if (inputText == "k")
	{
		kelvins = farenhait + kelvinsChange;
		cout << messageFirstHalf << KelvinStr << messageSecondHalf << kelvins << endl;
	}
	else if (inputText == "a")
	{
		celsium = ((farenhait - 32) * 5) / 9;
		cout << messageFirstHalf << celsiumStr << messageSecondHalf << celsium << endl;
		kelvins = farenhait + kelvinsChange;
		cout << messageFirstHalf << KelvinStr << messageSecondHalf << kelvins << endl;
	}
	else
	{
		cout << "Your input is invalid!\n";
	}
}