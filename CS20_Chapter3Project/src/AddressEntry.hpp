/*
 * AddressEntry.hpp
 *
 *  Created on: Sep 17, 2020
 *      Author: vessa
 */

#ifndef ADDRESSENTRY_HPP_
#define ADDRESSENTRY_HPP_

#include <string>
#include "date.hpp"

class AddressEntry
{
	std::string fullName;
	int phoneNumber;
	std::string address;
	Date dateOfBirth;

public:
	AddressEntry* next = nullptr;
	AddressEntry* prev = nullptr;

	~AddressEntry();

public:
	std::string getName();
	int getPhoneNumber();
	std::string getAddress();
	Date getDateOfBirth();
	std::string getDateString();
	void setFullName(std::string newName);
	void setPhoneNumber(int number);
	void setAddress(std::string address);
	void setDateOfBirth(int month, int day, int year);
};
#endif /* ADDRESSENTRY_HPP_ */
