
#include "listNode.h"

listNode::listNode(int key, char* firstName, char* lastName)
{
	
	key_value = key;
	fstName = firstName;
	lstName = lastName;
	next = nullptr;
	previous = nullptr;
}

listNode::listNode()
{
	key_value = -999;
	fstName = nullptr;
	lstName = nullptr;
	next = previous = nullptr;
}

listNode::~listNode()
{
	delete fstName;
	delete lstName;
	next = nullptr;
	previous = nullptr;
}