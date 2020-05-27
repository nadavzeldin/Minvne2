#include "node.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int Node::count;

Node::Node(int key, string firstName, string lastName)
{
	key_value = key;
	fstName = firstName;
	lstName = lastName;
	point[0] = nullptr, point[1] = nullptr;
	count = 0;
}

Node::Node(const Node& node)
{
	key_value = node.key_value;
	fstName = node.fstName;
	lstName = node.lstName;
	point[0] = nullptr, point[1] = nullptr;
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


bool Node::operator<(const int& k) const
{
	count++;
	return this->key_value < k;
}

bool Node::operator>(const int& k) const
{
	count++;
	return this->key_value > k;
}

bool Node::operator<(const Node& s) const
{
	count++;
	return this->key_value < s.key_value;
}

bool Node::operator>(const Node& s) const
{
	count++;
	return this->key_value > s.key_value;
}

bool Node::operator>=(const Node& s) const
{
	count++;
	return this->key_value >= s.key_value;
}

bool Node::operator==(const Node& s) const
{
	count++;
	return this->key_value == s.key_value;
}

void Node::initcount()
{
	count = 0;
}

int Node::getcount()
{
	return count;
}

ostream& operator<<(ostream& os, const Node& s)
{
	os << s.key_value << " (" << s.fstName << ") ";
	return os;
}
