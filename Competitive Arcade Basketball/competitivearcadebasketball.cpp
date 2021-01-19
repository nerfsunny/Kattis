#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    /* Initializing variables
       name, stores the player's name
       points, stores the number of points they scored when they shot the basketball
       minimumPoints, the lowest number of points the player needs to score in order to win
       numberOfPlayers, stores the number of players in the test case
       scoreHistory, stores the number of lines that contain the player's name and number of points they scored in the test case
    */
    string name;
    int points, minimumPoints, numberOfPlayers, scoreHistory;

    /* Initializing containers
        scoreboard stores each player's total number of points. The key is the player's name and the value is their total score
        players stores the players who have reached the minimum number of points
    */
    unordered_map<string, int> scoreboard;
    vector<string> players;

    //Storing values in their respective variables
    cin >> numberOfPlayers >> minimumPoints >> scoreHistory;

    //Setting the capacity of the containers with the number of players in the game
    scoreboard.reserve(numberOfPlayers);
    players.reserve(numberOfPlayers);

    //For-loop that inserts a player into the scoreboard
    for(int i = 0; i < numberOfPlayers; i++) {
        cin >> name;
        scoreboard.insert({name, 0});
    }

    for(int i = 0; i < scoreHistory; i++) {
        //Stores player name and how many points they scored in that instant
        cin >> name >> points;

        //Adds points to total score
        scoreboard[name] += points;

        //Checks if the current player has reached the minimum amount of points and is not already in players; if it is not, then it stores the player name in players
        if(scoreboard[name] >= minimumPoints && find(players.begin(), players.end(), name) == players.end())
            players.push_back(name);
    }

    //Checks if any players have reached the minimum number of points for the game. If no player has reached the minimum, then it outputs "No winner!". Otherwise, it outputs the winning players in order of who reached it first
    if(players.size() == 0)
        cout << "No winner!" << endl;
    else
        for(string p : players)
            cout << p << " wins!" << endl;
    
    return 0;
}