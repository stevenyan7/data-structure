/*
 * Node.cpp
 * Modifed by: Chu Yan
 * Modifed date: Feb 1st 2017
 * Class description: Node class - basic node class for linked list implementation.
 */

#include "Node.h"
#include <stddef.h>



// TO DO:: Fill in.
Node::Node(){next = NULL;}
Node::Node(Customer theData) {data = theData; next = NULL;}
Node::Node(Customer theData, Node* nextNode) {data = theData; next = nextNode;}
//Node::~Node() {}