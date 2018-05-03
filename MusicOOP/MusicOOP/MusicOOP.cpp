// MusicOOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    return 0;
}

class Song
{
private:
	char* title;
	char* musician;
	unsigned year;
	unsigned durationInSec;
	Song *original;

public:
	Song();
	Song(const Song&);
	Song& operator=(const Song&);
	~Song();

//private:
//	void myStrCpy(char*&, const char*);
//	void init();
//	void copy(const Song&);
//	void destroy();
};

Song::Song()
{
	title = musician = nullptr;
	year = durationInSec = 0;
	original = nullptr;
}

Song::Song(const Song& other)
{
	title = other.title;
	musician = other.musician;
	year = other.year;

	if (other.original == nullptr)
	{
		original = &other;
	}
	else
	{
		original = other.original;
	}
	
	
}

Song::~Song()
{
	delete[] title;
	delete[] musician;
	year = NULL;
	durationInSec = NULL;
	original = nullptr;
}

