#include "stdafx.h"
#include "Race.h"

Race::Race(Vector<CurveType> _curves, Vector<StraightLine> _straightLines, PavementType _pavement)
{
	curves = _curves;
	straightLines = _straightLines;
	pavement = _pavement;
}

Race::Race()
{
}

Vector<CurveType> Race::getCurves() const
{
	return curves;
}

Vector<StraightLine> Race::getStraightLines() const
{
	return straightLines;
}

size_t Race::getNumberOfCurves() const
{
	return curves.size();
}

size_t Race::getNumberOfStraightLines() const
{
	return straightLines.size();
}

PavementType Race::getPavement() const
{
	return pavement;
}

TrackBalance Race::getPredominant()
{
	if (curves.size() > straightLines.size())
	{
		return moreCurves;
	}
	else if (curves.size() < straightLines.size())
	{
		return moreStraightLines;
	}
	
	return equality;
}

void Race::setCurves(const Vector<CurveType> _curves)
{
	curves = _curves;
}

void Race::setStraightLines(const Vector<StraightLine> _straightLines)
{
	straightLines = _straightLines;
}

void Race::setPavement(const PavementType _pavement)
{
	pavement = _pavement;
}
