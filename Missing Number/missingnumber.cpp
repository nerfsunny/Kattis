#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    /* Initializing variables, 
     * numberOfNumbers, stores the highest number we wanted to count up to in sequential order
     * position, used to keep track of where we want to start extracting a number from in listedNumbers
     * digits, used to keep track of how many digits we want to extract for a number
     * counter, used to keep track of the highest number recorded in sequential order
     */
    int numberOfNumbers, position = 0, digits = 1, counter = 0;
    string listedNumbers;
    
    //Storing the number of numbers to consider and what numbers were written into their respective variables
    cin >> numberOfNumbers >> listedNumbers;
    
    //Initializing container, used to store the numbers processed from listedNumbers
    vector<int> numbers(numberOfNumbers);
    
    /* Initializing variables, 
     * num1, is used to store the number extracted just before num2. Or, is used to store the last element in numbers
     * num2, used to store the number just extracted from listedNumbers
     */
    int num1 = stoi(listedNumbers.substr(position, digits));
    int num2;
    
    //Checks if the first number grabbed was one. If it was not, then it outputs 1 and exits the program
    if(num1 != 1) {
        cout << digits << endl;
        return 0;
    }
    
    //If num1 was 1, it stores the number in numbers
    numbers.push_back(num1);

    //Increments the position by 1, in this case, in order to prepare for the next number to be processed
    position += digits;

    //Increments this value by 1 
    counter++;
    
    //While-loop that continues while the position is strictly less than the length of listedNumbers. This is for the case where the missing number is the number we want to count up to
    while(position < listedNumbers.length()) {
        //Extracts another number from listedNumbers
        num2 = stoi(listedNumbers.substr(position, digits));

        //Checks if we need to increase the number of digits we need to extract
        while(find(numbers.begin(), numbers.end(), num2) != numbers.end()) {
            digits++;
            num2 = stoi(listedNumbers.substr(position, digits));
        }
        
        //Checks if the two numbers are sequential. If it is, it stores the current number in numbers. If not, then it outputs the number between the two numbers and exits the loop
        if(num2 - num1 == 1) {
            //Stores current number in numbers
            numbers.push_back(num2);

            //Sets the current number to be previous number
            num1 = num2;
            
            //Sets the position for the next number
            position += digits;

            //Records the highest number sequentially counted
            counter++;
        }else {
            //Outputs the number that is supposed to come next after num1
            cout << ++num1 << endl;
            break;
        }
    }
    
    //Checks for the condition where the missing number is the number we want to count up to
    if(counter == numberOfNumbers-1)
        cout << numberOfNumbers << endl;
    
    return 0;
}
