set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
cmake_minimum_required(VERSION 3.20)
project(TicTacToe)

set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/gameplay.hpp
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/dataStream.hpp)

add_library(ticTacToe_lib src/gameplay.cpp ${HEADER_FILES})
target_include_directories(ticTacToe_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(ticTacToe main.cpp ${HEADER_FILES})
target_link_libraries(ticTacToe PUBLIC ticTacToe_lib)
target_include_directories(ticTacToe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

