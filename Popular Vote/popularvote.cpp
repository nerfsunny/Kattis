#include <iostream>
#include <vector>

using namespace std;

void determineWinner(const int totalSumOfVotes, vector<int>& electionResults) {
    int candidate = -1;
    double percentage = 1.0/electionResults.size();
    
    for(int i = 0; i < electionResults.size(); i++) {
        if((double) electionResults.at(i)/totalSumOfVotes > percentage) {
            percentage = (double) electionResults.at(i)/totalSumOfVotes;
            candidate = i + 1;
        }
    }
    
    if(candidate == -1)
        cout << "no winner" << endl;
    else if(percentage > 0.5)
        cout << "majority winner " << candidate << endl;
    else
        cout << "minority winner " << candidate << endl;
}

int main(int argc, char** argv) {
    int numberOfTestCases, numberOfCandidates, numberOfVotes, totalSumOfVotes = 0;
    vector<int> electionResults;
    
    cin >> numberOfTestCases;
    
    for(int i = 0; i < numberOfTestCases; i++) {
        cin >> numberOfCandidates;
        
        for(int j = 0; j < numberOfCandidates; j++) {
            cin >> numberOfVotes;
            totalSumOfVotes += numberOfVotes;
            electionResults.push_back(numberOfVotes);
        }
        
        determineWinner(totalSumOfVotes, electionResults);
        electionResults.clear();
        totalSumOfVotes = 0;
    }
    
    return 0;
}
