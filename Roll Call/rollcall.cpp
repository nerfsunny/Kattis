#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;



int main(int argc, char** argv) {
    string firstName, lastName;
    map<string, set<string>> roster;

    while(cin >> firstName >> lastName) {
        if(roster.find(lastName) != roster.end())
            roster[lastName].insert(firstName);
        else {
            set<string> newSet;
            newSet.insert(firstName);
            roster[lastName] = newSet;
        } 
    }

    for(auto& x : roster) {
        if(x.second.size() == 1) {
            set<string> :: iterator firstElement = x.second.begin();
            cout << *firstElement << " " << x.first << endl;
        }else
            for(string x : x.second)
                cout << x << endl;
    }

    return 0;
}