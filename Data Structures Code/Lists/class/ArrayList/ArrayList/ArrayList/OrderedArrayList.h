#ifndef ORDERED_ARRAY_LIST_H
#define ORDERED_ARRAY_LIST_H

#include "ArrayList.h"

template <class LT>
class OrderedArrayList : public ArrayList<LT>
{
public:
	OrderedArrayList(int); 
	void sort();
};

template <class LT>
OrderedArrayList<LT>::OrderedArrayList( int size)
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
void OrderedArrayList<LT>::sort()
{
	for( int pass = 1 ; pass < length ; pass++)
		for( int i = 0 ; i < length-1 ; i++)
			if( list[i] > list[i+1])
			{
				LT temp = list[i];
				list[i] = list[i+1];
				list[i+1] = temp;
			}
	return;
}


#endif;