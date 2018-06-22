#include "stdafx.h"
#include "Car.h"

#include <stdexcept>

Car::Car(String _model, TractionType _traction, double _engineElasticity, PavementsBehavior _behavior)
{
	model = _model;
	traction = _traction;
	engineElasticity = _engineElasticity;
	behavior = _behavior;
}

Car::Car()
{
	model = "";
	traction = C;
	engineElasticity = 0;
}

void Car::setTraction(const TractionType _traction)
{
	traction = _traction;
}

void Car::setElasticity(const double elasticity)
{
	engineElasticity = elasticity;
}

void Car::setBehavior(const PavementsBehavior _behavior)
{
	behavior = _behavior;
}

void Car::setModel(const String _model)
{
	model = _model;
}

TractionType Car::getTraction() const
{
	return traction;
}

double Car::getElasticity() const
{
	return engineElasticity;
}

PavementsBehavior Car::getBehavior() const
{
	return behavior;
}

String Car::getModel() const
{
	return model;
}

double Car::getRacingIndex(PavementType _pavement) const
{
	double index = 0;
	switch (traction)
	{
	case AA:
		index = 10;
		break;
	case A:
		index = 8;
		break;
	case B:
		index = 5;
		break;
	case C:
		index = 3;
		break;
	default:
		throw std::invalid_argument("received invalid type for traction");
		break;
	}

	index *= engineElasticity;

	switch (_pavement)
	{
	case asphalt:
		index *= behaviorToIndex(behavior.getOnAsphalt());
		break;
	case gravel:
		index *= behaviorToIndex(behavior.getOnGravel());
		break;
	case snow:
		index *= behaviorToIndex(behavior.getOnSnow());
		break;
	default:
		throw std::invalid_argument("received invalid type for behavior");
		break;
	}

	return index;
}

Behavior PavementsBehavior::getOnAsphalt() const
{
	return onAsphalt;
}

Behavior PavementsBehavior::getOnGravel() const
{
	return onGravel;
}

Behavior PavementsBehavior::getOnSnow() const
{
	return onSnow;
}

double behaviorToIndex(Behavior _behavior)
{
	switch (_behavior)
	{
	case perfect:
		return 6;
	case good:
		return 4;
	case average:
		return 2.5;
	case bad:
		return 1;
	default:
		throw std::invalid_argument("received invalid type for behavior");
		break;
	}
}
