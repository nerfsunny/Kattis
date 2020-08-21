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

    while(true) {
        if(potentialWords.find(initialWord[initialWord.length() - 1]) != potentialWords.end()) {
            char letter = initialWord[initialWord.length() - 1];

            for(auto& nextWord : potentialWords.at(letter)) {
                if(potentialWords.find(nextWord[0]) == potentialWords.end()) {
                    word = nextWord + "!";
                    break;
                }
            }

            word = potentialWords.at(letter).at(0);
            break;
        }else {
            word = "?";
            break;
        }
    }

    cout << word << endl;
    
    return 0;
}