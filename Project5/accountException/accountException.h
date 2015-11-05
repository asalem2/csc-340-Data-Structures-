/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
* Class:Hui Yang 340-01
* Date: October 29, 2014
* IDE/Compiler: Netbeans
* This is the header file for the accountException class that holds the initialize
* exceptions and accountException class with private and public data members
*/

#ifndef ACCOUNTEXCEPTION_H
#define	ACCOUNTEXCEPTION_H

#include <iostream>
#include <stdexcept>
#include "accountException.h"

using namespace std;

//This exception is thrown if a negative deposit is inputted
class Exception_Negative_Deposit : public exception{
public:
	virtual const char* what() const throw(){
		return "(INVALID INPUT) Cannot deposit negative amount of money!";
	}
};

//This exception is thrown if amount of withdraw is larger than the balance
class Exception_Overdraw : public exception{
public:
	virtual const char* what() const throw(){
		return "(OVERDRAW) You are trying to withdraw more money than what you have in your balance!";
	}
};

//This exception is thrown if a negative withdraw is inputted
class Exception_Negative_Withdraw : public exception{
public:
	virtual const char* what() const throw(){
		return "(INVALID INPUT) Cannot withdraw negative amount of money!";
	}
};

class accountException{
private:
	double balance;
public:
	//Default constructor
	accountException();
	//Default initialize constructor
	accountException(double initialDeposit);
	//Returns balance
	double getBalance();
	//Deposits amount that is given. Throws exceptions if amount is an invalid input
	double deposit(double amount)throw(Exception_Negative_Deposit);
	//Withdraws amount that is given. Throws exceptions if amount is an invalid input
	double withdraw(double amount)throw(Exception_Overdraw, Exception_Negative_Withdraw);
};

#endif	/* ACCOUNTEXCEPTION_H */

