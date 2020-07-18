#include <iostream>
#include <unordered_set>
#include <cctype>
#include <algorithm>

using namespace std;

//Coverts all characters in string to lower case
void convertToLowerCase(string& str) {
	for(int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
}

int main(int argc, char** argv) {
	//Initializing variable. Used to store input
	string line;

	//Obtaining number of inputs
	getline(cin, line);

	//Storing the number of inputs
	int numberOfInputs = stoi(line);

	//Initializing container. Used to store unique words/phrases from inputs
	unordered_set<string> uniquePhrases;

	//Allocating size for maximum amount, which is numberOfInputs
	uniquePhrases.reserve(numberOfInputs);

	//For-loop that iterates through all of the inputs
	for(int i = 0; i < numberOfInputs; i++) {
		//Storing word/phrase in line
		getline(cin, line);

		//Converting line to lowercase
		convertToLowerCase(line);

		//If line contains at -, it goes throughs line and replaces every instance of - with a space
		if(line.find("-") != string::npos)
			replace(line.begin(), line.end(), '-', ' ');

		//Checks to see if uniquePhrases contains line. If it doesn't, then it adds it to uniquePhrases
		if(uniquePhrases.find(line) == uniquePhrases.end())
			uniquePhrases.emplace(line);
	}

	//Outputs the number of unique words
	cout << uniquePhrases.size() << endl;

	return 0;
}