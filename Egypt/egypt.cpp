#include <iostream>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

//Checks if the sides satisfy Pythagoreans Theorem
bool isRightTriangle(const ull a, const ull b, const ull c) {
	return (pow(a, 2) + pow(b, 2)) == pow(c, 2);
}

int main(int argc, char** argv) {
	//Initializing input. a, b, and c are used to store the sides of the triangle
	ull a, b, c;

	//While-loop that goes through the input and stores the three numbers
	while(cin >> a >> b >> c) {
		//If-statemebt that checks if the input is at EOF
		if(a == 0 && b == 0 && c == 0)
			break;

		//If-statement that checks if one of the three combinations result in a right triangle. If it does, then it outputs right. Otherwise, it returns wrong
		if(isRightTriangle(a, b, c) || isRightTriangle(b, c, a) || isRightTriangle(a, c, b))
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return 0;
}