// IntReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntFilterReader.h"

bool p(size_t number);

int main()
{
	IntFilterReader reader;
	predicate f = p;
	reader.setPredicate(f);

	std::cout << reader.isEmpty() << std::endl;
	reader.read();
	std::cout << std::endl << reader.getData() << std::endl;
	std::cout << reader.isEmpty() << std::endl;

    return 0;
}

bool p(size_t number)
{
	return (((number % 2) == 0) && (number > 17));
}