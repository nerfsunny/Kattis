#include <iostream>
#include <vector>

using namespace std;

//Storing chess board and recording position of queen pieces
void storeBoard(vector<vector<char>>& chessBoard, vector<int>& queenPosition) {
    //Initializing variable, used to store the chess board and queen position pieces into memory
    char ch;
    
    for(int i = 0; i < 8; i++) {
        //Creating row
        chessBoard.push_back(vector<char>());
        
        //Recording each character in the row
        for(int j = 0; j < 8; j++) {
            //Storing character
            cin >> ch;
            
            //If the current character is a queen, stores the column index in queenPositino
            if(ch == '*')
                queenPosition.push_back(j);
            
            //Storing character in 2d vector
            chessBoard.at(i).push_back(ch);
        }
    }
}

//Checks if there are any other queens that are in the same row as the selected queen
bool validRow(const vector<vector<char>>& chessBoard, const int row) {
    //Initializing variable, used to count the number of queens in the same row
    int numberOfQueens = 0;
    
    //Goes though every index in row
    for(int col = 0; col < 8; col++)
        //Checks if current position on the chessboard at row and col contains a queen; if so, increments counter.
        if(chessBoard.at(row).at(col) == '*')
            numberOfQueens++;
        
    //Checks if there were more than one queen in the selected row
    return (numberOfQueens == 1);
}

//Checks if there are any other queens that are in the same column as the selected queen
bool validColumn(const vector<vector<char>>& chessBoard, const int column) {
    //Initializing variable, used to count the number of queens in the same column
    int numberOfQueens = 0;
    
    //Goes though every index in column
    for(int row = 0; row < 8; row++)
        //Checks if current position on the chessboard at row and col contains a queen; if so, increments counter.
        if(chessBoard.at(row).at(column) == '*')
            numberOfQueens++;
        
    //Checks if there were more than one queen in the selected column
    return (numberOfQueens == 1);
}

//Checking negative slope (top-right to bottom-left)
bool validDiagonal1(const vector<vector<char>>& chessBoard, const int row, const int column) {
    //Initializing variables, used to keep track of what position we are checking on the diagonal
    int currentRow = row + 1, currentCol = column + 1;
    
    //Checks all of the possible positions on this queen's diagonal path down and right of row and column
    while(currentRow <= 7 && currentCol <= 7) {
        //If it finds a queen at the current position, exits the current method with false
        if(chessBoard.at(currentRow).at(currentCol) == '*')
            return false;
        
        //Increments positions by 1
        currentRow++;
        currentCol++;
    }
    
    //Storing values to check the other portion of the diagonal
    currentRow = row - 1;
    currentCol = column - 1;
    
    //Checks all of the possible positions on this queen's diagonal path up and left of row and column
    while(currentRow >= 0 && currentCol >= 0) {
        //If it finds a queen at the current position, exits the current method with false
        if(chessBoard.at(currentRow).at(currentCol) == '*')
            return false;
        
        //Decrements positions by 1
        currentRow--;
        currentCol--;
    }
    
    //Found no conflict
    return true;
}

//Checking positive slope (bottom-right to top-left)
bool validDiagonal2(const vector<vector<char>>& chessBoard, const int row, const int column) {
    //Initializing variables, used to keep track of what position we are checking on the diagonal
    int currentRow = row + 1, currentCol = column - 1;
    
    //Checks all of the possible positions on this queen's diagonal path down and left of row and column
    while(currentRow <= 7 && currentCol >= 0) {
        //If it finds a queen at the current position, exits the current method with false
        if(chessBoard.at(currentRow).at(currentCol) == '*')
            return false;
        
        //Increments and decrements positions by 1
        currentRow++;
        currentCol--;
    }
    
    //Storing values to check the other portion of the diagonal
    currentRow = row - 1;
    currentCol = column + 1;
    
    //Checks all of the possible positions on this queen's diagonal path up and right of row and column
    while(currentRow >= 0 && currentCol <= 7) {
        //If it finds a queen at the current position, exits the current method with false
        if(chessBoard.at(currentRow).at(currentCol) == '*')
            return false;
        
        //Decrements and increments positions by 1
        currentRow--;
        currentCol++;
    }
    
    //Found no conflict
    return true;
}

//Checks if the currently selected queen has a conflict with another queen on one of its possible diagonals. If so, this method returns false. Otherwise true.
bool validDiagonal(const vector<vector<char>>& chessBoard, const int row, const int column) {
    return validDiagonal1(chessBoard, row, column) && validDiagonal2(chessBoard, row, column);
}

//Checks if the currenly selected queen is safe by checking all of its possible movements (same row, same column, diagonals).
//If it is determined that any of these movements results in a conflict, this returns false. Otherwise, true
bool isQueenSafe(const vector<vector<char>>& chessBoard, const int row, const int column) {
    return validRow(chessBoard, row) && validColumn(chessBoard, column) && validDiagonal(chessBoard, row, column);
}

//Checks if any of the queens are in conflict with any of the other queens. Returns true if no queen is in conflict with another queen. Otherwise, false.
bool isValidBoard(const vector<vector<char>>& chessBoard, const vector<int>& queenPosition) {
    //Goes through every queen recorded in queenPosition
    for(int row = 0; row < 8; row++)
        //If the queen is in conflict with another queen, this method exits with false
        if(!isQueenSafe(chessBoard, row, queenPosition.at(row)))
            return false;
    
    //Found no conflict
    return true;
}

int main(int argc, char** argv) {
    /* Initializing containers,
     *
     * chessBoard, stores the given chess board for a test case
     * queenPosition, stores the positions of the queen pieces on the chess board.
     *                The index is the row value and the value stored at the index is the column value
     */
    vector<vector<char>> chessBoard;
    vector<int> queenPosition;
    
    //Storing chess board and recording queen positions
    storeBoard(chessBoard, queenPosition);
    
    //Checks if there is at least one queen is in conflict with another queen. If so, it prints invalid. Otherwise, valid.
    if(isValidBoard(chessBoard, queenPosition))
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;
    
    return 0;
}
