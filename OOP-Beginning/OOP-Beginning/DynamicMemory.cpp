#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void stringCopy(char*& dest, char* src);
char* stringConcat(char* str1, char* str2);

//int main()
//{
//	char* sentence = "Cuki e mnogo lud.";
//	char* newSentence = "";
//	stringCopy(newSentence, sentence);
//	cout << newSentence << endl;
//	char* secondSentence = "I mi e losho kato go vidq.";
//	newSentence = stringConcat(sentence, secondSentence);
//	cout << newSentence << endl;
//
//	ifstream input;
//	input.open("fmi_oop-in.txt");
//
//	int stringFileSize = 0;
//
//	char* stringFromFile = new char[stringFileSize];
//
//
//	input.close();
//
//
//	return 0;
//}

void stringCopy(char*& destination, char* source)
{
	int sizeOfDest = strlen(source) + 1;
	destination = new char[sizeOfDest];
	for (int i = 0; i < sizeOfDest - 1; i++)
	{
		destination[i] = source[i];
	}
	destination[sizeOfDest - 1] = '\0';

	return;
}

char* stringConcat(char* str1, char* str2)
{
	int lenght = strlen(str1) + strlen(str2) + 1;
	char* finalStr = new char[lenght];
	int str1len = strlen(str1);
	int str2len = strlen(str2);

	for (int i = 0; i < str1len; i++)
	{
		finalStr[i] = str1[i];
	}
	finalStr[str1len] = ' ';
	for (int i = 0; i < str2len; i++)
	{
		finalStr[i + str1len + 1] = str2[i];
	}
	finalStr[lenght] = '\0';
	return finalStr;
}