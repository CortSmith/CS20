/*
 * AddressBook.cpp
 *
 *  Created on: Sep 17, 2020
 *      Author: vessa
 */

#include "AddressBook.hpp"

AddressBook::AddressBook()
{
	head = nullptr;
	tail = nullptr;
	numItemsInList = 0;
}

AddressBook::~AddressBook()
{
	delete head;
	delete tail;
}

bool AddressBook::isEmpty() const
{
	if (head == nullptr)
	{
		return true;
	}

	return false;
}

bool AddressBook::isFull() const
{
	if (this->numItemsInList >= this->maxListSize())
	{
		return true;
	}

	return false;
}

int AddressBook::listSize() const
{
	return this->numItemsInList;
}

int AddressBook::maxListSize() const
{
	return MAXLISTSIZE;
}

void AddressBook::print() const
{
	if (this->isEmpty())
	{
		std::cerr << "List is empty, item to remove is out of range." << std::endl;
		return;
	}

	AddressEntry* T = this->head;
	while (T)
	{
		std::cout << "Name          " << T->getName() << std::endl;
		std::cout << "Address       " << T->getAddress() << std::endl;
		std::cout << "Phone Number  " << T->getPhoneNumber() << std::endl;
		T = T->next;
	}
}

void AddressBook::seqSearch(std::string fullName)
{
	if (this->isEmpty())
	{
		std::cerr << "List is empty, item to remove is out of range." << std::endl;
		return;
	}

	AddressEntry* T = head;

	// Get the last object in list.
	while (head != nullptr)
	{
		// If name is found in list
		if (T->getName() == fullName)
		{
			std::cout << "Name      : " << T->getName() << std::endl;
			std::cout << "Address   : " << T->getAddress() << std::endl;
			std::cout << "Number    : " << T->getPhoneNumber() << std::endl;
			return;
		}
		T = T->next;
	}

	return;
}

void AddressBook::insertEnd(AddressEntry* newEntry)
{

	//Full list case
	if (isFull())
	{
		std::cerr << "Cannot insert in a full list." << std::endl;
		return;
	}

	// Empty case
	if (this->head == nullptr)
	{
		newEntry->prev = nullptr;
		newEntry->next = nullptr;
		head = newEntry;
		tail = newEntry;
		numItemsInList++;
		return;
	}

	newEntry->prev = tail;
	newEntry->next = nullptr;
	tail->next = newEntry;
	tail = newEntry;
	numItemsInList++;
}

void AddressBook::removeAt(int n)
{

	//Empty case.
	if (isEmpty())
	{
		std::cerr << "List is empty, item to remove is out of range." << std::endl;
		return;
	}

	//Out of range case.
	if (n >= this->numItemsInList || n < 0)
	{
		std::cerr << "index is out of range." << std::endl;
		return;
	}

	AddressEntry* T = this->head;


	//Find target index.
	for (int i=0; i<n; i++)
	{
		T = T->next;
	}

	if (T->prev) {
		T->prev->next = T->next;
	}
	else {
		this->head = T->next;
		T->next->prev = head;
	}

	if (T->next)
		T->next->prev = T->prev;
	else {
		this->tail = T->prev;
		T->prev->next = nullptr;
	}

	this->numItemsInList--;
	//delete T;
}

AddressEntry* AddressBook::retrieveAt(int index)
{
	//Empty case.
	if (isEmpty())
	{
		std::cerr << "List is empty, no item to return." << std::endl;
		return nullptr;
	}

	//Out of range case.
	if (index >= this->numItemsInList || index < 1)
	{
		std::cerr << "index is out of range." << std::endl;
		return nullptr;
	}

	AddressEntry* T = head;

	//Find target index.
	for (int i=1; i<index; i++)
	{
		T = T->next;
	}

	return T;
}

void AddressBook::clearList()
{
	if (this->isEmpty())
	{
		std::cerr << "List is empty, item to remove is out of range." << std::endl;
		return;
	}

	AddressEntry* T = head;

	while (head != nullptr)
	{
		T = head;
		head = head->next;
		delete T;
	}
}























