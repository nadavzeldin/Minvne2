
#include "node.h"

node::node(int key, char* firstName, char* lastName)
{
	key_value = key;
	fstName = firstName;
	lstName = lastName;
}

node::~node()
{
	delete fstName;
	delete lstName;
}