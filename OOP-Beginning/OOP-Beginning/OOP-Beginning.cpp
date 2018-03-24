// OOP-Beginning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

short const difference = 'a' - 'A';
const int MAX_LINE_LENGTH = 300;

void makeToUpper(ifstream& input, ofstream& outfile);
void howManyBaits();
void printDifferentLines(char* f1, char* f2);

//int main()
//{
//	ifstream input;
//	input.open("fmi_oop-in.txt");
//
//	ofstream outfile;
//	outfile.open("FMI_OOP-out.txt");
//
//	makeToUpper(input, outfile);
//	howManyBaits();
//	printDifferentLines("fmi_oop-in.txt", "FMI_OOP-out.txt");
//
//	input.close();
//	outfile.close();
//
//	return 0;
//}

void makeToUpper(ifstream& input, ofstream& outfile)
{
	char line[200] = { '\0' };
	while (!input.eof() && input.is_open())
	{
		input.getline(line, 200);
		for (short i = 0; i < 200; i++)
		{
			if (line[i] >= 'a' && line[i] <= 'z')
			{
				line[i] = line[i] - difference;
			}
		}
		outfile << line << '\n';
	}

	cout << "Ready with task 1\n";

	return;
}

void printDifferentLines(char* f1, char* f2)
{
	ifstream firstFile(f1);
	ifstream secondFile(f2);

	if (firstFile.is_open() && secondFile.is_open())
	{
		char firstFileLine[MAX_LINE_LENGTH] = { '\0' };
		char secondFileLine[MAX_LINE_LENGTH] = { '\0' };
		//different lines from first file
		while (!firstFile.eof())
		{
			firstFile.getline(firstFileLine, MAX_LINE_LENGTH);
			bool different = true;
			secondFile.seekg(ios::beg);
			while (!secondFile.eof())
			{
				secondFile.getline(secondFileLine, MAX_LINE_LENGTH);
				if (strcmp(firstFileLine, secondFileLine) == 0)
				{
					different = false;
				}
			}
			if (different)
			{
				cout << "< " << firstFileLine << '\n';
			}
		}

		secondFile.seekg(ios::beg);
		//different lines from second file
		while (!secondFile.eof())
		{
			secondFile.getline(secondFileLine, MAX_LINE_LENGTH);
			bool different = true;
			firstFile.seekg(ios::beg);
			while (!firstFile.eof())
			{
				firstFile.getline(firstFileLine, MAX_LINE_LENGTH);
				if (strcmp(secondFileLine, firstFileLine) == 0)
				{
					different = false;
				}
			}
			if (different)
			{
				cout << "> " << secondFileLine << '\n';
			}
		}
	}

	return;
}

void howManyBaits()
{
	ifstream input;
	input.open("fmi_oop-in.txt");

	int counter = 0;
	char buffer = '0';

	while (!input.eof() && input.is_open())
	{
		buffer = input.get();
		counter++;
	}

	cout << "The file size in Baits is: " << counter << "B\n";

	return;
}