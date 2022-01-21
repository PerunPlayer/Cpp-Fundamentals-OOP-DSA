#pragma once

#include "Jedi.h"

class JediTemple
{
public:
	JediTemple();
	JediTemple(const JediTemple& jediTemple);
	JediTemple& operator=(const JediTemple& jediTemple);
	~JediTemple();
	
public:
	void add(const Jedi& jedi);
	void remove(Jedi& jedi);
	unsigned int sizeOf();

private:
	void init();
	void destroy();
	void copy(const JediTemple& jediTemple);
	void resize();

	Jedi* container;
	size_t size;
	size_t capacity;

	friend class GalacticRepublic;
};