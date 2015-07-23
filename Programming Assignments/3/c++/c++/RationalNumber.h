#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include <iostream>
using namespace std;
class RationalNumber
{
public:
	RationalNumber(int=0,int=0);
	void SetNumerator(int);
	void SetDenominator(int);
	int GetNumerator();
	int GetDenominator();
	void ReducedForm();// 2/4 =>  1/2;
	bool Reduced(int,int,int&);
	void Printing1();// a/b
	void Printing2();// floating point format
	RationalNumber& operator= ( RationalNumber);

	friend RationalNumber Add ( RationalNumber n1,RationalNumber n2);
	friend RationalNumber Sub ( RationalNumber n1,RationalNumber n2);
	friend RationalNumber Mul ( RationalNumber n1,RationalNumber n2);
	friend RationalNumber Div ( RationalNumber n1,RationalNumber n2);
	friend RationalNumber Rec ( RationalNumber n1);
private:
	int numerator;
	int denominator;
};
RationalNumber::RationalNumber(int x,int y)
{
	numerator=x;
	denominator=y;
}
void RationalNumber::SetNumerator(int x)
{
	numerator=x;
}
void RationalNumber::SetDenominator(int x)
{
	if(x!=0)
	{
		denominator=x;
	}
	else
	{
		cout<<"Denominator can't be 0\n\n";
	}
}
int RationalNumber::GetNumerator()
{
	return numerator;
}
int RationalNumber::GetDenominator()
{
	return denominator;
}
void RationalNumber::ReducedForm()// 2/4 =>  1/2;
{
	int c;
	while(Reduced(numerator,denominator,c))
	{
		numerator=numerator/c;
		denominator=denominator/c;
	}
}
bool RationalNumber::Reduced(int a,int b, int &c)
{
	if (a%2==0&&b%2==0)
	{
		c=2;
		return true;
	}
	if (a%3==0&&b%3==0)
	{
		c=3;
		return true;
	}
	if (a%5==0&&b%5==0)
	{
		c=5;
		return true;
	}
	if (a%7==0&&b%7==0)
	{
		c=7;
		return true;
	}
	return false;

}
void RationalNumber::Printing1()// a/b
{
	cout<<numerator<<"/"<<denominator<<endl;
}
void RationalNumber::Printing2()// floating point format
{
	cout.precision(2);
	float t1=numerator,t2=denominator;
	float t=t1/t2;
	cout<<t<<endl;
}

RationalNumber Add( RationalNumber n1, RationalNumber n2)
{
	RationalNumber t;
	t.numerator=(n1.numerator*n2.denominator)+(n1.denominator*n2.numerator);
	t.denominator=n1.denominator*n2.denominator;
	t.ReducedForm();
	return t;
}
RationalNumber Sub ( RationalNumber n1,  RationalNumber n2)
{
	RationalNumber t;
	t.numerator=(n1.numerator*n2.denominator)-(n1.denominator*n2.numerator);
	t.denominator=n1.denominator*n2.denominator;
	t.ReducedForm();
	return t;
}
RationalNumber Mul ( RationalNumber n1,  RationalNumber n2)
{
	RationalNumber t;
	t.numerator=n1.numerator*n2.numerator;
	t.denominator=n1.denominator*n2.denominator;
	t.ReducedForm();
	return t;
}
RationalNumber Div ( RationalNumber n1,  RationalNumber n2)
{
	RationalNumber t;
	t.numerator=n1.numerator*n2.denominator;
	t.denominator=n1.denominator*n2.numerator;
	t.ReducedForm();
	return t;
}
RationalNumber Rec ( RationalNumber n1)
{
	RationalNumber t;
	t.numerator=n1.denominator;
	t.denominator=n1.numerator;
	t.ReducedForm();
	return t;
}

RationalNumber& RationalNumber::operator= ( RationalNumber right)
{
	if( &right != this)
	{
		numerator = right.numerator;
		denominator = right.denominator;
	}

	return *this;
}
#endif