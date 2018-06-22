#pragma once

#include "String.h"

enum Behavior
{
	perfect,
	good,
	average,
	bad
};

enum TractionType
{
	AA,
	A,
	B,
	C
};

enum PavementType
{
	asphalt,
	gravel,
	snow
};

double behaviorToIndex(Behavior _behavior);

struct PavementsBehavior
{
private:
	Behavior onAsphalt, onGravel, onSnow;
public:
	PavementsBehavior(Behavior behAsphalt, Behavior behGravel, Behavior behSnow)
	{
		onAsphalt = behAsphalt;
		onGravel = behGravel;
		onSnow = behSnow;
	}
	PavementsBehavior()
	{
		onAsphalt = onGravel = onSnow = (Behavior)3;
	}
	Behavior getOnAsphalt() const;
	Behavior getOnGravel() const;
	Behavior getOnSnow() const;
};

class Car
{
public:
	Car(String model, TractionType _traction, double _engineElasticity, PavementsBehavior _behavior);
	Car();
	
	void setTraction(const TractionType _traction);
	void setElasticity(const double elasticity);
	void setBehavior(const PavementsBehavior _behavior);
	void setModel(const String _model);
	
	TractionType getTraction() const;
	double getElasticity() const;
	PavementsBehavior getBehavior() const;
	String getModel() const;
	double getRacingIndex(PavementType _pavement) const;

private:
	TractionType traction; //traction ratings: A, AA, B, C
	double engineElasticity; //complex index with representation as real number
	PavementsBehavior behavior;
	String model;
};