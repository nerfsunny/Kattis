#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	vector<int> shotDistance;
	vector<int> courseLength;

	int shotDistanceInput, courseLengthInput, input;
	int numberOfHoles = 0;

	cin >> shotDistanceInput;

	for(int i = 0; i < shotDistanceInput; i++) {
		cin >> input;
		shotDistance.push_back(input);
	}

	cin >> courseLengthInput;

	for(int i = 0; i < courseLengthInput; i++) {
		cin >> input;
		courseLength.push_back(input);
	}

	//sort(shotDistance.begin(), shotDistance.end());
	//sort(courseLength.begin(), courseLength.end());

	for(int x : courseLength) {
		if(binary_search(shotDistance.begin(), shotDistance.end(), x)) {
			numberOfHoles++;
			continue;
		}

		for(int y : shotDistance) {
			if(y > x)
				break;

			if(binary_search(shotDistance.begin(), shotDistance.end(), (x - y))) {
				numberOfHoles++;
				break;
			}
		}
	}

	cout << numberOfHoles << endl;

	return 0;
}