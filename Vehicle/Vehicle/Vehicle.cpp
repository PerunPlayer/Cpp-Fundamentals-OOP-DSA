#include "stdafx.h"
#include "Vehicle.h"

Vehicle::Vehicle()
{
	init();
}

Vehicle::Vehicle(const Vehicle& other)
{
	init();
	copy(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}

	return *this;
}

Vehicle::~Vehicle()
{
	destroy();
}

Vehicle::Vehicle(Colour _colour, char* _manufactorer, unsigned short _year, unsigned short _seats, unsigned short _maxSpeed)
{
	this->colour = _colour;
	myStrCpy(this->manufacturer, _manufactorer);
	this->year = _year;
	this->seats = _seats;
	this->maxSpeed = _maxSpeed;
}

Colour Vehicle::getColour() const
{
	return colour;
}

void Vehicle::setColour(const Colour c)
{
	colour = c;
}

char* Vehicle::getManufactorer() const
{
	return manufacturer;
}

void Vehicle::setManufactorer(const char* _manufactorer)
{
	delete[] manufacturer;
	myStrCpy(manufacturer, _manufactorer);
}

unsigned short Vehicle::getYear() const
{
	return year;
}

void Vehicle::setYear(const unsigned short y)
{
	year = y;
}

unsigned short Vehicle::getSeats() const
{
	return seats;
}

void Vehicle::setSeats(const unsigned short s)
{
	seats = s;
}

unsigned short Vehicle::getMaxSpeed() const
{
	return maxSpeed;
}

void Vehicle::setMaxSpeed(const unsigned short ms)
{
	maxSpeed = ms;
}

void Vehicle::myStrCpy(char*& str1, const char* str2)
{
	if (str2)
	{
		unsigned length = 0;
		for (unsigned i = 0; str2[i] != '\0'; i++)
		{
			length++;
		}
		str1 = new char[length + 1];
		for (unsigned i = 0; str2[i] != '\0'; i++)
		{
			str1[i] = str2[i];
		}
		str1[length] = '\0';
	}
}

void Vehicle::copy(const Vehicle& other)
{
	myStrCpy(manufacturer, other.manufacturer);
	colour = other.colour;
	year = other.year;
	seats = other.seats;
	maxSpeed = other.maxSpeed;
}

void Vehicle::init()
{
	manufacturer = nullptr;
	year = seats = maxSpeed = 0;
	colour = (Colour)0;
}

void Vehicle::destroy()
{
	delete[] manufacturer;
}