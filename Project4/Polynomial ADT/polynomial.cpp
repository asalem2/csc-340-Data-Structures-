/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: October 11, 2014
 * IDE/Compiler: Netbeans
 * This is the implementation of the header file for the polynomial ADT
 */

#include <iostream>
#include <string>
#include "polynomial.h"

using namespace std;

//Constructor that makes the polynomial the default values of 0!^1
polynomial::polynomial(){
    for (int i = 0; i < 20; i++){
        coefficient[i] = 0;
        variable[i] = "!";
        power[i] = 1;
    }
}

//Reads a polynomial from the user
void polynomial::readpolynomial(int &terms){
    //Resizes polynomial to user size
    for (int i = 0; i < terms; i++){
        coefficient[i] = 0;
        variable[i] = "!";
        power[i] = 1;
    }
    
    //User inputs polynomial
    cout << "Enter the coefficient, variable and power of your terms. " << endl;
    int i = 0;
    while(i < terms){
        if ((i + 1) == 1){
            cout << "---Input your " << (i + 1) << "st polynomial---"<<endl;
            cout<< "coefficient (If none input 0): ";
                cin >> coefficient[i];
            cout<< "variable (If none input !): ";
                cin >> variable[i];
            cout<< "power (If none input 1): ";
                cin >> power[i];
        }
        else if ((i + 1) == 2){
            cout << "---Input your " << (i + 1) << "nd polynomial---"<<endl;
            cout<< "coefficient (If none input 0): ";
                cin >> coefficient[i];
            cout<< "variable (If none input !): ";
                cin >> variable[i];
            cout<< "power (If none input 1): ";
                cin >> power[i];
        }
        else if ((i + 1) == 3){
           cout << "---Input your " << (i + 1) << "rd polynomial---"<<endl;
            cout<< "coefficient (If none input 0): ";
                cin >> coefficient[i];
            cout<< "variable (If none input !): ";
                cin >> variable[i];
            cout<< "power (If none input 1): ";
                cin >> power[i];
        }
        else if ((i + 1) > 3){
            cout << "---Input your " << (i + 1) << "th polynomial---"<<endl;
            cout<< "coefficient (If none input 0): ";
                cin >> coefficient[i];
            cout<< "variable (If none input !): ";
                cin >> variable[i];
            cout<< "power (If none input 1): ";
                cin >> power[i];
        }
        i++;
    }
    //Checks for like terms
    int tempc[terms];
    string tempv[terms];
    int tempp[terms];
    for (int i = 0; i < terms; i++){
        tempc[i] = 0;
        tempv[i] = "!";
        tempp[i] = 1;
    }
    for (int i = 0; i < terms; i++){
        tempc[i] = coefficient[i];
        tempv[i] = variable[i];
        tempp[i] = power[i];
    }
    for (int i = 0; i < terms; i++){
        if (tempc[i] == 0)
            tempc[i] = 1;
    }
    //keeps track of where the polynomial is
    int track = 0;
    
    //for loop to goes through each element checking for like terms
    for (int i = 0; i < terms; i++){
        for (int k = i+1; k < terms;k++){
           if (tempc[i] != 1 || tempv[i] != "!" || tempp[i] != 1){
                if (tempp[i] == tempp[k] && tempv[i] == tempv[k]){
                    coefficient[track] = tempc[i] +tempc[k];
                    variable[track] = tempv[i];
                    power[track] = tempp[i];
                    tempc[k] = 0;
                    tempv[k] = "!";
                    tempp[k] = 1;
                    track++;
                    tempc[i] = 1;
                    tempv[i] = "!";
                    tempp[i] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < terms; i++){
        if (tempc[i] == 1)
            tempc[i] = 0;
    } 
    
    for (int i = 0; i < terms; i++){
        if (tempc[i] != 0 || tempv[i] != "!" || tempp[i] != 1){
            coefficient[track] = tempc[i]; 
            variable[track] = tempv[i];
            power[track] = tempp[i];
            track++;
        }   
    }
    
    terms = track;
    
    //Checks for like terms one more time just in case
    for (int i = 0; i < terms; i++){
        tempc[i] = coefficient[i];
        tempv[i] = variable[i];
        tempp[i] = power[i];
    }
    for (int i = 0; i < terms; i++){
        if (tempc[i] == 0)
            tempc[i] = 1;
    }
    
    //keeps track of where the polynomial is
    track = 0;
    
    //for loop to goes through each element checking for like terms
    for (int i = 0; i < terms; i++){
        for (int k = i+1; k < terms;k++){
           if (tempc[i] != 1 || tempv[i] != "!" || tempp[i] != 1){
                if (tempp[i] == tempp[k] && tempv[i] == tempv[k]){
                    coefficient[track] = tempc[i] +tempc[k];
                    variable[track] = tempv[i];
                    power[track] = tempp[i];
                    tempc[k] = 0;
                    tempv[k] = "!";
                    tempp[k] = 1;
                    track++;
                    tempc[i] = 1;
                    tempv[i] = "!";
                    tempp[i] = 1;
                
                }
            }
        }
    }
    
    for (int i = 0; i < terms; i++){
        if (tempc[i] == 1)
            tempc[i] = 0;
    } 
    
    for (int i = 0; i < terms; i++){
        if (tempc[i] != 0 || tempv[i] != "!" || tempp[i] != 1){
            coefficient[track] = tempc[i]; 
            variable[track] = tempv[i];
            power[track] = tempp[i];
            track++;
        }   
    }
    
    terms = track;
}

int polynomial::degree(){
     //variables for the for loops and a min variable as well
    int temp[20];
    for (int e = 0; e < 20; e++) {
        temp[e] = power[e];
    }
    int i,j;
    int min;
   
   //This for loop is to keep track of elements being compared
    for (j = 0; j < 20-1; j++) {
        min = j;
        for ( i = j+1; i < 20; i++) {
            if (temp[i] < temp[min]) {
                min = i;
            }
        }
        
        //If statement to swap which int is the min
        if(min != j) {
            swap(temp[j], temp[min]);
        }
    }
    
    //returns the highest degree
    return temp[19]; 
}

//Gets coefficient of a certain degree
int polynomial::getcoefficient(int degree){
    for (int i = 0; i < 20; i++){
        if(power[i] == degree ){
            return coefficient[i];
        }
    }
    return 0;
}

//Changes coefficient of certain degree
void polynomial::changeCoefficient(int newCoefficient, int degree){
    int noMatch = 0;
    for (int i = 0; i < 20; i++){
        if(power[i] == degree ){
            coefficient[i] = newCoefficient;
            noMatch = 1;
        }
    }
    if (noMatch == 0){
        cout << "There is no term with that degree so no changes were made!" <<endl;
    }
}

void polynomial::multiplys(int terms, int value){
    //Gives error if no first polynomial is read
    if(coefficient[0] == 0 && variable[0] == "!" && power[0] == 1){
       cout << "You must first enter a polynomial"<<endl;
    }
    else{
        //Multiplies all terms by scalar variable
        for (int i = 0; i < terms; i++){
            coefficient[i] =  coefficient[i] * value;
        }
    } 
}

void polynomial::add(int &terms){
    //Gives error if no first polynomial is read
    if(coefficient[0] == 0 && variable[0] == "!" && power[0] == 1){
       cout << "You must first enter your first polynomial"<<endl;
    }
    else{
        //Makes second polynomial
        int terms2;
        cout << "How many terms are you going to input into the second polynomial?: ";
            cin >> terms2;
        int coefficients[terms2];
        string variables[terms2];
        int powers[terms2];
        for (int i = 0; i < terms2; i++){
            coefficients[i] = 0;
            variables[i] = "!";
            powers[i] = 1;
        }
        
        //Ask user to enter there terms for second polynomial
        cout << "Enter the coefficient, variable and power of your terms. " << endl;
        int k = 0;
        while(k < terms2){
            if ((k + 1) == 1){
                cout << "---Input your " << (k + 1) << "st polynomial---"<<endl;
                cout<< "coefficient (If none input 0): ";
                    cin >> coefficients[k];
                cout<< "variable (If none input !): ";
                    cin >> variables[k];
                cout<< "power (If none input 1): ";
                    cin >> powers[k];
        }
        else if ((k + 1) == 2){
            cout << "---Input your " << (k + 1) << "nd polynomial---"<<endl;
            cout<< "coefficient (If none input 0): ";
                 cin >> coefficients[k];
            cout<< "variable (If none input !): ";
                 cin >> variables[k];
            cout<< "power (If none input 1): ";
               cin >> powers[k];
        }
        else if ((k + 1) == 3){
           cout << "---Input your " << (k + 1) << "rd polynomial---"<<endl;
            cout<< "coefficient (If none input 0): ";
                 cin >> coefficients[k];
            cout<< "variable (If none input !): ";
                 cin >> variables[k];
            cout<< "power (If none input 1): ";
                cin >> powers[k];
        }
        else if ((k + 1) > 3){
            cout << "---Input your " << (k + 1) << "th polynomial---"<<endl;
            cout<< "coefficient (If none input 0): ";
                 cin >> coefficients[k];
            cout<< "variable (If none input !): ";
                 cin >> variables[k];
            cout<< "power (If none input 1): ";
                cin >> powers[k];
        }
        k++;
    }
    int track = 0;
    int temp[20];
    //Make a temporary list to hold the sum values
    int addt = terms + terms2;
    int tempc[addt];
    string tempv[addt];
    int tempp[addt];
    for (int i = 0; i < addt; i++){
        tempc[i] = 0;
        tempv[i] = "!";
        tempp[i] = 1;
    }
    //Copy the coefficients we are going to add so they wont be modified in original polynomial
    for (int i = 0; i < terms; i++){
        tempc[i] = coefficient[i];
        tempv[i] = variable[i];
        tempp[i] = power[i];
    }
    int offset = terms;
    int zero = 0;
    for (int i = 0; i < terms2; i++){
        tempc[offset] = coefficients[zero];
        tempv[offset] = variables[zero];
        tempp[offset] = powers[zero];
        zero++;
        offset++;
    }
    for (int i = 0; i < addt; i++){
        if (tempc[i] == 0)
            tempc[i] = 1;
    }
    
    //keeps track of where the polynomial is
    track = 0;
    
    //for loop to add each polynomial respectively
    for (int i = 0; i < addt; i++){
        for (int k = i+1; k < addt;k++){
            if (tempc[i] != 1 || tempv[i] != "!" || tempp[i] != 1){
                if (tempp[i] == tempp[k] && tempv[i] == tempv[k]){
                    coefficient[track] = tempc[i] +tempc[k];
                    variable[track] = tempv[i];
                    power[track] = tempp[i];
                    tempc[k] = 1;
                    tempv[k] = "!";
                    tempp[k] = 1;
                    track++;
                    tempc[i] = 1;
                    tempv[i] = "!";
                    tempp[i] = 1;
                }
            }
        }
    }
    for (int i = 0; i < addt; i++){
        if (tempc[i] == 1 )
            tempc[i] = 0;
    }
    for (int i = 0; i < addt; i++){
        if (tempc[i] != 0 || tempv[i] != "!" || tempp[i] != 1){
            coefficient[track] = tempc[i]; 
            variable[track] = tempv[i];
            power[track] = tempp[i];
            track++;
        }   
    }
    //Updates the terms value to the actual terms we have now
    terms = track;
    }
}

void polynomial::printpolynomial(int termtoprint){
    //Copies the coefficients in the polynomial to a temp list so we can print respectively to there sign
    int temp[20];
    for(int k = 0; k < termtoprint; k++ ){
       temp[k] = coefficient[k];
    }
    
    //Here we begin to print the polynomial
    for(int i = 0; i < termtoprint; i++ ){
        if(temp[i] != 0 ){
            cout <<temp[i];
        }
        if(variable[i] != "!"){
            cout << variable[i];
        }
        if (power[i] != 1){
                cout << "^" <<power[i];
        }
        //After a term it either prints + or - depended on the next term
        if(i < termtoprint-1){
            if(temp[i + 1] >= 0){
                cout << " + ";
            }
            else if(temp[i + 1] < 0){
                cout << " - ";
                temp[i + 1] = temp[i + 1] * -1;
            }
        }
    }
    
    //If theres no polynomial to display it will let the user know
    if(coefficient[0] == 0 && variable[0] == "!" && power[0] == 1){
       cout << "No polynomial to display"<<endl;
    }
}

polynomial polynomial::operator /(int value){
    //Prints out error if there no polynomial to dive by
    if(coefficient[0] == 0 && variable[0] == "!" && power[0] == 1){
       cout << "You must first enter your first polynomial"<<endl;
       return *this;
    }
    else{
        //If there is a polynomial it divides he coefficients by the value user inputed
        for (int i = 0; i < 20; i++){
            coefficient[i] =  coefficient[i] / value;
        }
        return *this;
    }
}

polynomial polynomial::operator -(int terms){
    //Prints out error if there no polynomial to dive by
    if(coefficient[0] == 0 && variable[0] == "!" && power[0] == 1){
       cout << "You must first enter your first polynomial"<<endl;
       return *this;
    }
    else{
        //Negates the polynomial by multiplying the coefficients of each term by -1
        for (int i = 0; i < terms; i++){
        coefficient[i] = coefficient[i] * -1;
        }
    return *this;
    }
}
    