#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

int const MAX_ARR_SIZE = 100;

int main()
{
	int subset[MAX_ARR_SIZE] = { 0 };
	int set[MAX_ARR_SIZE] = { 0 };	
	
	int n1, n2;
	cout << "Enter n1, n2: \n";
	cin >> n1 >> n2;
	cout << "Enter the first set of numbers(max 100), that should not be repeated: \n";
	for (short i = 0; i < n1; i++)
	{
		cin >> subset[i];
	}
	cout << "Now enter the second set of numbers(max 100), that should not be repeated: \n";
	for (short i = 0; i < n2; i++)
	{
		cin >> set[i];
	}

	bool isFromSet = true;
	for (short subsetIndex = 0; subsetIndex < MAX_ARR_SIZE && isFromSet; subsetIndex++)
	{
		for (short setIndex = 0; setIndex < MAX_ARR_SIZE; setIndex++)
		{
			if (set[setIndex] == subset[subsetIndex])
			{
				break;
			}
			if (set[setIndex] != subset[subsetIndex] && setIndex == MAX_ARR_SIZE - 1)
			{
				isFromSet = false;
			}
		}
	}

	if (isFromSet)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}

	return 0;
}