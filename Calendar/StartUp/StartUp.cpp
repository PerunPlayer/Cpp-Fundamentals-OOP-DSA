// StartUp.cpp : Defines the entry point for the console application.

// Задачата пред вас е да създадете приложение за водене на задачи в календар.Обобщено трябва да имате информация за
//ден, месец, година, събития(tasks), масив(списък, множество) от задачи които има човек през съответния ден, трябва да предоставите функционалност за добавяне на задача, също и за премахване
//Подробно описание :
//Календарът трябва да съдържа следната информация : кратко описание на календара, масив(списък) от месеци
//Месецът трябва да съдържа "минимум": брой дни в месеца, "поредица" от дни
//всеки ден има информация за : задачите които имате през този ден
//Реализирайте абстракция на задачите, като->Задачата ви представлява най - горното ниво на абстракция; пример - бизнес задачата представлява имплементация на задачата като добавяте необходимите полета и функционалност
//Задача - в нея да се пази информация за : наименование на събитието(последователност от символи), пояснение(description), часови диапазон(пример на формат на чч::мм::сс - чч::мм::сс), тип(по подразбиране - default, На всяко ниво да се сменя автоматично), номер на събитието - статична променлива(да посочва колко общо имате създадени) и номер на текущо създадената инстанция
//Бизнес : Всичко от задача, Хора на срещата - представлява поредица от име и фамилия(можете да го изнесете в отделен клас), местоположение, пресмятане на продължителността, наименование на домакина
//Учебна : наименование на предмет, материал, който трябва да се изчете
//Развлечение : вид на развлечението(това е различно от тип, тук може и енъм пример : семейно, разходка в парка или да е стринг), местоположение, да може да проверявате времето на това местоположение(пример системна команда system("start chrome  https://www.sinoptik.bg/search?q={карлово}");)
//Приложението да предоставя допълнителна функционалност, за отпечатване на всичките задачи през подаден от потребителя месец и ден, да може да добавяте на даден ден(през конкретен месец) - задача, както и да премахвате задача.
//
//Заб: предавайте домашните си в.zip формат, по шаблона фн_гр_2.zip(71999_1_2.zip), в решението на задачата да присъства поне един списък

#include "stdafx.h"
#include "LinkedList.h"
#include "Calendar.h"

using namespace std;

int main()
{
	BusinessTask t1;
	tuple<string, string> brato = make_tuple("Andon", "Denkov");
	auto minkov = make_tuple("Georgi", "Minkov");
	MyVector<tuple<string, string>> people;
	people.push_back(brato);
	people.push_back(minkov);

	people.printTuples(cout);

	Time start1(0, 0, 0), end1(0, 30, 2);
	Time start2("12:30:00"), end2("14:00:00");
	tuple<Time, Time> timespan1 = make_tuple(start1, end1);
	tuple<Time, Time> timespan2 = make_tuple(start2, end2);
	BusinessTask t2 = BusinessTask(people, "Sofia", timespan1, "FMI", "Making business", "If Minkov can play guitar, he could play with the band."); //call 2 constructors

	LinkedList<char*> books;
	books.push_back("Algorithms by Das Gupta");
	books.push_front("CLRS");
	books.pushAfter("Invitation to Computer Science 5th", 0);	//																						   	     /\ 
	EducationalTask edu1("SDP", books, "Learning", "Learning data structures and algorithms in c++.", timespan2);		//call only 1 constructor => faster than ||

	Time start3("22:30:00"), end3("02:00:00");
	tuple<Time, Time> timespan3 = make_tuple(start3, end3);
	EntertainmentTask ent1(playMusic, "Pernik", "Concert", "Night with Dazed and G-Point Rock", timespan3);
	ent1.checkWeather();

	Day concertDay;
	Task* concert = new EntertainmentTask(ent1);
	concertDay.getTasks().push_back(concert);

	t1.setDescription("Buy a portable speaker");
	t1.setHost("Rock`N`Roll Cafe");
	t1.setLocation("Pernik");
	people.pop_back();
	t1.setPeople(people);
	t1.setSpan(timespan2);
	t1.setTitle("Spend money");

	auto eduSubj = edu1.getSubject(); //char*
	auto eduBooks = edu1.getBooks(); //LinkedList<char*>
	auto eduTitle = edu1.getTitle(); //char*
	auto eduDescription = edu1.getDescription(); //char*
	auto type = edu1.getType(); //Type
	auto businessDuration = t2.getDuration(); //size_t
	size_t concertduration = ent1.getDuration();

	Task* firstToAdd = new EducationalTask(edu1);	//too many constructor calls, but only for tests needs
	Task* newTask = new EntertainmentTask(sport, "Sofia", "Basketball", "Just playing basketball", timespan2);
	Task* businessTask = new BusinessTask(t2);
	
	bool isLeap = false;
	Calendar for2018 = Calendar(isLeap);
	LinkedList<Task*> tasks;
	tasks.push_back(firstToAdd);
	tasks.push_front(newTask);
	tasks.pushAfter(businessTask, 0);
	for2018.getMonths()[1].getDays()[4].setTasks(tasks);
	
	//-------------------------------------------------------------------------------// other ways to add tasks - The only limit is your own imagination.
	//Day newDay;
	//newDay.setTasks(tasks);
	//for2018.getMonths()[1].getDays()[4] = newDay;
	
	//for2018.getMonths()[1].getDays()[4].getTasks().push_back(firstToAdd);
	//for2018.getMonths()[1].getDays()[4].getTasks().push_back(newTask);
	//for2018.getMonths()[1].getDays()[4].getTasks().push_back(businessTask);
	//for2018.getMonths()[1].getDays()[4].getTasks().print(cout);

	tasks.print(cout);

    return 0;
}

