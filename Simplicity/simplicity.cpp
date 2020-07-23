#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char** argv) {
    string input;
    set<char> uniqueLetters;

    cin >> input;

    for(char x : input)
        if(uniqueLetters.find(x) == uniqueLetters.end())
            uniqueLetters.insert(x);

    if(uniqueLetters.size() <= 2)
        cout << "0" << endl;
    else
        cout << uniqueLetters.size() - 2 << endl;

    return 0;
}