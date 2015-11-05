/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: November 21, 2014
 * IDE/Compiler: Netbeans
 * This program testes my functions in the other RecurisiveADT file.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "RecursiveADT.h"

using namespace std;

int main() {
    //Variables we are going to use to test program
    RecursiveADT object;
    int nSize = 1000;
    int command;
    int userArray[nSize];
    
    //Checks for what command the user wants
    while (command != 5){
    cout << "                                                                     Choose a command\n"
            "1.Input Integers   2.Output out the array in reverse order   3.Output the largest number in the array   4.Output the k-th largest number in the array   5. Exit" << endl;
    cout << "Command: ";
    cin >> command;
    
    //Error if the command is out of range
    while (command < 1 || command > 5){
        cout <<"ERROR - Wrong input! Choose a command between 1-5" <<endl;
        cout << "                                                                     Choose a command\n"
            "1.Input Integers   2.Output out the array in reverse order   3.Output the largest number in the array   4.Output the k-th largest number in the array   5. Exit" << endl;
    cout << "Command: ";
    cin >> command;
    }
    
    //Ask user to enter their specific numbers
    if (command == 1){
        cout << "How many integers are you going to input?: ";
        cin >> nSize;
        
        //Error if the command is out of range
        while (nSize < 1 || nSize > 1000){
            cout << "Error - Choose a size between 1 - 1000" <<endl;;
            cout << "How many integers are you going to input?: ";
            cin >> nSize;
        }
        cout << "Enter your integers (eg: 23 12 43 223): ";
        for (int i = 0; i < nSize; i++)
            cin >> userArray[i];
        
        object.userArray(userArray, nSize);
    }
    
    //Outputs the array in reverse order
    if (command == 2){
        cout << "Reverse Order: ";
                object.reverseOrder(nSize, userArray);
    }
    
    //Finds the max number in the array and prints it out with its index
    if (command == 3){
        cout <<"Max number is: ";
        object.maxNum(0, 0, 0, userArray);
    }
    
    //Finds the k-th largest number recursively
    if(command == 4){
        int start = 0;
        int pivot = nSize - 1;
        vector <int> tempAr(nSize);
        for (int g = 0; g < nSize; g++){
            tempAr[g] = 0;
        }
        int k;
        cout << "What k-th largest number would you like to find: ";
        cin >>k;
        
        //Error if the command is out of range
        while (k < 0 || k > nSize){
           cout << "Error - your k-th value is either lower than 1 or greater than the array size which is " << nSize << "!" << endl;
           cout << "What k-th largest number would you like to find: "; 
           cin >>k;
        }
        cout << "The "<<k<< "-th largest number is ";
        object.klarge(k, tempAr, start, pivot, userArray);
    }
    
    }
}

