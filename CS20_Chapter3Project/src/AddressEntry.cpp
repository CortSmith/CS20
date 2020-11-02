/*
 * AddressEntry.cpp
 *
 *  Created on: Sep 17, 2020
 *      Author: vessa
 */

#ifndef ADDRESSENTRY_CPP_
#define ADDRESSENTRY_CPP_

#include "AddressEntry.hpp"

AddressEntry::~AddressEntry()
{
	delete next;
}

std::string AddressEntry::getName()
{
	return this->fullName;
}

int AddressEntry::getPhoneNumber()
{
	return this->phoneNumber;
}

std::string AddressEntry::getAddress()
{
	return this->address;
}

Date AddressEntry::getDateOfBirth()
{
	return this->dateOfBirth;
}

std::string AddressEntry::getDateString()
{
	return std::to_string(this->dateOfBirth.getMonth()) + "/" + std::to_string(this->dateOfBirth.getDay()) + "/" + std::to_string(this->dateOfBirth.getYear());
}

void AddressEntry::setFullName(std::string new_name)
{
	this->fullName = new_name;
}

void AddressEntry::setPhoneNumber(int new_number)
{
	this->phoneNumber = new_number;
}

void AddressEntry::setAddress(std::string new_address)
{
	this->address = new_address;
}

void AddressEntry::setDateOfBirth(int new_month, int new_day, int new_year)
{
	this->dateOfBirth.setMonth(new_month);
	this->dateOfBirth.setDay(new_day);
	this->dateOfBirth.setYear(new_year);
}



#endif /* ADDRESSENTRY_CPP_ */
