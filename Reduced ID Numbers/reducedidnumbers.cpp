#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char** argv) {
    int numberOfIds, studentId, modNumber;
    vector<int> studentIdNumbers;
    set<int> reducedStudentIdNumbers;
    
    cin >> numberOfIds;
    
    for(int i = 0; i < numberOfIds; i++) {
        cin >> studentId;
        studentIdNumbers.push_back(studentId);
    }
    
    modNumber = numberOfIds;
    bool increaseModNumber = false;
    
    while(reducedStudentIdNumbers.size() != studentIdNumbers.size()) {
        for(int i = 0; i < numberOfIds; i++) {
            if(reducedStudentIdNumbers.find(studentId%modNumber) != reducedStudentIdNumbers.end()) {
                increaseModNumber = true;
                break;
            }else
                reducedStudentIdNumbers.emplace(studentIdNumbers.at(i) % modNumber);
        }
                
        if(increaseModNumber) {
            modNumber++;
            increaseModNumber = false;
            reducedStudentIdNumbers.clear();
        }
    }
    
    cout << modNumber << endl;
    
    return 0;
}
