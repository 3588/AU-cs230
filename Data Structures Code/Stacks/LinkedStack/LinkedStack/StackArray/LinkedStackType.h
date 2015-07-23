#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <iostream>
#include <cassert>

using namespace std;

template <class NodeType>
struct StackNode
{
	NodeType data;
	StackNode *nextNodePtr;
};

template <class NodeType>
class LinkedStack
{
public:
	LinkedStack();
	void initializeStack();
	bool isStackEmpty();
	bool peek( NodeType & );
	bool push( const NodeType & );
	bool pop( NodeType & );
	void printStack();
	void getStackSize( int & );
	~LinkedStack( );

private: 
	StackNode<NodeType> * stackTop;
	int stackSize;
	StackNode<NodeType> * createNode( const NodeType & );
}; 

template <class NodeType>
StackNode<NodeType>* LinkedStack<NodeType>::createNode( const NodeType & value)
{
	StackNode<NodeType>* temp = new (StackNode<NodeType>);

	assert( temp);
	temp -> data = value;
	temp -> nextNodePtr = NULL;
	return temp;
}

template <class NodeType>
LinkedStack<NodeType>::LinkedStack( )
{
	stackTop = NULL;
	stackSize = 0;
}

template <class NodeType>
LinkedStack<NodeType>::~LinkedStack()
{
	if( isStackEmpty())
		cout << "Stack is empty." << endl;
	else
	{
		StackNode<NodeType>* temp;
		while( stackTop != NULL)
		{
			temp = stackTop;
			stackTop = stackTop -> nextNodePtr;
			delete temp;
		}
	}
}

template <class NodeType>
void LinkedStack<NodeType>::initializeStack()
{
	stackTop = NULL;
	stackSize = 0;

	return;
}

template <class NodeType>
bool LinkedStack<NodeType>::isStackEmpty( )
{
	return (stackTop == NULL);
}

template <class NodeType>
bool LinkedStack<NodeType>::peek( NodeType & item)
{
	if( !isStackEmpty())
	{
		item = stackTop -> data;
		return true;
	}
	else
	{
		cerr << "Stack is empty. Cannot peek at an empty stack." << endl;
		return false;
	}
}

template <class NodeType>
bool LinkedStack<NodeType>::push( const NodeType & newItem)
{
	if( isStackEmpty())
	{
		stackTop = createNode( newItem);
		stackSize++;
		return true;
	}

	StackNode<NodeType> * temp = createNode( newItem);
	temp -> nextNodePtr = stackTop;
	stackTop = temp;
	stackSize++;
	return true;
}

template <class NodeType>
bool LinkedStack<NodeType>::pop( NodeType & item)
{
	if( isStackEmpty())
	{
		cerr << "Stack is empty. Cannot retrieve from an empty stack." << endl;
		return false;
	}

	StackNode<NodeType> * temp = stackTop;
	item = stackTop -> data;
	stackTop = stackTop -> nextNodePtr;
	stackSize--;
	delete temp;

	return true;
}

template <class NodeType>
void LinkedStack<NodeType>::printStack()
{
	if( isStackEmpty())
	{
		cout << "Stack is empty. Cannot print an empty stack." << endl;
		return;
	}

	StackNode<NodeType>* temp = stackTop;
	while( temp != NULL)
	{
		cout << temp -> data << endl;
		temp = temp -> nextNodePtr;
	}
	
	return;
}

template <class NodeType>
void LinkedStack<NodeType>::getStackSize( int & size)
{
	size = stackSize;
	return;
}

#endif;