#include "stdafx.h"
#include "Page.h"

Page::Page(std::string title, std::string _content) : Document(title)
{
	content = _content;
}

void Page::info(std::ostream& out)
{
	out << getTitle() << std::endl;
}

void Page::contents(std::ostream& out)
{
	out << content << std::endl;
}

unsigned int Page::size()
{
	return 1;
}
