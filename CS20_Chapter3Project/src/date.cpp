/*
 * date.cpp
 *
 *  Created on: Sep 17, 2020
 *      Author: vessa
 */

#include "date.hpp"

Date::Date() : day(0), month(0), year(0)
{

}

int Date::getMonth()
{
	return this->month;
}

int Date::getDay()
{
	return this->day;
}

int Date::getYear()
{
	return this->year;
}

bool Date::setMonth(int new_month)
{
	if (new_month < 1 || new_month > 12)
		return false;
	else
		this->month = new_month;
	return true;
}

bool Date::setDay(int new_day)
{
	if (new_day < 1 || new_day > 365)
		return false;
	else
		this->day = new_day;
	return true;
}

bool Date::setYear(int new_year)
{
	if (new_year < 1900 || new_year > 2020)
		return false;
	else
		this->year = new_year;
	return true;
}

std::string Date::getDateString()
{
	return std::to_string(this->month) + "/" + std::to_string(this->day) + "/" + std::to_string(this->year);
}


