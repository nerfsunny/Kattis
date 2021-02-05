#include <iostream>

using namespace std;
using ull = unsigned long long int;

bool isLuckyNumber(ull num) {
    ull digit;
    
    while(num > 0) {
        digit = num % 10;
        
        if(digit == 4 || digit == 7)
            num /= 10;
        else
            return false;
    }

    return true;
}

int main(int argc, char** argv) {
    ull luckyNumber = 3, counter = 1, kthLuckyNumber;

    cin >> kthLuckyNumber;

    while(counter <= kthLuckyNumber) {
        luckyNumber++;
        
        while(!isLuckyNumber(luckyNumber))
            luckyNumber++;
        
        counter++;
    }

    //Outputs k-th Lucky Number
    cout << luckyNumber << endl;

    return 0;
}