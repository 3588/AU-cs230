#ifndef PRIVATELY_DERIVED_ARRAY_STACK_H
#define PRIVATELY_DERIVED_ARRAY_STACK_H

#include "ArrayList.h"

template <class NodeType>
class PrivatelyDerivedArrayStack : private ArrayList<NodeType>
{
public:
	void resetStack() 
			{ resetList(); return; }
	void push( const NodeType & value )
			{ insertItemAtFront( value); return; }
	void pop( NodeType & value)
			{ removeItemAtFront( value); return; }
	void peek( NodeType & value) 
			{ retrieveItemAtFront( value); return; }
	bool isStackEmpty() 
			{ return isListEmpty(); }
	bool isStackFull()
			{ return isListFull(); }
	void printStack()
			{ printList(); return; }
	int  getStackSize()
			{ return getListItemsCount();}
	void getStackMaximumSize( int & size)
			{ getListMaximumSize( size); return; }
};

#endif;