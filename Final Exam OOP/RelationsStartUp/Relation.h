#pragma once

#include <cmath>

template <typename T, typename U>
class Relation
{
private:
	T* ts;
	U* us;
	size_t count, capacity;

public:
	Relation<T, U>();
	Relation<T, U>(const Relation<T, U>& other);
	Relation<T, U>& operator=(const Relation<T, U>& other);
	~Relation<T, U>();

	bool operator[](const T& t);
	Relation<T, U> operator*(Relation<T, U> r);
	Relation<T, U>& operator*=(Relation<T, U> r);
	bool isFunction();
	void addPair(T t, U u);
	size_t getcount() const;
	void resize();
};

template<typename T, typename U>
inline Relation<T, U>::Relation()
{
	count = capacity = 8;
	ts = new T[capacity];
	us = new U[capacity];
}

template<typename T, typename U>
inline Relation<T, U>::Relation(const Relation<T, U>& other)
{
	count = other.count;
	count = other.count;
	capacity = other.capacity;
	capacity = other.capacity;
	ts = new T[capacity];
	us = new U[capacity];

	for (size_t i = 0; i < count; i++)
	{
		ts[i] = other.ts[i];
	}
	for (size_t i = 0; i < count; i++)
	{
		us[i] = other.us[i];
	}
}

template<typename T, typename U>
inline Relation<T, U>::~Relation()
{
	count = capacity = count = capacity = 0;
	delete[] ts;
	delete[] us;
}

template<typename T, typename U>
inline Relation<T, U>& Relation<T, U>::operator=(const Relation<T, U>& other)
{
	if (this != &other)
	{
		delete[] ts;
		delete[] us;

		count = other.count;
		count = other.count;
		capacity = other.capacity;
		capacity = other.capacity;
		ts = new T[capacity];
		us = new U[capacity];

		for (size_t i = 0; i < count; i++)
		{
			ts[i] = other.ts[i];
		}
		for (size_t i = 0; i < count; i++)
		{
			us[i] = other.us[i];
		}

		return *this;
	}
}

template<typename T, typename U>
inline bool Relation<T, U>::operator[](const T& t)
{
	size_t index;
	for (size_t i = 0; i < count; i++)
	{
		if ((ts[i] == t) && (us[i] != nullptr))
		{
			return true;
		}
	}

	return false;
}

template<typename T, typename U>
inline Relation<T, U> Relation<T, U>::operator*(Relation<T, U> r)
{
	Relation<T, U> result;

	for (size_t i = 0; i < count; i++)
	{
		for (size_t k = 0; k < r.count; k++)
		{
			if ((ts[i] == r.ts[k]) && (us[i] == r.us[k]))
			{
				result.addPair(ts[i], us[i]);
			}
		}
	}

	return result;
}

template<typename T, typename U>
inline Relation<T, U>& Relation<T, U>::operator*=(Relation<T, U> r)
{
	Relation<T, U> result;

	for (size_t i = 0; i < count; i++)
	{
		for (size_t k = 0; k < r.count; k++)
		{
			if ((ts[i] == r.ts[k]) && (us[i] == r.us[k]))
			{
				result.addPair(ts[i], us[i]);
			}
		}
	}

	this = result;

	return *this;
}

template<typename T, typename U>
inline bool Relation<T, U>::isFunction()
{
	size_t meetings;
	for (size_t i = 0; i < count; i++)
	{
		meetings = 0;
		for (size_t k = 0; k < count; k++)
		{
			if (ts[i] == us[k])
			{
				meetings++;
			}
		}
		if (meetings != 1)
		{
			return false;
		}
	}

	return true;
}

template<typename T, typename U>
inline void Relation<T, U>::addPair(T t, U u)
{
	if (count >= capacity)
	{
		resize();
	}

	T* tempt = new T[capacity];
	U* tempu = new U[capacity];

	for (size_t i = 0; i < count; i++)
	{
		tempt[i] = ts[i];
		tempu[i] = us[i];
	}

	tempt[count] = t;
	tempu[count] = u;

	delete[] ts;
	delete[] us;

	ts = tempt;
	us = tempu;
}

template<typename T, typename U>
inline size_t Relation<T, U>::getcount() const
{
	return count;
}

template<typename T, typename U>
inline void Relation<T, U>::resize()
{
	capacity = capacity * 2;
	T* tempt = new T[capacity];
	U* tempu = new U[capacity];

	for (size_t i = 0; i < count; i++)
	{
		tempt[i] = ts[i];
		tempu[i] = us[i];
	}
	
	delete[] ts;
	delete[] us;

	ts = tempt;
	us = tempu;
}
