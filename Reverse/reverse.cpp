#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	//Initiailzing variable, used to store given input
	int num;

	//Initiailzing container, used to construct the reverse order of the given test case
	vector<int> numbers;

	//Storing the size of the input
	cin >> num;

	//Resizing the vector to the input size so I can store values at a specific index
	numbers.resize(num, 0);

	//For-loop that iterates through the input
	for(int i = numbers.size() - 1; i >= 0; i--) {
		//Storing number
		cin >> num;

		//Stores number at index 
		numbers[i] = num;
	}

	//Outputs values stored in numbers
	for(int i : numbers)
		cout << i << endl;

	return 0;
}