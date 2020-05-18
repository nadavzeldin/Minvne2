#pragma once

#include "listNode.h"

class List
{
public:
	List();
	~List();

	void insertEnd(listNode* lstnode);
	bool IsEmpty();
	void MakeEmpty();

private:
	void MakeEmpty(listNode* lstnode);
	listNode * head;
	listNode * tail;
};