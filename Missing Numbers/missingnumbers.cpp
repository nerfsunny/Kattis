#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    //Initializing variable; used to initialize size of vector and store inputs in said vector
    int number;

    //Storing number of inputs
    cin >> number;

    //Initializing vectors; numbers is used to store the inputs given, missedNumbers stores the numbers missed when checking all values from 1 to biggest number in numbers - 1
    vector<int> numbers, missedNumbers;

    //Allocating size of numbers to number of inputs
    numbers.reserve(number);

    //While-loop that iterates through the rest of the inputs; stores in numbers
    while(cin >> number)
        numbers.emplace_back(number);

    //Storing iterators to the start and end of numbers
    auto begin = numbers.begin(), end = numbers.end();

    //For-loop that goes from 1 to largest number in numbers - 1; checks if every number in the range is in numbers
    for(int i = 1; i < numbers.at(numbers.size() - 1); i++) {
        //If-statement that checks if i is in numbers; if it is not, then it stores it in missedNumbers
        if(find(begin, end, i) == end)
            missedNumbers.emplace_back(i);
    }

    //If-else statement that executes one of two possible situations; if the size of missedNumbers is 0, then it prints "good job"; otherwise, it prints the elements in missedNumbers
    if(missedNumbers.size() == 0)
        cout << "good job" << endl;
    else
        for(auto& x : missedNumbers)
            cout << x << endl;

    return 0;
}