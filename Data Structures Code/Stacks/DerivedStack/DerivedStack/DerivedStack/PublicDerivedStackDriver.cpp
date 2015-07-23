#include "PublicDerivedStack.h"

using namespace std;

int main()
{
	PublicDerivedStack<int> stack;

	for( int i=0 ; i <=10 ; i++)
		stack.push( i);

	cout << "Stack contents: " << endl;
	stack.printList();

	int x;
	stack.peek( x);
	cout << "\nStack Top is: " << x << endl;

	stack.insertAtBack( 100000);

	cout << "\nStack contents after illegal operation: " << endl;
	stack.printList();

	return 0;
}