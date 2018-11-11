#pragma once

#include <iostream>

template <class T>
struct ListNode
{
	T data;
	ListNode<T>* next;
	ListNode(const T& _data, ListNode<T>* _next = nullptr) : data(_data), next(_next) {}
};

template <class T>
class LinkedList
{
private:
	ListNode<T>* first;
	ListNode<T>* last;
	unsigned int size;

	void copy(const LinkedList<T>& other);
	void destroy();

public:

	LinkedList();
	LinkedList(const LinkedList<T>* other);
	LinkedList& operator=(const LinkedList<T>& other);
	~LinkedList();

	void push_back(const T& elem);
	void push_front(T data);
	void pushAfter(T data, size_t index);
	T get(int index);
	void pop_front();
	void pop_back();
	void popFrom(size_t index);
	void print() const;
	unsigned int getSize() const;

	void removeRepeatedNodes();
	void reverse();
};

template<class T>
inline void LinkedList<T>::copy(const LinkedList<T>& other)
{
	ListNode<T>* temp = other.first;
	while (temp)
	{
		push_back(temp->data);
		temp = temp->next;
	}
}

template<class T>
inline void LinkedList<T>::destroy()
{
	while (size > 0)
	{
		pop_front();
	}
}

template<class T>
inline LinkedList<T>::LinkedList()
{
	first = last = nullptr;
	size = 0;
}

template<class T>
inline LinkedList<T>::LinkedList(const LinkedList<T>* other)
{
	copy(other);
}

template<class T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	if (this != other)
	{
		destroy();
		first = last = nullptr;
		copy(other);
	}

	return *this;
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
	destroy();
}

template<class T>
inline void LinkedList<T>::push_back(const T& elem)
{
	ListNode<T>* temp = new ListNode<T>(elem, nullptr);
	ListNode<T>* indexer = first;
	if (temp)
	{
		if (size == 0)
		{
			first = temp;
			last = temp;
		}
		else
		{
			for (size_t i = 0; i < this->size - 1; i++)
			{
				indexer = indexer->next;
			}
			indexer->next = temp;
			this->last = temp;
		}

		size++;
	}
}

template<class T>
inline void LinkedList<T>::push_front(T data)
{
	ListNode<T>* temp = new ListNode<T>(data, first);
	first = temp;
	size++;
}

template<class T>
inline void LinkedList<T>::pushAfter(T data, size_t index)
{
	if (index >= size)
	{
		return; //TODO: throw exception
	}
	ListNode<T>* temp2 = first;
	ListNode<T>* temp = new ListNode<T>(data, nullptr);
	while (index != 0)
	{
		temp2 = temp2->next;
		index--;
	}
	temp->next = temp2->next;
	temp2->next = temp;
	size++;
}

template<class T>
inline T LinkedList<T>::get(int index)
{
	if (index >= size)
	{
		return; //TODO: throw exception
	}
	ListNode<T>* temp = first;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

template<class T>
inline void LinkedList<T>::pop_front()
{
	ListNode<T>* temp = first;
	first = first->next;
	delete temp;
	size--;
}

template<class T>
inline void LinkedList<T>::pop_back()
{
	ListNode<T>* temp = first;
	while (temp->next != last)
	{
		temp = temp->next;
	}
	last = temp;
	temp = temp->next;
	delete temp;
	size--;
}

template<class T>
inline void LinkedList<T>::popFrom(size_t index)
{
	if (index >= size)
	{
		return; //TODO: throw exception
	}
	ListNode<T>* temp = first;
	for (size_t i = 0; i < index; i++, temp = temp->next)
	{
		if (i == index - 1)
		{
			ListNode<T>* toDelete = temp->next;
			temp->next = temp->next->next;
			delete[] toDelete;
		}
	}
	size--;
}

template<class T>
inline void LinkedList<T>::print() const
{
	ListNode<T>* curr = first;

	std::cout << "{ ";
	for (size_t i = 0; i < size - 1; i++)
	{
		std::cout << curr->data << ", ";
		curr = curr->next;
	}
	std::cout << curr->data << " }\n";
}

template<class T>
inline unsigned int LinkedList<T>::getSize() const
{
	return this->size;
}

template<class T>
inline void LinkedList<T>::removeRepeatedNodes()
{
	ListNode<T>* indexer1 = first;
	ListNode<T>* indexer2 = first->next;
	size_t i = 1, j = 0;

	while (indexer1->next != nullptr)
	{
		indexer2 = indexer1->next;
		i = j + 1;
		j++;

		for (size_t k = 0; k < size, indexer2->next != nullptr; k++)
		{
			if (indexer2->data == indexer1->data)
			{
				indexer2 = indexer2->next;
				popFrom(i);
			}
			else
			{
				i++;
				indexer2 = indexer2->next;
			}
		}
		indexer1 = indexer1->next;
	}

	indexer1 = first;
	while (indexer1->next != nullptr)
	{
		if ((indexer1->next == last) && (indexer1->data == indexer1->next->data))
		{
			popFrom(size - 1);
			return;
		}
		indexer1 = indexer1->next;
	}
}

template<class T>
inline void LinkedList<T>::reverse()
{
	ListNode<T> *current = first;
	ListNode<T> *prev = nullptr, *next = nullptr;


	while (current)
	{
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}
	first = prev;
}
