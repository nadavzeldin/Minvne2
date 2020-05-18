
#include "node.h"

node::node(int key, char* firstName, char* lastName)
{
	key_value = key;
	fstName = firstName;
	lstName = lastName;
	this->left = nullptr;
	this->right = nullptr;
}

node::~node()
{
	delete fstName;
	delete lstName;
}