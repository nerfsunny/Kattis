#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    int number1, number2, numberOfDecimals;
    string numString, startingDecimal = "0.";
    double num;
    
    while(cin >> number1 >> number2 >> numberOfDecimals) {
        num = (double) number1/number2;
        numString = to_string(num);
        printf("%s%s\n", startingDecimal.c_str(), numString.substr(2, numberOfDecimals).c_str());
    }
    
    return 0;
}
