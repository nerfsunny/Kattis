#include <iostream>
#include <string>

using namespace std;

//Uses the Base 10 to Binary conversion "algorithm", however, instead of constructing the binary number, it counts how many 1s would represent the binary number
int countingOnes(int number) {
    //Used to store how many 1s appear in the "binary number"
    int count = 0;

    //Continues until number has reached 0
    while(number > 0) {
        //Checks if the remainder of dividing the number by 2 is 1; if it is, then it incremenets count by 1
        if(number % 2 == 1)
            count++;

        number /= 2;
    }

    //Returns how many 1s would represent the "binary number"
    return count;
}

//Finds the maximum number of 1s that may represent the number in binary as it is being "typed"
int maximumNumberOfOnes(string& number) {
    /* Initializing variables
       maximumNumber, used to store the maximum number of 1s that would represent the number while it is being "typed"
       count, used to store the number 1s to represent an extracted set of digits from number in binary
    */
    int maximumNumber = 0, count;

    //For-loop that determines how many digits need to be extracted from number
    for(int i = 1; i <= number.length(); i++) {
        //Stores how many 1s would represent the binary number of the extracted digits from number
        count = countingOnes(stoi(number.substr(0, i)));

        //If the count is strictly greater than maximumNumber, then it stores it in maximumNumber
        if(count > maximumNumber)
            maximumNumber = count;
    }

    //Returns the highest count of 1s when "typing" the number
    return maximumNumber;
}

int main(int argc, char** argv) {
    /* Initializing variables
       inputSize, stores the number of inputs in a given test case
       number, stores the given number. Stores it in string to extract digits from left to right
    */
    int inputSize;
    string number;

    //Storing input size
    cin >> inputSize;

    //For-loop that iterates through all of the given inputs
    for(int i = 0; i < inputSize; i++) {
        //Stores number
        cin >> number;

        //Outputs the maximum number of 1s when "typing" the number
        cout << maximumNumberOfOnes(number) << endl;
    }

    return 0;
}