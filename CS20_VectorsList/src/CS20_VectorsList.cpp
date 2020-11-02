//============================================================================
// Name        : CS20_VectorsList.cpp
// Author      : Cort Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
	cout << "Program Start" << endl; // prints !!!Hello World!!!

	vector<int> myFirstVector;
	for (int i=0; i<10; i++) {
		myFirstVector.push_back(i);
	}

	vector<int> mySecondVector(myFirstVector);
	for (int i=0; i<10; i++) {
		cout << mySecondVector[i] << endl;
	}

	vector<int> myThirdVector(10);
	for (int i=0; i<10; i++) {
		cout << myThirdVector[i] << endl;
	}

	cout << endl;

	myThirdVector.resize(25,888);


	// Init new iterator for a vector of ints
	vector<int>::iterator myThirdIterator;

	//Assign this iterator to this vector of ints.
	myThirdIterator = myThirdVector.begin();

	for (myThirdIterator = myThirdVector.begin();
			myThirdIterator != myThirdVector.end();
			myThirdIterator++) {
		cout << *myThirdIterator << endl;
	}



	if (!myThirdVector.empty())
		myThirdVector.at(1);

	if (!myThirdVector.empty())
		myThirdVector[1];

	if (!myThirdVector.empty())
		myThirdVector.front();

	if (!myThirdVector.empty())
		myThirdVector.back();

	cout << "Program End" << endl; // prints !!!Hello World!!!
	return 0;
}
