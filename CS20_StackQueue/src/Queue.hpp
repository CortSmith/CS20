/*
 * Queue.hpp
 *
 *  Created on: Oct 21, 2020
 *      Author: cort
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <LinkedList.hpp>
#include <iostream>

#define DEBUG false

class Queue: private LinkedList
{
private:
	node* head;
	node* tail;
	int size;

public:
	/*
	 * Default queue, with a default maximum size of 100.
	 */
	Queue(void);

	/*
	 * Overloaded constructor making the queue a maximum size of x
	 *  This should throw a c-string exception (example: throw "Invalid Size") if x is
	 *  negative or zero.
	 */
	Queue(int x);

	virtual ~Queue();

	/*
	 * Same as text-book's addQueue function, this should add a node containing
	 *  a customer pointer to the end of the Queue and throw a c-string
	 *  exception (example: throw \push error") if the queue is full.
	 */
	void enqueue(Customer*);

	/*
	 * Same as text-book's deleteQueue function, this should remove a node
	 *	from the front of the Queue and throw a c-string exception if the queue
	 *	is empty.
	 */
	void dequeue(void);

	/*
	 * This function will return the customer pointer at the front of the queue.
	 */
	Customer* front(void);

	/*
	 * Should return true if the queue is empty, false if it is not.
	 */
	bool isEmptyQueue(void);

	/*
	 * Should return true if the queue is full, false if it is not.
	 */
	bool isFullQueue(void);
};




#endif /* QUEUE_HPP_ */
