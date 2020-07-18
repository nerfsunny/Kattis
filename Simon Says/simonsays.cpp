#include <iostream>
#include <string>

using namespace std; 

int main(int agrc, char** argv) {
	//Initializing variable. Used to store lines from input
	string line;

	//Getting number of inputs
	getline(cin, line);

	//Storing numberOfInputs
	int numberOfInputs = stoi(line);

	//F0r-loop that iterates through all of the inputs
	for(int i = 0; i < numberOfInputs; i++) {
		//Storing inpur
		getline(cin, line);

		//If-statemebt thar checks if the stirng contains the phrase "Simon Says". If it does, then it outputs the command. Otherwise, it outputs a new line
		if(line.find("simon says") != string::npos)
			//If-statemebt that checks if there is anything past the phrase "Simon Says". If there isn't, then it outputs a new line. If there is, it outputs the phrase that comes after "Simon Says"
			if(line.length() > 10)
				cout << line.substr(11) << endl;
			else
				cout << endl;
		else
			cout << endl;
	}

	return 0;
}