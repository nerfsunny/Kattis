#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;
using ull = unsigned long long int;

//Takes a hexadecimal number, converts it to its decimal counterpart and returns it
ull convertFromHexToDecimal(string& hexNumber, unordered_map<char, int>& hexadecimalCharSet) {
	/*Initializing variables
		decimalNumber, stores the working decimal number calculation of the hexNumber
		power, stores the power at which 16 needs to be raised by
	*/
    ull decimalNumber = 0, power = 0;

    //For-loop that iterates through all of the digits in the hexNumber starting from its right-most digit until it reaches the second left-most digit (as 0x is only used to that the number is a hexadecial number)
    for(int i = hexNumber.length() - 1; i > 1; i--) {
    	//Converts digit i of the hexadecimal number to its decimal counterpart and adds it to decimalNumber
        decimalNumber += (hexadecimalCharSet[hexNumber[i]] * pow(16, power));

        //Increments power by 1
        power++;
    }

    //Returns decimal number
    return decimalNumber;
}

/*Creates an unordered_map that contains the values of the digits for a hexadecimal number
  The key is the hexadeciaml digit, the value is its decimal counterpart
*/
unordered_map<char, int> populateSet() {
	//Initializing container
    unordered_map<char, int> set;

    //For-loop that adds the kv pairs into the set
    for(int i = 0; i < 16; i++) {
        if(i < 10) {
            char a = '0' + i;
            set[a] = i;
        }else {
            char b = 'A' + (i - 10), c = 'a' + (i - 10);
            set[b] = i;
            set[c] = i;
        }
    }

    //Returing set
    return set;
}

int main(int argc, char** argv) {
	/*Initializing variables
	  line, stores the given input
	  hexNumber, stores the number extracted from line
	*/
    string line, hexNumber = "";

    //Initializing container, contains the values of the digits for a hexadecimal number
    unordered_map<char, int> hexadecimalCharSet = populateSet();

    //While-loop that iterates through all of the lines from the input
    while(cin >> line) {
    	//For-loop loop that iterates from [0, index-1] of line to find hexNumbers
        for(int index = 0; index < line.size() - 1; index++) {
        	//Checks if there is a 0x and 0X at index and index+1 in line. If there is, it starts extracting the digits of the hexNumber in line
        	if(line[index] == '0' && (line[index + 1] == 'x' || line[index + 1] == 'X')) {
        		//Storing the two characters found at index and index+1 into lineNumber
        		hexNumber = string(1, line[index]) + string(1, line[index+1]);

        		//Increment index to move "cursor"
        		index++;

        		//While-loop that continues until the next character is not a hexadecimal digit listed in hexadecimalCharSet
        		while(hexadecimalCharSet.find(line[index+1]) != hexadecimalCharSet.end()) {
        			//Appends character to string
        			hexNumber += line[index+1];

        			//Increments index by 1
        			index++;
        		}

        		//Outputs hexNumber and its decimal counterpart
        		cout << hexNumber << " " << convertFromHexToDecimal(hexNumber, hexadecimalCharSet) << endl;

        		//Clears variable
        		hexNumber.clear();
        	}
        }

    }

    return 0;
}