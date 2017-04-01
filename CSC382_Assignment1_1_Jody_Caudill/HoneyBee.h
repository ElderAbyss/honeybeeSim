#pragma once

/*
CSC382 - Bee hive Simulator - Jody Caudill

HoneyBee header file - Abstract class
*/

#include "SimObject.h"
#include <memory>

class HoneyBee : public SimObject
{
public:
	HoneyBee() :SimObject() {};
	virtual ~HoneyBee() {};		//virtual - so we can polymorphicaly destory the rigth bee object
	virtual void Age() = 0;		//pure virtual, must overider in derived concerte class
	virtual void Age(int days) = 0;	//pure virtual, must overider in derived concerte class
	double getHoneyProduction();
	double getBroodProduction();
	double getHygenics();
	double getAgressivness();
	double getPopTolerance();
	virtual double getHoneyPerDayUsed();	//virtual - allows each derived to implements it's alogrithym for net honey used/produced
	double getTravelDistance();
	int getDaysToEmerge();
	int getLifeSpan();
	bool getDead();
	void setLifeSpan(int days);
	void setAlive(bool alive);
	void checkLifeSpan();	//used to kill okd bees
	void setHoneyProduction(double honey);
	void setBroodProduction(double brood);
	void setHygenics(double hygenic);
	void setAgressivness(double agressive);
	void setPopTolerance(double Tolerance);
	void setHoneyPerDayUsed(double honey);
	void setTravelDistance(double distance);
	void setDaysToEmerge(int days);
	virtual bool AreYouWorker() = 0;	//pure virtual, must overider in derived concerte class - allows for polymorphic window into a Bee * reference

private:
	bool alive;
	double honeyProduction;
	double broodProduction;
	double hygenics;
	double agressivness;
	double popTolerance;
	double honeyPerDayUsed;
	double travelDistance;
	int daysToEmerge;
	int lifeSpan;

};
