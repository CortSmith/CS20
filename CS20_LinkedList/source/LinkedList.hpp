/*
 * LinkedList.hpp
 *
 *  Created on: Sep 21, 2020
 *      Author: vessa
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#ifndef INPUT_OUTPUT_STREAM
#define INPUT_OUTPUT_STREAM
#include <iostream>
#endif

enum ListOrder
{
	ordered,
	unordered
};

template<typename T, ListOrder order=unordered>
class LinkedList
{
public:
	struct Node
	{
		//Keeps track of all nodes created
		//	including those lost in memory.
		//WARNING: Do not rely on for tracking
		//	number of nodes in the list.
		static int count;

		T data;
		Node* next;
		inline Node() {next=nullptr; count++;}
		inline ~Node() {next=nullptr; count--;}
	};

private:
	Node* head;

public:

	void pop_front(T object);
	void pop_back(T object);
	void remove_at(int n, T object);
	bool insert(T &object);
	bool insert(T &object, int n);		//ordered
	bool insert_front(T object);
	bool insert_back(T object);
	bool is_full();
};




template <typename T, ListOrder order>
void LinkedList<T, order>::pop_front(T object)
{

}

template <typename T, ListOrder order>
void LinkedList<T, order>::pop_back(T object)
{

}

template <typename T, ListOrder order>
void LinkedList<T, order>::remove_at(int n, T object)
{

}

template <typename T, ListOrder order>
bool LinkedList<T, order>::insert(T &object, int n)
{
	//Insert first.
		/*
		 * curNode = head
		 * if (5 < 10)
		 * 		true? push_front(5)
		 */
	//Insert last
	/*
	 * curNode = head
	 * if (40 < 30)
	 * 		true? push_front(40)
	 * 		false? is next null?
	 * 			true? push_back(value)
	 */
	Node* newNode;

	//Notable Test Cases
	//Empty List
	//Full List
	return true;
}

template <typename T, ListOrder order>
bool LinkedList<T, order>::insert(T &object)
{
	//Insert first.
		/*
		 * curNode = head
		 * if (5 < 10)
		 * 		true? push_front(5)
		 */
	//Insert last
	/*
	 * curNode = head
	 * if (40 < 30)
	 * 		true? push_front(40)
	 * 		false? is next null?
	 * 			true? push_back(value)
	 */
	Node* newNode;

	//Notable Test Cases
	//Empty List
	//Full List
	return true;
}

template <typename T, ListOrder order>
bool LinkedList<T, order>::insert_front(T object)
{
	//Notable Test Cases
	//Empty List
	//Full List

	if (is_full())
	{
		std::cerr << "List is full" << std::endl;
		return false;
	}

	// Instantiate a new node.
	Node* newNode;
	newNode = new Node;
	newNode->data = object;

	// Set heads current pointer
	newNode->next = this->head;
	// Set head to the new pointer
	this->head = newNode;

	newNode = nullptr;
	return true;
}

template <typename T, ListOrder order>
bool LinkedList<T, order>::insert_back(T object)
{
	return false;
}

template <typename T, ListOrder order>
bool LinkedList<T, order>::is_full()
{
	return false;
}

#endif /* LINKEDLIST_HPP_ */
