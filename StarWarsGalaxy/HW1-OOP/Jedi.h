#pragma once

#include "Planet.h"
#include <iostream>

enum JediRank
{
	JediInitiate = 0,
	JediPadawan = 1,
	JediKnight = 2,
	JediMaster = 3
};

class Jedi
{
private:
	char* name;
	JediRank rank;
	double midichlorian;
	Planet planet;
	char* species;
	char* militaryRank;

	friend class GalacticRepublic;

private:
	void init();
	void copy(const Jedi&);
	void destroy();
	void print(std::ostream& out);

public:			//Big 6
	Jedi();
	Jedi(const Jedi&);
	Jedi& operator=(const Jedi&);
	~Jedi();
	Jedi(char* name, JediRank rank, double midichlorian, Planet planet, char* species, char* militaryRank);
	//Move constructor
	Jedi(Jedi&& other);
	////Move assigment operator
	Jedi& operator=(Jedi&& other);

	bool operator==(Jedi& other);
	friend std::ostream& operator<<(std::ostream& out, Jedi& jedi);
};
