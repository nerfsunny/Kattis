#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	//Initiallizing variable for allocating size of vector
	int keysetSize;

	//Initiallizing vector
	vector<int> keyset;

	while(true) {
		//Storing vector size
		cin >> keysetSize;

		//Checking for end-of-file
		if(keysetSize == 0)
			break;

		//Allocating memory for vector
		keyset.reserve(keysetSize);

		//Initiallizing vector for reading in numbers for input
		int num;

		//For-loop for reading in numbers and storing it in the vector
		for(int i = 0; i < keysetSize; i++) {
			cin >> num;
			keyset.emplace_back(num);
		}

		//Initiallizing variables for storing the plaintext and constructing the ciphertext
		string plaintext, ciphertext = "";

		//Moving cursor to the beginning of the next line
		getline(cin, plaintext);

		//Storing input into the plaintext
		getline(cin, plaintext);

		//If-statement that checks if the plaintext is a multiple of the keysetSize. If it is not, then it appends " " to the plaintext until it reaches the next closest multiple of keysetSize
		if(plaintext.length() % keysetSize != 0) {
			//Calculates the number of spaces needed until the plaintext is a multiple of keysetSize
			int numberOfSpaces = keysetSize - (plaintext.length() % keysetSize);

			//For-loop that appends spaces to the plaintext
			for(int i = 0; i < numberOfSpaces; i++)
				plaintext += " ";
		}

		//While-loop that continues until there is no mmore plaintext to encrypt
		while(plaintext.length() > 0) {
			//Takes a substring from the plaintext that is the length of the keyset from the beginning of the plaintext
			string chunk = plaintext.substr(0, keysetSize);

			//For-loop that goes through all values in the keyset. It extracts the character at index i - 1 from the plaintext chunk and appends it to the ciphertext
			for(int i : keyset)
				ciphertext += chunk[i - 1];

			//Takes a substring from the plaintext that starts at the index of the keysetSize and stores it as the new plaintext
			plaintext = plaintext.substr(keysetSize);
		}

		//Outputs constructed ciphertext to terminal
		cout << "\'" << ciphertext << "\'" << endl;

		//Clearing entries in vector for next input
		keyset.clear();
	}

	return 0;
}

/*
This is another way to complete the problem

	string line;
	vector<int> keyset;

	while(true) {
		getline(cin, line);

		if(line == "0")
			break;

		int space = line.find(" ");
		int keysetSize = stoi(line.substr(0, space));
		
		line = line.substr(space + 1);
		stringstream ss(line);

		keyset.reserve(keysetSize);

		while(getline(ss, line, ' '))
			keyset.emplace_back(stoi(line));

		string plaintext, ciphertext = "";

		getline(cin, plaintext);

		if(plaintext.length() % keysetSize != 0) {
			int numberOfSpaces = keysetSize - (plaintext.length() % keysetSize);

			for(int i = 0; i < numberOfSpaces; i++)
				plaintext += " ";
		}

		while(plaintext.length() > 0) {
			string chunk = plaintext.substr(0, keysetSize);

			for(int i : keyset)
				ciphertext += chunk[i - 1];

			plaintext = plaintext.substr(keysetSize);
		}


		cout << "\'" << ciphertext << "\'" << endl;
		keyset.clear();

*/