#include <iostream>

using namespace std;

bool isLuckyNumber(int num) {
    while(num > 0) 
        if(num % 10 == 4 || num % 10 == 7)
            num /= 10;
        else
            return false;

    return true;
}

int main(int argc, char** argv) {
    int luckyNumber = 3, counter = 1, kthLuckyNumber;

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