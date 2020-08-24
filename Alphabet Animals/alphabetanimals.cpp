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

            if(potentialWords.at(letter).size() == 1 && potentialWords.at(letter).at(0)[0] == potentialWords.at(letter).at(0)[potentialWords.at(letter).at(0).length() - 1]) {
                word = potentialWords.at(letter).at(0) + "!";
                break;
            }

            for(int index = 0; index < potentialWords.at(letter).size(); index++) {
                string currentWord = potentialWords.at(letter).at(index);
                potentialWords.at(letter).erase(potentialWords.at(letter).begin() + index);

                if(potentialWords.find(currentWord[currentWord.length() - 1]) == potentialWords.end()) {
                    word = currentWord + "!";
                    break;
                }else
                    potentialWords.at(letter).insert(potentialWords.at(letter).begin() + index, currentWord);                
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