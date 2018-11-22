#include "stdafx.h"
#include <iostream>

template<typename T>
struct LinkedListNode
{
	T data;
	LinkedListNode<T>* next;
	LinkedListNode(const T _data, LinkedListNode<T>* _next = nullptr);
};

template<typename T>
struct DLinkedListNode
{
	T data;
	DLinkedListNode<T>* next;
	DLinkedListNode<T>* prev;
	DLinkedListNode(const T _data, DLinkedListNode<T>* _next = nullptr, DLinkedListNode<T>* _prev = nullptr);
};

LinkedListNode<int>* createLList(unsigned int n)
{
	if (n < 0)
	{
		return nullptr;
	}
	else if (n == 1)
	{
		LinkedListNode<int>* first = new LinkedListNode<int>(0);
		return first;
	}

	LinkedListNode<int>* first = new LinkedListNode<int>(0);
	LinkedListNode<int>* current = first;

	for (unsigned int i = 1; i <= n; i++)
	{
		LinkedListNode<int>* newNode = new LinkedListNode<int>(i);
		current->next = newNode;
		current = current->next;
	}
	return first;
}

DLinkedListNode<int>* createDLList(unsigned int n)
{
	if (n < 0)
	{
		return nullptr;
	}
	else if (n == 1)
	{
		DLinkedListNode<int>* first = new DLinkedListNode<int>(0);
		return first;
	}

	DLinkedListNode<int>* first = new DLinkedListNode<int>(0);
	DLinkedListNode<int>* current = first;

	for (unsigned int i = 1; i <= n; i++)
	{
		DLinkedListNode<int>* newNode = new DLinkedListNode<int>(i);
		current->next = newNode;
		newNode->prev = current;
		current = current->next;
	}
	return first;
}

template<typename T>
void reverseList(DLinkedListNode<T>*& first, unsigned int n)
{
	if ((!first) || (n <= 1))
	{
		return;
	}

	DLinkedListNode<T> *currentElement = first;
	DLinkedListNode<T> *lastReversed = first;
	while (n > 0 && currentElement)
	{
		std::swap(currentElement->next, currentElement->prev);
		lastReversed = currentElement;
		currentElement = currentElement->prev;
		n--;
	}
	first->next = currentElement;
	if (currentElement)
	{
		currentElement->prev = first;
	}
	lastReversed->prev = nullptr;
	first = lastReversed;
}

//if (currentElement->data - currentElement->previous->data != progStep)
//{
//	DLinkedListNode<T> *toDelete = currentElement;
//	currentElement->previous->next = currentElement->next;
//	if (currentElement->next)
//	{
//		currentElement->next->previous = currentElement->previous;
//	}
//	currentElement = currentElement->next;
//	delete toDelete;
//}

template <typename T>
void makeProgresson(DLinkedListNode<T>*& first)
{
	if ((first == nullptr) || (first->next == nullptr) || (first->next->next == nullptr))
	{
		return;
	}

	DLinkedListNode<T>* current1 = first, *current2 = first->next, *toDelete = nullptr;
	while (current2)
	{
		int sum = current1->data + current2->data;
		if (current2->next->data != sum)
		{
			toDelete = current2->next;
			current2->next = toDelete->next;
			if (current2->next)
			{
				current2->next->prev = toDelete->prev;
			}
			delete toDelete;
		}
		else
		{
			current1 = current1->next;
			current2 = current2->next;
		}
	}
}

int main()
{
	//Task 0 LList
	LinkedListNode<int>* testCreatingLList = createLList(5);
	LinkedListNode<int>* toIterateS = testCreatingLList;
	while (toIterateS)
	{
		std::cout << toIterateS->data << " ";
		toIterateS = toIterateS->next;
	}
	std::cout << "---- I am Linked list!" << std::endl;

	//Task 0 DLList
	DLinkedListNode<int>* testCreatingDLList = createDLList(11);
	DLinkedListNode<int>* toIterateD = testCreatingDLList;
	while (toIterateD)
	{
		std::cout << toIterateD->data << " ";
		toIterateD = toIterateD->next;
	}
	std::cout << "---- I am Doubly linked list!" << std::endl;

	//Task 1 Partial reverse
	reverseList(testCreatingDLList, 6);
	while (testCreatingDLList)
	{
		std::cout << testCreatingDLList->data << " ";
		testCreatingDLList = testCreatingDLList->next;
	}
	std::cout << "---- I am partial reversed Doubly linked list!" << std::endl;

	//Task 2 Make progression
	makeProgresson(testCreatingDLList);
	while (testCreatingDLList)
	{
		std::cout << testCreatingDLList->data << " ";
		testCreatingDLList = testCreatingDLList->next;
	}
	std::cout << "---- I am progression in Doubly linked list!" << std::endl;

	DLinkedListNode<int>* testProgressionDLList = createDLList(11);
	toIterateD = testProgressionDLList;
	while (toIterateD)
	{
		std::cout << toIterateD->data << " ";
		toIterateD = toIterateD->next;
	}
	makeProgresson(testProgressionDLList);
	while (testProgressionDLList)
	{
		std::cout << testProgressionDLList->data << " ";
		testProgressionDLList = testProgressionDLList->next;
	}
	std::cout << "---- I am progression in Doubly linked list!" << std::endl;

	return 0;
}

template<typename T>
LinkedListNode<T>::LinkedListNode(const T _data, LinkedListNode<T>* _next)
{
	data = _data;
	next = _next;
}

template<typename T>
DLinkedListNode<T>::DLinkedListNode(const T _data, DLinkedListNode<T>* _next, DLinkedListNode<T>* _prev)
{
	data = _data;
	next = _next;
	prev = _prev;
}
