#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    /* Initializing variables
       profession, stores the string with the highest double vowel count
       potentialProfession, stores the string obtained from the input
       numberOfInputs, stores how many professions to currently consider
       numberOfDoubleVowels, stores the current maximum number of double vowels. Uses -1 to also allow words with 0 double vowels to also potentially be stored in professions
       counter, used to count how many double vowels appear in potentialProfession
    */
    string profession = "", potentialProfession = "";
    long int numberOfInputs, numberOfDoubleVowels = -1, counter = 0;

    //Initializing container, stores vowels to check for in input
    vector<char> vowels {'a', 'e', 'i', 'o', 'u', 'y'};

    //Storing iterators to the front and back of the vector, as these will get called a lot
    vector<char>::iterator begin = vowels.begin(), end = vowels.end();

    //While-loop that iterates through the entire input
    while(cin >> numberOfInputs) {
        //Checks if the input size is 0; if it is, then it exits the loop
        if(numberOfInputs == 0)
            break;

        //For-loop that iterates through a specific numberOfInputs
        for(long int i = 0; i < numberOfInputs; i++) {
            //Stores given profession
            cin >> potentialProfession;

            //For-loop that iterates through all of the characters in potentialProfession; if the character at index and index + 1 are the same and are in vowels, then it increments the counter by 1 
            for(long int index = 0; index < potentialProfession.length() - 1; index++)
                if((find(begin, end, potentialProfession[index]) != end) && (potentialProfession[index] == potentialProfession[index+1]))
                    counter++;

            //Checks if the number of double vowels in potentialProfession is strictly greater than numberOfDoubleVowels; if it is, then it stores potentialProfession in profession and counter in numberOfDoubleVowels
            if(counter > numberOfDoubleVowels) {
                profession = potentialProfession;
                numberOfDoubleVowels = counter;
            }

            //Reseting variable
            counter = 0;
        }

        //Outputs profession with the highest double vowel count
        cout << profession << endl;

        //Reseting variable
        numberOfDoubleVowels = -1;
    }

    return 0;
}