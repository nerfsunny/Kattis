#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//Takes string, converts all letters to lower case and returns modified string
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

int main(int argc, char** argv) {
	//Initializing variables. numberOfInputs contains the number of strings/lines to check, line is used to store the input, missingLetters is used to store the letters that do not appear in line
	int numberOfInputs;
	string line, missingLetters;

	//Getting number of inputs
	getline(cin, line);

	//Storing number of inputs
	numberOfInputs = stoi(line);

	//For-loop that iterates through all of the inputs
	for(int i = 0; i < numberOfInputs; i++) {
		//Storing input in line
		getline(cin, line);

		//Converting string to lower case
		line = convertToLowerCase(line);

		//For-loop that goes through all lower case letters. It checks if that letter appears in line. If it doesn't, it appends itself to missingLetters
		for(int j = 0; j < 26; j++) {
			//Initializing lowercase character
			char c = 'a' + j;

			//If-statemebt that checks if the letter is in line. If it isn't, it appends it to missingLetters
			if(line.find(c) == string::npos)
				missingLetters += c;
		}

		//If-else statement that checks if there is any character in missingLetters. If the length is 0, then it outputs pangram. Otherwise, it outputs missingLetters
		if(missingLetters.length() == 0)
			cout << "pangram" << endl;
		else
			cout << "missing " << missingLetters << endl;

		//Clears string
		missingLetters.clear();
	}

	return 0;
}