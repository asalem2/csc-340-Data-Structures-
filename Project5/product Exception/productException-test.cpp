/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: September 7, 2014
 * IDE/Compiler: Netbeans
 * This program testes an exception which occurs when an item is not found
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include "productException.h"
using namespace std;

int main(){
    int productIds[]= {4, 5, 8, 10, 13};
    string products[] = { "computer", "flash drive", "mouse", "printer", "camera" };
    
    //Looks for the "mouse" id number and succeeds
    try{
       int id = getProductID(productIds, products, 5, "mouse");
       cout << "Product ID: " << id << endl;
    }        
    catch (exception& e)
    {
        cerr << "Error - " << e.what() <<endl; 
    }
    
    //Looks for the "camera" id number and succeeds
    try{
        int id = getProductID(productIds, products, 5, "camera");
        cout << "Product ID: " << id << endl;
    }        
    catch (exception& e)
    {
        cerr << "Error - " << e.what() <<endl; 
    }
    
    //throws exception since laptop is not found;
    try{
        cout << getProductID(productIds, products, 5, "laptop");
    }        
    catch (exception& e)
    {
        cerr << "Error - " << e.what(); 
    }
        return 0;
}


