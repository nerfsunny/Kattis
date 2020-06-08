#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	//Stores the initial input
	string line;

	//Stores the two number inputs from the line
	int input1, input2;

	//Counter for how many carry operations are needed for the two specified numbers
	int numberOfCarryOperations = 0;

	//Stores the final tally of the specific calculation in the vector
	vector<int> results;

	while(getline(cin, line)) {
		//Checks for End-of-File; if it reaches it, it breaks the loop
		if(line == "0 0")
			break;

		//Finds the index for the space character in the string
		int spaceIndex = line.find(" ");

		//Uses substring to extract the first number
		input1 = stoi(line.substr(0, spaceIndex));

		//Uses substring to extract the second number
		input2 = stoi(line.substr(spaceIndex + 1));

		//Used to store the current digit the program is on for the first and second number respectively
 		int digit1, digit2;

 		//Adds the carry over value to the next calculation if the current calculation is over 10
 		int carryOver = 0;

 		//While-loop that runs until both number reaches 0
		while(input1 != 0 || input2 != 0) {
			//Mods the number to extract the right-most digit from each number
			digit1 = input1 % 10;
			digit2 = input2 % 10;

			/*
			    Checks if the sum of these two digits (as well as the carryover if there is one) is at least 10 or more
			    If it is, then the counter increases by 1 and carryOver stores a 1 for the next operation.
			    If not, then the carryOver stores a 0
			*/
			if(digit1 + digit2 + carryOver >= 10) {
				numberOfCarryOperations++;
				carryOver = 1;
			}else
				carryOver = 0;

			/*
			Alternatively, the check condition can go here (if the while-loop was set to continue while it is true).
			The reason carryOver must be zero is for a situtation where there are three or more consecutive carry-overs (eg. 9999 1) in a calculation
			if((input1 == 0 || input2 == 0) && carryOver == 0)
				break;
			*/

			//Moves the decimal to the left by 1
			input1 = input1/10;
			input2 = input2/10;
		}

		//Stores the result in the vector
		results.push_back(numberOfCarryOperations);

		//Resets counter back to zero for the next input
		numberOfCarryOperations = 0;
	}

	//Iterates through the vector to output the result of each calculation in the style specified in the prompt
	for(int x : results) {
		if(x == 0)
			cout << "No carry operation.\n";
		else if (x == 1)
			cout << x << " carry operation.\n";
		else
			cout << x << " carry operations.\n";
	}

	return 0;
}