/*
 * Heap.hpp
 *
 *  Created on: Nov 28, 2020
 *      Author: vessa
 */

#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include "Planet.hpp"

struct HeapNode
{
	int key;
	Planet* data;

	HeapNode(int k=-999, Planet* p=nullptr) : key(k), data(p) { }
	~HeapNode() { }
};

class Heap
{
private:
	std::vector<HeapNode> theHeap;
	int heapType;

public:
	Heap(void);
	virtual ~Heap(void);

	void push(int key, Planet* planet);
	Planet* top(void);
	void pop(void);
	void setType(int type);
	int size(void);

	void print();

private:
	void upHeap(void);
	void downHeap(void);

};



#endif /* HEAP_HPP_ */
