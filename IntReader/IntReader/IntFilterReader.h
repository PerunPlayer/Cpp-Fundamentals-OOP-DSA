#pragma once

#include "IntReader.h"
using predicate = bool(*)(size_t);

class IntFilterReader : public IntReader
{
public:
	IntFilterReader();
	IntFilterReader(const IntFilterReader& other);
	IntFilterReader& operator=(const IntFilterReader& other);

	bool read() override;
	void setPredicate(predicate other);

private:
	bool isClean;
	predicate f;

};

IntFilterReader::IntFilterReader()
{
	isClean = 1;
}

inline IntFilterReader::IntFilterReader(const IntFilterReader& other)
{
	isClean = other.isClean;
}

inline IntFilterReader& IntFilterReader::operator=(const IntFilterReader& other)
{
	isClean = other.isClean;
	return *this;
}

inline bool IntFilterReader::read()
{
	try
	{
		std::cin >> toRead;
		alreadyRead = std::stoi(toRead);
		if (f(alreadyRead) && (alreadyRead != 0))
		{
			return true;
		}
		return false;
	}
	catch (const std::exception&)
	{
		std::cout << "Cannot be read!\n";
	}
	return false;
}

inline void IntFilterReader::setPredicate(predicate other)
{
	f = other;
}

