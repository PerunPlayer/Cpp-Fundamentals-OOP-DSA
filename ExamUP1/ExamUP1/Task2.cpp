#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int const MAX_ARR_SIZE = 100;

int main()
{
	int firstBoxSize = 1, secondBoxSize = 1;
	cout << "Enter the number of elements(between 1 and 100) in the boxes: (example: 5 99)\n";
	cin >> firstBoxSize >> secondBoxSize;

	if (firstBoxSize <= 0 || secondBoxSize <= 0)
	{
		cout << "You cannot have negative number of elements! I said between 1 and 100.";
		return 0;
	}


	int firstBox[MAX_ARR_SIZE] = { 0 };
	int secondBox[MAX_ARR_SIZE] = { 0 };
	cout << "Now enter the \"elements\" in the first box: ";
	for (short i = 0; i < firstBoxSize; i++)
	{
		cin >> firstBox[i];
	}

	cout << "Now enter the \"elements\" in the second box: ";
	for (short i = 0; i < secondBoxSize; i++)
	{
		cin >> secondBox[i];
	}

	int thirdBox[MAX_ARR_SIZE] = { 0 };
	bool isRepeated = true;
	short thirdBoxIndex = 0;
	for (short i = 0; i < firstBoxSize && isRepeated; i++)
	{
		for (short j = 0; j < secondBoxSize; j++)
		{
			if (firstBox[i] == secondBox[j])
			{
				thirdBox[thirdBoxIndex] = firstBox[i];
				thirdBoxIndex++;
				break;
			}
		}
	}

	if (thirdBox[0] == 0 && thirdBox[1] == 0)
	{
		cout << "There are no repeated elements in the boxes.\n";
	}
	else
	{
		for (short i = 0; i < thirdBoxIndex; i++)
		{
			cout << thirdBox[i] << " ";
		}
	}
	

	return 0;
}