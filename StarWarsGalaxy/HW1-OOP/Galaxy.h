#pragma once

#include "Planet.h"

class Galaxy
{
public:
	Galaxy();
	Galaxy(const Galaxy&);
	Galaxy& operator=(const Galaxy&);
	~Galaxy();
	Galaxy(char* name, Planet* planets, unsigned int countOfPlanets);
	Galaxy(Galaxy&& other);
	Galaxy& operator=(Galaxy&& other);

public:
	void add(Planet planet);
	void remove(Planet& planet);
	unsigned int sizeOf();

private:
	char* name;
	Planet* planets;
	size_t size;
	size_t capacity;

	friend class GalacticRepublic;

private:
	void init();
	void copy(const Galaxy&);
	void destroy();
	void resize();
};