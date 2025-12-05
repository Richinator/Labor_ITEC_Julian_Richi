cmake_minimum_required(VERSION 3.10)
project(MyCProject)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(MyCProject-ex src/main.c)

add_executable(Swap-ex src/swap_main.c)

add_executable(Print_hist-ex src/printHist_main.c src/itec.c)