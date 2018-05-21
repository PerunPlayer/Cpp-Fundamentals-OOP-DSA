#include "stdafx.h"
#include "Day.h"

void Day::init()
{
	tasks;
}

void Day::copy(const Day& other)
{
	tasks = other.tasks;
}

Day::Day()
{
	init();
}

Day::Day(const Day& other)
{
	init();
	copy(other);
}

LinkedList<Task*>& Day::getTasks()
{
	return tasks;
}

void Day::setTasks(LinkedList<Task*> t)
{
	tasks = t;
}

void Day::printTasks(std::ostream& out)
{
	tasks.printObjects(out);
}
