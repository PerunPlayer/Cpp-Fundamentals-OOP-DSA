#include "stdafx.h"
#include <string>
#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main()
{
	//TASK 0
	int number = 0;
	cin >> number;
	if (number % 2 == 0)
	{
		cout << "The number is odd.\n";
	}
	else
	{
		cout << "The number is even.\n";
	}


	//TASK 1
	int year = 0;
	cin >> year;
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				cout << "The year is lean.\n";
			}
			else
			{
				cout << "The year is not lean.\n";
			}
		}
		else
		{
			cout << "The year is lean.\n";
		}
	}
	else
	{
		cout << "The year is not lean.\n";
	}


	//TASK 2
	double a, b, c, x1, x2;
	cout << "Insert indexes of the equalation:\n";
	cin >> a;
	cin >> b;
	cin >> c;
	if (a == 0)
	{
		x1 = -b / 2 * a;
		cout << "x1 = x2 = " << x1 << endl;
	}
	else
	{
		double D = (b * b) - (4 * a * c);
		x1 = (-b + D) / (2 * a);
		x2 = (-b - D) / (2 * a);
		cout << "x1 is " << x1 << " and x2 is " << x2 << endl;
	}
	
	//TASK 3
	double num1, num2, result;
	char operation;

	cout << "Insert two numbers and then operation +,-,*,/ :\n";
	cin >> num1;
	cin >> num2;
	cin >> operation;

	switch (operation)
	{
	case '+':
		result = num1 + num2;
		cout << result << endl;
		break;
	case '-':
		result = num1 - num2;
		cout << result << endl;
		break;
	case '*':
		result = num1 * num2;
		cout << result << endl;
		break;
	case '/':
		result = num1 / num2;
		cout << result << endl;
		break;
	default:
		"You have inserted something that I was not expected.";
		break;
	}

	//TASK 4
	char inputCh;
	cout << "Insert a letter.\n";
	cin >> inputCh;
	if (inputCh >= 65 && inputCh <= 90 || inputCh >= 97 && inputCh <= 122)
	{
		if (isupper(inputCh))
		{
			inputCh = tolower(inputCh);
			cout << (char)inputCh << endl;
		}
		else
		{
			inputCh = toupper(inputCh);
			cout << (char)inputCh << endl;
		}
	}
	else
	{
		cout << (char)inputCh << " is not a letter.\n";
	}
	

	//TASK 5
	cout << "Insert a letter or a digit.\n";
	char input;
	cin >> input;
	if (input >= 48 && input <= 57)
	{
		cout << input * input << endl;
	}
	else
	{
		if (isupper(input))
		{
			input = tolower(input);
			cout << (char)input << endl;
		}
		else
		{
			input = toupper(input);
			cout << (char)input << endl;
		}
	}

	// TASK 6
	short month = 0;
	cin >> month;
	switch (month)
	{
	case 1:
		cout << "It's winter.\n";
		break;
	case 2:
		cout << "It's winter.\n";
		break;
	case 3:
		cout << "It's spring.\n";
		break;
	case 4:
		cout << "It's spring.\n";
		break;
	case 5:
		cout << "It's spring.\n";
		break;
	case 6:
		cout << "It's summer.\n";
		break;
	case 7:
		cout << "It's summer.\n";
		break;
	case 8:
		cout << "It's summer.\n";
		break;
	case 9:
		cout << "It's autumn.\n";
		break;
	case 10:
		cout << "It's autumn.\n";
		break;
	case 11:
		cout << "It's autumn.\n";
		break;
	case 12:
		cout << "It's winter.\n";
		break;
	default: "You're living on another planet.\n";
		break;
	}

	//BONUS
	int bigNum = 0;
	cout << "Insert a threediit number.\n";
	cin >> bigNum;
	int hundreds = bigNum / 100;
	int dec = (bigNum - (hundreds * 100)) / 10;
	int digits = bigNum % 10;

	int resultBonus = hundreds * dec * digits;
	if (resultBonus >= 100 && resultBonus <= 999)
	{
		int sum = hundreds + dec + digits;
		cout << "The result is again threedigit.\n" << resultBonus - sum << endl;
	}
	else
	{
		cout << "The result is not threedigit.\n" << resultBonus << endl;
	}

	//BONUS 2
	double p, q, r;
	cout << "Insert three sides of triangle.\n";
	cin >> p >> q >> r;

	if (p + q > r || p + r > q || q + r > p)
	{
		double p2 = p * p,  q2 = q * q, r2 = r * r;
		cout << "The triangle is valid.\n";

		if (p2 + q2 == r2 || p2 + r2 == q2 || q2 + r2 == p2)
		{
			cout << "The triangle is rectangular.\n";
		}
		else if (p2 + q2 > r2 || p2 + r2 > q2 || q2 + r2 > p2)
		{
			cout << "The triangle is thong.\n";
		}
		else
		{
			cout << "The triangle is acute-angled.\n";
		}
	}
	else
	{
		cout << "The triangle is not valid.\n";
	}

	return 0;
}