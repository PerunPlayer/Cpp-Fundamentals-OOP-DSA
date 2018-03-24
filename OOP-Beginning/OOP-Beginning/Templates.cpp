#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T> class MyVector
{
private:
	void resize();
	int _size;
	int* buffer;
	int capacity;
public:
	MyVector();
	~MyVector();
	MyVector(const MyVector&);
	MyVector& operator=(const MyVector&);
public:
	void add(const T element);
	T& getAt(const int index);
	void setAt(const int index, const T element);
	T& operator[](const int index)const;
	void print()const;
};

int main()
{
	MyVector<int> a;
	a.add(3);
	a.add(65);
	a.add(4);
	a.add(5);

	a.print();

	return 0;
}

template<typename T>
void MyVector<T>::resize()
{
	capacity = capacity * 2;
	T* temp = new T[capacity];

	for (int i = 0; i < _size; i++)
	{
		temp[i] = buffer[i];
	}
	delete[] buffer;
	buffer = temp;
}

template<typename T>
MyVector<T>::MyVector()
{
	_size = 0;
	buffer = nullptr;
	capacity = 8;
}

template<typename T>
MyVector<T>::~MyVector()
{
	_size = 0;
	delete[] buffer;
	capacity = 0;
}

template<typename T>
MyVector<T>::MyVector<T>(const MyVector<T>& other)
{
	_size = other._size;
	capacity = other.capacity;
	buffer = new T[_size];
	for (int i = 0; i < _size; i++)
	{
		buffer[i] = other.buffer[i];
	}
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		delete[] buffer;

		_size = other._size;
		capacity = other.capacity;

		buffer = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			buffer[i] = other.buffer[i];
		}
	}

	return *this;
}

template<typename T>
void MyVector<T>::add(const T element)
{
	if (_size == capacity)
	{
		resize();
	}

	T* newBuffer = new T[_size + 1];
	for (int i = 0; i < _size + 1; i++)
	{
		newBuffer[i] = buffer[i];
	}
	newBuffer[_size + 1] = element;

	if (_size > 0)
	{
		delete[] buffer;
	}

	buffer = newBuffer;
	_size++;
}

template<typename T>
T & MyVector<T>::operator[](const int index) const
{
	//std::cout << a[0]; | a.operator[] (0)
	//a[0] = 10;

	assert(index >= 0);
	assert(index < _size);

	return buffer[index];

}

template<typename T>
void MyVector<T>::print() const
{
	cout << "[ ";
	for (int i = 0; i < _size; i++)
	{
		if (i != _size - 1)
		{
			cout << buffer[i] << " ";
		}
		cout << buffer[i];
	}
	cout << "]\0";
}


