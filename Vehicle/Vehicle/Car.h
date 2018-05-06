#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	Car(const Car&);
	Car& operator=(const Car&);
	~Car();
	Car(Colour _colour, char* _manufactorer, unsigned short _year, unsigned short _seats, unsigned short _maxspeed, char* _model, unsigned short _doors, unsigned short _powerInHP);

	char* getModel()const;
	void setModel(const char*);

	unsigned short getDoors()const;
	void setDoors(const unsigned short);

	unsigned short getPowerInHP()const;
	void setPowerInHP(const unsigned short);

private:
	char* model;
	unsigned short doors;
	unsigned short powerInHP;

	void init();
	void copy(const Car&);
	void destroy();
};