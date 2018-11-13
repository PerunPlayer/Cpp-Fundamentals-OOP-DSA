#include "stdafx.h"

#include "DLList.cpp"
#include "LList.cpp"

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


	//ListNode<int>* temp = nullptr;
	//delete temp;

	//LinkedList<int> llist;
	//llist.push_back(2);
	//llist.push_front(9);

	//llist.print();

	//llist.push_back(2);
	//llist.pushAfter(3, 1);

	//llist.print();

	//llist.pop_back();
	//llist.pop_front();

	//llist.print();

	//llist.popFrom(1);
	//llist.print();

	//llist.push_back(4);
	//llist.push_back(2);
	//llist.push_back(4);
	//llist.push_back(3);
	//llist.push_back(3);
	//llist.print();
	//llist.removeRepeatedNodes();
	//llist.print();

	return 0;
}

