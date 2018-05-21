#include "stdafx.h"
#include "Task.h"

void myStrCpy(char*& dest, const char* src)
{
	if (src)
	{
		unsigned length = 0;
		for (unsigned i = 0; src[i] != '\0'; i++)
		{
			length++;
		}
		dest = new char[length + 1];
		for (unsigned i = 0; src[i] != '\0'; i++)
		{
			dest[i] = src[i];
		}
		dest[length] = '\0';
	}
}

std::string differenceInTimeformat(size_t miliseconds)
{
	size_t diffDays = miliseconds / TWENTY_FOUR_HOURS;
	miliseconds -= (diffDays * TWENTY_FOUR_HOURS);
	size_t diffHours = miliseconds / (TWENTY_FOUR_HOURS / 24);
	miliseconds -= (diffHours * (TWENTY_FOUR_HOURS / 24));
	size_t diffMinutes = miliseconds / (60 * 1000);
	miliseconds -= (diffMinutes * (60 * 1000));
	size_t diffSeconds = miliseconds * 1000;
	miliseconds -= (diffSeconds * 1000);

	std::string durationStr = std::to_string(diffDays) + " days " + std::to_string(diffHours) + ":";
	if (diffMinutes < 10)
	{
		durationStr += "0";
	}
	durationStr += std::to_string(diffMinutes) + ":";
	if (diffSeconds < 10)
	{
		durationStr += "0";
	}
	durationStr += std::to_string(diffSeconds) + ".";

	if (miliseconds < 100)
	{
		durationStr += "0";
		if (miliseconds < 10)
		{
			durationStr += "0";
		}
	}
	durationStr += std::to_string(miliseconds);

	return durationStr;
}

std::ostream& operator<<(std::ostream& out, Task& task)
{
	task.print(out);
	return out;
}

void Task::init()
{
	title = description = 0;
	type = (Type)0;
	std::tuple<Time, Time> timespan;
}

void Task::copy(const Task& other)
{
	myStrCpy(title, other.title);
	myStrCpy(description, other.description);
	timespan = other.timespan;
	type = other.type;
}

void Task::destroy()
{
	delete[] title;
	delete[] description;
	type = (Type)0;
}

Task::Task()
{
	init();
}

Task::Task(const Task& other)
{
	init();
	copy(other);
}

Task& Task::operator=(const Task& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

Task::~Task()
{
	destroy();
}

char* Task::getTitle() const
{
	return title;
}

void Task::setTitle(char* ttl)
{
	myStrCpy(title, ttl);
}

char* Task::getDescription() const
{
	return description;
}

void Task::setDescription(char* descr)
{
	myStrCpy(description, descr);
}

std::string Task::getTimespan()
{
	std::string span;
	span = std::get<0>(timespan).toStr() + " - " + std::get<1>(timespan).toStr();
	return span;
}

size_t Task::getDuration()
{
	size_t duration = 0, start = 0, end = 0;
	start = std::get<0>(timespan).toMiliseconds();
	end = std::get<1>(timespan).toMiliseconds();
	duration = (start > end) ? ((TWENTY_FOUR_HOURS - start) + end) : (end - start);
	return duration;
}

void Task::setSpan(std::tuple<Time, Time> _timespan)
{
	std::get<0>(timespan) = std::get<0>(_timespan);
	std::get<1>(timespan) = std::get<1>(_timespan);
}
