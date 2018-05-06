// fn71793_VA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int TEAM_NAME = 30;
const int TEAM_MEMBERS = 50;

class Elf
{
public:
	Elf();
	~Elf();
	Elf(const Elf&);
	Elf& operator=(const Elf&);

private:
	char* name;
	unsigned age;
	short ability;

public:
	char* getName()const;
	void setName(const char*);
	unsigned getAge()const;
	void setAge(const unsigned);
	short getAbility()const;
	void setAbility(const short);
	void myStrCpy(char*&, const char*);
};

Elf::Elf()
{
	name = nullptr;
	age = 0;
	ability = 0;
}

Elf::~Elf()
{
	delete[] name;
	age = 0;
	ability = 1;
}

Elf::Elf(const Elf& other)
{
	myStrCpy(this->name, other.name);
	this->age = other.age;
	this->ability = other.ability;
}

Elf & Elf::operator=(const Elf& other)
{
	if (this != &other)
	{
		delete[] this->name;
		age = 0;
		ability = 1;
	}

	myStrCpy(this->name, other.name);
	this->age = other.age;
	this->ability = other.ability;
	
	return *this;
}

class ElfTeam
{
public:
	ElfTeam();
	~ElfTeam();
	ElfTeam(const ElfTeam&);
	ElfTeam& operator=(const ElfTeam&);

private:
	char name[TEAM_NAME];
	Elf* teamMembers[TEAM_MEMBERS];
	int countOfTeammates;

public:
	void AddMember(Elf& teammate);
	bool operator<(ElfTeam& otherTeam);
	ElfTeam& operator+=(const ElfTeam&);
	ElfTeam operator+(const ElfTeam& otherTeam);
};

ElfTeam::ElfTeam()
{
	//this->name = myStrCpy
	this->teamMembers[TEAM_MEMBERS] = new Elf[TEAM_MEMBERS];
}

ElfTeam::~ElfTeam()
{
	delete[] name;
	teamMembers[TEAM_MEMBERS] = nullptr;
	countOfTeammates = 0;
}

ElfTeam::ElfTeam(const ElfTeam& other)
{
	this->countOfTeammates = other.countOfTeammates;
	this->teamMembers[TEAM_MEMBERS] = new Elf[TEAM_MEMBERS];
	for (int i = 0; i < this->countOfTeammates; i++)
	{
		this->teamMembers[i] = other.teamMembers[i];
	}
}

ElfTeam& ElfTeam::operator=(const ElfTeam& other)
{
	if (this != &other)		// so sorry for the copy-paste design pattern
	{
		delete[] name;
		teamMembers[TEAM_MEMBERS] = nullptr;
		countOfTeammates = 0;

		this->countOfTeammates = other.countOfTeammates;
		this->teamMembers[TEAM_MEMBERS] = new Elf[TEAM_MEMBERS];
		for (int i = 0; i < this->countOfTeammates; i++)
		{
			this->teamMembers[i] = other.teamMembers[i];
		}
	}
	return *this;
}

void ElfTeam::AddMember(Elf& teammate)
{
	countOfTeammates++;
	this->teamMembers[this->countOfTeammates] = &teammate;
}

bool ElfTeam::operator<(ElfTeam& otherTeam)
{
	int a, b;
	for (int i = 0; i < TEAM_MEMBERS; i++)
	{
		a += (this->teamMembers[i])->getAge();
		b += (otherTeam.teamMembers[i]->getAge());
	}

	if (a < b)
	{
		return true;
	}
	return false;
}

ElfTeam& ElfTeam::operator+=(const ElfTeam& otherTeam)
{
	int firstTeam = this->countOfTeammates;

	this->countOfTeammates += otherTeam.countOfTeammates;
	if (this->countOfTeammates > TEAM_MEMBERS)
	{
		this->countOfTeammates = TEAM_MEMBERS;
	}

	this->teamMembers[TEAM_MEMBERS] = new Elf[TEAM_MEMBERS];
	for (int i = firstTeam + 1, int j = 0; i < TEAM_MEMBERS; i++)
	{
		this->teamMembers[i] = otherTeam.teamMembers[j];
	}

	return *this;
}

ElfTeam ElfTeam::operator+(const ElfTeam& otherTeam)
{
	int firstTeam = this->countOfTeammates;

	this->countOfTeammates += otherTeam.countOfTeammates;
	if (this->countOfTeammates > TEAM_MEMBERS)
	{
		this->countOfTeammates = TEAM_MEMBERS;
	}

	this->teamMembers[TEAM_MEMBERS] = new Elf[TEAM_MEMBERS];
	for (int i = firstTeam + 1, int j = 0; i < TEAM_MEMBERS; i++)
	{
		this->teamMembers[i] = otherTeam.teamMembers[j];
	}

	return ;
}

int main()
{
    return 0;
}

char* Elf::getName() const
{
	return this->name;
}

void Elf::setName(const char* newName)
{
	myStrCpy(this->name, newName);
}

unsigned Elf::getAge() const
{
	return this->age;
}

void Elf::setAge(const unsigned newAge)
{
	if (newAge < 0 || newAge > 300) //incorrect data -> default data
	{
		this->age = 0;
	}
	this->age = newAge;
}

short Elf::getAbility() const
{
	return this->ability;
}

void Elf::setAbility(const short newAbility)
{
	if (newAbility < 1 || newAbility > 15)	//incorrect data -> default data
	{
		this->ability = 1;
	}
	this->ability = newAbility;
}

void Elf::myStrCpy(char*& str1, const char* str2)
{
	if (str2)
	{
		unsigned length = 0;
		for (unsigned i = 0; str2[i] != '\0'; i++)
		{
			length++;
		}
		str1 = new char[length + 1];
		for (unsigned i = 0; str2[i] != '\0'; i++)
		{
			str1[i] = str2[i];
		}
		str1[length] = '\0';
	}
}
