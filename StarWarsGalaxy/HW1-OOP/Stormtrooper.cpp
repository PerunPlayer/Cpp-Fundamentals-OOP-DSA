#include "stdafx.h"
#include "Stormtrooper.h"

void Stormtrooper::init()
{
	id = new char[1];
	id[0] = 0;
	type = new char[1];
	type[0] = 0;
	rank = (TrooperRank)0;
}

void Stormtrooper::copy(const Stormtrooper& other)
{
	myStrCpy(id, other.id);
	myStrCpy(type, other.type);
	rank = other.rank;
	planet = other.planet;
}

void Stormtrooper::print(std::ostream& out)
{
	out << "[";
	out << id << " - " << type << " - " <<  " from " << planet << " with rank of ";
	switch (this->rank)
	{
	case 0:
		out << "Trooper";
		break;
	case 1:
		out << "SquadLeader";
		break;
	case 2:
		out << "PlatoonLeader";
		break;
	case 3:
		out << "CompanyLeader";
		break;
	case 4:
		out << "BattalionCommander";
		break;
	case 5:
		out << "RegimentCommander";
		break;
	case 6:
		out << "GeneralOfLegion";
		break;

	default: out << "Trooper";
		break;
	}
	out << "]";
}

void Stormtrooper::destroy()
{
	delete[] id;
	delete[] type;
	rank = (TrooperRank)0;
}

Stormtrooper::Stormtrooper()
{
	init();
}

Stormtrooper::Stormtrooper(const Stormtrooper& other)
{
	init();
	copy(other);
}

Stormtrooper& Stormtrooper::operator=(const Stormtrooper& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

Stormtrooper::~Stormtrooper()
{
	destroy();
}

Stormtrooper::Stormtrooper(char* _id, TrooperRank _rank, char* _type, Planet _planet)
{
	myStrCpy(this->id, _id);
	myStrCpy(this->type, _type);
	this->rank = _rank;
	this->planet = _planet;
}

bool Stormtrooper::operator==(Stormtrooper& other)
{
	if (((this->id == other.id) || areEqualStr(this->id, other.id)) 
	 && ((this->type == other.type) || areEqualStr(this->type, other.type))
	 && (this->rank == other.rank) && (this->planet == other.planet))
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, Stormtrooper& trooper)
{
	trooper.print(out);
	return out;
}