#ifndef __BINARYTREE_H
#define __BINARYTREE_H

#pragma once
#include "ds.h"

class binaryTree : public DS
{
public:
	~binaryTree();
	Node* search(int key);
	void insert(Node* insertLeaf, Node* leaf);
	virtual void printDS();
	void printTree(Node* node);
	virtual void insert(Node* data);
	virtual bool isEmpty();
	virtual void makeEmpty();

private:
	Node* search(int key, Node* leaf);
	void makeEmptyFN(Node* leaf);

};

#endif // __BINARYTREE_H