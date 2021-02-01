#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;
using ull = unsigned long long int;


bool happyPrime(ull num) {
	ull sum = 0, digit;
	unordered_set<ull> numbers;

	while(true) {
		digit = num % 10;
		sum += pow(digit, 2);
		num /= 10;

		if(sum == 1)
			return true;
		else if(numbers.find(sum) != numbers.end())
			return false;

		numbers.emplace(sum);
		num = sum;
		sum = 0;
	}

	return true;
}

int main(int argc, char** argv) {
	int inputSize, tcase, num;

	cin >> inputSize;

	for(int i = 0; i < inputSize; i++) {
		cin >> tcase >> num;

		if(happyPrime(num) && num != 1)
			printf("%i %i %s\n", tcase, num, "YES");
		else
			printf("%i %i %s\n", tcase, num, "NO");
	}
}