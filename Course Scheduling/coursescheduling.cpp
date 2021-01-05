#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    /*Initializing variables
        line, stores the full input on line i
        fullName, stores the student's full name from line
        courseName, stores the courseName from line
    */
    string line, fullName, courseName;
    
    /*Initializing container
        key is the course name and the value is set container that contains students who requested course
    */
    map<string, set<string>> courseRequests;
    
    //Moving cursor to next line of input
    getline(cin, line);
    
    //While-loop that continues until there are no more lines in the input
    while(getline(cin, line)) {
        //Stores the last index found for space in line as the three fields in the line (student's first/last name and course name) are separated by spaces
        int lastSpaceIndex = line.rfind(' ');
        
        //Extracting student's name from line and storing it
        fullName = line.substr(0, lastSpaceIndex);
        
        //Extracting course name and storing it
        courseName = line.substr(lastSpaceIndex + 1);
        
        //If-else statement block that checks if the course is already listed in courseRequests. If it is, then it inserts the student's name into the set (if it does not exist already). Otherwise, it creates a new key-value pair
        if(courseRequests.find(courseName) != courseRequests.end())
            courseRequests[courseName].insert(fullName);
        else
            courseRequests.insert({courseName, set<string> {fullName}});
    }
    
    //For-each loop that iterates through all of the values in courseRequests; outputs the courseName and the number of unique students who requested the course
    for(auto& kv : courseRequests)
        cout << kv.first << " " << kv.second.size() << endl;
    
    return 0;
}
