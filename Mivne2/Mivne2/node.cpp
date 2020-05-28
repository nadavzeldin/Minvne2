#include "node.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

Node::Node(int key, string firstName, string lastName)
{
	key_value = key;
	fstName = firstName;
	lstName = lastName;
	point[0] = nullptr, point[1] = nullptr;
}

Node::Node(const Node& node)
{
	key_value = node.key_value;
	fstName = node.fstName;
	lstName = node.lstName;
	point[0] = nullptr, point[1] = nullptr;
}

Node& Node::operator=(const Node& node)
{
	this->setNode(node.key_value, node.fstName, node.lstName);
	return *this;
}

void Node::printNode()
{
	if (key_value != -9999)
	{
		cout << "Key is:" << key_value << endl;
		cout << "First Name is:" << fstName << endl;
		cout << "Last Name is: " << lstName << endl;
		cout << endl;
	}
	else
	{
		cout << "Invalid Node" << endl;
	}
}

void Node::setNode(const int k_val, const string f_name, const string l_name)
{
	setValue(k_val);
	setFirstName(f_name);
	setLastName(l_name);
}

void Node::setValue(const int k_val)
{
	key_value = k_val;
}

void Node::setFirstName(const string fName)
{
	fstName = fName;
}

void Node::setLastName(const string lName)
{
	lstName = lName;
}

ostream& operator<<(ostream& os, const Node& s)
{
	os << s.key_value << " (" << s.fstName << ") ";
	return os;
}
