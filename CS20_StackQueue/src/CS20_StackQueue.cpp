//============================================================================
// Name        : CS20_StackQueue.cpp
// Author      : Cort Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace std;

#include "Stack.hpp"
#include "Queue.hpp"

int main() {

	Stack* s = new Stack();
	Queue* q = new Queue();

	cout << endl << "*******************************************" << endl
		<<	"                    STACK                  " << endl
		<<	"*******************************************" << endl;

	Customer* d = new Customer();
	d->setID(1);
	d->setName("Charley");
	//s->push(d);

	d = new Customer();
	d->setID(2);
	d->setName("Steve");
	//s->push(d);

	d = new Customer();
	d->setID(3);
	d->setName("Danica");
	//s->push(d);

	d = new Customer();
	d->setID(4);
	d->setName("Peter");
	//s->push(d);

	/*
	 * There is a wierd bug in the way I used the random library, although
	 * 	I really think that nothing I did is wrong, the numbers printed in the
	 * 	second while loop are different than the ones I input in the id's of
	 * 	the customers.
	 */

	int i=0;
	while (!s->isFullStack()) {
		srand(i+1);
		int num = rand();
		//cout << rand() << endl;
		d = new Customer();
		d->setID(num);
		s->push(d);
		i++;
	}
	while (!s->isEmptyStack())
	{

		if (s->isFullStack())
			cout << "Stack is full." << endl;

		cout << s->top()->getID() << endl;
		s->pop();

		if (s->isEmptyStack())
			cout << "Stack is empty." << endl;
	}


	cout << endl << "*******************************************" << endl
		<<	"                    QUEUE                  " << endl
		<<	"*******************************************" << endl << endl;

	q->enqueue(d);


	d = new Customer();
	d->setID(1);
	d->setName("Rebecca");
	//q->enqueue(d);

	d = new Customer();
	d->setID(1);
	d->setName("Taylor");
	//q->enqueue(d);

	d = new Customer();
	d->setID(1);
	d->setName("Jerry");
	//q->enqueue(d);


	while (!q->isFullQueue()) {
		srand(i+1);
		int num = rand();
		//cout << rand() << endl;
		d = new Customer();
		d->setID(num);
		q->enqueue(d);
		i++;
	}
	while (!q->isEmptyQueue())
	{

		if (q->isFullQueue())
			cout << "Queue is full." << endl;

		cout << q->front()->getID() << endl;
		q->dequeue();

		if (q->isEmptyQueue())
			cout << "Queue is empty." << endl;
	}

	cout << "Printing Charley: " << q->front()->getName() << endl;
	q->dequeue();
	cout << "Printing Rebecca: " << q->front()->getName() << endl;
	q->dequeue();
	cout << "Printing Taylor: " << q->front()->getName() << endl;
	q->dequeue();
	cout << "Printing Jerry: " << q->front()->getName() << endl;
	q->dequeue();

	cout << "Program ending!" << endl; // prints !!!Hello World!!!
	return 0;
}
