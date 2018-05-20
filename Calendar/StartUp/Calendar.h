#pragma once

#include "Month.h"

class Calendar
{
private:
	char* description;
	MyVector<Month> months;

	void init();
	void copy(const Calendar& other);
	void destroy();
	void pushMonths(bool isLeap);

public:
	Calendar();
	Calendar(const Calendar& other);
	Calendar& operator=(const Calendar& other);
	~Calendar();
	Calendar(bool isLeap);

	char* getDescription() const;
	void setDescription(char* descr);
	MyVector<Month>& getMonths();
	void setMonths(MyVector<Month> m);
};
