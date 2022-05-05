//
//  gameScript.cpp
//  Treasure
//
//  Created by Austin Roach on 5/5/22.
//

#include "gameScript.hpp"
#include "aiLogic.cpp"
#include <unistd.h>
int rows = 8;
int columns = 8;
int aiScore = 0;
int userScore = 0;
int maxScore = (bronzeNum * bronzeLength) + (silverNum * silverLength) + (goldNum * goldLength) + (rubiesNum * rubiesLength) + (vibraniumNum * vibraniumLength);


void bothBoards(Board *aiBoard, Board *userBoard) {
    int s = system("clear");
    printf("Ai Board - Score %d/%d\n", aiScore, maxScore);
    aiBoard->printBoard();
    printf("User Board - Score %d/%d\n", userScore, maxScore);
    userBoard->printBoard();
}

void think(int seconds) {
    printf("Thinking...\n");
    for (int i = 0; i < seconds; i++) {
        sleep(1);
        printf("...\n");
    }
}

void digTurn(Board *aiBoard, Board *userBoard) {
    bothBoards(aiBoard, userBoard);
    think(3);
    aiScore += aiDig(userBoard);
    bothBoards(aiBoard, userBoard);
    userScore += userDig(aiBoard);
    bothBoards(aiBoard, userBoard);
}

void aiDigTurn(Board *aiBoard, Board *userBoard) {
    bothBoards(aiBoard, userBoard);
//    think(1);
    aiScore += aiDig(userBoard);
    bothBoards(aiBoard, userBoard);
    userScore += aiDig(aiBoard);
    bothBoards(aiBoard, userBoard);
}

void playGame() {
    Board *aiBoard = new Board(rows, columns);
    Board *userBoard = new Board(rows, columns);
    aiHideAll(aiBoard);
    userHideAll(userBoard);
    while (userScore < maxScore && aiScore < maxScore) {
        digTurn(aiBoard, userBoard);
    }
    if (userScore < maxScore) {
        printf("Ai Wins\n");
    } else if (aiScore < maxScore) {
        printf("You win\n");
    } else {
        printf("Ties\n");
    }
}

void aiGame() {
    Board *aiBoard = new Board(rows, columns);
    Board *userBoard = new Board(rows, columns);
    aiHideAll(aiBoard);
    aiHideAll(userBoard);
    while (userScore < maxScore && aiScore < maxScore) {
        aiDigTurn(aiBoard, userBoard);
    }
    if (userScore < maxScore) {
        printf("Ai Wins\n");
    } else if (aiScore < maxScore) {
        printf("You win\n");
    } else {
        printf("Ties\n");
    }
}
