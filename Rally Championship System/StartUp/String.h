#pragma once

#include <cstring>
#include <iostream>

class String
{
public:
	String();
	~String();
	String(const String&);
	String(const char* value);
	String& operator=(const String&);
	String& operator=(const char*);
	
	friend bool operator==(String& str1, String& str2);
	friend std::ostream& operator<<(std::ostream& out, String& strToPrint);

private:
	char* container;
	size_t length;

public:
	int size();
	void clear();
	bool empty();
	char operator[](size_t index);
	void operator+=(char* strToAppend);
	void append(char* strToAppend);
	void print(std::ostream& out);

	char* getContainer() const;  //couldn't workaround to use it, when it's private, so temporary is public

private:
	void stringCopy(char*&, const char*, int);
	void init();
	void copy(const String&);
	void destroy();
};