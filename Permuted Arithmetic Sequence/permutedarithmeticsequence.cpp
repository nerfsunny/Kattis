#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//Checks if a given sequence can be considered arithmetic or not. If there is an instance where the absolute difference is different than the absolute difference of two other sequential numbers, it returns false. Otherwise, it returns true
bool isArithmeticSequence(vector<int>& numbers) {
	//Calculates the absolute difference (so that ignpres whether the sequence is increasing or decreasing) between the first two elements
	int difference = abs(numbers.at(0) - numbers.at(1));

	//For-loop that iterates through all elements in the vector, starting at index 1. If there is an instance where the absolute difference between two numbers is different than difference, the function returns false
	for(int k = 1; k < numbers.size() - 1; k++) {
		int difference2 = abs(numbers.at(k) - numbers.at(k + 1));

		if(difference2 != difference)
			return false;
	}

	//Returns true if the difference is constant throughout the sequence
	return true;
}

//Checks if the arithmetic sequence is permuted or not. If it is permuted, then it returns false. If it is not permuted, then it returns true
bool arithmeticSeqeuenceType(vector<int>& number) {
	//If-statement that determines whether the sequence should be considered under an always increasing or always decreasing lens. If it is increasing, it executes the first block; otherwise, it returns the second block
	if(number.at(0) < number.at(1)) {
		//For-loop that iterates through all of the elements in the sequence
		for(int i = 0; i < number.size() - 1; i++) 
			//If-statement that checks if the next element at index i + 1 is less than the current element at index i. If it is, the function returns false
			if(number.at(i + 1) < number.at(i))
				return false;
	}else {
		//For-loop that iterates through all of the elements in the sequence
		for(int i = 0; i < number.size() - 1; i++) {
			//If-statement that checks if the next element at index i + 1 is greater than the current element at index i. If it is, the function returns false
			if(number.at(i + 1) > number.at(i))
				return false;
		}
	}

	//Returns true if the sequence is always increasing or always decreasing
	return true;
}

int main(int argc, char** argv) {
	//Initiallizing vector to store sequence of numbers
	vector<int> sequence;

	//Initiallizes variables. numberofSequences stores the number of sequences for the test case; numberOfInputs stores the number of integers in the sequence; num is used to store the specific number in the sequence
	int numberOfInputs, numberOfSequences, num;

	//Storing the total number of sequences
	cin >> numberOfSequences;

	//For-loop that iterate though the number of lines in the input
	for(int i = 0; i < numberOfSequences; i++) {
		//Stores the number of inputs in the specific sequence
		cin >> numberOfInputs;

		//Allocates space in the vector for the number of inputs in the sequence
		sequence.reserve(numberOfInputs);

		//For-loop that stores the inputs into the vector
		for(int j = 0; j < numberOfInputs; j++) {
			//Taking number in sequence
			cin >> num;

			//Storing number in vector
			sequence.emplace_back(num);
		}

		//Constuctimg second vector by copying elements from the seqeunce vector
		vector<int> sortedSequence(sequence);

		//Sorting newly constructed vector in ascending order
		sort(sortedSequence.begin(), sortedSequence.end());

		//Checks if the sorted sequence can be considered arithmetic or not. If it is, then it checks whether it is arithmetic or permuted. Otherwise, it is non-arithmetic
		if(isArithmeticSequence(sortedSequence)) {
			cout << (arithmeticSeqeuenceType(sequence) ? "arithmetic\n" : "permuted arithmetic\n");
		}else
			cout << "non-arithmetic\n";

		//Clears vector
		sequence.clear();
	}

	return 0;
}