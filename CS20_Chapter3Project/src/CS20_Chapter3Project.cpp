//============================================================================
// Name        : CS20_Chapter3Project.cpp
// Author      : Cort Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "AddressEntry.hpp"
#include "AddressBook.hpp"

template <typename T>
class Node
{
	T* next;
	T data;
};

int main()
{

	AddressBook book;
	AddressEntry* entry = nullptr;

	book.print();

	entry = new AddressEntry;
	entry->setFullName("cort");
	entry->setAddress("111 street ct.");
	entry->setPhoneNumber(1234567890);
	entry->setDateOfBirth(2, 18, 1995);
	book.insertEnd(entry);


	entry = new AddressEntry;
	entry->setFullName("chester");
	entry->setAddress("111 street ct.");
	entry->setPhoneNumber(1234567890);
	entry->setDateOfBirth(3, 12, 1990);
	book.insertEnd(entry);


	entry = new AddressEntry;
	entry->setFullName("sarah");
	entry->setAddress("111 street ct.");
	entry->setPhoneNumber(1234567890);
	entry->setDateOfBirth(1, 12, 2001);
	book.insertEnd(entry);


	entry = new AddressEntry;
	entry->setFullName("jenna");
	entry->setAddress("111 street ct.");
	entry->setPhoneNumber(1234567890);
	entry->setDateOfBirth(7, 12, 1993);
	book.insertEnd(entry);


	string name = "chester";
	book.seqSearch(name);
	book.removeAt(2);
	book.print();
	book.clearList();

	cout << "Program ending..." << endl; // prints !!!Hello World!!!
	return 0;
}
