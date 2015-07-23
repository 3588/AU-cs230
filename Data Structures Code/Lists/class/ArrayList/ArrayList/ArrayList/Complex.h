#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex
{
public: 
	Complex( int = 0, int = 0);
	void setRealPart( int);
	void setImaginaryPart( int);
	int  getRealPart();
	int  getImaginaryPart();
	void addComplex( Complex );
	void subtractComplex( Complex );
	void printComplex();
	// Complex& operator+ ( Complex );
	// bool operator== ( Complex );
	// bool operator!= ( Complex );
	Complex& operator= ( Complex);

private:
	int realPart;
	int imaginaryPart;
};

#endif;
