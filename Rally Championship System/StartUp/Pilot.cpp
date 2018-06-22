#include "stdafx.h"
#include "Pilot.h"

unsigned short Pilot::currentNumber = 0;

Pilot::Pilot(String _name, String _manufactorer, Car _car) : Participant(_name)
{
	if (currentNumber >= MAX_NUMBER_OF_PILOTS)
	{
		throw std::out_of_range("Exceeds the max possible count of pilots, which is 10.");
	}

	currentNumber++;
	car = _car;
	manufactorer = _manufactorer;

	save();
}

Pilot::Pilot() {}

void Pilot::print(std::ostream& out) const
{
	out << "Pilot: " << getName() << " racing with " << car.getModel() << " for " << getManufactorer() << "\n";
}

Car Pilot::getCar() const
{
	return car;
}

String Pilot::getManufactorer() const
{
	return manufactorer;
}

ParticipantType Pilot::getType() const
{
	return pilot;
}

double Pilot::getRacingIndex(PavementType _pavement, TrackBalance predominant) const
{
	double index;
	if (speciality == betterAtEverything)
	{
		index = 5;
	}
	else if (((speciality == betterAtCurves) && (predominant == moreCurves)) ||
		((speciality == betterAtStraights) && (predominant == moreStraightLines)))
	{
		index = 4.5;
	}
	else
	{
		index = 3;
	}

	if (favPavement == _pavement)
	{
		index *= 3;
	}

	index *= car.getRacingIndex(_pavement);
	index /= 10;

	return index;
}

void Pilot::save() const
{
	std::ofstream outfile;
	String fileName = "[";
	fileName.append(getName().getContainer());
	fileName.append("].txt");
	outfile.open(fileName.getContainer());

	print(outfile);
	outfile.close();
}
