#include "stdafx.h"
#include <iostream>
#include <cmath>

//ID, sum, div, max, pow, ... -> ID result()
template<typename T>
class Formula
{
public:
	virtual T result() = 0;
};

template<typename T>
class ID : public Formula<T>
{
	T param;

public: 
	ID(const T& elem) : param(elem) {}
	virtual T result()
	{
		return param;
	}
};

template<typename T>
class Sum : public Formula<T>
{
	Formula<T>* first;
	Formula<T>* second;
public:
	Sum(Formula<T>* f, Formula<T>* s)
	{
		first = f;
		second = s;
	}

	virtual T result()
	{
		return first->result() + second->result();
	}
};

template<typename T>
class Substract : public Formula<T>
{
	Formula<T>* first;
	Formula<T>* second;
public:
	Substract(Formula<T>* f, Formula<T>* s)
	{
		first = f;
		second = s;
	}

	virtual T result()
	{
		return first->result() - second->result();
	}
};

template<typename T>
class Div : public Formula<T>
{
	Formula<T>* first;
	Formula<T>* second;
public:
	Div(Formula<T>* f, Formula<T>* s)
	{
		first = f;
		second = s;
	}

	virtual T result()
	{
		return first->result() / second->result();
	}
};

template<typename T>
class Pow : public Formula<T>
{
	Formula<T>* first;
	Formula<T>* second;
public:
	Pow(Formula<T>* f, Formula<T>* s)
	{
		first = f;
		second = s;
	}

	virtual T result()
	{
		return first->result() ^ second->result();
	}
};

int main()
{
	ID<int> a(3);
	ID<int> c(5);
	std::cout << a.result() << std::endl;
	Sum<int> b(&a, &c);
	std::cout << b.result() << std::endl;
	Substract<int> d(&c, &a);
	std::cout << d.result() << std::endl;
	Div<int> div(&b, &a);
	std::cout << div.result() << std::endl;
	//Pow<int> p(&c, &a);
	//std::cout << p.result() << std::endl;



	Formula<int>* arr[2];
	arr[0] = &a;
	arr[1] = &b;
	std::cout << arr[1]->result();






	return 0;
}