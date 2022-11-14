cmake_minimum_required(VERSION 3.23)
project(BigRealNumber)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BigRealNumber
        BigDecimalIntClass.cpp
        BigDecimalIntClass.h
        BigReal.cpp
        BigReal.h
        main.cpp)
