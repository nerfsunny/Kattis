#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<char, pair<int, int>> initializeTable() {
	unordered_map<char, pair<int, int>> characters;

	char c1 = 'a', c2 = 'A';

	for(int i = 0; i < 26; i++) {
		characters.insert({c1, make_pair(0,0)});
		characters.insert({c2, make_pair(0,0)});
	}

	return characters;
}

int main(int argc, char** argv) {
	int stringLength, equivalentCharacters = 0, characters = 0;
	string cipherText, guessText;
	unordered_map<char, pair<int, int>> countCharacters = initializeTable();

	cin >> stringLength >> cipherText >> guessText;

	for(int i = 0; i < stringLength; i++) {
		if(cipherText[i] == guessText[i])
			equivalentCharacters++;
		else {
			get<0>(countCharacters.at(cipherText[i]))++;
			get<1>(countCharacters.at(guessText[i]))++;
		}
	}

	cout << equivalentCharacters << endl;

	return 0;
}