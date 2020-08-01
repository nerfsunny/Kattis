#include <iostream>
#include <string>
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

int main(int argc, char** argv) {
	string line, hexNumber;
	unordered_map<char, int> charSet = populateSet();

	auto end = charSet.end();

	while(cin >> line) {
		while(!line.empty()) {
			size_t index = line.find("0x");

			if(index != string::npos) {
				string hex = "0x";

				for(int i = index + 1; i < line.length(); i++) {
					if(charSet.find(line[i]) != end)
						hex += line[i];
					else {
						line = line.substr(i + 1);
						break;
					}
				}

				hexNumber = hex.substr(2);
				cout << hex << " " << convertFromHexToDecimal(hexNumber, charSet) << endl;

				continue;
			}

			index = line.find("0X");

			if(index != string::npos) {
				string hex = "0X";

				for(int i = index + 1; i < line.length(); i++) {
					if(charSet.find(line[i]) != end)
						hex += line[i];
					else {
						line = line.substr(i + 1);
						break;
					}
				}

				hexNumber = hex.substr(2);
				cout << hex << " " << convertFromHexToDecimal(hexNumber, charSet) << endl;

				continue;
			};

			if(index == string::npos)
				line.empty();
		}
	}

	return 0;
}