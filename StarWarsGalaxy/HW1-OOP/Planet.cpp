#include "stdafx.h"
#include "Planet.h"

Planet::Planet()
{
	init();
}

Planet::Planet(const Planet& other)
{
	init();
	copy(other);
}

Planet& Planet::operator=(const Planet& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

Planet::~Planet()
{
	destroy();
}

Planet::Planet(char* _name, char* _planetSystem, char* _republic)
{
	myStrCpy(this->name, _name);
	myStrCpy(this->planetSystem, _planetSystem);
	myStrCpy(this->republic, _republic);
}

Planet::Planet(Planet&& other)
{
	copy(other);

	delete[] other.name;
	delete[] other.planetSystem;
	delete[] other.republic;
}

Planet& Planet::operator=(Planet&& other)
{
	if (this != &other) 
	{
		destroy();
		init();
		copy(other);

		delete[] other.name;
		delete[] other.planetSystem;
		delete[] other.republic;
	}
	return *this;
}

bool Planet::operator==(Planet& other)
{
	if (((this->name == other.name) || areEqualStr(this->name, other.name))
		&& ((this->planetSystem == other.planetSystem) || areEqualStr(this->planetSystem, other.planetSystem))
		&& ((this->republic == other.republic) || areEqualStr(this->republic, other.republic)))
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, Planet& planet)
{
	planet.print(out);
	return out;
}

void Planet::init()
{
	name = new char[1];
	name[0] = 0;
	planetSystem = new char[1];
	planetSystem[0] = 0;
	republic = new char[1];
	republic[0] = 0;
}

void Planet::copy(const Planet& other)
{
	myStrCpy(name, other.name);
	myStrCpy(planetSystem, other.planetSystem);
	myStrCpy(republic, other.republic);
}

void Planet::destroy()
{
	delete[] name;
	delete[] planetSystem;
	delete[] republic;
}

void Planet::print(std::ostream& out)
{
	out << "[";
	out << name << " from system: " << planetSystem << " The planet is part of the " << republic;
	out << "]";
}

void myStrCpy(char*& dest, const char* src)
{
	if (src)
	{
		unsigned length = 0;
		for (unsigned i = 0; src[i] != '\0'; i++)
		{
			length++;
		}
		dest = new char[length + 1];
		for (unsigned i = 0; src[i] != '\0'; i++)
		{
			dest[i] = src[i];
		}
		dest[length] = '\0';
	}
}

bool areEqualStr(const char* str1, const char* str2)
{
	unsigned int i, j;
	for (i = 0; str1[i] != '\0'; i++) {}
	for (j = 0; str2[j] != '\0'; j++) {}
	if (i == j)
	{
		for (size_t k = 0; k <= i; k++)
		{
			if (str1[k] != str2[k])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
