#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

//initializes unordered_map. Keys are all lower case alphabetic characters ('a' - 'z') and values are empty string vectors 
unordered_map<char, vector<string>> initializeTable() {
	//Initializing unordered_map
	unordered_map<char, vector<string>> table;
	
	//For-loop that populates table
	for(int i = 0; i < 26; i++) {
		char key = 'a' + i;
		vector<string> wordList;
		table[key] = wordList;
	}

	//Returns initialized table
	return table;
}

//Takes a string and converts its letters to lowercase
string convertToLowerCase(string& word) {
	//Initializing variable
	string lowercase = "";

	//Allocating size of string lowercase to length of word
	lowercase.reserve(word.length());

	//For-loop that iterates through the word. It converts the character to its equivalent lowercase and appends it to string lowercase
	for(char x : word)
		lowercase += tolower(x);

	//Returns lowercase string
	return lowercase;
}

//Checks if string vector contains word. If it does, it returns true; otherwise, it returns false
bool checkDictionary(vector<string>& wordList, string& word) {
	if(find(wordList.begin(), wordList.end(), word) != wordList.end())
		return true;

	return false;
}

int main(int argc, char** argv) {
	/*Initializing string variables:
      sentence stores the entire line of input
      word is used to store each word in sentence
      lowercaseWord is the lowercase counterpart of word
      newSentence is modified sentence that removes all duplicate words found at that point in the sentence
	*/
	string sentence, word, lowercaseWord, newSentence = "";

	//Initializing stringstream
	stringstream ss;

	//Initializing and populating unordered_map
	unordered_map<char, vector<string>> dictionary = initializeTable();

	//Allocating size of string to potential maximum
	sentence.reserve(100);
	newSentence.reserve(100);

	//While-loop that goes through each line of the input and stores it in sentence
	while(getline(cin, sentence)) {
		//Passing sentence to stringstream
		ss.str(sentence);

		//While-loop that goes through each string (separated by space)
		while(ss >> word) {
			//Converts word to lowercase
			lowercaseWord = convertToLowerCase(word);

			/*Checks if the lowercaseWord is in the dictionary. If it is, then it appends a . to newSentence. 
			  Otherwise, it adds lowercaseWord to dictionary and appends lowercaseWord to newSentence
			*/
			if(!checkDictionary(dictionary[lowercaseWord[0]], lowercaseWord)) {
				dictionary[lowercaseWord[0]].push_back(lowercaseWord);
				newSentence += (word + " ");
			}else
				newSentence += (". ");
		}

		//Removing whitespace from end of string
		newSentence = newSentence.substr(0, newSentence.length() - 1);

		//Outputting modified sentence
		cout << newSentence << "\n";

		//Resetting stream to accept next input sentence in-loop
		ss.clear();

		//Resetting string for next modified sentence
		newSentence = "";
	}

	return 0;
}