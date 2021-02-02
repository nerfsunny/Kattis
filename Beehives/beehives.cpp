#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <utility>

using namespace std;

void printResults(map<pair<double, double>, int>& numberOfConflicts, const int noConflicts) {
	int sweet = 0, sour = 0;

	for(auto& point : numberOfConflicts)
		if(point.second == noConflicts)
			sweet++;
		else
			sour++;

	printf("%i sour, %i sweet", sour, sweet);
}

void populate(map<pair<double, double>, int>& numberOfConflicts, vector<pair<double, double>>& points, const int inputSize) {
	double xPoint, yPoint;

	for(int i = 0; i < inputSize; i++) {
		cin >> xPoint >> yPoint;
		points.push_back(make_pair(xPoint, yPoint));
		numberOfConflicts.insert({make_pair(xPoint, yPoint), 0});
	}
}

double calculateDistance(pair<double, double>& firstPoint, pair<double, double>& secondPoint) {
	double x = firstPoint.first + secondPoint.first, y = firstPoint.second + secondPoint.second;
	double x2 = pow(x, 2), y2 = pow(y, 2);

	double result = pow((x2 + y2), 0.5);

	return result;
}

void calculateConflicts(map<pair<double, double>, int>& numberOfConflicts, vector<pair<double, double>>& points, const int inputSize, const double distance) {
	for(int i = 0; i < inputSize; i++) {
		for(int j = i + 1; j < inputSize; j++) {
			if(calculateDistance(points.at(i), points.at(j)) > distance) {
				numberOfConflicts[points.at(i)]++;
				numberOfConflicts[points.at(j)]++;
			}
		}
	}
}

int main(int argc, char** argv) {
	vector<pair<double, double>> points;
	map<pair<double, double>, int> numberOfConflicts;
	double distance;
	int inputSize;

	while(cin >> distance >> inputSize) {
		if(distance == 0.0 && inputSize == 0)
			break;

		points.reserve(inputSize);

		populate(numberOfConflicts, points, inputSize);

		calculateConflicts(numberOfConflicts, points, distance, inputSize);
		
		printResults(numberOfConflicts, inputSize - 1);

		points.clear();
		numberOfConflicts.clear();
	}

	return 0;
}