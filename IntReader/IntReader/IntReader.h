#pragma once

#include <string>
#include <iostream>

class IntReader
{
public:
	IntReader();
	IntReader(const IntReader& other);
	IntReader& operator=(const IntReader& other);
	~IntReader();

	virtual bool read();
	virtual size_t getData();
	virtual bool isEmpty();

protected:
	std::string toRead;
	size_t alreadyRead;
};

IntReader::IntReader()
{
	toRead = "";
	alreadyRead = NULL;
}

inline IntReader::IntReader(const IntReader& other)
{
	toRead = other.toRead;
	alreadyRead = other.alreadyRead;
}

inline IntReader& IntReader::operator=(const IntReader& other)
{
	if (this != &other)
	{
		toRead = "";
		toRead = other.toRead;
		alreadyRead = other.alreadyRead;
	}

	return *this;
}

inline IntReader::~IntReader()
{
	toRead = "";
	alreadyRead = 0;
}

inline bool IntReader::read()
{
	try
	{
		std::cin >> toRead;
		alreadyRead = std::stoi(toRead);
	}
	catch (const std::exception&)
	{
		std::cout << "Cannot be read!\n";
	}
	return (toRead != "");
}

inline size_t IntReader::getData()
{
	toRead = "";
	return alreadyRead;
}

inline bool IntReader::isEmpty()
{
	return (alreadyRead == NULL);
}
