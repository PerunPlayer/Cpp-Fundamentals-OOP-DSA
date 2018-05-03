#include "stdafx.h"

class MyString
{
public:
	MyString();
	~MyString();
	MyString(const MyString&);
	MyString& operator=(const MyString&);
	MyString& operator=(const char*);


private:
	char* container;
	int length;

public:
	int size();
	void clear();
	bool empty();
	char operator[](int index);
	void operator+=(char* strToAppend);
	void append(char* strToAppend);
	void push_back(char c);
	void pop_back();
	short compare(MyString& other);
	char* data();
	bool find(char* strToFind);

private:
	void stringCopy(char*&, const char*, int);
	void init();
	void copy(const MyString&);
	void destroy();
};

//int main()
//{
//	//MyString str = "str";
//	MyString str;
//	str = "abv";
//	str += "cd";
//	int s = str.size();
//	char c = str[2];
//	bool isEmpty = str.empty();
//	str.clear();
//	s = str.size();
//	isEmpty = str.empty();
//
//	return 0;
//}

MyString::MyString()
{
	init();
}

MyString::~MyString()
{
	destroy();
}

MyString::MyString(const MyString& other)
{
	init();
	copy(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

MyString& MyString::operator=(const char* other)
{
	if (this != nullptr)
	{
		destroy();
	}

	int i;
	for (i = 0; other[i] != '\0'; i++){	}
	
	stringCopy(this->container, other, i+1);
	this->length = i;

	return *this;
}

void MyString::stringCopy(char*& destination, const char* source, int size)
{
	destination = new char[size];
	for (int i = 0; i < size - 1; i++)
	{
		destination[i] = source[i];
	}
	destination[size - 1] = '\0';

	return;
}

void MyString::init()
{
	this->container = nullptr;
	this->length = 0;
}

void MyString::copy(const MyString& other)
{
	this->length = other.length;
	stringCopy(this->container, other.container, length);
}

void MyString::destroy()
{
	delete[] container;
}

int MyString::size()
{
	return this->length;
}

void MyString::clear()
{
	destroy();
	init();
}

bool MyString::empty()
{
	if (this->length > 0)
	{
		return false;
	}
	return true;
}

char MyString::operator[](int index)
{
	return this->container[index];
}

void MyString::operator+=(char* strToAppend)
{
	int i;
	for (i = 0; strToAppend[i] != '\0'; i++){ }

	for (int k = 0, j = length - 1; j < this->length + i - 1; j++, k++)
	{
		this->container[j] = strToAppend[k];
	}
	this->container[length + i] = '\0';
}

