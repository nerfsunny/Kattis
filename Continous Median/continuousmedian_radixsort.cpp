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

void radixSort(vector<int>& numbers, const int numberOfPasses) {
    vector<int> temp(numbers.size()), significantDigit(numbers.size()), digits(10, 0);

    for(int i = 0; i < numberOfPasses; i++) {
        for(int j = 0; j < numbers.size(); j++) {
            significantDigit.at(j) = digit(numbers.at(j), i);
            digits[significantDigit.at(j)]++;
        }

        for(int w = 1; w < digits.size(); w++)
            digits.at(w) += digits.at(w-1);

        for(int k = numbers.size() - 1; k >= 0; k--) {
            temp.at(digits.at(significantDigit.at(k)) - 1) = numbers.at(k);
            digits[significantDigit.at(k)]--;
        }

        swap(numbers, temp);
        reset(digits);
    }
}

int medianValue(vector<int>& numbers) {
    int medianIndex = numbers.size()/2, value;

    if(numbers.size() % 2 == 0)
        value = (numbers.at(medianIndex - 1) + numbers.at(medianIndex))/2;
    else
        value = numbers.at(medianIndex);
    
    return value;
}

int main(int argc, char** argv) {
    int testCases, testCaseSize, num, largestNum = -1;
    ull sum = 0;
    vector<int> numbers;

    cin >> testCases;

    for(int i = 0; i < testCases; i++) {
        cin >> testCaseSize;
        numbers.reserve(testCaseSize);

        for(int j = 0; j < testCaseSize; j++) {
            cin >> num;

            if(num > largestNum)
                largestNum = num;

            numbers.push_back(num);

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