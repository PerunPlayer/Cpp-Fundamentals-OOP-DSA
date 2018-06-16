#include "stdafx.h"

#include <iostream>
#include <cassert>

template <typename T> class Vector
{
private:
	T* container;
	size_t _size;
	size_t capacity;
	void resize();

public:
	Vector();
	~Vector();
	Vector(const Vector&);
	Vector& operator=(const Vector&);

public:
	void push(size_t index, T element);
	void push_back(T element);
	void push_front(T element);
	void pop(size_t index, T element);
	void pop_back();
	void pop_front();

	T& operator[](const size_t index) const;
	void print() const;
	size_t size() const;
};

template<typename T>
void Vector<T>::resize()
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

template<typename T>
Vector<T>::Vector()
{
	_size = 0;
	capacity = 8;
	container = new T[capacity];
}

template<typename T>
Vector<T>::~Vector()
{
	_size = 0;
	delete[] container;
	capacity = 0;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	_size = other._size;
	capacity = other.capacity;
	container = new T[capacity];
	for (size_t i = 0; i < _size; i++)
	{
		container[i] = other.container[i];
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
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

template<typename T>
void Vector<T>::push_back(T element)
{
	if (_size >= capacity)
	{
		this->resize();
	}
	container[_size] = element;
	_size++;
}

template<typename T>
void Vector<T>::push_front(T element)
{
	push(0, element);
}

template<typename T>
void Vector<T>::pop(size_t index, T element)
{
	T temp = container[index + 1];
	for (size_t i = index; i < _size - 1; i++)
	{
		container[i] = temp;
		temp = container[i + 2];
	}
	_size--;
}

template<typename T>
void Vector<T>::push(size_t index, T element)
{
	_size++;

	for (size_t i = _size; i > index + 1; i--)
	{
		container[i] = container[i - 1];
	}

	container[index] = element;
}

template<typename T>
void Vector<T>::pop_back()
{
	_size--;
}

template<typename T>
void Vector<T>::pop_front()
{
	T temp = container[1];
	for (size_t i = 0; i < _size - 1; i++)
	{
		container[i] = temp;
		temp = container[i + 2];
	}
	_size--;
}

template<typename T>
T& Vector<T>::operator[](const size_t index) const
{
	assert(index >= 0);
	assert(index < _size);

	return container[index];
}

template<typename T>
void Vector<T>::print() const
{
	std::cout << "[ ";
	for (size_t i = 0; i < _size; i++)
	{
		if (i == _size - 1)
		{
			std::cout << container[i] << " ]\n";
			return;
		}
		std::cout << container[i] << " ";
	}
}

template<typename T>
size_t Vector<T>::size() const
{
	return _size;
}