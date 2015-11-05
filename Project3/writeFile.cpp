/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: September 29, 2014, 
 * IDE/Compiler: Netbeans
 * This program inputs the missing integer values into a file while still keeping everything in it
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
    
    //opens "file1.txt" so we can be able to read and write into it
    fstream outfile("file1.txt", ios::in | ios::out);
  
    //checks to see if opening the file fails, if it does program prints error message, if not we continue
    if (outfile.fail()){ 
        cout << "file1.txt cannot be found or opened!"; 
    }
    else{
    
    //Points to where we are going to start storing numbers for later use
    outfile.clear();
    outfile.seekp(5*24);
  
    //creates a vector of type int and size 100 to store the numbers that are going to be overwritten
    vector <int> numbers(100);
    int track = 0;
    
    //Goes through the file and stores all numbers until the file ends
    while (outfile.good()) { 
        outfile >> numbers[track];
        track++;
    }
  
    //Calls clear() then points to where we are going to start inputting numbers
    outfile.clear();
    outfile.seekp (5*24);
    
    //nextint is used to keep track of what numbers we are inputting
    int nextint = 25;
  
    //inputs the numbers that where missing into the file
    while (outfile.good() && nextint <= 70){
        outfile.width(4);
        outfile << nextint << endl;
        nextint++;
    }
  
    //inputs the numbers we stored back into the file to be complete
    for (int i =0; i < 100; i++){
        if (numbers[i] != 0){
            outfile.width(4);
            outfile << numbers[i] << endl;
        }
    }
  
    //closes file
    outfile.close();
    
    //Tell user everything was successful
    cout << "File was modified successfully!";
    }
  
    return 0;
  
}