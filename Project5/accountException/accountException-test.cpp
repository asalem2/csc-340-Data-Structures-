/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: October 29, 2014
 * IDE/Compiler: Netbeans
 * This program testes multiple cases that can throw exceptions to a balance of money
 */

#include <iostream>
#include <stdexcept>
#include "accountException.h"

using namespace std;

int main() {
    //Make an accountException object to test cases with initializer set to 50
    accountException object(50);
    
    //Output the balance
    cout << "Balance is $" << object.getBalance()<<endl;
    
    //Successful Deposit
    try{
    object.deposit(50);
    cout << "Deposit was successful! New balance is $" << object.getBalance()<<endl;
    }
    catch (exception& e){
        cerr << "Error - " << e.what() <<endl; 
    }
    
    //Test negative deposit error 
    try{
        object.deposit(-30);
    }
    catch (exception& e){
        cerr << "Error - " << e.what() <<endl; 
    }
    
    //Successful Withdraw
    try{
        object.withdraw(30);
        cout <<"Withdraw was successful! Your new balance is $"<<object.getBalance()<<endl;
    }
    catch(exception& e){
        cerr<<"Error - "<<e.what() << endl;
    }
    
    //Test overdraw exception
    try{
        object.withdraw(90);
    }
    catch(exception& e){
        cerr<<"Error - "<<e.what() << endl;
    }
    
    //Test negative withdraw exception
    try{
        object.withdraw(-60);
    }
    catch(exception& e){
        cerr<<"Error - "<< e.what();
    }
    
    return 0;
}

