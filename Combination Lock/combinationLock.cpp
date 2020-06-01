#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int firstNumber(int num1, int num2) {
    int result = 0;
    
    if(num1 < num2)
        result = ((40 * 2) + (num2 - num1)) * 9;
    else
        result = ((40 * 2) + (40 - num2 + num1)) * 9;
    
    cout << result << endl;
    
    return result;
}

int secondNumber(int num1, int num2) {
    int result = 0;
    
    if(num2 < num1) {
        result = (40 + num1 - num2) * 9;
    }
    else {
        result = (40 + (40 - num1 + num2)) * 9;
    }
    
    cout << result << endl;
    
    return result;
}

int thirdNumber(int num1, int num2) {
    int result = 0;
    
    if(num1 < num2)
        result = (num2 - num1) * 9;
    else
        result = (40 - num2 + num1) * 9;
    
    cout << result << endl;
    
    return result;
}

int main(int argc, char** argv) {
    string line;
    vector<int> output;
    
    while(getline(cin, line)) {
        if(line == "0 0 0 0")
            break;
        
        cout << line << endl;
        
        vector<int> numbers;
        
        stringstream ss(line);
        string number;
        
        while(getline(ss, number, ' '))
            numbers.push_back(stoi(number));
        
        int result = firstNumber(numbers.at(0), numbers.at(1)) + secondNumber(numbers.at(1), numbers.at(2)) + thirdNumber(numbers.at(2), numbers.at(3));
        
        output.push_back(result);
        cout << result << endl;
    }
    
    for(int index = output.size() - 1; index >= 0; index--)
        cout << output.at(index) << endl;
    
    return 0;
}
