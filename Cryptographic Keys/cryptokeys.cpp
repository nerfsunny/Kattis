#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using ull = unsigned long long int;

string convertFromBase10(const int base, ull number, vector<string>& digits) {
	string result = "";

	while(number > 0) {
		int remainder = number % base;
		number = number/base;
		result = digits.at(remainder) + result;
	}

	return result;
}

unordered_map<int, vector<string>> populate() {
	unordered_map<int, vector<string>> table;
	vector<string> digits;

	for(int i = 2; i <= 10; i++) {
		for(int j = 0; j < i; j++)
			digits.push_back(to_string(j));

		table[i] = digits;
		digits.clear();
	}

	for(int i = 0; i < 26; i++) {
		digits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

		for(int j = 0; j <= i; j++) {
			char c = 'A' + j;
			string str(1, c);
			digits.push_back(str);
		}

		table[i + 11] = digits;
	}

	return table;
}

int main(int argc, char** argv) {
	//Initiallizes variable to store number
	ull number;

	//Stores input
	cin >> number;

	unordered_map<int, vector<string>> table = populate();
	unordered_map<int, string> convertedNumbers;

	for(int base = 2; base <= 36; base++) 
		convertedNumbers[base] = convertFromBase10(base, number, table[base]);

	for(auto s : convertedNumbers)
		cout << s.first << " " << s.second << endl;

	int numberOfZeroes = 0, counter, lowestBase = 0;

	for(auto num : convertedNumbers) {
		counter = 0;

		for(int i = num.second.length() - 1; i >= 0; i--)
			if(num.second[i] == '0')
				counter++;
			else
				break;

		cout << "Number: " << num.second << " Base: " << num.first << " Number of Zeroes: " << counter << endl;

		if(counter > numberOfZeroes) {
			numberOfZeroes = counter;
			lowestBase = num.first;
		}else if(counter == numberOfZeroes && num.first < lowestBase) {
			lowestBase = num.first;
		}
	}

	cout << lowestBase << "\n";

	return 0;
}