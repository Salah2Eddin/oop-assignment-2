#pragma once

#include <utility>
#include "XOPlayer.h"

using namespace std;

class Bot : public Player {
private:
    int min_minimax(int depth, char player);
    int max_minimax(int depth, char player);
    static int evaluate(int depth);

public:
    Bot() = default;
    Bot(char symbol);
    pair<int, int> getMove();
};