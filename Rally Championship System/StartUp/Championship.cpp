#include "stdafx.h"
#include "Championship.h"

bool Championship::isSeasonOver()
{
	return (raceMarker > getNumberOfRaces());
}

void Championship::swapP(std::tuple<Pilot, unsigned short, double>& a, size_t k, std::tuple<Pilot, unsigned short, double>& b, size_t j)
{
	std::tuple<Pilot, unsigned short, double> temp;
	temp = pilotsRanking[k];
	pilotsRanking[k] = pilotsRanking[j];
	pilotsRanking[j] = temp;
}

void Championship::swapM(std::tuple<Manufactorer, unsigned short>& a, size_t i, std::tuple<Manufactorer, unsigned short>& b, size_t j)
{
	std::tuple<Manufactorer, unsigned short> temp;
	temp = manufactorersRanking[i];
	manufactorersRanking[i] = manufactorersRanking[j];
	manufactorersRanking[j] = temp;
}

Championship::Championship(Vector<Race> _races, Vector<Participant*> _participants)
{
	races = _races;
	participants = _participants;
	raceMarker = 0;

	for (size_t i = 0; i < participants.size(); i++)
	{
		if (participants[i]->getType() == pilot)
		{
			Pilot* p = dynamic_cast<Pilot*>(participants[i]);
			pilotsRanking.push_back(std::make_tuple(*p, 0, 0));
		}
	}

	for (size_t i = 0; i < participants.size(); i++)
	{
		if (participants[i]->getType() == crewMember)
		{
			Manufactorer* m = dynamic_cast<Manufactorer*>(participants[i]);
			manufactorersRanking.push_back(std::make_tuple(*m, 0));
		}
	}
}

size_t Championship::getNumberOfRaces()
{
	return races.size();
}

Vector<Race> Championship::getRaces()
{
	return races;
}

size_t Championship::getCountOfParticipants()
{
	return participants.size();
}

Vector<Participant*> Championship::getParticipants()
{
	return participants;
}

Manufactorer Championship::getChampionCrew()
{
	return championCrew;
}

Pilot Championship::getChampionPilot()
{
	return championPilot;
}

void Championship::setRaces(Vector<Race> _races)
{
	races = _races;
}

void Championship::setParticipants(Vector<Participant*> _participants)
{
	participants = _participants;
}

void Championship::setChampionCrew(Manufactorer _championCrew)
{
	championCrew = _championCrew;
}

void Championship::setChampionPilot(Pilot _championPilot)
{
	championPilot = _championPilot;
}

//-------------------------------------------------------------------------------------
void Championship::startNextRace()
{
	//		BLACK MAGIC 101						101 rows of black magic
	if (isSeasonOver())
	{
		std::cout << "The season is over!\n";
		return;
	}

	std::ofstream outfile;
	outfile.open("races.txt", std::ios::app); // open file in append mode

	//calculate race index for each pilot
	Race currRace = races[raceMarker];
	size_t length = pilotsRanking.size();
	for (size_t i = 0; i < length; i++)
	{
		std::get<2>(pilotsRanking[i]) = (std::get<0>(pilotsRanking[i]).getRacingIndex(currRace.getPavement(), currRace.getPredominant()) * (rand() % 100 + 1)) / 10;
	}

	//reorder pilot's ranking
	size_t j = 0;
	for (size_t k = 0; k < length; k++)
	{
		double maxIndex = std::get<2>(pilotsRanking[k]);
		for (size_t i = k + 1; i < length; i++)
		{
			if (std::get<2>(pilotsRanking[i]) > maxIndex)
			{
				maxIndex = std::get<2>(pilotsRanking[i]);
				j = i;
			}
		}

		swapP(pilotsRanking[k], k, pilotsRanking[j], j);
	}

	//giving points at the end of the race
	//hardcoded
	std::get<1>(pilotsRanking[0]) = 20;
	std::get<1>(pilotsRanking[1]) = 15;
	std::get<1>(pilotsRanking[2]) = 10;
	std::get<1>(pilotsRanking[3]) = 8;
	std::get<1>(pilotsRanking[4]) = 6;
	std::get<1>(pilotsRanking[5]) = 5;
	std::get<1>(pilotsRanking[6]) = 4;
	std::get<1>(pilotsRanking[7]) = 3;
	std::get<1>(pilotsRanking[8]) = 2;
	std::get<1>(pilotsRanking[9]) = 1;

	//giving points at the end of the race
	length = manufactorersRanking.size();
	for (size_t k = 0; k < length; k++)
	{
		for (size_t i = k + 1; i < length; i++)
		{
			if (std::get<0>(manufactorersRanking[k]).getName() == std::get<0>(pilotsRanking[i]).getManufactorer())
			{
				std::get<1>(pilotsRanking[i]) = std::get<1>(manufactorersRanking[0]);
			}
		}
	}

	//reorder manufactorer's ranking
	j = 0;
	for (size_t k = 0; k < length; k++)
	{
		unsigned short maxPoints = std::get<1>(manufactorersRanking[k]);
		for (size_t i = k + 1; i < length; i++)
		{
			if (std::get<1>(manufactorersRanking[i]) > maxPoints)
			{
				maxPoints = std::get<1>(manufactorersRanking[i]);
				j = i;
			}
		}

		swapM(manufactorersRanking[k], k, manufactorersRanking[j], j);
	}
	
	//save in file
	outfile << "----------------------------------------------\nRACE " << raceMarker << ".\n";
	outfile << "Manufactorer's ranking\n";
	for (size_t i = 0; i < length; i++)
	{
		outfile << std::get<0>(manufactorersRanking[i]).getName() << ": " << std::get<1>(manufactorersRanking[i]) << " points\n";		
	}

	outfile << "Pilot's ranking\n";
	length = pilotsRanking.size();
	for (size_t i = 0; i < length; i++)
	{
		outfile << std::get<0>(pilotsRanking[i]).getName() << " with " << std::get<0>(pilotsRanking[i]).getCar().getModel() << " racing for " << std::get<0>(pilotsRanking[i]).getManufactorer() << ": " << std::get<1>(pilotsRanking[i]) << " points\n";
	}
	outfile << "---------------------------------------------------\n\n\n";

	//clear race indexes of pilots for the next race
	for (size_t i = 0; i < length; i++)
	{
		std::get<2>(pilotsRanking[i]) = 0;
	}

	raceMarker++;
	outfile.close();
}
//-------------------------------------------------------------------------------------

void Championship::showRankingPilots(std::ostream& out)
{
	size_t length = pilotsRanking.size();
	for (size_t i = 0; i < length; i++)
	{
		out << i << ". " << std::get<0>(pilotsRanking[i]).getName() << " with " << std::get<1>(pilotsRanking[i]) << " points\n";
	}
}

void Championship::showRankingManufactorers(std::ostream& out)
{
	size_t length = manufactorersRanking.size();
	for (size_t i = 0; i < length; i++)
	{
		out << i << ". " << std::get<0>(manufactorersRanking[i]).getName() << " with " << std::get<1>(manufactorersRanking[i]) << " points\n";
	}
}

void Championship::showWinnerPilots(std::ostream& out)
{
	if (!isSeasonOver())
	{
		out << "There's no winner yet.\n";
		return;
	}

	out << "The pilot champion is: " << getChampionPilot().getName() << std::endl;
}

void Championship::showWinnerManufactorers(std::ostream& out)
{
	if (!isSeasonOver())
	{
		out << "There's no winner yet.\n";
		return;
	}

	out << "The manufactorer champion is: " << getChampionCrew().getName() << std::endl;
}
