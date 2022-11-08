cmake_minimum_required(VERSION 3.23)
project(clion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(clion main.cpp Client.h BankAccount.h Client.fwd.h Client.cpp BankAccount.cpp SavingBankAccount.h SavingBankAccount.cpp BankApplication.h BankApplication.cpp)
