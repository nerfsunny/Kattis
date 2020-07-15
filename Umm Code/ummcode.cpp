#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;

set<char> populateSet() {
	set<char> charSet;

	for(int i = 0; i < 26; i++) {
		char c = 'a' + i;

		if(c != 'u' && c != 'm')
			charSet.emplace(c);
	}

	return charSet;
}

void convertToLowerCase(string& sentence) {
	for(int i = 0; i < sentence.length(); i++) 
		sentence[i] = tolower(sentence[i]);
}

string convertFromStringToByteCode(string& um) {
	string umByteCode;

	for(char x : um) {
		if(x == 'u')
			umByteCode.append("1");
		else if(x == 'm')
			umByteCode.append("0");
		else
			continue;
	}

	return umByteCode;
}

string parseString(string& line, set<char>& charSet) {
	string umLine, word;
	bool umCondition = true;

	stringstream ss(line);

	auto charSetEnd = charSet.end();

	while(ss >> word) {
		for(char x : word)
			if(charSet.find(x) != charSetEnd) {
				umCondition = false;
				break;
			}

		if(umCondition)
			umLine.append(word);

		umCondition = true;
	}

	return umLine;
}

int convertFromBinaryToDecimal(string& binaryNumber) {
	int decimalNumber = 0, power = 0;

	while(binaryNumber.length() > 0) {
		int digit = stoi(binaryNumber.substr(binaryNumber.length() - 1));
		decimalNumber += (digit * pow(2, power));
		power++;
		binaryNumber = binaryNumber.substr(0, binaryNumber.length() - 1);
	}

	return decimalNumber;
}

string convertToString(string& byteCode) {
	string decodedString, chunk;

	while(byteCode.length() > 0) {
		chunk = byteCode.substr(0, 7);
		byteCode = byteCode.substr(7);

		decodedString += (char) convertFromBinaryToDecimal(chunk);
		chunk.clear();
	}

	return decodedString;
}

int main(int argc, char** argv) {
	set<char> charSet = populateSet();
	string line, um;

	getline(cin, line);

	convertToLowerCase(line);

	um = parseString(line, charSet);

	string umByteCode = convertFromStringToByteCode(um);

	line = convertToString(umByteCode);

	cout << line << endl;

	return 0;
}