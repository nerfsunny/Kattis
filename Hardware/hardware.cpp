#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Takes a string that contains lowerBound, upperBound and increment counter, generates eligible numbers in the range and stores it into the vector
void fillOrders(vector<string>& numbers, string& str) {
	//Extracts the first number from str
	int lowerBound = stoi(str.substr(0, str.find(" ")));
	str = str.substr(str.find(" ") + 1);

	//Extracts the second number from str
	int upperBound = stoi(str.substr(0, str.find(" ")));
	str = str.substr(str.find(" ") + 1);

	//Extracts third number from str
	int counter = stoi(str.substr(0, str.find(" ")));
	str = "";

	//For-loop that generates expected numbers in range [lowerBound, upperBound] and stores it into the vector
	for( ; lowerBound <= upperBound; lowerBound += counter) 
		numbers.push_back(to_string(lowerBound));
}

//Iterates through all of the elements in vector, counts total number of occurrences of a digit in all of the elements and outputs it; also, it outputs the total number of digits needed for the order
void printOrders(vector<string>& numbers) {
	//Initializing variables. num is used to count how many of a specified digit appear, sum stores the total number of digits needed for the order
	int num = 0, sum = 0;

	//For-loop that iterates through all of the digits
	for(int i = 0; i < 10; i++) {
		//Used as char equivalent of i
		char c = '0' + i;

		//For-loop that iterates through all elements in numbers. Counts number of instances of i in each number and adds it to num
		for(string s : numbers)
			num += count(s.begin(), s.end(), c);

		//Outputs num
		cout << "Make " << num << " digit " << c << endl;
		
		//Adds num to sum
		sum += num;

		//Resets num
		num = 0;
	}

	//Determines the right output for total
	if(sum == 1)
		cout << "In total " << sum << " digit" << endl;
	else
		cout << "In total " << sum << " digits" << endl;
}

int main(int argc, char** argv) {
	/*Initializing variables:
		line is used to store input
		address is used to store address for the order
		workOrder stores the number of orders for that address
		numbers stores the 
	*/
	string line, address, workOrder;
	vector<string> numbers;

	//Gets the number of work orders
	getline(cin, line);

	//Stores the number of work orders
	int numberOfInputs = stoi(line);

	//For-loop that iterates through all of the orders
	for(int i = 0; i < numberOfInputs; i++) {
		//Stores address
		getline(cin, address);

		//Stores workOrder
		getline(cin, workOrder);

		//Extracts number from workOrder and stores it
		int orderNumbers = stoi(workOrder.substr(0, workOrder.find(" ")));

		//While-loop that continues until the vector size is equal to orderNumbers
		while(numbers.size() != orderNumbers) {
			//Stores number(s) that need to be created
			getline(cin, line);

			/*If-statement that checks whether the input is a range or not. 
			 If it is, then it passes the range and vector into fillOrders to get the eligible numbers from the range. 
			 Otherwise, it passes the number into the vector
			*/
			if(line[0] == '+') {
				line = line.substr(2);
				fillOrders(numbers, line);
			}else 
				numbers.emplace_back(line);
		}

		//Outputs address
		cout << address << endl;

		//Outputs workOrder
		cout << workOrder << endl;

		//Outputs number of digits for each digit and total number of digits needed to fulfill the order
		printOrders(numbers);

		//Clears vector
		numbers.clear();
	}

	return 0;
}