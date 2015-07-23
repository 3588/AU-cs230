#ifndef COMPLEX_NUMBERS
#define COMPLEX_NUMBERS

class ComplexType
{
private:
	double realPart;
	double imaginaryPart;
public:
	ComplexType();
	ComplexType( const double, const double);
	void setComplex( const double, const double);
	void setRealPart( const double);
	void setImaginaryPart( const double);
	void getComplex( double &, double &);
	void getRealPart( double &);
	void getImaginaryPart( double &);
	void Add( const ComplexType );
	void Subtract( const ComplexType );
	void Print( void);
};

#endif