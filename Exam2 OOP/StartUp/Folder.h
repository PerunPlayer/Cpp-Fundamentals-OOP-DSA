#pragma once

#include "Document.h"
#include <vector>

class Folder : public Document
{
private:
	std::vector<Document*> content;
public:
	Folder(std::string title, std::vector<Document*> _content);

	void addDocument(Document* doc);
	void info(std::ostream& out);
	void contents(std::ostream& out);
	unsigned int size();
};