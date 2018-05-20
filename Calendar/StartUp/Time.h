#pragma once

#include <string>

const size_t TWENTY_FOUR_HOURS = ((24 * 60) * 60) * 1000;

class Time
{
private:
	size_t seconds;
	size_t minutes;
	size_t hours;

	void init();
	void copy(const Time& other);
	void destroy();

public:
	Time();
	Time(const Time& other);
	Time& operator=(const Time& other);
	~Time();
	Time(size_t seconds, size_t minutes, size_t hours);
	Time(std::string time);

	std::string toStr();
	std::string getTime();
	bool validateTime(const size_t seconds, const size_t minutes, const size_t hours);
	size_t toMiliseconds();
};