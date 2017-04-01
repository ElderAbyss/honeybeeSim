/*
CSC382 - Bee hive Simulator - Jody Caudill

DroneBee source file
*/

#include "DroneBee.h"

DroneBee::DroneBee():HoneyBee()
{
	setLifeSpan(90);	
}


DroneBee::~DroneBee()
{
}

double DroneBee::getHoneyPerDayUsed()
{
	return HoneyBee::getHoneyPerDayUsed() * -1;
}

bool DroneBee::AreYouWorker()
{
	return false;
}

void DroneBee::Age()
{
	addToAge(1);
	checkLifeSpan();
}

void DroneBee::Age(int days)
{
	for (size_t i = 0; i < days; i++)
	{
		Age();
	}
}
