#pragma once

#include "node.h"
class binaryTree
{
public:
	binaryTree();
	~binaryTree();

	void insert(node* insertLeaf, node* leaf);
	node* search(int key);
	bool IsEmpty();
	void MakeEmpty();

private:
	node* search(int key, node* leaf);
	void MakeEmpty(node* leaf);
	node* root;

};