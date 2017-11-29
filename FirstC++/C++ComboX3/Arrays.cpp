#include "stdafx.h"
#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;
const int ARRAY_SIZE = 100;

int main()
{
	//Task 1   Да се намерят минималния и максималния елемент на масива.
	int n;
	cin >> n;
	int array[ARRAY_SIZE] = {0};

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	int minElement = array[0];
	int maxElement = array[0];
	int indexOfMin = 0;
	int indexOfMax = 0;

	//minElement = array[i] < minElement ? array[i] : minElement;
	//maxElement = array[i] > maxElement ? array[i] : maxElement;
	//or ->
	for (int i = 1; i < n; i++)
	{
		if (array[i] < minElement)
		{
			minElement = array[i];
			indexOfMin = i;
		}
		if (array[i] > maxElement)
		{
			maxElement = array[i];
			indexOfMax = i;
		}
	}

	cout << minElement << endl;
	cout << maxElement << endl;

	//Task 2     Да се намерят минималния и максималния елемент на масива. Да се разменят местата им в масива и да се изведе новия масив.

	//swap max with min in the array
	array[indexOfMin] ^= array[indexOfMax];
	array[indexOfMax] ^= array[indexOfMin];
	array[indexOfMin] ^= array[indexOfMax];

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}

	//Task 3     Да се намери и изведе броя на тези числа в масива, чийто сбор от цифрите е едноцифрено число.

	int k;
	cin >> k;
	int arr[ARRAY_SIZE] = { 0 };

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	int counter = 0;

	for (int i = 0; i < k; i++)
	{
		int temp = arr[i];
		int sum = 0;
		while (temp != 0)
		{
			short lastDigit = temp % 10;
			sum += lastDigit;
			temp /= 10;
		}

		if (sum < 10)
		{
			counter++;
			cout << arr[i] << " ";
		}
	}

	if (counter == 0)
	{
		cout << "There are no numbers that have sum of digits smaller than 10." << endl;
	}
	cout << "The numbers that have sum of digits smaller than 10: " << counter << endl;

	//Task 4  Да се напише програма, която въвежда две цели числа n и m и елементите на правоъгълна матрица(nxm). Програмата да извежда матрицата, получена от въведената, като всеки нейн елемент е увеличен с 10.

	int twoDimensional[3][2] = {
		{1, 2},
		{3, 4},
		{5, 6}
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			twoDimensional[i][j] += 10;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << twoDimensional[i][j] << " "; 
		}
		cout << endl;
	}

	//Task 5   Програмата да намира и извежда сумата от елементите на квадратна матрица на (всеки ред/всеки стълб/главния диагонал/под главния диагонал/над главния диагонал/вторичния диагонал/под вторичния диагонал/над вторичния диагонал)
	
	int squareTwoDimensional[3][3] = {
		{ 1, 2, 3},
		{ 4, 5, 6},
		{ 7, 8, 9}
	};
	//вторичния диагонал
	int sumOfSecondary = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sumOfSecondary += (i + j == 2 ? squareTwoDimensional[i][j] : 0);
		}
	}

	cout << sumOfSecondary << endl;


	//Task 6    Да се въвежда цяло число х, да се провери дали х е елемент на матрицата, и ако е - да се изведе позицията на елемнта в матрицата и елемента да се умножи по 10, а ако не е елемент на матрицата да се изведе подходящо съобщ.

	int x = 0;
	cin >> x;
	bool flag = false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (squareTwoDimensional[i][j] == x)
			{
				cout << i << " " << j << endl;
				squareTwoDimensional[i][j] *= 10;
				flag = true;
			}
		}
	}

	if (!flag)
	{
		cout << "There is not such element in the array.\n";
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << squareTwoDimensional[i][j] << " ";
		}
		cout << endl;
	}




	return 0;
}