#include <iostream>
#include <string>

using namespace std;

//Takes a number and computes it checksum; returns checksum
int calculateCheckSum(string& number) {
    //Initializing variable; used to store the number's sum
    int sum = 0;

    /*For-loop that iterates through all of the digits in number
      index is used to determine which digit to extract from number
      digitNum is used to determine if the digit needs to be doubled or not
    */
    for(int index = number.length() - 1, digitNum = 1; index >= 0; digitNum++, index--) {
        //Stores digit found at index
        int digit = stoi(number.substr(index, 1));

        //Checks if the digitNum is even
        if(digitNum % 2 == 0) {
            //Doubles digit
            digit *= 2;

            //Checks if the digit is greater than or equal to 10; if it is, it sums the two digits and stores it in digit
            if(digit >= 10)
                digit = digit/10 + digit % 10;
        }

        //Adds digit to sum
        sum += digit;
    }

    return sum;
}

int main(int argc, char** argv) {
    /*Initializing variables
        numberOfInputs, stores the number of inputs in a given test case
        number, stores number that we want to validate via its checksum
    */
    int numberOfInputs;
    string number;

    //Stores number of inputs in a given test case
    cin >> numberOfInputs;

    //For-loop that iterates through all of the inputs in a test case
    for(int i = 0; i < numberOfInputs; i++) {
        //Stores number
        cin >> number;

        //Converts given number to its checksum; if its checksum is divisible by 10, it outputs Pass; otherwise it outputs Fail
        cout << ((calculateCheckSum(number) % 10 == 0) ? "Pass" : "Fail") << endl;
    }

    return 0;
}