//============================================================================
// Name        : CS20_ch3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node {
	node *next;
	string data;
};

void push_back(node* &theHead, string theData) {
	node* tempPtr = theHead;
	node* newNode = new node;
	newNode->data = theData;
	newNode->next = nullptr;
	if (tempPtr == nullptr) {
		theHead = newNode;
	}
	else {
		while (tempPtr->next != nullptr) {
			tempPtr = tempPtr->next;
		}
		tempPtr->next = newNode;
		tempPtr = nullptr;
	}
}

/* push_front(node* &theHead, string theData)
 * Description		insert a node at the beginning of the list.
 * Precondition		takes a head node pointer reference, and the data.
 * Post-condition	Inserts a node before the first node and sets head to the new node.
 */
void push_front(node* &theHead, string theData) {
	node* tempPtr = new node;
	tempPtr->data = theData;
	tempPtr->next = theHead->next;
	theHead = tempPtr;
}

void insert_after(node* &theHead, string theData) {

}

void print_list(const node* theHead)
{
	const node* tempPtr = theHead;
	if (tempPtr == nullptr) {
		cout << "The list is empty"<<endl;
	}
	else {
		while (tempPtr != nullptr) {
			cout << tempPtr->data << endl;
			tempPtr = tempPtr->next;
		}
	}
}

/*
 * clear_list (node* &theHead)
 *
 * Description	: Takes the pointer sent to it and delete all data.
 * Arguments	: theHead: A pointer to the first node in the list;
 */
void clear_list(node* &theHead)
{
	node* curPtr = theHead;
	node* nextPtr = nullptr;

	while (curPtr != nullptr) {
		nextPtr = curPtr->next;
		delete curPtr;
		curPtr = nextPtr;
	}

	curPtr = nullptr;
	nextPtr = nullptr;
	delete theHead;
}

int main() {

	node* head = nullptr;

	push_back(head, "Britney");
	push_back(head, "Nathan");
	push_back(head, "Yashaswi");

	print_list(head);

	clear_list(head);


	//clear_list(head);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
