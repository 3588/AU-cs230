#ifndef ORDERED_LINKED_LIST_CPP
#define ORDERED_LINKED_LIST_CPP

#include <iostream>
#include "OrderedLinkedList.h"

using namespace std;

template <class NodeType>
int OrderedLinkedList<NodeType>::GetLength()
{
	return getListLength();
}

template <class NodeType>
bool OrderedLinkedList<NodeType>::IsEmpty()
{
	return isEmpty();
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
	if( isEmpty())
	{
		cout << "List is empty." << endl;
		return false;
	}

	bool found = false;
	ListNode<NodeType> * current = first;

	while( current != NULL && !found)
		if( value == current -> data)
			found = true;
		else
			current = current -> nextNodePtr;

	return found;
}

template <class NodeType>
void OrderedLinkedList<NodeType>::insertAtProperLocation( const NodeType & value)
{
	// Case 1: List is empty
	if( isEmpty())
	{
		insertAtFront( value);
		return;
	}

	bool found = false;
	ListNode<NodeType> * current = first;
	ListNode<NodeType> * trailCurrent;
	ListNode<NodeType> * temp = createNode( value);

	while( current != NULL && !found)
		if( current -> data >= value)
			found = true;
		else
		{
			trailCurrent = current;
			current = current -> nextNodePtr;
		}

	// Case 2: The value is smaller than the smallest value in the list
	if( current == first)
	{
		insertAtFront( value);
		return;
	}

	// Case 3: The value is larger than the largest value in the list
	if( !found)
		insertAtBack( value);
	else
		// Case 4: The value is in between two existing valuyes in the list
	{
		trailCurrent -> nextNodePtr = temp;
		temp -> nextNodePtr = current;
		length++;
	}

	return;

}

template <class NodeType>
void OrderedLinkedList<NodeType>::deleteNode( const NodeType & value)
{
	// Case 1: List is empty
	if( isEmpty())
	{
		cout << "List is empty. Nothing to delete." << endl;
		return;
	}

	bool found = false;
	ListNode<NodeType> * current = first;
	ListNode<NodeType> * trailCurrent;
	
	while( current != NULL && !found)
		if( current -> data == value)
			found = true;
		else
		{
			trailCurrent = current;
			current = current -> nextNodePtr;
		}

	// Case 2: The value to delete is contained in the first node of the list
	if( current == first)
	{
		NodeType val;
		removeFromFront( val);
		return;
	}

	// Case 3: The value to delete is contained in the last node of the list
	if( current == last)
	{
		NodeType val;
		removeFromBack( val);
		return;
	}

	// Case 4: The value to delete is not in the list
	if( !found)
	{
		cout << "Value to be deleted is not in the list." << endl;
		return;
	}

	// Case 5: The value to delete is somewhere in the list
	trailCurrent -> nextNodePtr = current -> nextNodePtr;
	delete current;
	length--;
	return;
}
#endif;
