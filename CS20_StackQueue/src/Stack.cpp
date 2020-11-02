/*
 * Stack.cpp
 *
 *  Created on: Oct 21, 2020
 *      Author: cort
 */

#include "Stack.hpp"

/*
	 * Default stack, with a default maximum size of 10
	 */
	Stack::Stack(void)
	: head(nullptr), size(100)
	{

	}

	/*
	 * Overloaded constructor making the stack a maximum size of x
	 * This should throw a c-string exception.
	 * 		(example: throw "Invalid Size" if x is negative or zero.)
	 */
	Stack::Stack(int x)
	: head(nullptr), size(x)
	{

	}

	Stack::~Stack(void)
	{
		delete_list();
	}

	/*
	 * Same as text-book's push function, this should add a node containing a
	 *	customer pointer to the end of the stack and throw a c-string exception
	 *	(example: throw "push error") if the stack is full.
	 */
	void Stack::push(Customer* data)
	{
		//Same as push_front.
		node* newnode = new node;
		newnode->data = data;
		newnode->next = head;
		head = newnode;
	}

	/*
	 * Same as text-book's pop function, this should remove a node from the
	 *  back of the stack and throw a c-string exception if the stack is empty.
	 */
	void Stack::pop(void)
	{
		//Same as pop_front.
		node* temp = head;
		head = head->next;
		delete temp;
	}

	/*
	 * This function will return the customer pointer at the top of the stack.
	 */
	Customer* Stack::top(void)
	{
		return head->data;
	}

	/*
	 * Should return true if the stack is empty, false if it is not.
	 */
	bool Stack::isEmptyStack(void)
	{
		if (head == nullptr)
			return true;
		else
			return false;
	}

	/*
	 * Should return true if the stack is full, false if it is not.
	 */
	bool Stack::isFullStack(void)
	{
		node* T = head;
		int c = 0;

		while (T != nullptr)
		{
			c++;
			T = T->next;
		}

		T = nullptr;

		if (c >= size)
			return true;
		else
			return false;
	}


