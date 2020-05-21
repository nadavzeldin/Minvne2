#include <iostream>
using namespace std;

#include "List.h"

List::List() 
{
	tail = new Node();
	head = tail->point[1] = new Node();
	tail->point[0] = new Node();
}

List::~List()
{
	makeEmpty();
}

void List::printDS()
{
	Node* tmp = head;
	while(tmp)
	{
		tmp->printNode();
		tmp = tmp->point[1];
	}
}

void List::makeEmpty()
{
	makeEmpty(tail);
}

void List::makeEmpty(Node* tail)
{
	while (tail != nullptr)
	{
		Node* temp = tail;
		tail = tail->point[0];
		delete temp;
	}
}

bool List::isEmpty()
{
	return (head == tail || tail == nullptr);
}

void List::insert (int k, char * firstName, char * lastName) {
		tail->point[1] ->setNode(k, firstName, lastName);
		tail = tail->point[1];
		tail->point[1] = new Node();
}