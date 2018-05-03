#include "stdafx.h"
#include "JediTemple.h"

JediTemple::JediTemple()
{
	init();
}

JediTemple::JediTemple(const JediTemple& other)
{
	init();
	copy(other);
}

JediTemple& JediTemple::operator=(const JediTemple& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

JediTemple::~JediTemple()
{
	destroy();
}

void JediTemple::add(const Jedi& jedi)
{
	if (this->size >= this->capacity)
	{
		this->resize();
	}
	this->size++;
	this->container[this->size - 1] = jedi;
}

void JediTemple::remove(Jedi& jedi)
{
	for (size_t i = 0; i < size; i++)
	{
		if (this->container[i] == jedi)
		{
			this->container[i] = this->container[size - 1];
			size--;
			return;
		}
	}	
}

unsigned int JediTemple::sizeOf()
{
	return this->size;
}

void JediTemple::init()
{
	this->capacity = 8;
	this->size = 0;
	this->container = new Jedi[this->capacity];
}

void JediTemple::destroy()
{
	this->size = 0;
	this->capacity = 0;
	delete[] this->container;
}

void JediTemple::copy(const JediTemple& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->container = new Jedi[this->capacity];

	for (size_t i = 0; i < this->capacity; i++)
	{
		this->container[i] = other.container[i];
	}
}

void JediTemple::resize()
{
	this->capacity *= 2;

	Jedi* temp = new Jedi[this->capacity];
	for (size_t i = 0; i < this->capacity; i++)
	{
		temp[i] = this->container[i];
	}

	delete[] this->container;
	this->container = temp;
}
