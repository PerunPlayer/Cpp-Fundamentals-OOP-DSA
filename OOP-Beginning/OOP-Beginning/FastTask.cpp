#include "stdafx.h"
#include <cassert>

class IntSet
{
public:
	virtual bool member(int x) = 0;
};

class Interval : public IntSet
{
public:
	bool member(int x)
	{
		return (x >= a && x <= b);
	}

	Interval()
	{
		this->a = 0;
		this->b = 0;
	}
	Interval(int _a, int _b)
	{
		this->a = _a;
		this->b = _b;

		assert(a <= b);
	}

private:
	int a;
	int b;
};

class EvenNumbers : public IntSet
{
public:
	bool member(int x)
	{
		return (x % 2 == 0);
	}
};

class Container : public IntSet
{
private:
	int* set;
	size_t size;
	size_t capacity;

	void init()
	{
		this->capacity = 4;
		this->size = 0;
		this->set = new int[capacity];
	}

	void copy(const Container& other)
	{
		capacity = other.capacity;
		size = other.size;
		set = new int[capacity];
		for (size_t i = 0; i < capacity; i++)
		{
			set[i] = other.set[i];
		}
	}
	void destroy()
	{
		delete[] set;
	}

public:
	Container()
	{
		init();
	}
	Container(const Container& other)
	{
		init();
		copy(other);
	}

	Container& operator=(const Container& other)
	{
		if (this != &other)
		{
			destroy();
			init();
			copy(other);
		}
		return *this;
	}

	~Container()
	{
		destroy();
	}

	Container(size_t _capacity)
	{
		capacity = _capacity;
		size = 0;
		set = new int[capacity];
	}

	bool member(int x)
	{
		for (size_t i = 0; i < capacity; i++)
		{
			if (set[i] == x)
			{
				return true;
			}
		}
		return false;
	}

	bool add(int x)
	{
		if (size < capacity && !member(x))
		{
			set[size] = x;
			size++;
			return true;
		}
		return false;
	}
};

bool elementInAllSets(int el, IntSet* sets[], size_t nSets)
{
	for (size_t i = 0; i < nSets; i++)
	{
		if (!sets[i]->member(el))
		{
			return false;
		}
	}
	return true;
}

//int main()
//{
//	Interval i1(0, 100), i2(99, 200);
//
//	assert(i1.member(50));
//	assert(!i2.member(98));
//
//	EvenNumbers en;
//
//	assert(en.member(50));
//	assert(!en.member(51));
//
//	Container c1(5), c2(3);
//	c1.add(1);
//	c1.add(2);
//	c2.add(100);
//
//	assert(!c1.member(100));
//	assert(c1.member(2));
//
//	c1 = c2;
//
//	assert(c1.member(100));
//	assert(c2.member(100));
//
//	IntSet* sets[] = { &i1, &i2, &en, &c1, &c2 };
//
//	assert(elementInAllSets(100, sets, 5));
//
//	return 0;
//}