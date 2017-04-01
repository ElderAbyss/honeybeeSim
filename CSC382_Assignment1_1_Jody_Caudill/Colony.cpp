/*
CSC382 - Bee hive Simulator - Jody Caudill

conlony source file
*/

#include "Colony.h"

Colony::Colony()
{
}


Colony::~Colony()
{
	delete hiveQueen;
	bees.clear();
	delete beeHive;
}

void Colony::printStatus() 
{
	int workerCount = 0, droneCount = 0, shouldBeDead = 0, dead = 0;
	double dailyHoney = 0.0;
	for each (HoneyBee * bee in bees)
	{
		if (bee->AreYouWorker()) {
			workerCount++;
		}
		else {
			droneCount++;
		}
		//some numbers to help test and debug
		if (bee->getAge() > bee->getLifeSpan()) { shouldBeDead = 0; }
		if (bee->getDead()) { dead = 0; }
		dailyHoney += bee->getHoneyPerDayUsed();
	}
	std::cout << "Status of the colony" << std::endl;
	std::cout << "Age of colony : " << getAge() << std::endl;
	//std::cout << "Queens : "<< queens.size() << std::endl;
	std::cout << "Workers : " << workerCount << std::endl;
	
	std::cout << "Should be Dead Bees : " << shouldBeDead << std::endl;
	std::cout << "Dead Bees : " << dead << std::endl;
	std::cout << "Drones : " << droneCount << std::endl;
	std::cout << "Number of bees : " << bees.size() << std::endl;
	std::cout << "Honey Stores : " << beeHive->getHoneyStores() << "oz of honey" << std::endl;
	std::cout << "Daily honey change : " << dailyHoney * -1 << "oz of honey" << std::endl;
}

void Colony::addBees(int count)
{
	QueenBee * theQueen = nullptr;	
	bool queenless = false;
	srand(time(NULL));
	if (hiveQueen != nullptr) {
		theQueen = hiveQueen;
	}
	else {
		queenless = true;
		theQueen = makeStockQueen();
	}
	//create 90% as worker bees
	bool egg = false;
	bool * workerEgg = &egg;
	HoneyBee * bee = nullptr;
	for (size_t i = 0; i < count; i++)
	{	
		bee = theQueen->layEgg(workerEgg);
		bee->setAge(rand() % 20 + 20);
		bee->Age();
		bees.emplace_back(bee);			
	}	
	//cleanup the queen if this was a queenless addition of bees
	if (queenless) {
		delete theQueen;
	}
}

void Colony::addQueen()
{
	hiveQueen = makeStockQueen();
}

void Colony::addQueen(QueenBee * newQueen)
{
	hiveQueen = newQueen;
}

void Colony::Age()
{
	addToAge(1);

	//age the bees	
	AgeBees();

	//add new eggs from Queen laying for the day to the bee count
	AddEggs();

	//dump status every 10 days
	if (getAge() % 20 == 0) { printStatus(); }
}

void Colony::Age(int days)
{
	for (size_t i = 0; i < days; i++)
	{
		Age();
	}
}

void Colony::setBeeHive(Hive * hive)
{
	beeHive = hive;
}

bool Colony::getSwarmCondition()
{
	return swarmCondition;
}

void Colony::setSwarmCondition(bool swarm)
{
	swarmCondition = swarm;
}

QueenBee * Colony::makeStockQueen()
{
	QueenBee * theQueen = nullptr;
	theQueen = new QueenBee();
	theQueen->setHoneyProduction(0.00037);
	theQueen->setBroodProduction(2000);
	theQueen->setHygenics(75);
	theQueen->setAgressivness(70);
	theQueen->setPopTolerance(0.85);
	theQueen->setHoneyPerDayUsed(0.0002448);
	theQueen->setTravelDistance(7);
	theQueen->setDaysToEmerge(16);
	theQueen->setDaysToEggs(23);
	theQueen->setEggsPerDay(2000);
	theQueen->setDroneChance(5);
	return theQueen;
}

void Colony::AgeBees()
{
	//age the gueen
	hiveQueen->Age();
	beeHive->removeFromHoneyStores(hiveQueen->getHoneyPerDayUsed()); //probably not worth doing, but just to be fair
	//age the bees
	auto stop = bees.end();
	for (std::list<HoneyBee *>::iterator bee = bees.begin(); bee != stop; bee++)
	{
		if (*bee != nullptr) {
			(*bee)->Age();
			beeHive->removeFromHoneyStores((*bee)->getHoneyPerDayUsed());
		}			
	}
	//remove dead bees
	ProcessDeadBees();
}

void Colony::AddEggs()
{
	int eggs = hiveQueen->getEggsPerDay();  //set call to a local because I don't want to call if for every iteration of the loop to check
	bool temp = false;
	bool * worker = &temp;
	for (size_t i = 0; i < eggs; i++)
	{
		bees.emplace_back(hiveQueen->layEgg(worker));
	}
	//if the hive is not in swarm conditon true, check the population against the queens tolerance and set if needed.
	if (!getSwarmCondition() && beeHive->getBeeCapacity() / bees.size() > hiveQueen->getPopTolerance()) {
		setSwarmCondition(true);
	}
}

void Colony::ProcessDeadBees()
{
	//loop to find and remove dead bees
	HoneyBee * deadBee = nullptr;
	auto stop = bees.end();	
	for (auto start = bees.begin(); start != stop; start++)
	{		
		if ((*start)->getDead())
		{
			auto temp = *start;
			//delete *start;
			start = bees.erase(start);			
			stop
				= bees.end();
			delete temp;
		}				
	}
		
}
  
