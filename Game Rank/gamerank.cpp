#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<int, int> populateTable() {
    unordered_map<int, int> valueTable;
    int numberOfStars = 2;
    int counter = 0;

    for(int index = 25; index > 0; index--) {
        valueTable[index] = numberOfStars;
        counter++;

        if(counter == 5 && index > 10) {
            counter = 0;
            numberOfStars++;
        }
    }

    valueTable[0] = 0;

    return valueTable;
}

int main(int argc, char** argv) {
	string gameRecord;
	int numberOfStars = 0, rank = 25, combo = 0;
	unordered_map<int, int> ranks = populateTable();

	cin >> gameRecord;

	for(char x : gameRecord) {
		if(x == 'W') {
			numberOfStars++;
			combo++;

			if(combo >= 3 && rank > 5)
				numberOfStars++;

			if(rank != 0 && numberOfStars > ranks[rank-1]) {
				rank--;
				numberOfStars -= ranks[rank];
			}
		}else {
			combo = 0;

			if(rank == 0 || rank > 20)
				continue;

			if(numberOfStars == 0) {
				if(rank != 20) {
					rank++;
					numberOfStars = ranks[rank] - 1;
				}
			}else
				numberOfStars--;
		}
	}

	if(rank == 0)
		cout << "Legend" << endl;
	else
		cout << rank << endl;

	return 0;
}
