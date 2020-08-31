#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    unordered_map<string, int> wordValues;
    vector<string> lineChunks;
    string line, chunk, output;
    stringstream ss;
    int result;
    bool pass = true;

    while(getline(cin, line)) {
        if(line == "clear") {
            wordValues.clear();
            continue;
        }

        ss.str(line);

        while(ss >> chunk)
            lineChunks.push_back(chunk);

        if(lineChunks.at(0) == "def") {
            if(wordValues.find(lineChunks.at(1)) == wordValues.end())
                wordValues[lineChunks.at(1)] = stoi(lineChunks.at(2));
            else
                wordValues[lineChunks.at(1)] = stoi(lineChunks.at(2));
        }else {
            if(wordValues.find(lineChunks.at(1)) != wordValues.end())
                result = wordValues[lineChunks.at(1)];

            for(int i = 3; i <= lineChunks.size() - 2; i += 2) {
                if(wordValues.find(lineChunks.at(i)) == wordValues.end()) {
                    pass = false;
                    break;
                }else if(lineChunks.at(i - 1) == "+") {
                    result += wordValues[lineChunks.at(i)];
                }else {
                    result -= wordValues[lineChunks.at(i)];
                }
            }

            for(int i = 1; i < lineChunks.size(); i++)
                cout << lineChunks.at(i) << " ";

            for(auto& x : wordValues) {
                if(x.second == result) {
                    output = x.first;
                    break;
                }
            }

            if(pass && !output.empty()) 
                cout << output << endl;
            else
                cout << "unknown" << endl;
        }
        
        pass = true;
        ss.clear();
        lineChunks.clear();
        output.clear();
    }

    return 0;
}