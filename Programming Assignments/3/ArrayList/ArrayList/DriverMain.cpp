#include <iostream>
#include "ArrayList.h"
#include "Complex.h"

using namespace std;

ostream& operator<< (ostream&, Complex );
istream& operator>> (istream&, Complex& );
Complex  operator+ ( Complex, Complex );
bool operator== ( Complex, Complex );
bool operator!= ( Complex, Complex );

int main()
{
/*
	int x;
	ArrayList<int> a(10);

	a.insertAtFront( 7);
	a.printList();

	a.insertAtFront( 15);
	
	a.insertAtBack( 9);
	a.printList();
	
	a.insertAtBack( 15);
	a.printList();
	
	a.insertAtLocation( 1, 8);
	a.printList();
	
	a.insertAtLocation( 1, 10);
	a.printList();

	// a.removeFromLocation( 3, x);
	// a.printList();

	a.removeFromFront( x);
	a.printList();

	a.removeFromBack( x);
	a.printList();
	
*/
	Complex a( 2, 3), b( 1, -5), c( 9, 0), d, e;

	a.printComplex();
	b.printComplex();
	c.printComplex();
	d.printComplex();

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

	d = a + c;
	cout << d << endl;

	if( a + c == d)
		cout << a + c << " = " << d << endl;
	else
		cout << a + c << " != " << d << endl;

	Complex g( 2, 3), h( 1, -5), m( 9, 0), j, k;
	ArrayList<Complex> x;

	cout << "Enter 2 integers: "<< endl;
	cin >> e; 
	x.insertAtFront( e);
	x.printList();

	x.insertAtBack( g);
	x.printList();

	x.insertAtBack( h);
	x.printList();

	x.insertAtFront( g + h);
	x.printList();

	return 0;
}

ostream& operator<< (ostream& output, Complex x)
{
	if( x.getImaginaryPart() > 0)
		output << x.getRealPart() << " + " << x.getImaginaryPart() << "i";
	else if( x.getImaginaryPart() == 0)
		output << x.getRealPart();
	else
		output << x.getRealPart() << " - " << -x.getImaginaryPart() << "i";

	return output;
}

istream& operator>> (istream& input, Complex& x)
{
	int a, b;

	input >> a >> b;
	x.setRealPart( a);
	x.setImaginaryPart( b);

	return input;
}

Complex operator+ ( Complex left, Complex right)
{
	int a, b;
	Complex z;

	a = left.getRealPart() + right.getRealPart();
	b = left.getImaginaryPart() + right.getImaginaryPart();
	z.setRealPart( a);
	z.setImaginaryPart( b);

	return z;
}

bool operator== ( Complex left, Complex right)
{
	return( (left.getRealPart() == right.getRealPart()) && 
			(left.getImaginaryPart() == right.getImaginaryPart()));
}

bool operator!= ( Complex left, Complex right)
{
	return( (left.getRealPart() != right.getRealPart()) || 
			(left.getImaginaryPart() != right.getImaginaryPart()));
}