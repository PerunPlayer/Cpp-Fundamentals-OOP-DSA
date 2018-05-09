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
		T res = first->result();
		for (size_t i = 0; i < second->result() - 1; i++)
		{
			res *= first->result();
		}
		return res;
	}
};

//int main()
//{
//	ID<int> a(3);
//	ID<int> c(5);
//	std::cout << a.result() << std::endl;
//	Sum<int> b(&a, &c);
//	std::cout << b.result() << std::endl;
//	Substract<int> d(&c, &a);
//	std::cout << d.result() << std::endl;
//	Div<int> div(&b, &a);
//	std::cout << div.result() << std::endl;
//	Pow<int> p(&c, &a);
//	std::cout << p.result() << std::endl;
//
//
//
//	Formula<int>* arr[2];
//	arr[0] = &a;
//	arr[1] = &b;
//	std::cout << arr[1]->result();
//
//	return 0;
//}

//template<class T>
//class Formula {
//public:
//	virtual T value() const = 0;
//	//virtual char getFLType() const = 0;// method to get the first letter of the formula's type -> if we use Factory design model
//	virtual void selfCopy(Formula<T>*&) = 0;
//	virtual ~Formula() {}
//};
//template<class T>
//class ID :public Formula<T> {
//	T funcResult;
//public:
//	ID(const T&);
//	virtual T value() const override;//override specifier works with c++11 or above
//	virtual ~ID() {}
//	virtual void selfCopy(Formula<T>*&);
//};
//template<class T>
//ID<T>::ID(const T& element) :funcResult(element) {}
//template<class T>
//T ID<T>::value() const {
//	return funcResult;
//}
//template<class T>
//void ID<T>::selfCopy(Formula<T>*& destination) {
//	destination = new ID<T>(*this);
//}
//template<class T>
//class Sum :public Formula<T> {
//	T funcResult;
//public:
//	Sum(const Formula<T>* firstArg, const Formula<T>* secondArg);
//	virtual T value() const override;
//	virtual void selfCopy(Formula<T>*&) override;
//	virtual ~Sum() {}
//};
//template<class T>
//Sum<T>::Sum(const Formula<T>* firstArg, const Formula<T>* secondArg) {
//	funcResult = firstArg->value() + secondArg->value();
//}
//template<class T>
//T Sum<T>::value() const {
//	return funcResult;
//}
//template<class T>
//void Sum<T>::selfCopy(Formula<T>*& destination) {
//	destination = new Sum<T>(*this);
//}
//template<class T>
//void polyCopy(Formula<T>**&dest, Formula<T>**target, int targetSize) { // we have two arrays of Formula*
//																	   //std::cout << target[0]->value();
//	dest = new Formula<T>*[targetSize];
//	for (int i = 0; i < targetSize; i++) {
//		target[i]->selfCopy(dest[i]);
//	}
//}
//int main() {
//	ID<int> id1(2);
//	ID<int> id2(3);
//	ID<int> id3(4);
//	std::cout << id1.value();
//	Sum<int> sum1(&id1, &id2);
//	std::cout << sum1.value();
//	Sum<int> sum2(&id2, &id3);
//	Formula<int>** arr = new Formula<int>*[5];
//	arr[0] = &id1;
//	arr[1] = &id2;
//	arr[2] = &id3;
//	arr[3] = &sum1;
//	arr[4] = &sum2;
//	//now we have polymorphic array, containing all the formulas above
//	Formula<int>** newarray;//will hold the array
//	polyCopy<int>(newarray, arr, 5);
//	std::cout << std::endl;
//	std::cout << newarray[0]->value();
//	int c;
//	std::cin >> c;
//}