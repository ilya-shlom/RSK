cmake_minimum_required(VERSION 3.23)
project(RSK)

set(CMAKE_CXX_STANDARD 17)

add_executable(RSK main.cpp permutations.h tableaux.h)
