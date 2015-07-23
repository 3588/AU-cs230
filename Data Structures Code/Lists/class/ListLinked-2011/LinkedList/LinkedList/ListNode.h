#ifndef LIST_NODE_H
#define LIST_NODE_H

template <class NodeType>
struct ListNode
{
	NodeType data;
	ListNode<NodeType> *nextNodePtr;
};

#endif;