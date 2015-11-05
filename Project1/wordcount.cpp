/* Ahmed Salem
 * 910017087
 * ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date: September 7, 2014
 * IDE/Compiler: Netbeans
 * This program identifies the most frequent letter and word in a given paragraph
 * then it calculates its frequency.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

void getFreqLetter(string & CparagraphToCount, int size){
    //Made a Char array to get every single letter in the paragraph to be a Char
    char Cparagraph[size];
    for (int i = 0; i < size; i++){
        Cparagraph[i] = CparagraphToCount[i];
    }
    
    //Counter keeps track of how many times a letter appears and it is originally initialized at 0
    int counter[26];
    for (int j = 0; j < 25; j++){
        counter[j] = 0;
    }
    
    //Lower case alphabet
    char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l',
    'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //Cap size alphabet
    char ALPHABET[] = {'A','B','C','D','E','F','G','H','I','J','K','L',
    'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    //This converts all uppercase letters to lower case letters since it should be case insensitive
    //This will also help us later when finding the most frequent 
    for (int i = 0; i < size; i++){
       for (int y = 0; y < 25; y++){
         if (CparagraphToCount[i] == ALPHABET[y])
             CparagraphToCount[i] = alphabet[y];
       }
    }
   
    //for loops counts the letters in the paragraph char by char
    for (int i = 0; i < size; i++){
       for (int y = 0; y < 25; y++){
            if (CparagraphToCount[i] == alphabet[y])
               counter[y] = counter[y] + 1;
        }
    }
   
    //By default most frequent number is 0 and the most frequent letter is ' '
    int largestnumber = 0;
    char largestChar = ' ';
    
    //checks which letter comes up the most then assigns it to largestChar 
    //check the frequency of the letter
    int large;
    for (int j = 0; j < 26; j++){
        if (largestnumber < counter[j]){
           largestnumber =  counter[j];
           large = j;
           largestChar = alphabet [j];
        }
    }
    
    //This will check if some words have the same frequency
    //If they do then there would be no frequent word since multiple words have the same frequency
    int noLarge = 0;
    for (int k = large; k < 25; k++){
        if (largestnumber == counter[k + 1]){
            noLarge++;
        }
    }
    for (int k = large; k >= 0; k--){
        if (largestnumber == counter[k - 1]){
            noLarge++;
        }
    }
   
    //Displays results based on situation
    if (largestnumber != 0 && noLarge == 0)
        cout << "Most frequent letter is " << largestChar << " with it coming out " << largestnumber << " times" <<endl;
    else if (largestnumber != 0 && noLarge > 0 )
        cout << "No frequent letter since multiple words have frequency of " << largestnumber <<endl;
    else
        cout << "No frequent letter" << endl;
}

//struct with variables word and count to keep track how man times a unique word appears
struct wordFreq{
    string word;
    int count;
};

void countWordFreq(string & paragraph){
    //wordFreq type array to keep track of every unique word and its frequency
     //Assign all counts to 1
    wordFreq wordAppear [100];
    for (int k = 0; k<99; k++)
        wordAppear[k].count = 1;
    string fparagraph = paragraph + " ";
    string words[100];
    int size = fparagraph.length();
    
    //int front and int back will keep track when a word ends and begins and have been initialized to 0
    int front[100];
    for (int i=0; i< 99; i++)
	front[i] = 0;
    int back[100];
    for (int i=0; i< 99; i++)
	back[i] = 0;
    
    //track will keep count of how many words there are
    int track = 0;
    char quote = '"';
    
    // This for loop gets keeps track of when a word starts and ends by using delimeters 
    //It also initializes all the words in the paragraph into the wordFreq type array 
    for (int j = 0; j <size; j++ ){
       if (fparagraph[j] == ' ' || fparagraph[j] == '.' || fparagraph[j]== '?' || fparagraph[j]== '!' || fparagraph[j]== ',' || fparagraph[j] == ';'){
           back[track]= j;
           int wordLength =  back[track] - front[track];
           words[track].insert(0,paragraph,front[track], wordLength);
           wordAppear[track].word = words[track];
           track++;
           front[track]= back[track-1]+1;
       }
    }
    
    //This for loop counts the frequency of the appearance of the unique word
    for (int i = 0; i < 100; i++){
        for (int j = i+1; j < 100;j++){
            if((wordAppear[i].word.compare(wordAppear[j].word)== 0) && (!wordAppear[i].word.empty())){
               wordAppear[i].count = wordAppear[i].count + 1;
              wordAppear[j].word = wordAppear[99].word;
            }
        }
    }
    
    //By default the most frequent string is " " with a count of zero
    int largestnumber = 0;
    string largestString = " ";
    
    //This for loop checks which letter comes up the most then assigns it to largestChar 
    //largestNumber keeps track of the frequency
    int large;
    for (int j = 0; j < 99; j++){
        if (largestnumber < wordAppear[j].count){
           largestnumber =  wordAppear[j].count;
           large = j;
           largestString = wordAppear[j].word;
        }
    }
     
    //This will check if some words have the same frequency
    //If they do then there would be no frequent word since multiple words have the same frequency
    int noLarge = 0;
    for ( int k = large; k < 99; k++){
        if (largestnumber == wordAppear[k + 1].count && !wordAppear[k+1].word.empty()){
          noLarge++;
             
        }
    }
    for ( int k = large; k >= 0; k--){
        if (largestnumber == wordAppear[k - 1].count && (!wordAppear[k].word.empty())){
            noLarge++;
        }
    }

    //This will check to see if there is atleast one word inputed to choose the right result
    int oneNumber = -2;
    for ( int k = 0; k < 99; k++){
        if (!wordAppear[k].word.empty()){
            oneNumber++;
        }
    }
    
    //Displays results based on situation
    if ( largestnumber >= 1 && oneNumber > -2 && noLarge == 0 ){
        cout << "Most frequent word is " <<quote << largestString << quote << " with it coming out " << largestnumber << " times" <<endl;
        cout << "Counter| Word"<<endl;
        for (int i = 0; i < 100; i++){
            if(!wordAppear[i].word.empty())
            cout << "  " <<  wordAppear[i].count << "    | " << wordAppear[i].word << endl;
        }
    }
    else if (largestnumber >= 1 && noLarge > 0 && oneNumber > -1){
        cout << "No frequent word since multiple words have frequency of " << largestnumber <<endl;
        cout << "Counter| Word"<<endl;
        for (int i = 0; i < 100; i++){
            if(!wordAppear[i].word.empty())
            cout << "  " <<  wordAppear[i].count << "    | " << wordAppear[i].word << endl;
        }
    }
    else
        cout << "No frequent word" <<endl;
}

int main() {
     //Asking the user for their input paragraph   
    cout << "Enter your paragraph (Up to 100 characters): ";
    string paragraph;
    getline(cin, paragraph);
    
    //Passing the paragraph by reference and its size to getFreqLetter()
    int size = paragraph.length();
    getFreqLetter(paragraph, size);
  
    //Passing the paragraph by reference to countWordFreq()
    countWordFreq(paragraph);
  
    return 0;
}



