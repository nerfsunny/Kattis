#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ull = long long int;

//Calcualtes the sum of all numbers in factors
ull getSum(vector<ull>& factors) {
	//Initializing sum
	ull sum = 0;

	//Iterates through all numbers in factors and adds it to sum
	for(auto& x : factors)
		sum += x;

	//Returns total value
	return sum;
}

//Finds all factors of a given number and stores it in factors
void findFactors(vector<ull>& factors, ull num) {
	//Storing 1 in factors as all numbers greater than 0 are divisible by 1
	factors.emplace_back(1);

	//For-loop that iterates through 2 to the square root of num. This reduces the number of factors needed to check for factors. 
	/*Explanation: 
		If n is not a prime, then we can say that n = a * b, where a and b are two positive integer numbers. We know that a and b cannot both be greater than the sqaure root of n because if they were, then a * b would be greater than n.
		In other words, if n^0.5 * n^0.5 = n, then a and b (which are factors of n) cannot both be greater than the square root of n as the product of these two values would be greater than n. Thus, if a ≠ b, then either a < b or b < a.
		Then, once we find confim one factor of n, we can calculate its compliment value, thus reducing the time needed to find all of the factors.
	*/
	for(ull i = 2; i <= sqrt(num); i++) {
		//If-statement that checks if num is divisible by i
		if(num % i == 0) {
			//Stores i in factors
			factors.emplace_back(i);

			//If-statement that checks if the complement value is not itself
			if(num/i != i)
				//Stores completement value in factors
				factors.emplace_back(num/i);
		}
	}
}

int main(int argc, char** argv) {
	//Initializing variables. num is used to store the number from input, factors is used to store all factors of num
	ull num;
	vector<ull> factors;

	//While-loop that iterates through all inputs
	while(cin >> num) {
		//Detemines all of the factors of a given number
		findFactors(factors, num);

		//Calculates the sum of all factors and stores it in sum
		ull sum = getSum(factors);

		/*If-else statement block that checks if num satifies 1 of 3 possible conditions:
		    1. If sum is equal to num, then it is considered perfect
		    2. If the difference between num and sum is at most 2, then it is almost perfect
		    3. Otherwise it is considered not perfect
		*/
		if(sum == num)
			cout << num << " perfect\n";
		else if(abs(sum - num) <= 2)
			cout << num << " almost perfect\n";
		else
			cout << num << " not perfect\n";

		//Clears vectors
		factors.clear();
	}

	return 0;
}