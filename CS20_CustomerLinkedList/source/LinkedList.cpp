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
    //Iterate through list counting every node not equal to null.
    //create temp pointer.
    //create temp counter.
    //while(temp != nullptr)
    //count++
    //temp = temp->next
    //set class member counter
    //return temp counter

    Node* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    temp = nullptr;
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
	//create temp pointer
	//temp = head
	//while (temp != nullptr)
	//check: is temp->data == string
	//yes? return temp
	//no? temp = temp->next

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
void LinkedList::push_back(Customer* newdata) {
	//check: is list full?
	//create a new node
	//set data
	//create temp pointer
	//while (temp->next != nullptr) //need to check the following pointer, for when temp->next is null, temp is the end
	//temp = temp->next
	//temp->next = newNode
	if (this->isFull()) {
		std::cerr << "List is full; Please remove an entry to insert." << std::endl;
	}
	Node* newNode = new Node();
	newNode->data = newdata;

	Node* temp;
	temp = head;

	//Case: Empty List
	if (temp == nullptr) {
		head = newNode;
		newNode = nullptr;
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
	// Preserve head.
	Node* temp = head;
	// Create new pointer for customer data.
	Node* newNode = new Node(cust);
	// Link the list to newNode->next
	newNode->next = temp;
	// Set head to newNode
	head = newNode;
	// Clean up
	temp = nullptr;
}


Customer* LinkedList::pop_back() {
	Node* temp = head;
	Node* temp2 = nullptr;
	Customer* data;

	//Empty case
	if (temp == nullptr)
		return nullptr;

	//Single case
	if (temp->next == nullptr) {
		data = temp->data;
		temp->data = nullptr;
		temp = nullptr;
		delete head;
		return data;
	}

	//Case for everything else
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}

	// Preserve node for deletion.
	temp2 = temp->next;
	//Remove node from list.
	temp->next = temp2->next;
	// Preserve the data.
	data = temp2->data;
	// Remove the data address from the node.
	temp2->data = nullptr;
	// Delete the node.
	delete temp2;
	// Return the data.
	return data;
}

bool LinkedList::deleteit(int id) {
	/*
	Create a temp ptr.
	Set temp = head
	Check: Head case. Head->data->getId() == id
		yes? temp = head;
			 head = head->next;
			 delete temp;
		 // While we havent reached the second to last node.
	while (temp->next->next != nullptr
		   &&
		 // While we haven't found the Customer with the target id.
		   temp->next->data->getId() != id)
		temp = temp->next;
	Create temp2 ptr
	set temp2 = temp->next;
	set temp->next = temp2->next;
	delete temp2
	 */

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
	//check: is n within list?
	//yes? continue
	//no? report error
	//create temp pointer
	//set temp to head of list
	//for (i=0; i<n; i++)
	//	temp = temp->next;
	//return temp

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
	//check: is list empty?
	//yes? return
	//no? continue
	//create temp pointer
	//while (head != nullptr)
	//temp = head
	//head = head->next;
	//delete temp;

	if (this->isEmpty()) {
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



