#include "player.hpp"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
     s = side;
     board = Board();

    if (!testingMinimax) {
        return;
    }
    char boardData[64] = {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', 'b', ' ', ' ', ' ', ' ', ' ', ' ',
        'b', 'w', 'b', 'b', 'b', 'b', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
    };
    board.setBoard(boardData);
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    Side other = (s == BLACK) ? WHITE : BLACK;
    board.doMove(opponentsMove, other);
    //board.print();
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */
    Move *move = new Move(0,0);
    int max = -100;
    Move *best = new Move(-1,-1);
    for (int x = 0; x < 8; x ++) {
        for (int y = 0; y < 8; y ++) {
            move->setX(x);
            move->setY(y);
            if (!board.checkMove(move, s)){
                continue;
            }
            int score;
            if (testingMinimax) {
                score = minimax(move, 1, s, &board);
            } else {
                score = minimax(move, 4, s, &board);
            }
            if(score > max){
                max = score;
                best->setX(x);
                best->setY(y);
            }
        }
    }
    delete move;
    if(best->getX() == -1){
        std::cerr << "No valid move" << std::endl;
        return nullptr;
    }
    board.doMove(best, s);
        return best;
}

int Player::heuristic(Move *move, Side side, Board *b){
    Board *temp = b->copy();
    temp->doMove(move, side);
    int score = temp->countBlack() - temp->countWhite();
    delete temp;
    if(side == BLACK)
        return score;
    return -score;
}

int Player::weight_heuristic(Move *move){
    return weights[move->getY()][move->getX()];
}

int Player::minimax(Move *move, int depth, Side side, Board *b){
    //std::cerr << "Depth: " << depth << std::endl;
    //b->print();
    Side other = (side == BLACK) ? WHITE : BLACK;
    if(depth == 0){
        //std::cerr <<  move->getX() << move->getY() << side << depth << heuristic(move, side, b) << std::endl;
        if(side == BLACK)
            return b->countBlack() - b->countWhite();
        return -b->countBlack() + b->countWhite();
    }
    Board *temp = b->copy();
    temp->doMove(move, side);
    int min = 100;
    for (int x = 0; x < 8; x ++) {
        for (int y = 0; y < 8; y ++) {
            move->setX(x);
            move->setY(y);
            if (!temp->checkMove(move, other)){
                continue;
            }
            int score = minimax(move, depth - 1, other, temp);
            if(score < min){
                min = score;
            }
        }
    }
    delete temp;
    return min;

}


