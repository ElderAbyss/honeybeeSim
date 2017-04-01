/*
CSC382 - Bee hive Simulator - Jody Caudill

WorkerBee source file
*/

#include "WorkerBee.h"


int WorkerBee::nurseyEndDay = 6;
int WorkerBee::hiveEndDay = 14;
int WorkerBee::workerLifeSpan = 42;
double WorkerBee::honeyPerDayMade = 0.00037;

WorkerBee::WorkerBee(): HoneyBee(), job(WorkerJobs::nursey)
{
	setLifeSpan(WorkerBee::workerLifeSpan);
	
}

WorkerBee::~WorkerBee()
{

}

void WorkerBee::Age()
{
	addToAge(1);
	checkJob();
	checkLifeSpan();
}

void WorkerBee::Age(int days)
{
	for (size_t i = 0; i < days; i++)
	{
		Age();
	}	
}

double WorkerBee::getHoneyMade() 
{
	double honeyMade = 0.0;
	if (job == WorkerJobs::harvesters) {	//check that the bee is of harvester age
		honeyMade = getHoneyProduction();	//baseline honey production factored by the Bee's genetic disposisiton of honey production
	}
	return honeyMade;
}

double WorkerBee::getHoneyPerDayUsed()
{
	return HoneyBee::getHoneyPerDayUsed() - getHoneyMade();
}

bool WorkerBee::AreYouWorker()
{
	return true;
}

void WorkerBee::checkJob()
{
	int thisAge = getAge();	//would have had to call getter three times so cheaper to set to locale variable
	if (thisAge > WorkerBee::nurseyEndDay){
		job = thisAge > WorkerBee::hiveEndDay ? WorkerJobs::harvesters : WorkerJobs::hive;
	}
}


