#include "stdafx.h"
#include "Galaxy.h"

Galaxy::Galaxy()
{
	init();
}

Galaxy::Galaxy(const Galaxy& other)
{
	init();
	copy(other);
}

Galaxy& Galaxy::operator=(const Galaxy& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

Galaxy::~Galaxy()
{
	destroy();
}

Galaxy::Galaxy(char* _name, Planet* _planets, unsigned int _countOfPlanets)
{
	myStrCpy(this->name, _name);
	size = _countOfPlanets;
	capacity = size * 2;
	this->planets = new Planet[capacity];

	for (int i = 0; i < size; i++)
	{
		this->planets[i] = _planets[i];
	}
}

Galaxy::Galaxy(Galaxy&& other)
{
	copy(other);

	delete[] other.name;
	delete[] other.planets;
}

Galaxy& Galaxy::operator=(Galaxy&& other)
{
	if (this != &other) 
	{
		destroy();
		init();
		copy(other);

		delete[] other.name;
		delete[] other.planets;
	}
	return *this;
}

void Galaxy::add(Planet planet)
{
	if (this->size >= this->capacity)
	{
		this->resize();
	}
	this->planets[this->size++] = planet;
}

void Galaxy::remove(Planet& planet)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (this->planets[i] == planet)
		{
			for (size_t j = i; j < capacity - 1; j++)
			{
				planets[j] = planets[j + 1];
			}
			size--;
			return;
		}
	}
}

unsigned int Galaxy::sizeOf()
{
	return size;
}

void Galaxy::init()
{
	name = new char[1];
	name[0] = 0;
	size = 0;
	capacity = 8;
	planets = new Planet[this->capacity];
}

void Galaxy::copy(const Galaxy& other)
{
	myStrCpy(this->name, other.name);

	this->size = other.size;
	this->capacity = other.capacity;
	this->planets = new Planet[this->capacity];

	for (size_t i = 0; i < this->capacity; i++)
	{
		this->planets[i] = other.planets[i];
	}
}

void Galaxy::destroy()
{
	delete[] name;
	delete[] planets;
	size = 0;
	capacity = 0;
}

void Galaxy::resize()
{
	capacity *= 2;

	Planet* temp = new Planet[capacity];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = planets[i];
	}

	delete[] planets;
	planets = temp;
}
