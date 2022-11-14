#include "XOApplication.h"

Player *XOApplication::player1 = new Player;
Player *XOApplication::player2 = new Bot;

XOApplication::XOApplication() {
    player1->setSymbol('X');
    player2->setSymbol('O');
}

XOApplication::~XOApplication() {
    delete player1;
    delete player2;
}

void XOApplication::run() {
    Board::printBoard();
    while (!Board::isWin(player1->getSymbol()) && !Board::isWin(player2->getSymbol()) && !Board::isDraw()) {
        pair<int, int> move = player1->getMove();
        while (!Board::isMoveValid(move.first, move.second)) {
            cout << "Invalid move!" << endl;
            move = player1->getMove();
        }
        Board::makeMove(move.first, move.second, player1->getSymbol());
        Board::printBoard();
        cout << string(12, '=') << endl;
        if (Board::isWin(player1->getSymbol())) {
            cout << "Player 1 wins!" << endl;
            break;
        }
        if (Board::isDraw()) {
            cout << "Draw!" << endl;
            break;
        }

        cout << "Bot's move:" << endl;
        move = player2->getMove();
        Board::makeMove(move.first, move.second, player2->getSymbol());
        Board::printBoard();

        if (Board::isWin(player2->getSymbol())) {
            cout << "Player 2 wins!" << endl;
            break;
        }
        if (Board::isDraw()) {
            cout << "Draw!" << endl;
            break;
        }
    }

    while (true) {
        char r = 'x';
        cout << "Do you want to play again? (Y/N)";
        cin >> r;
        r = tolower(r);

        switch (r) {
            case 'y': {
                reset();
                run();
            }
            case 'n': {
                return;
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
    }
}

void XOApplication::reset() {
    Board::resetBoard();
}
