#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <iterator>

using namespace std;

int main(int argc, char ** argv) {
    /* Initializing variables,
     *
     * number, used to store the value into one of the lists
     * numberOfEntries, used to store the number of values on a list for a given sub-test case
     */
    int number, numberOfEntries;
    
    /* Initializing containers,
     *
     * list1, stores the values of the first list in their original order
     * orderedList1, stores the sorted list for all of the values in the first list of the input
     * orderedList2, stores the sorted list for all of the values in the second list of the input
     * associationTable, stores which value in orderedList1 is associated with which value in orderedList2
     */
    vector<int> list1;
    set<int> orderedList1, orderedList2;
    unordered_map<int, int> associationTable;
    
    //Continues until it reaches the end of the designated end of overall test case value
    while(cin >> numberOfEntries && numberOfEntries != 0) {
        //Storing all of the values of the first list into orderedList1, in order to sort it, and list1, in order to determine what order to print the values in list2
        for(int i = 0; i < numberOfEntries; i++) {
            cin >> number;
            list1.push_back(number);
            orderedList1.emplace(number);
        }
        
        //Storing all of the values in the second list into orderedList2, in order to sort it
        for(int j = 0; j < numberOfEntries; j++) {
            cin >> number;
            orderedList2.emplace(number);
        }
        
        //Initializing iterators for the two sets
        set<int>::iterator set1 = orderedList1.begin(), set2 = orderedList2.begin();
        
        //Going through all of the values in the two sets and storing it in the associationTable, such that the value from list1 is a key and the value from list2 is a value in the table
        while(set1 != orderedList1.end() && set2 != orderedList2.end()) {
            associationTable.insert({*set1, *set2});
            set1++;
            set2++;
        }
        
        //Going through every value in list1 and printing the value associated with it from list2, such that list2 is ordered the same way as list1
        for(const int x : list1)
            cout << associationTable.at(x) << endl;
        
        //Outputting new line to signal end of list
        cout << endl;
        
        //Clearing containers for next set of inputs
        orderedList2.clear();
        orderedList1.clear();
        associationTable.clear();
        list1.clear();
    }
    
    return 0;
}
