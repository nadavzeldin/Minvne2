#ifndef __NODE_H
#define __NODE_H

#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Node 
{
public:
	Node(int key, string firstName, string lastName);
	Node(const Node& node);
	Node() = default;
	void printNode();
	void setNode(const int k_val, const string f_name, const string l_name);
	void setFirstName(const string fName);
	void setLastName(const string lName);
	void setValue(const int k_val);
	Node* point[2];
	int key_value;
	string fstName;
	string lstName;

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