#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <utility>

using namespace std;

void printResults(map<pair<double, double>, bool>& producesSweetHoney) {
	int sweet = 0, sour = 0;

	for(auto& beehive : producesSweetHoney)
		if(beehive.second)
			sweet++;
		else
			sour++;

	printf("%i sour, %i sweet\n", sour, sweet);
}

void populate(map<pair<double, double>, bool>& producesSweetHoney, vector<pair<double, double>>& points, const int inputSize) {
	double xPoint, yPoint;
	pair<double, double> point;

	for(int i = 0; i < inputSize; i++) {
		cin >> xPoint >> yPoint;
		point = make_pair(xPoint, yPoint);
		points.push_back(point);
		producesSweetHoney.insert({point, true});
	}
}

double calculateDistance(pair<double, double>& firstPoint, pair<double, double>& secondPoint) {
	double x = pow(firstPoint.first - secondPoint.first, 2), 
	       y = pow(firstPoint.second - secondPoint.second, 2);

	return sqrt(x + y);
}

void calculateConflicts(map<pair<double, double>, bool>& producesSweetHoney, vector<pair<double, double>>& points, const int inputSize, const double distance) {
	for(int i = 0; i < points.size(); i++) {
		if(producesSweetHoney.at(points.at(i))) {
			for(int j = i + 1; j < points.size(); j++) {
				if(producesSweetHoney.at(points.at(j)) && calculateDistance(points.at(i), points.at(j)) < distance) {
					producesSweetHoney.at(points.at(i)) = false;
					producesSweetHoney.at(points.at(j)) = false;
				}
			}
		}
	}
}

int main(int argc, char** argv) {
	vector<pair<double, double>> points;
	map<pair<double, double>, bool> producesSweetHoney;
	double distance;
	int inputSize;

	while(cin >> distance >> inputSize && distance != 0.0 && inputSize != 0) {
		points.reserve(inputSize);

		populate(producesSweetHoney, points, inputSize);

		calculateConflicts(producesSweetHoney, points, inputSize, distance);
		
		printResults(producesSweetHoney);

		points.clear();
		producesSweetHoney.clear();
	}

	return 0;
}