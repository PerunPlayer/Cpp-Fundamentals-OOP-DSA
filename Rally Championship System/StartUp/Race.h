#pragma once

#include "Vector.cpp"
#include "Car.h"
#include "Pilot.h"
#include "Manufactorer.h"

enum CurveType
{
	slight,
	hairpin
};

enum StraightLine
{
	longDistance,
	mediumDistance,
	shortDistance
};

class Race
{
public:
	Race(Vector<CurveType> curves, Vector<StraightLine> straightLines, PavementType ground);
	Race();

	Vector<CurveType> getCurves() const;
	Vector<StraightLine> getStraightLines() const;
	size_t getNumberOfCurves() const;
	size_t getNumberOfStraightLines() const;
	PavementType getPavement() const;
	TrackBalance getPredominant();

	void setCurves(const Vector<CurveType> _curves);
	void setStraightLines(const Vector<StraightLine> _drags);
	void setPavement(const PavementType _pavement);

private:
	Vector<CurveType> curves;
	Vector<StraightLine> straightLines;
	PavementType pavement;
};