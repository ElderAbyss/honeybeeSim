/*
CSC382 - Bee hive Simulator - Jody Caudill

Hive source file
*/

#include "Hive.h"



Hive::Hive()
{
}


Hive::~Hive()
{
}

void Hive::Age()
{
	addToAge(1);
}

void Hive::Age(int days)
{
	for (size_t i = 0; i < days; i++)
	{
		Age();
	}
}

void Hive::setHoneyStores(double honey)
{
	honeyStores = honey;
}

void Hive::addToHoneyStores(double honey)
{
	honeyStores += honey;
}

void Hive::removeFromHoneyStores(double honey)
{
	honeyStores -= honey;
}

double Hive::getHoneyStores()
{
	return honeyStores;
}

int Hive::getBeeCapacity()
{
	return beeCapacity;
}

void Hive::setBeeCapacity(int capacity)
{
	beeCapacity = capacity;
}

void Hive::addBeeCapacity(int capacity)
{
	beeCapacity += capacity;
}
