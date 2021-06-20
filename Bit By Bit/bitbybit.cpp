#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

char applyBitwiseOperation(const string& operation, const string& bit1, const string& bit2) {
    if(bit1 != "?" && bit2 != "?") {
        if(operation == "AND")
            return '0' + (stoi(bit1) & stoi(bit2));
        else if(operation == "OR")
            return '0' + (stoi(bit1) | stoi(bit2));
    }
    
    return '?';
}

int main(int argc, char** argv) {
    int numberOfOperations, index1, index2, num1, num2;
    string registerNum, line, mode;
    stringstream ss;
    
    while(getline(cin, line) && line != "0") {
        registerNum = string(32, '?');
        numberOfOperations = stoi(line);
        
        for(int i = 0; i < numberOfOperations; i++) {
            getline(cin, line);
            ss.str(line);
            
            ss >> mode >> index1;
            
            index1 = 31 - index1;
            
            if(mode == "SET")
                registerNum[index1] = '1';
            else if(mode == "CLEAR")
                registerNum[index1] = '0';
            else {
                ss >> index2;
                
                index2 = 31 - index2;
                
                registerNum[index1] = applyBitwiseOperation(mode, registerNum.substr(index1, 1), registerNum.substr(index2, 1));
            }
            
            ss.clear();
        }
        
        cout << registerNum << endl;
    }
    
    return 0;
}
