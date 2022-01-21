// HW1-OOP.cpp : Defines the entry point for the console application.
//
//�� �� ������� ���� Jedi � ����� �� ��� name(char*), rank(char*/enum), midi-chlorian(double/float), planet(Planet), species(char*), militaryRank(char*).
//�� �� ������� ���� Stormtrooper � ����� �� ��� id(char*), rank(enum), type(char*), planet(Planet).
//�� �� ������� ���� Planet name(char*), planetSystem(char*), republic(char*) - ��� �� ������������� � ���������.
//�� �� ������� ���� JediTemple � ����� �� ��� jedi(Jedi*).
//�� �� ������� ���� Army � ����� �� ��� troops(Stormtrooper*).
//�� �� ������� ���� Galaxy � ����� �� ��� ��� �� ����������� � planets(Planet*).
//�� �� ������� ���� GalacticRepublic � ����� �� ��� ��� �� �����������, jediTemple(JediTemple), Army(Stormtrooper), galaxy(Galaxy).
//� JediTemple, ������ �� ����� �� �� ������� ���� Jedi � �� �� ���������.� Army, ������ �� ����� �� �� ������� ���� Stormtrooper � �� �� ���������.
//� Galaxy, ������ �� ����� �� �� ������� ���� Planet � �� �� ���������.
//��������� � ���������� �� ����� ���������� ����������� �������� ��������.
//�� ����� �� �� ��������� ������ Jedi �� ���� ������� � �� ����� �� �� ��������� ������ Stormtrooper �� ���� �������, � �� ����� �� �� ��������� ������ ������� � ���������.
//������ ������������ �� Jedi, Stormtrooper � Planet �� �� ���� � ������� �������.�.� ���� ���� �� Jedi, ���� ���� �� Stormtrooper � ���� �� Planet.
//�������, �� ���� ��������� �������� ������ ���������, ��� ������� ����������� ������������ �������� � ������ �������� ������� � ���.���� ������� � ���������� �� ������ ���������, ��� ����������� ��������� �������� �������, �� �� �� - ����� �� 3. �� �� ������ �������, ����� �� �������� ��������� � ��������� �������� ������������.�� �� ������ �������, ����� ��������� ����� �� ����������� � ������������ �� ���������, ���� ��������� �� ������� � ������� ���� ����� ������ : [��� �� ���������] - [��� �� ���������]
//

#include "stdafx.h"
#include "Jedi.h"
#include "Planet.h"
#include "Stormtrooper.h"
#include "JediTemple.h"
#include "Army.h"
#include "Galaxy.h"
#include "GalacticRepublic.h"

#include <iostream>
#include <fstream>

using namespace std;

GalacticRepublic& findDominating(GalacticRepublic& republic, GalacticRepublic& newWorldOrder, const Galaxy& StarWarsGalaxy);

int main()
{
	Planet alderaan = Planet("Alderaan", "Core Worlds", "Republic");
	Jedi youngling;
	Jedi PloKoon("Plo Koon", JediMaster, 8000, alderaan, "Kel Dor", "general");
	Stormtrooper Fives = Stormtrooper("FN5555", BattalionCommander, "Clone trooper", alderaan);
	JediTemple TempleOfYoda;
	TempleOfYoda.add(PloKoon);
	TempleOfYoda.add(youngling);
	Army FifthLegion;
	FifthLegion.add(Fives);
	Planet mustafar = Planet("Mustafar", "Outer Rim Territories", "Republic");
	Planet* planetsArr = new Planet[1];
	planetsArr[0] = mustafar;
	Galaxy StarWarsGalaxy = Galaxy("George Lucas' Galaxy", planetsArr, 1);
	StarWarsGalaxy.add(alderaan);
	Planet camino = Planet("Camino", "Not found! Perhaps the archieves are incomplete.", "Not found");
	StarWarsGalaxy.add(camino);		// must resize
	Planet coruscant = Planet("Coruscant", "Core worlds", "Republic");
	StarWarsGalaxy.add(coruscant);
	GalacticRepublic republic = GalacticRepublic("The Republic", TempleOfYoda, FifthLegion, StarWarsGalaxy);
	Jedi yoda = Jedi("Yoda", JediMaster, 17000, coruscant, "carnivorous humanoid", "general");
	cout << republic.getTemple().sizeOf() << endl;
	republic.getTemple().remove(youngling);
	//TempleOfYoda.remove(youngling);
	cout << republic.getTemple().sizeOf() << endl;
	republic.getTemple().add(yoda);
	cout << republic.getTemple().sizeOf() << endl;
	Stormtrooper deathtrooper = Stormtrooper("FN77354", BattalionCommander, "Death trooper", coruscant);
	Stormtrooper jumper = Stormtrooper("FN56700", SquadLeader, "Jump trooper", alderaan);
	republic.getArmy().add(deathtrooper);
	republic.getArmy().add(jumper);
	Planet endor = Planet("Endor", "Outer Rim Territoties", "Republic");
	republic.getGalaxy().add(endor);
	Stormtrooper rookie = Stormtrooper("FD88999", Trooper, "Forest trooper", endor);
	cout << republic.getArmy().sizeOf() << endl;
	republic.getArmy().add(rookie);
	cout << republic.getArmy().sizeOf() << endl;
	republic.getArmy().remove(rookie);
	cout << republic.getArmy().sizeOf() << endl;
	cout << republic.getGalaxy().sizeOf() << endl;
	republic.getGalaxy().remove(mustafar);
	cout << republic.getGalaxy().sizeOf() << endl;
	Jedi windu = Jedi("Mace Windu", JediMaster, 12000, coruscant, "human", "general");
	republic.getTemple().add(windu);
	int size = republic.getTemple().sizeOf();
	republic.printAllJedi(coruscant);				//print all jedi on one planet
	republic.printAllStormtroopers(coruscant);		//print all stormtroopers on one planet
	ofstream fout;
	fout.open("JediDB.txt");
	republic.printAllJedi(fout);
	fout.close();
	fout.open("StormtrooperDB.txt");
	republic.printAllStormtroopers(fout);
	fout.close();
	fout.open("PlanetDB.txt");
	republic.printAllPlanets(fout);					//print all planets in one galaxy
	fout.close();
	JediTemple orderOfTheGrayJedi;
	Army firstOrder;
	GalacticRepublic newWorldOrder("Republic of the new world order", orderOfTheGrayJedi, firstOrder, StarWarsGalaxy);
	GalacticRepublic result = findDominating(republic, newWorldOrder, StarWarsGalaxy);


	return 0;
}

GalacticRepublic& findDominating(GalacticRepublic& republic, GalacticRepublic& newWorldOrder, const Galaxy& StarWarsGalaxy) //������ ���������� �� ������� => ������� �� ���������� �� ����������� :D :D XD
{
	//if ((republic.getArmy().sizeOf() > newWorldOrder.getTemple().sizeOf())
	//	&& (republic.getGalaxy().sizeOf() > newWorldOrder.getGalaxy().sizeOf()))	//��� ������� ����������� ������������ �������� => ������� �� ������ ��������� ������ �������� �� ������� (Order 66)
	//{
	//	return republic;
	//}
	//if ((newWorldOrder.getArmy().sizeOf() > republic.getArmy().sizeOf())
	//	&& (newWorldOrder.getGalaxy().sizeOf() > republic.getGalaxy().sizeOf()))
	//{
	//	return newWorldOrder;
	//}

	GalacticRepublic nullG;
	return nullG;
}