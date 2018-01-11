#include "stdafx.h"
#include <iostream>
#include <cmath>

const short ARR_SIZE = 100;

bool containsVocals(char* str, short i);
int countVocals(char* str, short i, short counter);
int findMax(int* integerArr, short size, int index, int max);

using namespace std;

int main()
{
	char str[ARR_SIZE] = { 'd', 'a', 'r', 't', 'h', 'm', 'a', 'u', 'l' };
	//cin.getline(str, 100);

	if (containsVocals(str, 0))
	{
		cout << "Yes, the string cotains vocals.\n";
	}
	else
	{
		cout << "No, there are no vocals.\n";
	}
	
	cout << "The number of vocals is: " << countVocals(str, 0, 0) << endl;

	//Task with numbers...
	int integerArr[ARR_SIZE] = { 0 };
	int size = 0;
	cout << "Enter number for size of array: ";
	cin >> size;
	cout << "Enter " << size << " integers, separated by whitespaces: ";
	for (short i = 0; i < size; i++)
	{
		cin >> integerArr[i];
	}

	int max = integerArr[0];
	int index = 1;
	cout << "The biggest number is: " << findMax(integerArr, size, index, max) << endl;









	return 0;
}

bool containsVocals(char* str, short i)
{
	if (*str == 'a' || *str == 'A' || *str == 'e' || *str == 'E' || *str == 'o' || *str == 'O' || *str == 'u' || *str == 'U' || *str == 'i' || *str == 'I')
	{
		return 1;
	}
	if (str[i] == '\0')
	{
		return 0;
	}
	containsVocals(str + 1, ++i);
}

int countVocals(char* str, short i, short counter)
{
	if (*str == 'a' || *str == 'A' || *str == 'e' || *str == 'E' || *str == 'o' || *str == 'O' 
	 || *str == 'u' || *str == 'U' || *str == 'i' || *str == 'I' || *str == 'y' || *str == 'Y')
	{
		counter++;
	}
	if (str[i] == '\0')
	{
		return counter;
	}
	countVocals(str + 1, i, counter);
}

int findMax(int* integerArr, short size, int index, int max)
{
	if (index == size)
	{
		return max;
	}
	if (max < integerArr[index])
	{
		max = integerArr[index];
	}
	return findMax(integerArr, size, ++index, max);
}