#pragma once

#include "Document.h"

class Page : public Document
{
private:
	std::string content;

public:
	Page(std::string title, std::string _content);

	void info(std::ostream& out);
	void contents(std::ostream& out);
	unsigned int size();
};