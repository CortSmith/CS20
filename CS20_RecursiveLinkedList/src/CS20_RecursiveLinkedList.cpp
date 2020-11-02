//============================================================================
// Name        : CS20_RecursiveLinkedList.cpp
// Author      : Cort Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Customer.hpp"
#include "LinkedList.hpp"

int main() {

	LinkedList list;

	cout << "Print the list size(): " << list.size() << endl;

	cout << "Calling Print_List(): ";
	list.print_list();

	Customer* a;


	//Create new customer.
	a = new Customer;
	a->setID(1);
	a->setName("bonny");
	cout << "Calling push_back(): " << a->getName() << endl;
	list.push_back(a);
	//Clear refs.
	a = nullptr;
	cout << "Calling list_size(): " << list.size() << endl;


	//Create new customer.
	a = new Customer;
	a->setID(2);
	a->setName("clyde");
	cout << "Calling push_back(): " << a->getName() << endl;
	list.push_back(a);
	//Clear refs.
	a = nullptr;
	cout << "Calling list_size(): " << list.size() << endl;


	//Create new customer.
	a = new Customer;
	a->setID(3);
	a->setName("junior");
	cout << "Calling push_back(): " << a->getName() << endl;
	list.push_back(a);
	//Clear refs.
	a = nullptr;
	cout << "Calling list_size(): " << list.size() << endl;


	cout << "Customers in list" << endl << "-----------------" << endl;
	list.print_list();
	cout << "-----------------" << endl;


	cout << "Calling exists() on Bonny: " << list.exists(1) << endl;
	cout << "Calling exists() on junior: " << list.exists(3) << endl;


	cout << "Find bonny: " << list.find(1)->getName() << endl;
	cout << "Find clyde: " << list.find(2)->getName() << endl;
	cout << "Find junior: " << list.find(3)->getName() << endl;


	cout << "Deleteing clyde (1): " << list.deleteIt(2) << endl;
	cout << "Calling list_size(): " << list.size() << endl;
	if (list.find(2) != nullptr)
		cout << "Find clyde: " << list.find(2)->getName() << endl;
	else
		cout << "Find clyde: Not found." << endl;


	//Create new customer.
	a = new Customer;
	a->setID(4);
	a->setName("charly");
	cout << "Calling push_front(): " << a->getName() << endl;
	list.push_front(a);
	//Clear refs.
	a = nullptr;
	cout << "Calling list_size(): " << list.size() << endl;


	//Create new customer.
	a = new Customer;
	a->setID(5);
	a->setName("Mufasa");
	cout << "Calling push_front(): " << a->getName() << endl;
	list.push_front(a);
	//Clear refs.
	a = nullptr;
	cout << "Calling list_size(): " << list.size() << endl;


	cout << "Customers in list" << endl << "-----------------" << endl;
	list.print_list();
	cout << "-----------------" << endl;


	cout << "Find Mufasa: " << list.find(5)->getName() << endl;


	cout << "Calling pop_front(): " << list.pop_front()->getName() << endl;
	cout << "Calling list_size(): " << list.size() << endl;


	cout << "Customers in list" << endl << "-----------------" << endl;
	list.print_list();
	cout << "-----------------" << endl;


	cout << "Calling list_size(): " << list.size() << endl;


	cout << "Calling pop_back(): " << list.pop_back()->getName() << endl;


	cout << "Customers in list" << endl << "-----------------" << endl;
	list.print_list();
	cout << "-----------------" << endl;


	cout << "Calling list_size(): " << list.size() << endl;
	//cout << "Calling delete_list(): " << endl;
	//list.delete_list();

	cout << "Program Ending." << endl; // prints !!!Hello World!!!
	return 0;
}
