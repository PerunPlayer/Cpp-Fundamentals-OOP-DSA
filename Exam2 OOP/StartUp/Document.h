#pragma once

#include <string>
#include <iostream>

class Document
{
protected:
	std::string title;

public:
	Document(std::string title);

	virtual unsigned int size() = 0;
	virtual void info(std::ostream& out) = 0;
	virtual void contents(std::ostream& out) = 0;
	std::string getTitle();
};