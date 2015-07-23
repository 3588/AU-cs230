#ifndef ORDERED_LINKED_LIST_H
#define ORDERED_LINKED_LIST_H

#include "C:\Documents and Settings\iajwa\My Documents\Visual Studio 2008\Projects\LinkedList\LinkedList\LinkedList\LinkedList.h"

template< class NodeType>
class OrderedLinkedList : private LinkedList<NodeType>
{
public:
	void PrintList();
	bool IsEmpty();
	int  GetLength();
	void deleteNode( const NodeType & );
	bool searchList( const NodeType & );
	void insertAtProperLocation( const NodeType & );
};

#include "OrderedLinkedList.cpp"

#endif;