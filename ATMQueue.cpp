/*
 * ATMQueue.cpp
 * Modifed by: Chu Yan
 * Modifed date: Feb 1st 2017
 * Class description: Data structure class - Queue. Owns basic Queue metthods. 
 */

#include "ATMQueue.h"
#include <stddef.h>
#include <iostream>
using namespace std;

// TO DO:: Fill in.
ATMQueue::ATMQueue() {numOfElem = 0;front = NULL; back = NULL;}
ATMQueue::~ATMQueue()
{
	cout << "ATMQueue destructor called.\n";
	Node* current = front;
	while (current != NULL)
	{
		front = front -> next;
		delete current;
		current = front;
	}
	delete back;
	delete front;
	numOfElem = 0;
}

// general methods
void ATMQueue::enqueue(const Customer elem)
{
	Node* newNode = new Node(elem, NULL);
	if(isEmpty())
	{
		front = newNode;
		back = newNode;
	}
	else
	{
		back -> next = newNode;
		back = newNode;
	}
	numOfElem ++;
}

void ATMQueue::dequeue()
{
	if(!isEmpty())
	{
		Node* current = front;
		front = front -> next;
		if(numOfElem == 1)
			back = NULL;
		delete current;
		numOfElem --;
	}
}

Customer ATMQueue::ATMQueue::peek() const {return front -> data;}
bool ATMQueue::ATMQueue::isEmpty() const {return numOfElem == 0;}
int ATMQueue::ATMQueue::size() const {return numOfElem;}