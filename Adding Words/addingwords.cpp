#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    //Initializing containers. wordValues is used to store potential terms in a calculation and their values, lineCHunks is used to store all space separated strings
    unordered_map<string, int> wordValues;
    vector<string> lineChunks;

    //Initializing stream. Used to pass space separated string in lineChunks
    stringstream ss;

    /*Initializing variables
     * line is used to store the command to execute and to store space separated strings when passing to lineChunks, output is used to store the key that is associated with the result of a given expression
     * result is used to store the intermediary and final caluclation of a given expression
     * pass is used as a flag to indicate that a term in a given expression does not exist
     */
    string line, output;
    int result;
    bool pass = true;

    //While-loop that loops through all given inputs
    while(getline(cin, line)) {
        //If-statement that checks if the commnad is clear; if it is, then it clears wordValues and continues to the next input
        if(line == "clear") {
            wordValues.clear();
            continue;
        }

        //Passes line to stringstream
        ss.str(line);

        //While-loop that passes each string separated by a space into lineChunks
        while(ss >> line)
            lineChunks.push_back(line);

        //If-else statement block that checks if the command at is "def" or "calc"
        if(lineChunks.at(0) == "def")
            //Either stores a new Key-Value pair or replaces the value of an existing key in wordValues
            wordValues[lineChunks.at(1)] = stoi(lineChunks.at(2));
        else if(lineChunks.at(0) == "calc") {
            //If-else statement block that checks if the first word value exists; if it does, then it iterates through the rest of the calculation; otherwise, it sets pass to false
            if(wordValues.find(lineChunks.at(1)) != wordValues.end()) {
                //Stores wordValue in result
                result = wordValues[lineChunks.at(1)];

                //For-loop that iterates through every other term in lineChunks
                for(int i = 3; i <= lineChunks.size() - 2; i += 2) {
                    //If-else statement block that determines if wordValue at index i is exists. If it doesn't, then it sets pass to false and breaks out of the loop. If it does, then it determines what operation to perform on result with wordValue
                    if(wordValues.find(lineChunks.at(i)) == wordValues.end()) {
                        pass = false;
                        break;
                    }else if(lineChunks.at(i - 1) == "+") {
                        //Adds wordValue to result
                        result += wordValues[lineChunks.at(i)];
                    }else {
                        //Adds wordValue to result
                        result -= wordValues[lineChunks.at(i)];
                    }
                }
            } else 
                pass = false;

            //For-loop that outputs every term in lineChunks, starting at index 1
            for(int i = 1; i < lineChunks.size(); i++)
                cout << lineChunks.at(i) << " ";

            //If-statement that executes if pass is true
            if(pass) 
                //For-loop that iterates through all values in wordValues to determine if there is word associated with result
                for(auto& x : wordValues) 
                    //If-statement that checks if there is a key that has result as a value
                    if(x.second == result) {
                        //Sets output to the key and breaks out of the loop
                        output = x.first;
                        break;
                    }

            //If-else statement that checks if pass is true and output is not empty; If both are true, then it outputs output; otherwise, it outputs unknown
            if(pass && !output.empty()) 
                cout << output << endl;
            else {
                cout << "unknown" << endl;
                pass = true;
            }
        }
        
        //Clears ss, lineChunks, and output for the next input
        ss.clear();
        lineChunks.clear();
        output.clear();
    }

    return 0;
}