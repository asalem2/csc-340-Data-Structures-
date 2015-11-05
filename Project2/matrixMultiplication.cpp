/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: September 20, 2014
 * IDE/Compiler: Netbeans
 * This program multiplies two matrices then displays the result as Matrix C
 */

#include <cstdlib>
#include<iostream>
#include <vector>


using namespace std;

void multiply_matrices(vector<vector<int>> matrixA, int num_rows,int num_cols, vector<vector<int>>matrixB, int num_rowsB, int num_colsB){
    //Print out content in Matrix A as a table
    cout << "=====MatrixA " <<num_rows <<"x" << num_cols<< "==========\n";	
	for (int i=0; i<num_rows; i++) {
		for (int j=0; j<num_cols; j++ ){
			cout << matrixA[i][j] << " ";
		}
		cout << endl;
	}
    
    //Print out content in Matrix B as a table
    cout << "=====MatrixB " <<num_rowsB <<"x" << num_colsB<< "==========\n";	
	for (int i=0; i<num_rowsB; i++) {
		for (int j=0; j<num_colsB; j++ ){
			cout << matrixB[i][j] << " ";
		}
		cout << endl;
	}
    
    //Creates a vector of int type and size of (num_rows * num_colsB) to hold all the end values
    vector <int> array(num_rows * num_colsB);
    for (int size = 0; size < array.size(); size++ )
        array[size] = 0;
    
    //This for loop multiplies and adds the matrices respectively then inputs the final values into the vector we created earlier
    int arrayTracker = -1;
    for (int m = 0; m < num_rows; m++){
        for (int i = 0; i < num_colsB; i++){
            arrayTracker++;
            int k = 0;
                for(int j =0; j < num_rowsB; j++){
                    array[arrayTracker] = array[arrayTracker] + (matrixA[m][k] * matrixB[j][i]);
                    k++;
                }    
        }       
    }    
    
    //Creates Matrix C to hold the result
    vector<vector<int> > matrixC(num_rows);
        for ( int i = 0 ; i < num_rows ; i++ )
            matrixC[i].resize(num_colsB);
    
    //This for loops assigns all the final values to their designated spot in Matrix C
    int arrayindex = 0;
    for(int i = 0; i < num_rows; i++){
        for(int j =0; j <num_colsB; j++){
           matrixC[i][j] = array[arrayindex];
           arrayindex++;
        }
    }
    
    //Prints out Matrix C as a table for user to see their final answer
    cout << "=====MatrixC (MatrixA * MatrixB) " <<num_rows <<"x" << num_colsB<< "==========\n";	
	for (int i=0; i<num_rows; i++) {
		for (int j=0; j<num_colsB; j++ ){
			cout << matrixC[i][j] << " ";
		}
		cout << endl;
	}
    
}





int main() {
    //Variables to keep track of rows and columns of the matrices
    int num_rows = 0;
    int num_cols = 0;
    
    //Ask user how many rows and columns do they want it Matrix A
    cout << "===Matrix A===" << endl;
        cout << "How many rows and columns do you want in Matrix A?\nRows: ";
            cin >> num_rows;
        cout << "Columns: ";
            cin >> num_cols;
    
    //Create Matrix A
    vector<vector<int> > matrixA(num_rows);
        for ( int i = 0 ; i < num_rows ; i++ )
            matrixA[i].resize(num_cols);
   
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
                cin >> matrixA[i][j];
            }
    }
    
    //Ask user how many rows and columns do they want it Matrix B
    int num_rowsB = 0;
    int num_colsB = 0;
    cout << "\n";
    cout << "===Matrix B===" << endl;
        cout << "How many rows and columns do you want in Matrix B?\nRows: ";
            cin >> num_rowsB;
    
    /*Print out error if the numbers of rows in Matrix B does not equal 
     *the number of columns in Matrix A because then it cant be multiplied!*/
    while (num_rowsB != num_cols){
        cout << "Matrix B should have " << num_cols << " rows or else IT CANT BE MULTIPLIED!\n";
            cout << "How many rows do you want in Matrix B?\nRows: ";
                cin >> num_rowsB;
    }
        cout << "Columns: ";
            cin >> num_colsB;
    
    
    //Creates Matrix B
    vector<vector<int> > matrixB(num_rowsB);
        for ( int i = 0 ; i < num_rowsB ; i++ )
            matrixB[i].resize(num_colsB);
    
    //Get the numbers the user wants to input into Matrix A
    for (int i = 0; i < num_rowsB; i++){
        if ((i + 1) == 1)
            cout << "Input " << num_colsB <<  " numbers for the " << (i + 1) << "st row (eg: 4 21 2): ";
        else if ((i + 1) == 2)
            cout << "Input " << num_colsB <<  " numbers for the " << (i + 1) << "nd row (eg: 4 21 2): ";
        else if ((i + 1) == 3)
            cout << "Input " << num_colsB <<  " numbers for the " << (i + 1) << "rd row (eg: 4 21 2): ";
        else if ((i + 1) > 3)
            cout << "Input " << num_colsB <<  " numbers for the " << (i + 1) << "th row (eg: 4 21 2): ";
        
            for(int j = 0; j < num_colsB; j++){
                cin >> matrixB[i][j];
            }
    }      
    
    //Pass both matrices and their size	to multiply_matrices() function
    multiply_matrices(matrixA, num_rows, num_cols, matrixB, num_rowsB,num_colsB);
        
        return 0;
}