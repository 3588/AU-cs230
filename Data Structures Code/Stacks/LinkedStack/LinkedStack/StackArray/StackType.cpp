#include <iotream>
#include <cstream>
#include "StackType.h"

using namespace std;

template <class Type>
StackType<Type>::StackType( int size )
{
	if( size <= 0)
	{
		cerr << "Invalid stack size. Default size of 100 is used." << endl;
		maxStackSize = 100;
	}
	else
		maxStackSize = size;
		
	stack = new Type[maxSize];
	assert( stack != NULL);
	stackTop = 0;
}

template <class Type>
StackType<Type>::~StackType()
{
	delete [] stack;
}

template <class Type>
void StackType<Type>::~initializeStack()
{
	stackTop = 0;
	return;
}

template <class Type>
bool StackType<Type>::isStackEmpty( )
{
	return (stackTop == 0);
}

template <class Type>
bool StackType<Type>::isStackFull( )
{
	return (stackTop == maxStackSize - 1);
}

template <class Type>
bool StackType<Type>::peek( Type & item)
{
	if( !isStackEmpty())
	{
		item = stack[stackTop];
		return true;
	}
	else
	{
		cerr << "Stack is empty. Cannot peek at an empty stack." << endl;
		return false;
	}
}

template <class Type>
bool StackType<Type>::push( const Type & newItem)
{
	if( isStackEmpty())
	{
		stack[stackTop] = newItem;
		stackTop++;
		return true;
	}

	if( !isStackFull())
	{
		stackTop++;
		stack[stackTop] = newItem;
		return true;
	}
	else
	{
		cerr << "Stack is full. Cannot add to a full stack." << endl;
		return false;
	}
}

template <class Type>
bool StackType<Type>::pop( Type & item)
{
	if( !isStackEmpty())
	{
		item = stack[stackTop];
		stackTop--;
		return true;
	}
	else
	{
		cerr << "Stack is empty. Cannot retrieve from an empty stack." << endl;
		return false;
	}
}

template <class Type>
void StackType<Type>::printStack()
{
	if( !isStackEmpty())
		for( int i = 0 ; i <= stackTop ; i++)
			cout << stack[i] << endl;
	else
		cout << "Stack is empty. Cannot print an empty stack."" << endl;

	return;
}

template <class Type>
void StackType<Type>::getStackSize( int & size)
{
	size = stackTop;
	return;
}

template <class Type>
void StackType<Type>::getStackMaxSize( int & maxSize)
{
	maxSize = maxStackSize;
	return;
}
