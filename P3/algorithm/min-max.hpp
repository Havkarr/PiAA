#pragma once
#include "../board/tic-tac-toe.hpp"
#include <vector>

struct position
{
    int row;
    int col;
};


int minMax_X(board b, int depth, int alpha, int beta, bool maximizingPlayer);


int minMax_O(board b, int depth, int alpha, int beta, bool maximizingPlayer);