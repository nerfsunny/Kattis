#include <iostream>

using namespace std;

//Returns the sum of all of its digits
int digitSum(int number) {
    //Initializing variable, used to store the sum of all of the digits in number
    int sum = 0;
    
    //While-loop that extracts the right-most digit of number, adds it to sum and then moves the decimal over to the left by 1
    while(number > 0) {
        sum += (number % 10);
        number /= 10;
    }
    
    //Returns the digit sum
    return sum;
}

//Finds the smallest number in the given range that equals the target sum
int findMaximumInteger(const int lowerBound, const int upperBound, const int targetSum) {
    //Checks range [lowerBound, upperBound] for a number that equals the target sum. Returns the first one it finds
    for(int num = upperBound; num >= lowerBound; num--)
        if(digitSum(num) == targetSum)
            return num;
    
    //If no number is found, it returns -1
    return -1;
}

//Finds the largest number in the given range that equals the target sum
int findMinimumInteger(const int lowerBound, const int upperBound, const int targetSum) {
    //Checks range [lowerBound, upperBound] for a number that equals the target sum. Returns the first one it finds
    for(int num = lowerBound; num <= upperBound; num++)
        if(digitSum(num) == targetSum)
            return num;
    
    //If no number is found, it returns -1
    return -1;
}

int main(int argc, char** argv) {
    /* Initializing variables,
     * lowerBound, stores the lower limit for the provided range
     * upperBound, stores the upper limit for the provoded range
     * targetSum, stores the what the result of summing all of the digits in a number should be
     */
    int lowerBound, upperBound, targetSum;
    
    //Storing values into their respective variables
    cin >> lowerBound >> upperBound >> targetSum;
    
    //Outputs the smallest number in the range that equals the target sum
    cout << findMinimumInteger(lowerBound, upperBound, targetSum) << endl;
    
    //Outputs the larget number in the range that equals the target sum
    cout << findMaximumInteger(lowerBound, upperBound, targetSum) << endl;
    
    return 0;
}
