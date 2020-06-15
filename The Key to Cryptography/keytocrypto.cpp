#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	//Initiallizing variables
	string ciphertext, key;
	vector<char> table;

	//Populates vector with characters
	for(int i = 0; i < 26; i++) {
		char letter = 'A' + i;
		table.emplace_back(letter); 
	}

	//Stores input
	cin >> ciphertext >> key;

	//Storing the iterators of the beginning and ending of the table as these values are going to be called a lot
	auto begin = table.begin(), end = table.end();

	//Initiallizing string to build the unencrypted (plaintext string)
	string plaintext = "";

	//For-loop that iterates with respect to the length of the ciphertext
	for(int index = 0; index < ciphertext.length(); index++) {
		//Stores the index of where the key character at value index is in the table
		int shiftValue = distance(begin, find(begin, end, key[index]));
		
		//Extracts the character of ciphertext at value index
		char currentCharacter = ciphertext[index];

		//Stores the index of where the ciphertext character at value index is in the table
		int currentCharacterIndex = distance(begin, find(begin, end, currentCharacter));

		//Initiallizing variable to store the decrypted character
		char plaintextCharacter;

		/*If-else statement that checks whether the ciphertext character index is strictly less than the key index. 
		  If it is, then it calculates what index the plaintext character is at by finding the difference between the two indexes and adding 26
		  Otherwise, it shifts the currentCharacter back by the shiftvalue
		*/
		if(currentCharacterIndex < shiftValue) 
			plaintextCharacter = table.at(26 + currentCharacterIndex - shiftValue);
		else
			plaintextCharacter = currentCharacter - shiftValue;

		//Appending the decrypted character to the end of both the plaintext and the key
		plaintext += plaintextCharacter;
		key += plaintextCharacter;
	}

	//Outputting plaintext
	cout << plaintext << "\n";

	return 0;
}