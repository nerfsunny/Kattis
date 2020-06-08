#include <iostream>
#include <array>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <sstream>

using namespace std;

string getCoordinates(string cipher[][5], const string& str) {
	for(int row = 0; row < 5; row++) 
		for(int col = 0; col < 5; col++) 
			if(cipher[row][col] == str) 
				return to_string(row) + to_string(col);

	return NULL;
}

vector<string> createChunks(string plaintext) {
	vector<string> chunks;

	while(plaintext.length() > 0) {
		if(plaintext.length() == 1) {
			chunks.push_back(plaintext);
			plaintext = "";
		}else if(plaintext.length() == 2) {
			chunks.push_back(plaintext);
			plaintext = "";
		}else {
			chunks.push_back(plaintext.substr(0, 2));
			plaintext = plaintext.substr(2);
		}
	}

	return chunks;
}

int main(int argc, char** argv) {
	//Used to store the two lines of inputs
	string key, plaintext;

	//Used to construct the final string
	string encryptedText = "";

	string temp = "";

	//Table to hold cipherkey
	string cipher[5][5];

	//Storing lines of inputs
	getline(cin, key);
	getline(cin, plaintext);

	//Iterates through the given key to extract all unique letters from it and appends it to a temprorary string
	for(char x : key) {
		if(x != ' ' && temp.find(x) == string::npos)
			temp = temp + x;
	}

	//Checks if the temporary constructed string is the right size to populate the table; if it isn't, then it adds unique characters (meaning letters that are not present in the string already) to it until it reaches a length of 25
	if(temp.length() < 25) {
		char character = 'a';

		while(temp.length() < 25) {
			if(temp.find(character) == string::npos && character != 'q') {
				temp = temp + character;
				character++;
			}else
				character++;
		}
	}

	int index = 0;

	for(int row = 0; row < 5; row++) {
		for(int col = 0; col < 5; col++) {
			cipher[row][col] = temp[index];
			index++;
		}
	}

	istringstream iss(plaintext);
	plaintext = "";

	while(iss >> temp)
		plaintext = plaintext + temp;

	/*while(plaintext.length() > 0) {
		if(plaintext.length() == 1) {
			plaintextChunks.push_back(plaintext);
			plaintext = "";
		}else if(plaintext.length() == 2) {
			plaintextChunks.push_back(plaintext);
			plaintext = "";
		}else {
			plaintextChunks.push_back(plaintext.substr(0, 2));
			plaintext = plaintext.substr(2);
		}
	}*/

	vector<string> plaintextChunks = createChunks(plaintext);

	for(string s : plaintextChunks)
		cout << s << " ";

	cout << endl;

	char c = '';

	for(int i = 0; i < plaintextChunks.size(); i++) {
		
	}

	/*for(string str : plaintextChunks) {
		string c1 = getCoordinates(cipher, str.substr(0, 1));
		string c2 = getCoordinates(cipher, str.substr(1, 1));
		cout << "String: " << str << " C1: " << c1 << " C2: " << c2 << " ";
		string encryptedChunk = "";

		if(c1[0] == c2[0]) {
			int num1 = stoi(c1.substr(1, 1)) + 1;
			int num2 = stoi(c2.substr(1, 1)) + 1;

			if(num1 > 4)
				num1 = 0;

			if(num2 > 4)
				num2 = 0;

			c1 = c1[0] + to_string(num1);
			c2 = c2[0] + to_string(num2);

			int x1 = stoi(c1.substr(0,1)), y1 = stoi(c1.substr(1,1));
			int x2 = stoi(c2.substr(0,1)), y2 = stoi(c2.substr(1,1));

			encryptedChunk = cipher[x1][y1] + cipher[x2][y2];
			cout << "Encrypted Chunk: " << encryptedChunk << " New C1: " << to_string(x1) + to_string(y1) << " New C2: " << to_string(x2) + to_string(y2) << endl;
			encryptedText = encryptedText + encryptedChunk + " ";
		}else if(c1[1] == c2[1]) {
			int num1 = stoi(c1.substr(0, 1)) + 1;
			int num2 = stoi(c2.substr(0, 1)) + 1;

			if(num1 > 4)
				num1 = 0;

			if(num2 > 4)
				num2 = 0;

			c1 = to_string(num1) + c1[1];
			c2 = to_string(num2) + c2[1];

			int x1 = stoi(c1.substr(0,1)), y1 = stoi(c1.substr(1,1));
			int x2 = stoi(c2.substr(0,1)), y2 = stoi(c2.substr(1,1));

			encryptedChunk = cipher[x1][y1] + cipher[x2][y2];
			cout << "Encrypted Chunk: " << encryptedChunk << " New C1: " << to_string(x1) + to_string(y1) << " New C2: " << to_string(x2) + to_string(y2) << endl;
			encryptedText = encryptedText + encryptedChunk + " ";
		}else {
			int x1 = stoi(c1.substr(0,1)), y1 = stoi(c2.substr(1,1));
			int x2 = stoi(c2.substr(0,1)), y2 = stoi(c1.substr(1,1));
			encryptedChunk = cipher[x1][y1] + cipher[x2][y2];
			cout << "Encrypted Chunk: " << encryptedChunk << " New C1: " << to_string(x1) + to_string(y1) << " New C2: " << to_string(x2) + to_string(y2) << endl;
			encryptedText = encryptedText + encryptedChunk + " ";
		}
	}

	//converts all characters to their upper case equivalent
	for(int i = 0; i < encryptedText.length(); i++) 
		encryptedText[i] = toupper(encryptedText[i]);

	//Outputs string
	cout << encryptedText << endl;

	return 0;*/
}