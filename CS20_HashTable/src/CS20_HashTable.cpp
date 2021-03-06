//============================================================================
// Name        : CS20_HashTable.cpp
// Author      : Cort Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

struct student
{
	int ID;
	string Name;
	float GPA;
	~student() { delete this; }
};

const int HASHSIZE = 10;

int calcHash(int key);
int calcStringHash(string key);



int main() {

	student* T = nullptr;
	list<student*>* hashTable[HASHSIZE];

	cout << "Hash generated from Samantha: " << calcStringHash("Samantha") << endl;

	//Allocate memory of lists.
	for (int i=0; i<HASHSIZE; i++)
	{
		hashTable[i] = new list<student*>;
	}

	//Insert objects into list.
	for (int i=0; i<2000; i++)
	{
		T = new student;
		T->ID = rand();
		hashTable[calcHash(T->ID)]->push_back(T);
	}

	//Print list collisions.
	for (int i=0; i<HASHSIZE; i++)
	{
		int collisionCount = 0;
		if (hashTable[i]->size() == 0)
		{
			collisionCount = -1;
		}
		else
		{
			collisionCount = hashTable[i]->size()-1;
		}
		cout << "Collision Count for " << i << " is: " << collisionCount << endl;
	}

/*
	//Clear out memory in lists.
	for (int i=0; i<HASHSIZE; i++)
	{
		int listSize = hashTable[i]->size()-1;
		//Delete each student in the list.
		for (int j=0; j<listSize; i++)
		{
			//student* T = hashTable[i]->front();
			//delete T;
			hashTable[i]->pop_front();
		}
		//Delete the table.
		delete hashTable[i];
	}
*/





	cout << "Program Ending!" << endl; // prints !!!Hello World!!!
	return 0;
}



int calcStringHash(string key)
{
	int keySum = 0;
	for (int i=0; i<key.size(); i++)
	{
		keySum += static_cast<int>(key[i]);
	}

	//Division Hash method.
	return keySum % HASHSIZE;
}


int calcHash(int key)
{
	//Division Hash method.
	return key % HASHSIZE;
}




