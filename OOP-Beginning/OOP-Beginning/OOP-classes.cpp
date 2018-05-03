#include "stdafx.h"
#include <iostream>

using namespace std;

int const MAXLEN = 100;

class Student
{
private:
	char* firstName;
	char* lastName;
	int age;
	char* birthTown;
	int facultyNum;

private:
	void myStrCpy(char*&, const char*);
	void init();
	void copy(const Student&);
	void destroy();

public:
	Student();
	Student(const Student&);
	Student& operator=(const Student&);
	~Student();
	
	Student(const char* firstName, const char* lastName, unsigned age, const char* birthTown, unsigned facultyNum)
	{
		myStrCpy(this->firstName, firstName);
		myStrCpy(this->lastName, lastName);
		myStrCpy(this->birthTown, birthTown);
		this->age = age;
		this->facultyNum = facultyNum;
	}

	char* getFirstName()const;
	void setFirstName(const char*);

	char* getLastName()const;
	void setLastName(const char*);

	char*  getBirthTown()const;
	void setBirthTown(const char*);

	unsigned getAge()const;
	void setAge(const unsigned);

	unsigned getFacultyNum()const;
	void setFacultyNum(const unsigned);
};

//int main()
//{
//	char firN[MAXLEN];
//	char lastN[MAXLEN];
//	char birthT[MAXLEN];
//	unsigned age, facNum;
//	cin >> firN >> lastN >> birthT >> age >> facNum;
//	Student pesho(firN, lastN, age, birthT, facNum);
//
//	return 0;
//}

void Student::myStrCpy(char*& str1, const char* str2)
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

void Student::copy(const Student& other)
{
	myStrCpy(firstName, other.firstName);
	myStrCpy(lastName, other.lastName);
	myStrCpy(birthTown, other.birthTown);
	age = other.age;
	facultyNum = other.facultyNum;
}

void Student::init()
{
	firstName = lastName = birthTown = nullptr;
	age = facultyNum = 0;
}

void Student::destroy()
{
	delete[] firstName;
	delete[] lastName;
	delete[] birthTown;
}

Student::Student()
{
	init();
}

Student::Student(const Student& other)
{
	init();
	copy(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

Student::~Student()
{
	destroy();
}

char * Student::getFirstName() const
{
	return firstName;
}

void Student::setFirstName(const char* firstname)
{
	delete[] this->firstName;
	myStrCpy(this->firstName, firstname);
}

char * Student::getLastName() const
{
	return lastName;
}

void Student::setLastName(const char* lastname)
{
	delete[] this->lastName;
	myStrCpy(this->lastName, lastname);
}

char * Student::getBirthTown() const
{
	return birthTown;
}

void Student::setBirthTown(const char* birthTown)
{
	delete[] this->birthTown;
	myStrCpy(this->birthTown, birthTown);
}

unsigned Student::getAge() const
{
	return age;
}

void Student::setAge(const unsigned age)
{
	this->age = age;
}

unsigned Student::getFacultyNum() const
{
	return facultyNum;
}

void Student::setFacultyNum(const unsigned facNum)
{
	this->facultyNum = facNum;
}
