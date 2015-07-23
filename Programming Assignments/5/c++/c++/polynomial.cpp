#include <iostream>
#include "polynomial.h"
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;
poly::poly()
{
	polyomial=NULL;
	len=0;
}
poly::~poly()
{
	delete [] polyomial;
}

void poly::creat(vector <int> v1,vector <int> v2)
{ 

int max=v2[0];
for(int i=1;i<v2.size();i++)
if(max<v2[i])max=v2[i];


polyomial=new int[max+1];
len=max+1;
for(int z=0;z<max+1;z++)
polyomial[z]=0;
for(int i=0;i<max+1;i++)
{
	for(int j=0;j<v1.size();j++)
	{if(i==v2[j])polyomial[i]=v1[j];

	}
}

}
void  poly::evaluate(const poly& p, double x)
{
	float y=0.0;
	for(int i=0;i<p.len;i++)
	{
		if (i==0)
		y=p.polyomial[i];
		else
	y=y+p.polyomial[i]*pow(x,i);
	}
	cout<<y<<endl;
}
/*
poly operator +(const poly& p1,const poly& p2)
{ 
	poly aa;
if(p1.len>p2.len)
{ 
	aa.polyomial=new int[p1.len];

for(int i=0;i<p2.len;i++)
aa.polyomial[i]=p1.polyomial[i]+p2.polyomial[i];

for(int i=p2.len;i<p1.len;i++)
aa.polyomial[i]=p1.polyomial[i];

aa.len=p1.len;
}
else
{ 
	aa.polyomial=new int[p2.len];
for(int i=0;i<p1.len;i++)
aa.polyomial[i]=p1.polyomial[i]+p2.polyomial[i];
for(int i=p1.len;i<p2.len;i++)
aa.polyomial[i]=p1.polyomial[i];
aa.len=p2.len;
}
return aa;
}

poly operator -(const poly& p1,const poly& p2)
{ poly a;
if(p1.len>p2.len)
{ a.polyomial=new int[p1.len];
for(int i=0;i<p2.len;i++)
a.polyomial[i]=p1.polyomial[i]-p2.polyomial[i];
for(int i=p2.len;i<p1.len;i++)
a.polyomial[i]=p1.polyomial[i];
a.len=p1.len;
}
else if(p1.len<p2.len)
{ a.polyomial=new int[p2.len];
for(int i=0;i<p1.len;i++)
a.polyomial[i]=p1.polyomial[i]-p2.polyomial[i];
for(int i=p1.len;i<p2.len;i++)
a.polyomial[i]=-p2.polyomial[i];
a.len=p2.len;
}
else
{
	a.polyomial=new int[p1.len];
	for(int i=0;i<p1.len;i++)
		a.polyomial[i]=p1.polyomial[i]-p2.polyomial[i];
	a.len=p1.len;
}
return a;
}

poly operator *(const poly& p1,const poly& p2)
{
	poly a;

	a.polyomial=new int[p1.len+p2.len-1];

	a.len=p1.len+p2.len-1;
	for(int i=0;i<a.len;i++)
		a.polyomial[i]=0;
	for(int i=0;i<p2.len;i++)
	{
		for(int j=0;j<p1.len;j++)
		{
			if(0==i){ a.polyomial[i+j]=p2.polyomial[i]*p1.polyomial[j];}
			else { a.polyomial[i+j]=a.polyomial[i+j]+p2.polyomial[i]*p1.polyomial[j];}
		}
	}
	return a;
}

*/
poly& poly:: operator =(const poly& p)
{ 
	len=p.len;
polyomial=new int[len];
for(int i=0;i<len;i++)
polyomial[i]=p.polyomial[i];
return (*this);

}



ostream& operator <<(ostream& outs,const poly& p)
{
	int n=0;
for(int i=0;i<p.len;i++)
if(p.polyomial[i]!=0)
{  n++;
if(1==n)
{
	if(0==i)
		outs<<p.polyomial[0];
	else 
		outs<<p.polyomial[i]<<"x^"<<i;
}
else
{

	if(0==i)
		outs<<p.polyomial[0];
	else 
		if(p.polyomial[i]>0)
		outs<<"+"<<p.polyomial[i]<<"x^"<<i;
		else 
		outs<<p.polyomial[i]<<"x^"<<i;
}
}
return outs;
}

