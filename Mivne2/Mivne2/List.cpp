#include <iostream>
using namespace std;

#include "List.h"

List::List() 
{
	head = tail = new Node();
	tail->point[1] = new Node();
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

void List::insertWithOrder(int k, char* firstName, char* lastName, int& compares) {
	
	Node* temp = head;

	Node* newNodeToAdd = new Node();
	newNodeToAdd->setNode(k, firstName, lastName);
	//if head is null
	if (temp->key_value == -9999)
	{
		temp->setNode(k, firstName, lastName);
		temp->point[1] = nullptr;
		return;
	}
	//if head is less then new item
	else if (head->key_value > k)
	{
		newNodeToAdd->point[1] = head;
		head = newNodeToAdd;
		compares++;
		return;
	}
	else
	{
		//check to insert in middle
		while (temp->point[1] != nullptr)
		{
			
			if (temp->key_value < k && temp->point[1]->key_value > k)
			{
						
				//swap
				newNodeToAdd->point[1] = temp->point[1];
				temp->point[1] = newNodeToAdd;
				compares++;
				return;
			}
			temp = temp->point[1];
		}

		//insert in tail
		tail->point[1]=newNodeToAdd;
		tail = newNodeToAdd;
	}
	
}
