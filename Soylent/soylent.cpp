#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    /* Initializing variables
       targestCalories, stores the calories desired
       inputSize, stores the number of inputs in a given test case
    */
    int targetCalories, inputSize;

    //Storing input size
    cin >> inputSize;

    //For-loop that iterates through all of the inputs
    for(int i = 0; i < inputSize; i++) {
        //Storing calories
        cin >> targetCalories;

        //If calories are completely divisible by 400, it outputs that result. Otherwise, it finds the closest integer value and adds 1
        if(targetCalories % 400 == 0)
            cout << (targetCalories/400) << endl;
        else
            cout << (targetCalories/400 + 1) << endl;        
    }

    return 0;
}