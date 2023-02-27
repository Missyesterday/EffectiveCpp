cmake_minimum_required(VERSION 3.20)
project(EffectiveC++)

set(CMAKE_CXX_STANDARD 14)

add_executable(EffectiveC++ main.cpp)

add_executable(copyAssignment src/0Introduction/copyAssignment.cpp)
add_executable(const src/02const/const.cpp)
add_executable(UseConst src/03const2/UseConst.cpp)
add_executable(ptr src/03const2/ptr.cpp)
add_executable(init src/04Initialization/init.cpp)