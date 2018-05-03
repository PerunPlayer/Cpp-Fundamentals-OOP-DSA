#pragma once

#include "Stormtrooper.h"

class Army
{
public:
	Army();
	Army(const Army& army);
	Army& operator=(const Army& army);
	~Army();

public:
	void add(Stormtrooper trooper);
	void remove(Stormtrooper& trooper);
	unsigned int sizeOf();

private:
	void init();
	void destroy();
	void copy(const Army& army);
	void resize();

	Stormtrooper* container;
	size_t size;
	size_t capacity;

	friend class GalacticRepublic;
};