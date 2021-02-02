#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	/* Initializing variables
     * year, the most recent year at which the launch window between Mars and Earth was the smallest
     * month, the most recent month at which the launch window between Mars and Earth was the smallest
     * proposedYear, stores the year that a launch is proposed
	 */
	int year = 2018, month = 4, proposedYear;

	//Storing the year
	cin >> proposedYear;

	//Loops until the closest launch window is the proposedYear or after
	while(year < proposedYear) {
		//Increments both variables by 2, as the conditions appear every 26 months (which is 2 years and 2 months)
		year += 2;
		month += 2;

		//If the month is past Decemember, it subtracts 12 from month and increments year by 1 
		if(month > 12) {
			month -= 12;
			year++;
		}
	}

	//If the two variables are the same, then it prints yes. Otherwise, it prints no
	if(proposedYear == year)
		cout << "yes\n";
	else
		cout << "no\n";
}