#ifndef BINARY_SEARCH_TREE_CPP
#define BINARY_SEARCH_TREE_CPP

#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>


using namespace std;

template <class NodeType>
void BST<NodeType>::deleteNode( NodeType item)
{
	if( isTreeEmpty())
	{
		cout << "Tree is empty." << endl;
		return;
	}

	TreeNode<NodeType> * current = root;
	TreeNode<NodeType> * trailCurrent;
	bool found = false;

	while( current != NULL && !found)
	{
		if( current -> data == item)
			found = true;
		else if( current -> data < item)
		{
			trailCurrent = current;
			current = current -> rightChildPtr;
		}
		else
		{
			trailCurrent = current;
			current = current -> leftChildPtr;
		}
	}

	if( current == NULL)
	{
		cout << "Item to be deleted is not in the tree" << endl;
		return;
	}

	if( found)
	{
		if( current -> leftChildPtr == NULL && current -> rightChildPtr == NULL)
		{
			if( trailCurrent -> data < item)
				trailCurrent -> rightChildPtr = NULL;
			else
				trailCurrent -> leftChildPtr = NULL;
			delete current;
		}
		else if( current -> leftChildPtr == NULL)
		{
			if( trailCurrent -> data < item)
				trailCurrent -> rightChildPtr = current -> rightChildPtr;
			else
				trailCurrent -> leftChildPtr = current -> rightChildPtr;
			delete current;
		}
		else if( current -> rightChildPtr == NULL)
		{
			if( trailCurrent -> data < item)
				trailCurrent -> rightChildPtr = current -> leftChildPtr;
			else
				trailCurrent -> leftChildPtr = current -> rightChildPtr;
			delete current;
		}
		else
		{ // Assignment 10
		}
	}

	return;
}

template <class NodeType>
bool BST<NodeType>::searchTree( NodeType item)
{
	if( isTreeEmpty())
	{
		cout << "Tree is empty." << endl;
		return false;
	}

	TreeNode<NodeType> * current = root;

	while( current != NULL)
	{
		if( current -> data == item)
			return true;

		if( current -> data < item)
			current = current -> rightChildPtr;
		else
			current = current -> leftChildPtr;
	}

	return false;
}

template <class NodeType>
bool BST<NodeType>::isTreeEmpty()
{
	return root == NULL;
}

template <class NodeType>
void BST<NodeType>::inOrderTraversal()
{
	inOrder( root);
	cout << endl;
	return;
}

template <class NodeType>
void BST<NodeType>::inOrder( TreeNode<NodeType> * p)
{
	if( p == NULL)
		return;
	inOrder( p->leftChildPtr);
	cout << p -> data << " ";
	inOrder( p->rightChildPtr);
}

template <class NodeType>
void BST<NodeType>::postOrderTraversal()
{
	postOrder( root);
	cout << endl;
	return;
}

template <class NodeType>
void BST<NodeType>::postOrder( TreeNode<NodeType> * p)
{
	if( p == NULL)
		return;
	postOrder( p->leftChildPtr);
	postOrder( p->rightChildPtr);
	cout << p -> data << " ";
}

template <class NodeType>
void BST<NodeType>::preOrderTraversal()
{
	preOrder( root);
	cout << endl;
	return;
}

template <class NodeType>
void BST<NodeType>::preOrder( TreeNode<NodeType> * p)
{
	if( p == NULL)
		return;
	cout << p -> data << " ";
	preOrder( p->leftChildPtr);
	preOrder( p->rightChildPtr);
}

template <class NodeType>
int BST<NodeType>::getNodeCount()
{
	return countNodes( root);
}

template <class NodeType>
int BST<NodeType>::countNodes( TreeNode<NodeType> * p )
{
	if( p == NULL)
		return 0;

	return 1 + countNodes( p->leftChildPtr) + countNodes( p->rightChildPtr);

}

template <class NodeType>
TreeNode<NodeType> * BST<NodeType>::createNewNode( NodeType & item)
{
	TreeNode<NodeType> * newNode = new TreeNode<NodeType>;
	newNode -> data = item;
	newNode -> leftChildPtr = NULL;
	newNode -> rightChildPtr = NULL;
	newNode ->intn =0;

	return newNode;
}

template <class NodeType>
void BST<NodeType>::insertNode( NodeType & item)
{
	TreeNode<NodeType> * newNode = createNewNode( item);

	if( root == NULL)
	{
		root = newNode;
		return;
	}

	TreeNode<NodeType> * current = root;
	TreeNode<NodeType> * trailCurrent = root;

	while( current != NULL)
	{
		if( current -> data > item)
		{
			trailCurrent = current;
			current = current -> leftChildPtr;
		}
		else if ( current -> data < item)
		{
			trailCurrent = current;
			current = current -> rightChildPtr;
		}
		else 
		{
			cout << "Item already in the tree. No duplication." << endl;
			return;
		}
	}
	if( trailCurrent -> data > item)
		trailCurrent -> leftChildPtr = newNode;
	else
		trailCurrent -> rightChildPtr = newNode;

	return;
}


template <class NodeType>
BST<NodeType>::BST()
{
	root = NULL;
}

template <class NodeType>
BST<NodeType>::~BST()
{
	destroy( root);
}

template <class NodeType>
void BST<NodeType>::destroy( TreeNode<NodeType> * ptr)
{
	if( ptr != NULL)
	{
		destroy( ptr -> leftChildPtr);  // Destroy left subtree of ptr
		destroy( ptr -> rightChildPtr); // Destroy right subtree of ptr
		delete ptr;
	}
}

template <class NodeType>
int BST<NodeType>::getTreeDepth()
{
	return computeDepth( root);
}

template <class NodeType>
int BST<NodeType>::computeDepth( TreeNode<NodeType> * ptr)
{
	if( ptr == NULL)
		return 0;
	else 
		return 1 + maximum( computeDepth( ptr -> leftChildPtr), computeDepth( ptr -> rightChildPtr));	
}

template <class NodeType>
int BST<NodeType>::maximum( int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}





	  //test3
  /*
template <class NodeType>
void BST<NodeType>::inOrderTraversal()
{
	inOrder( root);
	cout << endl;
	return;
}
template <class NodeType>
void BST<NodeType>::inOrder( TreeNode<NodeType> * p)
{
	if( p == NULL)
		return;
	inOrder( p->leftChildPtr);
	cout << p -> data << " ";
	inOrder( p->rightChildPtr);
}*/
template <class NodeType>
void BST<NodeType>::swapSubtrees()
{
	swap( root);
	cout << endl;
	return;
}
template <class NodeType>
void BST<NodeType>::swap( TreeNode<NodeType> * t)              
{
	TreeNode<NodeType> * temp;
    
    if(t){
        swap(t -> leftChildPtr);
        swap(t -> rightChildPtr);
        temp = t -> leftChildPtr;
        t -> leftChildPtr = t -> rightChildPtr;
        t -> rightChildPtr = temp;
    }
}

/*
template <class NodeType>
int BST<NodeType>::getNodeCount()
{
	return countNodes( root);
}

template <class NodeType>
int BST<NodeType>::countNodes( TreeNode<NodeType> * p )
{
	if( p == NULL)
		return 0;

	return 1 + countNodes( p->leftChildPtr) + countNodes( p->rightChildPtr);

}
*/

template <class NodeType>
void BST<NodeType>::singleParentNodes()
{
	return single( root);
}

template <class NodeType>
void BST<NodeType>::single( TreeNode<NodeType> * p )
{		
	
	
	
	if( p == NULL)
		return;
	
	if(p->rightChildPtr!=NULL&&p->leftChildPtr!=NULL)
	{
		//cout<<p->data;
	//temp solution
		ofstream out;
		out.open("temp.txt", ios::app);
		out<<p->data<<"\n";
		out.close();

	}
			 single( p->leftChildPtr) ;
			 single( p->rightChildPtr);
	/*
	if( p == NULL)
		return 0;
	if(p->rightChildPtr>0&&p->leftChildPtr==NULL)
		cout<<"条件符合\n";
	single(p->leftChildPtr);
	/*if(((p->rightChildPtr!=NULL)&&(p->leftChildPtr==NULL))||((p->leftChildPtr!=NULL)&&(p->rightChildPtr==NULL)))
	{
		cout<<"符合条件\n";
		return 1 + single( p->leftChildPtr) + single( p->rightChildPtr);
	}		 */

}

#endif;
	