#pragma once

#include <iostream>
#include <cassert>
#include <typeinfo>

template <typename T> class Vector
{
private:
	T* data;
	size_t length;
	size_t capacity;
	void resize();

public:
	Vector();
	Vector(const Vector<T>& other);
	Vector& operator=(const Vector<T>& other);
	~Vector();

	void push(size_t index, T element);
	void push_back(T element);
	void push_front(T element);
	void pop(size_t index, T element);
	void pop_back();
	void pop_front();

	T& operator[](const size_t index) const;
	void print() const;
	size_t size() const;
	void sort();
};










template<typename T>
void Vector<T>::resize()
{
	capacity = capacity * 2;
	T* temp = new T[capacity];

	for (size_t i = 0; i < length; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}

template<typename T>
Vector<T>::Vector()
{
	length = 0;
	capacity = 8;
	data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	length = other.length;
	capacity = other.capacity;
	data = new T[capacity];
	for (size_t i = 0; i < length; i++)
	{
		this->data[i] = other.data[i];
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		delete[] data;

		length = other.length;
		capacity = other.capacity;
		data = new T[capacity];
		for (size_t i = 0; i < length; i++)
		{
			this->data[i] = other.data[i];
		}
	}

	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] data;
	length = capacity = 0;
}

template<typename T>
void Vector<T>::push(size_t index, T element)
{
	if (length >= capacity)
	{
		this->resize();
	}

	length++;
	for (size_t i = length; i < index + 1; i--)
	{
		data[length] = data[length - 1];
	}
	data[index] = element;
}

template<typename T>
void Vector<T>::push_back(T element)
{
	if (length >= capacity)
	{
		this->resize();
	}

	data[length] = element;
	length++;
}

template<typename T>
inline void Vector<T>::push_front(T element)
{
	push(0, element);
}

template<typename T>
void Vector<T>::pop(size_t index, T element)
{
	T temp = data[index + 1];
	for (size_t i = index; i < length - 1; i++)
	{
		data[i] = temp;
		temp = data[i + 2];
	}
	length--;
}

template<typename T>
void Vector<T>::pop_back()
{
	length--;
}

template<typename T>
void Vector<T>::pop_front()
{
	T temp = data[1];
	for (size_t i = 0; i < length - 1; i++)
	{
		data[i] = temp;
		temp = data[i + 2];
	}
	length--;
}

template<typename T>
T& Vector<T>::operator[](const size_t index) const
{
	assert(index >= 0);
	assert(index < length);

	return data[index];
}

template<typename T>
void Vector<T>::print() const
{
	std::cout << "[ ";
	for (size_t i = 0; i < length; i++)
	{
		if (i == length - 1)
		{
			std::cout << data[i] << " ]\n";
			return;
		}
		std::cout << data[i] << " ";
	}
}

template<typename T>
size_t Vector<T>::size() const
{
	return length;
}

template<typename T>
void Vector<T>::sort()
{
	if ((typeid(data[0]).name() == "int") || (typeid(data[0]).name() == "size_t")
	{
		mergeSort(0, length);
	}
	else
	{
		throw "Error vector type for sorting!";
	}
}

void mergeSort(size_t start, size_t end)
{
	if (start >= end)
	{
		return;
	}
	size_t middle = (start + end) / 2;

	mergeSort(start, middle);
	mergeSort(middle + 1, end);

	//compareAndSort(start, middle, end);
}

//void compareAndSort(int start, int middle, int end)   //copied from C# project
//{
//	int[] sortedArr = new int[arr1.Length];
//
//	int leftLocalArr = start;
//	int leftArrStart = start;
//	int middleArrStart = middle + 1;
//
//	while (leftArrStart <= middle && middleArrStart <= end)
//	{
//		if (arr1[leftArrStart] > arr1[middleArrStart])
//		{
//			sortedArr[leftLocalArr++] = arr1[middleArrStart++];
//		}
//		else
//		{
//			sortedArr[leftLocalArr++] = arr1[leftArrStart++];
//		}
//	}
//
//	while (leftArrStart <= middle)
//	{
//		sortedArr[leftLocalArr++] = arr1[leftArrStart++];
//	}
//
//	while (middleArrStart <= end)
//	{
//		sortedArr[leftLocalArr++] = arr1[middleArrStart++];
//	}
//
//	for (int i = start; i <= end; i++)
//	{
//		arr1[i] = sortedArr[i];
//	}
//}

//void merge(int arr[], int l, int m, int r) //copied from GeeksForGeeks
//{
//	int i, j, k;
//	int n1 = m - l + 1;
//	int n2 = r - m;
//
//	/* create temp arrays */
//	int L[n1], R[n2];
//
//	/* Copy data to temp arrays L[] and R[] */
//	for (i = 0; i < n1; i++)
//		L[i] = arr[l + i];
//	for (j = 0; j < n2; j++)
//		R[j] = arr[m + 1 + j];
//
//	/* Merge the temp arrays back into arr[l..r]*/
//	i = 0; // Initial index of first subarray 
//	j = 0; // Initial index of second subarray 
//	k = l; // Initial index of merged subarray 
//	while (i < n1 && j < n2)
//	{
//		if (L[i] <= R[j])
//		{
//			arr[k] = L[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//
//	/* Copy the remaining elements of L[], if there
//	are any */
//	while (i < n1)
//	{
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	/* Copy the remaining elements of R[], if there
//	are any */
//	while (j < n2)
//	{
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//}
//
///* l is for left index and r is right index of the
//sub-array of arr to be sorted */
//void mergeSort(int arr[], int l, int r)
//{
//	if (l < r)
//	{
//		// Same as (l+r)/2, but avoids overflow for 
//		// large l and h 
//		int m = l + (r - l) / 2;
//
//		// Sort first and second halves 
//		mergeSort(arr, l, m);
//		mergeSort(arr, m + 1, r);
//
//		merge(arr, l, m, r);
//	}
//}