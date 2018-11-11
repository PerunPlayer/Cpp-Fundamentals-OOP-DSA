#include "stdafx.h"

#include "DLList.cpp"

int main()
{
	DLList<int> testDLList;
	testDLList.push_back(3);
	testDLList.push_back(4);
	testDLList.push_back(5);
	testDLList.push_back(77);
	testDLList.push_back(0);
	testDLList.push_back(-3);
	testDLList.print();
	testDLList.reverse();
	testDLList.print();

	return 0;
}

