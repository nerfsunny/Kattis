#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

//Calculates the happiness sum for a given queue
ll happinessSum(vector<int>& numbers) {
    //Initializing variable, used to store the total happiness sum of the line
    ll sum = 0;

    //Goes through each person in line, taking the product of that person's excitement value of being in that position in line and their position, then adding it to sum
    for(int i = 1; i <= numbers.size(); i++)
        sum += (i * numbers.at(i-1));

    //Returns total happiness sum
    return sum;
}

//Swaps the two given values via pointers
void swap(ll *a, ll *b) {
    ll x = *a;
    *a = *b;
    *b = x;
}

int main(int argc, char**) {
    /* Initializing variables, 
     *
     * size, stores the input size of the test case
     * startingIndex, stores the index where 0 was initially recorded
     * currentIndex, stores the index where 0 is recorded in that iteration
     * highestHappiness, stores the highest possible happiness sum throughout the entire test case
     * currentHappiness, stores the happiness sum for a specific iteration of the queue
     */
    int size, startingIndex, currentIndex, num;
    ll highestHappiness = 0, currentHappiness;

    //Storing size of the given test case
    cin >> size;
    
    /* Initializing container, 
     * 
     * Used to store the position of each person (represented by their excitement value of being in the queue) in line
     */
    vector<int> line(size, 0);
    
    //Storing people (represented by their excitement value) in line
    //Starting at 1 since we have to multiply the excitement value of the person with their position in line (which the prompt starts counting at 1)
    for(int i = 1; i <= size; i++) {
        //Storing value
        cin >> num;

        //Checking if the current person is the indifferent person. If it is, then it records the initial position they had in line
        if(num == 0)
            startingIndex = i-1;
        
        //Storing value into line
        line.at(i-1) = num;
        
        //Calculating total happiness sum of the initial line
        highestHappiness += (i * num);
    }
    
    //Copying value. Used to determine if the 0 has reached its original position
    currentIndex = startingIndex;

    //Sets the current happiness to the current happiness value of the intiial queue
    currentHappiness = highestHappiness;

    //Do-While loops that continues until the indifferent position (denoted by the value 0) returns to their initial position in line
    //Calculates the total happiness sum of the queue after performing a adjacent swap with the indifferent participant and another adjacent participant that is in front of the indifferent person
    do {
        //Checks if the indifferent person is at the front of the line
        if(currentIndex == 0) {
            //Moves the indifferent person to the back of the line
            line.erase(line.begin());
            line.push_back(0);
            
            //Sets the currentIndex of the indifferent person
            currentIndex = size - 1;
            
            //Calculates the current happiness of the line
            currentHappiness = happinessSum(line);
        }else {
            //Calculates the new current happiness by subtracting the current happiness value (calculated by taking the product of the adjacent person's (that is in front of the indifferent person) excitment value and their position in line) of the person at currentIndex and adding the happiness value after the non-indifferent person to currentIndex + 1
            currentHappiness += ((line.at(currentIndex-1) * (currentIndex+1)) - (line.at(currentIndex-1) * (currentIndex)));
            
            //Swaps the two values such that the indifferent person is one step closer to the front of the line
            swap(line.at(currentIndex), line.at(currentIndex-1));

            //Decrements index to reflect new index for 0 in the queue
            currentIndex--;
        }

        //If the currentHappiness is greater than highestHappiness, then it stores it in highestHappiness
        if(currentHappiness > highestHappiness)
            highestHappiness = currentHappiness;
    }while(startingIndex != currentIndex);

    //Outputs the highest happiness value possible in the queue
    cout << highestHappiness << endl;
    
    return 0;
}
