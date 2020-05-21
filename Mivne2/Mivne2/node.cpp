#include "node.h"
#define _CRT_SECURE_NO_WARNINGS
 #pragma warning(disable : 4996)
Node::Node(int key, char* firstName, char* lastName)
{
	key_value = key;
	fstName = new char[strlen(firstName) + 1];
	strcpy(fstName, firstName);
	lstName = new char[strlen(lastName) + 1];
	strcpy(lstName, lastName);
	point[0] = nullptr, point[1] = nullptr;
}

Node::Node()
{
	key_value = -9999;
	fstName = nullptr, lstName = nullptr;
	point[0] = nullptr, point[1] = nullptr;
}

void Node::printNode()
{
	if (key_value != -9999)
	{
		cout << "Key is:" << key_value << endl;
		cout << "First Name is:" << fstName << endl;
		cout << "Last Name is: " << lstName << endl;
	}
	else
	{
		cout << "Invalid Node" << endl;
	}
	
}

void Node::setNode(const int k_val, const char* f_name, const char* l_name)
{
	setValue(k_val);
	setFirstName(f_name);
	setLastName(l_name);
}

void Node::setValue(const int k_val)
{
	key_value = k_val;
}

void Node::setFirstName(const char* fName)
{
	fstName = new char[strlen(fName) + 1];
	strcpy(fstName, fName);
}

void Node::setLastName(const char* lName)
{
	lstName = new char[strlen(lName) + 1];
	strcpy(lstName, lName);
}

Node::~Node()
{
	delete[] fstName;
	delete[] lstName;
}