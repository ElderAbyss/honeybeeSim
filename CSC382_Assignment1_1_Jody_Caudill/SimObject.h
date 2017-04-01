#pragma once
/*
CSC382 - Bee hive Simulator - Jody Caudill

SimObject header file - Abstract class
*/

class SimObject
{
public:
	SimObject():age(1) {}
	virtual ~SimObject() {}	 //virtual - so we can polymorphically destory the right object
	virtual void Age() = 0;	 //virtual - used by all sim objects to repersent one day of the simulation
	virtual void Age(int days) = 0; //pure virtual, must overider in derived concerte class, this will allow for running the sim 'days' number of days
	int getAge() {
		return age;
	}
	void setAge(int days) {
		age = days;
	}
	void addToAge(int days) {
		age += days;
	}
private:
	int age;
	
};
