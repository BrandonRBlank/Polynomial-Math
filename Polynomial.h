//----------------------------------------------------------------------------------------------
// Brandon Blank
// 10/24/2016
//----------------------------------------------------------------------------------------------
// Polynomial.h
//----------------------------------------------------------------------------------------------
// Header file for Polynomial.cpp used in conjunction with main application
// PolynomialMath.cpp
//----------------------------------------------------------------------------------------------

#ifndef POLY_H
#define POLY_H

class Polynomial
{
	private:
	int *coeff;
	int *exp;
	
	public:
	Polynomial();
	Polynomial(int);
	void setTerm(int, int, int);
	int getCoeff(int);
	int getExp(int);
	Polynomial operator+(Polynomial&);
	Polynomial operator+=(Polynomial&);
	Polynomial operator-(Polynomial&);
	Polynomial operator-=(Polynomial&);
	Polynomial operator*(Polynomial&);
	Polynomial operator*=(Polynomial&);
	Polynomial operator==(Polynomial&);
	void printPoly();
	~Polynomial();
};

#endif
