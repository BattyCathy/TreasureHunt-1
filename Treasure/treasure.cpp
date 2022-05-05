//
//  treasure.cpp
//  Treasure
//
//  Created by Austin Roach on 5/4/22.
//

#include "treasure.hpp"
#include <string>

using std::string;
enum TreasureType {
BRONZE, SILVER, GOLD, RUBIES, VIBRANIUM, MAX
};



int bronzeNum = 11;
int silverNum = 12;
int goldNum = 13;
int rubiesNum = 14;
int vibraniumNum = 15;

int bronzeLength = 5;
int silverLength = 4;
int goldLength = 3;
int rubiesLength = 2;
int vibraniumLength = 1;


class TreasureChest {
public:
TreasureType type;
int length;
int cipher;
string name;
TreasureChest(TreasureType type) {
  switch(type) {
    case BRONZE:
      length = bronzeLength;
      cipher = bronzeNum;
      name = "Bronze";
    break;
    case SILVER:
      length = silverLength;
      cipher = silverNum;
      name = "Silver";
    break;
    case GOLD:
      length = goldLength;
        cipher = goldNum;
      name = "Gold";
    break;
    case RUBIES:
      length = rubiesLength;
      cipher = rubiesNum;
      name = "Rubies";
    break;
    case VIBRANIUM:
      length = vibraniumLength;
      cipher = vibraniumNum;
          name = "Vibranium";
    break;
      default:
          length = -1;
          cipher = -1;
          name = "Invalid";
          break;
    
  }
}
};

TreasureType charGem(char c) {
  TreasureType type;
  switch(c) {
    case 'b':
    type = BRONZE;
    break;
    case 's':
    type = SILVER;
    break;
    case 'g':
    type = GOLD;
    break;
    case 'r':
    type = RUBIES;
    break;
    case 'v':
    type = VIBRANIUM;
  }
  return type;
}







