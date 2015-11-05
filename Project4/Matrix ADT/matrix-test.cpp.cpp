/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: October 11, 2014
 * IDE/Compiler: Netbeans
 * This program is an ADT for a Matrix that lets you do various commands to it
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "matrix.h"

using namespace std;

int main() {
int choice = 1;
matrix matri;
while(choice != 0){
    cout <<"\t\t\t\t\t\tChoose a command\n-------------------------------------------------------------------------------------------------------------------------------------------\n"
            " 1. Initialize matrix by values in a vector of vectors    2.Set number of rows and columns to the matrix    3. Retrieve value at desired position\n"
            " 4. Set value to a desired position    5. Transpose function    6. Multiply two matrices    7.  Multiply a matrix by a scalar variable.\n"
            " 8. Subtract matrices    9. Output a matrix on an output stream    0. To Exit\nCommand: ";
    cin >> choice;
    while (choice < 0 || choice > 9){
        cout << "ERROR!\n Please choose a command between 0 - 10" <<endl;
        cout <<"\t\t\t\t\t\tChoose a command\n-------------------------------------------------------------------------------------------------------------------------------------------\n"
            " 1. Initialize matrix by values in a vector of vectors    2.Set number of rows and columns to the matrix    3. Retrieve value at desired position\n"
            " 4. Set value to a desired position    5. Transpose function    6. Multiply two matrices    7.  Multiply a matrix by a scalar variable.\n"
            " 8. Subtract matrices    9. Output a matrix on an output stream    0. To Exit\nCommand: ";
               cin >> choice;
    }
    if (choice == 1){
       matri.vectorMatrix();
    }
    else if(choice == 2){
        int rows = 0;
        int cols = 0;
        cout << "How many rows and columns do you want the matrix to have\nRows: ";
                cin >> rows;
        cout << "Columns: ";
                cin >> cols;
        matri.customMatrix(rows, cols);
    }
    else if (choice == 3){
        int row = 0;
        int col = 0;
        cout << "What is the position (row,column) you want to see the value of (eg: 3 1 )?: ";
            cin >>row;
            cin>>col;
            cout <<"Value at that position is " << matri.getValue(row,col);
    }
    else if (choice == 4){
        int row = 0;
        int col = 0;
        int newValue= 0;
        cout << "What is the position (row,column) you want to change the value of (eg: 1 2 )?: ";
            cin >>row;
            cin>>col;  
        cout << "What value do you want to change it to?: ";
            cin >> newValue;
        matri.changeValue(row, col, newValue);
    }
    else if (choice == 5){
        matri.transpose();
    }
    else if(choice == 6){
        matrix matrib;
        matri.operator *(matrib);
    }
    else if(choice == 7){
        int value;
        cout << "By what value do you want to multiply by?: ";
            cin>> value;
        matri.operator *(value);
    }
    else if(choice == 8){
        matrix matrixb;
        matri.operator -(matrixb);
    }
    else if(choice == 9){
        matri.print();
    }
} 
cout << "Program Terminated\nGoodbye!";
    return 0;
}

