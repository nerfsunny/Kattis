#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main(int argc, char** argv) {
	/*Initiailzing variables
	  num, used to store given input
	  inputSize, used to store the size of the test case

	*/
	int num, inputSize;

	//Initiailzing container, used to construct the reverse order of the given test case
	list<int> numbers;

	//Stores the size of input
	cin >> inputSize;

	//For-loop that iterates through the input
	for(int i = 0; i < inputSize; i++) {
		//Storing number
		cin >> num;

		//Stores number at the front of the list 
		numbers.push_front(num);
	}

	//Outputs values stored in numbers
	for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		cout << *it << endl;

	return 0;
}