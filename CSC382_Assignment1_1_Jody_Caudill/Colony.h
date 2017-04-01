#pragma once

/*
CSC382 - Bee hive Simulator - Jody Caudill

Colony header file
*/

#include <stdio.h>
#include <iostream>
#include "SimObject.h"
#include "QueenBee.h"
#include "DroneBee.h"
#include "WorkerBee.h"
#include "HoneyBee.h"
#include "Hive.h"
#include <vector>
#include <list>
#include <algorithm>
#include <memory>

class Colony:public SimObject
{
public:
	Colony();
	~Colony();
	void printStatus();
	void addBees(int count);
	void addQueen();
	void addQueen(QueenBee * newQueen);
	void Age();
	void Age(int days);
	void setBeeHive(Hive * hive);
	bool getSwarmCondition();

private:
	QueenBee * hiveQueen;
	std::list<HoneyBee *> bees;
	Hive * beeHive;
	int populationLvl;
	bool swarmCondition;
	void setSwarmCondition(bool swarm);
	QueenBee * makeStockQueen();
	void AgeBees();	//hive aging its bees
	void AddEggs(); //hive receiving new eggs from queen each day
	void ProcessDeadBees(); //process dead bees and clean them up
};

