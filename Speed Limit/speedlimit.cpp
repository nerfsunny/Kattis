#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
    /* Initializing variables,
     *
     * currentSpeed, stores the most recent speed recorded when reading the input
     * totalDistance, stores the total distance traveled in the sub-test case
     * previousRecordedTime, stores the time elapsed of the previous entry. Stores 0 by default for the first entry in sub-test case
     * currentRecordTime, stores the most recent time elapseed when reading the input
     * numberOfEntries, stores the number of records in a sub-test case
     */
    int currentSpeed, totalDistance = 0, previousRecordedTime = 0, currentRecordTime, numberOfEntries;
    
    //Continues until it reads end of input (which is -1)
    while(cin >> numberOfEntries && numberOfEntries != -1) {
        //Goes through every entry in the sub-test case
        for(int i = 0; i < numberOfEntries; i++) {
            //Storing values into their respectuve variables
            cin >> currentSpeed >> currentRecordTime;
            
            //Calculates distance traveled over a certain period of time and adds result to totalDistance
            totalDistance += (currentSpeed * (currentRecordTime - previousRecordedTime));
            
            //Stores most recent recorded time into previousRecordedTime
            previousRecordedTime = currentRecordTime;
        }
        
        //Outputs total distance traveled for sub-test case
        printf("%i miles\n", totalDistance);
        
        //Reseting values for next case
        totalDistance = 0;
        previousRecordedTime = 0;
    }
    
    return 0;
}
