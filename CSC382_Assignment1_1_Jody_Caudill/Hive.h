#pragma once
/*
CSC382 - Bee hive Simulator - Jody Caudill

Hive header file
*/

#include "SimObject.h"

class Hive :public SimObject
{
public:
	Hive();
	~Hive();
	void Age();
	void Age(int days);
	void setHoneyStores(double honey);
	void addToHoneyStores(double honey);
	void removeFromHoneyStores(double honey);
	double getHoneyStores();
	int getBeeCapacity();
	void setBeeCapacity(int);
	void addBeeCapacity(int);


private:
	int beeCapacity;
	double honeyStores;

};

