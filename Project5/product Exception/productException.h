/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
* Class:Hui Yang 340-01
* Date: September 7, 2014
* IDE/Compiler: Netbeans
* This is the header file containing the exception class and the function to retrieve product id
*/

#ifndef PRODUCTEXCEPTION_H
#define	PRODUCTEXCEPTION_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//This exception is thrown if item is not found
class Exception_ID_Not_Found : public exception{
public:
	virtual const char* what() const throw(){
		return "Item was not found!";
	}
};

//Function returns the product id number. If its not found it throws an exception
int getProductID(int ids[], string names[], int numProducts, string target)throw(Exception_ID_Not_Found);

#endif	/* PRODUCTEXCEPTION_H */

