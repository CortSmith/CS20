/*
 * Customer.hpp
 *
 *  Created on: Sep 23, 2020
 *      Author: cort
 */

#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

#include <string>
#include <iostream>
#include <cassert>

class Customer {
	//Customer Identification.
	//Validation: Range(1-999999)
	int ID;

	//Customer Name.
	//Validation: Not empty.
	std::string Name;

	//Customer Address.
	//Validation: Not empty.
	std::string Address;

	//Customer City.
	//Validation: Not empty.
	std::string City;

	//Customer State.
	//Validation: Not empty.
	std::string State;

	//Customer Zip Code.
	//Validation: Not empty.
	int ZipCode;

	//Customer Account Balance.
	//Validation: No numeric validation
	float AccountBalance;

public:
	inline Customer(): ID(0), Name(""), Address(""), City(""), State(""), ZipCode(0),  AccountBalance(0) { }

	float getAccountBalance() const;
	void setAccountBalance(float accountBalance);

	const std::string& getAddress() const;
	bool setAddress(const std::string &address);

	const std::string& getCity() const;
	bool setCity(const std::string &city);

	int getId() const;
	bool setId(int id);

	const std::string& getName() const;
	bool setName(const std::string &name);

	const std::string& getState() const;
	bool setState(const std::string &state);

	int getZipCode() const;
	bool setZipCode(int zipCode);
};

#endif /* CUSTOMER_HPP_ */
