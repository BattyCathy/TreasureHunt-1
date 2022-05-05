#include <stdio.h>
#include "ciphers.cpp"





class Board {
public:
    int rows;
    int columns;
    int *data;
    
    Board(int setRows, int setColumns) {
        rows = setRows;
        columns = setColumns;
        data = new int[rows * columns];
    }
    int *cell(int row, int column) {
        return &data[(row * columns) + column];
    }
    bool onBoard(int row, int column) {
        return row < rows && column < columns;
    }
    bool validateCell(int row, int column) {
        if (onBoard(row, column)) {
            if (*cell(row, column) == 0) {
                return true;
            }
        }
        return false;
    }
    
    bool modifyCell(int row, int column, int value) {
        if (validateCell(row, column)) {
            *cell(row, column) = value;
            return true;
        }
        return false;
    }
    
    

    
    bool validateRange(int row, int column, int length, bool horizontal) {
        for (int cell = 0; cell < length; cell++) {
            if (!validateCell(row, column)) {
                return false;
            }
            
        }
        return true;
    }
    
    bool modifyRange(int row, int column, int length, bool horizontal, int value) {
        if (validateRange(row, column, length, horizontal)) {
            for (int cell = 0; cell < length; cell++) {
                modifyCell(row, column, value);
                if (horizontal) {
                    column++;
                } else {
                    row++;
                }
            }
            return true;
        }
        return false;
    }
    
    void printBoard() {
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                printf("[%3d]", *cell(row, column));
            }
            printf("\n");
        }
        printf("\n");
    }
    
    void cipherPrint(Cipher cipher) {
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                int cell = data[(row * columns) + column];
                switch(cipher) {
                    case SHOW:
                        printf("[%3c]", showCipher(cell));
                        break;
                    case REVEAL:
                        printf("[%3c]", revealCipher(cell));
                        break;
                    case NONE:
                        printf("[%3d]", cell);
                        break;
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    
};



