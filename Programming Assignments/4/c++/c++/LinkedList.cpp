#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include <iostream>
#include <cassert>
#include <string>
#include "LinkedList.h"

////////////////////////////////////////////  Function CreateNode
template <class NodeType>
ListNode<NodeType>* LinkedList<NodeType>::createNode( const NodeType & value)
{
	ListNode<NodeType>* temp = new ListNode<NodeType>;
	assert( temp);
	temp -> data = value;
	temp -> nextNodePtr = NULL;
	return temp;
}

////////////////////////////////////////////  Constructor
template <class NodeType>
LinkedList<NodeType>::LinkedList()
{
	first = NULL;
	last = NULL;
	length = 0;
}

////////////////////////////////////////////  Destructor
template <class NodeType>
LinkedList<NodeType>::~LinkedList()
{

	if(!isEmpty())
	{
	ListNode<NodeType> *temp = first;
	while (!isEmpty())
	{
		temp = first;
		first = first ->nextNodePtr;
		delete temp;
	}
	}
	/*
	if( isEmpty())
		cout << "List is empty." << endl;
	else{
		ListNode<NodeType>* temp;
		while( first != NULL)
		{
			temp = first;
			first = first -> nextNodePtr;
			delete temp;
		}
	}
	*/
}

////////////////////////////////////////////  Function insertAtFront
template <class NodeType>
void LinkedList<NodeType>::insertAtFront( const NodeType & x)
{
	if( isEmpty())
	{
		first = last = createNode( x);
		length++;
		return;
	}

	ListNode<NodeType>* temp = createNode( x);
	temp -> nextNodePtr = first;
	first = temp;
	length++;
	return;
}

////////////////////////////////////////////  Function insertAtBack
template <class NodeType>
void LinkedList<NodeType>::insertAtBack( const NodeType & x)
{
	ListNode<NodeType>*temp=createNode(x);
		if(isEmpty())
		{
			first=last=temp;
			length++;
			return;
		}
		last->nextNodePtr=temp;
		last=temp;
		length++;
		return;
	
	/*
	if( isEmpty())
	{
		first = last = createNode( x);
		count++;
		return true;
	}

	ListNode<NodeType>* temp = createNode( x);
	temp -> nextNodePtr = first;
	first = temp;
	count++;
	return true;
	*/
}

////////////////////////////////////////////  Function removeFromFront
template <class NodeType>
void LinkedList<NodeType>::removeFromFront( NodeType & x)
{
	if (isEmpty())
	{
		cout<<"Empty\n";
		return;
	}
	if (first==last)
	{
		ListNode<NodeType>*temp=first;
		x=temp->data;
		first=last=NULL;
		delete temp;
		length--;
	}
	ListNode<NodeType>*temp=first;
	x = temp->data;
	first=first->nextNodePtr;
	delete temp;
	length--;
	/*if( isEmpty())
	{
	cout << "List is empty." << endl;
	return false;
	}

	ListNode<NodeType>* temp = first;

	first = first -> nextNodePtr;
	x = temp -> data;
	delete temp;
	count--;

	// Needed if there is only one node in the initial list
	if( isEmpty())
	last = first;

	return true;*/
	return;
}

////////////////////////////////////////////  Function removeFromBack
template <class NodeType>
void LinkedList<NodeType>::removeFromBack( NodeType & x)
{
	if( isEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}

	if( first == last)
	{
		ListNode<NodeType>* temp = first;
		first = last = NULL;
		x = temp -> data;
		delete temp;
		length--;
		return;
	}

	ListNode<NodeType>* temp = first;
	while( temp -> nextNodePtr != last)
		temp = temp -> nextNodePtr;
	last = temp;
	temp = temp -> nextNodePtr;
	last -> nextNodePtr = NULL;
	x = temp -> data;
	delete temp;
	length--;
	return;
}

////////////////////////////////////////////  Function modifyElementAtFront
template <class NodeType>
void LinkedList<NodeType>::modifyElementAtFront( const NodeType & x)
{
	if (!isEmpty())
	first -> data = x;
	return;
}

////////////////////////////////////////////  Function modifyElementAtBack
template <class NodeType>
void LinkedList<NodeType>::modifyElementAtBack( const NodeType & x)
{
	last->data=x;
	return;
}

////////////////////////////////////////////  Function retrieveFromFront
template <class NodeType>
void LinkedList<NodeType>::retrieveFromFront( NodeType & x)
{
	if (!isEmpty())
	x=first->data;
	return;
}

////////////////////////////////////////////  Function retrieveFromBack
template <class NodeType>
void LinkedList<NodeType>::retrieveFromBack( NodeType & x)
{
	if( isEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}

	x = last -> data;
	return;
}

////////////////////////////////////////////  Function isEmpty
template <class NodeType>
bool LinkedList<NodeType>::isEmpty()
{
	return (first == NULL);
}

////////////////////////////////////////////  Function resetList
template <class NodeType>
void LinkedList<NodeType>::resetList()
{
	first=last=NULL;
	length=0;
	return;
}

////////////////////////////////////////////  Function printList
template <class NodeType>
void LinkedList<NodeType>::printList()
{
	if( isEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}

	ListNode<NodeType>* temp = first;
	while( temp != NULL)
	{
		cout << temp -> data << endl;
		temp = temp -> nextNodePtr;
	}

	return;
}
////////////////////////////////////////////  Function getListLength
template <class NodeType>
int LinkedList<NodeType>::getListLength()
{
	return length;
}



////////////////////////////////////////////  *Function getlocation
/*
template <class NodeType>
void LinkedList<NodeType>::getlocation(int &y,NodeType &x)
{
	if( isEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}
	int location=1;
	y=0;


	ListNode<NodeType>* temp = first;
	while( temp != NULL)
	{
		cout << temp -> data << endl;
		temp = temp -> nextNodePtr;
	}

	return;
}
*/ 
///////////////////////////////////////////  Function printatlocation
template <class NodeType>
void LinkedList<NodeType>::printatlocation(int x, NodeType& data1)
{
	int y=0;
	data1="";
	if( isEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}
	

	ListNode<NodeType>* temp = first;
	while( temp != NULL)
	{
		if (y==x-1)
		{
			data1=temp -> data;
			temp = temp -> nextNodePtr;
			return;
		}
		
		else
		{
			data1=temp -> data;
			temp = temp -> nextNodePtr;
			y++;
		}
	
	}

	return;
}
#endif;