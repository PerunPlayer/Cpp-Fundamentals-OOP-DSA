#include "stdafx.h"
#include "Jedi.h"

void Jedi::init()
{
	name = new char[1];
	name[0] = 0;
	species = new char[1];
	species[0] = 0;
	militaryRank = new char[1];
	militaryRank[0] = 0;
	midichlorian = 0;
	rank = (JediRank)0;
}

void Jedi::copy(const Jedi& other)
{
	myStrCpy(name, other.name);
	myStrCpy(species, other.species);
	myStrCpy(militaryRank, other.militaryRank);
	midichlorian = other.midichlorian;
	rank = other.rank;
	planet = other.planet;
}

void Jedi::destroy()
{
	delete[] name;
	delete[] species;
	delete[] militaryRank;
	midichlorian = 0;
	rank = (JediRank)0;
}

void Jedi::print(std::ostream& out)
{
	out << "[";
	out << name << " - " << species << " - " << militaryRank << ", have " << midichlorian << " midi-chlorians and is " << " from " << planet << " - ";
	switch (this->rank)
	{
	case 0:
		out << "JediInitiate";
		break;
	case 1:
		out << "JediPadawan";
		break;
	case 2:
		out << "JediKnight";
		break;
	case 3:
		out << "JediMaster";
		break;

	default: out << "JediInitiate";
		break;
	}
	out << "]";
}

Jedi::Jedi()
{
	init();
}

Jedi::Jedi(const Jedi& other)
{
	init();
	copy(other);
}

Jedi& Jedi::operator=(const Jedi& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

Jedi::~Jedi()
{
	destroy();
}

Jedi::Jedi(char* _name, JediRank _rank, double _midichlorian, Planet _planet, char* _species, char* _militaryRank)
{
	myStrCpy(this->name, _name);
	myStrCpy(this->species, _species);
	myStrCpy(this->militaryRank, _militaryRank);
	this->rank = _rank;
	this->midichlorian = _midichlorian;
	this->planet = _planet;
}

Jedi::Jedi(Jedi&& other)
{
	copy(other);

	other.name = nullptr;
	other.species = nullptr;
	other.militaryRank = nullptr;
}

Jedi& Jedi::operator=(Jedi&& other)
{
	if (this != &other) 
	{
		destroy();
		init();
		copy(other);

		delete[] other.name;
		delete[] other.species;
		delete[] other.militaryRank;

		/*other.name = nullptr;
		other.species = nullptr;
		other.militaryRank = nullptr;*/
	}

	return *this;
}

bool Jedi::operator==(Jedi& other)
{
	if ((areEqualStr(this->name, other.name) || (this->name == other.name))
		&& (this->rank == other.rank) && (this->midichlorian == other.midichlorian)
		&& (this->planet == other.planet) && ((this->species == other.species) || areEqualStr(this->species, other.species))
		&& ((this->militaryRank == other.militaryRank) || areEqualStr(this->militaryRank, other.militaryRank)))
	{
		return true;
	}
	return false;
}

const double& Jedi::getMidichlorian() const
{
	return this->midichlorian;
}

void Jedi::setMidichlorian(const double midichlorian)
{
	this->midichlorian = midichlorian;
}

std::ostream& operator<<(std::ostream& out, Jedi& jedi)
{
	jedi.print(out);
	return out;
}
