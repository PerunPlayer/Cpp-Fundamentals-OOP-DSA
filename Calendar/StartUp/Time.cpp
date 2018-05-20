#include "stdafx.h"
#include "Time.h"

void Time::init()
{
	seconds = minutes = hours = 0;
}

void Time::copy(const Time& other)
{
	if (validateTime(other.seconds, other.minutes, other.hours))
	{
		seconds = other.seconds;
		minutes = other.minutes;
		hours = other.hours;
	}
}

void Time::destroy()
{
	seconds = minutes = hours = 0;
}

Time::Time()
{
	init();
}

Time::Time(const Time& other)
{
	init();
	copy(other);
}

Time& Time::operator=(const Time& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}

	return *this;
}

Time::~Time()
{
	destroy();
}

Time::Time(size_t _seconds, size_t _minutes, size_t _hours)
{
	if (!validateTime(_seconds, _minutes, _hours))
		throw std::exception("Invalid value in " __FUNCTION__);

	seconds = _seconds;
	minutes = _minutes;
	hours = _hours;
}

Time::Time(std::string time)
{
	//hardcoded
	size_t parsedSeconds = 0, parsedMinutes = 0, parsedHours = 0;
	parsedHours = ((time[0] - '0') * 10) + (time[1] - '0');
	parsedMinutes = ((time[3] - '0') * 10) + (time[4] - '0');
	parsedSeconds = ((time[6] - '0') * 10) + (time[7] - '0');

	if (!validateTime(parsedSeconds, parsedMinutes, parsedHours))
		throw std::exception("Invalid value in " __FUNCTION__);

	seconds = parsedSeconds;
	minutes = parsedMinutes;
	hours = parsedHours;
}

std::string Time::toStr()
{
	std::string time = "";
	time = std::to_string(hours) + ":" + std::to_string(minutes);
	time += ":" + std::to_string(seconds);
 	return time;
}

std::string Time::getTime()
{
	return toStr();
}

bool Time::validateTime(const size_t seconds, const size_t minutes, const size_t hours)
{
	return ((seconds >= 0 && seconds <= 59)
		 && (minutes >= 0 && minutes <= 59)
		 && (hours >= 0 && hours <= 23));
}

size_t Time::toMiliseconds()
{
	return ((((hours * 60) + minutes) * 60) + seconds) * 1000;
}

