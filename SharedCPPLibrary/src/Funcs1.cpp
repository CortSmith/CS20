/*
 * Funcs1.cpp
 *
 *  Created on: Oct 12, 2020
 *      Author: vessa
 */

#include "Funcs1.hpp"
#include <climits>


void clearCIN(void) {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

//
int inputInt(void) {
	int userInput = 0;
	cout << "Please enter an integer: ";
	cin >> userInput;
	clearCIN();
	return userInput;
}

//
string inputString(void) {
	string userInput;
	cout << "Please enter a stirng: ";
	getline(cin, userInput);
	return userInput;
}


