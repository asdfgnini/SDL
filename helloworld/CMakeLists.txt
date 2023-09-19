cmake_minimum_required(VERSION 3.26)
project(hello-world)

set(CMAKE_CXX_STANDARD 11)

set(SDL2_DIR  D:\\SDL2-devel-2.28.3-mingw\\SDL2-2.28.3\\x86_64-w64-mingw32)

# 设置要包含的头文件的路径
include_directories(${SDL2_DIR}/include)

add_executable(hello-world main.cpp)

target_link_libraries(hello-world mingw32 SDL2main SDL2)
