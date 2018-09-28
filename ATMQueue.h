/*
 * ATMQueue.h
 * Modifed by: Chu Yan
 * Modifed date: Feb 1st 2017
 * Class description: Data structure class - Queue. Owns basic Queue metthods. 
 */

#ifndef ATMQUEUE_H_
#define ATMQUEUE_H_

#include "Node.h"
#include "Customer.h"

class ATMQueue {
  // TO DO:: Fill in.
	private:
		int numOfElem;
		Node* front;
		Node* back;
	public:
		// constructor & destructor
		ATMQueue();
		~ATMQueue();

		// general methods
		void enqueue(const Customer elem);
		void dequeue();

		Customer peek() const;
		bool isEmpty() const;
		int size() const;
};

#endif /* ATMQUEUE_H_ */
