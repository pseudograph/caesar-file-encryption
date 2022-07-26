cmake_minimum_required(VERSION 3.22)
project(CaesarFileEncryption)
include_directories(../include)

set(CMAKE_CXX_STANDARD 20)

add_executable(CaesarFileEncryption main.cpp FileData.cpp Key.cpp Utility.cpp Key.cpp)
