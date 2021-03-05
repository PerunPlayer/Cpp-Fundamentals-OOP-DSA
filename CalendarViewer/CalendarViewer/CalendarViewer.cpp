#include <string>
#include <iostream>
using namespace std;

int dayNumber(int day, int month, int year)
{
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	year -= month < 3;
	return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

string getMonthName(int monthNumber)
{
	/*enum Day
	{Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday	};*/
	string months[] = { "January", "February", "March",	"April", "May", "June",	"July", "August", "September",	"October", "November", "December"};
	return (months[monthNumber]);
}

int numberOfDays(int monthNumber, int year)
{
	switch (monthNumber)
	{
	case 0:	case 2:	case 4:	case 6:	case 7:	case 9:	case 11:
		return 31;
	case 3:	case 5:	case 8:	case 10:
		return 30;
	case 1:
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			return (29);
		else
			return (28);

	default:
		std::cout << "Invalid month\n";
		break;
	}
}

int main()
{
	std::cout << "Enter year: ";
	int year = 0;
	std::cin >> year;
	std::cout << "Calendar - " << year << std::endl;

	int first = dayNumber(1, 1, year);

	int monthDays = 0;
	for (int month = 0; month < 12; month++)
	{
		monthDays = numberOfDays(month, year);
		std::cout << "\n ------------" << getMonthName(month) << "-------------\n";
		std::cout << " Mon Tue Wed Thu Fri Sat Sun\n";

		int k;
		//shift date
		for (k = 0; k < first - 1; k++)
		{
			std::cout << "    ";
		}

		for (int day = 1; day <= monthDays; day++)
		{
			printf("%4d", day);

			if (++k > 6)
			{
				k = 0;
				std::cout << std::endl;
			}
		}

		if (k)
			std::cout << std::endl;

		first = k;
	}

	return (0);
}
