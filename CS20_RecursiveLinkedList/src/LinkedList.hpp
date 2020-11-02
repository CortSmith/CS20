//
//  LinkedList.hpp
//  LinkedListCustomers
//
//  Created by William Komanetsky on 8/29/18.
//  Copyright © 2018 William Komanetsky. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
#include "Customer.hpp"

struct node {
    Customer* data;
    node* next;
    inline node(Customer* a=nullptr):data(a), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList();
    virtual ~LinkedList();
    
    /* Performs a backward recursive count of each node
     * Postcondition: Returns the number of nodes in the list.
     */
    int size();

    /* Insert a node at the back of the list.
     */
    void push_back(Customer*);

    /* Insert a node at the front of the list.
     * Postcondition: Head points to the new node.
     */
    void push_front(Customer*);

    /* Remove the first node and return its data.
     * Postcondition: Returns nullptr if list is empty. Otherwise returns data.
     * Notes: Check for nullptr value prior to use.
     */
    Customer* pop_front();

    /* Remove the last node and return its data.
     * Postcondition: Returns nullptr if list is empty. Otherwise returns data.
     * Notes: Check for nullptr value prior to use.
     */
    Customer* pop_back();

    /* Find customer with target ID.
     * @param int: is a id that is unique to the customer.
     * Precondition: int must be within range (0, 999999).
     * Postcondition: Returns nullptr if not found.
     * Notes: Check for nullptr value prior to use.
     */
    Customer* find(int);

    /* Does object exist with ID.
     * @param int: is a id that is unique to the customer.
     * Precondition: int is greater than 0, less than 999999.
     */
    bool exists(int);

    /* Delete node with target ID.
     * Precondition: int must be greater than zero, and less than 999999.
     * Postcondition: Removes node in the list with that ID.
     * 				  Returns false if no node has ID.
     */
    bool deleteIt(int);

    /* Recursively deletes the entire list.
     * Postcondition: List is empty.
     */
    void delete_list();

    /* Recursively prints the entire lists name data in reverse.
     */
    void print_list();

	int getCustomerCount(void);
	Customer* getLargestBalance(void);
	Customer* getSmallestBalance(void);
	double getTotalBalances(void);

private:
    node* head;

    void recursiveHelper_print(node*);
    void recursiveHelper_size(node*, int&);
    void recursiveHelper_delete_list(node*);
    void recursiveHelper_push_back(node*, Customer*);
    Customer* recursiveHelper_find(node*, Customer*&, int);
    bool recursiveHelper_deleteIt(node*, int);
    bool recursiveHelper_exists(node*, int);
    Customer* recursiveHelper_pop_back(node*);

	int recursiveHelper_customerCount(node*);
	Customer* recursiveHelper_largestBalance(node*, Customer*);
	Customer* recursiveHelper_smallestBalance(node*, Customer*);
	double recursiveHelper_totalBalances(node*);

};

#endif /* LinkedList_hpp */
