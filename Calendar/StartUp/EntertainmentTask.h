#pragma once

#include "Task.h"

enum EntertainmentType
{
	playMusic,			//Since you're in FMI, your band is mad at you, so it's by default.
	sport,				//Please don't die this time!
	beWithYourGirl,		//She's also mad at you...
						//You have no time for that -->
	gaming,
	visitEvent
};

class EntertainmentTask : public Task
{
private:
	EntertainmentType activity;
	char* location;

	void init();
	void copy(const EntertainmentTask& other);
	void destroy();

public:
	EntertainmentTask();
	EntertainmentTask(const EntertainmentTask& other);
	EntertainmentTask& operator=(const EntertainmentTask& other);
	~EntertainmentTask();
	EntertainmentTask(EntertainmentType type, char* _location, char* title, char* description, std::tuple<Time, Time> timespan);

	Type getType() const;
	EntertainmentType getActivity() const;
	void setActivity(EntertainmentType entT);
	char* getLocation() const;
	void setLocation(char* loc);
	void checkWeather();

	void print(std::ostream& out);
};