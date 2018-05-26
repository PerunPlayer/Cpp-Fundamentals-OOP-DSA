#include "stdafx.h"
#include "Document.h"

Document::Document(std::string _title)
{
	title = _title;
}

std::string Document::getTitle()
{
	return title;
}
