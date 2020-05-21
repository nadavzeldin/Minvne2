#ifndef __NODE_H
#define __NODE_H

#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Node 
{
public:
	Node(int key, char* firstName, char* lastName);
	Node();
	void printNode();
	void setNode(const int k_val, const char* f_name, const char* l_name);
	void setFirstName(const char* fName);
	void setLastName(const char* lName);
	void setValue(const int k_val);
	~Node();
	Node* point[2];
	int key_value;
	char* fstName;
	char* lstName;

};
#endif // __NODE_H