#include <vector>
#include "XOBot.h"

Bot::Bot(char symbol) : Player(symbol) {}

pair<int, int> Bot::getMove() {
    pair<int, int> bestMove;
    int bestScore = -10000;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (Board::isMoveValid(i, j)) {
                Board::makeMove(i, j, symbol);
                int mv = min_minimax(1, 'X');
                Board::undoMove(i, j);
                if (mv >= bestScore) {
                    bestScore = mv;
                    bestMove = make_pair(i, j);
                }
            }
        }
    }
    cout << bestScore << endl;
    return bestMove;
}

int Bot::evaluate(int depth) {
    if (Board::isWin('O'))
        return 10 - depth;
    if (Board::isWin('X'))
        return - 10 + depth;
    if (Board::isDraw())
        return 0;
    return INT_MIN;
}

int Bot::max_minimax(int depth, char player) {
    int res = evaluate(depth);
    if (res != INT_MIN) {
        return res;
    }

    res = -10000;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (Board::isMoveValid(i, j)) {
                Board::makeMove(i, j, player);
                int mv = min_minimax(depth + 1, player=='X'? 'O' : 'X');
                Board::undoMove(i, j);
                res = max(res, mv);
            }
        }
    }
    return res;
}

int Bot::min_minimax(int depth, char player) {
    int res = evaluate(depth);
    if (res != INT_MIN) {
        return res;
    }

    res = 10000;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (Board::isMoveValid(i, j)) {
                Board::makeMove(i, j, player);
                int mv = max_minimax(depth + 1, player=='X'? 'O' : 'X');
                Board::undoMove(i, j);
                res = min(res, mv);
            }
        }
    }
    return res;
}