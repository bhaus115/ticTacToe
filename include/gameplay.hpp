#pragma once

#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
//#include "player.hpp"
#include "dataStream.hpp"
using namespace std;

class Gameplay {
  public:
    std::vector<int> X_moves;
    std::vector<int> O_moves;
    char currentTurnPlayer = 'X';
    std::vector<int> usedLocations;
    bool gameOver = false;
    char gameBoard[9];

    bool selectLocation();
    bool validInput(const uint8_t& pos);
    bool checkWinningBoard();
    void printBoard();
    void clearBoard();
    void switchPlayer();
    void saveEndOfGameData();
    void replay();

  private:
    char winner;
    gameMove_data moveData;
};
