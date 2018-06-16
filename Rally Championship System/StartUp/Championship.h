#pragma once

#include "Race.h"
#include "Participant.h"

#include <tuple>

class Championship
{
private:
	Vector<Race> races;
	Vector<Participant*> participants;
	Manufactorer championCrew;
	Pilot championPilot;
	size_t raceMarker;

	Vector<std::tuple<Pilot, unsigned short, double>> pilotsRanking;
	Vector<std::tuple<Manufactorer, unsigned short>> manufactorersRanking;

	bool isSeasonOver();
	void swapP(std::tuple<Pilot, unsigned short, double> &a, size_t i, std::tuple<Pilot, unsigned short, double> &b, size_t j);
	void swapM(std::tuple<Manufactorer, unsigned short> &a, size_t i, std::tuple<Manufactorer, unsigned short> &b, size_t j);

public:
	//constructors
	Championship(Vector<Race> races, Vector<Participant*> participants);

	//getters
	size_t getNumberOfRaces();
	Vector<Race> getRaces();
	size_t getCountOfParticipants();
	Vector<Participant*> getParticipants();
	Manufactorer getChampionCrew();
	Pilot getChampionPilot();

	//setters
	void setRaces(Vector<Race> races);
	void setParticipants(Vector<Participant*> participants);
	void setChampionCrew(Manufactorer championCrew);
	void setChampionPilot(Pilot championPilot);

	//functionalities
	void startNextRace(); //show results
	void showRankingPilots(std::ostream& out);
	void showRankingManufactorers(std::ostream& out);
	void showWinnerPilots(std::ostream& out);
	void showWinnerManufactorers(std::ostream& out);
};