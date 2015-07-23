#include <iostream>
#include "polynomial.h"
#include <fstream>
#include <vector>
using namespace std;
void word(int);
void get_data(poly&,poly&,poly&,poly&);
void put_data(poly,poly,poly,poly);
void evaluate(poly,poly,poly,poly);
void add_data(poly,poly,poly,poly);
void subtract_data(poly,poly,poly,poly);
void multiply_data(poly,poly,poly,poly);

vector <int> v1, v2;

int main()
{
	poly t1,t2,t3,t4;
	int choose;
	while (1)
	{
		word(1);
		cin>>choose;
		switch (choose)
		{
		case 1:
			get_data(t1,t2,t3,t4);
			break;
		case 2:
			put_data(t1,t2,t3,t4);
			get_data(t1,t2,t3,t4);
			break;
		case 3:
			evaluate(t1,t2,t3,t4);
			get_data(t1,t2,t3,t4);
			break;
		case 4:
			add_data(t1,t2,t3,t4);
			get_data(t1,t2,t3,t4);
			break;
		case 5:
			subtract_data(t1,t2,t3,t4);
			get_data(t1,t2,t3,t4);
			break;
		case 6:
			multiply_data(t1,t2,t3,t4);
			get_data(t1,t2,t3,t4);
			break;
		case 7:
			exit(7);
			break;
		}
	}
return 0;
}
void word(int choose)
{
	switch (choose)
	{
	case 1:
		cout<<"===============================\n"
			   <<"1.Get data from input.txt .\n"
			   <<"2.Show the polynomial.\n"
			   <<"3.Evaluate a polynomial at a given value.\n"
			   <<"4.Add two polynomials. \n"
			   <<"5.Subtract two polynomials. \n"
			   <<"6.Multiply two polynomials. \n"
			      <<"7.Exit. \n"
			   <<"===============================\n";
			break;
	case 4:
		cout<<"Polynomial x Add Polynomial y:\nplease enter x:";
		break;
	case 41:
		cout<<"Please enter y:";
		break;
	case 5:
		cout<<"Polynomial x Subtract Polynomial y:\nplease enter x:";
		break;
	case 6:
		cout<<"Polynomial x Multiply Polynomial y:\nplease enter x:";
		break;
	}
	
}
void get_data(poly& t1,poly& t2,poly& t3,poly& t4)
{
	ifstream in;
	in.open("input.txt");
	int next=1;
	vector <int> v1_1,v1_2;
	vector <int> v2_1,v2_2;
	vector <int> v3_1,v3_2;
	vector <int> v4_1,v4_2;
	while (!in.eof())
	{
	while (next)
		{	
			int x,y;
			char ch_t;
			in>>x;
			in>>y;
			in.get(ch_t);
			if (ch_t=='\n')
			{
				v1_1.push_back(x);
				v1_2.push_back(y);
				next=0;
			}
			else
			{
				v1_1.push_back(x);
				v1_2.push_back(y);
			}
		}
		next=1;
		while (next)
		{	
			int x,y;
			char ch_t;
			in>>x;
			in>>y;
			in.get(ch_t);
			if (ch_t=='\n')
			{
				v2_1.push_back(x);
				v2_2.push_back(y);
				next=0;
			}
			else
			{
				v2_1.push_back(x);
				v2_2.push_back(y);
			}
		}
		next=1;
		while (next)
		{	
			int x,y;
			char ch_t;
			in>>x;
			in>>y;
			in.get(ch_t);
			if (ch_t=='\n')
			{
				v3_1.push_back(x);
				v3_2.push_back(y);
				next=0;
			}
			else
			{
				v3_1.push_back(x);
				v3_2.push_back(y);
			}
		}
		next=1;
		while (next)
		{	
			int x,y;
			char ch_t;
			in>>x;
			in>>y;
			in.get(ch_t);
			if (ch_t=='\n')
			{
				v4_1.push_back(x);
				v4_2.push_back(y);
				next=0;
			}
			else
			{
				v4_1.push_back(x);
				v4_2.push_back(y);
			}
		}
	}
		t1.creat(v1_1,v1_2);
		t2.creat(v2_1,v2_2);
		t3.creat(v3_1,v3_2);
		t4.creat(v4_1,v4_2);
	in.close();
}
void put_data(poly t1,poly t2,poly t3,poly t4)
{
cout<<"Polynomial 1 "<<t1<<"\n"
	   <<"Polynomial 2 "<<t2<<"\n"
	   <<"Polynomial 3 "<<t3<<"\n"
	   <<"Polynomial 4 "<<t4<<"\n";
}
void evaluate(poly t1,poly t2,poly t3,poly t4)
{
	cout<<"enter the x: ";
	double x;
	cin>>x;
put_data(t1,t2,t3,t4);
get_data(t1,t2,t3,t4);
cout<<"after evaluate\n";
cout<<"f1 ( "<<x<<" ) ";
t1.evaluate(t1,x);
cout<<"f2 ( "<<x<<" ) ";
t2.evaluate(t2,x);
cout<<"f3 ( "<<x<<" ) ";
t3.evaluate(t3,x);
cout<<"f4 ( "<<x<<" ) ";
t4.evaluate(t4,x);
}
void add_data(poly t1,poly t2,poly t3,poly t4)
{
	poly p1,p2;
	put_data(t1,t2,t3,t4);
	get_data(t1,t2,t3,t4);
	word(4);
	int x,y;
	cin>>x;
	word(41);
	cin>>y;
	switch (x)
	{
	case 1:
		p1=t1;
		break;
	case 2:
		p1=t2;
		break;
	case 3:
		p1=t3;
		break;
	case 4:
		p1=t4;
		break;
	}
	switch (y)
	{
	case 1:
		p2=t1;
		break;
	case 2:
		p2=t2;
		break;
	case 3:
		p2=t3;
		break;
	case 4:
		p2=t4;
		break;
	}
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
			aa.polyomial[i]=p2.polyomial[i];

		aa.len=p2.len;
	}
	cout<<p1<<" + "<<p2<<" = "<<aa<<endl;
}
void subtract_data(poly t1,poly t2,poly t3,poly t4)
{
	poly p1,p2;
	put_data(t1,t2,t3,t4);
	get_data(t1,t2,t3,t4);
	word(5);
	int x,y;
	cin>>x;
	word(41);
	cin>>y;
	switch (x)
	{
	case 1:
		p1=t1;
		break;
	case 2:
		p1=t2;
		break;
	case 3:
		p1=t3;
		break;
	case 4:
		p1=t4;
		break;
	}
	switch (y)
	{
	case 1:
		p2=t1;
		break;
	case 2:
		p2=t2;
		break;
	case 3:
		p2=t3;
		break;
	case 4:
		p2=t4;
		break;
	}
	poly aa;
	if(p1.len>p2.len)
	{ aa.polyomial=new int[p1.len];
	for(int i=0;i<p2.len;i++)
		aa.polyomial[i]=p1.polyomial[i]-p2.polyomial[i];
	for(int i=p2.len;i<p1.len;i++)
		aa.polyomial[i]=p1.polyomial[i];
	aa.len=p1.len;
	}
	else if(p1.len<p2.len)
	{ aa.polyomial=new int[p2.len];
	for(int i=0;i<p1.len;i++)
		aa.polyomial[i]=p1.polyomial[i]-p2.polyomial[i];
	for(int i=p1.len;i<p2.len;i++)
		aa.polyomial[i]=-p2.polyomial[i];
	aa.len=p2.len;
	}
	else
	{
		aa.polyomial=new int[p1.len];
		for(int i=0;i<p1.len;i++)
			aa.polyomial[i]=p1.polyomial[i]-p2.polyomial[i];
		aa.len=p1.len;
	}

	cout<<p1<<" - "<<p2<<" = "<<aa<<endl;
}
void multiply_data(poly t1,poly t2,poly t3,poly t4)
{
	poly p1,p2;
	put_data(t1,t2,t3,t4);
	get_data(t1,t2,t3,t4);
	word(6);
	int x,y;
	cin>>x;
	word(41);
	cin>>y;
	switch (x)
	{
	case 1:
		p1=t1;
		break;
	case 2:
		p1=t2;
		break;
	case 3:
		p1=t3;
		break;
	case 4:
		p1=t4;
		break;
	}
	switch (y)
	{
	case 1:
		p2=t1;
		break;
	case 2:
		p2=t2;
		break;
	case 3:
		p2=t3;
		break;
	case 4:
		p2=t4;
		break;
	}
	poly aa;

	aa.polyomial=new int[p1.len+p2.len-1];

	aa.len=p1.len+p2.len-1;
	for(int i=0;i<aa.len;i++)
		aa.polyomial[i]=0;
	for(int i=0;i<p2.len;i++)
	{
		for(int j=0;j<p1.len;j++)
		{
			if(0==i){ aa.polyomial[i+j]=p2.polyomial[i]*p1.polyomial[j];}
			else { aa.polyomial[i+j]=aa.polyomial[i+j]+p2.polyomial[i]*p1.polyomial[j];}
		}
	}

	cout<<p1<<" * "<<p2<<" = "<<aa<<endl;
}