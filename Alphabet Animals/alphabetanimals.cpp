#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    int num;
    string initialWord, word;
    unordered_map<char, vector<string>> potentialWords;

    cin >> initialWord >> num;

    while(cin >> word) 
        if(potentialWords.find(word[0]) != potentialWords.end())
            potentialWords[word[0]].emplace_back(word);
        else
            potentialWords.insert({word[0], vector<string> {word}});

    word.clear();
    char startingLetter = initialWord[initialWord.length() - 1];
    vector<string> wordList;

    if(potentialWords.find(startingLetter) != potentialWords.end()) {
        for(int i = potentialWords.at(startingLetter).size() - 1; i >= 0; i--) {
            string temp = potentialWords.at(startingLetter).at(i);
            
            potentialWords.at(startingLetter).erase(potentialWords.at(startingLetter).begin() + i);
            bool isNotInList = (potentialWords.find(temp[temp.length() - 1]) == potentialWords.end());

            if(isNotInList) {
                word = temp + "!";
                break;
            }

            if(!isNotInList && potentialWords.at(temp[temp.length() - 1]).size() == 0) {
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