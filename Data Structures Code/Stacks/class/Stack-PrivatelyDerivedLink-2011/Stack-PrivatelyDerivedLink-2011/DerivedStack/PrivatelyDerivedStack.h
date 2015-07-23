#ifndef PRIVATELY_DERIVED_LINKED_STACK_H
#define PRIVATELY_DERIVED_LINKED_STACK_H

#include "LinkedList.h"

template <class NodeType>
class PrivatelyDerivedStack : private LinkedList<NodeType>
{
public:
	void push( const NodeType & value )
			{ insertAtFront( value); return; }
	void pop( NodeType & value)
			{ removeFromFront( value); return; }
	void peek( NodeType & value) 
			{ removeFromFront( value); return; }
	void resetStack() 
			{ resetList(); return; }
	void printStack()
			{ printList(); return; }
	bool isStackEmpty() 
			{ return isListEmpty(); }
	int  getStackSize()
			{ return getNodeCount();}
};

#endif;