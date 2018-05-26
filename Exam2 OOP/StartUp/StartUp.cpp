// StartUp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Page.h"
#include "Folder.h"

int main()
{
	Page description("Content", "1. \"Feel this moment - Pitbull ft. Christina Aguilera\", 2. \"Why you must to practice playing every day\", 3. \"They don't care about us\"");
	Page song1("Feel this moment", "E E C A A D D D F F G A ..."); //music sheets
	Page reason1("Musicians", "There's not so many musicians, so if you are very good...");
	Document* reason1P = new Page(reason1);
	Page reason2("Girls", "The fastest way to the heart of a girl is playing a song only for her....");
	Document* reason2P = new Page(reason2);
	std::vector<Document*> reasons;
	reasons.push_back(reason1P);
	reasons.push_back(reason2P);
	Folder practice("Why you must to practice playing every day", reasons);
	Page song2("They don't care about us", "F E F E F E D E D E D E D C D..."); // music sheets

	Document* descriptionP = new Page(description);
	Document* song1P = new Page(song1);
	Document* song2P = new Page(song2);
	Document* practiceP = new Folder(practice);
	std::vector<Document*> songBookContent;
	//songBookContent.push_back(descriptionP);
	//songBookContent.push_back(song1P);
	//songBookContent.push_back(practiceP);
	//songBookContent.push_back(song2P);
	Folder songBook("Song book", songBookContent);
	songBook.addDocument(descriptionP);
	songBook.addDocument(song1P);
	songBook.addDocument(practiceP);
	songBook.addDocument(song2P);

	std::cout << songBook.size() << std::endl;
	std::cout << songBook.getTitle() << std::endl;
	songBook.info(std::cout);
	songBook.contents(std::cout);
    return 0;
}

