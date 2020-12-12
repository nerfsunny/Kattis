#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    /*Initializing variables
      orderSize, stores how many people ordered for a given diner order
      name, stores the name of a customer on the diner order
      foodItem, stores the name of an item a customer ordered on the diner order
      line, stores the full line in a diner order
    */
    int orderSize;
    string name, foodItem, line;

    /*Initializing container; stores data from a given diner order. 
      Key, diner item
      Value, string vector that stores which customer on diner order ordered that diner item
    */
    map<string, vector<string>> bill;

    //Used to break the line by space
    stringstream ss;

    //Grabs how many people on a given diner order
    while(getline(cin, line)) {
        //Converts from string to int
        orderSize = stoi(line);

        //Checks if orderSIze if 0; if it is, then it exits the loop
        if(orderSize == 0)
            break;

        for(int i = 0; i < orderSize; i++) {
            //Storing customer order in line
            getline(cin, line);

            //Passing line to ss
            ss.str(line);

            //Extracting customer's name
            ss >> name;

            //While-loop that iterates through the customer's ordered items; if the item is already in the bill, then it stores the customer name; otherwise, it creates a new entry with item as the key and a string vector (initialized with the customer name) as the value
            while(ss >> foodItem) {
                if(bill.find(foodItem) != bill.end())
                    bill.at(foodItem).push_back(name);
                else
                    bill.insert({foodItem, vector<string> {name}});
            }

            //Clears ss
            ss.clear();
        }

        //For-each loop that iterates through all of the key-value pairs in bill
        for(auto& kv : bill) {
            //Sorts the vector in alphabetical order
            sort(kv.second.begin(), kv.second.end());

            //Outputs diner item
            cout << kv.first << " ";

            //For-loop that iterates through all of the names in vector; if it is the last index, it outputs an newline character; otherwise it outputs value i
            for(int i = 0; i < kv.second.size(); i++) {
                if(i == kv.second.size() - 1)
                    cout << kv.second.at(i) << endl;
                else
                    cout << kv.second.at(i) << " ";
            }
        }

        //Clears bill for next diner order
        bill.clear();

        //Outputs a new line to separate diner orders
        cout << endl;
    }

    return 0;
}