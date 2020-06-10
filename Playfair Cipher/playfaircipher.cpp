#include <iostream>
#include <array>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <sstream>

using namespace std;

/* Goes through the given cipher table to determine the coordinates for the given string in the table by using a nested for-loop to iterate through; 
   If it finds the given string at coordinates row and column, it returns those two strings (concantenated together with no space) as a result; 
   In the unlikelihood that it is not in the table, it returns NULL
*/
string getCoordinates(string cipher[][5], const string& str) {
	for(int row = 0; row < 5; row++) 
		for(int col = 0; col < 5; col++) 
			if(cipher[row][col] == str) 
				return to_string(row) + to_string(col);

	return NULL;
}

//Takes a given plaintext string and breaks it into string chunks of size 2
vector<string> createChunks(string plaintext) {
	//Initiallizes vector
	vector<string> chunks;

	//While-loop that continues until there are no more plaintext chunks to make
	while(plaintext.length() > 0) {
		//Holds the extracted string chunk so that it can be passed into the vector
		string chunk = "";

		/*Nested if-else statement block that checks to see if the plaintext falls in one of the two expressed conditions before executing a general statement:
		  	1. If the plaintext is of length 1, then it appends itself and the character x to chunk and then stores it in the vector; it then sets the plaintext to "empty"; 
		  	   If not, it goes to the if-else statement block (located in the else) to check condition 2
		  	2. If the first two characters of the plaintext are the same, it extracts the first character of the string, appends it and the character x to chunk and then stores it in the vector; 
		  	   it then uses substring to extract the plaintext string from index 1 to the end of the string;
		  	   If not, it goes to the else statement
		  	3. It extracts the first two characters of the plaintext; then it uses substring to extract the plaintext string from index 2 to the end of the string; then it stores the chunk in the vector
		*/
		if(plaintext.length() == 1) {
			chunk = plaintext + 'x';
			chunks.push_back(chunk);
			plaintext = "";
		}else {
			if(plaintext[0] == plaintext[1]) {
				chunk = plaintext.substr(0, 1) + 'x';
				plaintext = plaintext.substr(1);
				chunks.push_back(chunk);
			}else {
				chunk = plaintext.substr(0, 2);
				plaintext = plaintext.substr(2);
				chunks.push_back(chunk);
			}
		}
	}

	//Returns vector
	return chunks;
}

//Given a cipher table and a list of string chunks, it encrypts each chunk (and then appends it to a working string) to construct an encrypted string 
string encryptString(vector<string>& plaintextChunks, string cipher[][5]) {
	//Used to construct the final string
	string encryptedText = "";

	//For-each loop that iterates through the vector 
	for(string str : plaintextChunks) {
		//Stores the table coordinates of the first character in the chunk
		string c1 = getCoordinates(cipher, str.substr(0, 1));

		//Stores the table coordinates of the second character in the chunk
		string c2 = getCoordinates(cipher, str.substr(1, 1));

		//Used to store the encrypted chunk 
		string encryptedChunk = "";

		/* If-else statement block that checks if the given plaintextChunk falls into one of the three possible conditions:
			1. If the "x-coordinates" (or the row coordinates) of the two characters are the same, it executes the first if-statement
			2. If the "y-coordinates" (or the column coordinates) of the two characters are the same, it executes the second if-statement
			3. If it does pass either of the two previous conditions, it executes the else-statement
		*/
		if(c1[0] == c2[0]) {
			//Increments the "y-coordinate" of the first character by 1
			int num1 = stoi(c1.substr(1, 1)) + 1;

			//Increments the "y-coordinate" of the second character by 1
			int num2 = stoi(c2.substr(1, 1)) + 1;

			//If either of the coordinates are equal to 5, it then sets it to zero; In other words, if given character was already at the end of the column, it wraps around to the beginning of the column
			if(num1 == 5)
				num1 = 0;

			if(num2 == 5)
				num2 = 0;

			//Stores the new coordinates of the first character
			c1 = c1[0] + to_string(num1);

			//Stores the new coordinates of the second character 
			c2 = c2[0] + to_string(num2);

			//Splits the coordinates into their x- and y-components; it then converts them from string to int
			int x1 = stoi(c1.substr(0,1)), y1 = stoi(c1.substr(1,1));
			int x2 = stoi(c2.substr(0,1)), y2 = stoi(c2.substr(1,1));

			//Uses the coordinates to retrieve the element from the table and concatenates the two encrypted characters together
			encryptedChunk = cipher[x1][y1] + cipher[x2][y2];

			//Appends the chunk to the final encrypted string
			encryptedText = encryptedText + encryptedChunk;
		}else if(c1[1] == c2[1]) {
			//Increments the "x-coordinate" of the first character by 1
			int num1 = stoi(c1.substr(0, 1)) + 1;

			//Increments the "x-coordinate" of the second character by 1
			int num2 = stoi(c2.substr(0, 1)) + 1;

			//If either of the coordinates are equal to 5, it then sets it to zero; In other words, if given character was already at the end of the row, it wraps around to the beginning of the row
			if(num1 == 5)
				num1 = 0;

			if(num2 == 5)
				num2 = 0;

			//Stores the new coordinates of the first character
			c1 = to_string(num1) + c1[1];

			//Stores the new coordinates of the second character 
			c2 = to_string(num2) + c2[1];

			//Splits the coordinates into their x- and y-components; it then converts them from string to int
			int x1 = stoi(c1.substr(0,1)), y1 = stoi(c1.substr(1,1));
			int x2 = stoi(c2.substr(0,1)), y2 = stoi(c2.substr(1,1));

			//Uses the coordinates to retrieve the element from the table and concatenates the two encrypted characters together
			encryptedChunk = cipher[x1][y1] + cipher[x2][y2];

			//Appends the chunk to the final encrypted string
			encryptedText = encryptedText + encryptedChunk;
		}else {
			//Takes the x-coordinate of the first character and the y-coordinate of the second character; it then converts them from string to int
			int x1 = stoi(c1.substr(0,1)), y1 = stoi(c2.substr(1,1));

			//Takes the x-coordinate of the second character and the y-coordinate of the first character; it then converts them from string to int
			int x2 = stoi(c2.substr(0,1)), y2 = stoi(c1.substr(1,1));

			//Uses the coordinates to retrieve the element from the table and concatenates the two encrypted characters together
			encryptedChunk = cipher[x1][y1] + cipher[x2][y2];

			//Appends the chunk to the final encrypted string
			encryptedText = encryptedText + encryptedChunk;
		}
	}

	//converts all characters to their upper case equivalent
	for(int i = 0; i < encryptedText.length(); i++) 
		encryptedText[i] = toupper(encryptedText[i]);

	//Returns constructed string
	return encryptedText;
}

int main(int argc, char** argv) {
	//Used to store the two lines of inputs
	string key, plaintext;

	//Temporary string used as middleman throughout certain operations
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

	//Checks if that string is the right size to populate the table; if it isn't, then it adds unique characters (meaning letters that are not present in the string already) to it until it reaches a length of 25
	if(temp.length() < 25) {
		//Initiallizes a character to start at a
		char character = 'a';

		//Continues until the string length is 25
		while(temp.length() < 25) {
			/*If the specified character is not in the string and is also not the letter q, then it is appended to the end of the string and increases the value by 1 (meaning it goes to the next character); 
			  If it is already present in the string, then it increases the value by 1
			*/
			if(temp.find(character) == string::npos && character != 'q') {
				temp = temp + character;
				character++;
			}else
				character++;
		}
	}

	//Used to iterate through the string when populating the table
	int index = 0;

	//Nested for-loop that populates the table
	for(int row = 0; row < 5; row++) {
		for(int col = 0; col < 5; col++) {
			cipher[row][col] = temp[index];
			index++;
		}
	}

	//Passes pliantext phrase to stringstream in order to remove all spacces from the text
	istringstream iss(plaintext);

	//Sets the plaintext to "empty" so that it can be reconstructed
	plaintext = "";

	//While-loop that iterates through the temporary string; it appends itself to the plaintext so that fully reconstructed plaintext does not have any spaces
	while(iss >> temp)
		plaintext = plaintext + temp;

	//Passes plaintext to method createChunks() so construct vector 
	vector<string> plaintextChunks = createChunks(plaintext);

	//Passes vector and table to method encryptString() to construct the encrypted string; outputs string
	cout << encryptString(plaintextChunks, cipher) << endl;

	return 0;
}