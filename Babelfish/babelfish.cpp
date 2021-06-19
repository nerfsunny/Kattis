#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

void storeDefinitions(unordered_map<string, string>& dictionary) {
    /* Initializing variables,
     * line, used to store a specific line in the input (each line contains the english word and its equivalent foreign word)
     * englishWord, used to store the english word from line
     * foreignWord, used to store the foreign word from line
     */
    string line, englishWord, foreignWord;
    
    //used to separate the two words in the input line
    stringstream ss;
    
    //While-loop that continues until it reaches the empty line in the input
    while(getline(cin, line) && !line.empty()) {
        //Passes line to stringstream
        ss.str(line);
        
        //Stores the two words in their respective variables
        ss >> englishWord >> foreignWord;
        
        //Stores in dictionary
        dictionary.insert({foreignWord, englishWord});
        
        //Clears stream for next line in the input
        ss.clear();
    }
}

void translateWords(const unordered_map<string, string>& dictionary) {
    //Initializing variables, used to store the foreign word from the input
    string foreignWord;
    
    //While-loop that continues until it reaches the end of the input
    while(getline(cin, foreignWord)) {
        //Checks if the word is in the dictionary. If so, outputs the english equivalent. Otherwise, outputs "eh"
        if(dictionary.find(foreignWord) != dictionary.end())
            cout << dictionary.at(foreignWord) << endl;
        else
            cout << "eh" << endl;
    }
}

int main(int argc, char** argv) {
    //Initializing container, used to store the foreign word and english word pairs
    unordered_map<string, string> dictionary;
    
    //Storing definitions in dictionary
    storeDefinitions(dictionary);
    
    //Taking foreign words and outputs an english equivalent, if applicable
    translateWords(dictionary);
    
    return 0;
}
