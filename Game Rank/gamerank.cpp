#include <iostream>
#include <vector>
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

		valueTable[0] = 0;
	}

	return valueTable;
}

int main(int argc, char** argv) {
	string record, result;
	int numberOfStars = 0;
	int combo = 0;
	int rank = 25;

	unordered_map<int, int> valueTable = populateTable();

	cin >> record;

	for(char x : record) {
		if(x == 'W') {
			numberOfStars++;
			combo++;

			if(combo >= 3 && rank > 5) 
				numberOfStars++;

			if(rank <= 5)
				combo++;

			if(numberOfStars > valueTable[rank]) {
				numberOfStars = numberOfStars - valueTable[rank];
				rank--;
			}

			//cout << "Character: " << x << " Stars: " << numberOfStars << " Combo: " << combo << " Rank: " << rank << endl;
		}else {
			combo = 0;

			if((rank > 20 && rank <= 25) || rank == 0) {
				//cout << "Character: " << x << " Stars: " << numberOfStars << " Combo: " << combo << " Rank: " << rank << endl;
				continue;
			}

			if(numberOfStars == 0) {
				if(rank == 20) {
					//cout << "Character: " << x << " Stars: " << numberOfStars << " Combo: " << combo << " Rank: " << rank << endl;
					continue;
				}
				else{
					numberOfStars = valueTable[rank] - 1;
					rank++;
				}
			}else
				numberOfStars--;

			//cout << "Character: " << x << " Stars: " << numberOfStars << " Combo: " << combo << " Rank: " << rank << endl;
		}
	}

	if(rank == 0)
		result = "Legend";
	else
		result = to_string(rank);

	cout << result << endl;

	return 0;
}
