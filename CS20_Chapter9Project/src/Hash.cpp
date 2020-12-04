/*
 * Hash.cpp
 *
 *  Created on: Nov 7, 2020
 *      Author: vessa
 */

#include "Hash.hpp"



Hash::Hash()
: //table( new Employee**[TABLE_SIZE]{ nullptr } ),
  table_counter( new int[TABLE_SIZE]{ -1 } )
{

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
 * 	multiplied exponentially by 1 factor per letter in the key.
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
bool Hash::Insert(std::string key, Employee* object)
{
	int index = AsciiSummation(key)%TABLE_SIZE;

	if (table[index] == nullptr)
	{
		//Allocate new array for key-index.
		table[index] = new Employee*[HASH_SIZE]{ nullptr };
		table[index][0] = object;
		if (DEBUG) std::cout << key << " has been inserted into index (" << index << ", " << 0 << ")" << std::endl;
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
				if (DEBUG) std::cout << key << " has been inserted into index (" << index << ", " << i << ")" << std::endl;
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
Employee* Hash::Find(std::string key, Employee* object)
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

		if (table[index][i]->id == key)
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
	int counter = 0;

	int* array = CollisionCountHelper();

	for (int i=0; i < TABLE_SIZE; i++)
	{
		if (array[i] == -1) continue;
		counter += array[i];
	}

	return counter;
}
int* Hash::CollisionCountHelper(void)
{
	// Reset counter back to empty (-1) before counting again
	for (int i=0; i < TABLE_SIZE; i++)
	{
		table_counter[i] = -1;
	}

	for (int i=0; i < TABLE_SIZE; i++)
	{
		if (table[i] == nullptr) continue;

		for (int k=0; k < HASH_SIZE; k++)
		{
			if (table[i][k] == nullptr) continue;

			table_counter[i]++;
		}
	}

	return table_counter;
}


/* Prints the number of collisions for every table[index].
 */
void Hash::PrintCollisionCount(void)
{
	int* array = CollisionCountHelper();

	for (int i=0; i < TABLE_SIZE; i++)
	{
		std::cout << "Collisions encountered at table[" << i << "]: " << array[i] << std::endl;
	}

	std::cout << "Empty table -1 | No collisions 0 | Collisions +1" << std::endl;
	std::cout << "Total collisions encountered: [" << this->CollisionCount() << "]" << std::endl;
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
			std::cout << table[i][j]->id << std::endl;
		}
	}
}


