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
     	{10, 0, 4, 4, 4, 4, 0, 10},
     	{0, 0, 2, 2, 2, 2, 0, 0},
     	{4, 2, 1, 1, 1, 1, 2, 4},
     	{4, 2, 1, 1, 1, 1, 2, 4},
     	{4, 2, 1, 1, 1, 1, 2, 4},
     	{4, 2, 1, 1, 1, 1, 2, 4},
     	{0, 0, 2, 2, 2, 2, 0, 0},
     	{10, 0, 4, 4, 4, 4, 0, 10}
     };

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    int heuristic(Move *move, Side side, Board *b);
    int weight_heuristic(Side side, Board *b);
    int minimax(Move *move, int depth, Side side, Board *b);
    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif
