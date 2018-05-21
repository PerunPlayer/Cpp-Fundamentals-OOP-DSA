#pragma once

#include "Task.h"
#include "BusinessTask.h"
#include "EntertainmentTask.h"
#include "EducationalTask.h"

class Day
{
private:
	LinkedList<Task*> tasks;

	void init();
	void copy(const Day& other);

public:
	Day();
	Day(const Day& other);

	LinkedList<Task*>& getTasks();
	void setTasks(LinkedList<Task*> t);
	void printTasks(std::ostream& out);
};