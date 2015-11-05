/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu 
 * Class:Hui Yang 340-01
 * Date: October 29, 2014
 * IDE/Compiler: Netbeans
 * This is the implementation file for the header file accountException
 */

#include <iostream>
#include <stdexcept>
#include "accountException.h"

using namespace std;

//Initializes balance to 0
accountException::accountException(){
    balance = 0;
}

//Initializes balance to initialDeposit
accountException::accountException(double initialDeposit){
    balance = initialDeposit;
}

//Returns balance
double accountException::getBalance(){
    return balance;
}

//This function first checks to see if the amount is less than 0, if so we throw an exception
//else we modify the balance and return it
double accountException::deposit(double amount)throw(Exception_Negative_Deposit){
    Exception_Negative_Deposit e_neg;
    if (amount < 0)
        throw e_neg; // code indicating error
    else
        balance += amount;
	
    return balance; 
}

//This function first checks to see if the amount is greater than the balance if so we throw an exception
//else we check if the amount is less than 0, if so we throw an exception
//else we modify the balance and return it
double accountException::withdraw(double amount)throw(Exception_Overdraw,Exception_Negative_Withdraw){
    Exception_Overdraw e_over;
    Exception_Negative_Withdraw e_neg;
    if(amount > balance){
        throw e_over;
    }
    else if (amount < 0){
        throw e_neg;
    }
    else{
        balance -= amount;
    }
    
    return balance;
}
