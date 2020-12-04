/*
 * BinaryTree.hpp
 *
 *  Created on: Oct 23, 2017
 *      Author: bkomanet
 */

#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_

#include "TreeNode.hpp"

class BinaryTree {
public:
	BinaryTree();
	virtual ~BinaryTree();

    bool insert(int);
    void displayInOrder(void);
    void displayPostOrder(void);
    void displayPreOrder(void);
    int size(void);
    void destroyTree(void);
    bool remove(int);
    int height(void);
    int getBalanceFactor(int);
    int largestBF(void);
    bool isInBalance(void);
    bool searchNode(int);

private:
    TreeNode *rootNode = nullptr;

    bool insertNode(TreeNode* &, TreeNode*);
    void printNodesInOrder(TreeNode*);
    void printNodesPostOrder(TreeNode*);
    void printNodesPreOrder(TreeNode*);
    int treeSize(TreeNode*);
    void destroySubTree(TreeNode* &);
    bool isLeaf(TreeNode* root);
    bool hasLeftChild(TreeNode*);
    bool hasRightChild(TreeNode*);
    bool deleteNode(TreeNode* &, int);
    TreeNode* findNode(TreeNode*, int);

    //** Have students do these functions
    int calculateHeight(TreeNode*);
    int calculateBalance(TreeNode* );
    int getLargestBF(TreeNode*);

}; //BinaryTree

#endif /* BINARYTREE_HPP_ */
