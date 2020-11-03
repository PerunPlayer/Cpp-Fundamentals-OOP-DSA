#include "stdafx.h"
#include <iostream>

template <class T>
struct ListNode
{
	T data;
	ListNode<T>* next;
	ListNode(const T& _data, ListNode<T>* _next = nullptr) : data(_data), next(_next) {}
};

//pushFront
template <class T>
ListNode<T>*& pushFront(T data, ListNode<T>*& first)
{
	ListNode<T>* newNode = new ListNode<T>(data, first);
	return newNode;
}

//pushBack
template <class T>
void pushBack(T data, ListNode<T>*& first)
{
	ListNode<T>* curr = first;
	ListNode<T>* newNode = new ListNode<T>(data, nullptr);
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = newNode;
}

//pushAt
template <class T>
void pushAt(T data, ListNode<T>*& first, size_t index)
{
	ListNode<T>* curr = first;
	ListNode<T>* newNode = new ListNode<T>(data, nullptr);
	for (size_t i = 1; i < index - 1; i++)
	{
		curr = curr->next;
	}
	ListNode<T>* next = curr->next;
	curr->next = newNode;
	newNode->next = next;
}

//popFront
template <class T>
ListNode<T>*& popFront(ListNode<T>*& first)
{
	ListNode<T>* curr = first;
	if (curr)
	{
		ListNode<T>* next = curr->next;
		delete[] curr;
		curr = next;
	}

	return curr;
}

//popBack
template <class T>
void popBack(ListNode<T>*& first)
{
	ListNode<T>* curr = first;
	while (curr->next->next)
	{
		curr = curr->next;
	}
	delete[] curr->next;
	curr->next = nullptr;
}

//popAt
template <class T>
void popAt(ListNode<T>*& first, size_t index)
{
	ListNode<T>* curr = first;
	if (!index)
	{
		popFront(curr);
	}

	for (size_t i = 1; (i < index - 1) && curr; i++)
	{
		curr = curr->next;
	}
	ListNode<T>* next = curr->next->next;
	delete[] curr->next;
	curr->next = next;
}

//find
template <class T>
ListNode<T>*& find(ListNode<T>*& first, T data) //overload operator == for non primitive data types
{
	ListNode<T>* curr = first;
	while (curr)
	{
		if (curr->data == data)
		{
			return curr;
		}
		curr = curr->next;
	}
	std::cout << "Element not found. First element returned.\n";
	return first;
}

//reverse
template <class T>
void reverse(ListNode<T>*& first)
{
	ListNode<T>* current = first;
	ListNode<T>* prev = nullptr;
	ListNode<T>* next = nullptr;

	while (current) 
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	first = prev;
}

//checkForLoop
template <class T>
bool checkForLoop(ListNode<T>*& first)
{
	ListNode<T>* fastIterator = first;
	ListNode<T>* slowIterator = first;

	do
	{
		fastIterator = fastIterator->next->next;
		slowIterator = slowIterator->next;
		if (fastIterator == slowIterator)
		{
			return true;
		}
	} while (fastIterator && slowIterator);
}

template <class T>
void print(ListNode<T>* node)
{
	unsigned int counter = 0;
	while (node)
	{
		std::cout << "Element " << counter << ": " << node->data << std::endl;
		node = node->next;
		counter++;
	}
	std::cout << "----------------------------\n";
}

int main()
{
	ListNode<int>* five = new ListNode<int>(5, nullptr);
	ListNode<int>* four = new ListNode<int>(4, five);
	ListNode<int>* three = new ListNode<int>(3, four);
	ListNode<int>* two = new ListNode<int>(2, three);
	ListNode<int>* one = new ListNode<int>(1, two);

	print(one);
	ListNode<int>* first = pushFront(0, one);
	print(first);
	pushBack(100, one);
	print(first);
	pushAt(99, first, 5);
	print(first);
	first = popFront(first);
	print(first);
	popBack(first);
	print(first);
	pushAt(33, first, 3);
	print(first);
	popAt(first, 3);
	print(first);
	std::cout << find(first, 3)->data << std::endl;
	std::cout << find(first, 56)->data << std::endl;
	reverse(first);
	print(first);

	return 0;
}

