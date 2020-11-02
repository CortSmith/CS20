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
#include "Customer.hpp"

struct node {
    Customer* data;
    node* next;
};

class LinkedList {
public:
    LinkedList(void);
    virtual ~LinkedList(void);
    
    int size(void);
    void push_back(Customer*);
    void push_front(Customer*);
    Customer* pop_front(void);
    Customer* pop_back(void);
    Customer* find(int);
    bool exists(int);
    bool deleteIt(int);
    void delete_list(void);
    void print_list(void);

    //Recursive helpers
    double getTotalBalances(void);
    unsigned int getCustomerCount(void);
    Customer* getLargestBalance(void);
    Customer* getSmallestBalance(void);

private:
    node* head;

    //Recursive functions
    unsigned int customerCount(node*);
    Customer* largestBalance(node*, Customer*);
    Customer* smallestBalance(node*, Customer*);
    double totalBalances(node*);
};

#endif /* LinkedList_hpp */
