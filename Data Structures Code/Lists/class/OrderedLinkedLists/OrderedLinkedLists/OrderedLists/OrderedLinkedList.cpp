#ifndef ORDERED_LINKED_LIST_CPP
#define ORDERED_LINKED_LIST_CPP

#include <iostream>
#include "OrderedLinkedList.h"

using namespace std;

template <class NodeType>
bool OrderedLinkedList<NodeType>::IsListEmpty()
{
	return isListEmpty();
}

template <class NodeType>
void OrderedLinkedList<NodeType>::PrintList()
{
	printList();
	return;
}

template <class NodeType>
bool OrderedLinkedList<NodeType>::searchList( const NodeType & value)
{
	if( IsListEmpty())
	{
		cout << "List is empty" << endl;
		return false;
	}

	bool found = false;
	ListNode<NodeType> * current = firstNode;

	while( current != NULL && !found)
		if( current -> data == value)
			found = true;
		else
			current = current -> nextNodePtr;

	return found;
}

template <class NodeType>
void OrderedLinkedList<NodeType>::insertNode( const NodeType & value)
{
	// Case 1: List is empty. The new node goes as first node in the list
	if( IsListEmpty())
	{
		insertAtFront( value);
		return;
	}

	ListNode<NodeType> * current = firstNode;
	ListNode<NodeType> * trailCurrent;
	bool found = false;

	while (current != NULL && !found)
		if( current -> data >= value)
			found = true;
		else
		{
			trailCurrent = current;
			current = current -> nextNodePtr;
		}

	// Case 2: New node is smaller than the smallest value in the list 
	if( current == firstNode)
	{
		insertAtFront( value);
		return;
	}

	// Case 3: New node is larger than the largest value in the list
	if( current == NULL)
	{
		insertAtBack( value);
		return;
	}

	// Case 4: New node is to be inserted between two existing nodes
	ListNode<NodeType> * temp = createNewNode( value);
	trailCurrent -> nextNodePtr = temp;
	temp -> nextNodePtr = current;
	nodeCount++;
	return;
}

template <class NodeType>
void OrderedLinkedList<NodeType>::deleteNode( const NodeType & value)
{
	// Case 1: List is empty.
	if( IsListEmpty())
	{
		cout << "List is empty. Nothing to delete." << endl;
		return;
	}

	ListNode<NodeType> * current = firstNode;
	ListNode<NodeType> * trailCurrent;
	bool found = false;

	while (current != NULL && !found)
		if( current -> data == value)
			found = true;
		else
		{
			trailCurrent = current;
			current = current -> nextNodePtr;
		}

	// Case 2: Value to delete is contained in the first node of the list 
	if( current == firstNode && found)
	{
		removeFromFront();
		return;
	}

	// Case 3: Value to delete is contained in the last node of the list
	if( current == NULL && found)
	{
		removeFromBack();
		return;
	}

	// Case 4: Value to delete is not in the list
	if( !found)
	{
		cout << "\nValue to delete is not in the list." << endl;
		return;
	}

	// Case 5: Value to delete is contained in a node somewhere in the list
	trailCurrent -> nextNodePtr = current -> nextNodePtr;
	delete current;
	nodeCount--;
	return;
}

#endif;