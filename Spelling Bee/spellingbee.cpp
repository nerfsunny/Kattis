#include <iostream>
#include <string>

using namespace std;

//Checks if the given word is valid to use, given the conditions outlined in the prompt
bool isValid(const string& word, const string& givenLetters) {
	//Initializing variable, used to determine if word contains the specified letter (which is stored as the first character in givenLetters) that every word needs to contain
	bool containsSpecifcCharacter = false;

	//First, checks if the word meets the minimum size
	if(word.length() < 4)
		return false;

	//Goes through every character in the given word
	for(const char c : word) {
		//Checks if the character is one of seven stored in givenLetters
		if(givenLetters.find(c) == string::npos)
			return false;

		//Checks if the word contains the specifid letter. If it does, it changes containsSpecifcCharacter to true
		if(!containsSpecifcCharacter && c == givenLetters[0])
			containsSpecifcCharacter = true;
	}

	return containsSpecifcCharacter;
}

int main(int argc, char** argv) {
	/* Initializing variables
	 *
	 * word, contains the word that needs to be verified if it is valid to use, given the conditions
	 * givenLetters, contains the approved letters to use in a word 
	 * dictionarySize, contains the number of inputs in the test case
	 */
	string word, givenLetters;
	int dictionarySize;

	//Storing given letters and input size into their respective variables
	cin >> givenLetters >> dictionarySize;

	//Goes through all of the given inputs in a test case
	for(int i = 0; i < dictionarySize; i++) {
		//Storing a given word
		cin >> word;

		//Checks if the word is valid to use in the competition. Outputs it if it is
		if(isValid(word, givenLetters))
			cout << word << endl;
	}

	return 0;
}