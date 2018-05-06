// Vehicle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vehicle.h"
#include "Bicycle.h"
#include "Car.h"


int main()
{
	Vehicle smth(red, "Teck deck", 2015, 1, 50);
	Car ferrari(red, "Ferrari", 2015, 2, 320, "458 Italia", 2, 500);
	Bicycle balkan(blue, "Balkan", 1976, 1, 50, 1, 0, 1, "Zvyar");
	return 0;
}