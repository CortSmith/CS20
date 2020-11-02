/*
 * AddressBook.hpp
 *
 *  Created on: Sep 17, 2020
 *      Author: vessa
 */

#ifndef ADDRESSBOOK_HPP_
#define ADDRESSBOOK_HPP_

#define MAXLISTSIZE 500
#define DEBUG false

#include <string>
#include <iostream>
#include "AddressEntry.hpp"

class AddressBook
{
	// List.
	AddressEntry* head;

	// Last entry of the list.
	AddressEntry* tail;

public:

	// Contains total number of objects in list.
	int numItemsInList;
	AddressBook();
	~AddressBook();

	// Returns true if the list has no objects.
	// Precondition		:
	// Post-condition	:
	bool isEmpty() const;

	// Returns true if max size is met.
	// Precondition		:
	// Post-condition	: Returns true if the total of all objects is equal the max allowed objects.
	bool isFull() const;

	// Returns numItemsInList.
	// Precondition		:
	// Post-condition	: Returns the total of all objects in the list.
	int listSize() const;

	// Returns maximum allowed list size.
	// Precondition		:
	// Post-condition	: Returns the max size the list is allowed to be by design.
	int maxListSize() const;

	// Prints all objects in list.
	// Precondition		:
	// Post-condition	: Names of all objects are printed.
	void print() const;

	// Performs a linear search from beginning until target with name is found.
	// Precondition		: fullName must be a string.
	// Post-condition	: Returns an entry if entry with name exists; else nullptr is returned.
	void seqSearch(std::string fullName);

	// Inserts object at end of list.
	// Precondition		: Location must be an int
	// Post-condition	: Object is added to the end of the list.
	//					: Tail is updated to new object.
	void insertEnd(AddressEntry* newEntry);

	// Removes object at numeric location unless location is nullptr.
	// Precondition		: Location must be an int.
	//					  Location must be > 0 and <= 500.
	// Post-condition	: Object is removed from the list.
	void removeAt(int n);

	// Returns an address entry at location unless that object location is nullptr.
	// Precondition		: location must be an int.
	//					  Location must be > 0 and <= 500.
	// Post-condition	:
	AddressEntry* retrieveAt(int location);

	// Deletes all pointers in list.
	void clearList();
};



#endif /* ADDRESSBOOK_HPP_ */
