#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListNode.h"

template <class NodeType>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void insertAtFront( const NodeType & insertionData);
	void insertAtBack( const NodeType & insertionData);
	void removeFromFront( NodeType & dataRemoved);	
	void removeFromBack( NodeType & dataRemoved);				
	void modifyElementAtFront( const NodeType & modificationData);
	void modifyElementAtBack( const NodeType & modificationData);
	void retrieveFromFront( NodeType & retrievedData);
	void retrieveFromBack( NodeType & retrievedData);				
	bool isListEmpty();
	void resetList();
	void printList();
	void printListInReverse();
	int  getNodeCount();

	//=======test2
	void divideAt( LinkedList<NodeType> &secondList, const NodeType & item, int &del) ;

	

   protected:
	int nodeCount;
	void destroyNodes();
	void recursiveReversePrint( ListNode<NodeType> * nodePtr);
	void iterativeReversePrint();
	ListNode<NodeType>* firstNode;
	ListNode<NodeType>* lastNode;
	ListNode<NodeType>* createNewNode( const NodeType &);
	
};

#include "LinkedList.cpp"

#endif;