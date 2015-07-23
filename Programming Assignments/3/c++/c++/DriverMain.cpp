#include <iostream>
#include "ArrayList.h"
#include "RationalNumber.h"

using namespace std;

ostream& operator<< (ostream&, RationalNumber );
istream& operator>> (istream&, RationalNumber& );
RationalNumber operator+ (RationalNumber,RationalNumber );
RationalNumber operator- (RationalNumber,RationalNumber );
RationalNumber operator* (RationalNumber,RationalNumber );
RationalNumber operator/ (RationalNumber,RationalNumber );
int main()
{

	//test class
	RationalNumber t,t1,t2;
	cout<<"********************************\n*******Class Test***************\n*Unmerator=35,Denominator=315\n";
	t1.SetNumerator(35);
	t1.SetDenominator(315);
	cout<<"GetNumerator() Beofre Reduced :"<<t1.GetNumerator()<<endl;
	cout<<"GetDenominator() Beofre Reduced :"<<t1.GetDenominator()<<endl;

	t1.ReducedForm();
	cout<<"GetNumerator() after Reduced :"<<t1.GetNumerator()<<endl;
	cout<<"GetDenominator() after Reduced :"<<t1.GetDenominator()<<endl;
	cout<<"The Reduced Form is:";t1.Printing1();
	cout<<"The Floating point format is: ";t1.Printing2();
	cout<<"\n\n\n********************************\n*******Driver Test***************\n";
	cout<<"input << operators\n enter 4 int ex:a/b  c/d";
	cin>>t1>>t2;
	cout<<"output >> operators";
	cout<<t1<<t2<<endl;
	cout<<"+ operator: ";
	t=t1+t2;
	cout<<t;
	cout<<"- operator: ";
	t=t1-t2;
	cout<<t;
	cout<<"* operator: ";
	t=t1*t2;
	cout<<t;
	cout<<"/ operator: ";
	t=t1/t2;
	cout<<t;
	cout<<"= operator(=first rational numbers): \n";
	t=t1;
	cout<<t;
	cout<<"\n\n*******ArrayList Test***************\n";

	ArrayList<RationalNumber> x;
	RationalNumber t3(12,50);
	x.insertAtFront(t3);
	x.printList();

	x.insertAtBack(t2);
	x.printList();

	x.insertAtBack(t);
	x.printList();
	cout<<"you have "<<x.getLength()<<" rational numbers\n";
	x.removeFromBack(t);
	cout<<"after remove you have "<<x.getLength()<<" rational numbers\n";
	x.printList();
	return 0;
}

ostream& operator<< (ostream& out, RationalNumber y)
{
	out<<"The Reduced Form is:";y.ReducedForm();y.Printing1();
	out<<"The Floating point format is: ";y.Printing2();
	return out;
}
istream& operator>> (istream& in, RationalNumber& y)
{
	int a, b;
	in>>a>>b;
	y.SetNumerator(a);
	y.SetDenominator(b);
	return in;
}
RationalNumber operator+ (RationalNumber n1,RationalNumber n2)
{
	RationalNumber t;
	int a=n1.GetNumerator(),b=n1.GetDenominator(),c=n2.GetNumerator(),d=n2.GetDenominator();
	t.SetNumerator(a*d+b*c);
	t.SetDenominator(b*d);
	t.ReducedForm();
	return t;
}

RationalNumber operator- ( RationalNumber n1,  RationalNumber n2)
{
	RationalNumber t;
	int a=n1.GetNumerator(),b=n1.GetDenominator(),c=n2.GetNumerator(),d=n2.GetDenominator();
	t.SetNumerator(a*d-b*c);
	t.SetDenominator(b*d);
	t.ReducedForm();
	return t;
}
RationalNumber operator* ( RationalNumber n1,  RationalNumber n2)
{
	RationalNumber t;
	int a=n1.GetNumerator(),b=n1.GetDenominator(),c=n2.GetNumerator(),d=n2.GetDenominator();
	t.SetNumerator(a*c);
	t.SetDenominator(b*d);
	t.ReducedForm();
	return t;
}
RationalNumber operator/ ( RationalNumber n1,  RationalNumber n2)
{
	RationalNumber t;
	int a=n1.GetNumerator(),b=n1.GetDenominator(),c=n2.GetNumerator(),d=n2.GetDenominator();
	t.SetNumerator(a*d);
	t.SetDenominator(b*c);
	t.ReducedForm();
	return t;
}