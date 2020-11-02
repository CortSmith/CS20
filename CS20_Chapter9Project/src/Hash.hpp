/*
 * Hash.hpp
 *
 *  Created on: Nov 1, 2020
 *      Author: vessa
 */

#ifndef HASH_HPP_
#define HASH_HPP_

#include <string>
#include <iostream>
#include <sstream>

#include "Employee.hpp"

//Table size
#define TABLE_SIZE 500
//Hash size
#define HASH_SIZE 50
//Debug
#define DEBUG false

class Hash
{
	// Hash Table
	Employee*** table;
	//Table collision counter
	int* table_counter;

private:
	int AsciiSummation(std::string key);
	int AsciiExpSummation(std::string key, Employee* object);

public:
	Hash();
	~Hash();

	/* Insert object in hash table, and allocate array if table[index] is empty.
	 * Pre-condition: @key is a string.
	 * 				  @obj matches the declared type and not null.
	 * Post-condition: Table[index] has allocated array and atleast one object.
	 */
	bool Insert(string key, Employee* object);

	/* Return address object using the key.
	 * Pre-condition: @key is a string
	 * Post-condition: Returns address of object if found.
	 * 				   Returns nullptr if not found.
	 */
	Employee* Find(string key, Employee* object=nullptr);

	/* Return number of collisions.
	 * Pre-condition: @obj matches the declared type and not null.
	 * Post-condition: Returns -1 if table[index] is null.
	 * 				   Returns 0 if table[index] has only 1 entry.
	 * 				   Returns {number of collsions minus 1} if more
	 * 				   	than one object is in table[index].
	 */
	int CollisionCount(void);

	/* Prints the number of collisions for every table[index].
	 */
	void PrintCollisionCount(void);
	void PrintList(void);
};




Hash::Hash()
: //table( new Employee**[TABLE_SIZE]{ nullptr } ),
  table_counter( new int[TABLE_SIZE]{ -1 } )
{
	table = new Employee**[TABLE_SIZE];
	for (int i=0; i < TABLE_SIZE; i++)
	{
		table[i] = nullptr;
	}
}

Hash::~Hash()
{
	for (int i=0; i < TABLE_SIZE; i++)
		delete [] table[i];
}

int Hash::AsciiSummation(std::string key)
{
	int counter=0;

	for (unsigned int p=0; p < key.length()-1; p++)
	{
		counter += (int) key[p];
	}

	return counter;
}

/* Normal Ascii Summation method, except every char of the key is
 * 	multiplied exponentially by 1 factor per letter in the key, and
 * 	then the Employee id is added before modulus is considered.
 *
 * 	Number of collisions is mostly zero compared to regular summation.
 * 	Thought I'd have some fun exploring this a bit.
 */
int Hash::AsciiExpSummation(std::string key, Employee* object)
{
	int counter=0;

	for (unsigned int p=0; p < key.length(); p++)
	{
		counter += ((int) key[p])^(p+1);
	}
	return counter;
}

/* Insert object in hash table, and allocate array if table[index] is empty.
 * Pre-condition: @key must be a string.
 * 				  @obj matches the declared type and not null.
 * Post-condition: Table[index] has allocated array and atleast one object.
 */
bool Hash::Insert(string key, Employee* object)
{
	int index = AsciiSummation(key)%TABLE_SIZE;

	if (table[index] == nullptr)
	{
		//Allocate new array for key-index.
		table[index] = new Employee*[HASH_SIZE]{ nullptr };
		table[index][0] = object;
		std::cout << key << " has been inserted into index (" << index << ", " << 0 << ")" << std::endl;
		return true;
	}
	else
	{
		// Loop for Hash index.
		// Linear step-by-step approach for collision handling.
		for (int i=0; i < HASH_SIZE; i++)
		{
			if (table[index][i] == nullptr)
			{
				table[index][i] = object;
				std::cout << key << " has been inserted into index (" << index << ", " << i << ")" << std::endl;
				return true;
			}
		}
		return false;
	}
}

/* Return address object using the key.
 * Pre-condition: @key is a string
 * Post-condition: Returns address of object if found.
 * 				   Returns nullptr if not found.
 */
Employee* Hash::Find(string key, Employee* object)
{
	int index = AsciiSummation(key)%TABLE_SIZE;
	if (table[index] == nullptr)
	{
		return 0;
	}
	for (int i=0; i < HASH_SIZE; i++)
	{
		if (table[index][i] == nullptr)
		{
			continue;
		}
		if ((int) table[index][i]->id.data() == index)
		{
			return table[index][i];
		}
	}
	return 0;
}


/* Return number of collisions.
 * Pre-condition: @obj matches the declared type and not null.
 * Post-condition: Returns -1 if table[index] is null.
 * 				   Returns 0 if table[index] has only 1 entry.
 * 				   Returns {number of collsions minus 1} if more
 * 				   	than one object is in table[index].
 */
int Hash::CollisionCount(void)
{
	// Reset counter back to zero
	//  before counting again
	for (int i=0; i < TABLE_SIZE; i++)
	{
		table_counter[i] = -1;
	}
	int counter = 0;

	for (int i=0; i < TABLE_SIZE; i++)
	{
		if (table[i] == nullptr) continue;
		for (int k=0; k < HASH_SIZE; k++)
		{
			if (table[i][k] == nullptr) continue;
			table_counter[i]++;
		}
	}

	return counter;
}


/* Prints the number of collisions for every table[index].
 */
void Hash::PrintCollisionCount(void)
{
	for (int i=0; i < TABLE_SIZE; i++)
	{
		std::cout << "Collisions encountered at table[" << i << "]: " << table_counter[i] << std::endl;
	}
	std::cout << "Empty table -1 | No collisions 0 | Collisions +1" << std::endl;
	std::cout << "Total collisions encountered: [" << this->CollisionCount() << "]" << endl;
}


void Hash::PrintList(void)
{
	for (int i=0; i<TABLE_SIZE; i++)
	{
		if (table[i] == nullptr)
		{
			continue;
		}

		for (int j=0; j<HASH_SIZE; j++)
		{
			if (table[i][j] == nullptr)
			{
				continue;
			}
			cout << table[i][j]->first_name << endl;
		}
	}
}



#endif /* HASH_HPP_ */