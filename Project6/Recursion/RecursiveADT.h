/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
* Class:Hui Yang 340-01
* Date: November 21, 2014
* IDE/Compiler: Netbeans
* This program is the header file for the RecursiveADT main file.
*/

#ifndef RECURSIVEADT_H
#define	RECURSIVEADT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class RecursiveADT{
	//private variables and the private partition function 
private:
	int aSize;
	int array[1000];
	void partition(int k, vector<int> tempAr, int begi, int start, int pivot, int userArray[]);

	//public functions to implement
public:
	//Constructor
	RecursiveADT();

	//Functions
	void userArray(int userArray[], int nSize);
	void reverseOrder(int current, int userArray[]);
	void maxNum(int max, int index, int where, int userArray[]);
	void klarge(int k, vector<int> tempAr, int start, int pivot, int userArray[]);
};

#endif	/* RECURSIVEADT_H */

