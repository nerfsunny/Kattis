#include <iostream>
#include <vector>

using namespace std;

void storeBoard(vector<vector<char>>& chessBoard, vector<int>& queenPosition) {
    char ch;
    
    for(int i = 0; i < 8; i++) {
        chessBoard.push_back(vector<char>());
        for(int j = 0; j < 8; j++) {
            cin >> ch;
            
            if(ch == '*')
                queenPosition.push_back(j);
            
            chessBoard.at(i).push_back(ch);
        }
    }
}

bool validRow(const vector<vector<char>>& chessBoard, const int row) {
    int numberOfQueens = 0;
    
    for(int col = 0; col < 8; col++)
        if(numberOfQueens <= 1 && chessBoard.at(row).at(col) == '*')
            numberOfQueens++;
        
    return (numberOfQueens == 1);
}

bool validColumn(const vector<vector<char>>& chessBoard, const int column) {
    int numberOfQueens = 0;
    
    for(int row = 0; row < 8; row++)
        if(numberOfQueens <= 1 && chessBoard.at(row).at(column) == '*')
            numberOfQueens++;
        
    return (numberOfQueens == 1);
}

//Checking negative slope (top-right to bottom-left)
bool validDiagonal1(const vector<vector<char>>& chessBoard, const int row, const int column) {
    if((row == 7 && column == 0) || (row == 0 && column == 7))
        return true;
    
    int currentRow = row + 1, currentCol = column + 1;
    
    
    while(currentRow != row && currentCol != column) {
        
        
        if(chessBoard.at(row).at(column) == '.') {
            currentRow += 1;
            currentCol += 1;
        }else
            return false;
    }
        
    return true;
}

//Checking positive slope (bottom-right to top-left)
bool validDiagonal2(const vector<vector<char>>& chessBoard, const int row, const int column) {
    if((row == 0 && column == 0) || (row == 7 && column == 7))
        return true;
    
    int currentRow = row - 1, currentCol = column + 1;
    
    while(currentRow != row && currentCol != column) {
        
        
        if(chessBoard.at(row).at(column) == '.') {
            currentRow -= 1;
            currentCol += 1;
        }else
            return false;
    }
        
    return true;
}

bool validDiagonal(const vector<vector<char>>& chessBoard, const int row, const int column) {
    cout << "Diagonal 1 Safe: " << validDiagonal1(chessBoard, row, column) << endl;
    cout << "Diagonal 2 Safe: " << validDiagonal2(chessBoard, row, column) << endl;
    return validDiagonal1(chessBoard, row, column) && validDiagonal2(chessBoard, row, column);
}

bool isQueenSafe(const vector<vector<char>>& chessBoard, const int row, const int column) {
    printf("Queen Position Row %i Col %i:\n", row, column);
    cout << "Row Safe: " << validRow(chessBoard, row) << endl;
    cout << "Column Safe: " << validColumn(chessBoard, column) << endl;
    //cout << "Diagonal Safe: " << validDiagonal(chessBoard, row, column) << endl;
    return validRow(chessBoard, row) && validColumn(chessBoard, column) && validDiagonal(chessBoard, row, column);
}

bool isValidBoard(const vector<vector<char>>& chessBoard, const vector<int>& queenPosition) {
    for(int row = 0; row < 8; row++)
        if(!isQueenSafe(chessBoard, row, queenPosition.at(row)))
            return false;
    
    return true;
}

int main(int argc, char** argv) {
    vector<vector<char>> chessBoard;
    vector<int> queenPosition;
    bool isValid = true;
    
    storeBoard(chessBoard, queenPosition);
    
    for(int i : queenPosition)
        cout << i << endl;
    
    if(isValidBoard(chessBoard, queenPosition))
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;
    
    return 0;
}
