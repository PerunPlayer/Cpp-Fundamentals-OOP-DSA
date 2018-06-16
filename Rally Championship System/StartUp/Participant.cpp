#include "stdafx.h"
#include "Participant.h"

Participant::Participant(String _name)
{
	if (currentNumber >= MAX_NUMBER_OF_PARTICIPANTS)
	{
		throw std::out_of_range("Exceeds the max possible count of participants, which is 20.");
	}

	name = _name;
	currentNumber++;
}

Participant::Participant()
{
}

unsigned short Participant::currentNumber = 0;

String Participant::getName() const
{
	return name;
}

unsigned short Participant::getCurrentNumberOfParticipants()
{
	return currentNumber;
}
