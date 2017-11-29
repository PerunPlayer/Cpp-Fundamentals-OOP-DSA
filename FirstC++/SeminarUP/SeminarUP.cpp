// SeminarUP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	/*int weightInKilograms = 0;
	const double kiloToLbs = 2.2;
	char* inserting = "Insert weight(kg): ";

	cout << inserting;
	cin >> weightInKilograms;
	cout << weightInKilograms * kiloToLbs << endl;*/


	// ELHICHKA
	int n;
	cin >> n;

	int imageWidth = n;

	for (int i = 0; i <= (n + 1) / 2; i++)
	{
		int row = i;

		// Put the stank of the tree
		if (i == (n + 1) / 2)
		{
			row = 0;
		}

		int starCount = 1 + row * 2;
		int dotCount = (imageWidth - starCount) / 2;

		for (int j = 0; j < dotCount; j++)
		{
			cout << ".";
		}
		for (int j = 0; j < starCount; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < dotCount; j++)
		{
			cout << ".";
		}

		cout << endl;
	}

	return 0;
}

