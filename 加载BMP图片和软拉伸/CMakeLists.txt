cmake_minimum_required(VERSION 3.26)
project(hello-world)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_DIR  D:\\SDL2-devel-2.28.3-mingw\\SDL2-2.28.3\\x86_64-w64-mingw32)

include_directories(${SDL2_DIR}/include/SDL2)

include_directories(D:\\SDL2_image-devel-2.6.3-mingw\\SDL2_image-2.6.3\\x86_64-w64-mingw32\\include\\SDL2)
link_directories(D:\\SDL2_image-devel-2.6.3-mingw\\SDL2_image-2.6.3\\x86_64-w64-mingw32\\lib)

add_executable(hello-world main.cpp
        MySDL.cpp
        MySDL.h)
# 链接库
target_link_libraries(hello-world mingw32 SDL2main SDL2 SDL2_image)
