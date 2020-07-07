#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

ull calculateCheckDigit(string& ucn, unordered_map<string, string>& confusedDigitTable, unordered_map<string, int>& digitTable) {
	ull result = 0;
	string c;

	for(int digit = 0; digit < 8; digit++) {
		if(confusedDigitTable.find(ucn.substr(digit, 1)) != confusedDigitTable.end())
			c = confusedDigitTable[ucn.substr(digit, 1)];
		else
			c = ucn.substr(digit, 1);

		int charValue = digitTable[c];

		switch(digit) {
			case 0:
				result = result + (2 * charValue);
				break;
			case 1:
				result = result + (4 * charValue);
				break;
			case 2:
				result = result + (5 * charValue);
				break;
			case 3:
				result = result + (7 * charValue);
				break;
			case 4:
				result = result + (8 * charValue);
				break;
			case 5:
				result = result + (10 * charValue);
				break;
			case 6:
				result = result + (11 * charValue);
				break;
			case 7:
				result = result + (13 * charValue);
				break;
			default:
				break;
		};
	}

	return result;
}

ull convertFromBase27ToBase10(string ucn) {
	ull number = 0;
	int power = 0;

	for(int i = ucn.length() - 1; i >= 0; i--) {
		int digit = stoi(ucn.substr(i, 1));
		number = number + (digit * pow(27, power));
		power++;
	}

	return number;
}

unordered_map<string, int> populateTable(unordered_map<string, string>& confusedDigitTable) {
	unordered_map<string, int> table;
	int offset = 0;

	for(int i = 0; i < 36; i++) {
		if(i < 10) {
			table[to_string(i)] = i;
		}else {
			char c = 'A' + (i - 10);
			string s(1, c);

			if(confusedDigitTable.find(s) == confusedDigitTable.end())
				table[s] = i - offset;
			else
				offset++;
		}
	}

	return table;
}

int main(int agrc, char** argv) {
	int numberOfInputs, lineNumber;
	unordered_map<string, string> confusedDigitTable({{"B", "8"}, {"G", "C"}, {"I", "1"}, {"O", "0"}, {"Q", "0"}, {"S", "5"}, {"U", "V"}, {"Y", "V"}, {"Z", "2"}});
	unordered_map<string, int> digitTable = populateTable(confusedDigitTable);
	string ucn;

	cin >> numberOfInputs;

	for(int i = 1; i <= numberOfInputs; i++) {
		cin >> lineNumber >> ucn;
		ull ucnValue = calculateCheckDigit(ucn, confusedDigitTable, digitTable);
		string checkDigit(1, ucn[8]);

		if(confusedDigitTable.find(checkDigit) != confusedDigitTable.end())
			checkDigit = digitTable[checkDigit];

		if((ucnValue % 27) == digitTable[checkDigit])
			cout << lineNumber << " " << convertFromBase27ToBase10(ucn.substr(0, 8)) << endl;
		else
			cout << lineNumber << " Invalid" << endl;
	}

	return 0;
}