#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;
using ull = unsigned long long int;

int digit(int num, const int place) {
    for(int i = 0; i < place; i++)
        num /= 10;

    return num % 10;
}

void reset(vector<int>& v) {
    for(int i = 0; i < v.size(); i++)
        v.at(i) = 0;
}

void radixSort(vector<pair<int, int>>& numbers, const int numberOfPasses) {
    vector<pair<int, int>> temp(numbers.size(), {0, 0});
    vector<int> digits(10, 0);

    for(int i = 0; i < numberOfPasses; i++) {
        for(int j = 0; j < numbers.size(); j++) {
            get<1>(numbers.at(j)) = digit(numbers.at(j).first, i);
            digits[numbers.at(j).second]++;
        }

        for(int w = 1; w < digits.size(); w++)
            digits.at(w) += digits.at(w-1);

        for(int k = numbers.size() - 1; k >= 0; k--) {
            temp.at(digits.at(numbers.at(k).second) - 1) = {numbers.at(k).first, -1};
            digits[numbers.at(k).second]--;
        }

        swap(numbers, temp);
        reset(digits);
    }
}

int medianValue(vector<pair<int, int>>& numbers) {
    int medianIndex = numbers.size()/2, value;

    if(numbers.size() % 2 == 0)
        value = (numbers.at(medianIndex - 1).first + numbers.at(medianIndex).first)/2;
    else    
        value = get<0>(numbers.at(medianIndex));

    return value;
}

int main(int argc, char** argv) {
    int testCases, testCaseSize, num, largestNum = -1;
    ull sum = 0;
    vector<pair<int, int>> numbers;

    cin >> testCases;

    for(int i = 0; i < testCases; i++) {
        cin >> testCaseSize;
        numbers.reserve(testCaseSize);

        for(int j = 0; j < testCaseSize; j++) {
            cin >> num;

            if(num > largestNum)
                largestNum = num;

            numbers.push_back(make_pair(num, -1));

            radixSort(numbers, to_string(largestNum).length());
            sum += medianValue(numbers); 
        }

        cout << sum << endl;

        numbers.clear();
        largestNum = -1;
        sum = 0;
    }

    return 0;
}