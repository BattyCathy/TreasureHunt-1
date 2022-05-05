//
//  aiLogic.cpp
//  Treasure
//
//  Created by Austin Roach on 5/5/22.
//

#include "aiLogic.hpp"
#include "userMoves.cpp"
#include <time.h>
#include <stdlib.h>
#include <math.h>


int randomNumber(int modulus) {
    srand(time(NULL));
    int num = (rand() % modulus);
    return num;
}

bool flipCoin() {
    srand(time(NULL));
    int num = (rand() % 1);
    return num == 1;
}

void aiHide(Board *board, TreasureType treasure) {
    int row;
    int column;
    bool horizontal;
    bool success = false;
    while (!success) {
        row = randomNumber(board->rows);
        column = randomNumber(board->columns);
        horizontal = flipCoin();
        success = hideTreasure(row, column, horizontal, board, treasure);
    }
}

void aiHideAll(Board *board) {
    for (int treasure = 0; treasure < 5; treasure++) {
        aiHide(board, (TreasureType)treasure);
    }
    
}


int aiDig(Board *board) {
    int row;
    int column;
    bool success = false;
    while (!success) {
        row = randomNumber(board->rows);
        column = randomNumber(board->columns);
        success = digCell(row, column, board);
    }
  if (*board->cell(row, column) != -1) {
    return abs(*board->cell(row, column));
  } else {
    return 0;
  }
}


