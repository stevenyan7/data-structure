/*
 * Customer.h
 * Modifed by: Chu Yan
 * Modifed date: Feb 1st 2017
 * Class description: Customer class which represents an customer object in ATM simulation. It tracks customer's transaction time and arrival time.
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
  // TO DO:: Fill in.
	private:
		int transactionTime;
		int arrivalTime;
	public:
		// constructions
		Customer();
		Customer(int transTime, int arriTime);

		// getters and setters
		int getTransTime() const;
		int getArriTime() const;

		void setTransTime(int newTransTime);
		void setArriTime(int newArriTime);
};

#endif /* CUSTOMER_H_ */
