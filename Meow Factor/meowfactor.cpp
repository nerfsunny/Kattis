#include <iostream>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

bool isMeowFactor(int number, int factor) {
    int counter = 0;
    
    while(number % factor == 0 && counter < 9) {
        counter++;
        number /= factor;
    }
    
    return (counter == 9);
}

int main(int argc, char** argv) {
    ull number, meowFactor = 1;
    
    cin >> number;
    
    if(number % 2 == 0) {
        for(int num = 2; num <= sqrt(number); num++)
            if(number % num == 0 && isMeowFactor(number, num))
                meowFactor = num;
    } else {
        for(int num = 3; num <= sqrt(number); num += 2)
            if(number % num == 0 && isMeowFactor(number, num))
                meowFactor = num;
    }
    
    cout << meowFactor << endl;
    
    return 0;
}
