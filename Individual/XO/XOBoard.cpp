#include "XOBoard.h"

using namespace std;
int Board::moves = 0;
char Board::board[3][3] = {{'_', '_', '_'},
                           {'_', '_', '_'},
                           {'_', '_', '_'}};

void Board::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

bool Board::isFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_')
                return false;
        }
    }
    return true;
}

bool Board::isWin(char symbol) {
    // horizontal and vertical
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
            return true;
    }

    // diagonal
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return true;
    return false;
}

bool Board::isDraw() {
    return isFull() && !isWin('X') && !isWin('O');
}

bool Board::isMoveValid(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == '_';
}

void Board::makeMove(int x, int y, char symbol) {
    board[x][y] = symbol;
    moves++;
}

void Board::undoMove(int x, int y) {
    board[x][y] = '_';
    moves--;
}

void Board::resetBoard() {
    moves = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '_';
        }
    }
}

int Board::getMoves() {
    return moves;
}
