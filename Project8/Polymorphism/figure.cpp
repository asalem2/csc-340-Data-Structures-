/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date:December 10, 2014
 * IDE/Compiler: Netbeans
 * This program is the implementation file for figure.h
 */


#include <iostream>
#include "figure.h"

using namespace std;

void Figure::erase(){
    cout << "Calling Figure::erase()" <<endl;
}
    
void Figure::draw(){
    cout << "Calling Figure::draw()" <<endl;
}

void Figure::center(){
    cout << "Calling Figure::center()" <<endl;
    erase();
    draw();
}

