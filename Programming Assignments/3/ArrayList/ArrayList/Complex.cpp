#include "Complex.h"

Complex::Complex( int a, int b)
{
	realPart = a;
	imaginaryPart = b;
}

void Complex::setRealPart( int a)
{
	realPart = a;
	return;
}

void Complex::setImaginaryPart( int b)
{
	imaginaryPart = b;
	return;
}

int Complex::getRealPart()
{
	return realPart;
}

int Complex::getImaginaryPart()
{
	return imaginaryPart;
}

void Complex::addComplex( Complex x)
{
	realPart += x.realPart;
	imaginaryPart += x.imaginaryPart;

	return;
}

void Complex::subtractComplex( Complex x)
{
	realPart -= x.realPart;
	imaginaryPart -= x.imaginaryPart;

	return;
}

void Complex::printComplex()
{
	if( imaginaryPart > 0)
		cout << realPart << " + " << imaginaryPart << "i" << endl;
	else if( imaginaryPart == 0)
		cout << realPart << endl;
	else
		cout << realPart << " - " << -imaginaryPart << "i" << endl;
}

Complex& Complex::operator= ( Complex right)
{
	if( &right != this)
	{
		realPart = right.realPart;
		imaginaryPart = right.imaginaryPart;
	}

	return *this;
}

/*
bool Complex::operator == ( Complex right)
{
	return( (realPart == right.realPart) && (imaginaryPart == right.imaginaryPart));
}

bool Complex::operator != ( Complex right)
{
	return( (realPart != right.realPart) || (imaginaryPart != right.imaginaryPart));
}


Complex& Complex::operator + ( Complex right)
{
	realPart = realPart + right.realPart;
	imaginaryPart = imaginaryPart + right.imaginaryPart;

	return *this;
}
*/