#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include <iostream>
#include <cassert>
#include "LinkedList.h"

////////////////////////////////////////////  Function destroyNodes
template <class NodeType>
void LinkedList<NodeType>::destroyNodes()
{
	ListNode<NodeType>* currentNode;

	while( firstNode != NULL)
	{
		currentNode = firstNode;
		firstNode = firstNode -> nextNodePtr;
		delete currentNode;
	}
	
	return;
}

////////////////////////////////////////////  Function recursiveReversePrint
template <class NodeType>
void LinkedList<NodeType>::recursiveReversePrint( ListNode<NodeType> * current)
{
	if( current != NULL)
	{
		recursiveReversePrint( current -> nextNodePtr);
		cout << current -> data << "\t";
	}
	
	return;
}

////////////////////////////////////////////  Function iterativeReversePrint
////////////////////////////////////////////  By Marissa Uhrig - Fall 2011
template <class NodeType>
void LinkedList< NodeType>::iterativeReversePrint()
{
    int x = nodeCount;
    for(int i = 0 ; i < nodeCount ; i++)
    {
        ListNode<NodeType>* temp = firstNode;
        for(int j = 1 ; j < x ; j++)
        {
            temp=temp->nextNodePtr;
        }
        cout<<temp->data<<endl;
        x--;
    }
    return;
}

////////////////////////////////////////////  Function createNewNode
template <class NodeType>
ListNode<NodeType>* LinkedList<NodeType>::createNewNode( const NodeType & dataValue)
{
	ListNode<NodeType>* newNode = new ListNode<NodeType>;
	assert( newNode);
	newNode -> data = dataValue;
	newNode -> nextNodePtr = NULL;
	return newNode;
}

////////////////////////////////////////////  Constructor
template <class NodeType>
LinkedList<NodeType>::LinkedList()
{
	firstNode = NULL;
	lastNode = NULL;
	nodeCount = 0;
}

////////////////////////////////////////////  Destructor
template <class NodeType>
LinkedList<NodeType>::~LinkedList()
{
	destroyNodes();	
}

////////////////////////////////////////////  Function insertAtFront
template <class NodeType>
void LinkedList<NodeType>::insertAtFront( const NodeType & insertionData)
{
	if( isListEmpty())
	{
		firstNode = createNewNode( insertionData);
		lastNode = firstNode;
		nodeCount++;
		return;
	}

	ListNode<NodeType>* newNode = createNewNode( insertionData);
	newNode -> nextNodePtr = firstNode;
	firstNode = newNode;
	nodeCount++;
	return;
}

////////////////////////////////////////////  Function insertAtBack
template <class NodeType>
void LinkedList<NodeType>::insertAtBack( const NodeType & insertionData)
{
	if( isListEmpty())
	{
		lastNode = createNewNode( insertionData);
		firstNode = lastNode;
		nodeCount++;
		return;
	}

	ListNode<NodeType>* newNode = createNewNode( insertionData);
	lastNode -> nextNodePtr = newNode;
	lastNode = newNode;
	nodeCount++;
	return;
}

////////////////////////////////////////////  Function removeFromFront
template <class NodeType>
void LinkedList<NodeType>::removeFromFront( NodeType & dataRemoved)
{
	if( isListEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}

	if( firstNode == lastNode)
	{
		ListNode<NodeType>* currentNode = firstNode;
		firstNode = NULL;
		lastNode = NULL;
		dataRemoved = currentNode -> data;
		delete currentNode;
		nodeCount--;
		return;
	}

	ListNode<NodeType>* currentNode = firstNode;

	firstNode = firstNode -> nextNodePtr;
	dataRemoved = currentNode -> data;
	delete currentNode;
	nodeCount--;
	
	return;
}

////////////////////////////////////////////  Function removeFromBack
template <class NodeType>
void LinkedList<NodeType>::removeFromBack( NodeType & dataRemoved)
{
	if( isListEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}

	if( firstNode == lastNode)
	{
		ListNode<NodeType>* currentNode = firstNode;
		firstNode = NULL;
		lastNode = NULL;
		dataRemoved = currentNode -> data;
		delete currentNode;
		nodeCount--;
		return;
	}

	ListNode<NodeType>* currentNode = firstNode;
	while( currentNode -> nextNodePtr != lastNode)
		currentNode = currentNode -> nextNodePtr;
	lastNode = currentNode;
	currentNode = currentNode -> nextNodePtr;
	lastNode -> nextNodePtr = NULL;
	dataRemoved = currentNode -> data;
	delete currentNode;
	nodeCount--;

	return;
}

////////////////////////////////////////////  Function modifyElementAtFront
template <class NodeType>
void LinkedList<NodeType>::modifyElementAtFront( const NodeType & modificationData)
{
	firstNode -> data = modificationData;

	return;
}

////////////////////////////////////////////  Function modifyElementAtBack
template <class NodeType>
void LinkedList<NodeType>::modifyElementAtBack( const NodeType & modificationData)
{
	lastNode -> data = modificationData;

	return;
}

////////////////////////////////////////////  Function retrieveFromFront
template <class NodeType>
void LinkedList<NodeType>::retrieveFromFront( NodeType & retrievedData)
{
	if( isListEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}

	retrievedData = firstNode -> data;

	return;
}

////////////////////////////////////////////  Function retrieveFromBack
template <class NodeType>
void LinkedList<NodeType>::retrieveFromBack( NodeType & retrievedData)
{
	if( isListEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}

	retrievedData = lastNode -> data;

	return;
}

////////////////////////////////////////////  Function isListEmpty
template <class NodeType>
bool LinkedList<NodeType>::isListEmpty()
{
	return (firstNode == NULL);
}

////////////////////////////////////////////  Function resetList
template <class NodeType>
void LinkedList<NodeType>::resetList()
{
	destroyNodes();
	firstNode = NULL;
	lastNode = NULL;
	nodeCount = 0;

	return;
}

////////////////////////////////////////////  Function printList
template <class NodeType>
void LinkedList<NodeType>::printList()
{
	if( isListEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}

	ListNode<NodeType>* currentNode = firstNode;
	while( currentNode != NULL)
	{
		cout << currentNode -> data << endl;
		currentNode = currentNode -> nextNodePtr;
	}

	return;
}

////////////////////////////////////////////  Function printList
template <class NodeType>
void LinkedList<NodeType>::printListInReverse()
{
	if( isListEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}

	int choice;
	cout << "Enter: " << endl
		<< "       1: Using Recursion" << endl
		<< "       2: Using iteration" << endl
		<< "Your choice: ";
	cin >> choice;
	if( choice == 1)
		recursiveReversePrint( firstNode);
	else
		iterativeReversePrint();

	return;
}

////////////////////////////////////////////  Function getNodeCount
template <class NodeType>
int LinkedList<NodeType>::getNodeCount()
{
	return nodeCount;
}

#endif;