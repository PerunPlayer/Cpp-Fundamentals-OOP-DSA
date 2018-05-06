#pragma once

#include "Vehicle.h"

class Bicycle : public Vehicle
{
public:
	Bicycle();
	Bicycle(const Bicycle&);
	Bicycle& operator=(const Bicycle&);
	~Bicycle();
	Bicycle(Colour _colour, char* _manufactorer, unsigned short _year, unsigned short _seats, unsigned short _maxspeed, unsigned short _gears, bool _hasLights, bool _hasABell, char* _name);

	unsigned short getGears()const;
	void setGears(const unsigned short);

	bool getHasLighters()const;
	void setHasLighters(const bool);

	bool getHasABell()const;
	void setHasABell(const bool);

	char* getName()const;
	void setName(const char*);

private:
	unsigned short gears;
	bool hasLighters;
	bool hasABell;
	char* name;

	void init();
	void copy(const Bicycle&);
	void destroy();
};