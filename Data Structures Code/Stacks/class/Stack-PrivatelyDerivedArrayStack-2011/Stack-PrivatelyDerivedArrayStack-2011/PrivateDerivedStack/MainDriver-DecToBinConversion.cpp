#include "PrivatelyDerivedArrayStack.h"

using namespace std;

void convertToBinary( unsigned num)
{
	int number = num;
	PrivatelyDerivedArrayStack< int > binaryStack;

	while( number > 0)
	{
		if( !binaryStack.isStackFull())
			binaryStack.push( number % 2);
		else
		{
			cout << "Stack is full." << endl;
			exit( 0);
		}

		number = number / 2;
	}
	
	cout << "\nBinary representation of decimal " << num << " is ";
	int bit;
	while( !binaryStack.isStackEmpty())
	{
		binaryStack.pop( bit);
		cout << bit;
	}

	cout << "\n" << endl;

	return;
}

int main()
{
	unsigned number;

	for( int i = 1 ; i <= 5 ; i++)
	{
		cout << "Enter a positive integer: ";
		cin >> number;
		convertToBinary( number);
	}

	return 0;
}