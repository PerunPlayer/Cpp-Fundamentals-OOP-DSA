#pragma once

#include <vector>

#include "Race.h"

class Championship
{
private:
	std::vector<Race> races;
	std::vector<Participant*> participants;
	bool manufactorersTrophy;
	bool pilotsTrophy;

	bool isSeasonOver();

public:
	//constructors
	Championship(std::vector<Race> races, std::vector<Participant*> participants, bool manufactorersTrophy, bool pilotsTrophy);

	//getters
	unsigned short getNumberOfRaces();
	std::vector<Race> getRaces();
	auto getCountOfParticipants();
	std::vector<Participant*> getParticipants();
	bool getManufactorersTrophy();
	bool getPilotsTrophy();

	//setters
	void setRaces(std::vector<Race> races);
	void setParticipants(std::vector<Participant*> participants);
	void setManufactorersTrophy(bool manufactorersTrophy);
	void setPilotsTrophy(bool pilotsTrophy);

	//functionalities
	void startNextRace(); //show results
	void showRankingPilots(std::ostream& out);
	void showRankingManufactorers(std::ostream& out);
	void showWinnerPilots(std::ostream& out);
	void showWinnerManufactorers(std::ostream& out);
};