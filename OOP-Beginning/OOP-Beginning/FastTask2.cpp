#include "stdafx.h"
#include <vector>

class Task
{
public:
	virtual bool finished(unsigned long t) = 0;
};

class SimpleTask : public Task
{
private:
	unsigned long duration, start;

public:
	bool finished(unsigned long t)
	{
		return (t - start >= duration);
	}
};

class ComplexTask : public Task
{
private:
	std::vector<Task*> tasks;

public:
	bool finished(unsigned long t)
	{
		for (size_t i = 0; i < tasks.size; i++)
		{
			if (!tasks[i]->finished(t))
			{
				return false;
			}
		}
		return true;
	}

	void add(Task* tsk)
	{
		tasks.push_back(tsk);
	}
};