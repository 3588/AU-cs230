#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
	LinkedList<int> L;

	for( int i=1 ; i<=5 ; i++)
		L.insertAtFront( 5-i);

	L.printList();
	cout << endl;

	L.resetList();

	for( int i=1 ; i<=5 ; i++)
		if( i%2 == 1)
			L.insertAtFront( i);
		else
			L.insertAtBack( i);

	L.printList();
	cout << endl;

	L.resetList();

	for( int i=1 ; i<=3 ; i++)
	{  
		L.insertAtFront( i);
		L.insertAtBack( 4-i);
	}

	L.printList();

	return 0;
} 