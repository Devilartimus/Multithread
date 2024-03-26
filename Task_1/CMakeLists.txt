cmake_minimum_required(VERSION 3.5)

project(Task_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable( Task_1 main.cpp
    Socket_class.h Socket_class.cpp
    Queue_class.h Queue_class.cpp
    Reader_class.h Reader_class.cpp
    Writer_class.h Writer_class.cpp )
