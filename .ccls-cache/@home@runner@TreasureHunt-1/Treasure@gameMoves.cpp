//
//  gameMoves.cpp
//  Treasure
//
//  Created by Austin Roach on 5/5/22.
//

#include "gameMoves.hpp"
#include "board.cpp"
#include "treasure.cpp"

bool digCell(int row, int column, Board *board) {
    int *cell = board->cell(row, column);
    if (*cell > 0) {
        *cell *= -1;
        return true;
    } else if (*cell == 0) {
        *cell = -1;
        return true;
    } else {
        return false;
    }
  delete cell;
}

bool hideTreasure(int row, int column, bool horizontal, Board *board, TreasureType treasure) {
    TreasureChest *chest = new TreasureChest(treasure);
    return board->modifyRange(row, column, chest->length, horizontal, chest->cipher);
  delete chest;
}
