#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

//Calculates the sum of num by summing all of the squared digits
ull calculateSum(ull num) {
	/* Initializing variables
     * sum, stores the total of adding all of the squared digits
     * digit, stores the right-most digit in num
	 */
	ull sum = 0, digit;

	//Continues until there are no more digits
	while(num > 0) {
		//Extracts and stores the right most digit
		digit = num % 10;

		//Squares the value stored in digit and adds it to sum
		sum += pow(digit, 2);

		//Moves the decimal over one to the left
		num /= 10;
	}

	//Returns the total sum
	return sum;
}

//Checks if the number is prime or not; Returns false if it is prime (or true if it is not prime)
bool isNotPrime(ull num) {
	//If the num is even, then it returns true and exits the method
	if(num % 2 == 0)
		return true;

	/* Checks if any number in the range [3, sqrt(num)] is a factor of num; increments by 2 as the number tested here would be odd 
	 * (which is not divisible by any even number)
	 */
	for(int i = 3; i <= (int) sqrt(num); i+=2)
		//If i is a factor of num, then it returns true and exits the method
		if(num % i == 0)
			return true;

	//Returns false as there are no other factors for num other than itself and 1
	return false;
}

bool happyPrime(ull num) {
	//Initializing variable, stores the sum of its squared digits
	ull sum;

	//Initializing container, used to store all of the numbers (or sums) to calculate if num is a happy prime
	unordered_set<ull> numbers;

	//Checks if the number is prime, exits the method with false if the number is not prime
	if(isNotPrime(num)) 
		return false;

	//Continues until it is determined if the number is "happy" or not
	while(true) {
		//Calculates the sum of all of its squared digits
		sum = calculateSum(num);

		/* First, checks if the sum is 1; if it is, then it returns true and exits the method
		 * If it is not 1, then it checks if the value stored in sum has been calculated before and is stored in numbers. 
		 * If it is in numbers, it returns false and exits the method as it indicates that a subset of values in numbers are cyclic
		 */
		if(sum == 1)
			return true;
		else if(numbers.find(sum) != numbers.end())
			return false;

		//Stores the current sum in numbers
		numbers.emplace(sum);

		//Stores sum into num to see if this value will determine if the original num is a happy prime
		num = sum;
	}

	//Here to return some value if for some reason the loop above does not return a value for the method
	return true;
}

int main(int argc, char** argv) {
	/* Initializing variables
	 * inputSize, stores the number of inputs in the test case
	 * tcase, stores the line number from the input
	 * num, stores the number to test
	 */
	int inputSize, tcase, num;

	//Storing number of inputs
	cin >> inputSize;

	//Loop that iterates through the test case
	for(int i = 0; i < inputSize; i++) {
		//Stores the case number and number into their respective variables
		cin >> tcase >> num;

		/* Checks if the number is a happy prime (and is not 1). If it is, it outputs YES; if not then NO. 
		 * It also outputs the case numebr and number itself
		 */
		if(happyPrime(num) && num != 1)
			printf("%i %i %s\n", tcase, num, "YES");
		else
			printf("%i %i %s\n", tcase, num, "NO");
	}
}