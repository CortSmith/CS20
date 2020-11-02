//============================================================================
// Name        : CS20_RecursiveLinkedList_UsingLibraries.cpp
// Author      : Cort Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <LinkedList.hpp>
#include <Customer.hpp>

int main() {
	LinkedList list;

	Customer* c = new Customer();
	c->setID(1);
	c->setName("Bonny");
	c->setAccountBalance(250000);
	c->setState("CA");
	c->setZipCode(94556);
	list.push_back(c);

	c = new Customer();
	c->setID(2);
	c->setName("clyde");
	c->setState("CA");
	c->setZipCode(94556);
	c->setAccountBalance(1300);
	list.push_back(c);

	c = new Customer();
	c->setID(3);
	c->setName("junior");
	c->setState("WA");
	c->setZipCode(93211);
	c->setAccountBalance(26);
	list.push_back(c);

	c = new Customer();
	c->setID(4);
	c->setName("senior");
	c->setState("WY");
	c->setZipCode(24688);
	c->setAccountBalance(80000);
	list.push_back(c);

	cout << "Calling size(): " << list.size() << endl;
	list.print_list();
	cout << "Calling getCustomerCount(): " << list.getCustomerCount() << endl;
	cout << "Calling pop_front(): " << list.pop_front()->getName() << endl;
	cout << "Calling size(): " << list.size() << endl;
	list.print_list();
	cout << "Calling getCustomerCount(): " << list.getCustomerCount() << endl;
	cout << "Calling getTotalBalances(): " << list.getTotalBalances() << endl;

	cout << "Calling getSmallestBalance(): " << list.getSmallestBalance()->getID() << endl;
	cout << "Calling getLargestBalance(): " << list.getLargestBalance()->getID() << endl;



	cout << "Deleting list." << endl;
	list.delete_list();

	cout << "Checking customer count: " << list.getCustomerCount() << endl;
	cout << "Checking largest balance: " << list.getLargestBalance() << endl;
	cout << "Checking smallest balance: " << list.getSmallestBalance() << endl;
	cout << "Checking total balance: " << list.getTotalBalances() << endl;


	cout << "Program Ending." << endl; // prints !!!Hello World!!!
	return 0;
}
