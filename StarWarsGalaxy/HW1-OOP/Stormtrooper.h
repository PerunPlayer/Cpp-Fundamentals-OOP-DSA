#pragma once

#include "Planet.h"

enum TrooperRank
{
	Trooper,
	SquadLeader,
	PlatoonLeader,
	CompanyLeader,
	BattalionCommander,
	RegimentCommander,
	GeneralOfLegion
};

class Stormtrooper
{
public:
	Stormtrooper();
	Stormtrooper(const Stormtrooper&);
	Stormtrooper& operator=(const Stormtrooper&);
	~Stormtrooper();
	Stormtrooper(char* id, TrooperRank rank, char* type, Planet planet);
	Stormtrooper(Stormtrooper&& other);
	Stormtrooper& operator=(Stormtrooper&& other);

	bool operator==(Stormtrooper& other);
	friend std::ostream& operator<<(std::ostream& out, Stormtrooper& trooper);

private:
	char* id;
	TrooperRank rank;
	char* type;
	Planet planet;

	friend class GalacticRepublic;

private:
	void init();
	void copy(const Stormtrooper&);
	void destroy();
	void print(std::ostream& out);
};