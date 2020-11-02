/*
 * Customer.cpp
 *
 *  Created on: Sep 23, 2020
 *      Author: cort
 */

#include "Customer.hpp"

float Customer::getAccountBalance() const {
	return AccountBalance;
}

void Customer::setAccountBalance(float accountBalance) {
	AccountBalance = accountBalance;
}

const std::string& Customer::getAddress() const {
	return Address;
}

bool Customer::setAddress(const std::string &address) {
	if (address == "") return false;
//	assert(address != "");
	Address = address;
	return true;
}

const std::string& Customer::getCity() const {
	return City;
}

bool Customer::setCity(const std::string &city) {
	if (city == "") return false;
//	assert(city != "");
	City = city;
	return true;
}

int Customer::getId() const {
	return ID;
}

bool Customer::setId(int id) {
	if (id < 1 || id > 999999) return false;
//	assert(id > 1);
//	assert(id < 999999);
	ID = id;
	return true;
}

const std::string& Customer::getName() const {
	return Name;
}

bool Customer::setName(const std::string &name) {
	if (name == "") return false;
//	assert (name != "");
	Name = name;
	return true;
}

const std::string& Customer::getState() const {
	return State;
}

bool Customer::setState(const std::string &state) {
	if (state == "") return false;
//	assert (state != "");
	State = state;
	return true;
}

int Customer::getZipCode() const {
	return ZipCode;
}

bool Customer::setZipCode(int zipCode) {
	if (zipCode < 10000 || zipCode >= 99999) return false;
//	assert(zipCode >= 10000);
//	assert(zipCode <= 99999);
	ZipCode = zipCode;
	return true;
}


