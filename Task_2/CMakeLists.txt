cmake_minimum_required(VERSION 3.5)

project(Task_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Task_2 main.cpp
    Server_class.h Srever_class.cpp
    Socket_class.h Socket_class.cpp)
