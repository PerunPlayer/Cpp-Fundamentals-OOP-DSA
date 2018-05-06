#include "stdafx.h"
#include "Bicycle.h"

Bicycle::Bicycle()
{
	init();
}

//Bicycle::Bicycle(const Bicycle& other) : Vehicle(other) or call Vehicle::copy(other)           line 94
Bicycle::Bicycle(const Bicycle& other)
{
	init();
	copy(other);
}

Bicycle& Bicycle::operator=(const Bicycle& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}

	return *this;
}

Bicycle::~Bicycle()
{
	destroy();
}

Bicycle::Bicycle(Colour c, char* m, unsigned short y, unsigned short s, unsigned short ms, unsigned short g, bool l, bool b, char* n)
{
	setColour(c);
	setManufactorer(m);
	setYear(y);
	setSeats(s);
	setMaxSpeed(ms);
	gears = g;
	hasLighters = l;
	hasABell = b;
	myStrCpy(name, n);
}

unsigned short Bicycle::getGears() const
{
	return gears;
}

void Bicycle::setGears(const unsigned short g)
{
	gears = g;
}

bool Bicycle::getHasLighters() const
{
	return hasLighters;
}

void Bicycle::setHasLighters(const bool l)
{
	hasLighters = l;
}

bool Bicycle::getHasABell() const
{
	return hasABell;
}

void Bicycle::setHasABell(const bool b)
{
	hasABell = b;
}

char* Bicycle::getName() const
{
	return name;
}

void Bicycle::setName(const char* n)
{
	myStrCpy(name, n);
}

void Bicycle::init()
{
	Vehicle::init();
	gears = 0;
	hasLighters = hasABell = 0;
	name = nullptr;
}

void Bicycle::copy(const Bicycle& other)
{
	Vehicle::copy(other);

	//setColour(other.getColour());
	//setManufactorer(other.getManufactorer());
	//setYear(other.getYear());
	//setSeats(other.getSeats());
	//setMaxSpeed(other.getMaxSpeed());

	gears = other.gears;
	hasLighters = other.hasLighters;
	hasABell = other.hasABell;
	myStrCpy(name, other.name);
}

void Bicycle::destroy()
{
	delete[] name;
}
