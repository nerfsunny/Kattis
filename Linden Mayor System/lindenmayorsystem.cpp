#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

//Used to store all of the rules for a given test case
void populateRuleSet(unordered_map<char, string>& ruleSet, const int numberOfRules, stringstream& ss) {
	/* Initializing variables,
	 * 
	 * leftSide, stores the left side of the given rule
	 * rightSide, stores the right side of the given rule
	 * line, used to store an entire line from the input
	 * arrow, used to store the string that associates the left and right side of the rule
	 */
	char leftSide;
	string line, arrow, rightSide;

	//Goes through all of the rules in the given test case
	for(int i = 0; i < numberOfRules; i++) {
		//Storing line
		getline(cin, line);

		//Passing it to the stringstream
		ss.str(line);

		//Storing values into their respective variables
		ss >> leftSide >> arrow >> rightSide;

		//Storing it in its container
		ruleSet.insert({leftSide, rightSide});

		//Clearing stream for the next rule
		ss.clear();
	}
}

//Constructs a fractal string to its [blank] iteration (stored in iterations) based on the given rules for the test case
void constructFractalString(const unordered_map<char, string>& ruleSet, const int iterations) {
	/* Initializing variables,
	 *
	 * currentString, 
	 * newString, used to store the construction of a new string based on the characters in currentString and the rules stored in ruleSet
	 */
	string currentString, newString = "";

	//Storing the original version of the string
	getline(cin, currentString);

	//Continues until it has reached the desired iteration
	for(int i = 1; i <= iterations; i++) {
		/* Goes through each character in currentString. 
		 * If the character has a rule defined in ruleSet, it appends the result of that rule to newString. 
		 * Otherwise, it appends the current character to newString
		 */
		for(const char c : currentString)
			if(ruleSet.find(c) != ruleSet.end())
				newString += ruleSet.at(c);
			else
				newString += c;

		//Stores the new string in current string
		currentString = newString;

		//Resets value for the next iteration
		newString = "";
	}

	//Outputs current iteration of currentString
	cout << currentString << endl;
}

int main(int argc, char** argv) {
	/* Initializing variables, 
	 * numberOfRules, stores how many rules there are in the test case
	 * iterations, stores how many times we have to run through the currentString, constructing a newString based on the given rules
	 * line, used to store an entire line from the input
	 * ss, used to split the line along its space character
	 */
	int numberOfRules, iterations;
	string line;
	stringstream ss;

	/* Initializing container, used to store all of the rules for the test case
	 * 
	 * Key is the left side of the rule
	 * Value is the right side of the rule
	 */
	unordered_map<char, string> ruleSet;

	//Storing the first line of the input
	getline(cin, line);

	//Passing it to the stringstream
	ss.str(line);

	//Storing values into their respective variables
	ss >> numberOfRules >> iterations;

	//Clearing stream for next string
	ss.clear();

	//Populating the ruleSet for the given test case
	populateRuleSet(ruleSet, numberOfRules, ss);

	//Constructing the fractal string to iterations
	constructFractalString(ruleSet, iterations);

	return 0;
}