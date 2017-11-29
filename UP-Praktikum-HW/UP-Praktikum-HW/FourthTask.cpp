#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;
int const MAX_ARR_SIZE = 6;

int main()
{
	int array1[MAX_ARR_SIZE] = {
		1, 3, 2, 4, 3, 7
	};
	int array2[MAX_ARR_SIZE] = {
		1, 2, 3, 4, 5, 6
	};

	bool isZigZag = true;
	for (short i = 1; i < MAX_ARR_SIZE && isZigZag; i+=2)
	{
		if (array1[i] > array1[i - 1] && array1[i] > array1[i + 1])
		{
			continue;
		}
		else
		{
			isZigZag = false;
		}
	}

	if (isZigZag)
	{
		cout << "Array1 is zigzag.\n";
	}
	else
	{
		cout << "Array1 isn't zigzag.\n";
	}
	
	isZigZag = true;
	for (short i = 1; i < MAX_ARR_SIZE && isZigZag; i += 2)
	{
		if (array2[i] > array2[i - 1] && array2[i] > array2[i + 1])
		{
			continue;
		}
		else
		{
			isZigZag = false;
		}
	}

	if (isZigZag)
	{
		cout << "Array2 is zigzag.\n";
	}
	else
	{
		cout << "Array2 isn't zigzag.\n";
	}

	return 0;
}