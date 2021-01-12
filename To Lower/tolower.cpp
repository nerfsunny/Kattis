#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//Checks if the given word is all lower case; if there is at least a single instance of an upper case letter, it returns false; otherwise, it returns true
bool isLowerCase(string& word) {
    //Starts at index 1, since the user converts the first character in the word to lower case
    for(int k = 1; k < word.length(); k++) 
        if(!islower(word[k])) 
            return false;

    return true;
}

int main(int argc, char** argv) {
    /* Initializing variables
       totalProblems, stores the total number of test cases
       testCases, stores the number of cases in a given test case
       problemsSolved, stores the number of testCases the user can solve
       count, stores the number of cases the user can solve in a testCase
       word, stores the case to consider
    */
    int totalProblems, testCases, problemsSolved = 0, count = 0;
    string word;

    //Storing values in their respective variables
    cin >> totalProblems >> testCases;

    //Nested for-loop that goes through all of the testCases and cases
    for(int i = 0; i < totalProblems; i++) {
        for(int j = 0; j < testCases; j++) {
            //Stores case
            cin >> word;

            //Checks if all of the letters in word are lower case; if it is, then it increments count by 1
            if(isLowerCase(word))
                count++;
        }

        //If the user can solve all of the cases in a testCase, it increments problemsSolved by 1
        if(count == testCases)
            problemsSolved++;

        //Resets counter to 0
        count = 0;
    }

    //Outputs result
    cout << problemsSolved << endl;
    
    return 0;
}