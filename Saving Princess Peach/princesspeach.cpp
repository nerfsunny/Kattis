#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	//Container to contain unique elements
	set<int> passedObstacles;

	//Initiallizng variables. numberOfObstacles is the total number of obstacles on the course, numberOfPassedObstacles is the number that Mario reports to have passed, and num is used to store the input before it is put in passedObstacles
	int numberOfObstacles, numberOfPassedObstacles, num;

	//Storing first two inputs into their respective variables
	cin >> numberOfObstacles >> numberOfPassedObstacles;

	//For-llop that goes through the rest of the input and stores all unique numbers into the set
	for(int i = 0; i < numberOfPassedObstacles; i++) {
		cin >> num;
		passedObstacles.emplace(num);
	}

	//Initiallizing variables for set iterators as these are called numberOfObstacles times
	auto begin = passedObstacles.begin(), end = passedObstacles.end();

	//For-loop that goes from 0 to numberOfObstacles - 1. If it can't find the number i in the set, it outputs the number
	for(int i = 0; i < numberOfObstacles; i++)
		if(find(begin, end, i) == end)
			cout << i << endl;

	//Outputs size of set
	cout << "Mario got " <<  passedObstacles.size() << " of the dangerous obstacles." << endl;

	return 0;
}