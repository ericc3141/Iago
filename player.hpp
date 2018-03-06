#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

class Player {
private:
    Side s;
    Board board;

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    int heuristic(Move *move);
    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif
