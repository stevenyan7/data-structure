/*
 * ATM.cpp
 * Modifed by: Chu Yan
 * Modifed date: Feb 1st 2017
 * Class description: ATM class which represents an ATM object. It tracks few parameters.
 */

#include "ATM.h"
#include <iostream>
using namespace std;

// TO DO:: Fill in.
ATM::ATM()
{
	remainingTransTime = 0;
	available = true;
	timeSpent = 0;
	Que = new ATMQueue;
}

ATM::~ATM() {cout << "ATM destructor called.\n"; delete Que;}

// settrs
void ATM::insertCustomer(Customer newCus)
{
	if(available)
		remainingTransTime = newCus.getTransTime();
	else
		Que -> enqueue(newCus);
	available = false;
}

void ATM::processCustomer(int currentTime)
{
	if(!available)
		remainingTransTime -= 1;
	if(available)
	{
		if(getQueueLength() != 0)
		{
			remainingTransTime = Que -> peek().getTransTime();
			timeSpent += currentTime - Que -> peek().getArriTime();
			Que -> dequeue();
			remainingTransTime -= 1;
			available = false;
		}
	}
	if(remainingTransTime == 0)
		available = true;
}

// getters
int ATM::getQueueLength() const {return Que -> size();}
int ATM::getRemainingTransTime() const {return remainingTransTime;}
int ATM::getAvailable() const {return available;}
int ATM::getTimeSpent() const {return timeSpent;}