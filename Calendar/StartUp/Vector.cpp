#include "stdafx.h"
#include <iostream>
#include <cassert>

#pragma once

template <class T> class MyVector
{
private:
	T* container;
	size_t _size;
	size_t capacity;
	void resize();

public:
	MyVector();
	~MyVector();
	MyVector(const MyVector&);
	MyVector& operator=(const MyVector&);
	MyVector(size_t size);

	void push_back(T element);
	void push(size_t index, T element);
	void pop_back();
	void pop_front();

	T& operator[](const size_t index)const;
	void print(std::ostream& out)const;
	void printTuples(std::ostream& out)const;
	size_t size() const;
	void destroy();
	void setElement(size_t index, T elem);
};

template<class T>
void MyVector<T>::resize()
{
	capacity = capacity * 2;
	T* temp = new T[capacity];

	for (size_t i = 0; i < _size; i++)
	{
		temp[i] = container[i];
	}
	delete[] container;
	container = temp;
}

template<class T>
MyVector<T>::MyVector()
{
	_size = 0;
	capacity = 8;
	container = new T[capacity];
}

template<class T>
MyVector<T>::~MyVector()
{
	_size = 0;
	delete[] container;
	capacity = 0;
}

template<class T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	_size = other._size;
	capacity = other.capacity;
	container = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		container[i] = other.container[i];
	}
}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		delete[] container;

		_size = other._size;
		capacity = other.capacity;

		container = new T[capacity];
		for (size_t i = 0; i < _size; i++)
		{
			container[i] = other.container[i];
		}
	}

	return *this;
}

template<class T>
MyVector<T>::MyVector(size_t size)
{
	_size = size;
	capacity = size;
	container = new T[size];
}

template<class T>
void MyVector<T>::push_back(T element)
{
	if (_size >= capacity)
	{
		this->resize();
	}
	container[_size] = element;
	_size++;
}

template<class T>
void MyVector<T>::push(size_t index, T element)
{
	_size++;

	for (size_t i = _size; i > index + 1; i--)
	{
		container[i] = container[i - 1];
	}

	container[index] = element;
}

template<class T>
void MyVector<T>::pop_back()
{
	_size--;
}

template<class T>
void MyVector<T>::pop_front()
{
	T temp = container[1];
	for (size_t i = 0; i < _size - 1; i++)
	{
		container[i] = temp;
		temp = container[i + 2];
	}
	_size--;
}

template<class T>
T& MyVector<T>::operator[](const size_t index) const
{
	assert(index >= 0);
	assert(index < _size);

	return container[index];
}

template<class T>
void MyVector<T>::print(std::ostream& out) const
{
	out << "[ ";
	for (size_t i = 0; i < _size; i++)
	{
		if (i == _size - 1)
		{
			out << container[i] << " ]\n";
			return;
		}
		out << container[i] << " ";
	}
}

template<class T>
void MyVector<T>::printTuples(std::ostream& out) const
{
	out << "[ ";
	for (size_t i = 0; i < _size; i++)
	{
		if (i == _size - 1)
		{
			out << std::get<0>(container[i]) << " " << std::get<1>(container[i]) << " ]\n";
			return;
		}
		out << std::get<0>(container[i]) << " " << std::get<1>(container[i]) << " , ";
	}
	out << " ]\n";
}

template<class T>
size_t MyVector<T>::size() const
{
	return _size;
}

template<class T>
void MyVector<T>::destroy()
{
	delete[] container;
}

template<class T>
void MyVector<T>::setElement(size_t index, T elem)
{
	container[index] = elem;
}
