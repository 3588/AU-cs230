#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <cassert>

template <class LT>
class ArrayList
{
public:
	ArrayList( int size = 100);
	void insertAtFront( const LT & );
	void insertAtBack( const LT & );
	void insertAtLocation( int , const LT & );
	void removeFromFront( LT &);
	void removeFromBack( LT &);
	void removeFromLocation( int , LT &);		// To be coded by students
	void modifyElementAtFront( const LT &);		// To be coded by students  
	void modifyElementAtBack( const LT &);		// To be coded by students
	void modifyElementAtLocation( int , const LT &);
	void retrieveFromFront( LT &);				// To be coded by students
	void retrieveFromBack( LT &);				// To be coded by students
	void retrieveFromLocation(int , LT &);
	int  getMaxSize();
	int  getLength();
	bool isEmpty();
	bool isFull();
	void printList();
	~ArrayList();

private: 
	LT * list;
	int length;
	int maxSize;
};

#include "ArrayList.cpp"

#endif