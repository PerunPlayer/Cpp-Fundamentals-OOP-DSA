#include "stdafx.h"
#include <iostream>
#include <utility>

using namespace std;
using func_p = int(*)(int, int);

int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int _div(int a, int b) { return a / b; }
func_p toPointer(char symbol)
{
	switch (symbol)
	{
	case '+':
		return sum;
		break;
	case '-':
		return sub;
		break;
	case '*':
		return mult;
		break;
	case '/':
		return _div;
		break;

	default:
		cout << "Error!\n";
		return nullptr;
		break;
	}
}

//int main()
//{
//	int a, b;
//	char symbol;
//
//	do
//	{
//		cout << "Enter an expression with integers in type: 2 + 4 or 6 - 5 or 2 * 5 or 6 / 2\n";
//		cin >> a >> symbol >> b;
//		func_p p = *toPointer(symbol);
//		cout << p(a, b) << endl;
//	} while (!(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/'));
//}
