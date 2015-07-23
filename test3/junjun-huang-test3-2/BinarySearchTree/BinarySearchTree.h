#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "TreeNode.h"

template <class NodeType>
class BST
{
public:
	BST();
	~BST();
	int  getTreeDepth();
	int  getNodeCount();
	bool isTreeEmpty();
	bool searchTree( NodeType  );
	void preOrderTraversal();
	void inOrderTraversal();
	void postOrderTraversal();
	void insertNode( NodeType & );
	void deleteNode( NodeType );
	//test3	
	void swapSubtrees();
	void  singleParentNodes();

private:
	
	TreeNode<NodeType> * root;
	void destroy( TreeNode<NodeType> * ptr);
	int  countNodes( TreeNode<NodeType> *);
	TreeNode<NodeType> * createNewNode( NodeType & );
	int computeDepth( TreeNode<NodeType> * );
	int maximum( int, int);
	void preOrder( TreeNode<NodeType> *);
	void inOrder( TreeNode<NodeType> *);
	void postOrder( TreeNode<NodeType> *);
	//test3	
	void swap( TreeNode<NodeType> *);
	void  single( TreeNode<NodeType> *);
	
};

#include "BinarySearchTree.cpp"

#endif;