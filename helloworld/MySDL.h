//
// Created by Shmiky__ on 20/9/2023.
//

#ifndef HELLO_WORLD_MYSDL_H
#define HELLO_WORLD_MYSDL_H


#include "SDL2/SDL.h"

class MySDL {

public:
    MySDL();
    ~MySDL();
public:
    bool Init();//初始化SDL视频子系统，创建窗口，获取表面
    bool load_bmp();//加载bmp图像到表面，SDL默认支持bmp

private:
    SDL_Window* MyWindows = nullptr;//视频子系统窗口
    SDL_Surface* MySurface = nullptr;//视频子系统窗口的表面



};


#endif //HELLO_WORLD_MYSDL_H
