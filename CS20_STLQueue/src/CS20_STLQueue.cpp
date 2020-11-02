//============================================================================
// Name        : CS20_STLQueue.cpp
// Author      : Cort Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;


#include "Student.hpp"

struct Customer {
	int id;
	string name;
	double accountBalance;
};


int main() {

	Student* s1 = new Student();
	Student* s2 = new Student();

	if (s1 < s2){

	}

	queue<Customer*> mq;
	Customer* mc = new Customer;
	mc->name = "Mark";
	mc->accountBalance = 54233.99;
	mc->id = 1;
	mq.push(mc);

	mc = new Customer;
	mc->name = "Brittany";
	mc->accountBalance = -123.67;
	mc->id = 2;
	mq.push(mc);

	mc = new Customer;
	mc->name = "Nathan";
	mc->accountBalance = 0;
	mc->id = 3;
	mq.push(mc);


	if (*s1 < *s2) {
		cout << "Student 1's GPA is less than Student 2's" << endl;
	}
	else {
		cout << "Student 2's GPA is less than Student 1's" << endl;
	}


	for (unsigned int i=0; i<mq.size();) {
		mc = mq.front();
		mq.pop();
		cout << "Customer: " << mc->id << " retrieved and deleted" << endl;
		delete mc;
	}





	cout << "Program ending..." << endl; // prints !!!Hello World!!!
	return 0;
}
