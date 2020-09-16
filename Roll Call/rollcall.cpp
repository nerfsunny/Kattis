#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(int argc, char** argv) {
    //Initializing variables; used to store the first and last name of the student
    string firstName, lastName;

    /*
        Used to store the students given from the input
        The key is the student's last name and value is an ordered set that contains student first names that share the same last name
        Used so that the container will automatically sort the values stored
    */
    map<string, set<string>> roster;

    /*
        Used to store how many students have the same first name
        The key is the student's first name and is the number of students who share the first name
        Used to determine if the last name of a student should be printed or not. If there are more than one students who share the smae first name, then those students will have their last name printed
    */
    map<string, int> numberOfInstancesFirstName;

    //While-loop that goes through the input
    while(cin >> firstName >> lastName) {
        //Either inserts the first name of a student who shares the same last name as another student or creates a new key-value entry in roster, then stores the first name
        roster[lastName].insert(firstName);

        //If-else statement block that checks if the first name already exists in numberOfInstancesFirstName; if it does, then it increments the value by 1. If it does not, then it creates a new entry and gives it a value of 1
        if(numberOfInstancesFirstName.find(firstName) != numberOfInstancesFirstName.end()) {
            int instances = numberOfInstancesFirstName[firstName] + 1;
            numberOfInstancesFirstName[firstName] = instances;
        }else
            numberOfInstancesFirstName[firstName] = 1;
    }

    //For-loop that iterates through all values in roster
   for(auto& students : roster) {
       //For-loop that iterates through all values stored in the set of a certain key in rosters
       for(auto& firstName : students.second) {
           //If-else statement that checks if there are more than 1 students with the same first name; if the student's first name is unique (meaning it has a value of 1) then it prints only the first name; otherwise, it prints the student's first and last name
           if(numberOfInstancesFirstName[firstName] == 1)
                cout << firstName << endl;
            else
                cout << firstName << " " << students.first << endl;
       }
   }

    return 0;
}