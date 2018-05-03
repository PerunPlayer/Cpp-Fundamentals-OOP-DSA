// Account.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int const MAXLEN = 100;

enum lvlOfPrivilege
{
	Guest = 1,
	Member = 2,
	Admin = 3
};

class Account
{
public:
	Account();
	~Account();
	Account(const Account&);
	Account& operator=(const Account&);

public:
	bool correctPassword();
	bool validate(char* name, char* pass);
	lvlOfPrivilege getPrivilege();
	void createAcc(char* nickname, char* password, lvlOfPrivilege privilege);
	void myStrCpy(char*& str1, const char* str2);

private:
	char* nickname;
	char* password;
	lvlOfPrivilege privilege;

private:
	void destroy();
	void init();
	void copy(const Account&);
};

Account::Account()
{
	init();
}

Account::~Account()
{
	destroy();
}

Account::Account(const Account& other)
{
	this->copy(other);
}

Account& Account::operator=(const Account& other)
{
	if (this != &other)
	{
		this->destroy();
		this->copy(other);
	}
	return *this;
}

bool Account::correctPassword()
{
	int length = strlen(this->password);
	for (int i = 0; i < length, password[i] != '\0'; i++)
	{
		if ((password[i] >= 'a' && password[i] <= 'z') ||
			(password[i] >= 'A' && password[i] <= 'Z') ||
			(password[i] >= '0' && password[i] <= '9'))
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool Account::validate(char* name, char* pass)
{
	int thisLen = strlen(this->nickname);
	if (thisLen == strlen(name))
	{
		for (int i = 0; i <= thisLen; i++)
		{
			if (this->nickname[i] != name[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	thisLen = strlen(this->password);
	if (thisLen == strlen(pass))
	{
		for (int i = 0; i <= thisLen; i++)
		{
			if (this->password[i] != pass[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

lvlOfPrivilege Account::getPrivilege()
{
	return this->privilege;
}

void Account::createAcc(char* nick, char* password, lvlOfPrivilege privilege)
{
	myStrCpy(this->nickname, nick);
	myStrCpy(this->password, password);
	if (!correctPassword())
	{
		cout << "Incorrect password!\0";
		return;		//TODO: catch it
	}
	this->privilege = privilege;

	if (!validate(this->nickname, this->password))
	{
		return;		//TODO: catch it
	}
}

void Account::myStrCpy(char*& str1, const char* str2)
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

void Account::destroy()
{
	delete[] nickname;
	delete[] password;
	privilege = (lvlOfPrivilege)0;
}

void Account::init()
{
	nickname = password = nullptr;
	privilege = (lvlOfPrivilege)1;
}

void Account::copy(const Account& other)
{
	this->privilege = other.privilege;
	int length = 0;

	if (other.nickname == nullptr)
	{
		this->nickname = nullptr;
	}
	else
	{
		length = strlen(other.nickname);
		this->nickname = new char[length];
		myStrCpy(this->nickname, other.nickname);
	}

	if (other.password == nullptr)
	{
		this->password = nullptr;
	}
	else
	{
		length = strlen(other.password);
		this->password = new char[length];
		myStrCpy(this->password, other.password);
	}
}


int main()
{
	char nickname[MAXLEN];
	char password[MAXLEN];
	lvlOfPrivilege privilege;
	int privil;
	cin >> nickname >> password;
	do
	{
		cin >> privil;
	} while (privil < 1 || privil > 3);
	privilege = (lvlOfPrivilege)privil;


	Account newAcc;
	newAcc.createAcc(nickname, password, privilege);

	return 0;
}


