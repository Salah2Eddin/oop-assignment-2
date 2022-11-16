#pragma once

#include <utility>
#include "XOBoard.h"

using namespace std;

class Player {
protected:
    char symbol;
public:
    Player() = default;
    Player(char symbol);
    ~Player() = default;

    virtual pair<int, int> getMove();

    char getSymbol() const;
    void setSymbol(char symbol);
};