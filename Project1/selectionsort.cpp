/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: September 7, 2014
 * IDE/Compiler: Netbeans
 * This program read a list of integers in a random order then sorts them 
 * from smallest to largest 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr , int size){
   //variables for the for loops and a min variable as well
    int i,j;
    int min;

   //This for loop is to keep track of elements being compared
    for (j = 0; j < size-1; j++) {
        min = j;
    for ( i = j+1; i < size; i++) {
       if (arr[i] < arr[min]) {
            min = i;
        }
    }
        //If statement to swap which int is the min
        if(min != j) {
            swap(arr[j], arr[min]);
        }
    }

//prints out the ordered list
cout << "List: ";
    for (int m = 0; m < size;m++)
        cout << arr[m] << " ";
    }

int main() {
//Ask user of how many numbers are they going to input
cout << "How many numbers are you going to input: ";
    int inputSize;
    cin >> inputSize; 
    
//declare vector of inputSize length
vector <int> numbers(inputSize);
    
//Ask user to enter list of numbers
 cout << "Enter your list of numbers (eg: 23 5 64 12...): ";
    for (int y =0; y < inputSize; y++)
    cin >> numbers[y];

//Send vector and its size to selectionSort function
 int size = numbers.size();
 selectionSort(numbers, size);

  return 0;
}

