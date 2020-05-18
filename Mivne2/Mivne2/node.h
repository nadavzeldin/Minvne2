#pragma once

class node {

public:

	node(int key, char * firstName, char * lastName);
	~node();
	int key_value;
	char * fstName;
	char* lstName;
	node* left;
	node* right;

};