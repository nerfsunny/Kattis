#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <algorithm>

using namespace std;

<<<<<<< HEAD
=======
bool customSortParameters(const pair<string, int>& word1, const pair<string, int>& word2) {
    if(word2.second != word1.second)
        return word2.second < word1.second;
    else
        return word2.first < word1.first;
}

>>>>>>> 7907ab0... Current progress on problem. Currently passes 3/11 tests. Getting 'Wrong Answer'
void countFrequencyOfWords(unordered_map<string, set<string>>& words, unordered_map<string, int>& frequencyWords, set<string>& usernames) {
    string line, username, word;
    stringstream ss;

    getline(cin, line);

    while(getline(cin, line)) {
        ss.str(line);

        ss >> username;

        usernames.emplace(username);

        while(ss >> word) {
            if(words.find(word) != words.end()) {
                words.at(word).emplace(username);
                frequencyWords[word]++;
            }else {
                words.insert({word, set<string>{username}});
                frequencyWords.insert({word, 1});
            }
        }

        ss.clear();
    }
}

vector<pair<string, int>> determineFrequencyOfWords(unordered_map<string, set<string>>& words, unordered_map<string, int>& frequencyWords, set<string>& usernames) {
    vector<pair<string, int>> frequentWords;

    for(auto& kv : words) 
        if(kv.second == usernames) 
            frequentWords.push_back(make_pair(kv.first, frequencyWords.at(kv.first)));

    return frequentWords;
}

int main(int argc, char** argv) {
    set<string> users;
    unordered_map<string, set<string>> words;
    unordered_map<string, int> frequencyWords;

    countFrequencyOfWords(words, frequencyWords, users);
    vector<pair<string, int>> frequentWords = determineFrequencyOfWords(words, frequencyWords, users);

<<<<<<< HEAD
	if(frequentWords.size() != 0)
		cout << "More work needs to be done" << endl;
	else
		cout << "ALL CLEAR" << endl;
=======
    if(frequentWords.size() != 0) {
        sort(frequentWords.begin(), frequentWords.end(), customSortParameters);

        for(const pair<string, int>& word : frequentWords)
            cout << word.first << endl;
    }
    else
        cout << "ALL CLEAR" << endl;
>>>>>>> 7907ab0... Current progress on problem. Currently passes 3/11 tests. Getting 'Wrong Answer'

    return 0;
}