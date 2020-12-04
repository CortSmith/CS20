/*
 * CortSmith.cpp
 *
 *  Created on: Nov 18, 2020
 *      Author: vessa
 */

#include <iostream>
#include <iomanip>
#include "BinaryTree.hpp"
using namespace std;
//
//Private function which calculates the balance factor of a node and its branches/leafs.
//Called by isInBalance
int BinaryTree::calculateBalance(TreeNode* rootNode) {

	if (!rootNode)

		return 0;

	int a = 0,b = 0;

	if (rootNode->Left != nullptr)
	{
		a = calculateBalance(rootNode->Left) + 1;
	}
	if (rootNode->Right != nullptr)
	{
		b = calculateBalance(rootNode->Right) + 1;
	}

	rootNode->BalanceFactor = a - b;

	return max(a, b);

}//calculateBalance

//
//Private function returning the balance factor of a particular node.  Called by isInBalance
int BinaryTree::calculateHeight(TreeNode* rootNode) {

	if (!rootNode)

		return 0;

	int a = 0,b = 0;

	if (rootNode->Left != nullptr)
	{
		a = calculateHeight(rootNode->Left);
		++a;
	}

	if (rootNode->Right != nullptr)
	{
		b = calculateHeight(rootNode->Right);
		++b;
	}

	return max(a, b);

}//calculateHeight

//
//Private function which returns the largest balance factor in the entire tree.  Called by largestBF
int BinaryTree::getLargestBF(TreeNode* rootNode) {

	if (!rootNode)
		return 0;

	getLargestBF(rootNode->Left);

	getLargestBF(rootNode->Right);

	int a = calculateBalance(rootNode->Left);

	int b = calculateBalance(rootNode->Right);

	return abs(a) >= abs(b) ? a : b;

}//getLargestBF


