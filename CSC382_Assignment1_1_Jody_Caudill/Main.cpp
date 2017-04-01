/*
CSC382 - Assignemnt 1.1 - Jody Caudill

n the first assignment we will focus on general C++ programming.  
Think of an example application that will make use of object oriented programming, overloading, and inheritance.

Bee hive Simulator
This program will simulate the lifecycle of a single bee hive to simulate colony reproduction and potential for 
random genetics to result in hive unsustainability.

Full write up assumptions and logic can be found in "CSC382 Assignment 1_1 Jody Caudill.docx"

*/
#include <stdio.h>
#include <iostream>
#include "SimObject.h"
#include "QueenBee.h"
#include "DroneBee.h"
#include "WorkerBee.h"
#include "HoneyBee.h"
#include "Hive.h"
#include "Colony.h"
#include <vector>


int main()
{
	int daysToSim = 243;
	Hive * beeHive = new Hive();
	beeHive->setBeeCapacity(80000);
	beeHive->setHoneyStores(96);

	Colony * beeColony = new Colony();
	beeColony->setBeeHive(beeHive);

	beeColony->addQueen();
	beeColony->addBees(12500);

	std::cout << "Simulate starting with a average honey bee package. One Queen and 12,500 bees for the hive" << std::endl;
	std::cout << "Simulation will run for " << daysToSim << " days." << std::endl;
	beeColony->printStatus();
	beeColony->Age(daysToSim);
	std::cout << "Simulate complete" << std::endl;
	beeColony->printStatus();

	system("pause");

}