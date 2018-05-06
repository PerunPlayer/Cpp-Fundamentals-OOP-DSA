#include "stdafx.h"
#include "Car.h"

Car::Car()
{
	init();
}

Car::Car(const Car& other)
{
	init();
	copy(other);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}

	return *this;
}

Car::~Car()
{
	destroy();
}

Car::Car(Colour c, char* m, unsigned short y, unsigned short s, unsigned short ms, char* mod, unsigned short d, unsigned short p)
{
	setColour(c);
	setManufactorer(m);
	setYear(y);
	setSeats(s);
	setMaxSpeed(ms);
	myStrCpy(model, mod);
	doors = d;
	powerInHP = p;
}

unsigned short Car::getDoors() const
{
	return doors;
}

void Car::setDoors(const unsigned short d)
{
	doors = d;
}

unsigned short Car::getPowerInHP() const
{
	return powerInHP;
}

void Car::setPowerInHP(const unsigned short p)
{
	powerInHP = p;
}

char* Car::getModel() const
{
	return model;
}

void Car::setModel(const char* mod)
{
	myStrCpy(model, mod);
}

void Car::init()
{
	Vehicle::init();
	doors = powerInHP = 0;
	model = nullptr;
}

void Car::copy(const Car& other)
{
	Vehicle::copy(other);

	doors = other.doors;
	powerInHP = other.powerInHP;
	myStrCpy(model, other.model);
}

void Car::destroy()
{
	delete[] model;
}
