/*
 * Customer.cpp
 * Modifed by: Chu Yan
 * Modifed date: Feb 1st 2017
 * Class description: Customer class which represents an customer object in ATM simulation. It tracks customer's transaction time and arrival time.
 */

#include "Customer.h"


// TO DO:: Fill in.
Customer::Customer() {}

// constructor
Customer::Customer(int transTime, int arriTime)
{
	transactionTime = transTime;
	arrivalTime = arriTime;
}

// getters and setters
int Customer::getTransTime() const {return transactionTime;}
int Customer::getArriTime() const {return arrivalTime;}

void Customer::setTransTime(int newTransTime) {transactionTime = newTransTime;}
void Customer::setArriTime(int newArriTime) {arrivalTime = newArriTime;}
