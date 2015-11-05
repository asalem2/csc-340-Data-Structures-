/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: November 21, 2014
 * IDE/Compiler: Netbeans
 * This program is the file that contains all the functions.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "RecursiveADT.h"

using namespace std;

//Constructor that initializes all elements in array to 0
RecursiveADT::RecursiveADT(){
    aSize = 1000;
    array[aSize];
    for (int i = 0; i < 1000; i++)
        array[i] = 0;
}

//Makes array of user specified values
void RecursiveADT::userArray(int userArray[], int nSize){
    aSize = nSize;
    for (int i = 0; i < nSize; i++)
        array[i] = userArray[i];
}

//Prints the contents of the array in a recursive matter
void RecursiveADT::reverseOrder(int current, int userArray[]){
    current = current - 1;
    if(current == 0)
        cout << userArray[0] <<endl;
    else if (current > 0){
        cout << userArray[current] << " ";
        reverseOrder(current, userArray);
    }
}

//Function that looks for the max number in the array in a recursive matter
void RecursiveADT::maxNum(int max, int index, int where, int userArray[]){
    if(index<aSize){
        if(max<userArray[index]){
            max = userArray[index];
            where = index;
        }
        maxNum(max , index+1, where, userArray);
    }
    if(index == aSize)
        cout << max << " at index [" << where << "]" <<endl;
}

//Base function that is going to run the partition algorithm
void RecursiveADT::klarge(int k, vector<int> tempAr, int start, int pivot, int userArray[]){
    if (aSize == 1000 || aSize == 1)
        cout << userArray[0] << " at index [0]"<<endl;
    else{
        int tempSize = aSize;
        int outArray[aSize];
        for (int i = 0; i <aSize; i++)
            outArray[i] = userArray[i];
        int begi = 0;
        partition(k, tempAr,begi, start, pivot, userArray);
        for (int i = 0; i <tempSize; i++){
            userArray[i] = outArray[i];
            if (aSize == outArray[i])
                cout << " at index ["<<i<<"]"<<endl;
        }
        aSize = tempSize;
    }
}

//Private function that runs the partition algorithm until it finds the k-th largest number in the array
void RecursiveADT::partition(int k, vector<int> tempAr, int begi, int start, int pivot, int userArray[]){
    int end = pivot;
    for (int i = begi; i < pivot; i++){
        if (userArray[pivot] >= userArray[i]){
          tempAr[start] = userArray[i];
          start = start + 1;  
        }
        else if (userArray[pivot] < userArray[i]){
           tempAr[end] = userArray[i];
           end = end - 1;
        }
    }
    tempAr[start] = userArray[pivot];
    int checkK = tempAr.size() - start;
    if (checkK == k){
        cout << tempAr[start];
        aSize = tempAr[start];
    }
    else if (checkK > k){
        begi = start + 1;
        for (int i = 0; i <aSize; i++)
            userArray[i] = tempAr[i] ; 
        partition(k, tempAr, begi, start + 1, pivot, userArray);
    }
    else if (checkK < k){
        begi = 0;
        for (int i = 0; i <aSize; i++)
            userArray[i] = tempAr[i] ; 
        partition(k, tempAr, begi, 0, (start - 1), userArray);
    }
    
}


