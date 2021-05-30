#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

class Player {
    private:
        string name, nation, league, team;
    
    public:
        Player(string name, string nation, string league, string team) {
            this->name = name;
            this->nation = nation;
            this->league = league;
            this->team = team;
        }
    
        string getName() {
            return name;
        }
    
        string getTeam() {
            return team;
        }
    
        string getLeague() {
            return league;
        }
        
        string getNation() {
            return nation;
        }
    
        string toString() {
            return name + " " + team + " " + league + " " + team;
        }
};

void createGraph(unordered_map<int, vector<int>>& graph) {
    int numberOfEdges, node1, node2;
    cin >> numberOfEdges;
    for(int i = 0; i < numberOfEdges; i++) {
        cin >> node1 >> node2;
        
        if(graph.find(node1) != graph.end())
            graph.at(node1).push_back(node2);
        else
            graph.insert({node1, vector<int>{node2}});
    }
}

void createTeamRoster(unordered_map<int, Player>& teamRoster) {
    string name, nation, league, team;
    
    for(int i = 0; i < 10; i++) {
        cin >> name >> nation >> league >> team;
        teamRoster.insert({i, Player(name, nation, league, team)});
    }
}

bool fromSameTeam(Player& player1, Player& player2) {
    return player1.getTeam() == player2.getTeam();
}

bool fromSameCountry(Player& player1, Player& player2) {
    return player1.getNation() == player2.getNation();
}

bool fromSameLeague(Player& player1, Player& player2) {
    return player1.getLeague() == player2.getLeague();
}

int synergyValue1(Player& player1, Player& player2) {
    if(fromSameCountry(player1, player2) || fromSameLeague(player1, player2))
        return 1;
    
    return 0;
}

int synergyValue2(Player& player1, Player& player2) {
    if(fromSameTeam(player1, player2) || (fromSameCountry(player1, player2) && fromSameLeague(player1, player2)))
        return 2;
    
    return 0;
}

int synergyValue3(Player& player1, Player& player2) {
    if(fromSameTeam(player1, player2) && fromSameCountry(player1, player2))
        return 3;
    
    return 0;
}

int synergyScore(Player& player1, Player& player2) {
    return synergyValue1(player1, player2) + synergyValue2(player1, player2) + synergyValue3(player1, player2);
}

bool isPerfectSynergy(unordered_map<int, vector<int>>& graph, unordered_map<int, Player>& teamRoster) {
    if(graph.empty())
        return false;
    
    int totalSynergyScore = 0;
    
    for(auto& currentNode : graph) {
        for(int connectedNode : currentNode.second)
            totalSynergyScore += synergyScore(teamRoster.at(currentNode.first), teamRoster.at(connectedNode));
        
        if(totalSynergyScore < currentNode.second.size())
            return false;
        
        totalSynergyScore = 0;
    }
    
    return true;
}

int main(int argc, char** argv) {
    unordered_map<int, vector<int>> graph;
    unordered_map<int, Player> teamRoster;
    
    createGraph(graph);
    createTeamRoster(teamRoster);
    
    cout << (isPerfectSynergy(graph, teamRoster) ? "yes" : "no") << endl;
    
    return 0;
}
