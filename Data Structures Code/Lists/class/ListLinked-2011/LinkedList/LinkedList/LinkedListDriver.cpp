#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	int y = 5;
	LinkedList<int> x;

	// x.printList();
	x.insertFront( y);
	//x.printList();
	x.insertBack( 10);
	//x.printList();
	x.insertBack( 2);
	x.insertFront( 34);
	//x.printList();
	x.removeBack( y);
	x.removeFront( y);
	x.printList();

	return 0;
}