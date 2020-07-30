#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	//Initializing variables. radius is the radius of the whole pizza, crust is the length from circle edge to where the cheese is on the pizza
	int radius, crust;

	//Storing values
	cin >> radius >> crust;

	//Calculates the radius of the cheese circle and stores it
	int innerRadius = radius - crust;

	//Calculates the percentage of the area of the cheese to the area of the pizza and stores it
	long double areaPercentage = ((pow(innerRadius, 2) * M_PI)/(pow(radius, 2) * M_PI)) * 100;

	//Outputs the result and goes to the sixth decimal place
	cout << fixed << setprecision(6) << areaPercentage << endl;

	return 0;
}