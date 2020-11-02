/*
 * AddonLL.cpp
 *
 *  Created on: Oct 12, 2020
 *      Author: vessa
 */

#include <LinkedList.hpp>
#include <Customer.hpp>

//Recursive helpers
unsigned int LinkedList::getCustomerCount(void) {
	return customerCount(head);
}

Customer* LinkedList::getLargestBalance(void) {
	if (head == nullptr) return 0;
	return largestBalance(head, head->data);
}

Customer* LinkedList::getSmallestBalance(void) {
	if (head == nullptr) return 0;
	return smallestBalance(head, head->data);
}

double LinkedList::getTotalBalances(void) {
	return totalBalances(head);
}


//Recursive functions
unsigned int LinkedList::customerCount(node* T) {
	static int i=0;
	if (T == nullptr) {
		i=0;
		return i;
	}
	customerCount(T->next);
	return (unsigned) ++i;
}

Customer* LinkedList::largestBalance(node* T, Customer* C) {

	if (T == nullptr) {
		return C;
	}
	else
	{
		if (C->getAccountBalance() > T->data->getAccountBalance()) {
			largestBalance(T->next,C);
		}
		else {
			largestBalance(T->next,T->data);
		}
	}
}

Customer* LinkedList::smallestBalance(node* T, Customer* C) {

	if (T == nullptr) {
		return C;
	}
	else
	{
		if (C->getAccountBalance() < T->data->getAccountBalance()) {
			smallestBalance(T->next,C);
		}
		else {
			smallestBalance(T->next,T->data);
		}
	}
}

double LinkedList::totalBalances(node* T) {

	static double d = 0;

	if (T == nullptr) {
		d = 0;
		return d;
	}

	totalBalances(T->next);
	return d += T->data->getAccountBalance();
}


