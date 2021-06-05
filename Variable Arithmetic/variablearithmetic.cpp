#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <locale>
#include <cctype>
#include <algorithm>
#include <stdio.h>

using namespace std;

void storeDefinition(unordered_map<string, int>& definitions, const string& line) {
    string variable, equalSign, number;
    stringstream ss(line);
    
    ss >> variable >> equalSign >> number;
    
    if(definitions.find(variable) != definitions.end())
        definitions.at(variable) = stoi(number);
    else
        definitions.insert({variable, stoi(number)});
}

void evaluateLine(const unordered_map<string, int>& definitions, const string& line) {
    int total = 0;
    string chunk;
    vector<string> unusedVariables;
    stringstream ss(line);
    
    while(ss >> chunk) {
        if(chunk == "+")
            continue;
        
        if(all_of(chunk.begin(), chunk.end(), ::isdigit))
           total += stoi(chunk);
        else if(definitions.find(chunk) != definitions.end())
           total += definitions.at(chunk);
        else
           unusedVariables.push_back(chunk);
    }
    
    if(total == 0 && unusedVariables.size() != 0) {
        printf("%s", unusedVariables.at(0).c_str());
        
        for(int i = 1; i < unusedVariables.size(); i++)
            printf(" + %s", unusedVariables.at(i).c_str());
    }else {
        printf("%i", total);
        
        for(int i = 0; i < unusedVariables.size(); i++)
            printf(" + %s", unusedVariables.at(i).c_str());
    }
    
    cout << endl;
}

int main(int argc, char** argv) {
    string line;
    unordered_map<string, int> definitions;
    
    while(getline(cin, line)) {
        if(line.size() == 1 && stoi(line) == 0)
            break;
        
        if(line.find("=") != string::npos)
            storeDefinition(definitions, line);
        else
            evaluateLine(definitions, line);
    }
    
    return 0;
}
