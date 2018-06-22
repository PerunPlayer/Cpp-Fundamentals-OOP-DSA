// StartUp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Championship.h"

int main()
{
	PavementsBehavior mercedesBeh(perfect, perfect, perfect);
	Car mercedes("Mercedes-AMG C63 DTM", AA, 56.09, mercedesBeh);
	std::cout << mercedes.getModel() << std::endl;

	Vector<CurveType> curves;
	curves.push_back(slight);
	curves.push_back(slight);
	curves.push(1, slight);
	curves.push_back(hairpin);
	Vector<StraightLine> straightLines;
	straightLines.push_back(shortDistance);
	straightLines.push_front(shortDistance);
	straightLines.push_back(longDistance);
	straightLines.push(1, mediumDistance);
	straightLines.push_back(longDistance);
	Race nurburgring(curves, straightLines, asphalt);

	Pilot paffett("Gary Paffett", "Mercedes-AMG Motorsport DTM", mercedes);
	paffett.print(std::cout);

	Manufactorer mercedesAMG("Mercedes-AMG Motorsport DTM", 12);
	mercedesAMG.print(std::cout);

	return 0;
}

