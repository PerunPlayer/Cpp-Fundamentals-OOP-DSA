#pragma once

#include "String.h"

const unsigned short MAX_NUMBER_OF_PARTICIPANTS = 20;

enum ParticipantType
{
	crewMember,
	pilot
};

class Participant
{
private:
	String name;
	static unsigned short currentNumber;

public:
	Participant(String _name);
	Participant();

	String getName() const;
	virtual ParticipantType getType() const = 0;
	virtual void print(std::ostream& out) const = 0;

	static unsigned short getCurrentNumberOfParticipants();
};