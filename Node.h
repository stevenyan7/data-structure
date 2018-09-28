/*
 * Node.h
 * Modifed by: Chu Yan
 * Modifed date: Feb 1st 2017
 * Class description: Node class - basic node class for linked list implementation.
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {

  // TO DO:: Fill in.
	public:
		// public attributes
		Customer data;
		Node* next;

		// constructions and destructions
		Node();
		Node(Customer theData);
		Node(Customer theData, Node* nextNode);
		//~Node();
};

#endif /* NODE_H_ */
