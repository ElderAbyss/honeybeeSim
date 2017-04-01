#pragma once
/*
CSC382 - Bee hive Simulator - Jody Caudill

WorkerBee header file
*/
#include "HoneyBee.h"

enum WorkerJobs
{
	nursey,
	hive,
	harvesters
};

class WorkerBee : public HoneyBee
{
public:
	WorkerBee();
	~WorkerBee();
	void Age();
	void Age(int days);
	double getHoneyMade();
	double getHoneyPerDayUsed();  //overide in workerbee to encapsulate the mechanics that some workers both contribute and consume to overall honey
	bool AreYouWorker(); //allows for polymorphic window into a Bee * reference

private:
	WorkerJobs job;
	static double honeyPerDayMade;
	static int nurseyEndDay;
	static int hiveEndDay;
	static int workerLifeSpan;
	void checkJob();
	
};

