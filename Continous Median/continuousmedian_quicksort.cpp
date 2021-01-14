#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long int; 

int partition(vector<int>& numbers, int startingIndex, int endingIndex) {
    int pivot = endingIndex, index = startingIndex;

    for(int i = startingIndex; i < endingIndex; i++) {
        if(numbers.at(i) < numbers.at(endingIndex)) {
            iter_swap(numbers.begin() + i, numbers.begin() + index);
            index++;
        }
    }

    iter_swap(numbers.begin() + pivot, numbers.begin() + index);

    return index;
}

void quickSort(vector<int>& numbers, int startingIndex, int endingIndex) {
    if(startingIndex < endingIndex) {
        int pivotIndex = partition(numbers, startingIndex, endingIndex);
        quickSort(numbers, pivotIndex + 1, endingIndex);
        quickSort(numbers, startingIndex, pivotIndex - 1);
    }
}

int medianValue(vector<int>& numbers) {
    int medianIndex = numbers.size()/2, medianValue = -1;

    if(numbers.size() % 2 == 0)
        medianValue = (numbers.at(medianIndex - 1) + numbers.at(medianIndex))/2;
    else
        medianValue = numbers.at(medianIndex);

    return medianValue;
}

int main(int argc, char** argv) {
    int testCases, testCaseSize, num;
    ull sum = 0;
    vector<int> numbers;

    cin >> testCases;

    for(int i = 0; i < testCases; i++) {
        cin >> testCaseSize;

        for(int j = 0; j < testCaseSize; j++) {
            cin >> num;
            numbers.push_back(num);

            quickSort(numbers, 0, numbers.size() - 1);

            sum += medianValue(numbers);
        }

        cout << sum << endl;
        numbers.clear();
        sum = 0;
    }

    return 0;
}