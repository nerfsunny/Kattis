#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    //Initializing variable; used to store input in words and construct compound words
    string word;

    /*Initializing containers
        words is used to store inputs
        compoundWords is used to store the unique combinations of two words in words
    */
    vector<string> words, compoundWords;

    //While-loop that stores word in words
    while(cin >> word)
        words.push_back(word);

    //Nested for-loop that iterates through all elements in words. For each word w selected in the outer loop, the inner loop goes through the entire words vector and appends it to w
    for(int i = 0; i < words.size(); i++) 
        for(int j = 0; j < words.size(); j++) 
            //Checks if the word is the same; it it is not, it executes the following statements
            if(i != j) {
                //Combines the words found at index i and j and stores it in word
                word = words.at(i) + words.at(j);

                //Checks if word is already in compoundWords; if it is not, then it stores it
                if(find(compoundWords.begin(), compoundWords.end(), word) == compoundWords.end())
                    compoundWords.push_back(word);
            }

    //Sorts compoundWords in alphabetical order
    sort(compoundWords.begin(), compoundWords.end());

    //For-loop that outputs every word in compoundWords
    for(string& s : compoundWords)
        cout << s << endl;
    
    return 0;
}