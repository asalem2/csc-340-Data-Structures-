/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
* Class:Hui Yang 340-01
* Date: October 11, 2014
* IDE/Compiler: Netbeans
* This is the header file for matrix ADT
*/

#ifndef MATRIX_H
#define	MATRIX_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class matrix{
private:
	//Private variables
	int numrows;
	int numcols;
	vector<vector<int> > matrixx;

public:
	//Constructor
	matrix();
	void vectorMatrix();

	//Functions
	void customMatrix(int num_rows, int num_cols);
	int getValue(int row, int col);
	void changeValue(int row, int col, int newValue);
	void transpose();
	void print();

	//Operator overloading
	matrix operator-(matrix matrixb);
	matrix operator*(matrix matrixb);
	matrix operator*(int value);
};

#endif	/* MATRIX_H */

