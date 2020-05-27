#include <iostream>
using namespace std;

#include "List.h"

List::List() 
{
	head = tail = nullptr; 
}

List::~List()
{
	makeEmpty();
}


int List::getCount() const
{
	return DS::getCount();
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

void List::insert (int k, string firstName, string lastName) 
{
	Node *nw = new Node(k, firstName, lastName);
	if(!head)
	{
		head = nw;
		tail = nw;

	}
	else
	{
		tail->point[1] = nw;
		tail = tail->point[1];
	}
}

void List::insertWithOrder(int k, string firstName, string lastName)
{
	Node* new_node = new Node(k, firstName, lastName);
	//if head is null
	if (!head)
	{
		head = tail = new_node;
		return;
	}
	//if head is less then new item
	else if (head->key_value > k)
	{
		new_node->point[1] = head;
		head = new_node;
		count++;
		return;
	}
	else
	{
		count++;
		Node* temp = head;
		//check to insert in middle
		while (temp->point[1])
		{
			
			if (temp->key_value < k && temp->point[1]->key_value > k)
			{
				//swap
				new_node->point[1] = temp->point[1];
				temp->point[1] = new_node;
				count++;
				return;
			}
			temp = temp->point[1];
		}

		//insert in tail
		tail->point[1] = new_node;
		tail = new_node;
	}
	
}
