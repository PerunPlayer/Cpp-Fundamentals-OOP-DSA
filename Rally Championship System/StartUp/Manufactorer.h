#pragma once

#include "Participant.h"
#include "String.h"

const unsigned short MAX_NUMBER_OF_MANUFACTORERS = 10;

class Manufactorer : public Participant
{
public:
	Manufactorer(String _name, unsigned short _crewSize);
	Manufactorer();

	unsigned short getCrewSize() const;
	ParticipantType getType() const;
	void print(std::ostream& out) const;

private:
	unsigned short crewSize;
	static unsigned short currentNumber;
};