#include <iostream>
#include <set>

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

int main(int argc, char** argv) {
    ull num;
    set<ull> numberSequence;

    return 0;
}