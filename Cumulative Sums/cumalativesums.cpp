#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long int;

ull calculateSOD(ull num) {
    ull sum = 0;

    while(num > 0) {
        sum += (num % 10);
        num /= 10;
    }

    return sum;
}

ull calculateSum(vector<ull>& sequence, const ull num) {
    ull sum = 0;

    for(int i = 0; i < num; i++) 
        sum += sequence.at(i);

    return sum;
}

int main(int argc, char** argv) {
    ull num, numberOfTestCases, sod;
    vector<ull> numberSequence {1};

    cin >> numberOfTestCases;

    for(int i = 0; i < numberOfTestCases; i++) {
        cin >> num;

        if(num > numberSequence.size()) {
            for(ull j = numberSequence.size()-1; j < num; j++) {
                sod = numberSequence.at(j) + calculateSOD(numberSequence.at(j));
                numberSequence.push_back(sod);
            }
        }

        cout << (calculateSum(numberSequence, num) % 1000000007) << endl;
    }

    return 0;
}