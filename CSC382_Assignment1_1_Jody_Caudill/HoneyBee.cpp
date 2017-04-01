/*
CSC382 - Bee hive Simulator - Jody Caudill

HoneyBee source file
*/

#include "HoneyBee.h"

double HoneyBee::getHoneyProduction()
{
	return honeyProduction;
}

double HoneyBee::getBroodProduction()
{
	return broodProduction;
}

double HoneyBee::getHygenics()
{
	return hygenics;
}

double HoneyBee::getAgressivness()
{
	return agressivness;
}

double HoneyBee::getPopTolerance()
{
	return popTolerance;
}

double HoneyBee::getHoneyPerDayUsed()
{
	return honeyPerDayUsed;
}

double HoneyBee::getTravelDistance()
{
	return travelDistance;
}

int HoneyBee::getDaysToEmerge()
{
	return daysToEmerge;
}

int HoneyBee::getLifeSpan()
{
	return lifeSpan;
}

bool HoneyBee::getDead()
{
	return !alive;  
}

void HoneyBee::setLifeSpan(int days)
{
	lifeSpan = days;
}

void HoneyBee::setAlive(bool alive)
{
	this->alive = alive;
}

void HoneyBee::checkLifeSpan()
{
	if (getAge() > getLifeSpan()) {
		setAlive(false);
	}
}

void HoneyBee::setHoneyProduction(double honey)
{
	this->honeyProduction = honey;
}

void HoneyBee::setBroodProduction(double brood)
{
	broodProduction = brood;
}

void HoneyBee::setHygenics(double hygenic)
{
	hygenics = hygenic;
}

void HoneyBee::setAgressivness(double agressive)
{
	agressivness = agressive;
}

void HoneyBee::setPopTolerance(double Tolerance)
{
	popTolerance = Tolerance;
}

void HoneyBee::setHoneyPerDayUsed(double honey)
{
	honeyPerDayUsed = honey;
}

void HoneyBee::setTravelDistance(double distance)
{
	travelDistance = distance;
}

void HoneyBee::setDaysToEmerge(int days)
{
	daysToEmerge = days;
}
