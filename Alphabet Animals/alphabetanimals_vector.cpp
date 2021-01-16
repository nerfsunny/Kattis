#include <iostream>
#include <unordered_map>
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

    if(potentialWords.find(startingLetter) != potentialWords.end()) {
        string firstWord = potentialWords.at(startingLetter).front();

        do {
            string temp = potentialWords.at(startingLetter).front();

            potentialWords.at(startingLetter).erase(potentialWords.at(startingLetter).begin());
            bool isNotInList = (potentialWords.find(temp[temp.length() - 1]) == potentialWords.end());

            if(isNotInList) {
                word = temp + "!";
                break;
            }

            if(!isNotInList && potentialWords.at(temp[temp.length() - 1]).size() == 0) {
                word = temp + "!";
                break;
            }

            potentialWords.at(startingLetter).push_back(temp);
        }while (firstWord != potentialWords.at(startingLetter).front());
    }else
        word = "?";

    if(word.empty())
        word = potentialWords.at(startingLetter).front();
    
    cout << word << endl;
    
    return 0;
}