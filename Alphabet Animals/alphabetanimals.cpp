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

    while(cin >> word) 
        potentialWords[word[0]].emplace_back(word);

    word.clear();
    char startingLetter = initialWord[initialWord.length() - 1];
    vector<string> wordList;

    if(potentialWords.find(startingLetter) != potentialWords.end()) {
        wordList.reserve(potentialWords[startingLetter].size());

       while(potentialWords[startingLetter].size() > 0) {
            string temp = potentialWords.at(startingLetter).at(0);
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

            wordList.push_back(temp);
        }

        if(word.empty())
            word = wordList.at(0);
    }else
        word = "?";

    cout << word << endl;
    
    return 0;
}