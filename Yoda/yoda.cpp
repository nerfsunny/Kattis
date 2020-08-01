#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	//Initiaiizing variables. num1, num2 are used to store the input. newNum1, newNum2 are used to store the bigger digits of their respective number at a certain index
	string num1, num2, newNum1, newNum2;

	//Storing initial numbers
	cin >> num1 >> num2;

	/*If-statement that checks if the two numbers are the same length.
	  If they aren't, then it prepends 0 to the number with the smaller length until they both are the same length
	*/
	if(num1.length() != num2.length()) {
		if(num1.length() < num2.length()) 
			while(num1.length() != num2.length())
				num1 = "0" + num1;
		else
			while(num1.length() != num2.length())
				num2 = "0" + num2;
	}

	//For-loop that iterates through both numbers to see which digit is bigger at a certain index.
	for(int i = num1.length() - 1; i >= 0; i--) {
		//If-statement that checks if the digit in num1 is strictly greater than the digit in num2
		if(stoi(num1.substr(i, 1)) > stoi(num2.substr(i, 1)))
			//Prepends the digit to newNum1
			newNum1 = num1.substr(i, 1) + newNum1;
		//If-statement that checks if the digit in num2 is strictly greater than the digit in num1
		else if(stoi(num1.substr(i, 1)) < stoi(num2.substr(i, 1)))
			//Prepends the digit to newNum2
			newNum2 = num2.substr(i, 1) + newNum2;
		else {
			//Prepends the digits to their respective variables if they are equal
			newNum1 = num1.substr(i, 1) + newNum1;
			newNum2 = num2.substr(i, 1) + newNum2;
		}
	}

	//If-statement that checks if there is a "YODA" number. If all the digits in one number is strictly greater than the other number, then the newNum variable for that smaller-digit number should be empty
	if(newNum1.empty() || newNum2.empty()) {
		//If-statement that checks which number is the "YODA" number. If num2 is greater than num1, then it prints "YODA" first; otherwise, it prints "YODA" second
		if(stoi(num2) > stoi(num1))
			cout << "YODA" << "\n" << stoi(newNum2) << "\n";
		else
			cout << stoi(newNum1) << "\n" << "YODA" << "\n";
	}else
		//Prints the modified numbers
		cout << stoi(newNum1) << "\n" << stoi(newNum2) << "\n";

	return 0;
}