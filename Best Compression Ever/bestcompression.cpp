#include <iostream>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

int main(int argc, char** argv) {
    ull num1, num2;
    
    cin >> num1 >> num2;
    
    if(floor(log2(num1)) == num2)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    return 0;
}