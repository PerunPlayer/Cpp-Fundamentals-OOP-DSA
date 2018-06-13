#include "stdafx.h"
#include <cstring>

class String
{
public:
	String();
	~String();
	String(const String&);
	String(const char* value);
	String& operator=(const String&);
	String& operator=(const char*);

private:
	char* container;
	size_t length;

public:
	int size();
	void clear();
	bool empty();
	char operator[](int index);
	void operator+=(char* strToAppend);
	void append(char* strToAppend);

private:
	void stringCopy(char*&, const char*, int);
	void init();
	void copy(const String&);
	void destroy();
};

int main()
{
	String str;
	String str1 = "str";
	str = "abv";
	str += "cd";
	int s = str.size();
	char c = str[2];
	bool isEmpty = str.empty();
	str.clear();
	s = str.size();
	isEmpty = str.empty();

	return 0;
}

String::String()
{
	init();
}

String::~String()
{
	destroy();
}

String::String(const String& other)
{
	init();
	copy(other);
}

String::String(const char* value)
{
	this->length = strlen(value);
	this->container = new char[length + 1];
	stringCopy(this->container, value, length + 1);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

String& String::operator=(const char* other)
{
	if (this != nullptr)
	{
		destroy();
		init();

		length = strlen(other);
		stringCopy(this->container, other, length + 1);
	}

	return *this;
}

void String::stringCopy(char*& destination, const char* source, int size)
{
	destination = new char[size];
	for (int i = 0; i < size - 1; i++)
	{
		destination[i] = source[i];
	}
	destination[size - 1] = '\0';

	return;
}

void String::init()
{
	this->container = nullptr;
	this->length = 0;
}

void String::copy(const String& other)
{
	this->length = other.length;
	stringCopy(this->container, other.container, length);
}

void String::destroy()
{
	delete[] container;
}

int String::size()
{
	return this->length;
}

void String::clear()
{
	destroy();
	init();
}

bool String::empty()
{
	if (this->length > 0)
	{
		return false;
	}
	return true;
}

char String::operator[](int index)
{
	return this->container[index];
}

void String::operator+=(char* strToAppend)
{
	append(strToAppend);
}

void String::append(char* strToAppend)
{
	int i = strlen(strToAppend);

	char* temp = new char[length + i];
	for (size_t i = 0; i < length; i++)
	{
		temp[i] = container[i];
	}

	delete[] container;

	for (int k = 0, j = length; j < length + i; j++, k++)
	{
		temp[j] = strToAppend[k];
	}
	length += i;
	stringCopy(container, temp, length);
	delete[] temp;
}