#include <iostream>
#include <string>
using namespace std;
void word(int);
void drawup(int);
void draw(int);
void drawdown(int);
void re_for_add(int,string);
int main()
{
	int x;
	while (1)
	{
		word(1);
		cin>>x;
		if (x==0)
		exit(0);
		drawup(x);
		draw(x);
		drawdown(x);
	}

}
void word(int c)
{
	switch (c)
	{
	case 1:
		cout<<"Enter width(0 for exit): \n";
		break;

	}
}
void drawup(int w)
{
	w=w-1;
	int sp=0;
	for (int i=0;i<w;i++)
	{
		re_for_add(w-sp," ");
		re_for_add(sp+1,"* ");
		cout<<"\n";
		sp++;
	}
}
void draw(int w)
{
	re_for_add(w,"* ");
	cout<<"\n";
}
void drawdown(int w)
{
	w=w-1;
	int sp=0;
	for (int i=0;i<w;i++)
	{
		re_for_add(sp+1," ");
		re_for_add(w-sp,"* ");
		cout<<"\n";
		sp++;
	}
}
void re_for_add(int x,string y)
{
	for (int i=0;i<x;i++)
	cout<<y;
}