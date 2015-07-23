#include <iostream>
#include "LinkedStackType.h"

using namespace std;

int main()
{
	int x;
	LinkedStack<int> intStack;

	for( int i = 0 ; i < 22 ; i++)
		intStack.push( i*2);

	intStack.printStack();
	intStack.pop( x);

	cout << "After pop" << endl;
	intStack.printStack();

	return 0;
}