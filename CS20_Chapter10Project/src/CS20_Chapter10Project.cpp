//============================================================================
// Name        : CS20_Chapter10Project.cpp
// Author      : Cort Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "utilities.hpp"
#include "Heap.hpp"
#include "Planet.hpp"
using namespace std;

#define numPlanets 9

int main()
{
	cout << "Creating theHeap" << endl;
	Heap theHeap;
	Planet* newPlanet;

	//Planet data values.
	string planet_names[numPlanets] {"Saturn",
									 "Earth",
									 "Mars",
									 "Venus",
									 "Pluto",
									 "Uranus",
									 "Neptune",
									 "Mercury",
									 "Jupiter"
	};

	string planet_urls[numPlanets] {"https://cdn.mos.cms.futurecdn.net/XFL6HquyTYfQH5L7ztttp3.jpg",
									"https://interactioninstitute.org/wp-content/uploads/2020/06/planet-earth-4427436_1280-720x463.jpg",
									"https://nypost.com/wp-content/uploads/sites/2/2018/07/shutterstock_508294351.jpg?quality=80&strip=all",
									"https://upload.wikimedia.org/wikipedia/commons/a/a9/PIA23791-Venus-NewlyProcessedView-20200608.jpg",
									"https://i.dailymail.co.uk/1s/2019/08/26/09/17696660-0-image-a-9_1566808842392.jpg",
									"https://www.astronomytrek.com/wp-content/uploads/2012/11/uranus-1.jpg",
									"https://cdn.mos.cms.futurecdn.net/eNTJrysq4A6DqXncBtsRrB-1200-80.jpg",
									"https://cdn.mos.cms.futurecdn.net/MTEiJvP99DScN3vkAsE9LA.jpg",
									"https://upload.wikimedia.org/wikipedia/commons/2/2b/Jupiter_and_its_shrunken_Great_Red_Spot.jpg"
	};

	int planet_firsts[numPlanets];

	theHeap.setType(1);

	cout << "Setting planet_firsts indices to random values." << endl;
	//Set the random integers.
	for (int i=0; i<numPlanets; i++)
		planet_firsts[i] = getRandomInt(0,1000);

	cout << "Instantiating new planet objects and pushing to theHeap" << endl;
	//Push planets to theHeap.
	for (int i=0; i<numPlanets; i++)
	{
		newPlanet = new Planet();
		newPlanet->Name = planet_names[i];
		newPlanet->URL = planet_urls[i];
		newPlanet->first = planet_firsts[i];
		cout << "inserting " << newPlanet->Name << std::endl;
		theHeap.push(newPlanet->first, newPlanet);
	}
	cout << "Post instantiation" << endl;

	theHeap.print();

	for (unsigned int i=0; i<numPlanets; i++) {
		newPlanet = theHeap.top();
		cout << newPlanet->first << endl;
		cout << newPlanet->Name << endl;
		cout << newPlanet->URL << endl;
		cout << "Size of vector: " << theHeap.size() << endl;
		theHeap.pop();
		delete newPlanet;
	}//for

	cout << "Program ending." << endl;
	return 0;
}


//int main() {
//
//    Heap theHeap;
//    Planet* newPlanet;
//
//    cout << "setType" << endl;
//    theHeap.setType(0);            //Min Heap
//    //theHeap.setType(1);                //Max Heap
//    cout << "post setType" << endl << endl;
//
//    cout << "beginning to fill vector with 1,000,000" << endl;
//    for (int i=0; i<1000000; i++) {
//        newPlanet = new Planet();
//        newPlanet->first = getRandomInt(0, 1000000000);
//        theHeap.push(newPlanet->first, newPlanet);
//    }//for
//    cout << "Finished filling vector." << endl << endl;
//
//    cout << "Beginning to print and remove vector elements." << endl;
//
//    unsigned int theSize = theHeap.size();
//
//    for (unsigned int i=0; i<theSize; i++) {
//        newPlanet = theHeap.top();
//        cout << newPlanet->first << endl;
//        theHeap.pop();
//        delete newPlanet;
//    }//for
//
//    cout << "Program ending, have a nice day" << endl;
//    return 0;
//}//main
