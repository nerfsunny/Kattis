#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Method used to determine the validity of Stan's statemebts. It takes in two vectors that contains what numbers were guessed as well as Stan's response to it and the correct number for that round.
   It then iterates through the two vectors to compare each value to the correct number. If it determines that all of Stan's statemennts are correct, then it returns true. Otherwise, it returns false.
 */
bool checkResults(vector<int> numbers, vector<string> results, int correctNumber) {
	//Used to store what the correct response should be when given a guess
	string expectedResponse;

	//For-loop that iterates through the two vectors. Since both vectors are the same size, it does not matter whether one or the other is used
	for(int i = 0; i < numbers.size(); i++) {
		//Checks if correct number was already guessed. If it was, then it automatically returns false as the two vectors contain values from the beginning of the round to result before the correct answer was given
		if(numbers.at(i) == correctNumber)
			return false;

		//Compares the number guessed to the right number. If it is higher, then it executes the first statement. Otherwise, it executes the second statement
		if(numbers.at(i) > correctNumber)
			expectedResponse = "too high";
		else
			expectedResponse = "too low";

		//Checks the expected response with the actual response. If the actual response is the same as the expected response, then it does nothing. Otherwise, it exits the method and returns false
		if(expectedResponse != results.at(i))
			return false;
	}

	//If no issues occurred while iterating through the loop, then it returns true
	return true;
}

int main(int argc, char** argv) {
	//Used to store Stan's response when trying to guess the right number
	vector<string> results;

	//Used to store what numbers were guessed until the right number is guessed
	vector<int> numbers;

	//Used to store the specific response and guess reading the input
	string line, number;

	//Stores the guessed number as well as read the first line of the two inputs
	while(getline(cin, number)) {
		//Checks to see if getline has reached the end of the file
		if(number == "0")
			break;

		//Stores the response to the guessed number as well as the second line of the two inputs
		getline(cin, line);

		//Starts checking validity of Stan's statements once the right number was guessed
		if(line == "right on") {
			//Goes to method that takes the two vectors as well as the correct guess. If the method returns true, then it outputs the first statement. Otherwise, it outputs the second statement
			if(checkResults(numbers, results, stoi(number)))
				cout << "Stan may be honest\n";
			else
				cout << "Stan is dishonest\n";

			//Clears both vectors after determining result
			results.clear();
			numbers.clear();
		}else {
			//Stores command line input in correct vector
			results.push_back(line);
			numbers.push_back(stoi(number));
		}
	}

	return 0;
}
