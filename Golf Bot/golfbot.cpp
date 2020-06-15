#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	//vector<int> shotDistance;
	//vector<int> courseLength;
	set<int> shotDistance;
	set<int> courseLength;

	int shotDistanceInput, courseLengthInput, input;
	int numberOfHoles = 0;

	cin >> shotDistanceInput;
	//shotDistance.reserve(shotDistanceInput);

	for(int i = 0; i < shotDistanceInput; i++) {
		cin >> input;
		//shotDistance.emplace_back(input);
		shotDistance.insert(input);
	}

	cin >> courseLengthInput;
	//courseLength.reserve(courseLengthInput);

	for(int i = 0; i < courseLengthInput; i++) {
		cin >> input;
		//courseLength.emplace_back(input);
		courseLength.insert(input);
	}

	auto begin = shotDistance.begin();
	auto end = shotDistance.end();

	for(auto &x : courseLength) {
		if(binary_search(begin, end, x)) {
			numberOfHoles++;
			continue;
		}

		/*if(shotDistance.find(x) != end) {
			numberOfHoles++;
			continue;
		}*/

		for(auto &y : shotDistance) {
			if(y > x)
				break;

			if(binary_search(begin, end, (x - y))) {
				numberOfHoles++;
				break;
			}

			/*if(shotDistance.find(x - y) != end) {
				numberOfHoles++;
				break;
			}*/
		}
	}

	cout << numberOfHoles << "\n";

	return 0;
}