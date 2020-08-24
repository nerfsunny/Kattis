#include <iostream>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

//Method that checks if the given number is prime or not. If it is, then it returns true; otherwise, it returns false
bool isPrime(ull number) {
    //If-statement that checks if the number is even; returns false if it is
    if(number % 2 == 0) 
        return false;

    //For-loop that goes from 3 to closest int value of the square root of number; if a value in this range is a factor of number, it returns false
    for(ull num = 3; num <= (int) sqrt(number); num++) {
        //If-statement that checks if number is divisible by num; returns false if it is
        if(number % num == 0)
            return false;
    }

    //Returns true if it fails the two tests above
    return true;
}

int main(int argc, char** argv) {
    //Initializing variable. Used to store initial size of hash table
    ull number;

    //While-loop that iterates through all inputs
    while(cin >> number) {
        //If-statement that checks if it has reached the end of the input
        if(number == 0)
            break;

        //If-else statement that checks if the number is at least 4 or more. If it is not (meaning it is either 2 or 3), it doubles the size and adds 1. Otherwise, it calcualted the nearest prime to number
        if(number >= 4) {
            //Stores the doubled number
            ull primeNumber = 2 * number;

            //While-loop that continues until it finds the first prime number
            while(!isPrime(primeNumber)) 
                primeNumber++;

            //If-else statement that checks if the original number is prime or not; if it is, then it outputs the first result, otherwise, it outputs the second result
            if(!isPrime(number))
                cout << primeNumber << " (" << number << " is not prime)" << endl;
            else
                cout << primeNumber << endl;
        }else
            cout << (2 * number + 1) << endl;
    }

    return 0;
}