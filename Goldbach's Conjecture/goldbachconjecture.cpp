#include <iostream>
#include <map>
#include <stdio.h>
#include <cmath>

using namespace std;

//Determines if the given number is prime or not. Returns true if the given number is indeed prime
bool isPrime(const int number) {
    //Checks if the number is even, provided that it is greater than 2. Returns false if even
    if(number % 2 == 0 && number != 2)
        return false;
    
    //For-loop that goes from 3 to closest int value of the square root of number; if a value in this range is a factor of number, it returns false
    for(int i = 3; i <= sqrt(number); i+=2)
        if(number % i == 0)
            return false;
    
    //Returns true otherwise
    return true;
}

//Goes through all of the numbers from [2, number - 1] to find all of pairs of values that are both prime and sum to the given number
void listOfPrimeNumberSum(map<int, int>& primeNumberSum, const int number) {
    //Special case for when the number is 4
    if(isPrime(number - 2))
        primeNumberSum.insert({2, number - 2});
    
    //Checks all odd numbers between [3, number/2] to see if a pair of values, who are both prime, and sum to the given number
    for(int j = 3; j <= number/2; j+=2)
        //If both j and its complement value are both prime, it is stored in primeNumberSum
        if(isPrime(j) && isPrime(number - j))
            primeNumberSum.insert({j, number - j});
}

int main(int argc, char** argv) {
    /* Initializing variables,
     * inputSize, stores the number of inputs considered in the test case
     * number, stores the specific number in the test case
     */
    int inputSize, number;
    
    //Initializing container, used to store the different primes numbers (and their complementary pair) that are strictly below the number and sum to number
    //The key is the smaller prime number and the value is the larger prime number
    map<int, int> primeNumberSum;
    
    //Storing size of the test case
    cin >> inputSize;
    
    for(int i = 0; i < inputSize; i++) {
        //Storing number
        cin >> number;
        
        
        listOfPrimeNumberSum(primeNumberSum, number);
        
        //Outputs the number and how many sums were observed
        printf("%i has %lu representation(s)\n", number, primeNumberSum.size());
        
        //Goes through each entry in primeNumberSum and outputs the two prime numbers that make up that sum
        for(const auto& num : primeNumberSum)
            printf("%i+%i\n", num.first, num.second);
        
        //Outputting new line for the next potential number
        cout << endl;
        
        //Clearing for the next potential number
        primeNumberSum.clear();
    }
    
    return 0;
}
