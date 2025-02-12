cmake_minimum_required(VERSION 3.31)

add_library(core tuple.cpp common.cpp canvas.cpp)

target_compile_options(core PRIVATE /Wall /WX)
