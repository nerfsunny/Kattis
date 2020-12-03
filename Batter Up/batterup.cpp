#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    /*Initializing variables
        num is used to obtain the input
        dataPoints is used to count the number of values added to sum
        sum is the total sum of bases of a given test case  
    */
    int num, dataPoints = 0, sum = 0;

    //Moves cursor past number of inputs for the test case as it is not needed
    cin >> num;

    //While-loop that continues until there are no more inputs that can be stored in num
    while(cin >> num) {
        //If num is -1, it skips this iteration
        if(num == -1)
            continue;

        //Increments dataPoints by 1
        dataPoints++;

        //Adds num to total sum
        sum += num;
    }
    
    //Outputs the slugging average; casted as double as both values are int
    cout << (double) sum/dataPoints << endl;

    return 0;
}