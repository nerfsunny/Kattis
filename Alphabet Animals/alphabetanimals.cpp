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
    vector<string> wordList;

    if(potentialWords.find(startingLetter) != potentialWords.end()) {
        wordList.reserve(potentialWords.at(startingLetter).size());

        while(potentialWords.at(startingLetter).size() > 0) {
            string temp = potentialWords.at(startingLetter).at(0);
            potentialWords.at(startingLetter).erase(potentialWords.at(startingLetter).begin());

            if(potentialWords.find(temp[temp.length() - 1]) == potentialWords.end()) {
                word = temp + "!";
                break;
            }

            if(potentialWords.find(temp[temp.length() - 1]) != potentialWords.end() && potentialWords.at(temp[temp.length() - 1]).size() == 0) {
                word = temp + "!";
                break;
            }

            wordList.push_back(temp);
        }

        wordList.insert(wordList.end(), potentialWords.at(startingLetter).begin(), potentialWords.at(startingLetter).end());
        potentialWords[startingLetter] = wordList;

        if(word.empty())
            word = potentialWords.at(startingLetter).at(0);
    }else
        word = "?";

    cout << word << endl;
    
    return 0;
}