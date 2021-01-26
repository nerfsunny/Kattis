#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	int inputSize, teamSize, num, sum = 0;
	vector<int> number;
	cin >> inputSize;

	for(int i = 0; i < inputSize; i++) {
		cin >> teamSize;
		number.reserve(teamSize * 3);

		for(int j = 0; j < teamSize * 3; j++) {
			cin >> num;
			number.emplace_back(num);
		}

		sort(number.begin(), number.end());

		for(int k = 1; k < number.size(); k+=3)
			sum += number.at(k);

		cout << sum << endl;
		sum = 0;
		number.clear();
	}

	return 0;
}