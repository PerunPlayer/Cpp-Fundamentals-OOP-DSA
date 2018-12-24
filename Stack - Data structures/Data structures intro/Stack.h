#pragma once

#include <iostream>

using namespace std;

template <typename T>
struct Node<T>
{
	T data;
	Node<T>* next;

	Node<T>(const T& _data, Node<T>* _next = nullptr)
	{
		data = _data;
		next = _next;
	}
};

template <typename T>
class Stack<T>
{
private:
	Node<T>* topNode;
	size_t size;

public:
	Stack();
	Stack(const Stack<T>& other);
	Stack& operator=(const Stack<T>& other);
	~Stack();

	void copy(const Stack<T>& other);
	void destroy();
	bool isEmpty() const;
	size_t getSize() const;
	void push(const T& element);
	void pop();
	const T& top() const;
};

template<typename T>
inline Stack<T>::Stack()
{
	size = 0;
	topNode = nullptr;
}

template<typename T>
inline Stack<T>::Stack(const Stack<T>& other)
{
	copy(other);
}

template<typename T>
inline Stack & Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		size = 0;
		topNode = nullptr;
		copy(other);
	}
	return *this;
}

template<typename T>
inline Stack<T>::~Stack()
{
	if (top)
	{
		destroy();
	}
}

template<typename T>
inline void Stack<T>::copy(const Stack<T>& other)
{
	topElem = new Node<T>(other.topElem->data, other.topElem->next);
	Node<T>* temp1 = topElem;
	Node<T>* temp2 = other.topElem->next;
	while (temp2)
	{
		temp1->next = new Node<T>(temp2->data, temp2->next;
		temp2 = temp->next;
		temp1 = temp1->next;
	}
}

template<typename T>
inline void Stack<T>::destroy()
{
	while (!isEmpty())
	{
		pop();
	}
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return size == 0;
}

template<typename T>
inline size_t Stack<T>::getSize() const
{
	return size;
}

template<typename T>
inline void Stack<T>::push(const T& element)
{
	Node<T>* addElem = new Node<T>()
	{
		if (isEmpty())
		{
			topNode = addElem;
		}
		else
		{
			addElem->next = topElem;
			topElem = addElem;
		}
		size++;
	}
}

template<typename T>
inline void Stack<T>::pop()
{
	if (!isEmpty())
	{
		Node<T>* temp = topElem;
		topElem = topElem->next;
		delete temp;
		size--;
	}
}

template<typename T>
inline const T& Stack<T>::top() const
{
	if (!isEmpty())
	{
		return topElem->data;
	}
	return NULL;
}
