cmake_minimum_required(VERSION 3.26)
project(hello-world)

set(CMAKE_CXX_STANDARD 11)
# 链接路径
set(SDL2_DIR  D:\\SDL2-devel-2.28.3-mingw\\SDL2-2.28.3\\x86_64-w64-mingw32)
include_directories(${SDL2_DIR}/include)

add_executable(hello-world main.cpp
        MySDL.cpp
        MySDL.h)
# 链接库
target_link_libraries(hello-world mingw32 SDL2main SDL2)
