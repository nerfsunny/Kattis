#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    /* Initializing variables
        earthName is apaxianName without repeated char seqeuentially
        apaxianName is the input give
    */
    string earthName, apaxianName;

    //Stores input
    cin >> apaxianName;

    //For-each loop that iterates through each character in apaxianName. If the character is not the same one as the last character in earthName, it appends it to earthName
    for(char c : apaxianName)
        if(c != earthName[earthName.length() - 1])
            earthName += c;

    //Outputs earthName
    cout << earthName << endl;

    return 0;
}