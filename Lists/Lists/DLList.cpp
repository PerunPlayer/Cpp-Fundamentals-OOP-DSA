#include "stdafx.h"

#include <iostream>
#include <cassert>

#include "DLList.h"

template<class T>
DLListNode<T>::DLListNode(const T& _data, DLListNode<T>* _next, DLListNode<T>* _previous) :data(_data), next(_next), previous(_previous) {}

template<class T>
DLList<T>::DLList()
{
	first = last = nullptr;
	currentSize = 0;
}

template<class T>
void DLList<T>::copy(const DLList<T>& other)
{
	first = last = nullptr;
	currentSize = 0;
	if (other.first)
	{
		DLListNode<T>* otherIterate = other.first;
		while (otherIterate)
		{
			DLListNode<T>* newElement = new DLListNode<T>(otherIterate->data);
			if (!first)
			{
				first = last = newElement;
			}
			else
			{
				last->next = newElement;
				newElement->previous = last;
				last = last->next;
			}
			currentSize++;
			otherIterate = otherIterate->next;
		}
	}
}

template<class T>
void DLList<T>::destroy()
{
	while (first)
	{
		DLListNode<T>* toDelete = first;
		first = first->next;
		delete toDelete;
	}
	first = last = nullptr;
}

template<class T>
DLList<T>::DLList(const DLList<T>& other)
{
	copy(other);
}

template<class T>
DLList<T>::~DLList()
{
	destroy();
}

template<class T>
DLList<T>& DLList<T>::operator = (const DLList<T>& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

template<class T>
void DLList<T>::push_back(const T& data)
{
	DLListNode<T>* toAdd = new DLListNode<T>(data, nullptr, last);
	if (!first)
	{
		first = last = toAdd;
	}
	else
	{
		last->next = toAdd;
		last = last->next;
	}
	currentSize++;
}

template<class T>
void DLList<T>::push_front(const T& data)
{
	DLListNode<T>* toAdd = new DLListNode<T>(data, first);
	if (first)
	{
		first->previous = toAdd;
	}
	first = toAdd;
	if (!last)
	{
		first = last;
	}
	currentSize++;
}

template<class T>
void DLList<T>::pop_back()
{
	if (first)
	{
		if (first == last)
		{
			delete first;
			first = last = nullptr;
			return;
		}
		DLListNode<T>* toDelete = last;
		last = last->previous;
		last->next = nullptr;
		delete toDelete;
		currentSize--;
	}
}

template<class T>
void DLList<T>::pop_front()
{
	if (first)
	{
		if (first == last)
		{
			delete first;
			first = last = nullptr;
			return;
		}
		DLListNode<T>* toDelete = first;
		first = first->next;
		first->previous = nullptr;
		delete toDelete;
		currentSize--;
	}
}

template<class T>
size_t DLList<T>::size() const
{
	return currentSize;
}

template<class T>
void DLList<T>::print() const
{
	DLListNode<T>* curr = first;

	std::cout << "{ ";
	for (size_t i = 0; i < currentSize - 1; i++)
	{
		std::cout << curr->data << ", ";
		curr = curr->next;
	}
	std::cout << curr->data << " }\n";
}

template<class T>
void DLList<T>::reverse()
{
	DLListNode<T> *current = first;
	DLListNode<T> *temp = nullptr;

	while (current)
	{
		temp = current->previous;
		current->previous = current->next;
		current->next = temp;
		if (!current->previous)
		{
			first = current;
		}
		current = current->previous;
	}
}

template<class T>
bool DLList<T>::empty() const
{
	return first == nullptr;
}

template<class T>
T DLList<T>::front() const
{
	assert(first);
	return first->data;
}

template<class T>
T DLList<T>::back() const
{
	assert(last);
	return last->data;
}