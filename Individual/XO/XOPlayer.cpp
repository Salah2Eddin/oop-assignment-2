#include <iostream>
#include "XOPlayer.h"


using namespace std;

Player::Player(char symbol) : symbol(char(symbol)) {}

pair<int, int> Player::getMove() {
    int x, y;
    cout << "Enter move's column and row separated by space: ";
    cin >> x >> y;
    return make_pair(x-1, y-1);
}

char Player::getSymbol() const {
    return symbol;
}

void Player::setSymbol(char symbol) {
    Player::symbol = symbol;
}
