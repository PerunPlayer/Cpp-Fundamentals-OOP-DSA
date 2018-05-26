#include "stdafx.h"
#include "Folder.h"

Folder::Folder(std::string title, std::vector<Document*> _content) : Document(title)
{
	content = _content;
}

void Folder::addDocument(Document* doc)
{
	content.push_back(doc);
}

void Folder::info(std::ostream& out)
{
	out << "{\n";
	for (size_t i = 0; i < size(); i++) //because printing of document has std::endl
	{
		content[i]->info(out);
	}
	out << "}\n";
}

void Folder::contents(std::ostream& out)
{
	out << "{\n";
	/*for (size_t i = 0; i < size(); i++) //if printing of document hadn't std::endl      just hide the comment to see the clear code
	{
		if (i == size() - 2)
		{
			content[i]->contents(out);
			out << "\n";
		}
		else
		{
			content[i]->contents(out);
		}
	}*/
	for (size_t i = 0; i < size(); i++)
	{
		content[i]->contents(out);
	}
	out << "}\n";
}

unsigned int Folder::size()
{
	return content.size();
}