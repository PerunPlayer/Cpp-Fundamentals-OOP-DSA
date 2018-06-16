#include "stdafx.h"
#include "String.h"

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
	destination[size - 1] = '\0';             //writing after end of heap buffer

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
	stringCopy(this->container, other.container, length + 1);
}

void String::destroy()
{
	delete[] container;
}

char* String::getContainer() const
{
	return container;
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

char String::operator[](size_t index)
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

	for (size_t k = 0, j = length; j < length + i; j++, k++)
	{
		temp[j] = strToAppend[k];
	}
	length += i;
	stringCopy(container, temp, length + 1);
	delete[] temp;
}

void String::print(std::ostream& out)
{
	for (size_t i = 0; i < length; i++)
	{
		out << container[i];
	}
}

bool operator==(String& str1, String& str2)
{
	if (str1.size() != str2.size())
	{
		return false;
	}

	for (size_t i = 0; i < str1.size(); i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, String& strToPrint)
{
	strToPrint.print(out);
	return out;
}
