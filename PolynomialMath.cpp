//----------------------------------------------------------------------------------------------
// Brandon Blank
// 10/24/2016
//----------------------------------------------------------------------------------------------
// PolynomialMath.cpp
//----------------------------------------------------------------------------------------------
// Has user create two polynomials and performs addition, subtraction, and multiplication
// operations on the two polynomials and displays them
//----------------------------------------------------------------------------------------------

#include <iostream>
#include "Polynomial.h"

using namespace std;

int main(void)
{	
	int terms;
	int coeff;
	int exp;
	
	cout << "Enter two polynomials: " << endl;
	
	cout << "Enter number of terms in first polynomial: ";
	cin >> terms;
	cout << endl;
	
	Polynomial* poly_01 = new Polynomial(terms);
	
	//First polynomial assignment
	for(int j = 0; j < terms; j++)
	{
		cout << "Enter coefficient: ";
		cin >> coeff;
		
		cout << "Enter exponent: ";
		cin	>> exp;
		cout << endl;
		
		poly_01->setTerm(coeff, exp, j);
	}
	
	cout << "Enter number of terms in second polynomial: ";
	cin >> terms;
	cout << endl;
	
	Polynomial* poly_02 = new Polynomial(terms);
	
	//Second polynomial assignment
	for(int j = 0; j < terms; j++)
	{
		cout << "Enter coefficient: ";
		cin >> coeff;
		
		cout << "Enter exponent: ";
		cin	>> exp;
		cout << endl;
		
		poly_02->setTerm(coeff, exp, j);
	}
	
	cout << "First polynomial is: " << endl;
	poly_01->printPoly();
	
	cout << "Seconds polynomial is: " << endl;
	poly_02->printPoly();

	Polynomial* poly_03 = new Polynomial();
	
	cout << "The sum of the two polynomials is: " << endl;
	*poly_03 = (*poly_01) + (*poly_02);
	poly_03->printPoly();	
	*poly_03 == *poly_01;
	
	cout << "The '+=' of the two polynomials is: " << endl;
	(*poly_01) += (*poly_02);
	poly_01->printPoly();	
	*poly_01 == *poly_03;
	
	cout << "The difference of the two polynomials is: " << endl;
	*poly_03 = (*poly_01) - (*poly_02);
	poly_03->printPoly();
	*poly_03 == *poly_01;
	
	cout << "The '-=' of the two polynomials is: " << endl;
	(*poly_01) -= (*poly_02);
	poly_01->printPoly();	
	*poly_01 == *poly_03;
	
	cout << "The product of the two polynomials is: " << endl;
	*poly_03 = (*poly_01) * (*poly_02);
	poly_03->printPoly();
	*poly_03 == *poly_01;
	
	cout << "The '*=' of the two polynomials is: " << endl;
	(*poly_01) *= (*poly_02);
	poly_01->printPoly();	
	*poly_01 == *poly_03;
	
	return 0;
}
