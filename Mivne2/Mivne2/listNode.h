#pragma once


class listNode {

public:

	listNode(int key, char* firstName, char* lastName);
	listNode();
	~listNode();
	int key_value;
	char* fstName;
	char* lstName;
	listNode* next;
	listNode* previous;

};