#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;
using ull = unsigned long long int;

ull determineGCD(const ull num1, const ull num2) {
    if(num1 == num2 || num2 == 0)
        return num1;

    return determineGCD(num2, num1 % num2);
}

ull determineLCM(const ull num1, const ull num2) {
    if(num1 == 0 || num2 == 0)
        return 0;
    
    if(num1 % num2 == 0 || num2 % num1 == 0)
        return max(num1, num2);
    
    return (num1 / determineGCD(num1, num2)) * num2;
}

int main(int argc, char** argv) {
    ull numberOfMachines, numberOfWheels, num, lcm;
    vector<ull> wheels;
    
    cin >> numberOfMachines;
    
    for(int i = 0; i < numberOfMachines; i++) {
        cin >> numberOfWheels;
        
        for(int j = 0; j < numberOfWheels; j++) {
            cin >> num;
            wheels.push_back(num);
        }
        
        //lcm = wheels.at(0);
        num = wheels.at(0);
        
        for(int i = 1; i <= numberOfWheels - 1; i++)
            num = lcm(num, wheels.at(i));
        
        if(num < 1000000000)
            cout << num << endl;
        else
            cout << "More than a billion." << endl;
        
        wheels.clear();
    }
    
    return 0;
}
