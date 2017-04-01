#pragma once
/*
CSC382 - Bee hive Simulator - Jody Caudill

DroneBee header file
*/

#include "HoneyBee.h"

class DroneBee : public HoneyBee
{
public:
	DroneBee();
	~DroneBee();
	double getHoneyPerDayUsed();
	bool AreYouWorker();
	void Age();
	void Age(int days);
};

