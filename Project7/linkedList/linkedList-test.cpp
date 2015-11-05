/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date:December 10, 2014
 * IDE/Compiler: Netbeans
 * This program is the test file for LinkedList ADT
 */

#include "linkedList_structNode.h"   
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
    //Create list1
    List list1;
    
    //Check to see if list1 is empty (It should be since it was just created)
    cout <<"Is list1 empty? ";
    if (list1.isEmpty() != 0)
        cout << "Yes" << endl;
    else
        cout <<"No" <<endl;
    
    //Insert values into list 1
    list1.insert(1, 5);  list1.insert(2, 6); list1.insert(3, 2); list1.insert(4,10);  list1.insert(5, 7);
    
    //Create List list2 and set it equal to list1
    List list2 = list1;
   
    //Check to see if list2 is empty (It should not be since its a copy of list1)
    cout <<"Is list2 empty? ";
    if (list2.isEmpty() != 0)
        cout << "Yes" << endl;
    else
        cout <<"No" <<endl;
    
    //Remove index 2 from list1 then remove index 3"
    list1.remove(2); list1.remove(3);
    
    //Remove index 4 from list2 then insert a value into index 3
    list2.remove(4);  list2.insert(3, 21);
            
    //Get the lengths of both list respectively
    cout << endl;
    cout << "list1 length is "<<list1.getLength() <<endl;
    cout << "list2 length is "<<list2.getLength() <<endl;
    
    //Print out both list
    cout << endl;
    cout << "List 1 - " << list1 <<endl;
    cout << "List 2 - "  << list2 <<endl;
    
    //Reverse both list
    list1.reverseList(list1);
    list2.reverseList(list2);
    
    //Print out both list again in new order
    cout << endl;
    cout << "Reverse order"<<endl;
    cout << "List 1 - " << list1 <<endl;
    cout << "List 2 - " << list2 <<endl;
    
    return 0;
}

