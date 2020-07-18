#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
	//Initializing variables. line is used to store the full line from input, word is used to store a word from line, pigLatin is used to construct the translated line/words
	string line, word, pigLatin;

	//Initializing vowels with vowels
	set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
	
	//Initializing stringstream
	stringstream ss;

	//Storing end iterator for vowels as it is used frequently
	auto end = vowels.end();

	while(getline(cin, line)) {
		//Passing line to stringstream
		ss.str(line);

		//While-loop that goes through all words in line
		while(ss >> word) {
			//Checks if the first character is a vowel
			if(vowels.find(word[0]) != end)
				//Appends word and piglatin suffix to pigLatin
				pigLatin.append(word + "yay ");
			else {
				//Initializing variable. Used to store the index of the first instance of a vowel in word
				int index;

				//For-loop that iterates through word to find the first instance of a vowel
				for(int i = 0; i < word.length(); i++)
					//If the character at index i is a vowel
					if(vowels.find(word[i]) != end) {
						//Storing index
						index = i;
						break;
					}

				//Adding subsets of word and piglatin suffix to pigLatin
				pigLatin += word.substr(index) + word.substr(0, index) + "ay ";
			}
		}

		//Removing whitespace and outputting
		cout << pigLatin.substr(0, pigLatin.length() - 1) << endl;
		
		//Clearing pigLatin for nextLine
		pigLatin.clear();

		//Clearing ss for next line
		ss.clear();
	}

	return 0;
}