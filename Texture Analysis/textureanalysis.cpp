#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	/* Initializing variables
	   lineNumber, used to display the line number of the output
	   spacing, used to count the periods between two asterisks that are not the first two 
	   expectedSpacing, stores the spacing between the first two asterisks in line; is used as the standard when comparing the spacing between the other asterisks in line
	   printStatement, used to determine which of the two expected outputs to print. If the asterisks are evenly spaced, then this is true and prints "EVEN". Otherwise, it prints "NOT EVEN"
	   line, used to store the given input
	*/
    int lineNumber = 0, spacing = 0, expectedSpacing;
    bool printStatement = true;
    string line;

    //While-loop that iterates through all of the input, until it reaches "END"
    while(getline(cin, line) && line != "END") {
    	//Increments output line number by 1
        lineNumber++;

        //Checks if the given line is full of asterisks or not (as it is guaranteed that the first and last characters of a given line are asterisks)
        if(line.size() <= 2) {
            printf("%i EVEN\n", lineNumber);
            continue;
        }

        //Finds the index of the first asterisk in line (after the first character). That index - 1 is the expected spacing between the asterisks 
        expectedSpacing = line.find("*", 1) - 1;

        /*For-loop that iterates through line; counts how many periods (or spaces) it takes before it reaches the next asterisk. 
        If the number of spaces is equal to the expected amount, it continues as normal. Otherwise, it breaks out of the loop*/
        for(int i = 1; i < line.length(); i++) {
        	//Checks if the character at index i is an asterisk; if it is not, then it is a period and increments spacing by 1
            if(line[i] == '*') {
            	//Checks if the spacing between the two asterisks is expected; if it is, then it resets spacing; otherwise, it sets printStatement to false and breaks out of the loop
                if(spacing != expectedSpacing) {
                    printStatement = false;
                    break;
                }

                //Resets variable
                spacing = 0;
            }else
                spacing++;
        }

        //If the asterisks are evenly spaced, then it outputs the first line; otherwise, it outputs the second line
        if(printStatement)
            printf("%i EVEN\n", lineNumber);
        else
            printf("%i NOT EVEN\n", lineNumber);

        //Reseting variables
        spacing = 0;
        printStatement = true;
    }

    return 0;
}