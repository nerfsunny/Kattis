#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
using ull = unsigned long long int;

ull gcd(const ull num1, const ull num2) {
    if(num1 == num2)
		return num1;

	if(num2 == 0)
		return num1;

	return gcd(num2, num1 % num2);
}

ull lcm(const ull num1, const ull num2) {
    return ((num1)/gcd(num2, num1)) * num2;
}

int main(int argc, char** argv) {
    vector<ull> nums;
    string line, num;
    stringstream ss;

    while(getline(cin, line)) {
        ss.str(line);

        while(ss >> num)
            nums.emplace_back(stoull(num));

        sort(nums.begin(), nums.end());

        ull lcmNum = nums.at(0), num2;
        nums.erase(nums.begin());

        while(nums.size() > 0) {
            num2 = nums.at(0);
            lcmNum = lcm(lcmNum, num2);
            nums.erase(nums.begin());
        }

        cout << lcmNum << endl;

        nums.clear();
        ss.clear();
    }
    
    return 0;
}