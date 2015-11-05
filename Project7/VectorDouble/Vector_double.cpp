/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date:December 10, 2014
 * IDE/Compiler: Netbeans
 * This program is the implementation file for vectorDouble ADT header file
 */


#include "Vector_double.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//Destructor
Vector_double::~Vector_double() {
    //Makes sure everything is empty
    if (dArray != NULL) {
        dArray = NULL;
        size = 0;
        elements = 0;
    }
}

//Constructor
Vector_double::Vector_double() {
    //Everything set to 0
    size = 0;
    elements = 0;
    dArray = NULL;
}

//Constructor
Vector_double::Vector_double(int Isize, int userArray[]) {
    //size = into given size as well as elements 
    size = Isize;
    elements = Isize;
    //allocate memory
    try {
        dArray = new double[size];
    }    
    catch (bad_alloc &e) {
        cerr << "copyConstructor error(): " << e.what();
    }
    //copy array contents
    for (int i = 0; i < size; i++)
        dArray[i] = userArray[i];
}

//copy constructor
Vector_double::Vector_double(const Vector_double& newObject) {
    //size = into given size as well as elements 
    size = newObject.size;
    elements = newObject.elements;
    //allocate space to *dArray if elements>0
    if (size <= 0)
        dArray = NULL;
    else {
        //allocate memory;
        try {
            dArray = new double[size];
        }        
        catch (bad_alloc &e) {
            cerr << "copyConstructor error(): " << e.what();
        }
        //copy array contents
        for (int i = 0; i < size; i++) 
            dArray[i] = newObject.dArray[i];
    }
}


//overloaded assignment operator
Vector_double Vector_double::operator=(const Vector_double& rhs) {
    //allocate space to *dArray if needed
    if (size > 0)
        delete [] dArray; //release the old memory
    
    //size = into given size as well as elements 
    size = rhs.size;
    elements = rhs.elements;
    if (size <= 0)
        dArray = NULL;
    else {
        //allocate memory
        try {
            dArray = new double[size]; 
        }        catch (bad_alloc &e) {
            cerr << "copyConstructor error(): " << e.what();
        }
        //copy array contents
        for (int i = 0; i < size; i++)
            dArray[ i ] = rhs.dArray[i];
    }
    return (*this);
}

//returns capacity of vector
int Vector_double::capacity() {
    return size;
}

//returns boolean expression
bool Vector_double::empty() {
    return (dArray == NULL);
}

//erases a given position
void Vector_double::eraseP(int position){
    //checks to see if dArray is empty
    if (!empty()) {
        if (position <= 0 || position > size)
            cout << "Error - You must choose a position from 1 to " << size;
        else {
            if (dArray[position - 1] != 0)
                elements = elements - 1;
            dArray[position - 1] = 0;
        }
    } 
    else
        cout << "Vector is empty, there is nothing to erase";
}

//erases positions from a to b
void Vector_double::eraseSP(int pos1, int pos2) {
    //Error if users index values are invalid
    if (pos1 >= pos2)
        cout << "Position 2 must be larger than position 1 ex: (3  7)";
    //checks to see if dArray is empty
    else if (!empty()) {
        if (pos1 <= 0 || pos2 > size)
            cout << "Error - You must choose positions in between 1 - " << size;
        else {
            for (int i = (pos1 - 1); i < pos2; i++) {
                if (dArray[i] != 0)
                    elements = elements - 1;
                dArray[i] = 0;
            }
        }
    } 
    else
        cout << "Vector is empty, there is nothing to erase";
}

//inserts value into a given position
void Vector_double::insertP(int position, double element) {
    //size must be greater than 0
    if (size > 0) {
        if (position <= 0 || position > size)
            cout << "Error - You must choose a position from 1 to " << size;
        else {
            if (dArray[position - 1] == 0)
                elements = elements + 1;
            dArray[position - 1] = element;
        }
    }
    else
        cout << "Vector has no positions to insert into";
}

//inserts values from index a to b
void Vector_double::insertSP(int pos1, int pos2, double element[]) {
    //Error if users index values are invalid
    if (pos1 >= pos2)
        cout << "Position 2 must be larger than position 1 ex: (3  7)";
    //size must be greater than 0 to erase
    else if (size > 0){
        if (pos1 <= 0 || pos2 > size)
            cout << "Error - You must choose positions in between 1 - " << size;
        else {
            int trackUserArray = 0;
            for (int i = (pos1 - 1); i < pos2; i++) {
                if (dArray[i] == 0)
                    elements = elements + 1;
                dArray[i] = element[trackUserArray];
                trackUserArray++;
            }
        }
    } 
    else
        cout << "Vector has no positions to insert into";
}

//popback feature
void Vector_double::pop_back() {
    //dArray must not be empty for this to work
    if (!empty() && size > 0) {
        if (dArray[size - 1] != 0)
            elements = elements - 1;
        dArray[size - 1] = 0;
        size = size - 1;
    } 
    else 
        cout << "No element to pop back";
    
}

//pushback feature
void Vector_double::push_back(double newElement) {
    //case 1: dArray list is empty
    if (size == 0) {
        try {
            dArray = new double[1]; //deep copy
        }        catch (bad_alloc &e) {
            cerr << "Error: " << e.what();
        }
        dArray[0] = newElement;
    }
    else { 
        //case 2: expand the list
        double *tmp_dArray = NULL;
        try {
            tmp_dArray = new double[size + 1];
        } catch (bad_alloc& e) {
            cerr << "Error: " << e.what();
        }
        //move the dArray to tmp_dArray
        for (int i = 0; i < size; i++) //save the values
            tmp_dArray [i] = dArray[ i ];
        tmp_dArray [size] = newElement;
        //release the space allocated to the old dArray
        delete [] dArray;
        //set new dArray
        dArray = tmp_dArray;
    }
    //increment size and elements by 1
    size += 1;
    elements = elements + 1;
}

//resizes dArray
void Vector_double::resize(int newSize) {
    //Error if newSize is invalid
    if (newSize < 0)
        cout << "Error resize must be greater than 0" << endl;
    //set size and elements to 0 if newsize = 0
    else if (newSize == 0) {
        size = 0;
        elements = 0;
    } 
    //set size to newsize
    else if (newSize > size) {
        //extend dArray to new size
        for (int i = size; i < newSize; i++)
            dArray[i] = 0;
        size = newSize;
    }
}

//shrinks dArray to new value to save memory
void Vector_double::shrink_to_fit() {
    //size is greater than 0 then we check if its acceptable to shrink or not
    if (size > 0) {
        int breakOff = 0;
        int check = (size - 1);
        while (breakOff == 0) {
            if (dArray[check] == 0){
                size = size - 1;
                check = check - 1;
            } 
            else
                breakOff = 1;
        }
    } 
    else if (size == 0)
        cout << "Nothing to shrink";
}

//returns size of dArray
int Vector_double::getSize() {
    return size;
}

//overload put operator
ostream& operator<<(ostream& outS, const Vector_double& object1) {
    //Run for loop to go through the array to print all values in it
    for (int i = 0; i < object1.size; i++) {
        outS << object1.dArray[i] << ", ";
    }
    //return all values
    return outS;
}
