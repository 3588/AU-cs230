#include <iostream>
#include<vector>
#include "StackComposition.h"
using namespace std;

int main()
{				   
	ComposedStack<char> stack;
	//get data
	vector<char> charlist;
	int onemore=1;
	char chardata;
	while(onemore)
	{
		cin>>chardata;
		if(chardata!='.')
			charlist.push_back(chardata);
		else
			onemore=0;
	}
	int charsize=charlist.size(),type_char=0;
	//choose type
	for(int i=0;i<charsize;i++)
	{
		if(charlist[i]=='*'||charlist[i]=='*')
			type_char=1;
		if(charlist[i]=='('||charlist==')')
			type_char=2;
	}
	if(type_char==0)
	{

	}

	for(int i=0;i<charsize;i++)
	{
		if((charlist[i]>='a'&&charlist[i]<='z')||(charlist[i]>='A'&&charlist[i]<='Z'))
			cout<<charlist[i];
		if(charlist[i]=='+'||charlist[i]=='-')
			stack.push(charlist[i]);
		if(charlist[i]=='*')
		{
			cout<<charlist[i+1];
			cout<<charlist[i];
		}
		if(charlist[i]=='/')
		{
			cout<<charlist[i+1];
			if(!stack.isStackEmpty())
			{
				stack.pop(chardata);
				cout<<chardata;
			}
		}

	}
	while(!stack.isStackEmpty())
			{
				stack.pop(chardata);
				cout<<chardata;
			}
	return 0;
}
