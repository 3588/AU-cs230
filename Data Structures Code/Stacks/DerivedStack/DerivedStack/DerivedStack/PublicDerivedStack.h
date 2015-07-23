#ifndef PUBLIC_DERIVED_STACK
#define PUBLIC_DERIVED_STACK

#include "LinkedList.h"

template <class NodeType>
class PublicDerivedStack : public LinkedList<NodeType>
{
public:
	void resetStack() 
			{ resetList(); return; }
	bool isStackEmpty() 
			{ return isListEmpty(); }
	bool peek( NodeType & value) 
			{ return peekAtFront( value); }
	bool push( const NodeType & value )
			{ return insertAtFront( value); }
	bool pop( NodeType & value)
			{ return removeFromFront( value); }
	void printStack()
			{ printList(); return; }
	void getStackSize( int & size)
			{ size = getListLength(); return; }
};

#endif;