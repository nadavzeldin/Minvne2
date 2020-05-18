#include <iostream>
using namespace std;

#include "List.h"
#include "listNode.h"
List::List() 
{
	head = tail = new listNode(-99999, nullptr, nullptr);
}

List::~List()
{
	MakeEmpty();
}

void List::MakeEmpty()
{
	MakeEmpty(tail);
}

void List::MakeEmpty(listNode* tail)
{
	while (tail != nullptr)
	{
		listNode* temp = tail;
		tail = tail->previous;
		delete temp;
	}
	tail = nullptr;
}

bool List::IsEmpty()
{
	if (head == tail || tail == nullptr)
		return true;

	return false;
}

void List::insertEnd(listNode* data)
{
	if (data != nullptr)
	{
		tail->next = data;
		tail = tail->next;
	}
	else
		cout << "listNode is null";
	
}