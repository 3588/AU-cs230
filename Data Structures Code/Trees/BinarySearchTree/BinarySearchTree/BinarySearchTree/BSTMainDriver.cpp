#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	int x;
	BST<int> tree;

	for( int i = 1 ; i <= 20 ; i++)
	{
		x = 10 + rand() % 90;
		//cout << x << endl;
		tree.insertNode( x);
	}
	

		cout << "Tree depth is: " << tree.getTreeDepth() - 1 << endl;
		cout << "Node count: " << tree.getNodeCount() << endl;

		cout << "Preorder traversal:\t";
		tree.preOrderTraversal();
		cout << "Inorder traversal:\t";
		tree.inOrderTraversal();
		cout << "Postorder traversal:\t";
		tree.postOrderTraversal();

		for( int i = 1 ; i <= 4 ; i++)
		{
		cout << "Enter an item: ";
		cin >> x;

		tree.deleteNode( x);
		cout << "Inorder traversal:\t";
		tree.inOrderTraversal();

		}


	return 0;
}
