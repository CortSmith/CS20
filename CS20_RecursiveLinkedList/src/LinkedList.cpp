/*
 * LinkedList.cpp
 *
 *  Created on: Oct 11, 2020
 *      Author: vessa
 */

#include "LinkedList.hpp"


LinkedList::LinkedList()
: head(nullptr) {

}

LinkedList::~LinkedList() {
	delete_list();
}

void LinkedList::recursiveHelper_size(node* T, int& i) {
	if (T == nullptr) return;
	recursiveHelper_size(T->next, i);
	i++;
}

int LinkedList::size(){
	//Empty list?
	if (head == nullptr) return 0;

	//Counter.
	int i = 0;

	//Begin recursion.
	recursiveHelper_size(head, i);

	//Return count.
	return i;
}

void LinkedList::recursiveHelper_push_back(node* T, Customer* a) {
	if (T->next == nullptr) {
		T->next = new node(a);
		return;
	}
	recursiveHelper_push_back(T->next, a);
}

void LinkedList::push_back(Customer* a) {

	if (head == nullptr) {
		head = new node(a);
		return;
	}

	recursiveHelper_push_back(head, a);

}

void LinkedList::push_front(Customer* a) {

	//Empty list?
	if (head == nullptr) {

		//Set head.
		head = new node(a);

	}//
	else {

		//Temp for list preservation.
		node* T;

		//Preserve list.
		T = head;

		//Set head.
		head = new node(a);

		//Reattach list.
		head->next = T;

		//Remove refs.
		T = nullptr;

	}//

}//

Customer* LinkedList::pop_front() {

	//Empty list?
	if (head == nullptr) {

		//Print.
		std::cout << "List is empty. Cannot delete front node." << std::endl;

		//Breakout.
		return nullptr;

	}//

	//One node?
	if (head->next == nullptr) {

		//Delete.
		delete (head);

	}//

	//Temp for deletion.
	node* T;

	//Temp for return data.
	Customer* C;

	//Preserve node.
	T = head;

	//Preserve data.
	C = head->data;

	//Remove refs.
	head->data = nullptr;

	//Set head.
	head = head->next;

	//Delete.
	delete (T);

	//Return data.
	return C;
}

Customer* LinkedList::recursiveHelper_pop_back(node* T) {

	// Last node?
	if (T->next->next == nullptr) {

		// Preserve data.
		Customer* tempData = T->next->data;

		// Preserve target of deletion.
		node* tempPtr = T->next;

		// Remove refs.
		tempPtr->data = nullptr;

		// Delete.
		delete tempPtr;

		// Re-initialize.
		T->next = nullptr;

		// Return data.
		return tempData;
	}

	// Recurse.
	recursiveHelper_pop_back(T);
}

Customer* LinkedList::pop_back() {

	// Empty list?
	if (head == nullptr) {
		return nullptr;
	}

	// Single node.
	if (head->next == nullptr) {
		Customer* temp = head->data;
		head->data = nullptr;
		delete head;
		return temp;
	}

	// Recurse.
	return recursiveHelper_pop_back(head);
}//

Customer* LinkedList::recursiveHelper_find(node* T, Customer*& C, int a) {

	if (T->data->getID() == a) {
		return T->data;
	}

	if (T->next == nullptr) {
		std::cout << "Target not found with ID: " << a << endl;
		return nullptr;
	}

	recursiveHelper_find(T->next, C, a);
}

Customer* LinkedList::find(int a) {

	if (a == 0) return head->data;

	Customer* C;
	return recursiveHelper_find(head, C, a);

}

bool LinkedList::recursiveHelper_exists(node* T, int a) {

	// Null value?
	if (T == nullptr) {
		return false;
	}

	// Target?
	if (T->data->getID() == a) {
		return true;
	}

	//Recurse.
	recursiveHelper_exists(T->next, a);
}

bool LinkedList::exists(int a) {

	//Recurse.
	return recursiveHelper_exists(head, a);

}

bool LinkedList::recursiveHelper_deleteIt(node* T, int a) {
	if (T->next == nullptr) return false;
	if (T->next->data->getID() == a) {
		node* temp = T->next;
		T->next = temp->next;
		delete (temp);
		return true;
	}

	recursiveHelper_deleteIt(T->next, a);
}

bool LinkedList::deleteIt(int a) {

	if (this->size() == 1) {
		if (head->data->getID() == a) {
			delete head;
			return true;
		}
		return false;
	}

	return recursiveHelper_deleteIt(head, a);
}

void LinkedList::recursiveHelper_delete_list(node* T) {
	if (T == nullptr) return;
	recursiveHelper_delete_list(T->next);
	delete(T);
}

void LinkedList::delete_list() {
	//Empty list?
	if (head == nullptr) {
		std::cout << "Cannot delete an empty list." << std::endl;
		return;
	}

	recursiveHelper_delete_list(head);

	head = nullptr;

	return;
}

void LinkedList::recursiveHelper_print(node* T) {
	//At end?
	if (T == nullptr) return;

	//Recurse.
	recursiveHelper_print(T->next);
	//Print.
	std::cout << T->data->getName() << std::endl;
}

void LinkedList::print_list() {
	//Empty list?
	if (head == nullptr) {
		std::cout << "Cannot print an empty list." << std::endl;
		return;
	}

	//Begin recursion.
	recursiveHelper_print(head);
}//


//Recursive Functions

int getCustomerCount(void) {

	return 0;
}
Customer* getLargestBalance(void) {

	return nullptr;
}
Customer* getSmallestBalance(void) {

	return nullptr;
}
double getTotalBalances(void) {

	return 0.0;
}


//Recursive helpers

int recursiveHelper_customerCount(node*) {

	return 0;
}

Customer* recursiveHelper_largestBalance(node*, Customer*) {

	return nullptr;
}

Customer* recursiveHelper_smallestBalance(node*, Customer*) {

	return nullptr;
}

double recursiveHelper_totalBalances(node*) {

	return 0.0;
}


