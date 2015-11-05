/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: September 20, 2014
 * IDE/Compiler: Netbeans
 * This program reads three int values in different text files at the same time one by one 
 * then merges the numbers to a fourth file listing the numbers in order.
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


void mergeFiles(string file1, string file2, string file3){
    
    //variables I will be using in function
    char c, quote = '"';
    int i, j, k;
    
    //open the three files specified 
    ifstream openfile1(file1.c_str(), ios::in);
    ifstream openfile2(file2.c_str(), ios::in);
    int size = 50; vector <int> numbers(size);
    ifstream openfile3(file3.c_str(), ios::in);
    
    //Ask user to enter name for their merging text file then creates it/opens it
    string outputname;
    cout << "What would you like to call your merging text file (eg: " << quote << "outputfile.txt" << quote<< " )\nOutput File:";
    cin >> outputname;
    int track = 0; for (int i = 0; i < size; i++) 
                   numbers[i] = -999;
    fstream outfile(outputname.c_str(), ios::in | ios::out | ios::app);
    
    //Check to see if the file specified open successfully otherwise output an error message!
    if (openfile1.fail()){ 
        cout << "File " << quote << file1 << quote << " cannot be found or opened!"; 
    }
    else if (openfile2.fail()){ 
        cout << "File " << quote << file2 << quote << " cannot be found or opened!"; 
    }
    else if (openfile3.fail()){ 
        cout << "File " << quote << file3 << quote << " cannot be found or opened!"; 
    }
    else {
    //Here I check to see if the first file specified has a next int value to scan
    while (openfile1.good()) { 
    openfile1 >> numbers[track];
    track++;
    c = openfile1.get();  
    }
    
    //Here I check to see if the second file specified has a next int value to scan
    while (openfile2.good()) { 
    openfile2 >> numbers[track];
    track++;
    c = openfile2.get(); 
    } 
    
    //Here I check to see if the third file specified has a next int value to scan
    while (openfile3.good()) { 
    openfile3 >> numbers[track];
    track++;
    c = openfile3.get(); 
    }
   
    //This for loop is to keep track of elements being compared
    for (j = 0; j <size-1; j++) {
    k = j;
    for ( i = j+1; i < size; i++) {
    if (numbers[i] < numbers[k]) {
    k = i;}
    }
        
    //If statement to check which value is larger
    if(k != j) {
    swap(numbers[j], numbers[k]);
        }
    }
 
    //writes the int values scanned in the same line into the output text file specified
    for (int i = 0; i < size; i++){
        if (numbers[i] != -999)
        outfile << numbers[i] <<"\r\n";
    }
      
//closes all files respectively
openfile1.close();
openfile2.close();
openfile3.close(); 
outfile.close();

//Prints message to user everything was successful and the name of the text file they outputted too
cout << "Success! Your merged text file is done and is called "<< quote << outputname << quote;
 }

}

int main() {
    //Make string variables to hold the names of the files
    string file1, file2, file3;
    char quote = '"';
    //Ask user to input the file names
    cout << "What are the three file names you are going to be using? (eg: " <<  quote << "test.txt" << quote << ")" << endl;
        cout<<"File 1:";
            getline(cin, file1); 
        cout << "File 2:";   
            getline(cin, file2); 
        cout << "File 3:";
            getline(cin, file3);
        
    //Send file names to mergeFiles() to make 4th file 
    mergeFiles(file1, file2, file3);
    

    return 0;
}

