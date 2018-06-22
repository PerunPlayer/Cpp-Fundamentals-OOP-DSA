#include "stdafx.h"
#include "Manufactorer.h"

Manufactorer::Manufactorer(String _name, unsigned short _crewSize) : Participant(_name)
{
	if (currentNumber >= MAX_NUMBER_OF_MANUFACTORERS)
	{
		throw std::out_of_range("Exceeds the max possible count of manufactorers, which is 10.");
	}

	crewSize = _crewSize;
	currentNumber++;
}

Manufactorer::Manufactorer()
{
}

unsigned short Manufactorer::currentNumber = 0;

unsigned short Manufactorer::getCrewSize() const
{
	return crewSize;
}

ParticipantType Manufactorer::getType() const
{
	return crewMember;
}

void Manufactorer::print(std::ostream& out) const
{
	out << "Manufactorer: " << getName() << " with " << getCrewSize() << " crew members\n";
}
