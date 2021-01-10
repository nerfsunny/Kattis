#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//Sorts the frequency from largest to smallest. In the event of a tie, the number that appeared sooner is put ahead of the other number
void sort(vector<pair<int, int>>& frequency) {
    //Initializng temp variable to use in the event a switch needs to occur
    pair<int, int> temp;

    /*Nested for-loop
        Outer loop range is [1, frequency.size() - 1]. It treats all values before i as already sorted
        Inner loop range is [1, i]. It goes in "reverse" as it is finding where to place pair i in the already sorted part of frequency. It continues until it cannot make another swap
    */
    for(int i = 1; i < frequency.size(); i++) {
        for(int j = i; j > 0; j--)
            //Checks if the freuqnecy found at j is greater than its predecessor. If it is, then it swaps the two values; Otherwise, it breaks out of this loop
            if(get<1>(frequency.at(j)) > get<1>(frequency.at(j-1))) {
                temp = frequency.at(j-1);
                frequency.at(j-1) = frequency.at(j);
                frequency.at(j) = temp;
            }else
                break;            
    }
}

//Checks if the given vector contains value, if it does, then it returns the found index; Otherwise, it returns -1
int isFound(vector<pair<int, int>>& frequency, const int value) {
    for(int i = 0; i < frequency.size(); i++)
        if(frequency.at(i).first == value)
            return i;
    
    return -1;
}

int main(int argc, char** argv) {
    //Initializing container, used to store a number and the frequency which is stored in the form of a pair
    vector<pair<int, int>> frequency;

    /*Initializing variables
        number, stores a number from the CLI
        numberOfInputs, stores how many inputs are in the test case
        maximumNumber, what is supposed to be the highest expected number in the input; not really used anywhere in the code as all of the numbers are guaranteed to be at this number or lower
    */
    int number, numberOfInputs, maximumNumber;

    //Storing the numberOfInputs and maximumNumber
    cin >> numberOfInputs >> maximumNumber;

    //While-loop that continues until there are no more inputs left
    while(cin >> number) {
        //Checks if a pair with number in slot 0 already exists in frequency
        int index = isFound(frequency, number);

        //If the index is not -1, then it increments its companion value (which denotes how many times number has appeared in the input) by 1
        //Otherwise, it inserts a new pair, with number in slot 0 and 1 in slot 1
        if(index != -1) {
            get<1>(frequency.at(index)) += 1;
        }else
            frequency.push_back({number, 1});
    }

    //Sorts the frequency from largest to smallest. In the event of a tie, the number that appeared sooner is put ahead of the other number
    sort(frequency);

    //Outputs each number its companion number times
    for(pair<int, int> p : frequency)
        for(int i = 0; i < get<1>(p); i++)
            cout << get<0>(p) << " ";

    //Closing output stream with an end-character
    cout << endl;

    return 0;
}