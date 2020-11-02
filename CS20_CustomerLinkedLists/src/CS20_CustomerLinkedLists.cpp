//*****************
//Project Name: CS20_CustomerLinkedLists

//Project Description: A linked list implementation using customer data.

//Project Author: Smith, Cort

//Is this an extra credit Project:  No

//Date completed: 09/23/2020

//Operating system used: Windows

//IDE Used:  Eclipse
//*****************

#include <iostream>
#include "Customer.hpp"
#include "LinkedList.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
	LinkedList *myList = new LinkedList;

	int custIDSearch = 40;

	cout << "Size of the list is: " << myList->size() << endl;

	Customer* theCust = nullptr;

	for (int i=0; i<100; i+=10) {
		theCust = new Customer();
		theCust->setId(i);
		myList->push_back(theCust);
	}//for

	theCust = new Customer();
	theCust->setId(22);
	myList->push_front(theCust);

	cout << "Size of the list is: " << myList->size() << endl;

	myList->print_list();

	if (myList->exists(custIDSearch)) {
		cout << "Customer #" << custIDSearch << " exists" << endl;
	}//if
	else {
		cout << "Customer #" << custIDSearch << " does not exist" << endl;
	}//else

	if (myList->find(custIDSearch) != nullptr) {
		cout << "Customer #" << custIDSearch << " was found" << endl;
	}//if
	else {
		cout << "Customer #" << custIDSearch << " was not found" << endl;
	}//else

	if (myList->deleteit(90)) {
		cout << "Node 90 deleted OK" << endl;
	}//if
	else {
		cout << "Node 90 not deleted OK" << endl;
	}//else

	//cout << "Popping from the front of the list till empty" << endl;

	cout << "Popping from the back of the list till empty" << endl;

	int sizeOfList = myList->size();
	//cout << "Line 70: int sizeOfList = myList->size()" << endl;

	for (int i=0; i<sizeOfList; i++) {
		if (DEBUG) cout << "Line 73: for loop: myList->pop_back(): iteration: " << i << endl;
		//delete
		myList->pop_back();
	}//for

	if (DEBUG) cout << "Line 80: for loop: myList->delete_list()" << endl;
	myList->delete_list();

	cout << "Size of the list is: " << myList->size() << endl;
	cout << "Program ending, have a nice day" << endl;

	return 0;
}
