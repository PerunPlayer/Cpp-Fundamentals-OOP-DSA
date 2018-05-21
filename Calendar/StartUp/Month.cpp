#include "stdafx.h"
#include "Month.h"

Month::Month()
{
	numberOfDays = 0;
	days = MyVector<Day>(numberOfDays);
}

Month::Month(size_t _numberOfDays)
{
	if (_numberOfDays > 27 && _numberOfDays < 32)
	{
		numberOfDays = _numberOfDays;
		days = MyVector<Day>(_numberOfDays);
	}
	else
	{
		throw std::exception("Invalid value in " __FUNCTION__);
	}
}

size_t Month::getNumberOfDays() const
{
	return numberOfDays;
}

void Month::setNumberOfDays(size_t number)
{
	numberOfDays = number;
}

MyVector<Day>& Month::getDays()
{
	return days;
}

void Month::setDays(MyVector<Day> d)
{
	days = d;
}
