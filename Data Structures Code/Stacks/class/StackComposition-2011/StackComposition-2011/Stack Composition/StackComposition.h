#ifndef STACK_COMPOSITION_H
#define STACK_COMPOSITION_H

#include "LinkedList.h"

template <class NodeType>
class ComposedStack
{
public:
	void push( const NodeType & value )
			{ stack.insertAtFront( value); return; }
	void pop( NodeType & value)
			{ stack.removeFromFront( value); return; }
	void peek( NodeType & value) 
			{ stack.retrieveFromFront( value); return; }
	void resetStack() 
			{ stack.resetList(); return; }
	void printStack()
			{ stack.printList(); return; }
	bool isStackEmpty() 
			{ return stack.isListEmpty(); }
	int  getStackSize( int & size)
			{ return stack.getNodeCount(); }
private:
	LinkedList<NodeType> stack;
};

#endif;