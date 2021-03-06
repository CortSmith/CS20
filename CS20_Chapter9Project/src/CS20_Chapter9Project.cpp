//============================================================================
// Name        : CS20_Chapter9Project.cpp
// Author      : Cort Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Hash.hpp"
#include "Employee.hpp"

void loadEmployeesFromFile(string, Hash&);

int main() {

	// Hash table
	Hash table;

	loadEmployeesFromFile("Employees.txt", table);
	table.PrintCollisionCount();
	cout << "Find Emp01: " << table.Find("Emp01")->salary << endl;

	//table.PrintList();


	cout << "Program ending." << endl; // prints !!!Hello World!!!
	return 0;

}



void loadEmployeesFromFile(string filename, Hash& inTable)
{
	//File stream variable.
	ifstream file;
	file.open("Employees.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			Employee* t = new Employee;

			file >> t->id;
			file >> t->last_name;
			file >> t->first_name;
			file >> t->salary;

			inTable.Insert(t->id, t);
			t = nullptr;
		}
	}
	else
	{
		cout << "File not found in Project main directory!" << endl;
	}
	file.close();
}






