#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    //Initializing variables; number is used to store the initial input and the final value of the calculation, temp is used to the results of intermediary calcualtions
    int number, temp = 1;

    //Storing input in number
    cin >> number;

    //While-loop that continues until number is a single digit
    while(number > 9) {
        //While-loop that multiples all non-zero digits in number
        while(number > 0) {
            //Checks if the right-most digit is a 0
            if(number % 10 != 0) 
                //Multiplies the right-most digit to temp
                temp *= (number % 10);

            //Shifts decimal place of number to the left by 1
            number /= 10;
        }

        //Sets number to the result of temp
        number = temp;

        //Resets temp
        temp = 1;
    }

    //Outputs single digit to terminal
    cout << number << endl;

    return 0;
}