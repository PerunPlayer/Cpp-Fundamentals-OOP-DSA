#include "stdafx.h"
#include "Calendar.h"

Calendar::Calendar()
{
	init();
}

Calendar::Calendar(const Calendar& other)
{
	init();
	copy(other);
}

Calendar& Calendar::operator=(const Calendar& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

Calendar::~Calendar()
{
	destroy();
}

Calendar::Calendar(bool isLeap)
{
	description = nullptr;
	pushMonths(isLeap);
}

void Calendar::init()
{
	description = nullptr;
	pushMonths(false);
}

void Calendar::copy(const Calendar& other)
{
	myStrCpy(description, other.description);
	months = other.months;
}

void Calendar::destroy()
{
	delete[] description;
	months.destroy();
}

void Calendar::pushMonths(bool isLeap)
{
	months.push_back(Month(31));

	isLeap ? (months.push_back(Month(29))) : (months.push_back(Month(28)));

	months.push_back(Month(31));
	months.push_back(Month(30));
	months.push_back(Month(31));
	months.push_back(Month(30));
	months.push_back(Month(31));
	months.push_back(Month(31));
	months.push_back(Month(30));
	months.push_back(Month(31));
	months.push_back(Month(30));
	months.push_back(Month(31));
}

char* Calendar::getDescription() const
{
	return description;
}

void Calendar::setDescription(char* descr)
{
	myStrCpy(description, descr);
}

MyVector<Month>& Calendar::getMonths()
{
	return months;
}

void Calendar::setMonths(MyVector<Month> m)
{
	months = m;
}
