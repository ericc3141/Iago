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
     	{6, -1, 1, 1, 1, 1, -1, 6},
     	{-1, -3, 0, 0, 0, 0, -3, -1},
     	{1, 0, 0, 0, 0, 0, 0, 1},
     	{1, 0, 0, 0, 0, 0, 0, 1},
     	{1, 0, 0, 0, 0, 0, 0, 1},
     	{1, 0, 0, 0, 0, 0, 0, 1},
     	{-1, -3, 0, 0, 0, 0, -3, -1},
     	{6, -1, 1, 1, 1, 1, -1, 6}
     };

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    int heuristic(Move *move, Side side, Board *b);
    int weight_heuristic(Move *move);
    int minimax(Move *move, int depth, Side side, Board *b);
    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif
