#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

//Updates the duration of a customer's time in the park
void updateRecord(map<string, int>& customers, const string& line) {
	/* Initializing variables
	 *
	 * time, stores what time the customer either entered or left the park
	 * factor, used to determine if time needs to be added or subtracted to the total stored in customers.
	 * state, used to determine whether factor needs to be a positive or negative value
	 * name, stores the customer's name
	 * ss, used to split a given line along its space character
	 */
	int time, factor = 1;
	string state, name;
	stringstream ss(line);

	//Storing values into their respective variables
	ss >> state >> name >> time;

	//If the state is ENTER, then it sets factor to -1. Otherwise, it sets factor to 1 
	if(state == "ENTER")
		factor = -1;
	else
		factor = 1;

	/* Checks if the customer already exists in customers. If they do, then the result of (time * factor) is added to the current value associated with customer
	 * Otherwise, a new entry is added with the customer's name as the key and the result of (time * factor) is the value
	 */
	if(customers.find(name) != customers.end())
		customers.at(name) += (time * factor);
	else
		customers.insert({name, time * factor});
}

int main(int argc, char** argv) {
	/* Initializing variables
	 *
	 * day, keeps track of what subcase the program is running through
	 * line, used to store an entire line of an input
	 */
	int day = 1;
	string line;

	/* Initializing container, used to store the total amount of time a customer stayed in the park
	 * 
	 * Key is the customer's name
	 * Value is the total duration of the customer's time spent in the park
	 */
	map<string, int> customers;

	//Continues until it has reached the end of the input
	while(getline(cin, line)) {
		/* Runs on one of three conditions
		 *
		 * 1. If the line is "OPEN", then it signals the start of a new subcase. If the day is greater than one, it will then output a new line to the output. This is to separate the outputs of the multiple subcases.
		 * 2. If the line is "CLOSED", then it calculates how much each customer owes by taking the total duration of their and multiplying it by 0.1. It then outputs the customer name and this value
		 * 3. Otherwise, it either adds a customer to customers to start keeping track of their total duration or updates their total duration at the park
		 */
		if(line == "OPEN") {
			if(day != 1)
				cout << endl;
		}else if(line == "CLOSE") {
			//Outputs the day/subcase
			printf("Day %i\n", day);

			//Iterates through all of the entries in the container, calculates the amount the customer owes and outputs their name and amount
			for(const auto& entry : customers) 
				printf("%s $%.2f\n", entry.first.c_str(), (float) (entry.second * 0.1));

			//Clears container for next subcase
			customers.clear();

			//Increments value by 1
			day++;
		}else 
			updateRecord(customers, line);
	}

	return 0;
}