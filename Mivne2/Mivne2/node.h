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


	bool operator<(const int& k) const;
	bool operator>(const int& k) const;
	bool operator<(const Node& s) const;
	bool operator>(const Node& s) const;
	bool operator>=(const Node& s) const;
	bool operator==(const Node& s) const;

	static int count;

	friend ostream& operator<<(ostream& os, const Node& s);
	static void initcount();
	static int getcount();
};
#endif // __NODE_H