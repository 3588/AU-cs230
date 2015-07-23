#include <iostream>
#include "OrderedLinkedList.h"

using namespace std;

int main()
{
	int i;
	OrderedLinkedList<int> list;

	list.deleteNode( 4);

	for( i=0 ; i <= 50 ; i++)
		if( list.searchList( i))
			list.insertAtProperLocation( i);
		else
			list.insertAtProperLocation( i);

	list.PrintList();
	list.deleteNode( 34);
	list.deleteNode( 18);
	list.deleteNode( 9);
	list.deleteNode( 0);
	list.deleteNode( 50);

	list.PrintList();

	list.deleteNode( 60);

	cout << "\nThe number of nodes in the list is: " << list.GetLength() << endl;
	return 0;
}