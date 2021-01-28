#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	/* Initializing variables
       inputSize, stores the size of a sub-test case
       setNumber, keeps track of what sub-test to output
       frontIndex, stores what index to store the given input (from left to right)
       backIndex, stores what index to store the given input (from right to left)
       name, stores the person's name
	*/
	int inputSize, setNumber = 1, frontIndex, backIndex;
	string name;

	//Initializing container, used to store the given names in a speciiic order
	vector<string> names;

	//While-loop that checks if it is the start of a sub-test case
	while(cin >> inputSize && inputSize != 0) {
		//Sets the size of names to inputSize
		names.resize(inputSize);

		//Sets values of what indexes to start storing names in names
		frontIndex = 0;
		backIndex = inputSize - 1;

		//Iterates through all of the inputs in a sub-test case
		for(int i = 0; i < inputSize; i++) {
			//Stores name
			cin >> name;

			//If i is even, it stores the name in the front half name. Otherwise, it stores the name in the back half
			if(i % 2 == 0) {
				names.at(frontIndex) = name;
				frontIndex++;
			}else {
				names.at(backIndex) = name;
				backIndex--;
			}
		}

		//Outputs set number
		cout << "SET " << setNumber << endl;

		//Outputs all of the names in names
		for(string& s : names)
			cout << s << endl;

		//Clearing names for next sub-test case
		names.clear();

		//Increments value by 1
		setNumber++;
	}
}