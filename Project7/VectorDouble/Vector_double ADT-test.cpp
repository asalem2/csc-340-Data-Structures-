/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date:December 10, 2014
 * IDE/Compiler: Netbeans
 * This program is the test file for vectorDouble ADT
 */

#include "Vector_double.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main(){
    int userArray[6] = {1.0, 2.0, 3.0, 4.0, 5.0 ,6.0};
    Vector_double vector1(6, userArray); //Vector created
    cout << "What is vector1 capacity? " << vector1.capacity() <<endl;
    Vector_double vector2(vector1);  //2nd Vector created as a copy
    cout << "Is vector2 empty? ";
    if (vector2.empty() == 0)
        cout << "No" <<endl;
    else
        cout << "yes" <<endl;
    vector1.eraseP(4); //Erase position 4 from vector1
    vector1.eraseSP(1, 3); //Erase position 1 to 3 from vector 1
    vector2 = vector1; //vector 2 now equals vector 1;
    vector1.insertP(1, 5.6); //Insert value at position 1 to vector1
    double user[3] = {1.2, 5.6, 32.2};
    vector1.insertSP(2, 4, user); //Insert values at position 2 to 4 to vector1
    double newArray[4] = {3.2, 7.5, 4.5, 3.4};
    vector2.insertSP(1, 4, newArray); //Insert values at position 2 to 4 to vector1
    vector1.pop_back(); //popback vector1
    vector2.pop_back(); //popback vector2
    vector1.push_back(2.1); //pushback value 2.1 into vector1
    vector1.push_back(32.5);//pushback value 32.5 into vector1
    cout << "What is vector1 capacity? " << vector1.capacity() <<endl;
    vector1.resize(10); //resize vector 1 to 10
    vector1.shrink_to_fit();  //shrink to fit vector1
    cout << "What is vector1 size? " << vector1.getSize() <<endl;
    cout << "What is vector2 size? " << vector2.getSize() <<endl;
    cout <<"Final vector1 " <<vector1 <<endl;
    cout <<"Final vector2 " <<vector2 <<endl;
    return 0;
}

