#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int createBoard(vector<vector<char>>& board, const int xAxis, const int yAxis) {
    char boardCharacter;
    int playerShips = 0;

    for(int i = 0; i < yAxis; i++) {
        for(int j = 0; j < xAxis; j++) {
            cin >> boardCharacter;

            if(boardCharacter == '#')
                playerShips++;

            board.at(i).push_back(boardCharacter);
        }
    }

    return playerShips;
}

void storeMoves(vector<pair<int, int>>& moves, const int numberOfMoves) {
    int x, y;

    for(int i = 0; i < numberOfMoves; i++) {
        cin >> x >> y;
        moves.push_back(make_pair(x, y));
    }
}

void printBoard(vector<vector<char>>& board, const int xAxis, const int yAxis) {
    for(int i = 0; i < yAxis; i++) {
        for(int j = 0; j < xAxis; j++)
            cout << board.at(i).at(j);

        cout << endl;
    }
}

int main(int argc, char** argv) {
    int inputSize, xAxis, yAxis, numberOfMoves, player1Ships, player2Ships, movesUsed2 = 0;
    bool player1Lost = false, player2Lost = false;
    vector<pair<int, int>> moves;

    cin >> inputSize;

    for(int i = 0; i < inputSize; i++) {
        cin >> xAxis >> yAxis >> numberOfMoves;
        moves.reserve(numberOfMoves);
        vector<vector<char>> player1Board(yAxis), player2Board(yAxis);

        player1Ships = createBoard(player1Board, xAxis, yAxis);
        player2Ships = createBoard(player2Board, xAxis, yAxis);
        storeMoves(moves, numberOfMoves);

        for(int i = 0; i < moves.size(); i++) {
            if(i % 2 == 0) {
                
            }else {
                
            }
        }

        if(player1Lost && player2Lost)
            cout << "draw" << endl;
        else if(player1Lost)
            cout << "player two wins" << endl;
        else if(player2Lost)
            cout << "player one wins" << endl;

        moves.clear();
        player1Board.clear();
        player2Board.clear();
        player1Lost = false;
        player2Lost = false;
        movesUsed2 = 0;
    }

    return 0;
}