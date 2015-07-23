#include <iostream>
#include "OrderedLinkedList.h"

using namespace std;

int main()
{
	OrderedLinkedList<int> list;

	list.deleteNode( 51);
	
	cout << endl;

	for( int i = 1 ; i <= 10 ; i++)
		list.insertNode( i*2);

	list.insertNode( 0);
	list.insertNode( 1);
				
	cout << "New List: " << endl;
	list.PrintList();

	list.deleteNode( 40);
	list.deleteNode( 10);
	list.deleteNode( 0);
	list.deleteNode( 100);

	cout << "New List: " << endl;
	list.PrintList();

	for( int i = 0 ; i <= 20 ; i++)
		if( !list.IsListEmpty())
			if( list.searchList( i))
				cout << i << " was found in list" << endl;
			else
				cout << i << " was not found in list" << endl;

	return 0;
}