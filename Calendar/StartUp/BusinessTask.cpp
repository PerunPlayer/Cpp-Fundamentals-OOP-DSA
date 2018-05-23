#include "stdafx.h"
#include "BusinessTask.h"

void BusinessTask::init()
{
	Task::init();
	type = business;
	location = host = nullptr;
}

void BusinessTask::copy(const BusinessTask& other)
{
	Task::copy(other);
	people = other.people;
	timespan = other.timespan;
	myStrCpy(location, other.location);
	myStrCpy(host, other.host);
}

void BusinessTask::destroy()
{
	Task::destroy();
	delete[] location;
	delete[] host;
}

BusinessTask::BusinessTask()
{
	init();
}

BusinessTask::BusinessTask(const BusinessTask& other)
{
	init();
	copy(other);
}

BusinessTask& BusinessTask::operator=(const BusinessTask& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

BusinessTask::~BusinessTask()
{
	destroy();
}

BusinessTask::BusinessTask(MyVector<std::tuple<std::string, std::string>> _people, char* _location, std::tuple<Time, Time> _timespan, char* _host, char* _title, char* _description)
{
	people = _people;
	myStrCpy(location, _location);
	setSpan(_timespan);
	myStrCpy(host, _host);
	setTitle(_title);
	setDescription(_description);
}

Type BusinessTask::getType() const
{
	return business;
}

MyVector<std::tuple<std::string, std::string>>& BusinessTask::getPeople()
{
	return people;
}

void BusinessTask::setPeople(MyVector<std::tuple<std::string, std::string>> ppl)
{
	people = ppl;
}

char* BusinessTask::getLocation() const
{
	return location;
}

void BusinessTask::setLocation(char* loc)
{
	myStrCpy(location, loc);
}

char* BusinessTask::getHost() const
{
	return host;
}

void BusinessTask::setHost(char* _host)
{
	myStrCpy(host, _host);
}

void BusinessTask::print(std::ostream& out)
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
	people.printTuples(out);
	out << " , " << location << " , " << host << "]";
}
