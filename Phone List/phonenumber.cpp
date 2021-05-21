#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isUniqueNumber(const string& number, const vector<string>& numbers) {
	/*for(int i = 1; i <= number.length(); i++)
		if(find(numbers.begin(), numbers.end(), number.substr(0, i)) != numbers.end())
			return false;*/
    for(const string& listedNumber : numbers)
        if(number.find(listedNumber) != string::npos)
            return false;

	return true;
}

int main(int argc, char** argv) {
	int numberOfTestCases, testCaseSize;
	string number;
	bool print = true;
	vector<string> numbers;
	
	cin >> numberOfTestCases;
	
	for(int i = 0; i < numberOfTestCases; i++) {
		cin >> testCaseSize;
		
		for(int j = 0; j < testCaseSize; j++) {
			cin >> number;
			
			if(!isUniqueNumber(number, numbers)) {
				print = false;
				break;
			}else
				numbers.push_back(number);
		}
		
		if(!print) {
			cout << "NO" << endl;
			print = true;
		}else
			cout << "YES" << endl;
			
		numbers.clear();
	}
	
	return 0;
}
