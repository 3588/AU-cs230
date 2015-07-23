#ifndef ORDERED_LINKED_LIST_H
#define ORDERED_LINKED_LIST_H

#include "W:\2011-New-Courses\230\Resources\MyDataStructures\LinkedLists\LinkedList\LinkedList.h"

template <class NodeType>
class OrderedLinkedList : private LinkedList<NodeType>
{
public:
	bool searchList( const NodeType & );
	void deleteNode( const NodeType & );
	void insertNode( const NodeType & );
	void PrintList( );
	bool IsListEmpty();
};

#include "OrderedLinkedList.cpp"

#endif;