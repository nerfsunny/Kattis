#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;
using ll = long long int;

ll happinessSum(vector<int>& numbers) {
    ll sum = 0;

    for(int i = 1; i <= numbers.size(); i++) {
        sum += (i * numbers.at(i-1));
    }

    return sum;
}

int main(int argc, char**) {
    int size, num, startingIndex;
    ll highestHappiness = LLONG_MIN, currentHappiness;

    cin >> size;

    vector<int> line;
    vector<ll> totalHappinessValues;
    line.reserve(size);
    totalHappinessValues.reserve(size);

    for(int i = 0; i < size; i++) {
        cin >> num;

        if(num == 0)
            startingIndex = i;
        
        line.push_back(num);
    }

    int currentIndex = startingIndex;

    do {
        if(currentIndex == 0) {
            line.erase(line.begin());
            line.push_back(0);
            currentIndex = size - 1;
        }else {
            iter_swap(line.begin() + (currentIndex - 1), line.begin() + currentIndex);
            currentIndex--;
        }

        currentHappiness = happinessSum(line);

        if(currentHappiness > highestHappiness)
            highestHappiness = currentHappiness;
    }while(startingIndex != currentIndex);

    cout << highestHappiness << endl;
    
    return 0;
}