#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <utility>
#include <iterator>

using namespace std;

int main(int argc, char** argv) {
	int year, inputSize, num;
	string country;
	unordered_map<string, multiset<int>> trips;

	cin >> inputSize;

	for(int i = 0; i < inputSize; i++) {
		cin >> country >> year;

		if(trips.find(country) != trips.end())
			trips.at(country).emplace(year);
		else {
			multiset<int> s;
			s.emplace(year);
			trips.insert(make_pair(country, s));
		}
	}

	cin >> inputSize;
	multiset<int>::iterator it;

	for(int i = 0; i < inputSize; i++) {
		cin >> country >> num;
		it = trips.at(country).begin();
		advance(it, num - 1);

		cout << *it << endl;
	}

	return 0;
}