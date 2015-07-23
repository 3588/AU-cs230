#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include <iostream>
#include <cassert>
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
	
	return;
}

////////////////////////////////////////////  Function removeFromFront
template <class NodeType>
void LinkedList<NodeType>::removeFromFront( NodeType & x)
{
	
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
		return true;
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
	first -> data = x;
	return;
}

////////////////////////////////////////////  Function modifyElementAtBack
template <class NodeType>
void LinkedList<NodeType>::modifyElementAtBack( const NodeType & x)
{
	return;
}

////////////////////////////////////////////  Function retrieveFromFront
template <class NodeType>
void LinkedList<NodeType>::retrieveFromFront( NodeType & x)
{
	
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

#endif;