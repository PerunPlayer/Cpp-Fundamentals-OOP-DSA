#pragma once

#include "Time.h"
#include "LinkedList.h"
#include <tuple>

void myStrCpy(char*& dest, const char* src);
std::string differenceInTimeformat(size_t durationInMiliseconds);

enum Type
{
	default,
	business,
	educational,
	entertainment
};

class Task
{
private:
	char* title;
	char* description;

protected:
	Type type;
	std::tuple<Time, Time> timespan;
	
	void init();
	void copy(const Task& other);
	void destroy();

public:
	Task();
	Task(const Task& other);
	Task& operator=(const Task& other);
	virtual ~Task() = 0;

	char* getTitle() const;
	void setTitle(char* ttl);
	char* getDescription() const;
	void setDescription(char* descr);
	std::string getTimespan();
	virtual Type getType() const = 0;
	size_t getDuration();
	void setSpan(std::tuple<Time, Time> timespan);
	
	virtual void print(std::ostream& out) = 0;
	friend std::ostream& operator<<(std::ostream& out, Task& task);
};