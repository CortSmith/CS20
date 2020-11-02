/*
 * Stack.hpp
 *
 *  Created on: Oct 21, 2020
 *      Author: cort
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include <LinkedList.hpp>
#include <Customer.hpp>

class Stack: private LinkedList
{
private:
	node* head;
	int size;

public:
	/*
	 * Default stack, with a default maximum size of 10
	 */
	Stack(void);

	/*
	 * Overloaded constructor making the stack a maximum size of x
	 * This should throw a c-string exception.
	 * 		(example: throw "Invalid Size" if x is negative or zero.)
	 */
	Stack(int);
	virtual ~Stack(void);

	/*
	 * Same as text-book's push function, this should add a node containing a
	 *	customer pointer to the end of the stack and throw a c-string exception
	 *	(example: throw "push error") if the stack is full.
	 */
	void push(Customer*);

	/*
	 * Same as text-book's pop function, this should remove a node from the
	 *  back of the stack and throw a c-string exception if the stack is empty.
	 */
	void pop(void);

	/*
	 * This function will return the customer pointer at the top of the stack.
	 */
	Customer* top(void);

	/*
	 * Should return true if the stack is empty, false if it is not.
	 */
	bool isEmptyStack(void);

	/*
	 * Should return true if the stack is full, false if it is not.
	 */
	bool isFullStack(void);

};



#endif /* STACK_HPP_ */
