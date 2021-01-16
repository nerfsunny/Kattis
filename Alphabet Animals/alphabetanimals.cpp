#include <iostream>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    /* Initializing variables
        num, stores how many words are being considered in response to the previous player's word choice; not used anywhere in the code
        initialWord, stores the previous player's word
        word, used to store the potential words to use in response to the previous player's word as well as what the current player picks to play
    */
    int num;
    string initialWord, word;

    /* Initialzing container
        key is the starting letter of a list of words
        value is a list of words that share the same starting letter

        Initially, a vector was used here as the value instead of list. However, the implmentation I originally used it for was too slow for the problem restraints.
        I was originally going to use the current implementation with vector, however, list is much faster as erasing and inserting values than vector
    */
    unordered_map<char, list<string>> potentialWords;

    //Storing values into their respective variables
    cin >> initialWord >> num;

    //Storing the rest of the input into the container; checks if there is a key that is the first letter in word; 
    //If there is, then it stores the word at the end of the list. Otherwise, it creates a new entry with the startingLetter being the key and the word being the first entry in the list
    while(cin >> word) 
        if(potentialWords.find(word[0]) != potentialWords.end())
            potentialWords[word[0]].emplace_back(word);
        else
            potentialWords.insert({word[0], list<string> {word}});

    //Clearing value from word
    word.clear();

    //Storing the letter the next word needs to start with (which is the last letter of the previous word)
    char startingLetter = initialWord[initialWord.length() - 1];

    //Checks if there is an entry that starts with the last letter of the previous word. If there is not, then it stores "?" in word
    if(potentialWords.find(startingLetter) != potentialWords.end()) {
        //Stores the first word in the list that starts with startingLetter
        string firstWord = potentialWords.at(startingLetter).front();

        //Do-while loop that continues until the front-most (or first) word in the list is the same as firstWord
        do {
            //Storing the front-most (or first) word in a temporary string variable
            string temp = potentialWords.at(startingLetter).front();

            //Removes front-most (or first) word from the front of the list
            potentialWords.at(startingLetter).pop_front();

            //Checks if there is potentially a word that starts with the last letter of the word stored in temp. If there is, then false is stored. Otherwise, true is stored
            bool isNotInList = (potentialWords.find(temp[temp.length() - 1]) == potentialWords.end());

            //If there is no word that starts with the last letter of the word in temp, then it stores temp in word, appends an exclamation mark, and breaks the loop
            if(isNotInList) {
                word = temp + "!";
                break;
            }

            //If there is a word that potentially starts with the last letter of the word in temp but the list is empty, then it stores temp in word, appends an exclamation mark, and breaks the loop
            //It essentially checks for words that start and end with the same letter, and are the only word in its list
            if(!isNotInList && potentialWords.at(temp[temp.length() - 1]).size() == 0) {
                word = temp + "!";
                break;
            }

            //Stores the word stored in temp at the end of the list
            potentialWords.at(startingLetter).push_back(temp);
        }while (firstWord != potentialWords.at(startingLetter).front());
    }else
        word = "?";

    //If the best possible word to play can not be determined, then it picks the first word in list
    if(word.empty())
        word = potentialWords.at(startingLetter).front();
    
    //Outputs best word
    cout << word << endl;
    
    return 0;
}