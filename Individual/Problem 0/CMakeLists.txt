cmake_minimum_required(VERSION 3.23)
project(XO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(XO main.cpp XOApplication.h XOPlayer.h XOBot.h XOPlayer.cpp XOBoard.h XOBoard.cpp XOBot.cpp XOApplication.cpp)
