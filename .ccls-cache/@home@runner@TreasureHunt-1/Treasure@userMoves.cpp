//
//  userMoves.cpp
//  Treasure
//
//  Created by Austin Roach on 5/5/22.
//

#include "userMoves.hpp"
#include "cHelp.cpp"
#include "gameMoves.cpp"
#include <math.h>


int userRow(int rows) {
    int row;
    printf("Row:");
    int s = scanf("%d", &row);
    freeBuffer();
    if (row < 0 || row >= rows) {
        printf("ERROR");
        return userRow(rows);
    } else {
        return row;
    }
}

int userColumn(int columns) {
    int column;
    printf("Column:");
    int s = scanf("%d", &column);
    freeBuffer();
    if (column < 0 || column >= columns) {
        printf("ERROR");
        return userColumn(columns);
    } else {
        return column;
    }
}


bool align() {
    char alignment;
    printf("Would you like to hide your treasure horizontally or vertically?\n");
    printf("h/v\n");
    //Buffer overflow fixed - logic is murky
    
    int s = scanf("%c", &alignment);
    freeBuffer();
    
    if (alignment == 'h') {
        return true;
    } else if (alignment == 'v') {
        return false;
    } else {
        return align();
    }
}

void userHideTreasure(TreasureType treasure, Board *board) {

  TreasureChest *chest = new TreasureChest(treasure);
  int row;
  int column;
  bool horizontal;
  int s = system("clear");
  board->cipherPrint(REVEAL);

  printf("Hiding %s chest. Occupies %d cells.\n",chest->name.c_str(), chest->length);

  horizontal = align();
  row = userRow(board->rows);
  column = userColumn(board->columns);
  bool ret = board->modifyRange(row, column, chest->length, horizontal, chest->cipher);
  if (!ret) {
       userHideTreasure(treasure, board);
  }

  s = system("clear");
  board->printBoard();
delete chest;

}

void userHideAll(Board *board) {
  for (int i = 0; i < 5; i++) {
    userHideTreasure((TreasureType)i, board);
  }
}

int userDig(Board *board) {
    bool success = false;
    int row;
    int column;
    printf("Your turn to dig a cell\n");
    while (!success) {
        row = userRow(board->rows);
        column = userColumn(board->columns);
        success = digCell(row, column, board);
        if (!success) {
            printf("Invalid Entry - Please Try Again\n");
        }
    }
    return *board->cell(row, column);
}





