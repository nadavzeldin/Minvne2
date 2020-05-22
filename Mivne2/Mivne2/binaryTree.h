#ifndef __BINARYTREE_H
#define __BINARYTREE_H

#pragma once
#include "ds.h"

class binaryTree : public DS
{
public:
	binaryTree();
	~binaryTree();
	virtual void printDS();
	virtual bool isEmpty();
	virtual void makeEmpty();
	virtual void insert(int k, char* firstName, char* lastName);
	virtual void insert(int k, char* firstName, char* lastName, Node * leaf);
	

	//virtual void insert(Node* data);
	//void insert(Node* insertLeaf, Node* leaf);

private:
	Node* search(int key, Node* leaf);
	void makeEmptyFN(Node* leaf);
	Node* root;
	void printTree(Node* node);
	Node* search(int key);

};

#endif // __BINARYTREE_H
//
//virtual void printDS();
//virtual bool isEmpty();
//virtual void makeEmpty();
//virtual void insert(int k, char* firstName, char* lastName);