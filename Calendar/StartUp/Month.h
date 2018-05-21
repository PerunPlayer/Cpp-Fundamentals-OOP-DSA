#pragma once

#include "Day.h"
#include "Vector.cpp"

class Month
{
private:
	size_t numberOfDays;
	MyVector<Day> days;

public:
	Month();
	Month(size_t _numberOfDays);

	size_t getNumberOfDays() const;
	void setNumberOfDays(size_t number);
	MyVector<Day>& getDays();
	void setDays(MyVector<Day> d);
};