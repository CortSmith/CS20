/*
 * Heap.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: vessa
 */

#include <cstdlib>
#include "Heap.hpp"

Heap::Heap(void)
:heapType(0)
{

}



Heap::~Heap(void)
{

}



void Heap::push(int key, Planet* data)
{
	theHeap.push_back(HeapNode(key, data));
	this->upHeap();
}



Planet* Heap::top(void)
{
	return theHeap.front().data;
}



void Heap::pop(void)
{
	//Delete theHeap[0] (aka the zeroeth element) and replace it with the last element,
	// thereby moving the last element to the first position in the vector.
	//Then downHeap the first element until it meets the positional requirements.

	//Is theHeap empty?
	if (theHeap.size() == 0) return;
	//Is there only one element?
	if (theHeap.size() == 1)
	{
		theHeap.pop_back();
		return;
	}
	//Otherwise.
	//Pop last node.
	theHeap[0] = theHeap.back();  // decrease vector by one.
	theHeap.pop_back();

	//Downheap the new root node until satisfied.
	this->downHeap();
}



void Heap::setType(int type)
{
	if (theHeap.size() > 0)
		throw "Must be set before objects are added";
	heapType = type;
}



int Heap::size(void)
{
	return theHeap.size() - 1;
}



int calculate_parent(int n)
{
	return (n - 1) / 2;
}

void Heap::upHeap(void)
{
	if (theHeap.size() <= 1)
		return;
	else
	{
		HeapNode tmp = theHeap.back();

		unsigned int current_index = this->size();

		if (heapType == 0)
		{
			// Run through the vector n times.
			for (unsigned int i = 0; i < ceil(log2(theHeap.size())); i++)
			{
				// Check if the last node belongs in its current position.
				if (tmp.data->first < theHeap[calculate_parent(current_index)].data->first)
				{
					// Swap the parent with its child (the node that was pushed).
					//	Set the last node to its parent.
					theHeap[theHeap.size() - 1] = theHeap[calculate_parent(current_index)];
					//	Set the last nodes parent to tmp (e.g. the original last node).
					theHeap[calculate_parent(current_index)] = tmp;

					current_index = calculate_parent(current_index);
				}
				else return;
			}
		}
		else
		{
			// Run through the vector n times.
			for (unsigned int i = 0; i < ceil(log2(theHeap.size())); i++)
			{
				unsigned int parent_index = calculate_parent(current_index);
				std::cout << "loopcount: " << i << ", curindex: " << current_index << ", parent_index: " << parent_index
						<< ", tmp.data->first: " << tmp.data->first << ", pindex->data: " << theHeap[parent_index].data->first << std::endl;
				this->print();

				// Check if the last node belongs in its current position.
				if (tmp.data->first > theHeap[parent_index].data->first)
				{
					// Swap the parent with its child (the node that was pushed).
					//	Set the last node to its parent.
					theHeap[current_index] = theHeap[parent_index];
					//	Set the last nodes parent to tmp (e.g. the original last node).
					theHeap[parent_index] = tmp;

					current_index = parent_index;
				}
				else return;
			}
		}
	}
}



int calculate_smallest_child(std::vector<HeapNode>& theHeap, int x)
{
	//Calculate left and right indices.
	unsigned int left = 2 * x + 1;
	unsigned int right = 2 * x + 2;

	if (left > theHeap.size() - 1)
	{
		return theHeap.size() - 1;
	}

	//Return smallest.
	return theHeap[left].data->first < theHeap[right].data->first ? left: right;
}

int calculate_largest_child(std::vector<HeapNode>& theHeap, int x)
{
	//Calculate left and right indices.
	unsigned int left = 2 * x + 1;
	unsigned int right = 2 * x + 2;

	if (left > theHeap.size() - 1)
	{
		return theHeap.size() - 1;
	}

	//Return smallest.
	return theHeap[left].data->first > theHeap[right].data->first ? left: right;
}

void Heap::downHeap(void)
{
	// Start with the head.
	// Move it down.
	// Always swap with the largest of the two children.

	HeapNode tmp = theHeap.front();
	unsigned int current_index = 0;

	// Min heap.
	if (heapType == 0) {
		// Loop through
		for (unsigned int i = 0; i < ceil(log2(theHeap.size())); i++)
		{
			unsigned int largest_child = calculate_largest_child(theHeap, current_index);

			if (tmp.data->first > theHeap[largest_child].data->first)
			{
				theHeap[current_index] = theHeap[largest_child];
				theHeap[largest_child] = tmp;
				current_index = largest_child;
			}
			else return;
		}
	}
	else // Max heap.
	{
		for (unsigned int i = 0; i < ceil(log2(theHeap.size())); i++)
		{
			unsigned int smallest_child = calculate_smallest_child(theHeap, current_index);

			if (tmp.data->first < theHeap[smallest_child].data->first)
			{
				theHeap[current_index] = theHeap[smallest_child];
				theHeap[smallest_child] = tmp;
				current_index = smallest_child;
			}
			else return;
		}
	}
}

void Heap::print()
{
	std::cout << std::endl << "Printing all: planet(first) | index | parent " << std::endl;
	int size = theHeap.size();
	for (int i=0; i < size; i++)
	{
		std::cout << theHeap[i].data->Name << "(" << theHeap[i].data->first << ")" << " | " << i << " | " << calculate_parent(i) << std::endl;
	}
	std::cout << std::endl;
}


