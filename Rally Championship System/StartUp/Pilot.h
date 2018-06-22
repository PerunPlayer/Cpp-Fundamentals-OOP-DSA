#pragma once

#include "Participant.h"
#include "Car.h"

#include <fstream>

const unsigned short MAX_NUMBER_OF_PILOTS = 10;

enum Speciality
{
	betterAtCurves,
	betterAtStraights,
	betterAtEverything
};

enum FavoritePavement
{
	betterOnAsphalt,
	betterOnGravel,
	betterOnSnow
};

enum TrackBalance
{
	moreCurves,
	moreStraightLines,
	equality
};

class Pilot : public Participant
{
	friend String;

public:
	Pilot(String _name, String manufactorer, Car _car);
	Pilot();

	void print(std::ostream& out) const;
	ParticipantType getType() const;
	Car getCar() const;
	String getManufactorer() const;
	double getRacingIndex(PavementType _pavement, TrackBalance predominant) const;
	void save() const;

private:
	Car car;
	Speciality speciality;
	FavoritePavement favPavement;
	static unsigned short currentNumber;
	String manufactorer;
};