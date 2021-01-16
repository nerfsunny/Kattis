#include <iostream>
#include <vector>
#include <algorithm>

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
    ll highestHappiness = 0, currentHappiness;

    cin >> size;

    vector<int> line;
    line.reserve(size);

    for(int i = 0; i < size; i++) {
        cin >> num;

        if(num == 0)
            startingIndex = 1;
        
        line.push_back(num);
    }

    int currentIndex = startingIndex;

    do {
        

        currentHappiness = happinessSum(line);

        if(currentHappiness > highestHappiness)
            highestHappiness = currentHappiness;
    }while(startingIndex != currentIndex);
    
    return 0;
}