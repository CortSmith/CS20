/*
 * Queue.cpp
 *
 *  Created on: Oct 21, 2020
 *      Author: cort
 */

#include "Queue.hpp"

/*
	 * Default queue, with a default maximum size of 100.
	 */
	Queue::Queue(void)
	: head(nullptr), tail(nullptr), size(100)
	{

	}

	/*
	 * Overloaded constructor making the queue a maximum size of x
	 *  This should throw a c-string exception (example: throw "Invalid Size") if x is
	 *  negative or zero.
	 */
	Queue::Queue(int x)
	: head(nullptr), tail(nullptr), size(x)
	{

	}

	Queue::~Queue()
	{
		delete_list();
	}

	/*
	 * Same as text-book's addQueue function, this should add a node containing
	 *  a customer pointer to the end of the Queue and throw a c-string
	 *  exception (example: throw \push error") if the queue is full.
	 */
	void Queue::enqueue(Customer* data)
	{
		if (DEBUG) std::cout << "Entering enqueue" << std::endl;
		if (DEBUG) std::cout << "	Allocating a new data pointer" << std::endl;
		//push_back
		node* newnode = new node;
		newnode->data = data;
		newnode->next = nullptr;

		if (DEBUG) std::cout << "	Checking if empty" << std::endl;
		if (head == nullptr)
		{
			if (DEBUG) std::cout << "		List is empty" << std::endl;
			if (DEBUG) std::cout << "		Setting head and tail to new node" << std::endl;
			head = newnode;
			tail = newnode;

			if (DEBUG) std::cout << "		Exiting enqueue" << std::endl;
			return;
		}

		if (DEBUG) std::cout << "	List is not empty" << std::endl;
		if (DEBUG) std::cout << "	Renewing tail pointer target to new node" << std::endl;
		tail->next = newnode;
		tail = tail->next;

		if (DEBUG) std::cout << "	Clearing node ref from temp data variable" << std::endl;
		newnode = nullptr;
		if (DEBUG) std::cout << "	Exiting enqueue" << std::endl;
	}

	/*
	 * Same as text-book's deleteQueue function, this should remove a node
	 *	from the front of the Queue and throw a c-string exception if the queue
	 *	is empty.
	 */
	void Queue::dequeue(void)
	{
		//pop_front
		if (head == nullptr)
			return;

		node* temp = head;
		head = head->next;
		delete temp;
	}

	/*
	 * This function will return the customer pointer at the front of the queue.
	 */
	Customer* Queue::front(void)
	{
		if (head == nullptr)
			return 0;
		return head->data;
	}

	/*
	 * Should return true if the queue is empty, false if it is not.
	 */
	bool Queue::isEmptyQueue(void)
	{
		if (head == nullptr)
			return true;
		return false;
	}

	/*
	 * Should return true if the queue is full, false if it is not.
	 */
	bool Queue::isFullQueue(void)
	{
		node* T = head;
		int c = 0;
		while (T != nullptr)
		{
			c++;
			T = T->next;
		}

		if (c >= size)
			return true;
		return false;
	}
