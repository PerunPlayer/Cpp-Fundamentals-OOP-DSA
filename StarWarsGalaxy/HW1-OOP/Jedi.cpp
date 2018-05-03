#include "stdafx.h"
#include "Jedi.h"

void Jedi::init()
{
	name = new char[1];
	name[0] = 0;
	spicies = new char[1];
	spicies[0] = 0;
	militaryRank = new char[1];
	militaryRank[0] = 0;
	midichlorian = 0;
	rank = (JediRank)0;
}

void Jedi::copy(const Jedi& other)
{
	myStrCpy(name, other.name);
	myStrCpy(spicies, other.spicies);
	myStrCpy(militaryRank, other.militaryRank);
	midichlorian = other.midichlorian;
	rank = other.rank;
	planet = other.planet;
}

void Jedi::destroy()
{
	delete[] name;
	delete[] spicies;
	delete[] militaryRank;
	midichlorian = 0;
	rank = (JediRank)0;
}

void Jedi::print(std::ostream& out)
{
	out << "[";
	out << name << " - " << spicies << " - " << militaryRank << ", have " << midichlorian << " midi-chlorians and is " << " from " << planet << " - ";
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

Jedi::Jedi(char* _name, JediRank _rank, double _midichlorian, Planet _planet, char* _spicies, char* _militaryRank)
{
	myStrCpy(this->name, _name);
	myStrCpy(this->spicies, _spicies);
	myStrCpy(this->militaryRank, _militaryRank);
	this->rank = _rank;
	this->midichlorian = _midichlorian;
	this->planet = _planet;
}

bool Jedi::operator==(Jedi& other)
{
	if ((areEqualStr(this->name, other.name) || (this->name == other.name))
		&& (this->rank == other.rank) && (this->midichlorian == other.midichlorian)
		&& (this->planet == other.planet) && ((this->spicies == other.spicies) || areEqualStr(this->spicies, other.spicies))
		&& ((this->militaryRank == other.militaryRank) || areEqualStr(this->militaryRank, other.militaryRank)))
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, Jedi& jedi)
{
	jedi.print(out);
	return out;
}
