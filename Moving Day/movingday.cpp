#include <iostream>
#define VOLUME(x, y, z) ((x) * (y) * (z))
#define DIFFERENCE(a, b) ((a) - (b))

using namespace std;
using ll = long long int;

int main(int argc, char** argv) {
	/* Initializing variables
       num1, num2, num3: stores the dimension of a box
       targetVolume: the volume needed to store all of the theoretical items in one box
       largestVolume: the larget volume possible, given all of the boxes and their dimensions
       inputSize: the number of boxes (described by dimensions) in a given test case
	*/
	ll num1, num2, num3, targetVolume, largestVolume = 0;
	int inputSize;

	//Storing the number of inputs and target volume into their respective variables
	cin >> inputSize >> targetVolume;


	//Iterates through all of the boxes dimension in a test case
	for(int i = 0; i < inputSize; i++) {
		//Storing dimensions of the box
		cin >> num1 >> num2 >> num3;

		//If the current volume is stictly greater than the current largest volume, then it stores this value into largest volume
		if(VOLUME(num1, num2, num3) > largestVolume)
			largestVolume = VOLUME(num1, num2, num3);
	}

	//Outptus the difference between the largest possible volume, given the inputs, and the given targetVolume
	cout << DIFFERENCE(largestVolume, targetVolume) << endl;

	return 0;
}