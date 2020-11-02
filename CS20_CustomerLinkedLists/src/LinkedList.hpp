/*
 * linkedlist.hpp
 *
 *  Created on: Sep 22, 2020
 *      Author: cort
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#define DEBUG false

#include <string>
#include <iostream>
#include "Customer.hpp"

struct Node {
	Customer* data;
	Node* next;
	inline Node(Customer* inData=nullptr): data(inData), next(nullptr) { }
	inline ~Node() { delete data; delete next; }
};

//template<typename T>
class LinkedList {

    private:
    // List head.
    Node* head;
    // List max size.
    static const int MAX_LIST_SIZE = 500;

    public:
    LinkedList();
    ~LinkedList();

    /*
        Checks if list is empty.
        Post-condition: Returns true if the head points to null.
        Big-O: O(1)
        Done.
    */
    bool isEmpty() const;

    /*
        Checks if list is full.
        Post-condition: Returns true if the total number of objects
                        in the list reaches maximum allowed capacity.
        Big-O: O(n)
    */
    bool isFull() const;

    /*
        Returns the size of the list
        Post-condition: Returns the total number of objects in the list.
        Big-O: O(n)
    */
    int size() const;

    /*
        Returns the maximum size allowed in the list.
        Post-condition: Returns the maximum allowed capacity.
        Big-O: O(1)
    */
    int maxListSize() const;

    /*
        Returns true or false if the Customer id is found.
        Pre-condition: int must be within range (1,999999).
        Post-condition: Returns true if the Customer id is found in the list.
        Big-O: O(n)
    */
    bool exists(int) const;

    /*
        Prints the list to console.
        Post-condition: Returns false if list is empty.
        Big-O: O(n)
    */
    bool print_list() const;

    /*
        Searches through the list checking the name/id of each object.
        Pre-condition: int must be within range (1,999999)
        Post-condition: Returns the object, if found.
        Big-O: O(n)
    */
    Customer* find(int) const;

    /*
        Inserts a node at the end of the list.
        Pre-condition: Customer* must not be equal to nullptr.
        Post-condition: Object is located at the end of the list.
        Big-O: O(n)
    */
    void push_back(Customer*);

    /*
        Inserts a node at the end of the list.
        Pre-condition: Customer* must not be equal to nullptr.
        Post-condition: Object is located at the front of the list.
						Head points to this node.
        Big-O: O(n)
    */
    void push_front(Customer*);

    /*
        Iterates through the list (n - 1) times removing that node.
        Post-condition: Object is removed from the list and
                        deallocated from memory.
        Big-O: O(n)
    */
    Customer* pop_back();

    /*
        Iterates through the list (n - 1) times removing that node.
        Pre-condition: int must be within range (1,999999)
        Post-condition: Object is removed from the list and
                        deallocated from memory.
        Big-O: O(n)
    */
    bool deleteit(int);

    /*
        Iterates through the list n times returning that node.
        Pre-condition: int must be within range (1,999999)
        Post-condition: Returns the object, if found.
        Big-O: O(n)
    */
    Customer* retrieveAt(int) const;
    /*
		Iterates through the list n times returning that node.
		Post-condition: Returns the object, if found.
		Big-O: O(n)
	*/
    //T& retrieveAt(int) const;


    /*
        Removes and deallocates all nodes in the list.
        Post-condition: List head equals null.
        Big-O: O(n)
    */
    void delete_list();



};



#endif /* LINKEDLIST_HPP_ */
