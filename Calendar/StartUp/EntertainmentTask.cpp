#include "stdafx.h"
#include "EntertainmentTask.h"

void EntertainmentTask::init()
{
	Task::init();
	location = nullptr;
	activity = (EntertainmentType)0;
	type = entertainment;
}

void EntertainmentTask::copy(const EntertainmentTask& other)
{
	Task::copy(other);
	activity = other.activity;
	myStrCpy(location, other.location);
}

void EntertainmentTask::destroy()
{
	Task::destroy();
	delete[] location;
}

EntertainmentTask::EntertainmentTask()
{
	init();
}

EntertainmentTask::EntertainmentTask(const EntertainmentTask& other)
{
	init();
	copy(other);
}

EntertainmentTask& EntertainmentTask::operator=(const EntertainmentTask& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

EntertainmentTask::~EntertainmentTask()
{
	destroy();
}

EntertainmentTask::EntertainmentTask(EntertainmentType type, char* _location, char* title, char* description, std::tuple<Time, Time> timespan)
{
	activity = type;
	myStrCpy(location, _location);
	setTitle(title);
	setDescription(description);
	setSpan(timespan);
}

Type EntertainmentTask::getType() const
{
	return entertainment;
}

EntertainmentType EntertainmentTask::getActivity() const
{
	return activity;
}

void EntertainmentTask::setActivity(EntertainmentType entT)
{
	activity = entT;
}

char* EntertainmentTask::getLocation() const
{
	return location;
}

void EntertainmentTask::setLocation(char* loc)
{
	myStrCpy(location, loc);
}

void EntertainmentTask::checkWeather()
{
	std::string cmd, loc(location);
	cmd = "start chrome  https://www.sinoptik.bg/search?q={" + loc + "}";
	system(cmd.c_str());
}

void EntertainmentTask::print(std::ostream& out)
{
	out << "[";

	switch (getType())
	{
	case business:
		out << "Business";
		break;
	case educational:
		out << "Educational";
		break;
	case entertainment:
		out << "Entertainment";
		break;
	default:
		out << "Not initialized";
		break;
	}

	out << " task: " << getTitle() << " (" << getDescription() << ") ";
	out << getTimespan() << " , ";
	switch (activity)
	{
	case playMusic: 
		out << "\"Play music\"";
		break;
	case sport:
		out << "\"Sport\"";
		break;
	case beWithYourGirl:
		out << "\"Go out with the girl\"";
		break;
	case gaming:
		out << "\"Gaming\"";
		break;
	case visitEvent:
		out << "\"Visit event\"";
		break;
	default:
		out << "\"Uninitialized activity\"";
		break;
	}
	out << " , " << location << "]";
}
