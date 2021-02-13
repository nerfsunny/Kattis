#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	/* Initiailizing variables,
     * inputSize, stores the number of trips and number of queries to determine the which year that [blank]th trip occured to that country
     * year, stores the year that the trip occured
     * num, used to store the trip number to a specific country (ex. 1 Icland, 2 Iceland)
     * country, stores the country name
	 */
	int inputSize, year, num;
	string country;

	/* Initializing containers,
	 * trips, stores the counrty and the years Bernie went to that country
	 *        key is the country and the value is a vector of years
     *
	 * isSorted, stores whether the vector associasted with country is sorted in ascending order
	 *           key is the country and the value is a boolean (true if it is sorted)
	 */
	unordered_map<string, vector<int>> trips;
	unordered_map<string, bool> isSorted;

	//Storing the total number of trips to recollect
	cin >> inputSize;

	//Iterates through all of the trips Bernie may want to recall
	for(int i = 0; i < inputSize; i++) {
		//Storing values into their respective variables
		cin >> country >> year;

		/* Checks if the country is already listed in trips. If it is, then it stores the year in its vector
		 * Otherwise, it creates a new entry in both containers
		 */
		if(trips.find(country) != trips.end())
			trips.at(country).emplace_back(year);
		else {
			isSorted.insert({country, false});
			trips.insert({country, vector<int> {year}});
		}
	}

	//Storing the number of queries to ask what year Bernie traveled to a specific country
	cin >> inputSize;

	//Iterates through all of the queries
	for(int i = 0; i < inputSize; i++) {
		//Storing values into their respective variables
		cin >> country >> num;

		/* First checks if the vector is sorted. If it is not, then it sorts it in ascending order and sets the value in isSorted to true
		 * This is done here so that time is not wasted to sort values every time a new entry is added for trips to country
		 * And also to not waste time sorting values for countries that may not be asked about
		 */
		if(isSorted.at(country) == false) {
			sort(trips.at(country).begin(), trips.at(country).end());
			isSorted.at(country) = true;
		}

		//Outputs the year at which Bernie took to country at blank-th time
		cout << trips.at(country).at(num - 1) << endl;
	}
}