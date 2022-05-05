//
//  cHelp.cpp
//  Treasure
//
//  Created by Austin Roach on 5/4/22.
//
#include <stdio.h>
#include "cHelp.hpp"

void freeBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

