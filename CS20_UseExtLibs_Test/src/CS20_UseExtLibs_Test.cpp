//============================================================================
// Name        : CS20_UseExtLibs_Test.cpp
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
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	LinkedList* list = new LinkedList();

	Customer* customer = new Customer();
	customer->setID(1);
	customer->setName("tobin");
	list->push_back(customer);
	list->print_list();

	cout << "Program Ending." << endl; // prints !!!Hello World!!!
	return 0;
}
