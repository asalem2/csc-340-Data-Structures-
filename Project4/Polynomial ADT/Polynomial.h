/* Ahmed Salem
* 910017087	
* ahmeds@mail.sfsu.edu
* Class:Hui Yang 340-01
* Date: October 11, 2014
* IDE/Compiler: Netbeans
* This is the header file for the polynomial ADT
*/

#ifndef POLYNOMIAL_H
#define	POLYNOMIAL_H

#include <iostream>
#include <string>
using namespace std;

class polynomial{
private:
	//Creates the private variables used for the polynomial
	int coefficient[20];
	string variable[20];
	int power[20];

public:
	//Constructor
	polynomial();

	//Functions for the ADT
	//reads user polynomial
	void readpolynomial(int &terms);
	//prints highest degree in polynomial
	int degree();
	//gets the coefficient of a certain power
	int getcoefficient(int degree);
	//changes the coefficient of the degree provided
	void changeCoefficient(int newCoefficient, int degree);
	//multiplies by scalar variable
	void multiplys(int terms, int value);
	//adds two polynomials
	void add(int &terms);
	//prints out the polynomial
	void printpolynomial(int termstoprint);

	//Overload operators
	//divides polynomial by scalar variable
	polynomial operator/(int value);
	//negates polynomial
	polynomial operator-(int terms);
};

#endif	/* POLYNOMIAL_H */

