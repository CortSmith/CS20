/*
 * Hash.hpp
 *
 *  Created on: Nov 1, 2020
 *      Author: vessa
 */

#ifndef HASH_HPP_
#define HASH_HPP_

#define TABLE_SIZE 500
#define HASH_SIZE 50
#define DEBUG false

#include <string>
#include <iostream>
#include <sstream>
#include "Employee.hpp"


class Hash
{
	// Hash Table
	Employee** table[TABLE_SIZE]{ nullptr };
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
	bool Insert(std::string key, Employee* object);

	/* Return address object using the key.
	 * Pre-condition: @key is a string
	 * Post-condition: Returns address of object if found.
	 * 				   Returns nullptr if not found.
	 */
	Employee* Find(std::string key, Employee* object=nullptr);

	/* Return number of collisions.
	 * Pre-condition: @obj matches the declared type and not null.
	 * Post-condition: Returns -1 if table[index] is null.
	 * 				   Returns 0 if table[index] has only 1 entry.
	 * 				   Returns {number of collsions minus 1} if more
	 * 				   	than one object is in table[index].
	 */
	int CollisionCount(void);
	int* CollisionCountHelper(void);

	/* Prints the number of collisions for every table[index].
	 */
	void PrintCollisionCount(void);
	void PrintList(void);
};



#endif /* HASH_HPP_ */
