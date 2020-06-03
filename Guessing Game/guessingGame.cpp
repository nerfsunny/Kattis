#include <iostream>
#include <string>
#include <vector>

using namespace std;

void checkResults(vector<string>& results, vector<int>& numbers, const int correctNumber) {
    string comparison;
    bool statement = true;
    
    for(int i = 0; i < numbers.size() - 1; i++) {
        if(numbers.at(i) > correctNumber)
            comparison = "too high";
        else
            comparison = "too low";
        
        if(comparison != results.at(i)) {
            statement = false;
            break;
        }
    }
    
    if(statement)
        cout << "Stan may be honest\n";
    else
        cout << "Stan is dishonest\n";
}

int main(int argc, char** argv) {
    vector<string> guessResult;
    vector<int> guessNumber;
    string line, number;
    
    while(getline(cin, number)) {
        if(number == "0")
            break;
        
        getline(cin, line);
        
        cout << number << " " << line << endl;
        
        if(line == "right on") {
            checkResults(guessResult, guessNumber, stoi(number));
            guessResult.clear();
            guessNumber.clear();
        }else {
            guessResult.push_back(line);
            guessNumber.push_back(stoi(number));
        }
    }
    
    return 0;
}
