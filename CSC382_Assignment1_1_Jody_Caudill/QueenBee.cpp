/*
CSC382 - Bee hive Simulator - Jody Caudill

QueenBee source file
*/

#include "QueenBee.h"

QueenBee::QueenBee()
{
	setLifeSpan(1500);
}


QueenBee::~QueenBee()
{
}

void QueenBee::setDaysToEggs(int days)
{
	daysToEggs = days;
}

int QueenBee::getDaysToEggs()
{
	return daysToEggs;
}

void QueenBee::setEggsPerDay(int eggs)
{
	eggsPerDay = eggs;
}

int QueenBee::getEggsPerDay()
{
	return eggsPerDay;
}

void QueenBee::setDroneChance(int chance)
{
	droneChance = chance;
}

int QueenBee::getDroneChance()
{
	return droneChance;
}

void QueenBee::Age()
{
	addToAge(1);
	checkLifeSpan();
}

void QueenBee::Age(int days)
{
	for (size_t i = 0; i < days; i++)
	{
		Age();
	}
}

HoneyBee * QueenBee::layEgg(bool * Worker)
{
	HoneyBee * bee;
	//deciede type  worker || drone
	srand(time(NULL));
	if (rand() % 100 < getDroneChance()) {
		bee = new DroneBee();
	}
	else {
		bee = new WorkerBee();
	}	
	setTraits(bee);
	return bee;
}

void QueenBee::setTraits(HoneyBee * bee)
{
	//introduce some gentic noise
	//I want to acutally use a vector or mated drones to randomly propigate genes as this program progresses
	srand(time(NULL));
	double varient = 1 + (rand() % 3 / 100);
	varient = 1 - (rand() % 3 / 100);
	
	bee->setHoneyProduction(getHoneyProduction() * varient);
	bee->setBroodProduction(getBroodProduction() * varient);
	bee->setHygenics(getHygenics() * varient);
	bee->setAgressivness(getAgressivness() * varient);
	bee->setPopTolerance(getPopTolerance() * varient);
	bee->setHoneyPerDayUsed(getHoneyPerDayUsed() * varient);
	bee->setTravelDistance(5);
	bee->setDaysToEmerge(21);
}

bool QueenBee::AreYouWorker()
{
	return false;
}
