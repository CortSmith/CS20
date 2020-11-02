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
    Customer(void);
    virtual ~Customer(void);
    
    bool setID(int);
    bool setName(string);
    bool setAddress(string);
    bool setCity(string);
    bool setState(string);
    bool setZipCode(int);
    bool setAccountBalance(double);

    int getID(void);
    string getName(void);
    string getAddress(void);
    string getCity(void);
    string getState(void);
    int getZipCode(void);
    double getAccountBalance(void);

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
