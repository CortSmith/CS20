//
//  Customer.hpp
//  LinkedListCustomers
//
//  Created by William Komanetsky on 8/29/18.
//  Copyright © 2018 William Komanetsky. All rights reserved.
//

#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Customer {
public:
    inline Customer() {}
    virtual inline ~Customer() {}
    
    inline bool setID(int init) {
    	if (init <= 0 || init > 999999) return false;
    	this->ID = init; return true;
    }

    inline bool setName(string init)  {
    	if (init == "") return false;
    	this->Name = init; return true;
    }

    inline bool setAddress(string init)  {
    	if (init == "") return false;
    	this->Address = init; return true;
    }

    inline bool setCity(string init)  {
    	if (init == "") return false;
    	this->City = init; return true;
    }

    inline bool setState(string init)  {
    	if (init == "") return false;
    	this->State = init; return true;
    }

    inline bool setZipCode(int init)  {
    	if (init < 1000 || init > 99999) return false;
    	this->ZipCode = init; return true;
    }

    inline bool setAccountBalance(double init)  { this->AccountBalance = init; return true; }

    inline int getID(void) { return this->ID; }
    inline string getName(void) { return this->Name; }
    inline string getAddress(void) { return this->Address; }
    inline string getCity(void) { return this->City; }
    inline string getState(void) { return this->State; }
    inline int getZipCode(void) { return this->ZipCode; }
    inline double getAccountBalance(void) { return this->AccountBalance; }

private:
    int ID;
    string Name;
    string Address;
    string City;
    string State;
    int ZipCode;
    double AccountBalance;

};

#endif /* Customer_hpp */
