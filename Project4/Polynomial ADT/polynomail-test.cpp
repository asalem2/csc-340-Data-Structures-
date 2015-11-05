/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: October 11, 2014
 * IDE/Compiler: Netbeans
 * This program is an ADT for polynomials that lets you do various commands to it
 */

#include <iostream>
#include <string>
#include "polynomial.h"

using namespace std;

int main() {
//Declaring variable the user needs to input to get program going
int choice = 1;
polynomial poly;
int terms;

//Ask user what they want to do
while(choice != 0){
    cout <<"\t\t\t\t\t\tChoose a command\n-------------------------------------------------------------------------------------------------------------------------------------------\n"
            " 1. Input a polynomial    2. Get degree    3. Display coefficient of a term    4. Change coefficient of a term   5. Multiply by scalar variable\n"
            " 6. Add polynomials    7. Print out polynomial   8. Divide Polynomial    9. Negate polynomial    10. Output polynomial to a output stream\n"
            " 0. To Exit\n Command: ";
    cin >> choice;
    
//Checks for errors if a command is invalid
while (choice < 0 || choice > 10){
    cout << "ERROR!\n Please choose a command between 0 - 10" <<endl;
    cout <<"\t\t\t\t\t\tChoose a command\n-------------------------------------------------------------------------------------------------------------------------------------------\n"
            " 1. Input a polynomial    2. Get degree    3. Display coefficient of a term    4. Change coefficient of a term   5. Multiply by scalar variable\n"
            " 6. Add polynomials    7. Print out polynomial   8. Divide Polynomial    9. Negate polynomial    10. Output polynomial to a output stream\n"
            " 0. To Exit\n Command: ";
    cin >> choice;
} 
//Here we go to our designated function via command
    if (choice == 1){
        //Ask user how many terms he will input into the polynomial
        cout << "How many terms are you going to input?: ";
                cin >> terms;
        poly.readpolynomial(terms);
    }
    else if(choice == 2){
        //Gets highest degree in polynomial
        cout << " Highest degree is " << poly.degree();
    }
    else if (choice == 3){
        //This function get the coefficient given the users power
        int degree;
        cout << " Of what degree is the coefficient you want to see?: ";
            cin >> degree;
        while(degree == 0 || degree == 1){
            cout <<"Invalid power!" << endl;
            cout << " Of what degree is the coefficient you want to see?: ";
            cin >> degree;
        }
            if(poly.getcoefficient(degree)== 0){
                cout << "That degree doesnt have a coefficient or is not in this polynomial"<<endl;
            }
            else
             cout << " The coefficient of that power is " << poly.getcoefficient(degree);
    }
    else if(choice == 4){
        //Changes coefficient of a certain degree
        int newCoefficient;
        int power;
        cout << " What degree does the coefficient you want to change have?: ";
            cin >> power;
        while(power == 0 || power == 1){
            cout <<"Invalid power!" << endl;
            cout << " What degree does the coefficient you want to change have?: ";
            cin >> power;
        }
        cout << " What number would you like to replace the coefficient with?: ";
            cin >> newCoefficient;
        poly.changeCoefficient(newCoefficient, power); 
    }
    else if(choice == 5){
        //This function multiplies polynomial by a scalar variable
        int value;
        cout << "By what value would you like to multiply by?: ";
            cin >> value;
        poly.multiplys(terms, value);
    }
    else if (choice == 6){
        //Function adds two polynomials
        poly.add(terms);
    }
    else if(choice == 7){
        //Function prints out the polynomial
        poly.printpolynomial(terms);
    }
    else if(choice == 8){
        //Divides polynomial by scalar variable
        int value;
         cout << "By what value would you like to divide by?: ";
         cin >> value;
        poly.operator /(value);
    }
    else if(choice == 9){
        //Negates polynomial
        poly.operator-(terms);
       
    }
    else if(choice == 10){
       //Function prints out the polynomial
       poly.printpolynomial(terms);
    }
}     
    //Lets user know that the program has been ended
    cout << "--------------------------\nProgram Terminated\nGoodbye!";
    return 0;
}

