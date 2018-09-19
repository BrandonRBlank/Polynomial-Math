//----------------------------------------------------------------------------------------------
// Brandon Blank
// 10/24/2016
//----------------------------------------------------------------------------------------------
// Polynomial.cpp
//----------------------------------------------------------------------------------------------
// Implimentation file for Polynomial.h. Contains all function definitions regarding
// polynomial math operations with overloaded operators
//----------------------------------------------------------------------------------------------

#include <iostream>
#include "Polynomial.h"

using namespace std;

int MAX_POLY = 10;

//---------------------------------------------------------
//	Polynomial():	A defualt polynomial constuctor given
//					no parameters, creates a ten term
//					polynomial with zero for all terms
//---------------------------------------------------------
Polynomial::Polynomial()
{
	coeff = new int[MAX_POLY];
	exp = new int [MAX_POLY];
	for(int i = 0; i < MAX_POLY; i++)
	{
		coeff[i] = 0;
		exp[i] = 0;
	}
}

//---------------------------------------------------------
//	Polynomial(int):	Polynomial constuctor takes in
//						user desired number of terms in
//						the polynomial and fills rest of
//						polynomial array with zero 
//						coefficients and exponents
//---------------------------------------------------------
Polynomial::Polynomial(int len)
{
	exp = new int[MAX_POLY];
	coeff = new int[MAX_POLY];
	for(int i = 0; i < MAX_POLY; i++)
    {
        coeff[i] = 0;
        exp[i] = 0;
    }
}

//---------------------------------------------------------
//	setTerm:	Takes in coefficient, exponent, and term
//				location and assigns them to their 
//				proper location in the polynomial array
//---------------------------------------------------------
void Polynomial::setTerm(int newCoeff, int newExp, int i)
{
	coeff[i] = newCoeff;
	exp[i] = newExp;
}

//---------------------------------------------------------
//	getCoeff:	Takes in term location and returns coefficient
//---------------------------------------------------------
int Polynomial::getCoeff(int i)
{
	return coeff[i];
}

//---------------------------------------------------------
//	getExp:		Takes in term location and returns exponent
//---------------------------------------------------------
int Polynomial::getExp(int i)
{
	return exp[i];
}

//---------------------------------------------------------
//	operator+:	Overloaded addition operator adds two
//				polynomial objects and returns a new
//				polynomial object
//---------------------------------------------------------
Polynomial Polynomial::operator+(Polynomial &polyR)
{
	Polynomial temp;
	
	int tempCoeff;
	int size;		//Basically number of terms in polynomial
	int term;		//Which side of operator is not to be added (No matching exponent)
	int j = 0;
	int k = 0;		//k used as timing
	
	//Determine which polynomial exponent is higher to start arithmetic operations on
	if(this->getExp(0) > polyR.getExp(0))
		size = this->getExp(0);
	else
		size = polyR.getExp(0);
	
	//For loop runs from highest exponent to x^0
	for(int i = 0; k < size + 1; i++)
	{
		//Determines which side of operator has higher exponent
		if(this->getExp(i) > polyR.getExp(j))
			term = 1;
		else
			term = 0;
		
		//If exponents are equal, it adds coefficients
		if(this->getExp(i) == polyR.getExp(j))
		{
			tempCoeff = this->getCoeff(i) + polyR.getCoeff(j);
			temp.setTerm(tempCoeff, this->getExp(i), k);
			j++;
		}
		//Otherwise if the left operand has a larger exponent, it saves coefficient
		else if(term == 1)
		{
			tempCoeff = this->getCoeff(i);
			temp.setTerm(tempCoeff, this->getExp(i), k);
		}
		//Otherwise right operand coefficient is stored
		else
		{
			tempCoeff = polyR.getCoeff(j);
			temp.setTerm(tempCoeff, polyR.getExp(j), k);
			j++;
			i--;
		}
		k++;
	}
	return temp;
}

//---------------------------------------------------------
//	operator+=:	Overloaded '+=' operator adds two
//				polynomial objects and returns the result
//				into left-hand polynomial
//---------------------------------------------------------
Polynomial Polynomial::operator+=(Polynomial &polyR)
{
	Polynomial temp;
	
	int *arrCoeff;
	int *arrExp;
	int tempCoeff;
	int size;
	int term;
	int j = 0;
	int k = 0;
	
	arrCoeff = new int[MAX_POLY];	//Temp array to store coefficient
	arrExp = new int[MAX_POLY];		//Temp array to store exponent
	
	//Determine which polynomial's exponent is higher to start arithmetic operations on
	if(this->getExp(0) > polyR.getExp(0))
		size = this->getExp(0);
	else
		size = polyR.getExp(0);
	
	//For loop sorts and adds coefficients
	for(int i = 0; k < size + 1; i++)
	{
		//Determine which side of operator has higher exponent
		if(this->getExp(i) > polyR.getExp(j))
			term = 1;
		else
			term = 0;
		
		//If exponents are equal, it adds coefficients
		if(this->getExp(i) == polyR.getExp(j))
		{
			tempCoeff = this->getCoeff(i) + polyR.getCoeff(j);
			arrCoeff[k] = tempCoeff;
			arrExp[k] = this->getExp(i);
			j++;
		}
		else if(term == 1)
		{
			tempCoeff = this->getCoeff(i);
			arrCoeff[k] = tempCoeff;
			arrExp[k] = this->getExp(i);
		}
		else
		{
			tempCoeff = polyR.getCoeff(j);
			arrCoeff[k] = tempCoeff;
			arrExp[k] = polyR.getExp(j);
			j++;
			i--;
		}
		k++;
	}
	
	//Sets the sum of the two polynomials from the temp arrays into left-hand operand
	for(int i = 0; i < size + 1; i++)
		{
			this->setTerm(arrCoeff[i], arrExp[i], i);
		}
	
	//returns left-hand operand
	return *this;
}

//---------------------------------------------------------
//	operator-:	Overloaded subtraction operator subtracts 
//				two	polynomial objects and returns a new
//				polynomial object
//				*(Same as addition in everyway, but subtracts)
//---------------------------------------------------------
Polynomial Polynomial::operator-(Polynomial &polyR)
{
	Polynomial temp;
	
	int tempCoeff;
	int size;
	int term;
	int j = 0;
	int k = 0;
	
	if(this->getExp(0) > polyR.getExp(0))
		size = this->getExp(0);
	else
		size = polyR.getExp(0);
	
	for(int i = 0; k < size + 1; i++)
	{
		if(this->getExp(i) > polyR.getExp(j))
			term = 1;
		else
			term = 0;
		
		if(this->getExp(i) == polyR.getExp(j))
		{
			tempCoeff = this->getCoeff(i) - polyR.getCoeff(j);
			temp.setTerm(tempCoeff, this->getExp(i), k);
			j++;
		}
		else if(term == 1)
		{
			tempCoeff = this->getCoeff(i);
			temp.setTerm(tempCoeff, this->getExp(i), k);
		}
		else
		{
			tempCoeff = polyR.getCoeff(j);
			temp.setTerm(tempCoeff, polyR.getExp(j), k);
			j++;
			i--;
		}
		k++;
	}
	return temp;
}

//---------------------------------------------------------
//	operator-=:	Overloaded '-=' operator subtracts two
//				polynomial objects and returns the result
//				into the left-hand polynomial
//				*(Same as '+=' in everyway, but subrtacts)
//---------------------------------------------------------
Polynomial Polynomial::operator-=(Polynomial &polyR)
{
	Polynomial temp;
	
	int *arrCoeff;
	int *arrExp;
	int tempCoeff;
	int size;
	int term;
	int j = 0;
	int k = 0;
	
	arrCoeff = new int[MAX_POLY];
	arrExp = new int[MAX_POLY];
	
	if(this->getExp(0) > polyR.getExp(0))
		size = this->getExp(0);
	else
		size = polyR.getExp(0);
	
	for(int i = 0; k < size + 1; i++)
	{
		if(this->getExp(i) > polyR.getExp(j))
			term = 1;
		else
			term = 0;
		
		if(this->getExp(i) == polyR.getExp(j))
		{
			tempCoeff = this->getCoeff(i) - polyR.getCoeff(j);
			arrCoeff[k] = tempCoeff;
			arrExp[k] = this->getExp(i);
			j++;
		}
		else if(term == 1)
		{
			tempCoeff = this->getCoeff(i);
			arrCoeff[k] = tempCoeff;
			arrExp[k] = this->getExp(i);
		}
		else
		{
			tempCoeff = polyR.getCoeff(j);
			arrCoeff[k] = tempCoeff;
			arrExp[k] = polyR.getExp(j);
			j++;
			i--;
		}
		k++;
	}
	
	for(int i = 0; i < size + 1; i++)
		{
			this->setTerm(arrCoeff[i], arrExp[i], i);
		}
	
	return *this;
}

//---------------------------------------------------------
//	operator*:	Overloaded multiplication operator multiplies 
//				two polynomial objects and returns a new
//				polynomial object
//---------------------------------------------------------
Polynomial Polynomial::operator*(Polynomial &polyR)
{
	Polynomial temp;	//Holds all terms after FOIL method
	Polynomial temp2;	//Holds terms after FOIL method and after the addition of like terms
	
	int tempCoeff;
	int tempExp;
	int size1;
	int size2;
	int term;			//If '1': left-hand polynomial has more terms
						//If '0': right-hand polynomial has more terms
	int k = 0;
	int j = 0;
	
	//Determines which side of operator is longer
	if(this->getExp(0) > polyR.getExp(0))
	{
		size1 = this->getExp(0);
		size2 = polyR.getExp(0);
		term = 1;
	}
	else
	{
		size1 = polyR.getExp(0);
		size2 = this->getExp(0);
		term = 0;
	}
	
	//Left-hand polynomial has more terms and FOIL method is performed properly
	if(term == 1)
	{
		for(int i = 0; i < size1 + 1; i++)
		{
			for(int j = 0; j < size2 + 1; j++)
			{
				tempCoeff = this->getCoeff(i) * polyR.getCoeff(j);
				tempExp = this->getExp(i) + polyR.getExp(j);
				temp.setTerm(tempCoeff, tempExp, k);
				k++;
			}
		}
	}
	//Right-hand polynomial has more terms
	else
	{
		for(int i = 0; i < size1 + 1; i++)
		{
			for(int j = 0; j < size2 + 1; j++)
			{
				tempCoeff = this->getCoeff(j) * polyR.getCoeff(i);
				tempExp = this->getExp(j) + polyR.getExp(i);
				temp.setTerm(tempCoeff, tempExp, k);
				k++;
			}
		}
	}
	
	//For loop adds all like terms after FOIL method and stores in new polynomial object
	for(int i = 0; i < k; i++)
	{
		if(temp.getExp(i) == temp.getExp(i + 1))
		{
			tempCoeff = temp.getCoeff(i) + temp.getCoeff(i + 1);
			tempExp = temp.getExp(i);
			temp2.setTerm(tempCoeff, tempExp, j);
			i++;
			j++;
		}
		else
		{
			tempCoeff = temp.getCoeff(i);
			tempExp = temp.getExp(i);
			temp2.setTerm(tempCoeff, tempExp, j);
			j++;
		}
	}
	
	return temp2;
}

//---------------------------------------------------------
//	operator*=:	Overloaded '*=' operator multiplies two
//				polynomial objects and returns the product
//				of the two in the left-hand polynomial
//				*(Works just like the multiplication operator, but only has one temp object
//				and returns the product into the left-hand polynomial)
//---------------------------------------------------------
Polynomial Polynomial::operator*=(Polynomial &polyR)
{
	Polynomial temp;
	
	int tempCoeff;
	int tempExp;
	int size1;
	int size2;
	int term;
	int k = 0;
	int j = 0;
	
	if(this->getExp(0) > polyR.getExp(0))
	{
		size1 = this->getExp(0);
		size2 = polyR.getExp(0);
		term = 1;
	}
	else
	{
		size1 = polyR.getExp(0);
		size2 = this->getExp(0);
		term = 0;
	}
	
	if(term == 1)
	{
		for(int i = 0; i < size1 + 1; i++)
		{
			for(int j = 0; j < size2 + 1; j++)
			{
				tempCoeff = this->getCoeff(i) * polyR.getCoeff(j);
				tempExp = this->getExp(i) + polyR.getExp(j);
				temp.setTerm(tempCoeff, tempExp, k);
				k++;
			}
		}
	}
	else
	{
		for(int i = 0; i < size1 + 1; i++)
		{
			for(int j = 0; j < size2 + 1; j++)
			{
				tempCoeff = this->getCoeff(j) * polyR.getCoeff(i);
				tempExp = this->getExp(j) + polyR.getExp(i);
				temp.setTerm(tempCoeff, tempExp, k);
				k++;
			}
		}
	}
		
	for(int i = 0; i < k; i++)
	{
		if(temp.getExp(i) == temp.getExp(i + 1))
		{
			tempCoeff = temp.getCoeff(i) + temp.getCoeff(i + 1);
			tempExp = temp.getExp(i);
			this->setTerm(tempCoeff, tempExp, j);
			i++;
			j++;
		}
		else
		{
			tempCoeff = temp.getCoeff(i);
			tempExp = temp.getExp(i);
			this->setTerm(tempCoeff, tempExp, j);
			j++;
		}
	}
	
	return *this;
}

//---------------------------------------------------------
//	operator==:	Overloaded operator assigns the right-hand
//				polynomial to the left-hand polynomial
//---------------------------------------------------------
Polynomial Polynomial::operator==(Polynomial &polyR)
{
	int tempCoeff;
	int tempExp;

	for(int i = 0; i < MAX_POLY; i++)
	{
		tempCoeff = polyR.getCoeff(i);
		tempExp = polyR.getExp(i);
		
		this->setTerm(tempCoeff, tempExp, i);
	}	
	return *this;
}

//---------------------------------------------------------
//	printPoly():	Prints a polynomial object (Excludes
//					exponent for exponents equaling 1, and 
//					if the exponent is zero, excludes variable)
//---------------------------------------------------------
void Polynomial::printPoly()
{
	//Runs the whole polynomial
	for(int i = 0; i < MAX_POLY; i++)
	{
		//If the coefficient is not zero, it will print
		if(coeff[i] != 0)
		{
			//If the exponent is zero, it only prints the coefficient
			if(exp[i] == 0)
			{
				cout << coeff[i];
			}
			//Otherwise it print the whole term
			else
			{
				cout << coeff[i] << "x";
				//Exponents of one are not printed
				if(exp[i] != 1)
				{
					cout << "^" << exp[i];
				}
				
				//No '+' sign if its the end of the polynomial
				if(i != MAX_POLY - 1 && coeff[i + 1] != 0)
				{
					cout << " + ";
				}
			}
		}	
	}
	cout << endl;
}

//---------------------------------------------------------
//	Polynomial destructor	
//---------------------------------------------------------
Polynomial::~Polynomial()
{
	
}
