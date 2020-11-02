/*
 * main.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: vessa
 */

#include <iostream>
#include <map>
using namespace std;

class Student {
public:
	Student() {}
	~Student() {}

	string name;
	string ID;
	string address;
	int phone;
	string email;
};



int main() {

	//maps
		//key:value ppair to specify data for each access point
	map<string, Student> myClass;
	Student student1;
	student1.ID = "W100";
	student1.name = "Shato";
	myClass.insert(make_pair("W100", student1));



	return 0;
}

