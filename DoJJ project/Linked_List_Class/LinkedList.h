/*
 * LinkedList.h
 *
 *  Created on: Oct 16, 2014
 *      Author: MackO
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

/*************************************************************
 * 		HOW TO USE
 *
 * 	A_Type = the object
 * 	B_Type = the value you want the object to be sorted by
 *
 * ******example******
 *
 * 	SortedList<Object_Type,string> theList;
 *
 * 	theList.Add( Object_Name, "Jeff Lo");
 ************************************************************/



//STRUCT - what the list is made out of
template <class A_Type,class B_Type>
struct node
{
	A_Type item;
	B_Type value;
	node* next;
	node* prev;
};

template <class A_Type,class B_Type>
class SortedList
{
public:
	SortedList();
	~SortedList();
	void Add(A_Type newVariable,B_Type ValueOfNew);
	void OutputList();
	A_Type SearchFor(B_Type serch);
	bool   Remove(B_Type search);


private:

	node<A_Type,B_Type>* SearchForPtr(B_Type search);
	void SortAsReadIn(node<A_Type,B_Type>* newNode);

	node<A_Type,B_Type>* head;
	node<A_Type,B_Type>* tail;
	int size;
};

template <class A_Type,class B_Type>
node<A_Type,B_Type>* SortedList<A_Type,B_Type>::SearchForPtr(B_Type search)
{
	node<A_Type,B_Type>* temp;
	bool found = false;

	temp = head;

	while(!found && temp!=NULL)
	{
		if(temp->value == search)
		{
			found = true;
		}
		else
		{
			temp = temp->next;
		}
	}

	return temp;
}
template <class A_Type,class B_Type>
bool SortedList<A_Type,B_Type>::Remove(B_Type search)
{
	node<A_Type,B_Type>* temp = SearchForPtr(search);
	bool found = true;

	if(temp != NULL)
	{
		temp->prev->next = temp ->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
	else
	{
		found = false;
	}

	return found;
}
template <class A_Type,class B_Type>
A_Type SortedList<A_Type,B_Type>::SearchFor(B_Type search)
{
	node<A_Type,B_Type>* temp;
	bool found = false;

	temp = head;

	while(!found && temp!=NULL)
	{
		if(temp->value == search)
		{
			found = true;
		}
		else
		{
			temp = temp->next;
		}
	}

	return temp->item;
}

template <class A_Type,class B_Type>
SortedList<A_Type,B_Type>::SortedList()
{
	size = 0;
	head = NULL;
	tail = NULL;
}

template <class A_Type,class B_Type>
SortedList<A_Type,B_Type>::~SortedList()
{
	if(head->next != NULL)
	{
		head = head->next;
		delete head->prev;
	}
	else if(head->next ==NULL)
	{
		delete head;
	}
}

template <class A_Type,class B_Type>
void SortedList<A_Type,B_Type>::Add(A_Type newVariable,B_Type ValueOfNew)
{
	node<A_Type,B_Type>* temp = new node<A_Type,B_Type>;
	temp->item = newVariable;
	temp->value = ValueOfNew;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
		temp->next = NULL;
		temp->prev = NULL;
		size ++;
	}
	else
	{
		SortAsReadIn(temp);
		size++;
	}
}

template <class A_Type,class B_Type>
void SortedList<A_Type,B_Type>::SortAsReadIn(node<A_Type,B_Type>* newNode)
{
	node<A_Type,B_Type>* temp = head;
	if(newNode->value <= head->value)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		newNode->prev = NULL;
	}
	else
	{
		while(temp != NULL && newNode->value > temp->value)
		{
			temp = temp->next;
		}

		if(temp != NULL)
		{
			newNode->next = temp;
			newNode->prev = temp->prev;
			newNode->prev->next = newNode;
			temp->prev = newNode;
		}
		else
		{
			newNode->next = NULL;
			newNode->prev = tail;
			newNode->prev->next = newNode;
			tail = newNode;
		}
	}
}

template <class A_Type,class B_Type>
void SortedList<A_Type,B_Type>::OutputList()
{
	node<A_Type,B_Type>* temp = head;
	while(temp != NULL)
	{
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}

#endif /* LINKEDLIST_H_ */
