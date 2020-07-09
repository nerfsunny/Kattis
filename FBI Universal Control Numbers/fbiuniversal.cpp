#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

//Calculates the expected check digit, given a UCN number and two tables
ull calculateCheckDigit(string& ucn, unordered_map<string, string>& confusedDigitTable, unordered_map<string, int>& digitTable) {
	/*Initializing variable to store information. 
	  checkDigit is used to store the calulations for check digit,
	  ucnDigit is used to store the base 27 digit at a certain index after checking if it is in the confusedDigitTable or not
	  extractedDigit is used to store the extracted digit from UCN at a certain index
	*/
	ull checkDigit = 0;
	string ucnDigit, extractedDigit;

	//For-loop that iterates through the UCN number
	for(int digit = 0; digit < 8; digit++) {
		//Extracts the digit at index digit from UCN number
		extractedDigit = ucn.substr(digit, 1);

		//Checks if the extractedDigit is in the confusedDigitTable. If it is, then it stores the value from that table in ucnDigit; otherwise, it stores it in ucnDigit
		if(confusedDigitTable.find(extractedDigit) != confusedDigitTable.end())
			ucnDigit = confusedDigitTable[extractedDigit];
		else
			ucnDigit = extractedDigit;

		//Stores the base 10 counterpart of the ucnDigit
		int ucnDecimalDigit = digitTable[ucnDigit];

		//Switch-statement that calculates a part of the formula to obtain the check digit. The digit iterator determines which part of the formula it needs to calculate
		switch(digit) {
			case 0:
				checkDigit = checkDigit + (2 * ucnDecimalDigit);
				break;
			case 1:
				checkDigit = checkDigit + (4 * ucnDecimalDigit);
				break;
			case 2:
				checkDigit = checkDigit + (5 * ucnDecimalDigit);
				break;
			case 3:
				checkDigit = checkDigit + (7 * ucnDecimalDigit);
				break;
			case 4:
				checkDigit = checkDigit + (8 * ucnDecimalDigit);
				break;
			case 5:
				checkDigit = checkDigit + (10 * ucnDecimalDigit);
				break;
			case 6:
				checkDigit = checkDigit + (11 * ucnDecimalDigit);
				break;
			case 7:
				checkDigit = checkDigit + (13 * ucnDecimalDigit);
				break;
			default:
				break;
		};
	}

	//Returns calculated value
	return checkDigit;
}

//Converts the UCN value (written in base 27) to its decimal counterpart value (which is base 10)
ull convertFromBase27ToBase10(string& ucn, unordered_map<string, string>& confusedDigitTable, unordered_map<string, int>& digitTable) {
	/*Initialize variables to store information; 
	  number is the final base 10 number after converting all of the digits, 
	  sDigit to extract the digit from ucn, 
	  digit is used to store the base 10 counterpart of the base 27 digit,
	  power is used raise 27
	*/
	ull number = 0;
	int power = 0, digit;
	string sDigit;

	//For-loop that iterates through ucn
	for(int i = ucn.length() - 1; i >= 0; i--) {
		//Extracts digit from ucn (goes from right to left)
		sDigit = ucn.substr(i, 1);

		//Checks if sDigit is in confusedDigitTable; if it is, then it stores the value from it in sDigit
		if(confusedDigitTable.find(sDigit) != confusedDigitTable.end())
			sDigit = confusedDigitTable[sDigit];

		//Stores the value from digitTable in digit
		digit = digitTable[sDigit];

		//Converts the base 27 digit to its base 10 version and adds it to number
		number = number + (digit * pow(27, power));

		//Increments power
		power++;
	}

	//Returns final value
	return number;
}

/* Populates the unordered_map to represent numbers written in Base 27. The key is the digit in Base 27 and the value is their decimal (Base 10) counterpart
   When populating the table, when it reaches a value in confusedDigitTable, it skips over the value
*/
unordered_map<string, int> populateTable(unordered_map<string, string>& confusedDigitTable) {
	//Initialize unordered_map
	unordered_map<string, int> table;

	//Used to correct the value that should be paired with its key; since certain values are skipped over when populating the table, it is used to correct for what value should actually be paired with the key
	int offset = 0;

	//For-loop that poulates table
	for(int i = 0; i < 36; i++) {
		//Used to store the decimal digits 0-9
		if(i < 10) {
			table[to_string(i)] = i;
		}else {
			//Initialize variable to character representation of a decimal number greater than 9 and less than 27
			char c = 'A' + (i - 10);

			//Converts character to string
			string s(1, c);

			//Checks if the digit is in the confusedDigit table; if it is not, then it is stored in table; otherwise, it increments offset
			if(confusedDigitTable.find(s) == confusedDigitTable.end())
				table[s] = i - offset;
			else
				offset++;
		}
	}

	//Returns unordered_map
	return table;
}

int main(int agrc, char** argv) {
	//Initializing variables to store information from input
	int numberOfInputs, lineNumber;
	string ucn, ucnLine;

	//Initializing unordered_map with values that should map to some other value
	unordered_map<string, string> confusedDigitTable({{"B", "8"}, {"G", "C"}, {"I", "1"}, {"O", "0"}, {"Q", "0"}, {"S", "5"}, {"U", "V"}, {"Y", "V"}, {"Z", "2"}});
	
	//Initiallizing unordered_map with values from 0 to 35, skipping values found in confusedDigitTable
	unordered_map<string, int> digitTable = populateTable(confusedDigitTable);

	//Storing the number of inputs in the test case
	cin >> numberOfInputs;

	for(int i = 1; i <= numberOfInputs; i++) {
		//Storing lineNumber and UCN value from input
		cin >> lineNumber >> ucnLine;

		//Extracts the first 8 characters from ucnLine as the first 8 characters represent the UCN number
		ucn = ucnLine.substr(0, 8);

		//Calculates what the check digit should be given a UCN value and two unordered_maps
		ull ucnCheckDigitValue = calculateCheckDigit(ucn, confusedDigitTable, digitTable);

		//Extracts the supposed check digit from the last character from ucn
		string checkDigit(1, ucnLine[8]);

		/*Checks if the extracted check digit is in the confusedDigitTable or not. 
		  If it is, then it replaces the value of checkDigit with the "right value" in the digit table
		*/
		if(confusedDigitTable.find(checkDigit) != confusedDigitTable.end())
			checkDigit = digitTable[checkDigit];

		/*Checks if the calculated check digit is the same as the suppoed check digit; 
		  If it is, then it outputs the line number and the decimal value of the ucn number
		  If they are not the same, then it outputs the line number and "Invalid"
		*/
		if((ucnCheckDigitValue % 27) == digitTable[checkDigit])
			cout << lineNumber << " " << convertFromBase27ToBase10(ucn, confusedDigitTable, digitTable) << endl;
		else
			cout << lineNumber << " Invalid" << endl;
	}

	return 0;
}