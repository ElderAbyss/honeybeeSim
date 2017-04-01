#pragma once
/*
CSC382 - Bee hive Simulator - Jody Caudill

QueenBee header file
*/

#include "HoneyBee.h"
#include <stdlib.h>
#include <time.h>
#include "DroneBee.h"
#include "WorkerBee.h"
#include <memory>

class QueenBee : public HoneyBee
{
public:
	QueenBee();
	~QueenBee();
	void setDaysToEggs(int days);
	int getDaysToEggs();
	void setEggsPerDay(int eggs);
	int getEggsPerDay();
	void setDroneChance(int chance);
	int getDroneChance();
	void Age();
	void Age(int days);
	HoneyBee * layEgg(bool * worker);
	void setTraits(HoneyBee *);		//not sure yet, but not conviced this needs to be public
	bool AreYouWorker();	//allows for polymorphic window into a Bee * reference
private:
	int daysToEggs;
	int eggsPerDay;
	int droneChance;

};

