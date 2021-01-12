#include <iostream>
#include <string>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

//Takes a given decimal number and converts to its binary counterpart; however, it constructs it in reverse order
void convertToReverseBinary(ull num, string& rBinaryNumber) {
    while(num > 0) {
        if(num % 2 == 1) 
            rBinaryNumber += '1';
        else
            rBinaryNumber += '0';

        num /= 2;
    }
}

//Takes a given binaryNumber and converts it to its decimal counterpart
ull convertToDecimal(string& rBinaryNumber) {
    /* Initializing variables
        num, used to calculate and store the decimal number
        power, used to store what power 2 needs to be raised by
    */
    ull num = 0, power = 0;

    //For-loop that iterates all of the digits in the binary number, converts to its decimal counterpart and adds it to num
    for(int i = rBinaryNumber.length() - 1; i >= 0; i--) {
        num += (stoi(rBinaryNumber.substr(i, 1)) * pow(2, power));
        power++;
    }

    //Returns decimal number
    return num;
}

int main(int argc, char** argv) {
    /* Initializing variables
        rBinaryNumber, stores the reverse ordering a binary number
        number, stores the input number
    */
    string rBinaryNumber;
    ull number;

    //Stores given number
    cin >> number;

    //Converts a given decimal number into its binary counterpart, however, it reverses the order of its digits
    convertToReverseBinary(number, rBinaryNumber);

    //Converts the "new" binary number back into decimal and outputs it
    cout << convertToDecimal(rBinaryNumber) << endl;
    
    return 0;
}