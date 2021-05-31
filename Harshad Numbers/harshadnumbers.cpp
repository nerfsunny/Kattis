#include <iostream>

using namespace std;

//Calculates the sum of all of the digits in the given number
int digitSum(int number) {
    int sum = 0;
    
    while(number > 0) {
        sum += (number % 10);
        number /= 10;
    }
    
    return sum;
}

int main(int argc, char** argv) {
    //Initializing varibale, used to store the input
    int number = 0;
    
    //Storing input
    cin >> number;
    
    /* While-loop that continues until it finds the smallest number that satisfies the following conditions:
     * 1. Is greater than or equal to the original number
     * 2. The sum of its digits can evenly divide into the number
     */
    while(number % digitSum(number) != 0)
        number++;
    
    //Outputs number that satisfies those conditions
    cout << number << endl;
    
    return 0;
}
