#include <iostream>
#include <cassert>
#include "LinkedQueue.h"

using namespace std;

int main()
{
	int i, x;
	LinkedQueue<int> q;

	for( i = 1 ; i <= 10 ; i++)
		q.enQueue( i);	

	for( i = 1 ; i <= 3 ; i++)
	{
		q.deQueue( x);
		cout << "X = " << x << endl;
	}

	q.enQueue( 1000);
	q.enQueue( 2000);
	q.enQueue( 3000);

	q.printQueue();

	return 0;
}


