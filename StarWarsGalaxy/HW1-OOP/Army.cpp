#include "stdafx.h"
#include "Army.h"

Army::Army()
{
	init();
}

Army::Army(const Army& other)
{
	init();
	copy(other);
}

Army& Army::operator=(const Army& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

Army::~Army()
{
	destroy();
}

void Army::add(Stormtrooper trooper)
{
	if (this->size >= this->capacity)
	{
		this->resize();
	}
	this->container[this->size++] = trooper;
}

void Army::remove(Stormtrooper& trooper)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (this->container[i] == trooper)
		{
			for (size_t j = i; j < capacity - 1; j++)
			{
				container[j] = container[j + 1];
			}
			size--;
			return;
		}
	}
}

unsigned int Army::sizeOf()
{
	return size;
}

void Army::init()
{
	this->capacity = 8;
	this->size = 0;
	this->container = new Stormtrooper[this->capacity];
}

void Army::destroy()
{
	this->size = 0;
	this->capacity = 0;
	delete[] this->container;
}

void Army::copy(const Army& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->container = new Stormtrooper[this->capacity];

	for (size_t i = 0; i < this->capacity; i++)
	{
		this->container[i] = other.container[i];
	}
}

void Army::resize()
{
	this->capacity *= 2;

	Stormtrooper* temp = new Stormtrooper[this->capacity];
	for (size_t i = 0; i < this->capacity; i++)
	{
		temp[i] = this->container[i];
	}

	delete[] this->container;
	this->container = temp;
}

