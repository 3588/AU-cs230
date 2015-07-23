#ifndef LINKED_LIST_H
#define LINKED_LIST_H
template <class NodeType>
struct ListNode
{
	NodeType data;
	ListNode<NodeType> *nextNodePtr;
};


template <class NodeType>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();										// To be coded in class
	void insertAtFront( const NodeType &);
	void insertAtBack( const NodeType &);				// To be coded in class
	void removeFromFront( NodeType &);					// To be coded in class
	void removeFromBack( NodeType &);				
	void modifyElementAtFront( const NodeType &);
	void modifyElementAtBack( const NodeType &);		// To be coded in class
	void retrieveFromFront( NodeType &);				// To be coded in class
	void retrieveFromBack( NodeType &);				
	bool isEmpty();
	void resetList();									// To be coded in class
	void printList();
	int  getListLength();
	//void getlocation(int&,NodeType&);
	void printatlocation(int,NodeType &);
	ListNode<NodeType>* first;
	ListNode<NodeType>* last;
	ListNode<NodeType>* createNode( const NodeType &);
	int length;	
};

#include "LinkedList.cpp"

#endif;