#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
using ull = unsigned long long int; 

int main(int argc, char** argv) {
    int testCases, testCaseSize, num;
    ull sum = 0;
    vector<int> numbers;

    //cin >> testCases;
    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++) {
        //cin >> testCaseSize;
        scanf("%d", &testCaseSize);

        for(int j = 0; j < testCaseSize; j++) {
            //cin >> num;
            scanf("%d", &num);
            numbers.push_back(num);

            sort(numbers.begin(), numbers.end());
            int median = numbers.size()/2;

            if(numbers.size() % 2 == 0)
                sum += ((numbers.at(median - 1) + numbers.at(median))/2);
            else 
                sum += numbers.at(median);
        }

        cout << sum << endl;
        numbers.clear();
        sum = 0;
    }

    return 0;
}