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
     int weights[8][8] = {
     	{4, -1, 1, 1, 1, 1, -1, 4},
     	{-1, 0, 0, 0, 0, 0, 0, -1},
     	{1, 0, 0, 0, 0, 0, 0, 1},
     	{1, 0, 0, 0, 0, 0, 0, 1},
     	{1, 0, 0, 0, 0, 0, 0, 1},
     	{1, 0, 0, 0, 0, 0, 0, 1},
     	{-1, 0, 0, 0, 0, 0, 0, -1},
     	{4, -1, 1, 1, 1, 1, -1, 4}
     };

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    int heuristic(Move *move);
    int weight_heuristic(Move *move);
    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif
