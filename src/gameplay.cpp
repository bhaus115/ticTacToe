#include "gameplay.hpp"
#include "dataStream.hpp"
#include <cstring>

using namespace std;

bool Gameplay::validInput(const uint8_t& pos) {
  if (pos < 0 || pos > 8){
    return false;
  } else {
    for (const auto& location: this->usedLocations){
      if(location == pos){
        cout << "Location already taken" << std::endl;
        return false;
      }
    }
    return true;  
  }
}

bool Gameplay::selectLocation() {
  int location;
    cout<<"\n" << this->currentTurnPlayer << " choose a location\n";
    cin >> location;

    if (this->validInput(location)) {
      this->gameBoard[location] = this->currentTurnPlayer;
      this->usedLocations.insert(this->usedLocations.begin(), location);
      this->X_moves.insert(this->X_moves.end(), location);
      return true;
    }
    else {
      cout<<"Invalid location\n";
      return false;    
    }
}

void Gameplay::clearBoard() {
  //memset(this->gameBoard, 0, 9);
  for(int i = 0; i<9; i++){
    this->gameBoard[i] = ' ';
  }
  this->usedLocations.clear();
  this->X_moves.clear();
  this->O_moves.clear(); 

  this->currentTurnPlayer = 'X';
  this->winner = '-';
  cout << "\nStart\n";
  this->printBoard();
}

void Gameplay::switchPlayer() {
  if (this->currentTurnPlayer == 'X') {
    this->currentTurnPlayer = 'O';
  } else {
    this->currentTurnPlayer = 'X';
  }
}

bool Gameplay::checkWinningBoard() {
  bool winning = false;

  if(gameBoard[0]==gameBoard[1] && gameBoard[1]==gameBoard[2]){
    if(!isspace(gameBoard[0])){
      winning = true;
      this->winner = this->currentTurnPlayer;
    }
  }
  else if(gameBoard[3]==gameBoard[4] && gameBoard[4]==gameBoard[5]){
    if(!isspace(gameBoard[3])){
      winning = true;
      this->winner = this->currentTurnPlayer;
    }
  }
  else if(gameBoard[6]==gameBoard[7] && gameBoard[7]==gameBoard[8]){
    if(!isspace(gameBoard[6])){
      winning = true;
      this->winner = this->currentTurnPlayer;
    }
  }
  else if(gameBoard[0]==gameBoard[3] && gameBoard[3]==gameBoard[6]){
    if(!isspace(gameBoard[0])){
      winning = true;
      this->winner = this->currentTurnPlayer;
    }
  }
  else if(gameBoard[1]==gameBoard[4] && gameBoard[4]==gameBoard[7]){
    if(!isspace(gameBoard[1])){
      winning = true;
      this->winner = this->currentTurnPlayer;
    }
  }
  else if(gameBoard[2]==gameBoard[5] && gameBoard[5]==gameBoard[8]){
    if(!isspace(gameBoard[2])){
      winning = true;
      this->winner = this->currentTurnPlayer;
    }
  }
  else if(gameBoard[0]==gameBoard[4] && gameBoard[4]==gameBoard[8]){
    if(!isspace(gameBoard[0])){
      winning = true;
      this->winner = this->currentTurnPlayer;
    }
  }
  else if(gameBoard[2]==gameBoard[4] && gameBoard[4]==gameBoard[6]){
    if(!isspace(gameBoard[2])){
      winning = true;
      this->winner = this->currentTurnPlayer;
    }
  }

  return winning;
}

void Gameplay::printBoard() {
  cout<<"-------------------------------"<<std::endl;
  for(int i = 0; i<3; i ++){
    cout<< this->gameBoard[i] <<" ";
  }
  cout<<"\n";
  for(int i = 3; i<6; i ++){
    cout<< this->gameBoard[i] <<" ";
  }
  cout<<"\n";
  for(int i = 6; i<9; i ++){
    cout<< this->gameBoard[i] <<" ";
  }
  cout<<"\n-------------------------------"<<std::endl;
}

void Gameplay::saveEndOfGameData() {
  if (this->usedLocations.size() == 9 && this->gameOver == false){
    this->moveData.write_x_data(this->X_moves, result::push);
    this->moveData.write_o_data(this->O_moves, result::push);
  }
  else if(this->currentTurnPlayer == 'X'){
    this->moveData.write_x_data(this->X_moves, result::lose);
    this->moveData.write_o_data(this->O_moves, result::win);
  }
  else if(this->currentTurnPlayer == 'O'){
    this->moveData.write_x_data(this->X_moves, result::win);
    this->moveData.write_o_data(this->O_moves, result::lose);
  }
}

void Gameplay::replay() {
    int replay;
    cout<< "Play Again? (1=yes 2=no)" << std::endl;
    cin >> replay;
    if (replay == 2){
      this->gameOver = true;
    }
    else if (replay == 1){
      this->gameOver = false;
      this->clearBoard();
      this->usedLocations.clear();
      this->X_moves.clear();
      this->O_moves.clear();
    }
}