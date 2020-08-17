#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

int convertFromHexToDecimal(string& hexNumber, unordered_map<char, int>& charSet) {
	int sum = 0, power = 0;

	for(int i = hexNumber.length() - 1; i >= 0; i--) {
		sum += (charSet[hexNumber[i]] * pow(16, power));
		power++;
	}

	return sum;
}

unordered_map<char, int> populateSet() {
	unordered_map<char, int> charSet;

	for(int i = 0; i < 16; i++) {
		if(i < 10) {
			char a = '0' + i;
			charSet[a] = i;
		}else {
			char b = 'A' + (i - 10), c = 'a' + (i - 10);
			charSet[b] = i;
			charSet[c] = i;
		}
	}

	return charSet;
}

string getHexString(string& line, const int index, const unordered_map<char, int>& charSet) {
	string hex = line.substr(index, 2);
	auto end = charSet.end();

	for(int i = index + 2; i < line.length(); i++) {
		if(charSet.find(line[i]) != end)
			hex.append(line.substr(i, 1));
		else {
			line = line.substr(i + 1);
			break;
		}
	}

	return hex;
}

set<int> hexStringStartingIndexes(string line, unordered_map<char, int> charSet) {
	set<int> indexes;

	while(!line.empty()) {

	}

	return indexes;
}

int main(int argc, char** argv) {
	string line;
	unordered_map<char, int> charSet = populateSet();

	while(cin >> line) {
		set<int> indexes = hexStringStartingIndexes(line, charSet);
	}

	return 0;
}