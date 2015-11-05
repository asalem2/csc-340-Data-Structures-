/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
* Class:Hui Yang 340-01
* Date:December 10, 2014
* IDE/Compiler: Netbeans
* This program is the the header file for the vectorDouble ADT
*/


#ifndef VECTOR_DOUBLE_H
#define	VECTOR_DOUBLE_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Vector_double{
	//private data members
private:
	int size;
	int elements;
	double *dArray;

	//public fuctions
public:
	//destructor
	~Vector_double();

	//default constructor
	Vector_double();
	Vector_double(int Isize, int userArray[]);
	//copy constructor, assignment
	Vector_double(const Vector_double& newObject);
	//overloaded assignment operator
	Vector_double operator=(const Vector_double& rhs);
	//accessors
	int capacity();
	bool empty();
	int getSize();
	//mutators
	void eraseP(int position);
	void eraseSP(int pos1, int pos2);
	void insertP(int position, double element);
	void insertSP(int pos1, int pos2, double elements[]);
	void pop_back();
	void push_back(double newElement);
	void resize(int newSize);
	void shrink_to_fit();
	//overloaded put operator
	friend ostream& operator<<(ostream& outS, const Vector_double& object1);

};

#endif	/* VECTOR_DOUBLE_H */

