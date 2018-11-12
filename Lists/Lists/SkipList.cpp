#include "stdafx.h"
#include "SkipList.h"

template <class T>
Node<T>::Node(const T &_data, Node *_next, Node *_skip) : data(_data)
{
	next[0] = _next;
	next[1] = _skip;
}

template<class T>
void SkipList<T>::copy(const SkipList<T>& other)
{
	first = last = nullptr;
	crrsize = 0;
	if (other.first)
	{
		Node<T>* otherIterate = other.first;
		while (otherIterate)
		{
			Node<T>* newElement = new Node<T>(otherIterate->data);
			if (!first)
			{
				first = last = newElement;
			}
			else
			{
				last->next = newElement;
				last = last->next;
			}
			currentSize++;
			otherIterate = otherIterate->next;
		}

		optimize();
	}
}

template<class T>
void SkipList<T>::destroy()
{
	while (first)
	{
		Node<T>* toDelete = first;
		first = first->next;
		delete toDelete;
	}
	first = last = nullptr;

	crrsize = skipLength = 0;
}

template<class T>
void SkipList<T>::optimize()
{

}

template <class T>
SkipList<T>::SkipList()
{
	first = last = nullptr;
	crrsize = 0;
	skipLength = 0;
}

template<class T>
SkipList<T>::SkipList(const SkipList<T>& other)
{
	copy(other);
}

template<class T>
SkipList& SkipList<T>::operator = (const SkipList<T>& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

template<class T>
SkipList<T>::~SkipList()
{
	destroy();
}

template<class T>
void SkipList<T>::push_front(const T& data)
{
	first = new Node<T>(data, first, nullptr);
	if (last == nullptr)
	{
		last = first;
	}

	crrsize++;
	if (((int)sqrt(crrsize)) > skipLength)
	{
		optimize();
	}
}

template<class T>
size_t SkipList<T>::size()
{
	return crrsize;
}
