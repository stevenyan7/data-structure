/*
 * ATM.h
 * Modifed by: Chu Yan
 * Modifed date: Feb 1st 2017
 * Class description: ATM class which represents an ATM object. It tracks few parameters.
 */


#ifndef ATM_H_
#define ATM_H_

#include "ATMQueue.h"
#include "Customer.h"

class ATM {
  // TO DO:: Fill in.
	private:
		int remainingTransTime;
		bool available;
		int timeSpent;
		ATMQueue* Que;
	public:
		// constructor & destructor
		ATM();
		~ATM();

		// settrs
		void insertCustomer(Customer newCus);
		void processCustomer(int currentTime);

		// getters
		int getQueueLength() const;
		int getRemainingTransTime() const;
		int getAvailable() const;
		int getTimeSpent() const;
};

#endif /* ATM_H_ */
