#ifndef __LIST_H
#define __LIST_H

#pragma once

#include "ds.h"

class List : public DS
{
public:
	List();
	~List();

	virtual void printDS();
	virtual bool isEmpty();
	virtual void makeEmpty();
	virtual void insert(int k, string firstName, string lastName);
	void insertWithOrder(int k, string firstName, string lastName);
private:
	void makeEmpty(Node* lstnode);
	Node *tail;
};
#endif // __LIST_H