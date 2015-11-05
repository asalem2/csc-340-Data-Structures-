/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: September 7, 2014
 * IDE/Compiler: Netbeans
 * This is the implementation of the header file "productException.h"
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "productException.h"

using namespace std;

//Function will look for the specified products id number. If its not found at the end it throws a not found exception
int getProductID(int ids[], string names[], int numProducts, string target)throw(Exception_ID_Not_Found){
    Exception_ID_Not_Found e_notFound;
    for (int i=0; i < numProducts; i++){
	if (names[i] == target){
            return ids[i];
        }
    }
      throw e_notFound;
    
}

