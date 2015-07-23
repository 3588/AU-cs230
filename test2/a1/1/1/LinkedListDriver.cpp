#include <iostream>
#include "LinkedList.h"
using namespace std;
void put_data(LinkedList<int> &);
int main()
{
	int del,y;
	LinkedList<int> myList;
	LinkedList<int> otherList;
	put_data(myList);
	myList.divideAt(otherList,18,del);
	cout<<"OtherList\n";
	otherList.printList();
	cout<<"\nmylist\n";
	for (int i=0;i<del-1;i++)
	myList.removeFromBack(y);

	myList.printList();
	return 0;
} 
void put_data(LinkedList<int> &myl)
{
	int data[7]={34,65,18,39,27,89,12};
	for (int i=0;i<7;i++)
		myl.insertAtBack(data[i]);
}