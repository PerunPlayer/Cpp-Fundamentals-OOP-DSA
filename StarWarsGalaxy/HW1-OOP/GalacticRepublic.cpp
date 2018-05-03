#include "stdafx.h"
#include "GalacticRepublic.h"

GalacticRepublic::GalacticRepublic()
{
	init();
}

GalacticRepublic::GalacticRepublic(const GalacticRepublic& other)
{
	init();
	copy(other);
}

GalacticRepublic& GalacticRepublic::operator=(const GalacticRepublic& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

GalacticRepublic::~GalacticRepublic()
{
	destroy();
}

GalacticRepublic::GalacticRepublic(char* name, const JediTemple& temple, const Army& army, const Galaxy& galaxy)
{
	myStrCpy(this->name, name);
	this->jediTemple = temple;
	this->army = army;
	this->galaxy = galaxy;
}

void GalacticRepublic::printAllJedi(Planet& planet)
{
	unsigned int limit = this->jediTemple.sizeOf();

	for (size_t i = 0; i < limit; i++)
	{
		if (this->jediTemple.container[i].planet == planet)
		{
			std::cout << this->jediTemple.container[i] << std::endl;
		}
	}
}

void GalacticRepublic::printAllStormtroopers(Planet& planet)
{
	unsigned int limit = this->army.sizeOf();

	for (size_t i = 0; i < limit; i++)
	{
		if (this->army.container[i].planet == planet)
		{
			std::cout << this->army.container[i] << std::endl;
		}
	}
}

void GalacticRepublic::printAllPlanets(std::ostream& out)
{
	unsigned int limit = this->galaxy.sizeOf();

	for (size_t i = 0; i < limit; i++)
	{
		out << this->galaxy.planets[i] << std::endl;
	}
}

void GalacticRepublic::printAllJedi(std::ostream& out)
{
	unsigned int limit = this->jediTemple.sizeOf();

	for (size_t i = 0; i < limit; i++)
	{
		out << this->jediTemple.container[i] << std::endl;
	}
}

void GalacticRepublic::printAllStormtroopers(std::ostream & out)
{
	unsigned int limit = this->army.sizeOf();

	for (size_t i = 0; i < limit; i++)
	{
		out << this->army.container[i] << std::endl;
	}
}

JediTemple& GalacticRepublic::getTemple()
{
	return this->jediTemple;
}

Army& GalacticRepublic::getArmy()
{
	return this->army;
}

Galaxy& GalacticRepublic::getGalaxy()
{
	return this->galaxy;
}

void GalacticRepublic::init()
{
	name = new char[1];
	name[0] = 0;
}

void GalacticRepublic::destroy()
{
	delete[] name;
}

void GalacticRepublic::copy(const GalacticRepublic& other)
{
	myStrCpy(this->name, other.name);
	this->jediTemple = other.jediTemple;
	this->army = other.army;
	this->galaxy = other.galaxy;
}
