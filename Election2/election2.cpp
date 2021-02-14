#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

int createCandidateList(unordered_map<string, pair<string, int>>& candidates, const int numberOfCandidates) {
	string candidate, party;

	for(int i = 0; i < numberOfCandidates; i++) {
		getline(cin, candidate);
		getline(cin, party);

		candidates.insert({candidate, {party, 0}});
	}

	return numberOfCandidates;
}

int countVotes(unordered_map<string, pair<string, int>>& candidates, const int numberOfVotes) {
	string candidate;

	for(int i = 0; i < numberOfVotes; i++) {
		getline(cin, candidate);

		if(candidates.find(candidate) != candidates.end())
		    get<1>(candidates.at(candidate))++;
	}

	return numberOfVotes;
}

void determineWinner(unordered_map<string, pair<string, int>>& candidates, const int numberOfVotes, const int numberOfCandidates) {
	double greatestPercentage = (double) 1/numberOfCandidates, percentage;
	string party = "tie";

	for(auto& candidate : candidates) {
		percentage = (double) candidate.second.second/numberOfVotes;

		if(percentage > greatestPercentage) {
			greatestPercentage = percentage;
			party = candidate.second.first;
		}
	}

	cout << party << endl;
}


int main(int argc, char** argv) {
	string size;
	int numberOfCandidates, numberOfVotes;
	unordered_map<string, pair<string, int>> candidates;

	getline(cin, size);

	numberOfCandidates = createCandidateList(candidates, stoi(size));

	getline(cin, size);

	numberOfVotes = countVotes(candidates, stoi(size));

	determineWinner(candidates, numberOfVotes, numberOfCandidates);
	
	return 0;
}
