#pragma once

#include "Task.h"
#include "Vector.cpp"

//Всичко от задача плюс :
//Хора на срещата - представлява поредица от име и фамилия(можете да го изнесете в отделен клас)
//пресмятане на продължителността

class BusinessTask : public Task
{
	MyVector<std::tuple<std::string, std::string>> people;
	char* location;
	char* host;

	void init();
	void copy(const BusinessTask& other);
	void destroy();

public:
	BusinessTask();
	BusinessTask(const BusinessTask& other);
	BusinessTask& operator=(const BusinessTask& other);
	~BusinessTask();
	BusinessTask(MyVector<std::tuple<std::string, std::string>> _people, char* _location, std::tuple<Time, Time> timespan, char* _host, char* title, char* description);

	Type getType() const;
	MyVector<std::tuple<std::string, std::string>>& getPeople();
	void setPeople(MyVector<std::tuple<std::string, std::string>> ppl);
	char* getLocation() const;
	void setLocation(char* loc);
	char* getHost() const;
	void setHost(char* _host);

	void print(std::ostream& out);
};