#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    int num;
    string initialWord, word;
    map<char, vector<string>> potentialWords;

    cin >> initialWord >> num;

    while(cin >> word) {
        if(potentialWords.find(word[0]) != potentialWords.end()) 
            potentialWords.at(word[0]).push_back(word);
        else {
            potentialWords[word[0]].push_back(word);
        }
    }

    word.clear();
    char startingLetter = initialWord[initialWord.length() - 1];

    if(potentialWords.find(startingLetter) != potentialWords.end()) {
        for(int i = 0; i < potentialWords.at(startingLetter).size(); i++) {
            string temp = potentialWords.at(startingLetter).at(i);
            potentialWords.at(startingLetter).erase(potentialWords.at(startingLetter).begin() + i);

            if(potentialWords.find(temp[temp.length() - 1]) == potentialWords.end()) {
                word = temp + "!";
                break;
            }

            if(potentialWords.find(temp[temp.length() - 1]) != potentialWords.end() && potentialWords.at(temp[temp.length() - 1]).size() == 0) {
                word = temp + "!";
                break;
            }

            potentialWords.at(startingLetter).insert(potentialWords.at(startingLetter).begin() + i, temp);
        }

        if(word.empty())
            word = potentialWords.at(startingLetter).at(0);
    }else
        word = "?";

    cout << word << endl;
    
    return 0;
}