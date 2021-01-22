#include <iostream>

using namespace std;
using ull = unsigned long long int;

//Takes the starting number of the sequence and "constructs" its hailstone sequence and its sum as it tries to reach 1
ull hailstoneSequenceSum(ull num) {
	/*If the number is not 1, then it finds the next number in the seqeunce to add to the total
	  If the number is even, then its halved and recursively sent back into the function
	  If the numebr is odd, then the number is tripled, then increased by one and recursively sent back into the function
	*/
	if(num != 1) {
		if(num % 2 == 0)
			return num + hailstoneSequenceSum(num/2);
		else
			return num + hailstoneSequenceSum(3 * num + 1);
	}

	//Base case; stops calculating numbers for the sequence, returns 1 and starts going back up the stack
	return 1;
}

int main(int argc, char** argv) {
	//Initializing variable, used to store a number to start the sequence
	ull number;

	//Storing number
	cin >> number;

	//Calculates the sum of the sequence as it is "constructed" recursively
	cout << hailstoneSequenceSum(number) << endl;
}