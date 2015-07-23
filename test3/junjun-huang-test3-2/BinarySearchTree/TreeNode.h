#ifndef TREE_NODE_H
#define TREE_NODE_H

template <class NodeType>
struct TreeNode
{
	NodeType data;
	TreeNode<NodeType> * leftChildPtr;
	TreeNode<NodeType> * rightChildPtr;
	NodeType intn;
};
#endif;