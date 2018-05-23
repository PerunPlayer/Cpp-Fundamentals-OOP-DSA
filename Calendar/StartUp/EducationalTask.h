#pragma once

#include "Task.h"

class EducationalTask : public Task
{
	char* subject;
	LinkedList<char*> books;

	void init();
	void copy(const EducationalTask& other);
	void destroy();

public:
	EducationalTask();
	EducationalTask(const EducationalTask& other);
	EducationalTask& operator=(const EducationalTask& other);
	~EducationalTask();
	EducationalTask(char* _subject, LinkedList<char*> _books, char* title, char* description, std::tuple<Time, Time> timespan);

	Type getType() const;
	char* getSubject() const;
	void setSubject(char* subj);
	LinkedList<char*>& getBooks();
	void setBooks(LinkedList<char*> b);

	void print(std::ostream& out);
};