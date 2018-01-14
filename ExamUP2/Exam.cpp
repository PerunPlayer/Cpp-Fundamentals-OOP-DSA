// Exam.cpp : Defines the entry point for the console application.
// Pavel Denkov FN:71793

#include "stdafx.h"
#include <cmath>
#include <iostream>

using namespace std;

const short SIZE = 3;
const short PHRASE_SIZE = 100;

long factorialSum(double number);
long factorial(int i);
void replaceElements(double matrix[][SIZE], int sum);
bool containsElement(double matrix[][SIZE], double searched);
void codeRefactoring(char *phrase);
void toLower(char *phrase);
void add(char *phrase, int index, char toAdd);
int* findPerfectElement(int *intArr, short arrSize, bool &existPerfectElement, short startElement, int currMax, int* p);


int main()
{
	//Task 1
	double number;
	cout << "Enter a number: ";
	cin >> number;

	long sum = 0;
	cout << "The sum of factorials, smaller than this number, is: ";
	sum = factorialSum(number);

	cout << sum << endl;

	//Task 2
	double matrix[SIZE][SIZE] = { 
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },

	};
	replaceElements(matrix, sum);

	double k = 0;
	cin >> k;
	containsElement(matrix, k);

	//Task 3
	char phrase[PHRASE_SIZE] = { 0 };
	cout << "Enter a phrase to refactor it:\n";
	cin.getline(phrase, PHRASE_SIZE);
	cin.getline(phrase, PHRASE_SIZE);
	codeRefactoring(phrase);

	for (short i = 0; i < PHRASE_SIZE; i++)
	{
		cout << phrase[i];
	}
	cout << endl;

	//Task 4
	cout << "Enter count of integer array(max " << PHRASE_SIZE << "): ";
	short arrSize = 0;
	cin >> arrSize;
	cout << "Enter "<< arrSize << " integers (separated by whitespace): ";
	int intArr[PHRASE_SIZE] = { 0 };
	for (short i = 0; i < arrSize; i++)
	{
		cin >> intArr[i];
	}

	int *p = NULL;
	bool existPerfectElement = false;
	int *pointer = findPerfectElement(intArr, arrSize, existPerfectElement, 0, 0, p);
	if (existPerfectElement)
	{
		cout << "The address of the perfect element is: " << pointer << endl;
	}
	else
	{
		cout << "There is no perfect element here.\n";
	}

    return 0;
}

long factorialSum(double number)
{
	long sum = 0;
	int numberInt = floor(number);
	for (int i = 0; i <= numberInt; i++)
	{
		long fact = factorial(i);
		if (fact <= number)
		{
			sum += fact;
		}
	}

	return sum;
}

long factorial(int number)
{
	long product = 1;
	if (number == 0)
	{
		return 1;
	}

	if (number == 1)
	{
		return 1;
	}

	for (int i = 1; i <= number; i++)
	{
		product *= i;
	}

	return product;
}

void replaceElements(double matrix[][SIZE], int sum)
{
	for (short i = 0; i < SIZE; i++)
	{
		for (short j = 0; j < SIZE; j++)
		{
			if (i - j <= SIZE - 1)
			{
				matrix[i][j] = factorialSum(matrix[i][j]);
			}
		}
	}
}

bool containsElement(double matrix[][SIZE], double searched)
{
	bool contains = false;
	for (short i = 0; i < SIZE; i++)
	{
		for (short j = 0; j < SIZE; j++)
		{
			if (matrix[i][j] == searched)
			{
				contains = true;
				return contains;
			}

			if (matrix[i][j] != searched && i == SIZE - 1 && j == SIZE -1)
			{
				return contains;
			}
		}
	}
}

void codeRefactoring(char *phrase)
{
	short differnce = ('a' - 'A');
	bool containLower = false;
	for (short i = 0; i < PHRASE_SIZE; i++)
	{
		if (phrase[i] >= 'a' && phrase[i] <= 'z')
		{
			containLower = true;
			break;
		}
	}

	if (!containLower)
	{
		toLower(phrase);
	}

	for (short i = 0; i < PHRASE_SIZE; i++)
	{
		if (phrase[i] == '4' && ((phrase[i - 1] >= 'a' && phrase[i - 1] <= 'z') || (phrase[i - 1] >= 'A' && phrase[i - 1] <= 'Z') 
							 || (phrase[i + 1] >= 'a' && phrase[i + 1] <= 'z') || (phrase[i + 1] >= 'A' && phrase[i + 1] <= 'Z')))
		{
			phrase[i] = 'c';
			add(phrase, i + 1, 'h');
		}
		if (phrase[i] == '6' && ((phrase[i - 1] >= 'a' && phrase[i - 1] <= 'z') || (phrase[i - 1] >= 'A' && phrase[i - 1] <= 'Z')
							 || (phrase[i + 1] >= 'a' && phrase[i + 1] <= 'z') || (phrase[i + 1] >= 'A' && phrase[i + 1] <= 'Z')))
		{
			phrase[i] = 's';
			add(phrase, i + 1, 'h');
		}
	}

	if (phrase[0] >= 'a' && phrase[0] <= 'z')
	{
		phrase[0] = phrase[0] - differnce;
	}

	for (short i = 0; i < PHRASE_SIZE; i++)
	{
		if (phrase[i - 2] == '.' && phrase[i - 1] == ' ' && phrase[i] >= 'a' && phrase[i] <= 'z')
		{
			phrase[i] = phrase[i] - differnce;
		}
	}

	return;
}

void toLower(char *phrase)
{
	short difference = 'a' - 'A';
	for (short i = 0; i < PHRASE_SIZE; i++)
	{
		if (phrase[i] >= 'A' && phrase[i] <= 'Z')
		{
			phrase[i] = phrase[i] + difference;
		}
	}
	return;
}

void add(char *phrase, int index, char toAdd)
{
	char temp = ' ';
	for (int i = index; i < PHRASE_SIZE; i++)
	{
		temp = phrase[i];
		phrase[i] = toAdd;
		toAdd = temp;
	}
}

int* findPerfectElement(int *intArr, short arrSize, bool &existPerfectElement, short startElement, int currMax, int* p)
{
	short i = startElement;

	for (short i = startElement; i < arrSize; i++)
	{
		if (intArr[i] == (intArr[i + 1] + 2) && intArr[i] > currMax)
		{
			currMax = intArr[i];
			p = &intArr[i];
			existPerfectElement = true;
			startElement = i;
			break;
		}
		if (i == arrSize - 1)
		{
			return p;
		}
	}

	findPerfectElement(intArr, arrSize, existPerfectElement, startElement, currMax, p);
}