#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include "ArrayList.h"

using namespace std;

/////////////////////////////////////////////// Constructor and Destrutor
template <class LT>
ArrayList<LT>::ArrayList( int size)
{
	if( size <= 0)
	{
		cerr << "Invalid list size. Default size of 100 is used." << endl;
		maxSize = 100;
	}
	else
		maxSize = size;
		
	list = new LT[maxSize];
	assert( list != NULL);
	length = 0;
}

template <class LT>
ArrayList<LT>::~ArrayList()
{
	delete [] list;
}

/////////////////////////////////////////////// Insert Functions

template <class LT>
void ArrayList<LT>::insertAtFront( const LT & item)
{
	if( isFull())
	{
		cout << "List is full." << endl;
		return;
	}
	if( !isEmpty())
	{
		int i = length;
		while( i >= 0)
		{
			list[i+1] = list[i];
			i--;
		}
	}
	list[0] = item;
	length++;
	return;
}

template <class LT>
void ArrayList<LT>::insertAtBack( const LT & item)
{
	if( isFull())
	{
		cout << "List is full." << endl;
		return;
	}

	list[length] = item;
	length++;

	return;
}

template <class LT>
void ArrayList<LT>::insertAtLocation( int location, const LT & item)
{
	if( isFull())
	{
		cout << "List is full." << endl;
		return;
	}

	if( location < 0 || location > length+1)
	{
		cout << "Invalid location. Item not inserted." << endl;
		return;
	}
	
	int i = length;
	while( i >= location)
		{
			list[i+1] = list[i];
			i--;
		}
	
	list[length] = item;
	length++;

	return;
}

/////////////////////////////////////////////// Remove Functions

template <class LT>
void ArrayList<LT>::removeFromFront( LT & item)
{
	if( !isEmpty())
	{
		item = list[0];
		int i = 1;
		while( i < length)
		{
			list[i] = list[i+1];
			i++;
		}

		length--;
		return;
	}

	cout << "List is empty" << endl;
	return;
}

template <class LT>
void ArrayList<LT>::removeFromBack( LT & item)
{
	if( !isEmpty())
	{
		item = list[length];
		length--;
		return;
	}

	cout << "List is empty" << endl;
	return;
}

template <class LT>
void ArrayList<LT>::removeFromLocation( int location, LT & item)
{
	
	return;
}

/////////////////////////////////////////////// Modify Functions

template <class LT>
void ArrayList<LT>::modifyElementAtFront( const LT & item)
{

	return;
}

template <class LT>
void ArrayList<LT>::modifyElementAtBack( const LT & item)
{

	return;
}

template <class LT>
void ArrayList<LT>::modifyElementAtLocation( int location, const LT & item)
{
	if( location < 0 || location > length)
	{
		cout << "Invalid subscript. No elements were modified." << endl;
		return;
	}

	list[location] = item;
	return;
}

/////////////////////////////////////////////// Retrieve Functions

template <class LT>
void ArrayList<LT>::retrieveFromFront( LT & item)
{

	return;
}

template <class LT>
void ArrayList<LT>::retrieveFromBack( LT & item)
{

	return;
}

template <class LT>
void ArrayList<LT>::retrieveFromLocation(int location, LT & item)
{
	if( location >= 0 && location < length)
		item = list[location];
	else
		cout << "Invalid subscript. Nothing was retrieved." << endl;
	return;
}

/////////////////////////////////////////////// Utility Functions

template <class LT>
int ArrayList<LT>::getMaxSize()
{
	return maxSize;
}

template <class LT>
int ArrayList<LT>::getLength()
{
	return length;
}

template <class LT>
bool ArrayList<LT>::isEmpty()
{
	return (length == 0);
}

template <class LT>
bool ArrayList<LT>::isFull()
{
	return (length == maxSize);
}

template <class LT>
void ArrayList<LT>::printList( )
{
	if( !isEmpty())
	{
		for( int i = 0 ; i < length ; i++)
			cout << list[i] << "   ";

		cout << "\n" << endl;
		return;
	}

	cout << "List is empty" << endl;
	return;
}

#endif





