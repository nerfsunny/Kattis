#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    //Initializing variables; used to store the two inputs
    string name1, name2;

    //Initializing vector; contains vowels except for e and y
    vector<char> vowels{'a', 'i', 'o', 'u'};

    //Storing input into variables
    cin >> name1 >> name2;

    /*If-else statement block:
        First, checks if the last character of name1 is e; appends x and name2 if true
        Second, checks if the last character of name1 is a vowel in vowels; replaces it with ex and appends name2 if true
        Third, checks if the last two characters of name1 is ex; appends name2 if true
        Fourth, appends ex and name2 to name1

        Outputs concantenated string
    */
    if(name1[name1.length() - 1] == 'e')
        cout << name1 + "x" + name2 << endl;
    else if(find(vowels.begin(), vowels.end(), name1[name1.length() - 1]) != vowels.end())
        cout << name1.substr(0, name1.length() - 1) + "ex" + name2 << endl;
    else if(name1.substr(name1.length() - 2) == "ex")
        cout << name1 + name2 << endl;
    else
        cout << name1 + "ex" + name2 << endl;
    
    return 0;
}