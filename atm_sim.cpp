/*
 * atm_cim.cpp
 * Modifed by: Chu Yan
 * Modifed date: Feb 1st 2017
 * Class description: Main simulation program for ATM line-up simulation in certain time period, certain amount of ATMs and certain number of customers.
 */

#include "ATM.h"
#include "ATMQueue.h"
#include "Customer.h"
#include "Node.h"
#include "iostream"
using namespace std;

int getSimParameters(int &lenOfSim, int &numOfATM, int &numOfCus, int *&atime_list, int *&ttime_list);
void displaySimResults(int wait, int numOfCus);
int getShortestQue(int numOfATM, ATM* &ATMlist);

int main () {
  // TO DO:: Rename these
  int lenOfSim, numOfATM, numOfCus;
  int *atime_list, *ttime_list;

  // Total wait time for all customers in the simulation.
  int total_wait_time = 0;

  // Input code to read simulation parameters
  int param_err = getSimParameters(lenOfSim, numOfATM, numOfCus, atime_list, ttime_list);
  if (param_err) {
    cerr << "Error in simulation parameters." << endl;
    return -1;
  }



  // TO DO:: Your simulation code goes here.
  int realTime = 0, shownCus = 0; // realTime: current time indicator, shownCus: num of customers that has shown
  ATM* ATMlist = new ATM[numOfATM];
  while(realTime < lenOfSim || shownCus < numOfCus)
  {
    for(int i = shownCus; i < numOfCus; i++)
    {
      if(atime_list[i] == realTime && realTime < lenOfSim)
      {
        
        Customer newCus(ttime_list[i], atime_list[i]);
        ATMlist[getShortestQue(numOfATM, ATMlist)].insertCustomer(newCus);
        shownCus ++;

      }
    }

    // process ATMs
    for(int i = 0; i < numOfATM; i++)
      ATMlist[i].processCustomer(realTime);

    realTime ++;
  }

  // statistic
  for(int i = 0; i < numOfATM; i++)
    total_wait_time += ATMlist[i].getTimeSpent(); 


  // Display statistics on the simulation.
  displaySimResults(total_wait_time, numOfCus);
  // Return total_wait_time, will be used by test script.

  // memery delocate
  delete [] ATMlist;
  delete [] atime_list;
  delete [] ttime_list;

  return total_wait_time;
}




// Read the simulation parameters from standard input (cin).
// Parameters:
// lenOfSim: minutes to run simulation
// numOfATM: number of ATMs
// numOfCus: number of customers
// atime_list: array of customer arrival times
// ttime_list: array of customer transaction times
//    customer i arrives at time atime_list[i] and performs a transaction that takes ttime_list[i] minutes
//
// All parameters are pass-by-reference (note & character).  This means assignments in this function will affect value from calling function
// 
// Return value:
// returns 0 if successful read of input
// non-zero values used to denote failure
//   1: simulation time < 1
//   2: number of ATMs < 1
//   3: number of customers < 1
//   4: a customer's transaction time < 1
//   5: customer list is not sorted by arrival time
//   6: customer arrival time later than simulation end time
int getSimParameters(int &lenOfSim, int &numOfATM, int &numOfCus, int *&atime_list, int *&ttime_list) {
  // Code to read simulation parameters.
  cout << "Run an ATM simulation" << endl;

  cout << "Enter the number of minutes" << endl;
  cin >> lenOfSim;
  // Check input validity.
  if (lenOfSim < 1) {
    cerr << "Simulation for invalid length of time." << endl;
    return 1;
  }

  
  cout << "Enter the number of ATMs" << endl;
  cin >> numOfATM;
  // Check input validity.
  if (numOfATM < 1) {
    cerr << "Simulation for invalid number of ATMs." << endl;
    return 2;
  }


  // Read customer list
  cout << "Enter the number of customers" << endl;
  cin >> numOfCus;
  if (numOfCus < 1) {
    cerr << "Simulation for invalid number of customers." << endl;
    return 3;
  }
  // Allocate memory for customer list.
  atime_list = new int [numOfCus];
  ttime_list = new int [numOfCus];

  // Read numOfCus customers
  int atime = -1;
  int prevatime = -1;
  int ttime = 0;
  for (int i=0; i<numOfCus; i++) {
    cout << "Enter customer arrival and transaction time." << endl;
    cin >> atime;
    cin >> ttime;

    // Check input validity.
    if (ttime < 1) {
      cerr << "Invalid transaction time." << endl;
      return 4;
    }
    if (atime < prevatime) {
      cerr << "Arrival times not sorted." << endl;
      return 5;
    }
    if (atime >= lenOfSim) {
      cerr << "Arrival time later than simulation end time." << endl;
      return 6;
    }
    prevatime = atime;

    atime_list[i] = atime;
    ttime_list[i] = ttime;
  }

  // All went well, return 0.
  return 0;
}


// Display statistics on the simulation.
// wait: Total wait time of all customers in simulation.
// numOfCus: total number of customers in simulation.
void displaySimResults(int wait, int numOfCus) {
  cout << "Simulation results" << endl;
  cout << "Number of customers: " << numOfCus << endl;
  cout << "Total wait time: " << wait << endl;
  cout << "Average wait time: " << ((double) wait)/((double) numOfCus) << endl;
}

int getShortestQue(int numOfATM, ATM* &ATMlist)
{
  int result = 0;
  for(int i = 0; i < numOfATM; i++)
  {
    if(ATMlist[i].getAvailable())
      return i;
    else if(ATMlist[i].getQueueLength() < ATMlist[result].getQueueLength())
      result = i;
  }
  return result;
}
