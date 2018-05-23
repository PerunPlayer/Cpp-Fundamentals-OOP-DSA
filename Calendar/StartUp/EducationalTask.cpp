#include "stdafx.h"
#include "EducationalTask.h"

void EducationalTask::init()
{
	Task::init();
	subject = nullptr;
	books;
	type = educational;
}

void EducationalTask::copy(const EducationalTask& other)
{
	Task::copy(other);
	myStrCpy(subject, other.subject);
	books = other.books;
}

void EducationalTask::destroy()
{
	Task::destroy();
	delete[] subject;
}

EducationalTask::EducationalTask()
{
	init();
}

EducationalTask::EducationalTask(const EducationalTask& other)
{
	init();
	copy(other);
}

EducationalTask& EducationalTask::operator=(const EducationalTask& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

EducationalTask::~EducationalTask()
{
	destroy();
}

EducationalTask::EducationalTask(char* _subject, LinkedList<char*> _books, char* title, char* description, std::tuple<Time, Time> timespan)
{
	myStrCpy(subject, _subject);
	books = _books;
	setTitle(title);
	setDescription(description);
	setSpan(timespan);
}

Type EducationalTask::getType() const
{
	return educational;
}

char* EducationalTask::getSubject() const
{
	return subject;
}

void EducationalTask::setSubject(char* subj)
{
	myStrCpy(subject, subj);
}

LinkedList<char*>& EducationalTask::getBooks()
{
	return books;
}

void EducationalTask::setBooks(LinkedList<char*> b)
{
	books = b;
}

void EducationalTask::print(std::ostream& out)
{
	out << "[";

	switch (getType())
	{
	case business:
		out << "Business";
		break;
	case educational:
		out << "Educational";
		break;
	case entertainment:
		out << "Entertainment";
		break;
	default:
		out << "Not initialized";
		break;
	}

	out << " task: " << getTitle() << " (" << getDescription() << ") " << getTimespan() << " , ";
	out << " , " << subject << " , ";
	books.printPrimitiveTypes(out);
	out <<  "]";
}
