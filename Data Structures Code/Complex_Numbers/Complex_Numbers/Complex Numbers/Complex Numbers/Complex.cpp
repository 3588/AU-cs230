#include <iostream>
#include "Complex.h"

using namespace std;

ComplexType::ComplexType()
{
	realPart = 0;
	imaginaryPart = 0;
}

ComplexType::ComplexType( const double a, const double b)
{
	realPart = a;
	imaginaryPart = b;
}

void ComplexType::setComplex( const double a, const double b)
{
	realPart = a;
	imaginaryPart = b;

	return;
}

void ComplexType::setRealPart( const double a)
{
	realPart = a;

	return;
}

void ComplexType::setImaginaryPart( const double b)
{
	imaginaryPart = b;

	return;
}

void ComplexType::getComplex( double& a, double& b)
{
	a = realPart;
	b = imaginaryPart;

	return;
}

void ComplexType::getRealPart( double& a)
{
	a = realPart;

	return;
}

void ComplexType::getImaginaryPart( double& b)
{
	b = imaginaryPart;

	return;
}

void ComplexType::Add(const ComplexType a)
{
	realPart += a.realPart;
	imaginaryPart += a.imaginaryPart;

	return;
}

void ComplexType::Subtract(const ComplexType a)
{
	realPart -= a.realPart;
	imaginaryPart -= a.imaginaryPart;

	return;
}

void ComplexType::Print()
{
	cout << "\n( " << realPart << " , " << imaginaryPart << " )" << endl;

	return;
}