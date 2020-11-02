/*
 * date.hpp
 *
 *  Created on: Sep 17, 2020
 *      Author: vessa
 */

#ifndef DATE_HPP_
#define DATE_HPP_

#include <string>

class Date
{
	int month;
	int day;
	int year;

public:
	Date();

	int getMonth();
	int getDay();
	int getYear();

	bool setMonth(int new_month);
	bool setDay(int new_day);
	bool setYear(int new_year);

	std::string getDateString();
};


#endif /* DATE_HPP_ */
