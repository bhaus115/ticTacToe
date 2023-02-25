#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include "gameplay.hpp"

using namespace std;
/* game board 
     |     |
  0  |  1  |  2
_____|_____|_____
     |     |
  3  |  4  |  5
_____|_____|_____
     |     |
  6  |  7  |  8
     |     |

*/

int main(int argc, char **argv) {
  Gameplay currentGame;
  currentGame.clearBoard();

  while (!currentGame.gameOver) {
    // Select location to put X or O
    if (currentGame.selectLocation()) {
      currentGame.printBoard();
      // Check if game is over and Play Again after game is over
      //cout << currentGame.usedLocations.size() << "\t"<< std::boolalpha << currentGame.checkWinningBoard() << std::endl;
      if (currentGame.usedLocations.size() == 9 || currentGame.checkWinningBoard()) {
        currentGame.saveEndOfGameData();
        currentGame.replay();
      } else {
        currentGame.switchPlayer();
      }
    } else {
      cout << "Enter different location\n";
    }
  }
  return 0;
}
