#include <iostream>
#include "BinarySearchTree.h"
						
//temp solution
#include <fstream>


using namespace std;

//test3
int main()
{
	int x;
	BST<int> tree;

	for( int i = 1 ; i <= 30 ; i++)
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
		/*
		for( int i = 1 ; i <= 4 ; i++)
		{
		cout << "Enter an item: ";
		cin >> x;

		tree.deleteNode( x);
		cout << "Inorder traversal:\t";
		tree.inOrderTraversal();

		}
			*/
		
			cout<<"\n test singleParentNodes\n";
		
			//temp solution
			ofstream out;
		out.open("temp.txt");
		out.close();
		
		cout << "((**TEST**))not are only one child: ";
		tree.singleParentNodes()	;
		//temp solution
		ifstream in;
		in.open("temp.txt");
		int twochild=0,temp_1;
		while(!in.eof())
		{
			in>>temp_1;
			cout<<temp_1<<" ";
			twochild++;
		}
		cout<<" \nThe number of nodes in a binary tree that only one child is :"<<tree.getNodeCount()-twochild;

		cout<<"\n\ntest swapSubtrees:\nAfter swap  left and right\n";
		tree.swapSubtrees();
				cout << "Tree depth is: " << tree.getTreeDepth() - 1 << endl;
		cout << "Node count: " << tree.getNodeCount() << endl;

		cout << "Preorder traversal:\t";
		tree.preOrderTraversal();
		cout << "Inorder traversal:\t";
		tree.inOrderTraversal();
		cout << "Postorder traversal:\t";
		tree.postOrderTraversal();

	return 0;
}


