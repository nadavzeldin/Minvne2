#ifndef __BSTree_H
#define __BSTree_H

#pragma once
#include "ds.h"

class BSTree : public DS
{
public:
	BSTree() = default;
	~BSTree();
	virtual void printDS();
	virtual bool isEmpty();
	virtual void makeEmpty();
	virtual void insert(int k, string firstName, string lastName);
	virtual void insert(int k, string firstName, string lastName, Node *leaf);
	void printDS_key(int key);
private:
	Node* search(int key, Node* leaf);
	void makeEmptyFN(Node* leaf);
	void printTree(Node* node, int key=99999999);
	Node* search(int key);

};

#endif // __BSTree_H