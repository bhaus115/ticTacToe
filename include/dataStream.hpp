#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

//using namespace std;

typedef enum {
  push = 0,
  win = 1,
  lose = 2,
} result;

class gameMove_data {
  public:
    std::ofstream X_move_data;
    std::ofstream O_move_data;

    void write_x_data(std::vector<int> XData, result win) {
      X_move_data.open("moveData/x_move_data.dat", std::ios::app);
      auto now = std::chrono::system_clock::now();
      X_move_data <<std::chrono::system_clock::to_time_t(now)<<std::endl;
      X_move_data <<"result: "<<win<<std::endl;
      for(uint32_t i = 0; i < XData.size(); i++){
        X_move_data << XData[i] <<" ";
      }
      X_move_data <<'\n';
      X_move_data.close();
    }

    void write_o_data(std::vector<int> OData, result win){
      O_move_data.open("moveData/o_move_data.dat",std::ios::app);
      auto now = std::chrono::system_clock::now();
      O_move_data <<std::chrono::system_clock::to_time_t(now)<<std::endl;
      O_move_data <<"result: "<<win<<std::endl;
      for(uint32_t i = 0; i < OData.size(); i++){
        O_move_data << OData[i] <<" ";
      }
      O_move_data <<'\n';
      O_move_data.close();
    }
};
