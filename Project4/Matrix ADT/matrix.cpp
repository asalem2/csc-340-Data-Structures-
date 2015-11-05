/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: October 11, 2014
 * IDE/Compiler: Netbeans
 * This is the implementation of the header file for matrix ADT
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;

matrix::matrix(){
    //Default constructor
    //Initializes all variables
    numrows = 0;
    numcols = 0;
    matrixx.resize(1);
    for ( int i = 0 ; i < 1 ; i++)
            matrixx[i].resize(1);   
}

void matrix::vectorMatrix(){
    int num_rows = 0;
    int num_cols = 0;
    
        cout << "How many rows and columns do you want in your Matrix?\nRows: ";
            cin >> num_rows;
        cout << "Columns: ";
            cin >> num_cols;
    
    matrixx.resize(num_rows);
        for ( int i = 0 ; i < num_rows ; i++)
            matrixx[i].resize(num_cols);
   
    //Get the numbers the user wants to input into Matrix A
    for (int i = 0; i < num_rows; i++){
        if ((i + 1) == 1)
            cout << "Input " << num_cols <<  " numbers for the " << (i + 1) << "st row (eg: 4 21 2): ";
        else if ((i + 1) == 2)
            cout << "Input " << num_cols <<  " numbers for the " << (i + 1) << "nd row (eg: 4 21 2): ";
        else if ((i + 1) == 3)
            cout << "Input " << num_cols <<  " numbers for the " << (i + 1) << "rd row (eg: 4 21 2): ";
        else if ((i + 1) > 3)
            cout << "Input " << num_cols <<  " numbers for the " << (i + 1) << "th row (eg: 4 21 2): ";
        
            for(int j = 0; j < num_cols; j++){
                cin >> matrixx[i][j];
            }
    }
    numcols = num_cols;;
    numrows = num_rows;
}

void matrix::customMatrix(int num_rows, int num_cols){
    //Gets user input dimensions and resizes matrix to those dimensions
    numrows = num_rows;
    numcols = num_cols;
    matrixx.resize(num_rows);
    for (int i = 0; i < num_rows ; i++)
            matrixx[i].resize(num_cols);
        
    //Here we set all the values to zero
    for(int i = 0; i < num_rows; i++){
        for(int j =0; j <num_cols; j++){
           matrixx[i][j] = 0;
        }
    }
 }

int matrix::getValue(int row, int col){
    //Gets value for (row,col)
    //We subtract 1 from their values since user doesn't know array index starts at 0
    return  matrixx[row - 1][col - 1];
}

void matrix::changeValue(int row, int col, int newValue){
    //We subtract 1 from their values since user doesn't know array index starts at 0
    matrixx[row - 1][col - 1] = newValue;
    //Lets user know the value was change successfully
    cout << "Value changed successfully!"<<endl;
}

void matrix::transpose(){
    //First we make a list to hold all the values in the matrix
    vector <int> list(numrows + numcols);
    int track = 0;
    for(int i = 0; i < numrows; i++){
        for(int j =0; j <numcols; j++){
           list[track] = matrixx[i][j];
           track++;
        }
    }
    
    //We switch the dimernsions of the matrix ex:(2,3) --> (3,2)
    int temp = numrows;
    numrows = numcols;
    numcols = temp;
    
    //We then apply the change of dimensions to the matrix
    matrixx.resize(numrows);
    for (int i = 0; i < numrows ; i++)
        matrixx[i].resize(numcols);
    
    //Then we copy all the values we stored at the beginning and assigned them to their respected spot
    track = 0;
    for(int i = 0; i < numcols; i++){
        for(int j =0; j <numrows; j++){
           matrixx[j][i] = list[track];
           track++;
        }
    }
}

matrix matrix::operator*(matrix matrixb){
    if (numrows == 0){
        //Error message if no matrix to multiply by
        cout << "You must first input a matrix" << endl;
        return *this;
    }
    else{
        //Gets user input for dimensions
        cout << "How many rows and columns do you want in your second matrix?\nRows: ";
            cin >> matrixb.numrows;
    
    /*Prints out error if the numbers of rows in Matrix 2 does not equal 
     *the number of columns in Matrix 1 because then it cant be multiplied!*/
    while (matrixb.numrows != numcols){
        cout << "Your second matrix should have " << numcols << " rows or else IT CANT BE MULTIPLIED!\n";
            cout << "How many rows and columns do you want in your second matrix?\nRows: ";
                cin >> matrixb.numrows;
    }
        cout << "Columns: ";
            cin >> matrixb.numcols;
    
    
    //Creates Matrix 2
    matrixb.matrixx.resize(matrixb.numrows);
        for ( int i = 0 ; i < matrixb.numrows ; i++ )
            matrixb.matrixx[i].resize(matrixb.numcols);
    
    //Get the numbers the user wants to input into Matrix 2
    for (int i = 0; i < matrixb.numrows; i++){
        if ((i + 1) == 1)
            cout << "Input " << matrixb.numcols <<  " numbers for the " << (i + 1) << "st row (eg: 4 21 2): ";
        else if ((i + 1) == 2)
            cout << "Input " << matrixb.numcols <<  " numbers for the " << (i + 1) << "nd row (eg: 4 21 2): ";
        else if ((i + 1) == 3)
            cout << "Input " << matrixb.numcols <<  " numbers for the " << (i + 1) << "rd row (eg: 4 21 2): ";
        else if ((i + 1) > 3)
            cout << "Input " << matrixb.numcols <<  " numbers for the " << (i + 1) << "th row (eg: 4 21 2): ";
        for(int j = 0; j < matrixb.numcols; j++){
            cin >> matrixb.matrixx[i][j];
        }
    }      
    //Creates list to hold the values of the multiplied results
    vector <int> array(numrows * matrixb.numcols);
    for (int size = 0; size < array.size(); size++ )
        array[size] = 0;
    
    //This for loop multiplies and adds the matrices respectively then inputs the final values into the vector list we created earlier
    int arrayTracker = -1;
    for (int m = 0; m < numrows; m++){
        for (int i = 0; i < matrixb.numcols; i++){
            arrayTracker++;
            int k = 0;
            for(int j =0; j < matrixb.numrows; j++){
                array[arrayTracker] = array[arrayTracker] + (matrixx[m][k] * matrixb.matrixx[j][i]);
                k++;
            }    
        }       
    }    
    
    //Resizes Matrix 1 to its new dimensions
                matrixx.resize(numrows);
        for ( int i = 0 ; i < numrows ; i++ )
            matrixx[i].resize(matrixb.numcols);
    
    //This for loops assigns all the final values from the vector list to their designated spot in Matrix 1
    int arrayindex = 0;
    for(int i = 0; i < numrows; i++){
        for(int j =0; j <matrixb.numcols; j++){
           matrixx[i][j] = array[arrayindex];
           arrayindex++;
        }
    }
    numcols = matrixb.numcols;
    return *this;
  }
}

matrix matrix::operator*(int value){
    if (numrows == 0){//Error if theres no matrix to multiply
        cout << "You must first input a matrix" << endl;
        return *this;
    }
    else{
        //Here we multiply every number in the matrix by the value the user specified
        for (int i=0; i<numrows; i++) {
            for (int j=0; j<numcols; j++ ){
                matrixx[i][j] = matrixx[i][j] * value;
            }
        }
        return *this;
    }
}

matrix matrix::operator-(matrix matrixb){
    if (numrows == 0){
        //Error if theres no matrix to subtract from
        cout << "You must first input a matrix" << endl;
        return *this;
    }
    else{
        //Ask user for the dimensions of the matrix they want to subtract by
        cout << "How many rows and columns do you want in your second matrix?\nRows: ";
            cin >> matrixb.numrows;
            cout << "Columns: ";
            cin >> matrixb.numcols;
    
    /*Print out error if the numbers of rows and columns in Matrix 2 does not equal 
     *the number of rows and columns in Matrix 1 because then it cant be subtracted!*/
    while (matrixb.numrows != numrows || matrixb.numcols != numcols){
        cout << "The second Matrix should have " << numrows << " rows and "<< numcols <<" columns or else IT CANT BE SUBTRACTED!\n";
            cout << "How many rows do you want in your second Matrix?\nRows: ";
                cin >> matrixb.numrows;
                cout << "Columns: ";
                cin >> matrixb.numcols;
    }
            
    //Creates Matrix 2
    matrixb.matrixx.resize(matrixb.numrows);
        for ( int i = 0 ; i < matrixb.numrows ; i++ )
            matrixb.matrixx[i].resize(matrixb.numcols);
    
    //Gets the numbers user wants to input into Matrix 2
    for (int i = 0; i < matrixb.numrows; i++){
        if ((i + 1) == 1)
            cout << "Input " << matrixb.numcols <<  " numbers for the " << (i + 1) << "st row (eg: 4 21 2): ";
        else if ((i + 1) == 2)
            cout << "Input " << matrixb.numcols <<  " numbers for the " << (i + 1) << "nd row (eg: 4 21 2): ";
        else if ((i + 1) == 3)
            cout << "Input " << matrixb.numcols <<  " numbers for the " << (i + 1) << "rd row (eg: 4 21 2): ";
        else if ((i + 1) > 3)
            cout << "Input " << matrixb.numcols <<  " numbers for the " << (i + 1) << "th row (eg: 4 21 2): ";
        for(int j = 0; j < matrixb.numcols; j++){
            cin >> matrixb.matrixx[i][j];
            matrixb.matrixx[i][j] = matrixb.matrixx[i][j] * -1;
        }
    }
    //This for loop subtracts the values in the matrices respectively
    for (int m = 0; m < numrows; m++){
        for (int i = 0; i < numcols; i++){
            matrixx[m][i] = matrixx[m][i] + matrixb.matrixx[m][i];
        }       
    }   
    return *this;
  }
}

void matrix::print(){
    cout << "=====Matrix " <<numrows <<"x"<< numcols<< "==========\n";	
    for (int i=0; i<numrows; i++) {
        for (int j=0; j<numcols; j++ ){
            cout << matrixx[i][j] << " ";
        }
        cout << endl;
    }
}


    
    



