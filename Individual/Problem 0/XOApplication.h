#pragma once

#include "XOPlayer.h"
#include "XOBot.h"
#include "XOBoard.h"

class XOApplication {
private:
    static Player *player1;
    static Player *player2;
public:
    XOApplication();

    ~XOApplication();

    static void run();

    static void reset();
};