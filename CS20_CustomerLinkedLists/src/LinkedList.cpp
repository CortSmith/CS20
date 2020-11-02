/*
 * linkedlist.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: cort
 */

#include "LinkedList.hpp"


//template<typename T>
LinkedList::LinkedList(): head(nullptr) { }


//template<typename T>
LinkedList::~LinkedList() {
	delete_list();
    delete head;
}


//template<typename T>
bool LinkedList::isEmpty() const {
    if (head == nullptr)
        return true;
    return false;
}


//template<typename T>
bool LinkedList::isFull() const {
    Node* temp = head;
    int count = 0;
    while (temp != nullptr) {
    	count++;
        temp = temp->next;
    }
    if (count >= this->MAX_LIST_SIZE)
    	return true;
    temp = nullptr;
    return false;
}


//template<typename T>
int LinkedList::size() const {
    Node* temp = head;
    int count = 0;

    if (temp == nullptr) return 0;
    if (temp->next == nullptr) return 1;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}


//template<typename T>
int LinkedList::maxListSize() const {
    return MAX_LIST_SIZE;
}


bool LinkedList::exists(int id) const {
	Node* temp;
	temp = head;
	while (temp != nullptr) {
		if (temp->data->getId() == id) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}


//template<typename T>
bool LinkedList::print_list() const {
    Node* temp = head;
    if (temp == nullptr)
    	return false;

    while (temp != nullptr) {
    	std::cout << temp->data << std::endl;
        temp = temp->next;
    }
    temp = nullptr;
    return true;
}


//template<typename T>
Customer* LinkedList::find(int id) const {
	Node* temp;
	temp = head;
	while (temp != nullptr) {
		if (id == temp->data->getId()) {
			return temp->data;
		}
		temp = temp->next;
	}
	temp = nullptr;
	return nullptr;
}

//template<typename T>
void LinkedList::push_back(Customer* cust) {
	if (this->isFull()) {
		std::cerr << "List is full; Please remove an entry to insert." << std::endl;
		return;
	}

	Node* newNode = new Node(cust);
	Node* temp = head;

	//Case: Empty List
	if (temp == nullptr) {
		head = newNode;
		return;
	}

	// Iterate through list until you reach the last node.
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = newNode;

	newNode = nullptr;
	temp = nullptr;
}


void LinkedList::push_front(Customer* cust) {
	// Create new pointer for customer data.
	Node* newNode = new Node(cust);
	// Link the list to newNode->next
	newNode->next = head;
	// Set head to newNode
	head = newNode;
}


Customer* LinkedList::pop_back() {
	Node* temp = head;
	Node* temp2 = nullptr;
	Customer* data = nullptr;


	//Empty case
	if (temp == nullptr) { return nullptr; }
	if (DEBUG) std::cout << "LinkedList.cpp: pop_back: Line 151: Empty case" << std::endl;


	//Single case
	if (temp->next == nullptr) {
		data = new Customer(*temp->data);
		delete temp;
		return data;
	} if (DEBUG) std::cout << "LinkedList.cpp: pop_back: Line 156: Single case" << std::endl;


	while (temp->next->next != nullptr) {
		if (DEBUG) std::cout << "LinkedList.cpp: pop_back: Line 164: While loop: " << temp->next->data->getId() << std::endl;
		temp = temp->next;
	} if (DEBUG) std::cout << "LinkedList.cpp: pop_back: Line 163: While loop: Finished." << std::endl;


	temp2 = temp->next;
	if (DEBUG) std::cout << "LinkedList.cpp: pop_back: Line 170: temp2 set to temp->next" << std::endl;

	temp->next = nullptr;
	if (DEBUG) std::cout << "LinkedList.cpp: pop_back: Line 172: temp->next set to nullptr" << std::endl;

	data = new Customer(*temp2->data);
	if (DEBUG) std::cout << "LinkedList.cpp: pop_back: Line 175: Perform deep copy between data and temp2->data" << std::endl;

	delete temp2;
	if (DEBUG) std::cout << "LinkedList.cpp: pop_back: Line 178: delete temp2" << std::endl;

	return data;
	if (DEBUG) std::cout << "LinkedList.cpp: pop_back: Line 181: return data" << std::endl;
}

bool LinkedList::deleteit(int id) {
	Node* temp = head;
	Node* temp2 = nullptr;
	if (temp->data->getId() == id) {
		head = head->next;
		delete temp;
		return true;
	}
	//Its either going to reach the end, or reach the target.
	while (temp->next->next != nullptr && temp->next->data->getId() != id) {
		temp = temp->next;
	}
	//Ensure we have the correct node.
	if (temp->next->data->getId() == id) {
		temp2 = temp->next;
		temp->next = temp2->next;
		delete temp2;
		return true;
	}
	return false;
}

//template<typename T>
Customer* LinkedList::retrieveAt(int n) const {
	int size = this->size();

	if (n > -1 && n < size) {
		Node* temp;
		temp = head;
		for (int i=0; i<n;i++) {
			temp = temp->next;
		}
		return temp->data;
	}
	else {
		std::cerr << "Target (n) is out of bounds." << std::endl;
		return nullptr;
	}
}


//template<typename T>
void LinkedList::delete_list() {
	if (this->isEmpty()) {
		std::cout << "List is empty" << std::endl;
		return;
	}
	else {
		Node* temp;
		while (head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
}



