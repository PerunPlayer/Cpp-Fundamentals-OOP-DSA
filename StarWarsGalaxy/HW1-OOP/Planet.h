#pragma once

#include <iostream>

void myStrCpy(char*& dest, const char* src);
bool areEqualStr(const char*, const char*);

class Planet
{
public:		//Big 5
	Planet();
	Planet(const Planet&);
	Planet& operator=(const Planet&);
	~Planet();
	Planet(char* name, char* planetSystem, char* republic);

	bool operator==(Planet& other);
	friend std::ostream& operator<<(std::ostream& out, Planet& planet);

private:
	char* name;
	char* planetSystem;
	char* republic;

private:
	void init();
	void copy(const Planet&);
	void destroy();
	void print(std::ostream& out);
};
