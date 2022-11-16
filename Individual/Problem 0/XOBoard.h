#pragma once

#include <iostream>

class Board {
private:
    static int moves;
    static char board[3][3];
public:
    Board() = default;
    ~Board() = default;

    static void printBoard();
    static void resetBoard();
    static bool isFull();
    static bool isWin(char symbol);
    static bool isDraw();
    static bool isMoveValid(int x, int y);
    static void makeMove(int x, int y, char symbol);
    static void undoMove(int x, int y);

    static int getMoves();
};