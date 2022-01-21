#pragma once

#include "JediTemple.h"
#include "Army.h"
#include "Galaxy.h"

class GalacticRepublic
{
public:
	GalacticRepublic();
	GalacticRepublic(const GalacticRepublic& galacticRepublic);
	GalacticRepublic& operator=(const GalacticRepublic& galacticRepublic);
	~GalacticRepublic();
	GalacticRepublic(char* name, const JediTemple& temple, const Army& army, const Galaxy& galaxy);
	GalacticRepublic(GalacticRepublic&& other);
	GalacticRepublic& operator=(GalacticRepublic&& other);

	void printAllJedi(Planet& planet);
	void printAllStormtroopers(Planet& planet);
	void printAllPlanets(std::ostream& out);
	void printAllJedi(std::ostream& out);
	void printAllStormtroopers(std::ostream& out);
	JediTemple& getTemple();
	Army& getArmy();
	Galaxy& getGalaxy();

private:
	char* name;
	JediTemple jediTemple;
	Army army;
	Galaxy galaxy;

private:
	void init();
	void copy(const GalacticRepublic& galacticRepublic);
	void destroy();
};